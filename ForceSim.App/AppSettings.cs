internal sealed class AppSettings
{
    public int TouchWidth { get; set; } = 2316;
    public int TouchHeight { get; set; } = 1636;

    public int Cols { get; set; } = 16;
    public int Rows { get; set; } = 12;

    public double SpeedSec { get; set; } = 0.02;

    // 필요하면 y축 뒤집기 옵션도 추가 가능
    public bool FlipY { get; set; } = true;
}