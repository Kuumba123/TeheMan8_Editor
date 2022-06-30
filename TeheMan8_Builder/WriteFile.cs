using System;
using System.IO;

namespace TeheMan8_Builder
{
    class WriteFile
    {
        public int lba;
        public string name;
        public byte[] data;
        public bool isFolder = false;
        public static string missing;
        public WriteFile()
        {

        }
        public WriteFile(int lba,string name)
        {
            this.lba = lba;
            this.name = name;
            isFolder = true;
        }
        public static bool FileCheck(string path)
        {
            //Check Movie Files
            if (!File.Exists(path + "/MOVIE/CAPCOM15.STR"))
            {
                missing = "CAPCOM15.STR";
                return false;
            }
            for (int i = 0; i < 5; i++)
            {
                if(!File.Exists(path + "/MOVIE/ROCK8_" + i + ".STR"))
                {
                    missing = "ROCK8_" + i + ".STR";
                    return false;
                }
            }
            //Check Overlay Files
            if (!File.Exists(path + "/OVL/DEMO.BIN"))
            {
                missing = "DEMO.BIN";
                return false;
            }
            for (int i = 0; i < 0xE; i++)
            {
                if(!File.Exists(path + "/OVL/STAGE0" + Convert.ToString(i,16).ToUpper() + ".BIN"))
                {
                    missing = "STAGE0" + Convert.ToString(i, 16).ToUpper() + ".BIN";
                    return false;
                }
            }
            //Check Sound Files
            if(!File.Exists(path + "/SOUND/PCOMMON.PAC"))
            {
                missing = "PCOMMON.PAC";
                return false;
            }
            for (int i = 0; i < 0x46; i++)
            {
                if(!File.Exists(path + "/SOUND/PBGM" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                {
                    missing = "PBGM" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                    return false;
                }
            }
            //Check Stage Data Files
            string[] bossFiles = new string[]
            {
                "BOSSAQU.PAC","BOSSAST.PAC","BOSSCLO.PAC","BOSSDUO.PAC","BOSSFRO.PAC",
                "BOSSGRE.PAC","BOSSSEA.PAC","BOSSSWD.PAC","BOSSTNG.PAC","OVER.PAC",
                "ENDING.PAC","GETDEMO.PAC","COMNCHAR.PAC","LABO.PAC","PLAYER.PAC","SELECT.PAC","W_DEVIL.PAC","WILY.PAC"};
            for (int i = 0; i < bossFiles.Length; i++)
            {
                if(!File.Exists(path + "/STDATA/" + bossFiles[i]))
                {
                    missing = bossFiles[i];
                    return false;
                }
            }
            if(!File.Exists(path + "/SYSTEM.CNF"))
            {
                missing = "SYSTEM.CNF";
                return false;
            }
            //Root Files
            if (!File.Exists(path + "/END1.DA") && !File.Exists(path + "/END1.WAV"))
            {
                missing = "END1.DA";
                return false;
            }
            for (int i = 0; i < 0xE; i++)
            {
                if(!File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                {
                    missing = "STAGE0" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                    return false;
                }
            }
            for (int i = 0; i < 0xE; i++)
            {
                if (i == 0 || i == 1 || i > 8)
                    continue;
                if (!File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                {
                    missing = "STAGE0" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC";
                    return false;
                }
            }
            if (!File.Exists(path + "/SLUS_004.53"))
            {
                missing = "SLUS_004.53";
                return false;
            }
            return true;
        }
    }
}
