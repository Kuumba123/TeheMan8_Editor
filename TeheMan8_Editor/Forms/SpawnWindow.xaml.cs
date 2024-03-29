﻿using System;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for SpawnWindow.xaml
    /// </summary>
    public partial class SpawnWindow : UserControl
    {
        #region Constructors
        public SpawnWindow()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void SetSpawnSettings()
        {
            if (!PSX.levels[Level.Id].pac.filename.Contains("STAGE"))
            {
                //Disable
                MainWindow.window.spawnE.spawnInt.IsEnabled = false;
                MainWindow.window.spawnE.colTimer.IsEnabled = false;
                MainWindow.window.spawnE.scrollInt.IsEnabled = false;
                MainWindow.window.spawnE.prorityInt.IsEnabled = false;
                MainWindow.window.spawnE.bg2Check.IsEnabled = false;
                MainWindow.window.spawnE.bg3Check.IsEnabled = false;
                MainWindow.window.spawnE.texInt.IsEnabled = false;
                MainWindow.window.spawnE.clutId.IsEnabled = false;
                MainWindow.window.spawnE.bgInt.IsEnabled = false;
                MainWindow.window.spawnE.megaIntX.IsEnabled = false;
                MainWindow.window.spawnE.megaIntY.IsEnabled = false;
                MainWindow.window.spawnE.camIntX.IsEnabled = false;
                MainWindow.window.spawnE.camIntY.IsEnabled = false;
                MainWindow.window.spawnE.camLeftInt.IsEnabled = false;
                MainWindow.window.spawnE.camRightInt.IsEnabled = false;
                MainWindow.window.spawnE.camTopInt.IsEnabled = false;
                MainWindow.window.spawnE.camBottomInt.IsEnabled = false;
                MainWindow.window.spawnE.midInt.IsEnabled = false;
                MainWindow.window.spawnE.waterInt.IsEnabled = false;
                return;
            }
            else
            {
                int stageId = GetSpawnIndex();
                MainWindow.window.spawnE.spawnInt.Value = 0;
                MainWindow.window.spawnE.spawnInt.Maximum = Settings.MaxPoints[stageId];
                uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + (stageId * 4))));
                uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));
                SetIntValues((int)PSX.CpuToOffset(dataAddress));
                SetWaterIntValue();

                //Enable
                if (!MainWindow.window.spawnE.megaIntX.IsEnabled)
                {
                    MainWindow.window.spawnE.spawnInt.IsEnabled = true;
                    MainWindow.window.spawnE.colTimer.IsEnabled = true;
                    MainWindow.window.spawnE.scrollInt.IsEnabled = true;
                    MainWindow.window.spawnE.prorityInt.IsEnabled = true;
                    MainWindow.window.spawnE.bg2Check.IsEnabled = true;
                    MainWindow.window.spawnE.bg3Check.IsEnabled = true;
                    MainWindow.window.spawnE.texInt.IsEnabled = true;
                    MainWindow.window.spawnE.clutId.IsEnabled = true;
                    MainWindow.window.spawnE.bgInt.IsEnabled = true;
                    MainWindow.window.spawnE.megaIntX.IsEnabled = true;
                    MainWindow.window.spawnE.megaIntY.IsEnabled = true;
                    MainWindow.window.spawnE.camIntX.IsEnabled = true;
                    MainWindow.window.spawnE.camIntY.IsEnabled = true;
                    MainWindow.window.spawnE.camLeftInt.IsEnabled = true;
                    MainWindow.window.spawnE.camRightInt.IsEnabled = true;
                    MainWindow.window.spawnE.camTopInt.IsEnabled = true;
                    MainWindow.window.spawnE.camBottomInt.IsEnabled = true;
                    MainWindow.window.spawnE.midInt.IsEnabled = true;
                    MainWindow.window.spawnE.waterInt.IsEnabled = true;
                }
                MainWindow.window.spawnE.midInt.Value = PSX.exe[PSX.CpuToOffset((uint)(Const.MidCheckPointAddress + stageId))];
                MainWindow.window.spawnE.midInt.Maximum = Settings.MaxPoints[stageId];
            }
        }
        public static int GetSpawnIndex() //For each Stage
        {
            if (!PSX.levels[Level.Id].pac.filename.Contains("STAGE"))
                return -1;
            return Convert.ToInt32(PSX.levels[Level.Id].pac.filename.Replace("STAGE0", "")[0].ToString(), 16);
        }
        private void SetIntValues(int offset) //does not include water level
        {
            MainWindow.window.spawnE.colTimer.Value = PSX.exe[offset];
            MainWindow.window.spawnE.scrollInt.Value = PSX.exe[offset + 2];
            MainWindow.window.spawnE.prorityInt.Value = BitConverter.ToUInt16(PSX.exe, offset + 1);
            MainWindow.window.spawnE.bg2Check.IsChecked = Convert.ToBoolean(PSX.exe[offset + 3]);
            MainWindow.window.spawnE.bg3Check.IsChecked = Convert.ToBoolean(PSX.exe[offset + 4]);
            MainWindow.window.spawnE.texInt.Value = PSX.exe[offset + 5];
            MainWindow.window.spawnE.clutId.Value = PSX.exe[offset + 6];
            MainWindow.window.spawnE.bgInt.Value = PSX.exe[offset + 7];
            MainWindow.window.spawnE.megaIntX.Value = BitConverter.ToUInt16(PSX.exe, offset + 8);
            MainWindow.window.spawnE.megaIntY.Value = BitConverter.ToUInt16(PSX.exe, offset + 0xA);
            MainWindow.window.spawnE.camIntX.Value = BitConverter.ToUInt16(PSX.exe, offset + 0xC);
            MainWindow.window.spawnE.camIntY.Value = BitConverter.ToUInt16(PSX.exe, offset + 0xE);
            MainWindow.window.spawnE.camLeftInt.Value = BitConverter.ToUInt16(PSX.exe, offset + 0x10);
            MainWindow.window.spawnE.camRightInt.Value = BitConverter.ToUInt16(PSX.exe, offset + 0x12);
            MainWindow.window.spawnE.camTopInt.Value = BitConverter.ToUInt16(PSX.exe, offset + 0x14);
            MainWindow.window.spawnE.camBottomInt.Value = BitConverter.ToUInt16(PSX.exe, offset + 0x16);
        }
        private void SetWaterIntValue()
        {
            int offset = GetSpawnIndex();
            if (offset == -1)
                return;

            offset *= 4;
            offset += PSX.CpuToOffset(Const.WaterLevelAddress);

            if (MidCheck())
                offset += 2;

            MainWindow.window.spawnE.waterInt.Value = BitConverter.ToUInt16(PSX.exe, offset);
        }
        public static async Task WriteCheckPoints() //For Redux
        {
            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;

            //Checkpoints
            {
                byte[] data = new byte[0x78C];
                Array.Copy(PSX.exe, PSX.CpuToOffset(0x80137b34), data, 0, data.Length);
                await Redux.Write(0x80137b34, data);
            }

            //Water Level
            int offset = stageId *= 4;
            uint addr = Const.WaterLevelAddress;
            addr += (uint)offset;

            if (MidCheck())
                addr += 2;
            ushort val = BitConverter.ToUInt16(PSX.exe, (int)PSX.CpuToOffset(addr));
            byte[] vals = BitConverter.GetBytes(val);
            await Redux.Write(0x801b2988, vals);
            await Redux.Write(addr, vals);


            //Mid Checkpoint
            await Redux.Write((uint)(Const.MidCheckPointAddress + stageId), PSX.exe[PSX.CpuToOffset((uint)(Const.MidCheckPointAddress + stageId))]);

            //Background
            {
                byte[] data = new byte[0x4F8];
                Array.Copy(PSX.exe, PSX.CpuToOffset(0x8013c658), data, 0, data.Length);
                await Redux.Write(0x8013c658, data);
            }
        }
        public static bool MidCheck()
        {
            return PSX.levels[Level.Id].pac.filename.Contains("B.PAC") && !PSX.levels[Level.Id].pac.filename.Contains("0B.PAC");
        }
        #endregion Methods

        #region Events
        private void spawnInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || megaIntX == null)
                return;
            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + ((int)e.NewValue * 4)));

            SetIntValues((int)PSX.CpuToOffset(dataAddress));

        }
        private void setting_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            NumInt updown = (NumInt)sender;

            int t = 0;

            int i = Convert.ToInt32(updown.Uid.Split(' ')[0],16);
            if (updown.Uid.Split(' ').Length != 1)
                t = Convert.ToInt32(updown.Uid.Split(' ')[1]);
            switch (t) //Size of data to modify
            {
                case 1:
                    byte b = PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))];
                    if (b == (byte)(int)e.NewValue)
                        return;
                    PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))] = (byte)(int)e.NewValue;
                    PSX.edit = true;
                    Settings.EditedPoints[stageId] = true;
                    break;
                default:
                    ushort val = BitConverter.ToUInt16(PSX.exe, (int)PSX.CpuToOffset((uint)(dataAddress + i)));
                    if (val == (ushort)(int)e.NewValue)
                        return;
                    PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))] = (byte)(((int)e.NewValue) & 0xFF);
                    PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i + 1))] = (byte)(((int)e.NewValue >> 8) & 0xFF);
                    PSX.edit = true;
                    Settings.EditedPoints[stageId] = true;
                    break;
            }
        }
        private void SettingBox_Checked(object sender, System.Windows.RoutedEventArgs e)
        {
            if (PSX.levels.Count == 0)
                return;

            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            var c = (CheckBox)sender;

            int i = Convert.ToInt32(c.Uid.Split(' ')[0], 16);

            int v = PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))];
            if (v == 1)
                return;

            PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))] = 1;
            PSX.edit = true;
            Settings.EditedPoints[stageId] = true;
        }

        private void SettingBox_Unchecked(object sender, System.Windows.RoutedEventArgs e)
        {
            if (PSX.levels.Count == 0)
                return;

            int stageId = GetSpawnIndex();
            if (stageId == -1)
                return;
            uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + (stageId * 4))));
            uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (MainWindow.window.spawnE.spawnInt.Value * 4)));

            var c = (CheckBox)sender;

            int i = Convert.ToInt32(c.Uid.Split(' ')[0], 16);

            int v = PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))];
            if (v == 0)
                return;

            PSX.exe[PSX.CpuToOffset((uint)(dataAddress + i))] = 0;
            PSX.edit = true;
            Settings.EditedPoints[stageId] = true;
        }
        private void midInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int stageId = GetSpawnIndex();
            if (stageId == -1 || PSX.exe[PSX.CpuToOffset((uint)(Const.MidCheckPointAddress + stageId))] == (byte)(int)e.NewValue)
                return;
            PSX.edit = true;
            PSX.exe[PSX.CpuToOffset((uint)(Const.MidCheckPointAddress + stageId))] = (byte)(int)e.NewValue;
        }
        private void waterInt_ValueChanged(object sender, System.Windows.RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            int offset = GetSpawnIndex();
            if (offset == -1)
                return;

            offset *= 4;
            offset += (int)PSX.CpuToOffset(Const.WaterLevelAddress);


            if (MidCheck())
                offset += 2;

            ushort val = BitConverter.ToUInt16(PSX.exe, offset);
            if (val == (int)e.NewValue)
                return;

            PSX.exe[offset] = (byte)(((int)e.NewValue) & 0xFF);
            PSX.exe[offset + 1] = (byte)(((int)e.NewValue >> 8) & 0xFF);
            PSX.edit = true;
        }
        private async void GOTO_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (GetSpawnIndex() == -1) return;

            if (MainWindow.settings.useNops)
            {
                try
                {
                    ListWindow.checkpoingGo = true;
                    MainWindow.loadWindow = new ListWindow(false);
                    MainWindow.loadWindow.ShowDialog();
                }
                catch (Exception ex)
                {
                    System.Windows.MessageBox.Show(ex.Message, "ERROR");
                }
            }
            else
            {
                try
                {
                    await Redux.Pause();
                    await WriteCheckPoints();
                    await Redux.Write(Const.LivesAddress, (byte)3);
                    await Redux.Write(Const.CheckPointAddress, (byte)(int)spawnInt.Value);
                    await Redux.Write(Const.MegaAliveAddress, (byte)0);
                    await Redux.Resume();
                }catch(System.Net.Http.HttpRequestException ex)
                {
                    System.Windows.MessageBox.Show(ex.Message, "REDUX ERROR");
                }
                catch (Exception ex)
                {
                    System.Windows.MessageBox.Show(ex.Message, "ERROR");
                }
            }
        }
        private void GearBtn_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            if (Settings.ExtractedPoints) //Show window for configuring each point amount
            {
                ListWindow win = new ListWindow(6);
                win.ShowDialog();
            }
            else //Extract
            {
                System.Windows.MessageBox.Show("In order to edit the amount of checkpoints per stage you need to extract the data from the un-edited PSX.EXE");
                using (var fd = new System.Windows.Forms.OpenFileDialog())
                {
                    fd.Filter = "PSX-EXE |*53";
                    fd.Title = "Select MegaMan 8 PSX-EXE";

                    if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        byte[] exe = System.IO.File.ReadAllBytes(fd.FileName);

                        ICSharpCode.SharpZipLib.Checksum.Crc32 crc32 = new ICSharpCode.SharpZipLib.Checksum.Crc32();
                        crc32.Update(exe);

                        if (crc32.Value != Const.Crc)
                        {
                            System.Windows.MessageBox.Show("Modified EXE , CRC is: " + Convert.ToString(crc32.Value, 16) + " it should be: " + Convert.ToString(Const.Crc, 16));
                            return;
                        }
                        else
                        {
                            //Valid EXE (Extract Checkpoints)
                            byte[] data = new byte[24];
                            int pastIndex = -1;

                            System.IO.Directory.CreateDirectory(PSX.filePath + "/CHECKPOINT");
                            foreach (var l in PSX.levels)
                            {
                                int index = l.GetIndex();
                                if (index == pastIndex || index == -1)
                                    continue;
                                else
                                    pastIndex = index;

                                System.IO.MemoryStream ms = new System.IO.MemoryStream();
                                System.IO.BinaryWriter bw = new System.IO.BinaryWriter(ms);

                                for (int i = 0; i < Settings.MaxPoints[index] + 1; i++)
                                {
                                    uint addr = BitConverter.ToUInt32(exe, PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + index * 4)));
                                    uint read = BitConverter.ToUInt32(exe, PSX.CpuToOffset((uint)(addr + i * 4)));

                                    Array.Copy(exe, PSX.CpuToOffset(read), data, 0, 24);
                                    bw.Write(data);
                                }
                                System.IO.File.WriteAllBytes(PSX.filePath + "/CHECKPOINT/" + l.pac.filename + ".BIN", ms.ToArray());
                            }

                            //Done
                            System.Windows.MessageBox.Show("Checkpoints extracted!\nClose the Editor and re-open to be able to edit checkpoint amounts");
                        }
                    }
                }
            }
        }
        #endregion Events
    }
}
