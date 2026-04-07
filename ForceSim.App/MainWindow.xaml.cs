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
        private FsdParser.FsdData _fsdData;
        private int _fsdEntryIndex = 0;
        private bool _isFsdMode = false;
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
        private string _progressText = "Line: 0 / 0";
        private short[] _lastScaler = new short[6];
        private short[][] _lastDelta = null; // [Sa~Sf][A~F] 6×6 행렬 (FSD) 또는 [1][A~F] (TXT)
        private long[]  _lastBaseline = null;
        public string ProgressText
        {
            get => _progressText;
            set { _progressText = value; OnPropertyChanged(); }
        }
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
            set
            {
                _selectedLogFile = value;
                _lines = null;
                _lineIndex = 0;
                _fsdData = default;
                _fsdEntryIndex = 0;
                _isFsdMode = false;
            }
        }

        public MainWindow()
        {
            InitializeComponent();
            DataContext = this;
            _timer.Tick += Timer_Tick;

            // setting.conf는 exe 폴더 옆에 두는 걸 추천
            string root = GetProjectRoot();
            string confPath = System.IO.Path.Combine(root, "setting.conf");
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
        private void UpdateProgressText()
        {
            int total, current;
            if (_isFsdMode)
            {
                total = _fsdData.Entries?.Count ?? 0;
                current = _fsdEntryIndex;
            }
            else
            {
                total = (_lines == null) ? 0 : _lines.Count;
                current = _lineIndex;
            }

            // 사람이 보기 좋게 1-based로 보여주기
            if (total > 0 && current < 0) current = 0;
            if (total > 0 && current > total) current = total;

            ProgressText = $"Line: {current} / {total}";
        }

        private static string F4(int v) => string.Format("{0,4}", v); // 4칸 오른쪽 정렬
        private static string F3(int v) => string.Format("{0,3}", v); // 3칸 오른쪽 정렬

        private static string BuildLogLine(
            int x, int y,
            int simP,
            short[] s6,
            int delta,
            int sx, int sy)
        {
            // s6: Sa..Sf 로 표시
            // 자리 정렬을 위해 각 항목을 "Label:####" 형태로 만들고, ####은 4칸 고정
            return
                $"X:{F4(x)}  Y:{F4(y)}  P:{F4(simP)}  " +
                $"Sa:{F4(s6[0])}  Sb:{F4(s6[1])}  Sc:{F4(s6[2])}  Sd:{F4(s6[3])}  Se:{F4(s6[4])}  Sf:{F4(s6[5])}  " +
                $"Δ:{F4(delta)}  SX:{F3(sx)}  SY:{F3(sy)}";
        }

        private void RefreshLogFileList()
        {
            string root = GetProjectRoot();
            string logsDir = System.IO.Path.Combine(root, "logs");
            Directory.CreateDirectory(logsDir);

            LogFiles.Clear();

            // .txt 파일 (logs/ 직접)
            foreach (var f in Directory.GetFiles(logsDir, "*.txt"))
                LogFiles.Add(new LogFileItem(f, logsDir));

            // .fsd 파일 (logs/ 하위 디렉토리)
            foreach (var subDir in Directory.GetDirectories(logsDir))
                foreach (var f in Directory.GetFiles(subDir, "*.fsd"))
                    LogFiles.Add(new LogFileItem(f, logsDir));

            if (LogFiles.Count > 0)
                SelectedLogFile = LogFiles[0];

            AppendLog($"[INFO] log folder: {logsDir}");
            AppendLog($"[INFO] found {LogFiles.Count} files (txt+fsd)");
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

            _isFsdMode = item.IsFsd;

            if (_isFsdMode)
            {
                if (_fsdData.Entries == null || _fsdData.Entries.Count == 0)
                {
                    _fsdData = FsdParser.Parse(path, item.DirName);
                    _fsdEntryIndex = 0;
                    ForceNative.Force_SetScaler(_fsdData.Scaler6);
                    _lastScaler = (short[])_fsdData.Scaler6.Clone();
                    _lastDelta = _fsdData.Delta6x6;
                    _lastBaseline = _fsdData.Baseline6 != null ? (long[])_fsdData.Baseline6.Clone() : null;
                    AppendLog($"[Scaler] {string.Join(",", _fsdData.Scaler6)}");
                    AppendLog($"[FSD] {_fsdData.Entries.Count} entries / dir={item.DirName}");
                }
            }
            else
            {
                if (_lines == null || _lines.Count == 0)
                {
                    _lines = new List<string>(File.ReadAllLines(path));
                    _lineIndex = 0;
                }
            }

            BtnStart.IsEnabled = false;
            BtnStop.IsEnabled = true;

            AppendLog($"[INFO] start: {item.DisplayName}");
            _timer.Start();
            UpdateProgressText();
        }

        private void BtnStop_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            _timer.Stop();
            UpdateProgressText();
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
            _lines?.Clear();
            _lineIndex = 0;
            _fsdData = default;
            _fsdEntryIndex = 0;
            _isFsdMode = false;
            _lastDelta = null;
            _lastBaseline = null;

            BtnStart.IsEnabled = true;
            BtnStop.IsEnabled = false;
            LogLines.Clear();
            UpdateProgressText();
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

            if (_isFsdMode)
            {
                Timer_Tick_Fsd();
                return;
            }

            if (_lineIndex >= _lines.Count)
            {
                BtnStop_Click(null, null);
                AppendLog("[INFO] EOF");
                AppendLog($"[Scaler] {string.Join(",", _lastScaler)}");
                if (_lastDelta != null)
                    AppendLog($"[Delta] {_lastDelta.Length}x6 matrix");
                UpdateProgressText();
                return;
            }

            string line = _lines[_lineIndex++];
            UpdateProgressText();
            // 타임스탬프 [08:35:15.000] 같은 거 포함되어 있으니,
            // 필요한 경우 뒤에서 파싱하면 됨. 일단 전체 line 그대로 넣고 Regex가 매칭되는지 확인.
            if (LogParser.TryParseScaler(line, out var scaler6))
            {
                ForceNative.Force_SetScaler(scaler6);
                AppendLog($"[Scaler] {string.Join(",", scaler6)}");
                _lastScaler = (short[])scaler6.Clone();
                return;
            }

            if (LogParser.TryParseDelta(line, out var delta6))
            {
                _lastDelta = new short[][] { delta6 };
                return;
            }

            if (LogParser.TryParseData(line, out short x, out short y, out var s6, out short fwP))
            {
                ApplySimResult(x, y, s6, fwP);
                return;
            }
            // 매칭 안 되는 줄은 원하면 로그로 뿌리기
            // AppendLog("[SKIP] " + line);
        }

        private void Timer_Tick_Fsd()
        {
            if (_fsdEntryIndex >= _fsdData.Entries.Count)
            {
                BtnStop_Click(null, null);
                AppendLog("[INFO] EOF");
                AppendLog($"[Scaler] {string.Join(",", _lastScaler)}");
                if (_lastDelta != null)
                    AppendLog($"[Delta] {_lastDelta.Length}x6 matrix");
                UpdateProgressText();
                return;
            }

            var entry = _fsdData.Entries[_fsdEntryIndex++];
            UpdateProgressText();
            ApplySimResult(entry.X, entry.Y, entry.S6, entry.FwWeight);
        }

        // Force 계산 → 셀 업데이트 → 로그 출력 공통 처리
        private void ApplySimResult(short x, short y, short[] s6, short fwP)
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

            // "변화가 계속 들어오는 동안" 유지 시간을 갱신
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
            // AppendLog(BuildLogLine(x, y, simP, s6, delta, col, row));
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
        private static string GetProjectRoot()
        {
            var dir = new DirectoryInfo(AppDomain.CurrentDomain.BaseDirectory);

            while (dir != null)
            {
                if (File.Exists(System.IO.Path.Combine(dir.FullName, "ForceSim.sln")))
                    return dir.FullName;

                dir = dir.Parent;
            }

            return AppDomain.CurrentDomain.BaseDirectory;
        }

        private void MenuCopyGrid_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            int cols = _settings.Cols;
            int rows = _settings.Rows;
            var sb = new System.Text.StringBuilder();
            // Baseline
            sb.AppendLine("baseline_Sa\tbaseline_Sb\tbaseline_Sc\tbaseline_Sd\tbaseline_Se\tbaseline_Sf");
            if (_lastBaseline != null)
                sb.AppendLine(string.Join("\t", _lastBaseline));
            else
                sb.AppendLine();

            // Scaler
            sb.AppendLine("scaler_Sa\tscaler_Sb\tscaler_Sc\tscaler_Sd\tscaler_Se\tscaler_Sf");
            sb.AppendLine(string.Join("\t", _lastScaler));

            // Delta 6×6 행렬
            sb.AppendLine("\tdelta_Sa\tdelta_Sb\tdelta_Sc\tdelta_Sd\tdelta_Se\tdelta_Sf");
            if (_lastDelta != null)
            {
                string[] rowLabels = { "Sa", "Sb", "Sc", "Sd", "Se", "Sf" };
                for (int i = 0; i < _lastDelta.Length; i++)
                {
                    sb.Append(i < rowLabels.Length ? rowLabels[i] : $"S{i}");
                    sb.Append('\t');
                    sb.AppendLine(_lastDelta[i] != null ? string.Join("\t", _lastDelta[i]) : "");
                }
            }
            else
            {
                sb.AppendLine();
            }

            sb.AppendLine();

            // 그리드 (rows x cols TSV)
            for (int r = 0; r < rows; r++)
            {
                for (int c = 0; c < cols; c++)
                {
                    var cell = _cellIndex[r * cols + c];
                    if (c > 0) sb.Append('\t');
                    if (cell.Count > 0)
                        sb.Append(cell.MaxSimP);
                }
                sb.AppendLine();
            }

            string text = sb.ToString();
            for (int retry = 0; retry < 5; retry++)
            {
                try
                {
                    System.Windows.Clipboard.SetText(text);
                    AppendLog($"[INFO] 그리드 복사 완료 ({cols}x{rows})");
                    return;
                }
                catch (System.Runtime.InteropServices.COMException)
                {
                    System.Threading.Thread.Sleep(50);
                }
            }
            AppendLog("[ERR] 클립보드 복사 실패 (다른 프로세스 점유 중)");
        }

        public event PropertyChangedEventHandler PropertyChanged;
        private void OnPropertyChanged([CallerMemberName] string name = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
    }
}
