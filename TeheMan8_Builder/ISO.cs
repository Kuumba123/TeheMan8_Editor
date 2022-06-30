using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace TeheMan8_Builder
{
    static class ISO
    {
        #region Fields
        static BinaryWriter bw;
        static FileStream fs;
        static List<WriteFile> movieFiles = new List<WriteFile>();
        static List<WriteFile> ovlFiles = new List<WriteFile>();
        static List<WriteFile> soundFiles = new List<WriteFile>();
        static List<WriteFile> stageFiles = new List<WriteFile>();
        static DateTime currentTime;
        static byte[] sector = new byte[0x930];
        public static byte[] exe;
        #endregion Fields

        #region Methods
        public static void FreshExport(string dir, string save)
        {
            try
            {
                int i = 0;
                if (Program.expand)
                    i = 1;
                fs = File.Create(save);
                currentTime = DateTime.Now;
                bw = new BinaryWriter(fs);
                PrepareGameFiles(dir);
                int totalSectorSize = 575;
                int movieSectorSize = GetFilesSectorSize(movieFiles);
                int ovlSectorSize = GetFilesSectorSize(ovlFiles);
                int soundSectorSize = GetFilesSectorSize(soundFiles);
                int stageSectorSize = GetFilesSectorSize(stageFiles);
                int moveInfoSize = GetDirectoryInfoSize(movieFiles);
                int ovlInfoSize = GetDirectoryInfoSize(ovlFiles);
                int soundInfoSize = GetDirectoryInfoSize(soundFiles);
                int stageInfoSize = GetDirectoryInfoSize(stageFiles);
                totalSectorSize += movieSectorSize + ovlSectorSize + soundSectorSize + stageSectorSize;
                totalSectorSize += moveInfoSize + ovlInfoSize + soundInfoSize + stageInfoSize;
                if(totalSectorSize >= Const.MaxFilesSectorSize[i] + 1)
                {
                    Console.WriteLine("ERROR: MAX files sector count is " + Const.MaxFilesSectorSize[i] + 1);
                    return;
                }
                //Start Dumping
                var rooFolders = new List<WriteFile>();
                //Set ISO 9660 LBA for Files in Directory
                ApplyDirectoryFilesLba(movieFiles, 575 + moveInfoSize);
                ApplyDirectoryFilesLba(ovlFiles, 575 + ovlInfoSize + moveInfoSize + movieSectorSize);
                ApplyDirectoryFilesLba(soundFiles, 575 + soundInfoSize + ovlInfoSize + ovlSectorSize + moveInfoSize + movieSectorSize);
                ApplyDirectoryFilesLba(stageFiles, 575 + stageInfoSize + soundInfoSize + soundSectorSize + ovlInfoSize + ovlSectorSize + moveInfoSize + movieSectorSize);
                //Set LBA Table in PSX-EXE
                ApplySectorLocations(movieFiles, 2);
                ApplySectorLocations(ovlFiles, 8);
                ApplySectorLocations(soundFiles, 23);
                ApplySectorLocations(stageFiles, 94);
                //Set Song Sector
                Array.Copy(BitConverter.GetBytes(Const.SongSector[i]), 0, exe, 0x77DF4, 4);
                //Root Folders
                rooFolders.Add(new WriteFile(575, "MOVIE"));
                rooFolders.Add(new WriteFile(575 + moveInfoSize + movieSectorSize, "OVL"));
                rooFolders.Add(new WriteFile(575 + ovlInfoSize + ovlSectorSize + moveInfoSize + movieSectorSize, "SOUND"));
                rooFolders.Add(new WriteFile(575 + soundInfoSize + soundSectorSize + ovlInfoSize + ovlSectorSize + moveInfoSize + movieSectorSize, "STDATA"));
                //Setup ISO 9660 PATH TABLE
                {
                    //Path Tables and Root Directory (LSB)
                    Array.Copy(BitConverter.GetBytes(rooFolders[0].lba), 0, Const.PathTableLSB, 0xC, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[1].lba), 0, Const.PathTableLSB, 0x1A, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[2].lba), 0, Const.PathTableLSB, 0x26, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[3].lba), 0, Const.PathTableLSB, 0x34, 4);
                    //Path Table and Root Directory (MSB)
                    Array.Copy(BitConverter.GetBytes(rooFolders[0].lba).Reverse().ToArray(), 0, Const.PathTableMSB, 0xC, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[1].lba).Reverse().ToArray(), 0, Const.PathTableMSB, 0x1A, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[2].lba).Reverse().ToArray(), 0, Const.PathTableMSB, 0x26, 4);
                    Array.Copy(BitConverter.GetBytes(rooFolders[3].lba).Reverse().ToArray(), 0, Const.PathTableMSB, 0x34, 4);
                    //Root Dir (TODO: clean this up)
                    Const.MainDir[0x9A] = (byte)(rooFolders[0].lba & 0xFF);
                    Const.MainDir[0x9A + 1] = (byte)((rooFolders[0].lba >> 8) & 0xFF);
                    Const.MainDir[0x9A + 2] = (byte)((rooFolders[0].lba >> 16) & 0xFF);
                    Const.MainDir[0x9A + 3] = (byte)((rooFolders[0].lba >> 24) & 0xFF);
                    Const.MainDir[0x9A + 4] = BitConverter.GetBytes(rooFolders[0].lba).ToArray()[3];
                    Const.MainDir[0x9A + 5] = BitConverter.GetBytes(rooFolders[0].lba).ToArray()[2];
                    Const.MainDir[0x9A + 6] = BitConverter.GetBytes(rooFolders[0].lba).ToArray()[1];
                    Const.MainDir[0x9A + 7] = BitConverter.GetBytes(rooFolders[0].lba).ToArray()[0];



                    Const.MainDir[0xCE] = (byte)(rooFolders[1].lba & 0xFF);
                    Const.MainDir[0xCE + 1] = (byte)((rooFolders[1].lba >> 8) & 0xFF);
                    Const.MainDir[0xCE + 2] = (byte)((rooFolders[1].lba >> 16) & 0xFF);
                    Const.MainDir[0xCE + 3] = (byte)((rooFolders[1].lba >> 24) & 0xFF);
                    Const.MainDir[0xCE + 4] = BitConverter.GetBytes(rooFolders[1].lba).ToArray()[3];
                    Const.MainDir[0xCE + 5] = BitConverter.GetBytes(rooFolders[1].lba).ToArray()[2];
                    Const.MainDir[0xCE + 6] = BitConverter.GetBytes(rooFolders[1].lba).ToArray()[1];
                    Const.MainDir[0xCE + 7] = BitConverter.GetBytes(rooFolders[1].lba).ToArray()[0];


                    Const.MainDir[0x13C] = (byte)(rooFolders[2].lba & 0xFF);
                    Const.MainDir[0x13C + 1] = (byte)((rooFolders[2].lba >> 8) & 0xFF);
                    Const.MainDir[0x13C + 2] = (byte)((rooFolders[2].lba >> 16) & 0xFF);
                    Const.MainDir[0x13C + 3] = (byte)((rooFolders[2].lba >> 24) & 0xFF);
                    Const.MainDir[0x13C + 4] = BitConverter.GetBytes(rooFolders[2].lba).ToArray()[3];
                    Const.MainDir[0x13C + 5] = BitConverter.GetBytes(rooFolders[2].lba).ToArray()[2];
                    Const.MainDir[0x13C + 6] = BitConverter.GetBytes(rooFolders[2].lba).ToArray()[1];
                    Const.MainDir[0x13C + 7] = BitConverter.GetBytes(rooFolders[2].lba).ToArray()[0];

                    Const.MainDir[0x170] = (byte)(rooFolders[3].lba & 0xFF);
                    Const.MainDir[0x170 + 1] = (byte)((rooFolders[3].lba >> 8) & 0xFF);
                    Const.MainDir[0x170 + 2] = (byte)((rooFolders[3].lba >> 16) & 0xFF);
                    Const.MainDir[0x170 + 3] = (byte)((rooFolders[3].lba >> 24) & 0xFF);
                    Const.MainDir[0x170 + 4] = BitConverter.GetBytes(rooFolders[3].lba).ToArray()[3];
                    Const.MainDir[0x170 + 5] = BitConverter.GetBytes(rooFolders[3].lba).ToArray()[2];
                    Const.MainDir[0x170 + 6] = BitConverter.GetBytes(rooFolders[3].lba).ToArray()[1];
                    Const.MainDir[0x170 + 7] = BitConverter.GetBytes(rooFolders[3].lba).ToArray()[0];
                }
                //Start Disc Build Process
                if(Program.expand)
                    Console.WriteLine("Now starting Expanded CD Build");
                else
                    Console.WriteLine("Now starting Normal CD Build");
                bw.Write(Const.PSX_SectorData);
                GotoNextSector();
                Console.WriteLine("PSX Logo + Liscenes has been written");
                //Volume Descritor
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x090000);
                bw.Write(0x090000);
                //Set Sector Count in  Volume Descriptor
                Array.Copy(BitConverter.GetBytes(Const.TotalSectors[i]), 0, Const.VolDesc, 80, 4);
                Array.Copy(BitConverter.GetBytes(Const.TotalSectors[i]).Reverse().ToArray(), 0, Const.VolDesc, 84, 4);
                bw.Write(Const.VolDesc);
                GotoNextSector();
                Console.WriteLine("ISO 9660 Volume Descriptor has been written");

                //CD001 - Text
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.DiscTag);
                GotoNextSector();
                //LSB Path Table
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.PathTableLSB);
                GotoNextSector();
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.PathTableLSB);
                GotoNextSector();
                //MSB Path Table
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.PathTableMSB);
                GotoNextSector();
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.PathTableMSB);

                Console.WriteLine("ISO 9660 Path Tables have been written");

                GotoNextSector();
                //Main Dir
                bw.Write(Const.Sync);
                bw.Write(GetSectorTime());
                bw.Write(0x890000);
                bw.Write(0x890000);
                bw.Write(Const.MainDir);
                GotoNextSector();

                //Dump PSX-EXE
                WriteFile(exe);
                //SYSTEM.CNF
                WriteFile(File.ReadAllBytes(dir + "/SYSTEM.CNF"));

                Console.WriteLine("PSX.EXE & SYSTEM.CNF have been written");

                //Actual Game Files
                bw.Write(GetDirectorySectors(movieFiles));
                DumpFiles(movieFiles);

                Console.WriteLine("Folder - \"MOVIE\" have been written");

                bw.Write(GetDirectorySectors(ovlFiles));
                DumpFiles(ovlFiles);

                Console.WriteLine("Folder - \"OVL\" have been written");

                bw.Write(GetDirectorySectors(soundFiles));
                DumpFiles(soundFiles);

                Console.WriteLine("Folder - \"SOUND\" have been written");

                bw.Write(GetDirectorySectors(stageFiles));
                DumpFiles(stageFiles);

                Console.WriteLine("Folder - \"STDATA\" have been written");

                GotoNextSector();
                ClearSector();
                Array.Copy(Const.Sync, sector, Const.Sync.Length);

                while (true)
                {
                    if (bw.BaseStream.Position > (Const.MaxFilesSectorSize[i] * 0x930))
                        break;
                    Array.Copy(GetSectorTime(), 0, sector, 0xC, 4);
                    WriteSector();
                }
                ClearSector();
                while (true)
                {
                    if (bw.BaseStream.Position >= (Const.SongSector[i] * 0x930))
                        break;
                    WriteSector();
                }
                bw.Write(new byte[0x18]);
                //Add END1.DA (Ending Theme)
                bw.Write(File.ReadAllBytes(dir + "/END1.DA"), 0, 0x2C83F20);
                Console.WriteLine("File - \"END1.DA\" (ending theme) has been written");

                if (bw.BaseStream.Position < (Const.TotalSectors[i] * 0x930))
                {
                    bw.BaseStream.Position = (Const.TotalSectors[i] * 0x930) - 1;
                    bw.Write((byte)0);
                }
                //Start Writting out CUE FILE
                string cueFileName = save.Replace(".BIN", ".cue").Replace(".bin",".cue");

                StreamWriter sw = File.CreateText(cueFileName);
                sw.WriteLine(string.Format("FILE \"{0}\" BINARY\n  TRACK 01 MODE2/2352", Path.GetFileName(save)));
                if (!Program.expand)
                {
                    sw.WriteLine("    INDEX 01 00:00:00\n  TRACK 02 AUDIO\n    INDEX 00 31:34:46\n    INDEX 01 31:36:46\n  TRACK 03 AUDIO\n    INDEX 00 36:01:17\n    INDEX 01 36:03:17");
                    sw.Close();
                }
                else
                {   //TODO: set different Time Code
                    sw.WriteLine("    INDEX 01 00:00:00\n  TRACK 02 AUDIO\n    INDEX 00 62:42:41\n    INDEX 01 62:44:41\n  TRACK 03 AUDIO\n    INDEX 00 67:09:12\n    INDEX 01 67:11:12");
                    sw.Close();
                }
                Console.WriteLine("New CUE Sheet Generated");

                //Build Finished
                bw.Close();
                fs.Close();
                Console.WriteLine("Build Completed!");
            }
            catch(Exception e)
            {
                Console.WriteLine("ERROR: " + e.Message);
            }
        }
        private static void ApplyDirectoryFilesLba(List<WriteFile> l, int lbaBase) //For each File in Folder
        {
            int lba = lbaBase;
            foreach (var r in l)
            {
                if (!r.name.Contains(".STR"))
                {
                    r.lba = lba;
                    if (r.data.Length % 0x800 != 0)
                        lba++;
                    lba += r.data.Length / 0x800;
                }
                else
                {
                    r.lba = lba;
                    if (r.data.Length % 0x920 != 0)
                        lba++;
                    lba += r.data.Length / 0x920;
                }
            }
        }
        private static void ApplySectorLocations(List<WriteFile> l, int baseId)
        {
            for (int i = 0; i < l.Count; i++)
            {
                int size = l[i].data.Length;
                int lba = l[i].lba;
                int o = (baseId * 12) + (i * 12);
                if (l[i].name == "WILY.PAC")
                    o = 0x88 * 12;
                else if (l[i].name == "W_DEVIL.PAC")
                    o = 0x89 * 12;

                //LBA
                Array.Copy(BitConverter.GetBytes(lba), 0, exe, o + Const.FileTableOffset, 4);
                //Size
                Array.Copy(BitConverter.GetBytes(size), 0, exe, o + 4 + Const.FileTableOffset, 4);
            }
        }
        private static int GetDirectoryInfoSize(List<WriteFile> l)
        {
            int sectorCount = 1;
            int offset = 0;
            int i = 0;
            foreach (var r in l)
            {
            Start:
                if (i < 2)
                {
                    i++;
                    offset += 0x30;
                    goto Start;
                }
                int space = 0x800;
                if (offset != 0)
                    space = 0x800 - offset;
                int length = r.name.Length + 0x21 + 2 + (((r.name.Length + 2) & 1) ^ 1) + 0xE /*<= Extra PSX Info*/;
                if (space < length)
                {
                    offset = 0;
                    sectorCount++;
                }
                offset += length;
            }
            return sectorCount;
        }
        private static int GetFilesSectorSize(List<WriteFile> l)
        {
            int size = 0;
            foreach (var r in l)
            {
                if (!r.name.Contains(".STR"))
                {
                    if (r.data.Length % 0x800 != 0)
                        size++;
                    size += r.data.Length / 0x800;
                }
                else
                {
                    if (r.data.Length % 0x920 != 0)
                        size++;
                    size += r.data.Length / 0x920;
                }
            }
            return size;
        }
        private static int GetFileSectorSize(WriteFile r)
        {
            int size = 0;
            if (!r.name.Contains(".STR"))
            {
                if (r.data.Length % 0x800 != 0)
                    size++;
                size += r.data.Length / 0x800;
            }
            else
            {
                if (r.data.Length % 0x920 != 0)
                    size++;
                size += r.data.Length / 0x920;
            }
            return size;
        }
        public static void PrepareGameFiles(string dir)
        {
            exe = File.ReadAllBytes(dir + "/SLUS_004.53");
            //MOVIE FILES
            movieFiles.Add(new WriteFile() { data = File.ReadAllBytes(dir + "/MOVIE/CAPCOM15.STR"), name = "CAPCOM15.STR" });
            for (int i = 0; i < 5; i++)
            {
                var f = new WriteFile();
                f.name = "ROCK8_" + i + ".STR";
                f.data = File.ReadAllBytes(dir + "/MOVIE/ROCK8_" + i + ".STR");
                movieFiles.Add(f);
            }
            //OVL FILES
            ovlFiles = new List<WriteFile>();
            {
                var f = new WriteFile();
                f.name = "DEMO.BIN";
                f.data = File.ReadAllBytes(dir + "/OVL/DEMO.BIN");
                ovlFiles.Add(f);
            }
            for (int i = 0; i < 0xE; i++)
            {
                var f = new WriteFile();
                f.name = "STAGE0" + Convert.ToString(i, 16).ToUpper() + ".BIN";
                f.data = File.ReadAllBytes(dir + "/OVL/STAGE0" + Convert.ToString(i, 16).ToUpper() + ".BIN");
                ovlFiles.Add(f);
            }
            //SOUND FILES
            soundFiles = new List<WriteFile>();
            for (int i = 0; i < 0x46; i++)
            {
                var f = new WriteFile();
                f.name = "PBGM" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                f.data = File.ReadAllBytes(dir + "/SOUND/PBGM" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC");
                soundFiles.Add(f);
            }
            {
                var f = new WriteFile();
                f.name = "PCOMMON.PAC";
                f.data = File.ReadAllBytes(dir + "/SOUND/PCOMMON.PAC");
                soundFiles.Add(f);
            }
            //STDATA FILES
            stageFiles = new List<WriteFile>();
            {
                string[] bossFiles = new string[]
              {
                "BOSSAQU.PAC","BOSSAST.PAC","BOSSCLO.PAC","BOSSDUO.PAC","BOSSFRO.PAC",
                "BOSSGRE.PAC","BOSSSEA.PAC","BOSSSWD.PAC","BOSSTNG.PAC" };
                for (int i = 0; i < bossFiles.Length; i++)
                {
                    var f = new WriteFile();
                    f.name = bossFiles[i];
                    f.data = File.ReadAllBytes(dir + "/STDATA/" + bossFiles[i]);
                    stageFiles.Add(f);
                }
            }
            {
                {
                    string[] addFiles = { "COMNCHAR.PAC", "ENDING.PAC", "GETDEMO.PAC", "LABO.PAC", "OVER.PAC",
                        "PDEMO00.PAC", "PDEMO01.PAC","PDEMO02.PAC","PDEMO03.PAC","PDEMO04.PAC" };
                    for (int i = 0; i < addFiles.Length; i++)
                    {
                        var f = new WriteFile();
                        f.name = addFiles[i];
                        f.data = File.ReadAllBytes(dir + "/STDATA/" + addFiles[i]);
                        stageFiles.Add(f);
                    }
                }
                {
                    //PLAYER.PAC & SELECT.PAC
                    var f = new WriteFile();
                    f.name = "PLAYER.PAC";
                    f.data = File.ReadAllBytes(dir + "/STDATA/PLAYER.PAC");
                    stageFiles.Add(f);
                    var f2 = new WriteFile();
                    f2.name = "SELECT.PAC";
                    f2.data = File.ReadAllBytes(dir + "/STDATA/SELECT.PAC");
                    stageFiles.Add(f2);
                }
                //STAGEXX.PAC & STAGEXXB.PAC
                for (int i = 0; i < 0xE; i++)
                {
                    var f = new WriteFile();
                    f.name = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                    f.data = File.ReadAllBytes(dir + "/STDATA/STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC");
                    stageFiles.Add(f);
                    if (i > 1 && i < 9)
                    {
                        var f2 = new WriteFile();
                        f2.name = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC";
                        f2.data = File.ReadAllBytes(dir + "/STDATA/STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC");
                        stageFiles.Add(f2);
                    }
                }
                {   //Add Last Few PAC Files
                    var f = new WriteFile();
                    f.name = "WILY.PAC";
                    f.data = File.ReadAllBytes(dir + "/STDATA/WILY.PAC");
                    stageFiles.Add(f);
                    var f2 = new WriteFile();
                    f2.name = "W_DEVIL.PAC";
                    f2.data = File.ReadAllBytes(dir + "/STDATA/W_DEVIL.PAC");
                    stageFiles.Add(f2);
                }
            }
        }
        private static byte[] GetDirectorySectors(List<WriteFile> l)
        {
            MemoryStream ms = new MemoryStream();
            BinaryWriter w = new BinaryWriter(ms);
            long headerOffset = 0;
            int offset = 0;
            int sectorL = 0;
            int i = 0;
            w.Write(Const.Sync);
            w.Write(GetSectorTime());
            headerOffset = w.BaseStream.Position;
            w.Write(0x80000);
            w.Write(0x80000);
            /*Time Parameters*/
            byte year = (byte)(currentTime.Year - 1900);
            byte month = (byte)currentTime.Month;
            byte day = (byte)currentTime.Day;
            byte hour = (byte)currentTime.Hour;
            byte min = (byte)currentTime.Minute;
            byte sec = (byte)currentTime.Second;

            foreach (var r in l)
            {
            Start:
                if (i < 2)
                {
                    w.Write((ushort)0x30);
                    if(i == 0)
                    {
                        w.Write((int)(bw.BaseStream.Position / 0x930));
                        w.Write(BitConverter.GetBytes((int)(bw.BaseStream.Position / 0x930)).Reverse().ToArray());
                    }
                    else
                    {
                        w.Write(0x16);
                        w.Write(0x16000000);
                    }
                    w.Write(0x800);
                    w.Write(0x80000);

                    w.Write(year);
                    w.Write(month);
                    w.Write(day);
                    w.Write(hour);
                    w.Write(min);
                    w.Write(sec);
                    w.Write((byte)0);

                    w.Write((byte)2);
                    w.Write((ushort)0);
                    w.Write((ushort)1);
                    w.Write((ushort)0x0100);
                    w.Write((byte)1);
                    w.Write((byte)i);
                    w.Write(new byte[] { 00, 00, 00, 00, 0x8D, 0x55, 0x58, 0x41, 00, 00, 00, 00, 00, 00 });
                    i++;
                    offset += 0x30;
                    goto Start;
                }
                int space = 0x800;
                if (offset != 0)
                    space = 0x800 - offset;
                int length = r.name.Length + 0x21 + 2 + (((r.name.Length + 2) & 1) ^ 1) + 0xE /*<= Extra PSX Info*/;
                if (space < length)
                {
                    sectorL++;
                    while (true)
                    {
                        if (w.BaseStream.Position % 0x930 == 0)
                            break;
                        w.Write((byte)0);
                    }
                    w.Write(Const.Sync);
                    w.Write(GetSectorTime(sectorL));
                    headerOffset = w.BaseStream.Position;
                    w.Write(0x80000);
                    w.Write(0x80000);
                    offset = 0;
                }
                int size = r.data.Length;

                offset += length;
                w.Write((byte)length); //Length
                w.Write((byte)0);   //Extend Attri Record Length
                w.Write(r.lba); //LBA LSB
                w.Write(BitConverter.GetBytes(r.lba).Reverse().ToArray()); //LBA MSB

                if (r.name.Contains(".STR"))
                    size = GetMovieNormalFileSize(r);

                w.Write(size);    //Size LSB
                w.Write(BitConverter.GetBytes(size).Reverse().ToArray()); //Size LSB
                //Write Time Related Info
                w.Write(year);
                w.Write(month);
                w.Write(day);
                w.Write(hour);
                w.Write(min);
                w.Write(sec);
                w.Write((byte)0);

                w.Write((byte)0); //Flag
                w.Write((byte)0); //...
                w.Write((byte)0); //..
                w.Write((ushort)1); //Vol Noun LSB
                w.Write((ushort)0x100);//Vol Noun MSB
                w.Write((byte)(r.name.Length + 2)); //File Name Length
                var name = (r.name + ";1").ToArray();
                w.Write(name);
                if (((r.name.Length + 2) & 1) == 0) //Padding
                    w.Write((byte)0);

                //Extra PSX Info (0xE bytes)
                w.Write(0); // Group & User Id
                if (!r.name.Contains(".STR"))
                    w.Write((ushort)0x550D);
                else
                    w.Write((ushort)0x5525);
                /*"XA" Text*/
                w.Write('X');
                w.Write('A');
                if (!r.name.Contains(".STR"))
                    w.Write((byte)0);
                else
                    w.Write((byte)1);
                w.Write(0);
                w.Write((byte)0);

            }
            //add filler
            while (true)
            {
                if ((w.BaseStream.Position % 0x930) == 0)
                    break;
                w.Write((byte)0);
            }
            w.BaseStream.Position = headerOffset;
            w.Write(0x890000);
            w.Write(0x890000);
            return ms.ToArray();
        }
        private static void WriteFile(byte[] data)
        {

            int size = data.Length;
            int addr_R = 0;
            ClearSector();
            while (size != 0)
            {
                ClearSector();
                Array.Copy(Const.Sync, sector, Const.Sync.Length);
                Array.Copy(GetSectorTime(), 0, sector, 0xC, 3);
                sector[0xF] = 2;
                sector[0x12] = 8;
                sector[0x16] = 8;
                if (size > 0x800)
                {
                    Array.Copy(data, addr_R, sector, 0x18, 0x800);
                    WriteSector();
                    addr_R += 0x800;
                    size -= 0x800;
                }
                else
                {
                    Array.Copy(data, addr_R, sector, 0x18, size);
                    sector[0x12] = 0x89;
                    sector[0x16] = 0x89;
                    WriteSector();
                    break;
                }
            }
            GotoNextSector();
        }
        private static void DumpFiles(List<WriteFile> l)
        {
            foreach (var r in l)
            {
                int lba = (int)r.lba;
                int size = r.data.Length;
                int addr_R = 0;
                while (size != 0)
                {
                    ClearSector();
                    Array.Copy(Const.Sync, sector, Const.Sync.Length);
                    Array.Copy(CdIntToPos((int)(bw.BaseStream.Position / 0x930)), 0, sector, 0xC, 3);
                    sector[0xF] = 2;
                    sector[0x12] = 8;
                    sector[0x16] = 8;
                    if (!r.name.Contains(".STR"))
                    {
                        if (size > 0x800)
                        {
                            Array.Copy(r.data, addr_R, sector, 0x18, 0x800);
                            WriteSector();
                            addr_R += 0x800;
                            size -= 0x800;
                            lba++;
                        }
                        else
                        {
                            Array.Copy(r.data, addr_R, sector, 0x18, size);
                            sector[0x12] = 0x89;
                            sector[0x16] = 0x89;
                            WriteSector();
                            break;
                        }
                    }
                    else
                    {
                        if (size > 0x920)
                        {
                            Array.Copy(r.data, addr_R, sector, 0x10, 0x920);
                            WriteSector();
                            addr_R += 0x920;
                            size -= 0x920;
                        }
                        else
                        {
                            Array.Copy(r.data, addr_R, sector, 0x10, size);
                            WriteSector();
                            break;
                        }
                    }
                }
                GotoNextSector();
            }
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
        private static void GotoNextSector()
        {
            while (true)
            {
                if (bw.BaseStream.Position % 0x930 == 0)
                    break;
                bw.Write((byte)0);
            }
        }
        private static byte[] GetSectorTime()
        {
            byte[] time = CdIntToPos((int)(bw.BaseStream.Position / 0x930));
            Array.Resize(ref time, 4);
            time[3] = 2;
            return time;
        }
        private static byte[] GetSectorTime(int sectAdd)
        {
            byte[] time = CdIntToPos((int)(bw.BaseStream.Position / 0x930) + sectAdd);
            Array.Resize(ref time, 4);
            time[3] = 2;
            return time;
        }
        private static void WriteSector()
        {
            bw.Write(sector);
        }
        private static void ClearSector()
        {
            for (int i = 0; i < sector.Length; i++)
            {
                sector[i] = 0;
            }
        }
        private static int GetMovieNormalFileSize(WriteFile r)
        {
            return r.data.Length - (GetFileSectorSize(r) * 0x120);
        }
        public static uint CpuToOffset(uint cpu)
        {
            return (uint)(cpu - BitConverter.ToInt32(exe, 0x18) + 0x800);
        }
#endregion Methods
    }
}
