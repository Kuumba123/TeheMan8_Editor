using System;
using System.Collections.Generic;
using System.Linq;

namespace TeheMan8_Editor
{
    public class PAC
    {
        #region Properties
        public List<Entry> entries = new List<Entry>();
        public string path;
        public string filename;
        public string error;
        public bool isMSB = false;
        #endregion Properties

        #region Constructors
        public PAC()
        {
        }
        public PAC(byte[] data)
        {
            if (data.Length < 0x800)
                return;
            int fileSize = BitConverter.ToInt32(data, 4);
            if (fileSize == BitConverter.ToInt32(BitConverter.GetBytes(data.Length).Reverse().ToArray(), 0))
            {
                fileSize = BitConverter.ToInt32(BitConverter.GetBytes(fileSize).Reverse().ToArray(), 0);
                isMSB = true;
            }
            else if (fileSize != data.Length)
            {
                return;
            }

            int type;
            int size;
            int o = 0x800;
            try
            {
                int fileCount = BitConverter.ToInt32(data, 0);
                if (isMSB)
                {
                    fileCount = BitConverter.ToInt32(BitConverter.GetBytes(fileCount).Reverse().ToArray(), 0);
                }
                for (int i = 0; i < fileCount; i++)
                {
                    if (i == 0)
                    {
                        type = BitConverter.ToInt32(data, 8);
                        size = BitConverter.ToInt32(data, 0xC);
                    }
                    else
                    {
                        type = BitConverter.ToInt32(data, (i - 1) * 8 + 0x10);
                        size = BitConverter.ToInt32(data, (i - 1) * 8 + 0x14);
                    }
                    if (isMSB)
                    {
                        type = BitConverter.ToInt32(BitConverter.GetBytes(type).Reverse().ToArray(),0);
                        size = BitConverter.ToInt32(BitConverter.GetBytes(size).Reverse().ToArray(), 0);
                    }

                    //Add in new Entry
                    var e = new Entry();
                    e.type = type & 0xFFFF;
                    e.data = new byte[size];
                    Array.Copy(data, o, e.data, 0, size);
                    entries.Add(e);
                    //Sector Padding
                    if ((size % 0x800) != 0)
                        o += 0x800 - (size % 0x800) + size;
                    else
                        o += size;
                }
            }
            catch(Exception e)
            {
                error = e.Message;
            }
        }
        #endregion Constructors

        #region Methods
        public byte[] LoadEntry(int id)
        {
            foreach (var e in entries)
            {
                if (e.type != id)
                    continue;
                return e.data;
            }
            return null;
        }
        public void LoadEntry(int id,byte[] dump)
        {
            for (int i = 0; i < this.entries.Count; i++)
            {
                if (entries[i].type != id)
                    continue;
                Array.Copy(entries[i].data, dump,entries[i].data.Length);
                return;
            }
        }
        public void SaveEntry(int id,byte[] dump)
        {
            for (int i = 0; i < this.entries.Count; i++)
            {
                if (entries[i].type != id)
                    continue;
                Array.Resize(ref entries[i].data, dump.Length);
                Array.Copy(dump, entries[i].data, dump.Length);
                return;
            }
        }
        public void SaveTrimedEntry(int id,byte[] dump)
        {
            for (int i = 0; i < this.entries.Count; i++)
            {
                if (entries[i].type != id)
                    continue;
                Array.Copy(dump, entries[i].data, entries[i].data.Length);
                return;
            }
        }
        public byte[] GetEntriesData()  //With Filler + Header
        {
            int size = 0x800;
            //Calculate Size of byte Array
            foreach (var e in entries)
            {
                int s = e.data.Length;
                if(s % 0x800 != 0)
                {
                    s += 0x800 - (s % 0x800);
                }
                size += s;
            }
            byte[] data = new byte[size]; //+0x800 cus Header

            int addr_W = 0x800;
            foreach (var e in entries)
            {
                Array.Copy(e.data, 0, data, addr_W, e.data.Length);
                int s = e.data.Length;
                //Padding
                if(s % 0x800 != 0)
                {
                    s += 0x800 - (s % 0x800);
                }
                addr_W += s;
            }
            addr_W = 0;
            for (int i = 0; i < entries.Count; i++)
            {
                if (i == 0)
                {
                    //Amount of Entries
                    data[0] = (byte)(entries.Count & 0xFF);
                    data[1] = (byte)((entries.Count >> 8) & 0xFF);
                    data[2] = (byte)((entries.Count >> 16) & 0xFF);
                    data[3] = (byte)((entries.Count >> 24) & 0xFF);
                    //File Size
                    data[4] = (byte)(size & 0xFF);
                    data[5] = (byte)((size >> 8) & 0xFF);
                    data[6] = (byte)((size >> 16) & 0xFF);
                    data[7] = (byte)((size >> 24) & 0xFF);
                    //Type
                    data[8] = (byte)(entries[i].type & 0xFF);
                    data[9] = (byte)((entries[i].type >> 8) & 0xFF);
                    data[0xA] = (byte)((entries[i].type >> 16) & 0xFF);
                    data[0xB] = (byte)((entries[i].type >> 24) & 0xFF);
                    //Size
                    data[0xC] = (byte)(entries[i].data.Length & 0xFF);
                    data[0xD] = (byte)((entries[i].data.Length >> 8) & 0xFF);
                    data[0xE] = (byte)((entries[i].data.Length >> 16) & 0xFF);
                    data[0xF] = (byte)((entries[i].data.Length >> 24) & 0xFF);
                    continue;
                }
                //Type
                data[((i - 1) * 8) + 0x10] = (byte)(entries[i].type & 0xFF);
                data[((i - 1) * 8) + 0x11] = (byte)((entries[i].type >> 8) & 0xFF);
                data[((i - 1) * 8) + 0x12] = (byte)((entries[i].type >> 16) & 0xFF);
                data[((i - 1) * 8) + 0x13] = (byte)((entries[i].type >> 24) & 0xFF);
                //Size
                data[((i - 1) * 8) + 0x14] = (byte)(entries[i].data.Length & 0xFF);
                data[((i - 1) * 8) + 0x15] = (byte)((entries[i].data.Length >> 8) & 0xFF);
                data[((i -  1) * 8) + 0x16] = (byte)((entries[i].data.Length >> 16) & 0xFF);
                data[((i - 1) * 8) + 0x17] = (byte)((entries[i].data.Length >> 24) & 0xFF);
            }
            return data;
        }
        public bool ContainsEntry(int type)
        {
            for (int i = 0; i < entries.Count; i++)
            {
                if (entries[i].type != type)
                    continue;
                return true;
            }
            return false;
        }
        public int GetIndexOfType(int type)
        {
            for (int i = 0; i < entries.Count; i++)
            {
                if (entries[i].type != type)
                    continue;
                return i;
            }
            return -1;
        }
        public int GetEntrySize(int id)
        {
            foreach (var e in entries)
            {
                if (e.type != id)
                    continue;
                return e.data.Length;
            }
            return -1;
        }
        public int GetSize()
        {
            int size = 0;
            foreach (var e in entries)
            {
                size += e.data.Length;
            }
            return size;
        }
        #endregion Methods
    }
}
