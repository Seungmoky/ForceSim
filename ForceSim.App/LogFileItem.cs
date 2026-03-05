public sealed class LogFileItem
{
    public string FullPath { get; }
    public string FileName { get; }

    public LogFileItem(string fullPath)
    {
        FullPath = fullPath;
        FileName = System.IO.Path.GetFileName(fullPath);
    }

    public override string ToString() => FileName;
}