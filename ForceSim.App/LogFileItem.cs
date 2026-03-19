public sealed class LogFileItem
{
    public string FullPath { get; }
    public string FileName { get; }
    public string DirName { get; }   // .fsd의 경우 상위 폴더명
    public bool IsFsd { get; }
    public string DisplayName { get; } // 목록에 표시할 이름

    public LogFileItem(string fullPath, string logsRoot = null)
    {
        FullPath = fullPath;
        FileName = System.IO.Path.GetFileName(fullPath);
        IsFsd = System.IO.Path.GetExtension(fullPath)
                    .Equals(".fsd", System.StringComparison.OrdinalIgnoreCase);

        if (IsFsd)
        {
            var dir = System.IO.Path.GetDirectoryName(fullPath);
            DirName = System.IO.Path.GetFileName(dir);
            DisplayName = DirName + "/" + FileName;
        }
        else
        {
            DirName = string.Empty;
            DisplayName = FileName;
        }
    }

    public override string ToString() => DisplayName;
}
