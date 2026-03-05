using System;
using System.Globalization;
using System.Windows.Data;
using System.Windows.Media;

namespace ForceSim.App
{
    public sealed class MaxSimPToBrushConverter : IValueConverter
    {
        // 히트맵 스케일의 최대값(대략 Pressure 상한)
        // 필요하면 setting.conf로 나중에 뺄 수 있음
        public double MaxValue { get; set; } = 300.0;

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value == null) return Brushes.White;

            double v;
            try { v = System.Convert.ToDouble(value); }
            catch { return Brushes.White; }

            if (v <= 0) return Brushes.White;

            double t = v / MaxValue;
            if (t < 0) t = 0;
            if (t > 1) t = 1;

            // White -> LightSkyBlue 계열로 점점 진해지게
            // (너무 과한 원색은 눈 아픔 방지용)
            byte baseR = 255, baseG = 255, baseB = 255;
            byte targetR = 135, targetG = 206, targetB = 250; // LightSkyBlue

            byte r = (byte)(baseR + (targetR - baseR) * t);
            byte g = (byte)(baseG + (targetG - baseG) * t);
            byte b = (byte)(baseB + (targetB - baseB) * t);

            return new SolidColorBrush(Color.FromRgb(r, g, b));
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
            => Binding.DoNothing;
    }
}