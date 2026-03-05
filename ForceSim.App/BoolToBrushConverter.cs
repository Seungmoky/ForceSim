using System;
using System.Globalization;
using System.Windows.Data;
using System.Windows.Media;

namespace ForceSim.App
{
    internal sealed class BoolToBrushConverter : IValueConverter
    {
        public Brush HotBrush { get; set; } = Brushes.LightGoldenrodYellow;
        public Brush NormalBrush { get; set; } = Brushes.White;

        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            if (value is bool b && b) return HotBrush;
            return NormalBrush;
        }

        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
            => Binding.DoNothing;
    }
}