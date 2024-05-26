using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor
{
    class Level
    {
        #region Properties
        public PAC pac;
        public byte[] layout;
        public byte[] layout2;
        public byte[] layout3;
        public byte[] screenData;
        public byte[] tileInfo;
        public byte[] pal;
        public List<Enemy> enemies = new List<Enemy>();
        public bool edit = false;
        public DateTime time;
        #endregion Properties

        #region Fields
        public static byte[] pixels = new byte[0x80000];
        public static int Id = 0;
        public static int BG = 0;
        public static bool textureSupport; //8bpp Textures
        public static WriteableBitmap[] bmp = new WriteableBitmap[16 + 4];
        public static BitmapPalette[] palette = new BitmapPalette[0x80];
        #endregion Fields

        #region Methods
        public static void LoadLevels(string path)
        {
            PSX.levels.Clear();

            /*8bpp Texture Support*/
            Visibility visibility;
            int max;
            string Texture8bpp = "TEXTURE_8BPP";
            if (System.Text.Encoding.ASCII.GetString(PSX.exe, PSX.CpuToOffset(0x800F9ED4), Texture8bpp.Length) == Texture8bpp)
            {
                visibility = Visibility.Visible;
                max = 0xB;
                textureSupport = true;
            }
            else
            {
                visibility = Visibility.Collapsed;
                max = 7;
                textureSupport = false;
            }
            MainWindow.window.screenE.pageInt.Maximum = max;
            MainWindow.window.x16E.pageInt.Maximum = max;
            Forms.ClutEditor.maxPage = max;

            for (int i = 0; i < 4; i++)
            {
                ((System.Windows.Controls.Button)MainWindow.window.x16E.tPagePannel.Children[9 + i]).Visibility = visibility;
                ((System.Windows.Controls.Button)MainWindow.window.clutE.pagePannel.Children[9 + i]).Visibility = visibility;
            }

            //Main Levels
            for (int i = 0; i < 0xE; i++)
            {
                if (File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                {
                    int o = PSX.levels.Count;
                    PSX.levels.Add(new Level());
                    PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"));
                    PSX.levels[o].pac.filename = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                    PSX.levels[o].pac.path = path;
                    PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC");
                }
                if (File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC"))
                {
                    int o = PSX.levels.Count;
                    PSX.levels.Add(new Level());
                    PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC"));
                    PSX.levels[o].pac.filename = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC";
                    PSX.levels[o].pac.path = path;
                    PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC");
                }
            }

            //Sub Levels
            string[] subLevels = { "ENDING.PAC", "GETDEMO.PAC", "LABO.PAC", "SELECT.PAC", "WILY.PAC" };
            for (int i = 0; i < subLevels.Length; i++)
            {
                if (!File.Exists(path + "/STDATA/" + subLevels[i]))
                    continue;
                int o = PSX.levels.Count;
                PSX.levels.Add(new Level());
                PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + subLevels[i]));
                PSX.levels[o].pac.filename = subLevels[i];
                PSX.levels[o].pac.path = path;
                PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + subLevels[i]);
            }
            //DEMO Levels...
            for (int i = 0; i < 5; i++)
            {
                if (!File.Exists(path + "/STDATA/" + "PDEMO" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                    continue;
                int o = PSX.levels.Count;
                PSX.levels.Add(new Level());
                PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + "PDEMO" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"));
                PSX.levels[o].pac.filename = "PDEMO" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                PSX.levels[o].pac.path = path;
                PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + "PDEMO" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC");
            }
            foreach (var l in PSX.levels)
                l.ExtractLevelData();
        }
        public static unsafe void Draw16xTile(int id, int x, int y, int stride, IntPtr dest)
        {
            id &= 0xFFF;
            byte* buffer = (byte*)dest;
            int page = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 8) & 0xFF;

            if (page > 0xB || id == 0) // 0 = Empty Tile
            {
                for (int Y = 0; Y < 16; Y++)
                {
                    for (int X = 0; X < 16; X++)
                    {
                        int index = ((x + X) * 3) + (y + Y) * stride;
                        buffer[index] = 0;
                        buffer[index + 1] = 0;
                        buffer[index + 2] = 0;
                    }
                }
                return;
            }

            //Get Tile Info
            int cordX = BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) & 0xF;
            int cordY = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 4) & 0xF;
            int clut = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 16) & 0x3F;

            IntPtr bmpBackBuffer;
            int bmpStride;

            if (page < 8) //4bpp
            {
                bmpBackBuffer = bmp[page + 8].BackBuffer;
                bmpStride = bmp[page].BackBufferStride;

                for (int row = 0; row < 16; row++)
                {
                    int destIndex = (x * 3) + (y + row) * stride;
                    int sourceIndex = (cordX * 8) + ((cordY * 16 + row) * bmpStride);

                    for (int col = 0; col < 16; col++)
                    {
                        byte pixel = *(byte*)(bmpBackBuffer + sourceIndex + (col / 2));

                        if ((col & 1) == 1)
                            pixel &= 0xF;
                        else
                            pixel >>= 4;

                        buffer[destIndex++] = palette[clut + 64].Colors[pixel].R;
                        buffer[destIndex++] = palette[clut + 64].Colors[pixel].G;
                        buffer[destIndex++] = palette[clut + 64].Colors[pixel].B;
                    }
                }
            }
            else //8bpp
            {
                bmpBackBuffer = bmp[(page & 3) + 16].BackBuffer;
                bmpStride = 256;

                for (int row = 0; row < 16; row++)
                {
                    int destIndex = (x * 3) + (y + row) * stride;
                    int sourceIndex = (cordX * 16) + ((cordY * 16 + row) * bmpStride);

                    for (int col = 0; col < 16; col++)
                    {
                        byte pixel;

                        pixel = *(byte*)(bmpBackBuffer + sourceIndex + col);
                        int indexClut = clut + (pixel >> 4);
                        pixel &= 0xF;
                        if ((indexClut * 16 + pixel) > 8191) continue;

                        buffer[destIndex] = palette[indexClut + 64].Colors[pixel].R;
                        buffer[destIndex + 1] = palette[indexClut + 64].Colors[pixel].G;
                        buffer[destIndex + 2] = palette[indexClut + 64].Colors[pixel].B;
                        destIndex += 3;
                    }
                }
            }
        }
        public static void DrawScreen(int s, int stride, IntPtr ptr)
        {
            int total = PSX.levels[Id].screenData.Length / 0x200;
            if (s > total - 1)
                s = 0;
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Draw16xTile(BitConverter.ToUInt16(PSX.levels[Id].screenData, (x * 2) + (y * 0x20) + (0x200 * s)), x * 16, y * 16, stride, ptr);
                }
            }
        }
        public static void DrawScreen(int s, int drawX, int drawY, int stride, IntPtr ptr)
        {
            int total = PSX.levels[Id].screenData.Length / 0x200;
            if (s > total - 1)
                s = 0;
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Draw16xTile(BitConverter.ToUInt16(PSX.levels[Id].screenData, (x * 2) + (y * 0x20) + (0x200 * s)), (x * 16) + drawX, (y * 16) + drawY, stride, ptr);
                }
            }
        }
        public void ExtractLevelData()
        {
            this.layout = this.pac.LoadEntry(0);
            this.layout2 = this.pac.LoadEntry(1);
            this.layout3 = this.pac.LoadEntry(2);
            this.screenData = this.pac.LoadEntry(3);
            this.tileInfo = this.pac.LoadEntry(4);
            this.pal = this.pac.LoadEntry(9);
            this.LoadEnemyData(this.pac.LoadEntry(0xA));
        }
        public void ApplyLevelsToPAC()
        {
            this.pac.SaveEntry(0, this.layout);
            this.pac.SaveEntry(1, this.layout2);
            this.pac.SaveEntry(2, this.layout3);
            this.pac.SaveEntry(3, this.screenData);
            this.pac.SaveEntry(4, this.tileInfo);
            this.pac.SaveEntry(9, this.pal);
            if (this.pac.ContainsEntry(0xA)) //Enemy Data
            {
                byte[] enemyData = new byte[0x800];
                this.DumpEnemyData(enemyData);
                this.pac.SaveEntry(0xA, enemyData);
            }
        }
        public unsafe void LoadTextures()
        {
            //BG Textures
            Array.Clear(pixels, 0, pixels.Length);
            this.pac.LoadEntry(0x0103, pixels);

            //8bpp
            for (int i = 0; i < 4; i++)
            {
                bmp[16 + i].Lock();
                byte* buffer = (byte*)bmp[16 + i].BackBuffer;
                for (int r = 0; r < 256; r++)
                {
                    for (int c = 0; c < 256; c++)
                    {
                        if (c < 128)
                            buffer[r * 256 + c] = pixels[i * 0x10000 + r * 128 + c];
                        else
                            buffer[r * 256 + c] = pixels[i * 0x10000 + 0x8000 + r * 128 + c - 128];
                    }
                }

                bmp[16 + i].AddDirtyRect(new Int32Rect(0, 0, 256, 256));
                bmp[16 + i].Unlock();
            }

            //4bpp
            ConvertBmp(pixels);
            for (int i = 0; i < 8; i++)
                bmp[i + 8].WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 128, i * 0x8000);

            //Object Textures
            Array.Clear(pixels, 0, pixels.Length);
            this.pac.LoadEntry(0x102, pixels);
            ConvertBmp(pixels);
            for (int i = 0; i < 8; i++)
                bmp[i].WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 128, i * 0x8000);

        }
        public byte[] GetSpawnData()
        {
            int index = this.GetIndex();
            byte[] data = new byte[24];

            MemoryStream ms = new MemoryStream();
            BinaryWriter bw = new BinaryWriter(ms);

            for (int i = 0; i < Settings.MaxPoints[index] + 1; i++)
            {
                uint addr = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.CheckPointPointersAddress + index * 4)));
                uint read = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(addr + i * 4)));

                Array.Copy(PSX.exe, PSX.CpuToOffset(read), data, 0, 24);
                bw.Write(data);
            }
            return ms.ToArray();
        }
        private void LoadEnemyData(byte[] data)
        {
            this.enemies.Clear();
            if (data == null)
                return;
            try
            {
                for (int i = 0; i < 255; i++)
                {
                    int offset = i * 8;
                    if (data[offset + 3] == 0xFF)
                        return;

                    //Add New Enemy
                    var e = new Enemy();
                    e.id = data[offset + 1];
                    e.var = data[offset + 2];
                    e.type = data[offset + 3];
                    e.x = BitConverter.ToInt16(data, offset + 4);
                    e.y = BitConverter.ToInt16(data, offset + 6);
                    this.enemies.Add(e);
                }
            }catch(Exception e)
            {
                MessageBox.Show("Something happened while reading " + this.pac.filename + " enemy data\n" + e.Message, "ERROR");
                Application.Current.Shutdown();
            }
        }
        public void DumpEnemyData(byte[] dump)
        {
            BinaryWriter bw = new BinaryWriter(new MemoryStream(dump));
            foreach (var e in this.enemies)
            {
                bw.Write((byte)0);
                bw.Write(e.id);
                bw.Write(e.var);
                bw.Write(e.type);
                bw.Write(e.x);
                bw.Write(e.y);
            }
            bw.Write((byte)0);
            bw.Write((ushort)0);
            bw.Write((byte)0xFF);
        }
        public int GetIndex()
        {
            if (!this.pac.filename.Contains("STAGE"))
                return -1;
            return Convert.ToInt32(this.pac.filename.Replace("STAGE0", "")[0].ToString(), 16);
        }
        public static void AssignPallete()
        {
            //For clut
            for (int b = 0; b < 0x80; b++)
            {
                List<Color> l = new List<Color>();
                for (int i = 0; i < 16; i++)
                {
                    ushort color = BitConverter.ToUInt16(PSX.levels[Id].pal, (i + b * 16) * 2);

                    byte R = (byte)(color % 32 * 8);
                    byte G = (byte)(color / 32 % 32 * 8);
                    byte B = (byte)(color / 1024 % 32 * 8);
                    l.Add(Color.FromRgb(R, G, B));
                }
                palette[b] = new BitmapPalette(l);
            }

            for (int a = 0; a < bmp.Length; a++)
            {
                if (a < 16)
                {
                    if (bmp[a] == null)
                        bmp[a] = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Indexed4, Const.GreyScalePallete);
                }
                else
                {
                    if (bmp[a] == null)
                        bmp[a] = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Indexed8, Const.GreyScalePallete);
                }
            }
        }
        public static void AssignPallete(int clut)
        {
            List<Color> l = new List<Color>();
            for (int i = 0; i < 16; i++)
            {
                ushort color = BitConverter.ToUInt16(PSX.levels[Id].pal, (i + clut * 16) * 2);

                byte R = (byte)(color % 32 * 8);
                byte G = (byte)(color / 32 % 32 * 8);
                byte B = (byte)(color / 1024 % 32 * 8);
                l.Add(Color.FromRgb(R, G, B));
            }
            palette[clut] = new BitmapPalette(l);
        }
        public static int GetClut(int id)
        {
            return (BitConverter.ToInt32(PSX.levels[Level.Id].tileInfo, id * 4) >> 16) & 0x3F;
        }
        public static int To32Rgb(int color)
        {
            byte R = (byte)(color % 32 * 8);
            byte G = (byte)(color / 32 % 32 * 8);
            byte B = (byte)(color / 1024 % 32 * 8);
            return (R << 16) + (G << 8) + B;
        }
        public static int To15Rgb(byte B,byte G,byte R)
        {
            return  B / 8 * 1024 + G / 8 * 32 + R / 8;
        }
        public static int GetSelectedTile(int c, double w, int d)
        {
            int i = (int)w;
            int e = i / d;
            return c / e;
        }
        public static void ConvertBmp(byte[] b)
        {
            //PSX 4bpp => BMP 4bpp
            int lc = 0;
            while (lc != b.Length)
            {
                var n1 = (b[lc] & 0xF) << 4;
                var n2 = (b[lc] >> 4) + n1;
                b[lc] = (byte)n2;
                lc++;
            }
        }
        #endregion Methods
    }
}
