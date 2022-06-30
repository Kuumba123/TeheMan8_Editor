using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ListWindow.xaml
    /// </summary>
    public partial class ListWindow : Window
    {
        #region Fields
        public static bool screenViewOpen = false;
        public string tab = "";
        public static int layoutOffset = 0;
        #endregion Fields

        #region Properties
        public int mode = -1;
        #endregion Properties

        #region Constructors
        public ListWindow() //For viewering build output
        {
            InitializeComponent();
            this.Title = "CD Builder";
            this.mode = -1;
            TextBox t = new TextBox();
            t.TextWrapping = TextWrapping.NoWrap;
            t.AcceptsReturn = true;
            t.IsReadOnly = true;
            t.Foreground = Brushes.White;
            t.Background = Brushes.Black;
            this.grid.Children.Add(t);
        }
        public ListWindow(PAC pac,int type)  //For Viewing Textures
        {
            InitializeComponent();
            this.Width = 804;
            this.Height = 812;
            for (int i = 0; i < pac.entries.Count; i++)
            {
                if (pac.entries[i].type >> 8 != 1)
                    continue;
                //Fancy Border
                var b = new Border();
                if ((i & 1) == 0)
                    b.BorderBrush = Brushes.Red;
                else
                    b.BorderBrush = Brushes.BlueViolet;
                b.BorderThickness = new Thickness(2);

                //Setup Texture
                Image image = new Image();
                //Define LEFT & RIGHT Click Events
                System.Windows.Input.MouseButtonEventHandler p1 = (s,e) => 
                {
                    using(var fd = new System.Windows.Forms.OpenFileDialog())
                    {
                        byte[] data;
                        if (type == 0)
                        {
                            fd.Filter = "4bpp BMP |*.BMP";
                            fd.Title = "Open an 4bpp Bitmap";
                        }
                        else
                        {
                            fd.Filter = "BIN |*BIN";
                            fd.Title = "Open an BIN File";
                        }
                        if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                        {
                            if (type == 0) //BMP
                            {
                                var uri = new Uri(fd.FileName);
                                WriteableBitmap tex = new WriteableBitmap(new BitmapImage(uri));
                                Uri.EscapeUriString(fd.FileName);

                                if (tex.PixelWidth != 256)
                                {
                                    MessageBox.Show("Texture must\nHave a width of 256 pixels.", "ERROR");
                                    return;
                                }
                                if (tex.Format != PixelFormats.Indexed4)
                                {
                                    MessageBox.Show("Texture must be in 4bpp.", "ERROR");
                                    return;
                                }
                                data = new byte[256 * tex.PixelHeight / 2];
                                tex.CopyPixels(data, 128, 0);
                                Level.ConvertBmp(data);

                                //Get PAC Info
                                var im = (Image)s;
                                var id = Convert.ToInt32(im.Uid);
                                var filePAC = (PAC)im.Tag;
                                Array.Resize(ref pac.entries[id].data, data.Length);
                                Array.Copy(data, pac.entries[id].data, data.Length);
                                File.WriteAllBytes(pac.path, pac.GetEntriesData());
                                im.Source = tex;
                            }
                            else //BIN
                            {
                                data = File.ReadAllBytes(fd.FileName);

                                //Get PAC Info
                                var im = (Image)s;
                                var id = Convert.ToInt32(im.Uid);
                                var filePAC = (PAC)im.Tag;
                                Array.Resize(ref pac.entries[id].data, data.Length);
                                Array.Copy(data, pac.entries[id].data, data.Length);
                                File.WriteAllBytes(pac.path, pac.GetEntriesData());

                                Level.ConvertBmp(data);
                                WriteableBitmap tex = new WriteableBitmap(256, data.Length / 128, 96, 96, PixelFormats.Indexed4, new BitmapPalette(Const.GreyScale));
                                tex.WritePixels(new Int32Rect(0, 0, 256, data.Length / 128), data, 128, 0);
                                im.Source = tex;
                            }
                        }
                    }
                };
                System.Windows.Input.MouseButtonEventHandler p2 = (s, e) =>
                {
                    string x;
                    string y;
                    int[] cordTable = new int[] { 0x140, 0x1000140, 0x200, 0x1000200, 0x1000180 };
                    int cordId = Convert.ToInt32((((Image)s).Name).Replace("_","")) & 0xFF;
                    int height = (int)((Image)s).Source.Height;
                    if (cordId > 4)
                    {
                        x = "?";
                        y = "?";
                    }
                    else
                    {
                        x = (cordTable[cordId] & 0xFFFF).ToString();
                        y = (cordTable[cordId] >> 16).ToString();
                    }
                    //Display Info
                    MessageBox.Show("X: " + x + " Y: " + y + "\nWidth: 256 Height: " + height, "Texture Info");
                };
                image.MouseLeftButtonDown += p1;
                image.MouseRightButtonDown += p2;
                image.Tag = pac;
                image.Uid = i.ToString();   //For Getting PAC data
                image.Name = "_" + pac.entries[i].type.ToString(); //For XY

                //Draw Texture
                var p = new byte[pac.entries[i].data.Length];
                Array.Copy(pac.entries[i].data, p, p.Length);
                Level.ConvertBmp(p);
                var l = new List<Color>()
                            {
                                Color.FromRgb(0,0,0),
                                Color.FromRgb(0x11,0x11,0x11),
                                Color.FromRgb(0x22,0x22,0x22),
                                Color.FromRgb(0x33,0x33,0x33),
                                Color.FromRgb(0x44,0x44,0x44),
                                Color.FromRgb(0x55,0x55,0x55),
                                Color.FromRgb(0x66,0x66,0x66),
                                Color.FromRgb(0x77,0x77,0x77),
                                Color.FromRgb(0x88,0x88,0x88),
                                Color.FromRgb(0x99,0x99,0x99),
                                Color.FromRgb(0xAA,0xAA,0xAA),
                                Color.FromRgb(0xBB,0xBB,0xBB),
                                Color.FromRgb(0xCC,0xCC,0xCC),
                                Color.FromRgb(0xDD,0xDD,0xDD),
                                Color.FromRgb(0xEE,0xEE,0xEE),
                                Color.FromRgb(0xFF,0xFF,0xFF)
                            };
                var pal = new BitmapPalette(l);
                var bmp = new WriteableBitmap(256, p.Length / 128, 96, 96, PixelFormats.Indexed4, pal);
                bmp.WritePixels(new Int32Rect(0, 0, 256, p.Length / 128), p, 128, 0);
                //Add to Window
                image.Source = bmp;
                b.Child = image;
                pannel.Children.Add(b);
            }
        }
        public ListWindow(int action) //Various
        {
            Action[] acts = new Action[] { ScreenGrid, LayoutEdit };
            InitializeComponent();
            mode = action;
            acts[action]();
        }
        #endregion Constructors

        #region Methods
        private void ScreenGrid() //Viewing All Screens in Layout
        {
            screenViewOpen = true;
            this.Width = 1060;
            this.Height = 934;
            this.MaxWidth = 1060;
            this.MaxHeight = 934;
            this.Title = "All Screens in Layer " + (Level.BG + 1);
            this.scroll.HorizontalScrollBarVisibility = ScrollBarVisibility.Visible;
            while (true)
            {
                if (grid.ColumnDefinitions.Count == 32)
                    break;
                grid.ColumnDefinitions.Add(new ColumnDefinition());
                grid.ColumnDefinitions[grid.ColumnDefinitions.Count - 1].Width = GridLength.Auto;
            }
            while (true)
            {
                if (grid.RowDefinitions.Count == 32)
                    break;
                grid.RowDefinitions.Add(new RowDefinition());
                grid.RowDefinitions[grid.RowDefinitions.Count - 1].Height = GridLength.Auto;
            }
            //Add Buttons to Grid
            for (int y = 0; y < 32; y++)
            {
                for (int x = 0; x < 32; x++)
                {
                    Button b = new Button();
                    b.Margin = new Thickness(1);
                    b.Padding = new Thickness(1);
                    b.Width = 30;
                    b.Click += (s, e) =>
                    {
                        MainWindow.window.layoutE.viewerX = Grid.GetColumn(s as UIElement) << 8;
                        MainWindow.window.layoutE.viewerY = Grid.GetRow(s as UIElement) << 8;
                        MainWindow.window.UpdateViewrCam();
                        MainWindow.window.layoutE.DrawLayout();
                    };
                    b.MouseRightButtonDown += (s, e) =>
                    {
                        MainWindow.window.enemyE.viewerX = Grid.GetColumn(s as UIElement) << 8;
                        MainWindow.window.enemyE.viewerY = Grid.GetRow(s as UIElement) << 8;
                        MainWindow.window.enemyE.ReDraw();
                    };
                    if (Level.BG == 0)
                        b.Content = Convert.ToString(ISO.levels[Level.Id].layout[x + (y * 32)], 16).ToUpper();
                    else if(Level.BG == 1)
                        b.Content = Convert.ToString(ISO.levels[Level.Id].layout2[x + (y * 32)], 16).ToUpper();
                    else
                        b.Content = Convert.ToString(ISO.levels[Level.Id].layout3[x + (y * 32)], 16).ToUpper();
                    Grid.SetColumn(b, x);
                    Grid.SetRow(b, y);
                    grid.Children.Add(b);
                }
            }
        }
        private void LayoutEdit() //Changing Screen in Layout
        {
            this.Title = "Set New Screen ID";
            this.Width = 330;
            this.Height = 90;
            this.scroll.VerticalScrollBarVisibility = ScrollBarVisibility.Disabled;
            this.ResizeMode = ResizeMode.NoResize;

            //Setup INT UP/DOWN
            var integer = new Xceed.Wpf.Toolkit.IntegerUpDown();
            integer.Maximum = 0xEF;
            integer.Minimum = 0;
            integer.ParsingNumberStyle = System.Globalization.NumberStyles.HexNumber;
            integer.FormatString = "X";
            integer.FontSize = 40;
            integer.TextAlignment = TextAlignment.Center;
            integer.AllowTextInput = true;
            //Set current screen Value
            integer.Value = 1;
            if (Level.BG == 0)
                integer.Value = ISO.levels[Level.Id].layout[layoutOffset];
            else if (Level.BG == 1)
                integer.Value = ISO.levels[Level.Id].layout2[layoutOffset];
            else
                integer.Value = ISO.levels[Level.Id].layout3[layoutOffset];

            //Setup Confirm Button
            var okBtn = new Button();
            okBtn.Content = "Modify";
            okBtn.Click += (s, e) =>
            {
                try
                {
                    if (Level.BG == 0)
                        ISO.levels[Level.Id].layout[layoutOffset] = (byte)integer.Value;
                    else if (Level.BG == 1)
                        ISO.levels[Level.Id].layout2[layoutOffset] = (byte)integer.Value;
                    else
                        ISO.levels[Level.Id].layout3[layoutOffset] = (byte)integer.Value;
                    ISO.levels[Level.Id].edit = true;
                    MainWindow.window.layoutE.DrawLayout();
                }catch(Exception ex)
                {
                    System.Windows.MessageBox.Show(ex.Message, "ERROR");
                    return;
                }
                this.Close();
            };
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            grid.ColumnDefinitions.Add(new ColumnDefinition());
            Grid.SetColumn(okBtn, 0);
            Grid.SetColumn(integer, 1);
            grid.Children.Add(integer);
            grid.Children.Add(okBtn);
        }
        public void DrawScreens()
        {
            if (this.Visibility != Visibility.Visible)
                return;
            foreach (var u in grid.Children)
            {
                if (u.GetType() != typeof(Button))
                    continue;
                //Prep for Button Screen Id Change
                var b = u as Button;
                int c = Grid.GetColumn(u as UIElement);
                int r = Grid.GetRow(u as UIElement);
                if (Level.BG == 0)
                    b.Content = Convert.ToString(ISO.levels[Level.Id].layout[c + (r * 32)], 16).ToUpper();
                else if (Level.BG == 1)
                    b.Content = Convert.ToString(ISO.levels[Level.Id].layout2[c + (r * 32)], 16).ToUpper();
                else
                    b.Content = Convert.ToString(ISO.levels[Level.Id].layout3[c + (r * 32)], 16).ToUpper();
            }
        }
        #endregion Methods

        #region Events
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            switch (this.mode)
            {
                case 0: //Layout Viewer
                    screenViewOpen = false;
                    break;
                case -1:
                    if (MainWindow.building)
                        e.Cancel = true;
                    break;
                default:
                    break;
            }
        }
        #endregion Events
    }
}
