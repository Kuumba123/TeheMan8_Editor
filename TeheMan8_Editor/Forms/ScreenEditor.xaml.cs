using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ScreenEditor.xaml
    /// </summary>
    public partial class ScreenEditor : UserControl
    {
        #region Fields
        WriteableBitmap screenBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap tileBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap tileBMP_S = new WriteableBitmap(16, 16, 96, 96, PixelFormats.Rgb24, null);
        Button past;
        public byte[] pixels = new byte[0x30000];
        public int tileCol = 0;
        public int tileX = 0;
        public int tileY = 0;
        public int selectedTile = 0;
        public int screenId = 1;
        #endregion Fields

        #region Constructors
        public ScreenEditor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void DrawScreen()
        {
            Level.DrawScreen(screenId, 0, 0, 768, pixels);
            screenBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
            MainWindow.window.screenE.screenImage.Source = screenBMP;
        }
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
            tileImage.Source = tileBMP;
        }
        public void DrawTile()
        {
            Level.Draw16xTile(selectedTile, 0, 0, 48, pixels);
            UpdateTileText();
            tileBMP_S.WritePixels(new Int32Rect(0, 0, 16, 16), pixels, 48, 0);
            MainWindow.window.screenE.tileImageS.Source = tileBMP_S;
        }
        public static int GetSelectedTile(int c, double w, int d)
        {
            int i = (int)w;
            int e = i / d;
            return c / e;
        }
        private void UpdateTileText()
        {
            //Various Tile Info
            MainWindow.window.screenE.tileInt.Value = selectedTile;
            MainWindow.window.screenE.cordInt.Value = ISO.levels[Level.Id].tileInfo[selectedTile * 4];
            MainWindow.window.screenE.pageInt.Value = (ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1]) & 7;
            MainWindow.window.screenE.clutInt.Value = ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2];
            MainWindow.window.screenE.colInt.Value = ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3];
        }
        #endregion Methods

        #region Events
        private void TilesButton_Click(object sender, RoutedEventArgs e)
        {
            Button b = (Button)sender;
            int i = Convert.ToInt32(b.Content.ToString().Trim(), 16);
            if (tileCol == i)
                return;
            tileCol = i;
            if (past != null)
            {
                past.Background = Brushes.Black;
                past.Foreground = Brushes.White;
            }
            b.Background = Brushes.LightBlue;
            b.Foreground = Brushes.Black;
            past = b;

            DrawTiles();
        }

        private void ScreenGridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (screenGrid.ShowGridLines)
                screenGrid.ShowGridLines = false;
            else
                screenGrid.ShowGridLines = true;
        }

        private void TileGridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (tileGrid.ShowGridLines)
                tileGrid.ShowGridLines = false;
            else
                tileGrid.ShowGridLines = true;
        }
        private void screenImage_MouseUp(object sender, System.Windows.Input.MouseButtonEventArgs e)
        {
            var p = e.GetPosition(screenImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = GetSelectedTile(x, screenImage.ActualWidth, 16);
            int cY = GetSelectedTile(y, screenImage.ActualHeight, 16);
            int cord = (cX * 2) + (cY * 16 * 2);
            if (e.ChangedButton == MouseButton.Right)
            {
                int b = ISO.levels[Level.Id].screenData[cord + (screenId * 0x200)];
                b += ISO.levels[Level.Id].screenData[1 + cord + (screenId * 0x200)] << 8;
                selectedTile = b & 0xFFF;
                DrawTile();
            }
            else
            {

            }
        }
        private void screenImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var p = e.GetPosition(screenImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = GetSelectedTile(x, screenImage.ActualWidth, 16);
            int cY = GetSelectedTile(y, screenImage.ActualHeight, 16);
            int cord = (cX * 2) + (cY * 16 * 2);
            if (e.LeftButton == MouseButtonState.Pressed)
            {
                var w = BitConverter.ToUInt16(ISO.levels[Level.Id].screenData, cord + (screenId * 0x200));
                if (w == selectedTile)
                    return;
                ISO.levels[Level.Id].screenData[cord + (screenId * 0x200)] = (byte)(selectedTile & 0xFF);
                ISO.levels[Level.Id].screenData[cord + 1 + (screenId * 0x200)] = (byte)(selectedTile >> 8);
                ISO.levels[Level.Id].edit = true;
                DrawScreen();
                screenBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
                screenImage.Source = screenBMP;
                MainWindow.window.layoutE.DrawLayout();
            }
        }

        private void tileImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var p = e.GetPosition(tileImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = GetSelectedTile(x, tileImage.ActualWidth, 16);
            int cY = GetSelectedTile(y, tileImage.ActualHeight, 16);
            int id = cX + (cY * 16);
            if ((uint)id > 0xFF)
                id = 0xFF;
            selectedTile = id + (tileCol * 0x100);
            DrawTile();
        }
        private void screenInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            //For current Screen
            if (e.NewValue == null || e.OldValue == null)
                return;
            if (screenId == (int)e.NewValue)
                return;
            screenId = (int)e.NewValue;
            if ((uint)screenId >= 0xEF)
                screenId = 0xEF;
            if (ISO.exe == null)
                return;
            DrawScreen();
        }
        private void tileInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (selectedTile == (int)e.NewValue)
                return;
            selectedTile = (int)e.NewValue;
            DrawTile();
        }

        private void cordInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels[Level.Id].tileInfo[selectedTile * 4] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[selectedTile * 4] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.x16E.DrawTiles();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if (MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.DrawTile();
            }
        }

        private void pageInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.x16E.DrawTiles();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if (MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.DrawTile();
            }
        }

        private void clutInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;
            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.x16E.DrawTiles();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if(MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.DrawTile();
            }
        }

        private void colInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (ISO.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] == (byte)(int)e.NewValue)
                return;
            ISO.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] = (byte)(int)e.NewValue;
            ISO.levels[Level.Id].edit = true;


        }
        #endregion Events
    }
}
