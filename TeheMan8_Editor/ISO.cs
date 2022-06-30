using System;
using System.Collections.Generic;
using System.IO;
using System.Text.RegularExpressions;

namespace TeheMan8_Editor
{
    static class ISO
    {
        #region Fields
        static string strTheseAreInvalidFileNameChars = new string(Path.GetInvalidFileNameChars());
        static Regex regInvalidFileName = new Regex("[" + Regex.Escape(strTheseAreInvalidFileNameChars) + "]");
        static byte[] sector = new byte[0x800];
        static public List<Level> levels = new List<Level>();
        static public byte[] exe;
        static public bool edit = false;
        static public string filePath;
        static public string lastSave;
        static public DateTime time; //for EXE
        static BinaryReader br;
        #endregion Fields

        #region Methods
        public static void Extract(string path, string save)
        {
            try
            {
                br = new BinaryReader(File.OpenRead(path));
                //Check to See if this is ISO 9660
                br.BaseStream.Position = 0x18 + (0x930 * 16);
                sector = br.ReadBytes(sector.Length);
                if (System.Text.Encoding.ASCII.GetString(sector, 1, 5) != "CD001")
                {
                    System.Windows.MessageBox.Show("Not a valid ISO 9660 Image");
                    return;
                }
                var rootFolders = new List<Folder>();
                //Get LBA Volume Location
                uint lba = BitConverter.ToUInt32(sector, 140);
                br.BaseStream.Position = 0x18 + (0x930 * lba);
                sector = br.ReadBytes(sector.Length);

                int offset = 0;
                //Get Folders in 'Path Table'
                while (true)
                {
                    int idSize = sector[offset];
                    if (idSize == 0)
                        break;
                    uint foldLBA = BitConverter.ToUInt32(sector, offset + 2);
                    string folderName = System.Text.Encoding.ASCII.GetString(sector, 8 + offset, idSize);
                    if (folderName != "\0")
                    {
                        rootFolders.Add(new Folder(foldLBA, folderName, save + "\\" + folderName));
                        Directory.CreateDirectory(save + "\\" + folderName);
                    }
                    offset += 9 + idSize;
                }
                var subFolders = new List<Folder>();
                var files = new List<WriteFile>();
                //For Files (TODO: maybe check if there is NO root files)
                rootFolders.Add(new Folder(BitConverter.ToUInt32(sector, 2), null, null));
            //Get Files in Directory
            ReadFolders:
                uint extra = 0;
                foreach (var f in rootFolders)
                {
                    offset = 0;
                    extra = 0;
                    br.BaseStream.Position = GetSectorOffset(f.lba);
                    ReadSector();
                    while (true)
                    {
                        if (offset >= 0x7D0)
                        {
                            extra++;
                            br.BaseStream.Position = GetSectorOffset(f.lba + extra);
                            ReadSector();
                            offset = 0;
                        }
                        int recordSize = sector[offset];
                        if (recordSize == 0)
                            break;
                        uint location = BitConverter.ToUInt32(sector, offset + 2);
                        int fileSize = BitConverter.ToInt32(sector, offset + 10);
                        string fileName = System.Text.Encoding.ASCII.GetString(sector, offset + 33, sector[32 + offset]);
                        if (fileName == "\0")
                        {
                            offset += recordSize;
                            continue;
                        }
                        if (!regInvalidFileName.IsMatch(fileName))
                        {
                            if (fileName.Contains(";1")) //Is File
                            {
                                if (f.name != null)
                                {
                                    fileName = fileName.Replace(";1", "");
                                    files.Add(new WriteFile(location, fileName, f.path, fileSize));
                                }
                                else
                                {
                                    fileName = fileName.Replace(";1", "");
                                    files.Add(new WriteFile(location, fileName, save, fileSize));
                                }
                            }
                            else //Is Folder
                            {
                                if (f.name != null)
                                {
                                    subFolders.Add(new Folder(location, fileName, f.path + "\\" + fileName));
                                    Directory.CreateDirectory(f.path + "\\" + fileName);
                                }
                                else
                                {
                                    subFolders.Add(new Folder(lba, fileName, save));
                                    if (!Directory.Exists(save + "\\" + fileName))
                                        Directory.CreateDirectory(save + "\\" + fileName);
                                }
                            }
                        }
                        offset += recordSize;
                    }
                }
                rootFolders.Clear();
                for (int i = 0; i < subFolders.Count; i++)
                {
                    rootFolders.Add(subFolders[0]);
                    subFolders.RemoveAt(0);
                }
                if (rootFolders.Count != 0)
                    goto ReadFolders;
                foreach (var f in files)
                {
                    ExtractFile(f.lba, (uint)f.size, f.path + "\\" + f.name, f.name);
                }
            }
            catch (Exception e)
            {
                System.Windows.MessageBox.Show(e.Message);
            }
        }
        private static void ExtractFile(uint lba, uint fileSize, string save, string filename)
        {
            byte[] data;
            int o = 0;

            if (!filename.Contains(".STR") && !filename.Contains(".XA"))
                data = new byte[0x800];
            else if (filename.Contains(".DA"))
            {
                data = new byte[0x930];
                o = 0x18;
            }
            else
            {
                data = new byte[0x920];
                o = 8;
            }

            var bw = new BinaryWriter(File.Create(save));
            br.BaseStream.Position = GetSectorOffset(lba) - o;
            while (fileSize != 0)
            {
                if (filename.Contains(".DA"))
                {
                    if(fileSize >= 0x800)
                    {
                        data = br.ReadBytes(0x930);
                        bw.Write(data);
                        fileSize -= 0x800;
                        if (fileSize <= 0)
                            break;
                    }
                    else
                    {
                        data = br.ReadBytes((int)fileSize);
                        bw.Write(data, 0, (int)fileSize);
                        fileSize = 0;
                    }
                }
                else if (!filename.Contains(".STR") && !filename.Contains(".XA"))
                {
                    if (fileSize > 0x800)
                    {
                        data = br.ReadBytes(0x800);
                        bw.Write(data);
                        br.BaseStream.Position += 0x130;
                        fileSize -= 0x800;
                        if (fileSize == 0)
                            break;
                    }
                    else
                    {
                        data = br.ReadBytes((int)fileSize);
                        bw.Write(data, 0, (int)fileSize);
                        fileSize = 0;
                    }
                }
                else
                {
                    if (true)
                    {
                        data = br.ReadBytes(0x920);
                        bw.Write(data);
                        br.BaseStream.Position += 0x10;
                        fileSize -= 0x800;
                    }
                }
            }
            bw.Close();
        }
        public static byte[] CdIntToPos(int i) //Absolute Sector => Time Code
        {
            int v3 = (i + 0x96) / 0x4B;
            int v2 = (i + 0x96) % 0x4B;
            int v1 = v3 / 0x3C;
            v3 = v3 % 0x3C;

            var time = new byte[3];

            time[1] = (byte)((byte)v3 + ((byte)(v3 / 10)) * 6);
            time[2] = (byte)((byte)v2 + ((byte)(v2 / 10)) * 6);
            time[0] = (byte)((byte)v1 + ((byte)(v1 / 10)) * 6);
            return time;
        }
        public static int CdPosToInt(byte[] i) //Time Code => Absolute Sector
        {
            return (((i[0] >> 4) * 10 + (i[0] & 0xF)) * 0x3C + (i[1] >> 4) * 10 + (i[1] & 0xF)) * 0x4B + (i[2] >> 4) * 10 + (i[2] & 0xF) + -150;
        }
        public static uint CpuToOffset(uint cpu)
        {
            return (uint)(cpu - BitConverter.ToInt32(exe, 0x18) + 0x800);
        }
        public static uint CpuToOffset(uint cpu,uint text)
        {
            return cpu - text + 0x800;
        }
        private static long GetSectorOffset(uint lba)
        {
            return 0x18 + (lba * 0x930);
        }
        private static void ReadSector()
        {
            sector = br.ReadBytes(sector.Length);
        }
        #endregion Methods
    }
}
