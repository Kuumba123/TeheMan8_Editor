using System;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for SpawnWindow.xaml
    /// </summary>
    public partial class SpawnWindow : UserControl
    {
        #region Fields
        static byte[] pixesl = new byte[0x30000];
        static int viewerX = 0;
        static int viewerY = 0;
        #endregion Fields

        #region Constructors
        public SpawnWindow()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void DrawScreen() //...
        {

        }
        public void SetSpawnSettings()
        {
            if (!ISO.levels[Level.Id].pac.filename.Contains("STAGE"))
            {
                //Disable
                MainWindow.window.spawnE.prorityInt.IsEnabled = false;
                MainWindow.window.spawnE.bg2Check.IsEnabled = false;
                MainWindow.window.spawnE.bg3Check.IsChecked = false;
                MainWindow.window.spawnE.megaIntX.IsEnabled = false;
                MainWindow.window.spawnE.megaIntY.IsEnabled = false;
                MainWindow.window.spawnE.camIntX.IsEnabled = false;
                MainWindow.window.spawnE.camIntY.IsEnabled = false;
                MainWindow.window.spawnE.camLeftInt.IsEnabled = false;
                MainWindow.window.spawnE.camRightInt.IsEnabled = false;
                MainWindow.window.spawnE.camTopInt.IsEnabled = false;
                MainWindow.window.spawnE.camBottomInt.IsEnabled = false;
                return;
            }
            else
            {
                int stageId = GetSpawnIndex();
                uint address = BitConverter.ToUInt32(ISO.exe, (int)ISO.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
                uint dataAddress = BitConverter.ToUInt32(ISO.exe, (int)(ISO.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));
                MainWindow.window.spawnE.spawnInt.Value = 0;
                MainWindow.window.spawnE.spawnInt.Maximum = Const.MaxPoints[stageId];
                SetIntValues((int)ISO.CpuToOffset(dataAddress));

                if (!megaIntX.IsEnabled)
                {
                    //Enable
                    MainWindow.window.spawnE.prorityInt.IsEnabled = true;
                    MainWindow.window.spawnE.bg2Check.IsEnabled = true;
                    MainWindow.window.spawnE.bg3Check.IsChecked = true;
                    MainWindow.window.spawnE.megaIntX.IsEnabled = true;
                    MainWindow.window.spawnE.megaIntY.IsEnabled = true;
                    MainWindow.window.spawnE.camIntX.IsEnabled = true;
                    MainWindow.window.spawnE.camIntY.IsEnabled = true;
                    MainWindow.window.spawnE.camLeftInt.IsEnabled = true;
                    MainWindow.window.spawnE.camRightInt.IsEnabled = true;
                    MainWindow.window.spawnE.camTopInt.IsEnabled = true;
                    MainWindow.window.spawnE.camBottomInt.IsEnabled = true;
                }
            }
        }
        private int GetSpawnIndex() //For each Stage
        {
            if (!ISO.levels[Level.Id].pac.filename.Contains("STAGE"))
            {
                return -1;
            }
            return Convert.ToInt32(ISO.levels[Level.Id].pac.filename.Replace("STAGE0", "")[0].ToString(), 16);
        }
        private void SetIntValues(int offset)
        {
            var t = ISO.exe;
            MainWindow.window.spawnE.prorityInt.Value = BitConverter.ToUInt16(ISO.exe, offset + 1);
            MainWindow.window.spawnE.bg2Check.IsChecked = Convert.ToBoolean(ISO.exe[offset + 3]);
            MainWindow.window.spawnE.bg3Check.IsChecked = Convert.ToBoolean(ISO.exe[offset + 4]);
            MainWindow.window.spawnE.megaIntX.Value = BitConverter.ToUInt16(ISO.exe, offset + 8);
            MainWindow.window.spawnE.megaIntY.Value = BitConverter.ToUInt16(ISO.exe, offset + 0xA);
            MainWindow.window.spawnE.camIntX.Value = BitConverter.ToUInt16(ISO.exe, offset + 0xC);
            MainWindow.window.spawnE.camIntY.Value = BitConverter.ToUInt16(ISO.exe, offset + 0xE);
            MainWindow.window.spawnE.camLeftInt.Value = BitConverter.ToUInt16(ISO.exe, offset + 0x10);
            MainWindow.window.spawnE.camRightInt.Value = BitConverter.ToUInt16(ISO.exe, offset + 0x12);
            MainWindow.window.spawnE.camTopInt.Value = BitConverter.ToUInt16(ISO.exe, offset + 0x14);
            MainWindow.window.spawnE.camBottomInt.Value = BitConverter.ToUInt16(ISO.exe, offset + 0x16);
        }
        #endregion Methods

        #region Events
        private void spawnInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || megaIntX == null)
                return;
            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(ISO.exe, (int)ISO.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(ISO.exe, (int)(ISO.CpuToOffset(address) + ((int)e.NewValue * 4)));

            SetIntValues((int)ISO.CpuToOffset(dataAddress));

        }
        private void setting_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(ISO.exe, (int)ISO.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(ISO.exe, (int)(ISO.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            var updown = (Xceed.Wpf.Toolkit.IntegerUpDown)sender;

            int t = 0;

            int i = Convert.ToInt32(updown.Uid.Split(' ')[0],16);
            if (updown.Uid.Split(' ').Length != 1)
                t = Convert.ToInt32(updown.Uid.Split(' ')[1]);
            switch (t) //Size of data to modify
            {
                case 1:
                    break;
                default:
                    ushort val = BitConverter.ToUInt16(ISO.exe, (int)ISO.CpuToOffset((uint)(dataAddress + i)));
                    if (val == (int)e.NewValue)
                        return;
                    ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i))] = (byte)(((int)e.NewValue) & 0xFF);
                    ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i + 1))] = (byte)(((int)e.NewValue >> 8) & 0xFF);
                    break;
            }
            ISO.edit = true;
        }
        private void SettingBox_Checked(object sender, System.Windows.RoutedEventArgs e)
        {
            if (ISO.levels.Count == 0)
                return;

            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(ISO.exe, (int)ISO.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(ISO.exe, (int)(ISO.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            var c = (CheckBox)sender;

            int i = Convert.ToInt32(c.Uid.Split(' ')[0], 16);

            int v = ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i))];
            if (v == 1)
                return;

            ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i))] = 1;
            ISO.edit = true;
        }

        private void SettingBox_Unchecked(object sender, System.Windows.RoutedEventArgs e)
        {
            if (ISO.levels.Count == 0)
                return;

            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(ISO.exe, (int)ISO.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(ISO.exe, (int)(ISO.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            var c = (CheckBox)sender;

            int i = Convert.ToInt32(c.Uid.Split(' ')[0], 16);

            int v = ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i))];
            if (v == 0)
                return;

            ISO.exe[ISO.CpuToOffset((uint)(dataAddress + i))] = 0;
            ISO.edit = true;
        }
        #endregion Events
    }
}
