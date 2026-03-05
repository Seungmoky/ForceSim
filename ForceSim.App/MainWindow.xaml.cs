using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.IO;
using System.Windows.Threading;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace ForceSim.App
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window, INotifyPropertyChanged
    {
        private readonly DispatcherTimer _timer = new DispatcherTimer();
        private List<string> _lines = new List<string>();
        private int _lineIndex = 0;
        private AppSettings _settings = new AppSettings();
        private CellViewModel _hotCell = null;
        private DateTime _hotUntil = DateTime.MinValue;
        private LogFileItem _selectedLogFile;
        private ObservableCollection<CellViewModel> _cells = new ObservableCollection<CellViewModel>();
        private CellViewModel[] _cellIndex; // 빠른 접근용 (row*cols + col)
        public ObservableCollection<CellViewModel> Cells { get; } = new ObservableCollection<CellViewModel>();
        public ObservableCollection<string> LogLines { get; } = new ObservableCollection<string>();
        public ObservableCollection<LogFileItem> LogFiles { get; } = new ObservableCollection<LogFileItem>();
        public int GridCols { get; set; }
        public int GridRows { get; set; }
        private short _heatMin = 0;
        public short HeatMin
        {
            get => _heatMin;
            set { _heatMin = value; OnPropertyChanged(); }
        }

        private short _heatMax = 0;
        public short HeatMax
        {
            get => _heatMax;
            set { _heatMax = value; OnPropertyChanged(); }
        }
        public LogFileItem SelectedLogFile
        {
            get => _selectedLogFile;
            set { _selectedLogFile = value; }
        }

        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;
            _timer.Tick += Timer_Tick;

            // setting.conf는 exe 폴더 옆에 두는 걸 추천
            string confPath = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "setting.conf");
            _settings = IniReader.LoadSettings(confPath);
            GridCols = _settings.Cols;
            GridRows = _settings.Rows;
            // speed.sec -> timer interval
            _timer.Interval = TimeSpan.FromSeconds(_settings.SpeedSec);

            RefreshLogFileList();

            AppendLog($"[CONF] touchpad=({_settings.TouchWidth}x{_settings.TouchHeight}) section=({_settings.Cols}x{_settings.Rows}) speed={_settings.SpeedSec}s flipY={_settings.FlipY}");
            InitCells();
        }

        private void AppendLog(string msg)
        {
            LogLines.Add(msg);
            while (LogLines.Count > 5)
                LogLines.RemoveAt(0);
        }

        private void RefreshLogFileList()
        {
            string dir = System.IO.Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "logs");
            Directory.CreateDirectory(dir);

            LogFiles.Clear();
            var files = Directory.GetFiles(dir, "*.txt");
            foreach (var f in files)
                LogFiles.Add(new LogFileItem(f));

            if (LogFiles.Count > 0)
                SelectedLogFile = LogFiles[0];

            AppendLog($"[INFO] log folder: {dir}");
            AppendLog($"[INFO] found {LogFiles.Count} txt files");
        }

        private void BtnRefresh_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            RefreshLogFileList();
        }

        private void BtnStart_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            var item = SelectedLogFile;
            var path = item?.FullPath;

            if (string.IsNullOrWhiteSpace(path) || !File.Exists(path))
            {
                AppendLog("[ERR] select a valid log file.");
                return;
            }

            _lines = new List<string>(File.ReadAllLines(path));
            _lineIndex = 0;

            BtnStart.IsEnabled = false;
            BtnStop.IsEnabled = true;

            AppendLog($"[INFO] start: {item.FileName}  lines={_lines.Count}");
            _timer.Start();
        }

        private void BtnStop_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            _timer.Stop();
            BtnStart.IsEnabled = true;
            BtnStop.IsEnabled = false;
            AppendLog("[INFO] stopped");
        }

        private void BtnReset_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            _timer.Stop();
            InitCells();
            _hotCell = null;
            _hotUntil = DateTime.MinValue;
            _lines.Clear();
            _lineIndex = 0;

            BtnStart.IsEnabled = true;
            BtnStop.IsEnabled = false;
            LogLines.Clear();
            AppendLog("[INFO] reset");
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            // 핫셀 자동 해제 (입력 끊기면 꺼짐)
            if (_hotCell != null && DateTime.Now > _hotUntil)
            {
                _hotCell.IsHot = false;
                _hotCell = null;
            }
            if (_lineIndex >= _lines.Count)
            {
                BtnStop_Click(null, null);
                AppendLog("[INFO] EOF");
                return;
            }

            string line = _lines[_lineIndex++];
            // 타임스탬프 [08:35:15.000] 같은 거 포함되어 있으니,
            // 필요한 경우 뒤에서 파싱하면 됨. 일단 전체 line 그대로 넣고 Regex가 매칭되는지 확인.
            if (LogParser.TryParseScaler(line, out var scaler6))
            {
                ForceNative.Force_SetScaler(scaler6);
                AppendLog($"[Scaler] {string.Join(",", scaler6)}");
                return;
            }

            if (LogParser.TryParseData(line, out short x, out short y, out var s6, out short fwP))
            {
                short simP = ForceNative.Force_EstimateWeight(x, y, s6);

                MapToSectionCell(x, y, out int col, out int row);

                short delta = (short)(simP - fwP);

                // 이전 hot 지우기(가장 최근 한 칸만 hot 유지)
                foreach (var c in _cells)
                    if (c.IsHot) c.IsHot = false;

                // 해당 셀 갱신
                int idx = row * _settings.Cols + col;
                var cell = _cellIndex[idx];
                // 핫셀 갱신: 같은 셀이 계속 업데이트되면 유지
                if (!ReferenceEquals(_hotCell, cell))
                {
                    if (_hotCell != null) _hotCell.IsHot = false;
                    _hotCell = cell;
                }
                bool needHeatRecalc = false;

                cell.IsHot = true;

                // “변화가 계속 들어오는 동안” 유지 시간을 갱신
                _hotUntil = DateTime.Now.AddSeconds(Math.Max(_settings.SpeedSec * 3.0, 0.20));

                cell.IsHot = true;
                cell.Count += 1;
                // MaxSimP 변경 감지
                if (simP > cell.MaxSimP)
                {
                    cell.MaxSimP = simP;
                    needHeatRecalc = true;
                }
                cell.SimP = simP;
                cell.Delta = delta;

                if (needHeatRecalc)
                    RecalcHeatRange();
                AppendLog($"X={x},Y={y} -> cell=({col},{row})  FW_P={fwP}  SIM_P={simP}  Δ={delta}");
                return;
            }
            // 매칭 안 되는 줄은 원하면 로그로 뿌리기
            // AppendLog("[SKIP] " + line);
        }
        private void MapToSectionCell(short x, short y, out int col, out int row)
        {
            // double로 계산해서 정확도 확보
            double fx = (double)x * _settings.Cols / _settings.TouchWidth;
            double fy = (double)y * _settings.Rows / _settings.TouchHeight;

            col = (int)Math.Floor(fx);
            row = (int)Math.Floor(fy);

            // clamp
            if (col < 0) col = 0;
            if (col >= _settings.Cols) col = _settings.Cols - 1;

            if (row < 0) row = 0;
            if (row >= _settings.Rows) row = _settings.Rows - 1;

            if (_settings.FlipY)
                row = (_settings.Rows - 1) - row;
        }
        private void InitCells()
        {
            Cells.Clear();

            int cols = _settings.Cols;
            int rows = _settings.Rows;

            _cellIndex = new CellViewModel[cols * rows];

            // (0,0)이 왼쪽 위: row 0부터 아래로 쌓이게 생성
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    var cell = new CellViewModel(c, r);
                    Cells.Add(cell);
                    _cellIndex[r * cols + c] = cell;
                }
            }
            CellsView.ItemsSource = Cells;
        }

        private void RecalcHeatRange()
        {
            short min = short.MaxValue;
            short max = 0;

            foreach (var c in Cells)
            {
                if (c.Count <= 0) continue;
                if (c.MaxSimP < min) min = c.MaxSimP;
                if (c.MaxSimP > max) max = c.MaxSimP;
            }

            if (max > 0)
            {
                HeatMin = min;
                HeatMax = max;
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged([CallerMemberName] string name = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}
