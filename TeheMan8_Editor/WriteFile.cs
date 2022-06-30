namespace TeheMan8_Editor
{
    class WriteFile
    {
        #region Properties
        public uint lba;
        public string name;
        public string path;
        public int size;
        #endregion

        #region Constructors
        internal WriteFile()
        {

        }
        internal WriteFile(uint lba, string name, string path,int size)
        {
            this.lba = lba;
            this.name = name;
            this.path = path;
            this.size = size;
        }
        #endregion Constructors
    }
}
