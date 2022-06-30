using Newtonsoft.Json;
using System;
using System.IO;

namespace TeheMan8_Builder
{
    class Program
    {
        #region Fields
        public static Cache cache;
        public static bool expand = false;
        public static string newName;
        #endregion Fields
        static void Main(string[] args)
        {
            if(args.Length < 2)
            {
                Console.WriteLine("TeheMan 8 CD Builder ver 1.0 by twitch.tv/kuumba_");
                Console.WriteLine("Usage: TeheMan8_Builder.exe <Game-Directory> <Save-File> <para> <para>\n");
                Console.WriteLine("Optional Parameters (IMPORTANT)");
                Console.WriteLine(string.Format("\t-exp\tenable building a bigger ISO to allow bigger file sizes ({0} vs {1})", Const.TotalSectors[0], Const.TotalSectors[1]));
                return;
            }
            if (!WriteFile.FileCheck(args[0])) //Check for all Game Files
            {
                Console.WriteLine("ERROR: cant find - " + WriteFile.missing);
                return;
            }
            if (File.Exists("Cache.json"))
            {
                //TODO: use Cache.json for build optimizations
            }
            if(args.Length > 2)
            {
                for (int i = 2; i < args.Length; i++)
                {
                    if (args[i] == "-exp")
                        expand = true;
                }
            }
            ISO.FreshExport(args[0], args[1]);
        }
    }
}
