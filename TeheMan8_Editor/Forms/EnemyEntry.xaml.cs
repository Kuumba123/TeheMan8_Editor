using System.Windows;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for EnemyEntry.xaml
    /// </summary>
    public partial class EnemyEntry : UserControl
    {
        #region Constructors
        public EnemyEntry(byte id, byte var, byte type, short x, short y)
        {
            InitializeComponent();

            idInt.Value = id;
            varInt.Value = var;
            typeInt.Value = type;
            xInt.Value = x;
            yInt.Value = y;
        }
        #endregion Constructors

        #region Events
        private void idInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            PSX.levels[Level.Id].edit = true;
        }

        private void typeInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            PSX.levels[Level.Id].edit = true;
        }
        private void setting_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            PSX.levels[Level.Id].edit = true;
        }
        #endregion Events
    }
}
