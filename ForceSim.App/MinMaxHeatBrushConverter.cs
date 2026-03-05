using System;
using System.Globalization;
using System.Windows.Data;
using System.Windows.Media;

namespace ForceSim.App
{
    public sealed class MinMaxHeatBrushConverter : IMultiValueConverter
{
    public object Convert(object[] values, Type targetType, object parameter, CultureInfo culture)
    {
        // values[0] = cell MaxSimP
        // values[1] = HeatMin
        // values[2] = HeatMax

        if (values == null || values.Length < 3) return Brushes.White;

        double v, vmin, vmax;
        try
        {
            v = System.Convert.ToDouble(values[0]);
            vmin = System.Convert.ToDouble(values[1]);
            vmax = System.Convert.ToDouble(values[2]);
        }
        catch
        {
            return Brushes.White;
        }

        if (v <= 0) return Brushes.White;

        // 범위가 아직 의미 없으면(초기 상태), 그냥 연하게 처리
        if (vmax <= vmin + 0.0001)
            return Brushes.White;

        // 정규화(0~1)
        double t = (v - vmin) / (vmax - vmin);
        if (t < 0) t = 0;
        if (t > 1) t = 1;

        // 색상 계산
        // 3-color gradient
        // min → red → white → blue → max

        Color cMin = Color.FromRgb(248, 105, 107);
        Color cMid = Color.FromRgb(252, 252, 252);
        Color cMax = Color.FromRgb(90, 138, 198);

        Color result;

        if (t < 0.5)
        {
            double k = t * 2.0;
            result = Lerp(cMin, cMid, k);
        }
        else
        {
            double k = (t - 0.5) * 2.0;
            result = Lerp(cMid, cMax, k);
        }

        return new SolidColorBrush(result);
    }

    private static Color Lerp(Color a, Color b, double t)
    {
        byte r = (byte)(a.R + (b.R - a.R) * t);
        byte g = (byte)(a.G + (b.G - a.G) * t);
        byte b2 = (byte)(a.B + (b.B - a.B) * t);
        return Color.FromRgb(r, g, b2);
    }

    public object[] ConvertBack(object value, Type[] targetTypes, object parameter, CultureInfo culture)
    => null;


}}