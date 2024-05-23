using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ToolsWindow.xaml
    /// </summary>
    public partial class ToolsWindow : Window
    {
        #region Fields
        public static bool textureToolsOpen;
        public static bool soundToolsOpen;
        public static bool isoToolsOpen;
        public static bool otherToolsOpen;
        #endregion Fields

        #region Constructors
        public ToolsWindow()
        {
            InitializeComponent();
            textureExpand.IsExpanded = textureToolsOpen;
            soundExpand.IsExpanded = soundToolsOpen;
            isoExpand.IsExpanded = isoToolsOpen;
            otherExpand.IsExpanded = otherToolsOpen;
        }
        #endregion Constructors

        #region Events
        private void texBmpBtn_Click(object sender, RoutedEventArgs e) //Extract TEX as BMP
        {
            using (var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Open an MegaMan 8 PAC Files that contains Textures";
                fd.Multiselect = true;
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                    sfd.Description = "Select BMP Save Location";
                    sfd.UseDescriptionForTitle = true;
                    if ((bool)sfd.ShowDialog())
                    {
                        List<string> files = new List<string>(); //Files with No Textures
                        int texturesCount = 0;
                        for (int f = 0; f < fd.FileNames.Length; f++)
                        {
                            var file = File.ReadAllBytes(fd.FileNames[f]);
                            var pac = new PAC(file);
                            var pal = new BitmapPalette(Const.GreyScale);
                            int i = 0; //Per PAC

                            //Check each Entry
                            foreach (var en in pac.entries)
                            {
                                if (en.type >> 8 != 1)
                                    continue;
                                try
                                {
                                    BmpBitmapEncoder encoder = new BmpBitmapEncoder();
                                    var b = new byte[en.data.Length];
                                    Array.Copy(en.data, 0, b, 0, en.data.Length);
                                    var bmp = new WriteableBitmap(256, en.data.Length / 128, 96, 96, PixelFormats.Indexed4, pal);

                                    int lc = 0;
                                    while (lc != b.Length)
                                    {
                                        var n1 = (b[lc] & 0xF) << 4;
                                        var n2 = (b[lc] >> 4) + n1;
                                        b[lc] = (byte)n2;
                                        lc++;
                                    }


                                    bmp.WritePixels(new Int32Rect(0, 0, 256, en.data.Length / 128), b, 128, 0);
                                    encoder.Frames.Add(BitmapFrame.Create(bmp));
                                    var s = File.Create(sfd.SelectedPath + "\\" + fd.SafeFileNames[f] + "_" + "TEX" + Convert.ToString(i, 16).PadLeft(2, '0') + ".bmp");
                                    encoder.Save(s);
                                    s.Close();
                                }
                                catch (ArgumentException)
                                {
                                    System.Windows.MessageBox.Show(fd.SafeFileNames[f] + " is corrupted or doesnt follow the PAC File Format", "ERROR");
                                    continue;
                                }
                                catch (Exception ex)
                                {
                                    System.Windows.MessageBox.Show(ex.Message, "ERROR in " + fd.SafeFileNames[f]);
                                    return;
                                }
                                i++;
                                texturesCount++;
                            }
                            if (i == 0)
                                files.Add(fd.SafeFileNames[f]);
                        }
                        //Extraction Completed
                        if (texturesCount != 0)
                            System.Windows.MessageBox.Show("Textures Extracted");
                        else
                        {
                            System.Windows.MessageBox.Show("Non of these PAC files had Textures embed in them");
                            return;
                        }
                        if (files.Count != 0)
                        {
                            string s = "";
                            foreach (var f in files)
                            {
                                s = "," + f + " ";
                            }
                            var c = s.ToCharArray();
                            s = new string(c, 1, s.Length - 1);
                            System.Windows.MessageBox.Show("The Following Files had no Textures in them:\n\n" + s);
                        }
                    }
                }
            }
        }
        private void texBinBtn_Click(object sender, RoutedEventArgs e) //Extract TEX as BIN
        {
            using(var fd =  new OpenFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Open an MegaMan 8 PAC Files that contains Textures";
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var file = File.ReadAllBytes(fd.FileName);
                    var pac = new PAC(file);
                    if(pac.entries.Count == 0)
                    {

                    }
                    var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                    sfd.Description = "Select BIN Save Location";
                    sfd.UseDescriptionForTitle = true;
                    if ((bool)sfd.ShowDialog())
                    {
                        int i = 0;
                        //Check each Entry
                        foreach (var en in pac.entries)
                        {
                            if (en.type >> 8 != 1)
                                continue;
                            File.WriteAllBytes(sfd.SelectedPath + "\\" + fd.SafeFileName + "_" + "TEX" + Convert.ToString(i,16).PadLeft(2,'0') + ".BIN", en.data);
                            i++;
                        }
                        if (i == 0)
                            System.Windows.MessageBox.Show("There are no textures in\nThis PAC File", "ERROR");
                        else
                            System.Windows.MessageBox.Show("Textures Extracted");
                    }
                }
            }
        }

        private void inertTexBtn_Click(object sender, RoutedEventArgs e) //INSERT TEX as BMP
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Open an MegaMan 8 PAC Files that contains Textures";
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var pac = new PAC(File.ReadAllBytes(fd.FileName));
                    pac.path = fd.FileName;
                    int amount = 0;
                    foreach (var en in pac.entries)
                    {
                        if (en.type >> 8 != 1)
                            continue;
                        amount++;
                    }
                    if (amount == 0)
                    {
                        System.Windows.MessageBox.Show("There are no textures in\n" + fd.SafeFileName);
                        return;
                    }
                    var lw = new ListWindow(pac,0);
                    lw.Title = fd.SafeFileName + " Textures";
                    lw.ShowDialog(); ;
                }
            }
        }

        private void insertBinBtn_Click(object sender, RoutedEventArgs e) //INSERT TEX as BIN
        {
            using (var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Open an MegaMan 8 PAC Files that contains Textures";
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var pac = new PAC(File.ReadAllBytes(fd.FileName));
                    pac.path = fd.FileName;
                    int amount = 0;
                    foreach (var en in pac.entries)
                    {
                        if (en.type >> 8 != 1)
                            continue;
                        amount++;
                    }
                    if (amount == 0)
                    {
                        System.Windows.MessageBox.Show("There are no textures in\n" + fd.SafeFileName);
                        return;
                    }
                    var lw = new ListWindow(pac, 1);
                    lw.Title = fd.SafeFileName + " Textures";
                    lw.ShowDialog(); ;
                }
            }
        }

        private void extractIsoBtn_Click(object sender, RoutedEventArgs e)
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "ISO |*BIN";
                fd.Title = "Open an ISO 9660 File";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    if(fd.SafeFileName.Contains("(Track "))
                    {
                        System.Windows.MessageBox.Show("Multi Track ISO's are not supported", "ERROR");
                        return;
                    }
                    var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                    sfd.Description = "Select Files Save Location";
                    sfd.UseDescriptionForTitle = true;
                    if ((bool)sfd.ShowDialog())
                    {
                        PSX.Extract(fd.FileName,sfd.SelectedPath);
                    }
                }
            }
        }
        private void replaceBtn_Click(object sender, RoutedEventArgs e)
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "ISO |*BIN";
                fd.Title = "Open an ISO 9660 File";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    PSX.OpenFileBrowser(fd.FileName);
                }
            }
        }
        private void vabExtBtn_Click(object sender, RoutedEventArgs e) //EXTRACT VAB
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*PAC";
                fd.Title = "Open an MegaMan 8 PAC File";
                fd.Multiselect = true;
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                    sfd.Description = "Select VAB Files Save Location";
                    sfd.UseDescriptionForTitle = true;
                    if ((bool)sfd.ShowDialog())
                    {
                        try
                        {
                            int total = 0;
                            for (int f = 0; f < fd.FileNames.Length; f++)
                            {
                                var pac = new PAC(File.ReadAllBytes(fd.FileNames[f]));
                                int count = 0;

                                byte[] vabHeader = null; //TODO: doesnt copy the correct data if Multi files are selected
                                byte[] vabData = null;
                                byte[] vabHeader2 = null;
                                byte[] vabData2 = null;
                                foreach (var en in pac.entries)
                                {
                                    if ((en.type >> 8) != 2 && en.type != 3 && en.type != 4)
                                        continue;
                                    if (en.type == 3 || en.type == 4)
                                    {
                                        count++;
                                        total++;
                                        if (en.type == 3)
                                        {
                                            vabHeader = new byte[en.data.Length];
                                            Array.Copy(en.data, vabHeader, en.data.Length);
                                        }
                                        else
                                        {
                                            vabHeader2 = new byte[en.data.Length];
                                            Array.Copy(en.data, vabHeader2, en.data.Length);
                                        }
                                    }
                                    else
                                    {
                                        if ((en.type & 0xFF) == 0)
                                            vabData = en.data;
                                        else
                                            vabData2 = en.data;
                                    }
                                }
                                if(count != 0)
                                {
                                    if (vabHeader != null)
                                    {
                                        var vabFile = new byte[vabHeader.Length + vabData.Length];
                                        Array.Copy(vabHeader, vabFile, vabHeader.Length);
                                        Array.Copy(vabData, 0, vabFile, vabHeader.Length, vabData.Length);
                                        File.WriteAllBytes(sfd.SelectedPath + "\\" + fd.SafeFileNames[f] + "_" + "VAB1" + Convert.ToString(count, 16).PadLeft(2, '0') + ".vab", vabFile);
                                    }
                                    if(vabHeader2 != null)
                                    {
                                        var vabFile = new byte[vabHeader2.Length + vabData2.Length];
                                        Array.Copy(vabHeader2, vabFile, vabHeader2.Length);
                                        Array.Copy(vabData2, 0, vabFile, vabHeader2.Length, vabData2.Length);
                                        File.WriteAllBytes(sfd.SelectedPath + "\\" + fd.SafeFileNames[f] + "_" + "VAB2" + Convert.ToString(count, 16).PadLeft(2, '0') + ".vab", vabFile);
                                    }
                                }
                            }
                            if (total != 0)
                                System.Windows.MessageBox.Show("VAB Export Completed");
                        }
                        catch (Exception ex)
                        {
                            System.Windows.MessageBox.Show(ex.Message, "ERROR");
                        }
                    }
                }
            }
        }

        private void vabInsertBtn_Click(object sender, RoutedEventArgs e) //INSERT VAB
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*PAC";
                fd.Title = "Open an MegaMan 8 PAC File containing VAB data";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    PAC pac = new PAC(File.ReadAllBytes(fd.FileName));
                    string savePath = fd.FileName;
                    int id = -1; //Entry index for Header
                    int id2 = -1; //Index for data
                    for (int i = 0; i < pac.entries.Count; i++)
                    {
                        if ((pac.entries[i].type >> 8) != 2)
                            continue;
                        id = i;
                        break;
                    }
                    for (int i = 0; i < pac.entries.Count; i++)
                    {
                        if (pac.entries[i].type != 3 && pac.entries[i].type != 4)
                            continue;
                        id2 = i;
                        break;
                    }
                    if(id == -1 || id2 == -1)
                    {
                        System.Windows.MessageBox.Show("There is no VAB data in this PAC File", "ERROR");
                        return;
                    }
                    string save = fd.FileName;
                    fd.FileName = "";
                    fd.Filter = "VAB |*vab";
                    fd.Title = "Select an PSX VAB File";

                    if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        byte[] vab = File.ReadAllBytes(fd.FileName);
                        //Get VH & VB
                        ushort programC = BitConverter.ToUInt16(vab, 18);
                        int vbOffset = 512 + 0x820 + (32 * 16 * programC);

                        byte[] vabHeader = new byte[vbOffset];
                        Array.Copy(vab, vabHeader, vbOffset);

                        byte[] vabBody = new byte[vab.Length - vbOffset];
                        Array.Copy(vab, vbOffset, vabBody, 0, vabBody.Length);

                        //Save PAC File
                        pac.entries[id].data = vabBody;
                        pac.entries[id2].data = vabHeader;
                        File.WriteAllBytes(save, pac.GetEntriesData());
                        System.Windows.MessageBox.Show("PAC VAB Data Saved!");
                    }
                }
            }
        }

        private void seqExtBtn_Click(object sender, RoutedEventArgs e) //EXTRACT SEQ
        {
            using (var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*PAC";
                fd.Title = "Open an MegaMan 8 PAC File containing SEQ Data";
                fd.Multiselect = true;
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                    sfd.Description = "Select SEQ Files Save Location";
                    sfd.UseDescriptionForTitle = true;
                    if ((bool)sfd.ShowDialog())
                    {
                        try
                        {
                            bool seqflag = false;
                            for (int f = 0; f < fd.FileNames.Length; f++)
                            {
                                PAC pac = new PAC(File.ReadAllBytes(fd.FileNames[f]));


                                foreach (var en in pac.entries)
                                {
                                    if (en.type != 1)
                                        continue;
                                    //SEQ data found
                                    File.WriteAllBytes(sfd.SelectedPath + "\\" + fd.SafeFileNames[f] + "_" + ".seq", en.data);
                                    seqflag = true;
                                    break;
                                }
                            }
                            if (seqflag)
                                System.Windows.MessageBox.Show("SEQ Export Completed!");
                            else
                                System.Windows.MessageBox.Show("Non of these PAC files have SEQ data in them","ERROR");
                        }
                        catch (Exception ex)
                        {
                            System.Windows.MessageBox.Show(ex.Message, "ERROR");
                        }
                    }
                }
            }
        }
        private void seqInsertBtn_Click(object sender, RoutedEventArgs e) //INSERT SEQ
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "PAC |*PAC";
                fd.Title = "Open an MegaMan 8 PAC File containing SEQ data";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    PAC pac = new PAC(File.ReadAllBytes(fd.FileName));
                    string savePath = fd.FileName;
                    int id = -1; //Entry index
                    for (int i = 0; i < pac.entries.Count; i++)
                    {
                        if (pac.entries[i].type != 1)
                            continue;
                        id = i;
                        break;
                    }
                    if(id == -1)
                    {
                        System.Windows.MessageBox.Show("There is no SEQ data in this PAC File", "ERROR");
                        return;
                    }
                    //SEQ Data Found
                    fd.Filter = "SEQ |*seq";
                    fd.Title = "Select PSX SEQ File";
                    fd.FileName = "";
                    if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        try
                        {
                            pac.entries[id].data = File.ReadAllBytes(fd.FileName);
                            File.WriteAllBytes(savePath, pac.GetEntriesData());
                        }catch(Exception ex)
                        {
                            System.Windows.MessageBox.Show(ex.Message, "ERROR");
                            return;
                        }
                        //SEQ Import Completed
                        System.Windows.MessageBox.Show("SEQ Import Completed");
                    }
                }
            }
        }
        private void fixBtn_Click(object sender, RoutedEventArgs e)
        {
            using (var fd = new OpenFileDialog())
            {
                fd.Filter = "PSX-EXE |*53";
                fd.Title = "Select MegaMan 8 PSX-EXE";
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    using(var fd2 = new OpenFileDialog())
                    {
                        try
                        {
                            fd2.Filter = "C HEADER |*h";
                            fd2.Title = "Select C Header File Contain Files LBA";
                            if (fd2.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                            {
                                string[] lines = File.ReadAllLines(fd2.FileName);
                                MemoryStream ms = new MemoryStream(File.ReadAllBytes(fd.FileName));
                                BinaryWriter bw = new BinaryWriter(ms);

                                foreach (var line in lines)
                                {
                                    if (line.Trim() == "")
                                        continue;
                                    string[] words = System.Text.RegularExpressions.Regex.Replace(line.Trim(), " {2,}", " ").Split();
                                    if (words[0] != "#define")
                                        continue;

                                    foreach (var file in Const.DiscFiles)
                                    {
                                        if (file != words[1])
                                            continue;
                                        int i = Array.FindIndex(Const.DiscFiles, x => x.Contains(file));
                                        i *= 12;
                                        i += (int)PSX.CpuToOffset(Const.FileDataAddress, 0x800C0000);
                                        bw.BaseStream.Position = i;

                                        int sector;
                                        if (words[2].Contains("0x"))
                                            sector = Convert.ToInt32(words[2], 16);
                                        else
                                            sector = Convert.ToInt32(words[2]);
                                        bw.Write(sector);
                                    }
                                }
                                //Save PSX.EXE
                                File.WriteAllBytes(fd.FileName, ms.ToArray());
                                System.Windows.MessageBox.Show("LBA Fixed !");
                            }
                        }catch(Exception ex)
                        {
                            System.Windows.MessageBox.Show(ex.Message);
                        }
                    }
                }
            }
        }
        private void tracksBtn_Click(object sender, RoutedEventArgs e)
        {

        } 
        private void gameSettingsBtn_Click(object sender, RoutedEventArgs e)
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "PSX-EXE |*53";
                fd.Title = "Select MegaMan 8 PSX-EXE";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    GameSettingsWindow s = new GameSettingsWindow(fd.FileName);
                    s.Show();
                }
            }
        }
        private void createPacBtn_Click(object sender, RoutedEventArgs e)
        {
            ListWindow listWindow = new ListWindow(new PAC());
            listWindow.ShowDialog();
        }

        private void editPacBtn_Click(object sender, RoutedEventArgs e)
        {
            using(var fd = new OpenFileDialog())
            {
                fd.Filter = "|*.PAC;*ARC";
                fd.Title = "Open an MegaMan 8 PAC File or an MegaMan X4 ARC File";
                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    PAC pac = new PAC(File.ReadAllBytes(fd.FileName));
                    if(pac.entries.Count == 0)
                    {
                        System.Windows.MessageBox.Show(pac.filename + " is an invalid PAC file", "ERROR");
                        return;
                    }
                    pac.filename = Path.GetFileName(fd.FileName);
                    ListWindow listWindow = new ListWindow(pac);
                    listWindow.ShowDialog();
                }
            }
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            textureToolsOpen = textureExpand.IsExpanded;
            soundToolsOpen = soundExpand.IsExpanded;
            isoToolsOpen = isoExpand.IsExpanded;
            otherToolsOpen = otherExpand.IsExpanded;
        }
        #endregion Events
    }
}
