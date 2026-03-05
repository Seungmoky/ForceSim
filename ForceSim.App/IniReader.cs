using System;
using System.Collections.Generic;
using System.IO;

internal static class IniReader
{
    internal static Dictionary<string, Dictionary<string, string>> Load(string path)
    {
        var data = new Dictionary<string, Dictionary<string, string>>(StringComparer.OrdinalIgnoreCase);

        string currentSection = "";
        foreach (var raw in File.ReadAllLines(path))
        {
            var line = raw.Trim();
            if (line.Length == 0) continue;
            if (line.StartsWith(";") || line.StartsWith("#")) continue;

            if (line.StartsWith("[") && line.EndsWith("]"))
            {
                currentSection = line.Substring(1, line.Length - 2).Trim();
                if (!data.ContainsKey(currentSection))
                    data[currentSection] = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
                continue;
            }

            int eq = line.IndexOf('=');
            if (eq <= 0) continue;

            var key = line.Substring(0, eq).Trim();
            var val = line.Substring(eq + 1).Trim();

            if (!data.ContainsKey(currentSection))
                data[currentSection] = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);

            data[currentSection][key] = val;
        }

        return data;
    }

    internal static AppSettings LoadSettings(string path)
    {
        var s = new AppSettings();
        if (!File.Exists(path)) return s;

        var ini = Load(path);

        string Get(string sec, string key, string def = null)
        {
            if (ini.TryGetValue(sec, out var kv) && kv.TryGetValue(key, out var v))
                return v;
            return def;
        }

        s.TouchWidth = ToInt(Get("touchpad", "width", s.TouchWidth.ToString()), s.TouchWidth);
        s.TouchHeight = ToInt(Get("touchpad", "height", s.TouchHeight.ToString()), s.TouchHeight);

        s.Cols = ToInt(Get("section", "cols", s.Cols.ToString()), s.Cols);
        s.Rows = ToInt(Get("section", "rows", s.Rows.ToString()), s.Rows);

        s.SpeedSec = ToDouble(Get("speed", "sec", s.SpeedSec.ToString()), s.SpeedSec);

        // flipy 옵션까지 넣고 싶으면 setting.conf에 flipY=true 추가해서 사용 가능
        var flip = Get("section", "flipY", null);
        if (!string.IsNullOrWhiteSpace(flip))
            s.FlipY = flip.Equals("true", StringComparison.OrdinalIgnoreCase) || flip == "1";

        return s;
    }

    private static int ToInt(string v, int def)
        => int.TryParse(v, out var n) ? n : def;

    private static double ToDouble(string v, double def)
        => double.TryParse(v, out var n) ? n : def;
}