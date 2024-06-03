﻿using System;
using System.Collections.Generic;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ClutEditor.xaml
    /// </summary>
    public partial class ClutEditor : UserControl
    {
        #region Fields
        private static bool added = false;
        public static int maxPage;
        public static int page = 0;
        public static int clut = 0;
        public static int bgF = 1;
        private static Button pastPage;
        #endregion Fields

        #region Constructors
        public ClutEditor()
        {
            InitializeComponent();
            if (PSX.levels.Count == 0)
                return;
            AddClut();
        }
        #endregion Constructors

        #region Methods
        public void DrawTextures()
        {
            if (page > 7 && bgF == 0)
                page = 7;

            if (bgF == 1)
                clut %= 0x40;
            else
            {
                if (clut > 0x3F)
                    clut = 0x3F;
            }
            IntPtr pixelDataPtr = Level.bmp[page + bgF * 8].BackBuffer;
            BitmapPalette pal;
            int stride = 128;
            PixelFormat format = PixelFormats.Indexed4;
            if (page < 8)
                pal = Level.palette[clut + bgF * 64];
            else
            {
                List<Color> colors = new List<Color>();

                for (int i = 0; i < 256; i++)
                {
                    if (((((i >> 4) + clut) * 16) + (i & 0xF)) > 8191) break;
                    colors.Add(Level.palette[clut + 64 + (i >> 4)].Colors[i & 0xF]);
                }
                pal = new BitmapPalette(colors);
                format = PixelFormats.Indexed8;
                stride = 256;
            }

            MainWindow.window.clutE.textureImage.Source = BitmapSource.Create(256,
            256,
            96,
            96,
            format,
            pal,
            pixelDataPtr,
            256 * stride,
            stride);
        }
        public void DrawClut()
        {
            if (!added)
            {
                AddClut();
                return;
            }
            foreach (var p in MainWindow.window.clutE.clutGrid.Children)
            {
                var c = Grid.GetColumn(p as UIElement);
                var r = Grid.GetRow(p as UIElement);

                var rect = (Rectangle)p;
                rect.Fill = new SolidColorBrush(Color.FromRgb(Level.palette[r + (bgF * 0x40)].Colors[c].R, Level.palette[r + (bgF * 0x40)].Colors[c].G, Level.palette[r + (bgF * 0x40)].Colors[c].B));
            }
        }
        private void AddClut()
        {
            added = true;
            for (int y = 0; y < 0x40; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    //Create Color
                    Rectangle r = new Rectangle();
                    r.Fill = Brushes.Blue;
                    r.Focusable = false;
                    r.Width = 16;
                    r.Height = 16;
                    r.Fill = new SolidColorBrush(Color.FromRgb(Level.palette[y + (bgF * 0x40)].Colors[x].R, Level.palette[y + (bgF * 0x40)].Colors[x].G, Level.palette[y + (bgF * 0x40)].Colors[x].B));
                    r.MouseDown += Color_Down;
                    r.HorizontalAlignment = HorizontalAlignment.Stretch;
                    r.VerticalAlignment = VerticalAlignment.Stretch;
                    Grid.SetRow(r, y);
                    Grid.SetColumn(r, x);
                    Panel.SetZIndex(r, 0);
                    MainWindow.window.clutE.clutGrid.Children.Add(r);
                }
            }
        }
        public void UpdateClutTxt() //also update Cursor
        {
            MainWindow.window.clutE.palBtn.Content = "CLUT: " + Convert.ToString(clut, 16).ToUpper().PadLeft(2, '0'); //Update Txt
            Canvas.SetTop(MainWindow.window.clutE.cursor, clut * 16);
        }
        public void UpdateSelectedTexture(int type)
        {
            if(type == 0)
            {
                if (bgF == 0)
                    return;
                bgF = 0;
                DrawClut();
                DrawTextures();
                MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
            }
            else
            {
                if (bgF == 1)
                    return;
                bgF = 1;
                DrawClut();
                DrawTextures();
                MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
            }
        }
        public void UpdateTpageButton(int t)
        {
            page = t;
            if(pastPage != null)
            {
                pastPage.Background = Brushes.Black;
                pastPage.Foreground = Brushes.White;
            }
            pastPage = (Button)pagePannel.Children[1 + t];
            ((Button)pagePannel.Children[1 + t]).Foreground = Brushes.Black;
            ((Button)pagePannel.Children[1 + t]).Background = Brushes.LightBlue;
            DrawTextures();
            MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
        }
        #endregion Methods

        #region Events
        private void Color_Down(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            if (e.ChangedButton == System.Windows.Input.MouseButton.Right) //Change Color
            {
                //Get Current Color
                var c = Grid.GetColumn(sender as UIElement);
                var r = Grid.GetRow(sender as UIElement);
                ushort oldC = BitConverter.ToUInt16(PSX.levels[Level.Id].pal, (c + (r + (bgF * 0x40)) * 16) * 2);

                var d = new ColorDialog(oldC,c,r);
                d.ShowDialog();
                if (d.confirm)
                {
                    ushort newC = (ushort)Level.To15Rgb(d.canvas.SelectedColor.Value.B, d.canvas.SelectedColor.Value.G, d.canvas.SelectedColor.Value.R);

                    if (newC != oldC)
                    {
                        //Edit Clut in PAC
                        PSX.levels[Level.Id].edit = true;
                        BitConverter.GetBytes(newC).CopyTo(PSX.levels[Level.Id].pal, (c + (r + (bgF * 0x40)) * 16) * 2);
                        Level.AssignPallete(r + (bgF * 0x40));

                        //Convert & Change Clut in GUI
                        int rgb32 = Level.To32Rgb(newC);
                        ((Rectangle)sender).Fill = new SolidColorBrush(Color.FromRgb((byte)(rgb32 >> 16), (byte)((rgb32 >> 8) & 0xFF), (byte)(rgb32 & 0xFF)));

                        //Updating the rest of GUI
                        if (clut == r)
                            DrawTextures();
                        if (bgF == 0)
                            return;
                        //Enemy Tab
                        MainWindow.window.enemyE.Draw();
                        //16x16 Tab
                        MainWindow.window.x16E.DrawTextures();
                        if (Level.GetClut(MainWindow.window.x16E.selectedTile) == r)
                            MainWindow.window.x16E.DrawTile();
                        MainWindow.window.x16E.DrawTiles();
                        //Screen Tab
                        if (Level.GetClut(MainWindow.window.screenE.selectedTile) == r)
                            MainWindow.window.screenE.DrawTile();
                        MainWindow.window.screenE.DrawScreen();
                        MainWindow.window.screenE.DrawTiles();
                        //Layout Tab
                        MainWindow.window.layoutE.DrawLayout();
                        MainWindow.window.layoutE.DrawScreen();
                    }
                }
            }
            else //Change selected Clut
            {
                clut = Grid.GetRow(sender as UIElement);
                UpdateClutTxt();
                DrawTextures();
            }
        }
        private void Tpage_Click(object sender, RoutedEventArgs e)
        {
            if (Convert.ToInt32(((Button)sender).Content.ToString(), 16) == page)
                return;
            if(pastPage != null)
            {
                pastPage.Background = Brushes.Black;
                pastPage.Foreground = Brushes.White;
            }
            pastPage = (Button)sender;
            ((Button)sender).Foreground = Brushes.Black;
            ((Button)sender).Background = Brushes.LightBlue;
            MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
            page = Convert.ToInt32(((Button)sender).Content.ToString(), 16);
            DrawTextures();
        }

        private void palBtn_Click(object sender, RoutedEventArgs e)
        {
            //...
        }
        private void GearBtn_Click(object sender, RoutedEventArgs e)
        {
            ListWindow.isAnime = false;
            ListWindow l = new ListWindow(5);
            l.ShowDialog();
        }

        private void BackgroudTex_Click(object sender, RoutedEventArgs e) //For Toggle Between Obj & BG
        {
            if (bgF == 1)
                return;
            bgF = 1;
            DrawClut();
            DrawTextures();
            MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
        }

        private void ObjectTex_Click(object sender, RoutedEventArgs e)
        {
            if (bgF == 0)
                return;
            bgF = 0;
            DrawClut();
            DrawTextures();
            MainWindow.window.clutE.cursor.Fill = Brushes.Transparent;
        }
        #endregion Events
    }
}
