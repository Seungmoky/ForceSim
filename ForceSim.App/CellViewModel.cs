using System.ComponentModel;

public sealed class CellViewModel : INotifyPropertyChanged
{
    public int Col { get; }
    public int Row { get; }

    private int _count;
    public int Count
    {
        get => _count;
        set
        {
            _count = value;
            OnPropertyChanged(nameof(Count));
            OnPropertyChanged(nameof(HasSim));
            OnPropertyChanged(nameof(Label));
        }
    }

    private short _simP;

    private short _maxSimP;
    public short MaxSimP
    {
        get => _maxSimP;
        set { _maxSimP = value; OnPropertyChanged(nameof(MaxSimP)); OnPropertyChanged(nameof(Label)); }
    }

    public bool HasSim => Count > 0;

    public string Label => HasSim ? $"{MaxSimP}" : $"({Col},{Row})";
    public short SimP
    {
        get => _simP;
        set { _simP = value; OnPropertyChanged(nameof(SimP)); }
    }

    private short _delta;
    public short Delta
    {
        get => _delta;
        set { _delta = value; OnPropertyChanged(nameof(Delta)); }
    }

    private bool _isHot;
    public bool IsHot
    {
        get => _isHot;
        set { _isHot = value; OnPropertyChanged(nameof(IsHot)); }
    }

    public CellViewModel(int col, int row)
    {
        Col = col;
        Row = row;
        Count = 0;
        SimP = 0;
        Delta = 0;
        MaxSimP = 0;
        IsHot = false;
    }

    public event PropertyChangedEventHandler PropertyChanged;
    private void OnPropertyChanged(string name)
        => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
}