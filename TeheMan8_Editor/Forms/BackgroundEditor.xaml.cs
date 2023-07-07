using System;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for BackgroundEditor.xaml
    /// </summary>
    public partial class BackgroundEditor : UserControl
    {
        #region Feilds
        #endregion Feilds

        #region Constructors
        public BackgroundEditor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void SetBackgroundSettings()
        {
            if (!PSX.levels[Level.Id].pac.filename.Contains("STAGE"))
            {
                //Disable
                MainWindow.window.bgE.scrollType2Int.IsEnabled = false;
                MainWindow.window.bgE.scrollType3Int.IsEnabled = false;

                MainWindow.window.bgE.priority2Int.IsEnabled = false;
                MainWindow.window.bgE.priority3Int.IsEnabled = false;

                MainWindow.window.bgE.baseX2Int.IsEnabled = false;
                MainWindow.window.bgE.baseY2Int.IsEnabled = false;

                MainWindow.window.bgE.baseX3Int.IsEnabled = false;
                MainWindow.window.bgE.baseY3Int.IsEnabled = false;
            }
            else
            {
                int stageId = SpawnWindow.GetSpawnIndex();
                MainWindow.window.bgE.settingsInt.Value = 0;
                MainWindow.window.bgE.settingsInt.Maximum = Const.MaxBGEffects[stageId];
                uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.EffectsBGAddress + (stageId * 4))));
                uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.bgE.settingsInt.Value * 4)));

                SetBGValues((int)PSX.CpuToOffset(dataAddress));

                //Enable
                if (!MainWindow.window.bgE.scrollType2Int.IsEnabled)
                {
                    MainWindow.window.bgE.scrollType2Int.IsEnabled = true;
                    MainWindow.window.bgE.scrollType3Int.IsEnabled = true;

                    MainWindow.window.bgE.priority2Int.IsEnabled = true;
                    MainWindow.window.bgE.priority3Int.IsEnabled = true;

                    MainWindow.window.bgE.baseX2Int.IsEnabled = true;
                    MainWindow.window.bgE.baseY2Int.IsEnabled = true;

                    MainWindow.window.bgE.baseX3Int.IsEnabled = true;
                    MainWindow.window.bgE.baseY3Int.IsEnabled = true;
                }
            }
        }
        private void SetBGValues(int offset)
        {
            MainWindow.window.bgE.scrollType2Int.Value = PSX.exe[offset];
            MainWindow.window.bgE.scrollType3Int.Value = PSX.exe[offset + 1];

            MainWindow.window.bgE.priority2Int.Value = PSX.exe[offset + 2];
            MainWindow.window.bgE.priority3Int.Value = PSX.exe[offset + 3];

            MainWindow.window.bgE.baseX2Int.Value = BitConverter.ToUInt16(PSX.exe, offset + 4);
            MainWindow.window.bgE.baseY2Int.Value = BitConverter.ToUInt16(PSX.exe, offset + 6);

            MainWindow.window.bgE.baseX3Int.Value = BitConverter.ToUInt16(PSX.exe, offset + 8);
            MainWindow.window.bgE.baseY3Int.Value = BitConverter.ToUInt16(PSX.exe, offset + 10);
        }
        #endregion Methods

        #region Events
        private void settingsInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int stageId = SpawnWindow.GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.EffectsBGAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + ((int)e.NewValue * 4)));

            SetBGValues((int)PSX.CpuToOffset(dataAddress));
        }
        private void byteSettingValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int stageId = SpawnWindow.GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.EffectsBGAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.bgE.settingsInt.Value * 4)));

            dataAddress += Convert.ToUInt32(((NumInt)sender).Uid);
            dataAddress = (uint)PSX.CpuToOffset(dataAddress);
            byte val = PSX.exe[dataAddress];
            if (val == (byte)(int)e.NewValue)
                return;
            PSX.exe[dataAddress] = (byte)(int)e.NewValue;
            PSX.edit = true;
        }
        private void shortSettingValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int stageId = SpawnWindow.GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.EffectsBGAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.bgE.settingsInt.Value * 4)));

            dataAddress += Convert.ToUInt32(((NumInt)sender).Uid);
            dataAddress = (uint)PSX.CpuToOffset(dataAddress);
            ushort val = BitConverter.ToUInt16(PSX.exe, (int)dataAddress);
            if (val == (int)e.NewValue)
                return;
            PSX.exe[dataAddress] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[dataAddress] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }
        #endregion Events
    }
}
