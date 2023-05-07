using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for SettingsWindow.xaml
    /// </summary>
    public partial class GameSettingsWindow : Window
    {
        #region Properties
        private bool enable = false;
        private bool saved = true;
        private BinaryWriter bw;
        private BinaryReader br;
        private MemoryStream ms;
        private string path;
        #endregion Properties

        #region Constructors
        public GameSettingsWindow(string path)
        {
            ms = new MemoryStream(File.ReadAllBytes(path));
            bw = new BinaryWriter(ms);
            br = new BinaryReader(ms);
            this.path = path;
            InitializeComponent();

            //Setup Int UP/DOWN
            foreach (var c in mainPannel.Children)
            {
                if (c.GetType() != typeof(Expander))
                    continue;
                foreach (var c2 in ((StackPanel)((Expander)c).Content).Children)
                {
                    foreach (var c3 in ((StackPanel)c2).Children)
                    {

                        if (c3.GetType() != typeof(NumInt))
                            continue;

                        NumInt t = (NumInt)c3;
                        var words = t.Uid.Split();
                        uint addr = Convert.ToUInt32(words[0], 16);
                        int type = 0;
                        if (words.Length != 1)
                            type = Convert.ToInt32(words[1]);
                        switch (type)
                        {
                            case 1:
                                br.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                                t.Value = br.ReadByte();
                                break;
                            case 2:
                                br.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                                t.Value = br.ReadUInt16();
                                break;
                            default:
                                bw.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                                t.Value = br.Read();
                                break;
                        }
                    }
                }
            }
            enable = true;
        }
        #endregion Constructors

        #region Events
        private void IntegerUpDown_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (!enable)
                return;
            saved = false;
            int type = 0;
            var words = ((Control)sender).Uid.Split();
            uint addr = Convert.ToUInt32(words[0], 16);
            if (words.Length != 1)
                type = Convert.ToInt32(words[1]);
            switch (type)
            {
                case 1:
                    bw.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                    bw.Write((byte)(int)e.NewValue);

                    if(addr == 0x801009E8) //Lives
                    {
                        bw.BaseStream.Position = PSX.CpuToOffset(0x801213f0, 0x800C0000);
                        bw.Write((byte)(int)e.NewValue);
                    }
                    break;
                case 2:
                    bw.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                    bw.Write((ushort)(int)e.NewValue);
                    break;
                default:
                    bw.BaseStream.Position = PSX.CpuToOffset(addr, 0x800C0000);
                    bw.Write((int)e.NewValue);
                    break;
            }
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (saved)
                return;
            var result = MessageBox.Show("You edited certain Parameters without saving.\nAre you sure you wanna quit out without saving?", "WARNING", MessageBoxButton.YesNo);
            if (result != MessageBoxResult.Yes)
                e.Cancel = true;
            else
                return;
        }

        private void SaveBtn_Click(object sender, RoutedEventArgs e)
        {
            if (saved && File.Exists(path))
                return;
            try
            {
                var fs = File.Create(path);
                ms.WriteTo(fs);
                fs.Close();
                saved = true;
                MessageBox.Show("Parameters Saved!");
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "ERROR");
            }
        }
        private void SaveAsBtn_Click(object sender, RoutedEventArgs e)
        {
            using(var fd = new System.Windows.Forms.SaveFileDialog())
            {
                fd.Filter = "PSX-EXE |*.53";
                fd.Title = "Select PSX-EXE Save Location";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    path = fd.FileName;
                    try
                    {
                        var fs = File.Create(path);
                        ms.WriteTo(fs);
                        fs.Close();
                        saved = true;
                        MessageBox.Show("Parameters Saved!");
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message, "ERROR");
                    }
                }
            }
        }
        #endregion Events
    }
}
