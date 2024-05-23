using ICSharpCode.SharpZipLib.Checksum;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;

namespace TeheMan8_Editor
{
    class Settings
    {
        #region Constants
        public static byte[] MaxPoints = new byte[Const.MaxPoints.Length];
        #endregion Constants

        #region Fields
        public static bool ExtractedPoints;
        public static bool[] EditedPoints = new bool[Const.MaxPoints.Length];
        static public bool error = false;
        static public Process nops = new Process()
        {
            StartInfo = new ProcessStartInfo()
            {
                FileName = "nops.exe",
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                CreateNoWindow = true
            }
        };
        #endregion Fields

        #region Properties
        public string webPort; //Redux
        public string comPort; //NOPS
        public bool useNops;
        public int referanceWidth;
        public bool dontUpdate;
        public bool saveOnReload;
        public bool dontSaveLayout;
        public bool autoScreen; //open layout viewer for screens automatically
        public bool autoExtra;  //open extra screen tile flags viewer
        public bool autoFiles;  //open files viewer
        public bool dontResetId;
        #endregion Properties

        #region Methods
        public static void DefineCheckpoints()
        {
            ExtractedPoints = false;
            if (Directory.Exists(PSX.filePath + "/CHECKPOINT"))
            {
                Crc32 crc32 = new Crc32();
                crc32.Update(PSX.exe);
                long oldCrc = crc32.Value;

                uint freeDataAddress = 0x80137b34;
                int pastIndex = -1;

                foreach (var l in PSX.levels)
                {
                    int index = l.GetIndex();
                    if (index == pastIndex || index == -1)
                        continue;
                    else
                        pastIndex = index;
                    EditedPoints[index] = false;
                    int checkPoint = 0;
                    BinaryReader br = new BinaryReader(new MemoryStream(File.ReadAllBytes(PSX.filePath + "/CHECKPOINT/" + l.pac.filename + ".BIN")));
                    List<uint> pointAddresses = new List<uint>();
                    while (true) //Copy Checkpoint Data & Fix each Pointer
                    {
                        //Dump Data
                        br.ReadBytes(24).CopyTo(PSX.exe, PSX.CpuToOffset(freeDataAddress));
                        pointAddresses.Add(freeDataAddress);
                        checkPoint++;
                        freeDataAddress += 24;

                        if (br.BaseStream.Position == br.BaseStream.Length)
                        {
                            MaxPoints[index] = (byte)(checkPoint - 1);
                            break;
                        }
                    }
                    //Fix stage specfic pointer
                    BitConverter.GetBytes(freeDataAddress).CopyTo(PSX.exe, PSX.CpuToOffset(Const.CheckPointPointersAddress) + index * 4);
                    foreach (var i in pointAddresses)
                    {
                        BitConverter.GetBytes(i).CopyTo(PSX.exe, PSX.CpuToOffset(freeDataAddress));
                        freeDataAddress += 4;
                    }
                }
                ExtractedPoints = true;

                crc32 = new Crc32();
                crc32.Update(PSX.exe);
                if (oldCrc != crc32.Value)
                    PSX.edit = true;
            }
            else
            {
                Const.MaxPoints.CopyTo(MaxPoints, 0);
                ExtractedPoints = false;
            }
        }
        public static Settings SetDefaultSettings()
        {
            Settings s = new Settings();
            s.webPort = "8080";
            s.comPort = "5";
            s.useNops = false;
            s.saveOnReload = true;
            return s;
        }
        public void CheckForValidSettings()
        {
            if (webPort == null)
                webPort = "8080";
            if (comPort == null)
                comPort = "5";
        }
        public static bool IsPastVersion(string ver)
        {
            foreach (var v in Const.pastVersions)
            {
                if (v == ver)
                    return true;
            }
            return false;
        }
        #endregion Methods
    }
}
