using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace ForceSim.App
{
    /// <summary>
    /// .fsd 파일 파싱 및 strengthData 계산
    /// </summary>
    internal static class FsdParser
    {
        private static readonly Regex ReScaler = new Regex(
            @"Scaler1:(\d+),Scaler2:(\d+),Scaler3:(\d+),Scaler4:(\d+),Scaler5:(\d+),Scaler6:(\d+)",
            RegexOptions.Compiled);

        private static readonly Regex ReDelta = new Regex(
            @"Delta1:(-?\d+),Delta2:(-?\d+),Delta3:(-?\d+),Delta4:(-?\d+),Delta5:(-?\d+),Delta6:(-?\d+)",
            RegexOptions.Compiled);

        internal struct FsdData
        {
            public short[] Scaler6;        // A,B,C,D,E,F 순서로 재정렬된 스케일러
            public short[] Delta6;         // A,B,C,D,E,F 순서로 재정렬된 델타 (없으면 null)
            public List<FsdEntry> Entries; // 재생할 데이터 목록 (report_x != -1인 행)
        }

        internal struct FsdEntry
        {
            public short X;          // report_x
            public short Y;          // report_y
            public short[] S6;       // strengthData[6] (A,B,C,D,E,F 순서)
            public short FwWeight;   // weight 컬럼값 (델타 계산용 기준값)
        }

        /// <summary>
        /// .fsd 파일을 파싱하여 FsdData를 반환한다.
        /// dirName: 디렉토리 이름 (mutual/self/smutual 구분용)
        /// </summary>
        internal static FsdData Parse(string filePath, string dirName)
        {
            var result = new FsdData { Entries = new List<FsdEntry>() };
            var lines = File.ReadAllLines(filePath);

            // 스케일러 파싱 (순서: C, F, D, A, E, B → A,B,C,D,E,F 재정렬)
            result.Scaler6 = ParseScaler(lines) ?? new short[] { 300, 300, 300, 300, 300, 300 };
            // 델타 파싱 (스케일러와 동일한 순서 재정렬)
            result.Delta6 = ParseDelta(lines);

            // 데이터 행 수집
            var baselineRows = new List<long[]>();
            var dataRows = new List<(int weight, long[] sa6, int rx, int ry)>();

            foreach (var line in lines)
            {
                if (!TryParseDataRow(line, out int weight, out long[] sa6, out int rx, out int ry))
                    continue;

                if (rx == -1 && ry == -1)
                    baselineRows.Add(sa6);
                else
                    dataRows.Add((weight, sa6, rx, ry));
            }

            // baseline: report_x == -1인 행들의 센서값 평균
            var baseline = new long[6];
            if (baselineRows.Count > 0)
            {
                foreach (var row in baselineRows)
                    for (int i = 0; i < 6; i++)
                        baseline[i] += row[i];
                for (int i = 0; i < 6; i++)
                    baseline[i] /= baselineRows.Count;
            }

            // dir 이름으로 연산 방향 결정
            // self 또는 smutual 포함 → rawData - baseline
            // mutual 포함 (smutual/self 미포함) → baseline - rawData
            bool isMutualOnly = ContainsIgnoreCase(dirName, "mutual")
                             && !ContainsIgnoreCase(dirName, "smutual")
                             && !ContainsIgnoreCase(dirName, "self");

            // strengthData 계산 및 엔트리 생성
            foreach (var (weight, sa6, rx, ry) in dataRows)
            {
                var s6 = new short[6];
                for (int i = 0; i < 6; i++)
                {
                    long val = isMutualOnly ? (baseline[i] - sa6[i]) : (sa6[i] - baseline[i]);
                    val = Math.Max(short.MinValue, Math.Min(short.MaxValue, val));
                    s6[i] = (short)val;
                }
                result.Entries.Add(new FsdEntry
                {
                    X = (short)rx,
                    Y = (short)ry,
                    S6 = s6,
                    FwWeight = (short)weight
                });
            }

            return result;
        }

        // Scaler1~6 파싱: 순서 C,F,D,A,E,B → A,B,C,D,E,F 재정렬
        private static short[] ParseScaler(string[] lines)
        {
            foreach (var line in lines)
            {
                var m = ReScaler.Match(line);
                if (!m.Success) continue;

                var s = new short[6];
                s[0] = short.Parse(m.Groups[4].Value); // A = Scaler4
                s[1] = short.Parse(m.Groups[6].Value); // B = Scaler6
                s[2] = short.Parse(m.Groups[1].Value); // C = Scaler1
                s[3] = short.Parse(m.Groups[3].Value); // D = Scaler3
                s[4] = short.Parse(m.Groups[5].Value); // E = Scaler5
                s[5] = short.Parse(m.Groups[2].Value); // F = Scaler2
                return s;
            }
            return null;
        }

        // Delta1~6 파싱: 순서 C,F,D,A,E,B → A,B,C,D,E,F 재정렬
        private static short[] ParseDelta(string[] lines)
        {
            foreach (var line in lines)
            {
                var m = ReDelta.Match(line);
                if (!m.Success) continue;

                var d = new short[6];
                d[0] = short.Parse(m.Groups[4].Value); // A = Delta4
                d[1] = short.Parse(m.Groups[6].Value); // B = Delta6
                d[2] = short.Parse(m.Groups[1].Value); // C = Delta1
                d[3] = short.Parse(m.Groups[3].Value); // D = Delta3
                d[4] = short.Parse(m.Groups[5].Value); // E = Delta5
                d[5] = short.Parse(m.Groups[2].Value); // F = Delta2
                return d;
            }
            return null;
        }

        // CSV 데이터 행 파싱: weight,coord_x,coord_y,Sa,Sb,Sc,Sd,Se,Sf,report_x,report_y
        private static bool TryParseDataRow(string line, out int weight, out long[] sa6, out int rx, out int ry)
        {
            weight = 0; sa6 = null; rx = 0; ry = 0;
            if (string.IsNullOrWhiteSpace(line)) return false;

            var parts = line.Split(',');
            if (parts.Length < 9) return false;

            // 헤더 행 스킵 (첫 컬럼이 숫자가 아닌 경우)
            if (!int.TryParse(parts[0].Trim(), out weight)) return false;
            // coord_x, coord_y 를 report 좌표로 사용
            if (!int.TryParse(parts[1].Trim(), out rx)) return false;
            if (!int.TryParse(parts[2].Trim(), out ry)) return false;

            sa6 = new long[6];
            for (int i = 0; i < 6; i++)
                if (!long.TryParse(parts[3 + i].Trim(), out sa6[i])) return false;

            return true;
        }

        private static bool ContainsIgnoreCase(string source, string value)
            => source.IndexOf(value, StringComparison.OrdinalIgnoreCase) >= 0;
    }
}
