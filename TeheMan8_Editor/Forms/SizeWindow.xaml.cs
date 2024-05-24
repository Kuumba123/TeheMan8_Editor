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
            enemyCountLbl.Content = "Total Enemies: " + PSX.levels[Level.Id].enemies.Count.ToString();
            enable = true;
        }
        #endregion Constructors

        #region Events
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (edit && screenInt.Value != null && tileInt.Value != null)
            {
                int i = PSX.levels[Level.Id].pac.GetIndexOfType(3);
                int screenCount = (int)screenInt.Value;
                int tileCount = (int)tileInt.Value;

                Array.Resize(ref PSX.levels[Level.Id].pac.entries[i].data, screenCount * 0x200);
                Array.Resize(ref PSX.levels[Level.Id].screenData, screenCount * 0x200);
                i = PSX.levels[Level.Id].pac.GetIndexOfType(4);
                Array.Resize(ref PSX.levels[Level.Id].pac.entries[i].data, tileCount * 4);
                Array.Resize(ref PSX.levels[Level.Id].tileInfo, tileCount * 4);

                screenCount--;
                for (int l = 0; l < 0x400; l++)
                {
                    if (PSX.levels[Level.Id].layout[l] > screenCount)
                        PSX.levels[Level.Id].layout[l] = 0;
                    if (PSX.levels[Level.Id].layout2[l] > screenCount)
                        PSX.levels[Level.Id].layout2[l] = 0;
                    if (PSX.levels[Level.Id].layout3[l] > screenCount)
                        PSX.levels[Level.Id].layout3[l] = 0;
                }

                for (int s = 0; s < PSX.levels[Level.Id].screenData.Length / 0x200; s++)
                {
                    for (int t = 0; t < 0x100; t++)
                    {
                        int index = s * 0x200 + t * 2;
                        ushort id = (ushort)(BitConverter.ToUInt16(PSX.levels[Level.Id].screenData, index) & 0x3FFF);

                        if (id > (tileCount - 1))
                        {
                            PSX.levels[Level.Id].screenData[index] = 0;
                            PSX.levels[Level.Id].screenData[index + 1] = 0;
                        }
                    }
                }
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.layoutE.AssignLimits();
                MainWindow.window.screenE.AssignLimits();
                MainWindow.window.x16E.AssignLimits();
                Undo.ClearLevelUndos();
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
