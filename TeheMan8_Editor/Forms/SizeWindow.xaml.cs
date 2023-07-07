using System;
using System.Windows;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for SizeWindow.xaml
    /// </summary>
    public partial class SizeWindow : Window
    {
        #region Properties
        bool enable;
        bool edit;
        #endregion Properties

        #region Constructors
        public SizeWindow()
        {
            InitializeComponent();

            if (ListWindow.screenViewOpen)
                MainWindow.layoutWindow.Close();
            if (ListWindow.extraOpen)
                MainWindow.extraWindow.Close();

            Title = PSX.levels[Level.Id].pac.filename + " Sizes";
            enable = false;
            //Setup Ints
            screenInt.Value = PSX.levels[Level.Id].screenData.Length / 0x200;
            tileInt.Value = PSX.levels[Level.Id].tileInfo.Length / 4;
            enable = true;
        }
        #endregion Constructors

        #region Events
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (edit)
            {
                int i = PSX.levels[Level.Id].pac.GetIndexOfType(3);
                Array.Resize(ref PSX.levels[Level.Id].pac.entries[i].data, (int)screenInt.Value * 0x200);
                Array.Resize(ref PSX.levels[Level.Id].screenData, (int)screenInt.Value * 0x200);
                i = PSX.levels[Level.Id].pac.GetIndexOfType(4);
                Array.Resize(ref PSX.levels[Level.Id].pac.entries[i].data, (int)tileInt.Value * 4);
                Array.Resize(ref PSX.levels[Level.Id].tileInfo, (int)tileInt.Value * 4);

                MainWindow.window.layoutE.AssignLimits();
                MainWindow.window.screenE.AssignLimits();
                MainWindow.window.x16E.AssignLimits();

                PSX.levels[Level.Id].edit = true;
            }
        }
        private void MaxButton_Click(object sender, RoutedEventArgs e)
        {
            screenInt.Value = screenInt.Maximum;
            tileInt.Value = tileInt.Maximum;
            edit = true;
        }

        private void Int_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null || !enable)
                return;
            edit = true;
        }
        #endregion Events
    }
}
