using System.Diagnostics;

namespace TeheMan8_Editor
{
    class Settings
    {
        #region Fields
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
        public bool useFast;
        public bool noScreenReload;
        public bool noClutReload;
        public bool saveOnReload;
        #endregion Properties

        #region Methods
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
        #endregion Methods
    }
}
