using System;
using System.Text.RegularExpressions;

internal static class LogParser
{
    private static readonly Regex ReScaler = new Regex(
        @"Scaler1:(\d+),Scaler2:(\d+),Scaler3:(\d+),Scaler4:(\d+),Scaler5:(\d+),Scaler6:(\d+)",
        RegexOptions.Compiled);

    private static readonly Regex ReData = new Regex(
        @"X:(\d+),Y:(\d+),S1=(-?\d+),S2=(-?\d+),S3=(-?\d+),S4=(-?\d+),S5=(-?\d+),S6=(-?\d+),P:(-?\d+)",
        RegexOptions.Compiled);

    internal static bool TryParseScaler(string line, out short[] scaler6)
    {
        scaler6 = null;
        var m = ReScaler.Match(line);
        if (!m.Success) return false;

        scaler6 = new short[6];
        // 로그 순서가 Scaler1 ~ 6이 A, B, C, D, E, F 순서일 경우
        for (int i = 0; i < 6; i++)
            scaler6[i] = short.Parse(m.Groups[i + 1].Value);
        //// 로그 순서가 Scaler1 ~ 6이 C, F, D, A, E, B 순서일 경우
        //scaler6[0] = short.Parse(m.Groups[4].Value);
        //scaler6[1] = short.Parse(m.Groups[6].Value);
        //scaler6[2] = short.Parse(m.Groups[1].Value);
        //scaler6[3] = short.Parse(m.Groups[3].Value);
        //scaler6[4] = short.Parse(m.Groups[5].Value);
        //scaler6[5] = short.Parse(m.Groups[2].Value);

        return true;
    }

    internal static bool TryParseData(string line, out short x, out short y, out short[] s6, out short fwP)
    {
        x = y = fwP = 0;
        s6 = null;

        var m = ReData.Match(line);
        if (!m.Success) return false;

        x = short.Parse(m.Groups[1].Value);
        y = short.Parse(m.Groups[2].Value);

        s6 = new short[6];
        // 로그 순서가 Seensor1 ~ 6이 A, B, C, D, E, F 순서일 경우
        for (int i = 0; i < 6; i++)
            s6[i] = short.Parse(m.Groups[i + 3].Value);
        //// 로그 순서가 Seensor1 ~ 6이 C, F, D, A, E, B 순서일 경우
        //s6[0] = short.Parse(m.Groups[6].Value);
        //s6[1] = short.Parse(m.Groups[8].Value);
        //s6[2] = short.Parse(m.Groups[3].Value);
        //s6[3] = short.Parse(m.Groups[5].Value);
        //s6[4] = short.Parse(m.Groups[7].Value);
        //s6[5] = short.Parse(m.Groups[4].Value);

        fwP = short.Parse(m.Groups[9].Value);
        return true;
    }
}