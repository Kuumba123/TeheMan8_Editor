using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for Tile16Editor.xaml
    /// </summary>
    public partial class Tile16Editor : UserControl
    {
        #region Properties
        WriteableBitmap tileBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap tileBMP_S = new WriteableBitmap(16, 16, 96, 96, PixelFormats.Rgb24, null);
        Button past;
        Button past2;
        public byte[] pixels = new byte[0x30000];
        public int tileCol = 0;
        public int selectedTile = 0;
        public int selectTex = 0;
        public int clut = 0;
        public int tileX = 0;
        public int tileY = 0;
        public int page = 0;
        #endregion Properties

        #region Constructors
        public Tile16Editor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void DrawTiles()
        {
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Level.Draw16xTile((tileCol * 0x100) + x + (y * 16), x * 16, y * 16, 768, pixels);
                }
            }
            tileBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
            MainWindow.window.x16E.tileImage.Source = tileBMP;
        }
        public void DrawTextures()
        {
            palBtn.Content = "CLUT: " + Convert.ToString(clut, 16).ToUpper().PadLeft(2, '0'); //Update Txt
            var b = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Indexed4, Level.palette[clut + 0x40]);
            Level.bmp[page + 8].CopyPixels(new Int32Rect(0, 0, 256, 256), pixels, 128, 0);
            b.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 128, 0);
            MainWindow.window.x16E.textureImage.Source = b;
        }
        public void DrawTile()
        {
            Level.Draw16xTile(selectedTile, 0, 0, 48, pixels);
            UpdateTileText();
            MainWindow.window.x16E.tileBMP_S.WritePixels(new Int32Rect(0, 0, 16, 16), pixels, 48, 0);
            MainWindow.window.x16E.tileImageS.Source = tileBMP_S;
        }
        private void UpdateTileText()
        {
            //Various Tile Info
            MainWindow.window.x16E.tileInt.Value = selectedTile;
            MainWindow.window.x16E.cordInt.Value = ISO.levels[Level.Id].tileInfo[selectedTile * 4];
            MainWindow.window.x16E.pageInt.Value = (ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1]) & 7;
            MainWindow.window.x16E.clutInt.Value = ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2];
            MainWindow.window.x16E.colInt.Value = ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3];
        }
        #endregion Methods

        #region Events
        private void TpageButton_Click(object sender, RoutedEventArgs e)
        {
            Button b = (Button)sender;
            int i = Convert.ToInt32(b.Content.ToString().Trim(), 16);
            if (page == i)
                return;
            page = i;
            if (past2 != null)
            {
                //Old Color
                past2.Background = Brushes.Black;
                past2.Foreground = Brushes.White;
            }
            //New Color
            b.Background = Brushes.LightBlue;
            b.Foreground = Brushes.Black;
            past2 = b;
            DrawTextures();
        }
        private void TileButton_Click(object sender, RoutedEventArgs e)
        {
            Button b = (Button)sender;
            int i = Convert.ToInt32(b.Content.ToString().Trim(), 16);
            if (tileCol == i)
                return;
            tileCol = i;
            if(past != null)
            {
                past.Background = Brushes.Black;
                past.Foreground = Brushes.White;
            }
            b.Background = Brushes.LightBlue;
            b.Foreground = Brushes.Black;
            past = b;
            DrawTiles();
        }
        private void tileImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var p = e.GetPosition(tileImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = ScreenEditor.GetSelectedTile(x, tileImage.ActualWidth, 16);
            int cY = ScreenEditor.GetSelectedTile(y, tileImage.ActualHeight, 16);
            int id = cX + (cY * 16);
            if ((uint)id > 0xFF)
                id = 0xFF;
            selectedTile = id + (tileCol * 0x100);
            DrawTile();
        }
        private void textureImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var p = e.GetPosition(textureImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = ScreenEditor.GetSelectedTile(x, textureImage.ActualWidth, 16);
            int cY = ScreenEditor.GetSelectedTile(y, textureImage.ActualHeight, 16);
            if (e.ChangedButton == MouseButton.Right)
            {
                if (clut != 0x3F)
                    clut++;
                else
                    clut = 0;
                DrawTextures();
            }
            else
            {
                ISO.levels[Level.Id].tileInfo[selectedTile * 4] = (byte)(cX + (cY * 16));
                ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] = (byte)page;
                DrawTile();
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.layoutE.DrawScreen();
                MainWindow.window.screenE.DrawScreen();
                MainWindow.window.screenE.DrawTiles();
                MainWindow.window.screenE.DrawTile();
            }
        }

        private void textureImage_MouseWheel(object sender, MouseWheelEventArgs e)
        {
            if(e.Delta > 0)
            {
                if (clut != 0x3F)
                    clut++;
                else
                    clut = 0;
            }
            else
            {
                if (clut != 0)
                    clut--;
                else
                    clut = 0x3F;
            }
            DrawTextures();
        }

        private void palBtn_Click(object sender, RoutedEventArgs e)
        {

        }

        private void tileGridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (tileGrid.ShowGridLines)
                tileGrid.ShowGridLines = false;
            else
                tileGrid.ShowGridLines = true;
        }

        private void textureGridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (textureGrid.ShowGridLines)
                textureGrid.ShowGridLines = false;
            else
                textureGrid.ShowGridLines = true;
        }
        private void tileInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null)
                return;
            if (ISO.levels.Count == 0 || selectedTile == (int)e.NewValue)
                return;
            selectedTile = (int)e.NewValue;
            DrawTile();
        }

        private void cordInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels.Count == 0 || ISO.levels[Level.Id].tileInfo[selectedTile * 4] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[selectedTile * 4] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            DrawTile();
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.screenE.DrawScreen();
            MainWindow.window.screenE.DrawTiles();
            if (MainWindow.window.screenE.selectedTile == selectedTile)
            {
                MainWindow.window.screenE.DrawTile();
            }
        }

        private void pageInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels.Count == 0 || ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            DrawTile();
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.screenE.DrawScreen();
            MainWindow.window.screenE.DrawTiles();
            if (MainWindow.window.screenE.selectedTile == selectedTile)
            {
                MainWindow.window.screenE.DrawTile();
            }
        }

        private void clutInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels.Count == 0 || ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            DrawTile();
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.screenE.DrawScreen();
            MainWindow.window.screenE.DrawTiles();
            if (MainWindow.window.screenE.selectedTile == selectedTile)
            {
                MainWindow.window.screenE.DrawTile();
            }
        }

        private void colInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels.Count == 0 || ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;

        }
        #endregion Events
    }
}
