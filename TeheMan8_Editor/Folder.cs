namespace TeheMan8_Editor
{
    class Folder
    {
        #region Properties
        public uint lba;
        public string name;
        public string path;
        #endregion Properties

        #region Constructors
        public Folder(uint lba, string name, string path)
        {
            this.lba = lba;
            this.name = name;
            this.path = path;
        }
        #endregion Constructors
    }
}
