using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ClutWindow.xaml
    /// </summary>
    public partial class ClutWindow : UserControl
    {
        #region Fields
        private static bool added = false;
        private static byte[] pixels = new byte[0x8000];
        public static int page = 0;
        public static int clut = 0;
        public static int bgF = 1;
        private static Button pastPage;
        #endregion Fields

        #region Constructors
        public ClutWindow()
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
            IntPtr pixelDataPtr = Level.bmp[page + (bgF * 8)].BackBuffer;

            int pixelWidth = Level.bmp[page + (bgF * 8)].PixelWidth;
            int pixelHeight = Level.bmp[page + (bgF * 8)].PixelHeight;
            int stride = 128;


            MainWindow.window.clutE.textureImage.Source = BitmapSource.Create(pixelWidth,
                pixelHeight,
                Level.bmp[page + (bgF * 8)].DpiX,
                Level.bmp[page + (bgF * 8)].DpiY,
                Level.bmp[page + (bgF * 8)].Format,
                Level.palette[clut + (bgF * 0x40)],
                pixelDataPtr,
                Level.bmp[page + (bgF * 8)].PixelHeight * stride,
                stride
            );
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
            if (Convert.ToInt32(((Button)sender).Content.ToString()) == page)
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
            page = Convert.ToInt32(((Button)sender).Content.ToString());
            DrawTextures();
        }

        private void palBtn_Click(object sender, RoutedEventArgs e)
        {
            //...
        }
        private void GearBtn_Click(object sender, RoutedEventArgs e)
        {
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
