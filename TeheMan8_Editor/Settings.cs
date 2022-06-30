using System.Diagnostics;

namespace TeheMan8_Editor
{
    class Settings
    {
        #region Fields
        static public bool error = false;
        static public string message;
        static public Process builder = new Process()
        {
            StartInfo = new ProcessStartInfo()
            {
                FileName = @"TeheMan8_Builder.exe",
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                CreateNoWindow = true
            }
        };
        #endregion Fields

        #region Properties
        public string buildArgs;
        public bool outputBuild;
        public bool saveOnExport;
        public bool enableExpandedPac;
        #endregion Properties

        #region Constructors
        public Settings()
        {

        }
        #endregion Constructors

        #region Methods
        public static Settings SetDefaultSettings()
        {
            Settings s = new Settings();
            s.buildArgs = "";
            s.outputBuild = true;
            s.saveOnExport = true;
            s.enableExpandedPac = false;
            return s;
        }
        #endregion Methods
    }
}
