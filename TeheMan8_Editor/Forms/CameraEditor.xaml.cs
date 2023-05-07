using System;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for CameraEditor.xaml
    /// </summary>
    public partial class CameraEditor : UserControl
    {
        #region Constructors
        public CameraEditor()
        {
            InitializeComponent();
        }
        #endregion

        #region Methods
        public void SetupTab()
        {
            SetBorderValues((int)MainWindow.window.cameraE.settingsInt.Value);
            SetDoorValues((int)MainWindow.window.cameraE.doorInt.Value);
            SetHorizontalValues((int)MainWindow.window.cameraE.horiInt.Value);
            SetVerticalValues((int)MainWindow.window.cameraE.vertInt.Value);
        }
        private void SetBorderValues(int id)
        {
            int offset = (int)PSX.CpuToOffset((uint)(Const.BorderDataAddress + id * 8));

            //R
            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            MainWindow.window.cameraE.rightInt.Value = val;
            //L
            val = BitConverter.ToUInt16(PSX.exe, offset + 2);
            MainWindow.window.cameraE.leftInt.Value = val;
            //B
            val = BitConverter.ToUInt16(PSX.exe, offset + 4);
            MainWindow.window.cameraE.bottomInt.Value = val;
            //T
            val = BitConverter.ToUInt16(PSX.exe, offset + 6);
            MainWindow.window.cameraE.topInt.Value = val;
        }
        private void SetDoorValues(int id)
        {
            int offset = (int)PSX.CpuToOffset((uint)(Const.DoorDataAddress + id * 2));
            MainWindow.window.cameraE.doorSetInt.Value = BitConverter.ToUInt16(PSX.exe, offset);
        }
        private void SetHorizontalValues(int id)
        {
            int offset = (int)PSX.CpuToOffset((uint)(Const.HoriDataAddress + id * 4));
            MainWindow.window.cameraE.horiIntL.Value = BitConverter.ToUInt16(PSX.exe, offset);
            MainWindow.window.cameraE.horiIntR.Value = BitConverter.ToUInt16(PSX.exe, offset + 2);
        }
        private void SetVerticalValues(int id)
        {
            int offset = (int)PSX.CpuToOffset((uint)(Const.VertDataAddress + id * 4));
            MainWindow.window.cameraE.vertIntD.Value = BitConverter.ToUInt16(PSX.exe, offset);
            MainWindow.window.cameraE.vertIntU.Value = BitConverter.ToUInt16(PSX.exe, offset + 2);
        }
        #endregion Methods

        #region Events

        private void settingsInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            SetBorderValues((int)e.NewValue);
        }
        private void CameraSetting_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e) //RLTB Values
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int offset = (int)PSX.CpuToOffset((uint)(Const.BorderDataAddress + MainWindow.window.cameraE.settingsInt.Value * 8));
            offset += Convert.ToInt32(((NumInt)sender).Uid);

            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            if (val == (int)e.NewValue)
                return;

            PSX.exe[offset] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[offset + 1] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }
        private void doorInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            SetDoorValues((int)e.NewValue);
        }
        private void doorSetInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int offset = (int)PSX.CpuToOffset((uint)(Const.DoorDataAddress + MainWindow.window.cameraE.doorInt.Value * 2));
            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            if (val == (int)e.NewValue)
                return;

            PSX.exe[offset] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[offset + 1] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }

        private void DoorGoto_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MainWindow.window.cameraE.settingsInt.Value == MainWindow.window.cameraE.doorSetInt.Value)
                return;
            MainWindow.window.cameraE.settingsInt.Value = MainWindow.window.cameraE.doorSetInt.Value;
        }
        private void horiInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            SetHorizontalValues((int)e.NewValue);
        }
        private void horiIntDir_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int offset = (int)PSX.CpuToOffset((uint)(Const.HoriDataAddress + MainWindow.window.cameraE.horiInt.Value * 4));
            offset += Convert.ToInt32(((NumInt)sender).Uid);
            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            if (val == (int)e.NewValue)
                return;

            PSX.exe[offset] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[offset + 1] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }
        private void HoriGotoL_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MainWindow.window.cameraE.settingsInt.Value == MainWindow.window.cameraE.horiIntL.Value)
                return;
            MainWindow.window.cameraE.settingsInt.Value = MainWindow.window.cameraE.horiIntL.Value;
        }
        private void HoriGotoR_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MainWindow.window.cameraE.settingsInt.Value == MainWindow.window.cameraE.horiIntR.Value)
                return;
            MainWindow.window.cameraE.settingsInt.Value = MainWindow.window.cameraE.horiIntR.Value;
        }
        private void vertInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            SetVerticalValues((int)e.NewValue);
        }

        private void vertIntDir_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int offset = (int)PSX.CpuToOffset((uint)(Const.VertDataAddress + MainWindow.window.cameraE.vertInt.Value * 4));
            offset += Convert.ToInt32(((NumInt)sender).Uid);
            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            if (val == (int)e.NewValue)
                return;

            PSX.exe[offset] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[offset + 1] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }
        private void VertGotoD_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MainWindow.window.cameraE.settingsInt.Value == MainWindow.window.cameraE.vertIntD.Value)
                return;
            MainWindow.window.cameraE.settingsInt.Value = MainWindow.window.cameraE.vertIntD.Value;
        }
        private void VertGotoU_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (MainWindow.window.cameraE.settingsInt.Value == MainWindow.window.cameraE.vertIntU.Value)
                return;
            MainWindow.window.cameraE.settingsInt.Value = MainWindow.window.cameraE.vertIntU.Value;
        }
        private void Help_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            HelpWindow h = new HelpWindow(3);
            h.ShowDialog();
        }
        #endregion Events
    }
}
