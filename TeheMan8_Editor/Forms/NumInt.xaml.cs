using System.Windows.Media;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for NumInt.xaml
    /// </summary>
    public partial class NumInt : Xceed.Wpf.Toolkit.IntegerUpDown
    {
        public NumInt()
        {
            InitializeComponent();
        }
        public override void OnApplyTemplate()
        {
            base.OnApplyTemplate();
            TextBox.CaretBrush = Brushes.White;
        }
    }
}
