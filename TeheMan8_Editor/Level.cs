﻿using System;
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
        private static byte[] tilebuffer = new byte[0x2000];
        public static int Id = 0;
        public static int BG = 0;
        public static WriteableBitmap[] bmp = new WriteableBitmap[16];
        public static BitmapPalette[] palette = new BitmapPalette[0x80];
        #endregion Fields

        #region Constructors
        public Level()
        {
        }
        #endregion Constructors

        #region Methods
        public static void LoadLevels(string path)
        {
            //Main Levels
            PSX.levels.Clear();
            for (int i = 0; i < 0xE; i++)
            {
                if (!File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"))
                    continue;
                int o = PSX.levels.Count;
                PSX.levels.Add(new Level());
                PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC"));
                PSX.levels[o].pac.filename = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC";
                PSX.levels[o].pac.path = path;
                PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + ".PAC");
            }
            //Mid Levels
            for (int i = 0; i < 0xD; i++)
            {
                if (!File.Exists(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC"))
                    continue;
                int o = PSX.levels.Count;
                PSX.levels.Add(new Level());
                PSX.levels[o].pac = new PAC(File.ReadAllBytes(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC"));
                PSX.levels[o].pac.filename = "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC";
                PSX.levels[o].pac.path = path;
                PSX.levels[o].time = File.GetLastWriteTime(path + "/STDATA/" + "STAGE" + Convert.ToString(i, 16).ToUpper().PadLeft(2, '0') + "B.PAC");
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
                PSX.levels[o].ExtractLevelData();
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
            {
                l.ExtractLevelData();
            }
        }
        public static void Draw16xTile(int id,int x,int y,int stride,byte[] buffer)
        {
            id &= 0xFFF;
            if (id == 0) //0 = Empty Tile
            {
                for (int Y = 0; Y < 16; Y++)
                {
                    for (int X = 0; X < 16; X++)
                    {
                        buffer[((x + X) * 3) + (y + Y) * stride] = 0;
                        buffer[((x + X) * 3) + (y + Y) * stride + 1] = 0;
                        buffer[((x + X) * 3) + (y + Y) * stride + 2] = 0;
                    }
                }
                return;
            }
            //Get Tile Info
            int cordX = BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) & 0xF;
            int cordY = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 4) & 0xF;
            int page = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 8) & 0x7;
            int clut = (BitConverter.ToInt32(PSX.levels[Id].tileInfo, id * 4) >> 16) & 0x3F;

            FormatConvertedBitmap f = new FormatConvertedBitmap();
            f.BeginInit();
            var b = new WriteableBitmap(16, 16, 96, 96, PixelFormats.Indexed4, palette[clut + 0x40]);

            bmp[page + 8].CopyPixels(new Int32Rect(cordX * 16, cordY * 16 , 16, 16), tilebuffer, 128, 0);
            b.WritePixels(new Int32Rect(0, 0, 16, 16), tilebuffer, 128, 0);
            f.Source = b;
            f.DestinationFormat = PixelFormats.Rgb24;
            f.EndInit();
            f.CopyPixels(new Int32Rect(0, 0, 16, 16), buffer, stride, (x * 3) + (y * stride));
        }
        public static void DrawScreen(int s,int stride,byte[] buffer)
        {
            int total = PSX.levels[Id].screenData.Length / 0x200;
            if (s > total - 1)
                s = 0;
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Draw16xTile(BitConverter.ToUInt16(PSX.levels[Id].screenData, (x * 2) + (y * 0x20) + (0x200 * s)), x * 16, y * 16, stride, buffer);
                }
            }
        }
        public static void DrawScreen(int s, int drawX, int drawY,int stride, byte[] buffer)
        {
            int total = PSX.levels[Id].screenData.Length / 0x200;
            if (s > total - 1)
                s = 0;
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Draw16xTile(BitConverter.ToUInt16(PSX.levels[Id].screenData,( x * 2) + (y * 0x20) + (0x200 * s)), (x * 16) + drawX, (y * 16) + drawY, stride, buffer);
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
            this.pac.SaveTrimedEntry(0, this.layout);
            this.pac.SaveTrimedEntry(1, this.layout2);
            this.pac.SaveTrimedEntry(2, this.layout3);
            this.pac.SaveTrimedEntry(3, this.screenData);
            this.pac.SaveTrimedEntry(4, this.tileInfo);
            this.pac.SaveTrimedEntry(9, this.pal);
            if (this.pac.ContainsEntry(0xA)) //Enemy Data
            {
                byte[] enemyData = new byte[0x800];
                this.DumpEnemyData(enemyData);
                this.pac.SaveEntry(0xA, enemyData);
            }
        }
        public void LoadTextures()
        {
            //BG Textures
            Array.Clear(pixels, 0, pixels.Length);
            this.pac.LoadEntry(0x0103, pixels);
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
                if (bmp[a] == null)
                    bmp[a] = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Indexed4, palette[a]);
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
