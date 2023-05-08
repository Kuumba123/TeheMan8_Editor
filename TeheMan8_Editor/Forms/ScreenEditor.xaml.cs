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
        #region Properties
        WriteableBitmap screenBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap tileBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap tileBMP_S = new WriteableBitmap(16, 16, 96, 96, PixelFormats.Rgb24, null);
        Button past;
        public byte[] pixels = new byte[0x30000];
        public int tileCol = 0;
        public int tileX = 0;
        public int tileY = 0;
        public int selectedTile = 0;
        public int screenId = 2;
        #endregion Properties

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
            int tileAmount = PSX.levels[Level.Id].tileInfo.Length / 4;
            tileAmount--;
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    int id = (tileCol * 0x100) + x + (y * 16);
                    if (id > tileAmount)
                        id = 0;
                    Level.Draw16xTile(id, x * 16, y * 16, 768, pixels);
                }
            }
            tileBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
            tileImage.Source = tileBMP;
        }
        public void DrawTile()
        {
            Level.Draw16xTile(selectedTile, 0, 0, 48, pixels);
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
            MainWindow.window.screenE.cordInt.Value = PSX.levels[Level.Id].tileInfo[selectedTile * 4];
            MainWindow.window.screenE.pageInt.Value = (PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 1]) & 7;
            MainWindow.window.screenE.clutInt.Value = PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 2];
            MainWindow.window.screenE.colInt.Value = PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 3];
        }
        public void AssignLimits()
        {
            int screenAmount = PSX.levels[Level.Id].screenData.Length / 0x200;
            int tileAmount = PSX.levels[Level.Id].tileInfo.Length / 4;
            screenAmount--;
            tileAmount--;
            //Max Screen Settings
            MainWindow.window.screenE.screenInt.Maximum = screenAmount;
            if (MainWindow.window.screenE.screenInt.Value > screenAmount)
            {
                MainWindow.window.screenE.screenInt.Value = screenAmount;
            }
            //Max Tile Settings
            MainWindow.window.screenE.tileInt.Maximum = tileAmount;
            if (MainWindow.window.screenE.tileInt.Value > tileAmount)
            {
                MainWindow.window.screenE.tileInt.Value = tileAmount;
            }
            DrawScreen();
            DrawTiles();
            DrawTile();
            UpdateTileText();
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
        private void screenImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Point p = e.GetPosition(screenImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = Level.GetSelectedTile(x, screenImage.ActualWidth, 16);
            int cY = Level.GetSelectedTile(y, screenImage.ActualHeight, 16);
            int cord = (cX * 2) + (cY * 16 * 2);
            if (e.LeftButton == MouseButtonState.Pressed) //Paste
            {
                ushort t = BitConverter.ToUInt16(PSX.levels[Level.Id].screenData, cord + (screenId * 0x200));
                if ((t & 0xFFF) == selectedTile)
                    return;
                PSX.levels[Level.Id].screenData[cord + (screenId * 0x200)] = (byte)(selectedTile & 0xFF);
                PSX.levels[Level.Id].screenData[cord + 1 + (screenId * 0x200)] = (byte)((selectedTile >> 8) + ((t & 0x3000) >> 8));
                PSX.levels[Level.Id].edit = true;
                DrawScreen();
                screenBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
                screenImage.Source = screenBMP;
                MainWindow.window.layoutE.DrawLayout();
            }
            else //Copy
            {
                int b = PSX.levels[Level.Id].screenData[cord + (screenId * 0x200)];
                b += PSX.levels[Level.Id].screenData[1 + cord + (screenId * 0x200)] << 8;
                selectedTile = b & 0xFFF;
                DrawTile();
                UpdateTileText();
            }
        }
        private void screenImage_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.LeftButton == MouseButtonState.Pressed)
            {
                Point p = e.GetPosition(screenImage);

                HitTestResult result = VisualTreeHelper.HitTest(MainWindow.window.screenE.screenImage, p);

                if(result != null)
                {
                    //Get Cords
                    int x = (int)p.X;
                    int y = (int)p.Y;
                    int cX = Level.GetSelectedTile(x, screenImage.ActualWidth, 16);
                    int cY = Level.GetSelectedTile(y, screenImage.ActualHeight, 16);
                    int cord = (cX * 2) + (cY * 16 * 2);

                    ushort t = BitConverter.ToUInt16(PSX.levels[Level.Id].screenData, cord + (screenId * 0x200));
                    if ((t & 0xFFF) == selectedTile)
                        return;
                    //New Tile
                    PSX.levels[Level.Id].screenData[cord + (screenId * 0x200)] = (byte)(selectedTile & 0xFF);
                    PSX.levels[Level.Id].screenData[cord + 1 + (screenId * 0x200)] = (byte)((selectedTile >> 8) + ((t & 0x3000) >> 8));
                    PSX.levels[Level.Id].edit = true;
                    DrawScreen();
                    screenBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
                    screenImage.Source = screenBMP;
                    MainWindow.window.layoutE.DrawLayout();
                }
            }
        }

        private void tileImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            int tileAmount = PSX.levels[Level.Id].tileInfo.Length / 4;
            tileAmount--;
            Point p = e.GetPosition(tileImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = GetSelectedTile(x, tileImage.ActualWidth, 16);
            int cY = GetSelectedTile(y, tileImage.ActualHeight, 16);
            int id = cX + (cY * 16);
            if ((uint)id > 0xFF)
                id = 0xFF;
            id += tileCol * 0x100;
            if(id > tileAmount)
            {
                id = tileAmount;
            }
            selectedTile = id;
            DrawTile();
            UpdateTileText();
        }
        private void screenInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            //For current Screen
            if (e.NewValue == null || e.OldValue == null || PSX.levels.Count == 0)
                return;
            if (screenId == (int)e.NewValue)
                return;
            screenId = (int)e.NewValue;
            if ((uint)screenId >= 0xEF)
                screenId = 0xEF;
            if (PSX.exe == null)
                return;
            DrawScreen();
            if (ListWindow.extraOpen)
                MainWindow.extraWindow.DrawExtra();
        }
        private void tileInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (selectedTile == (int)e.NewValue)
                return;
            selectedTile = (int)e.NewValue;
            DrawTile();
        }

        private void cordInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            byte val = (byte)(int)e.NewValue;
            if (PSX.levels[Level.Id].tileInfo[selectedTile * 4] == val)
                return;
            PSX.levels[Level.Id].tileInfo[selectedTile * 4] = val;
            PSX.levels[Level.Id].edit = true;

            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if (tileCol == (selectedTile >> 8))
                DrawTiles();

            if (MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.cordInt.Value = val;
                MainWindow.window.x16E.DrawTile();
            }
            if (MainWindow.window.x16E.tileCol == (selectedTile >> 8))
                MainWindow.window.x16E.DrawTiles();
        }

        private void pageInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            byte val = (byte)(int)e.NewValue;
            if (PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] == val)
                return;
            PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 1] = val;
            PSX.levels[Level.Id].edit = true;

            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if (tileCol == (selectedTile >> 8))
                DrawTiles();

            if (MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.pageInt.Value = val;
                MainWindow.window.x16E.DrawTile();
            }
            if (MainWindow.window.x16E.tileCol == (selectedTile >> 8))
                MainWindow.window.x16E.DrawTiles();
        }

        private void clutInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || e.OldValue == null)
                return;
            byte val = (byte)(int)e.NewValue;
            if (PSX.levels.Count == 0 || PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] == val)
                return;
            PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 2] = val;
            PSX.levels[Level.Id].edit = true;

            //Update
            MainWindow.window.layoutE.DrawLayout();
            MainWindow.window.layoutE.DrawScreen();
            MainWindow.window.enemyE.Draw();
            DrawTile();
            DrawScreen();
            if (tileCol == (selectedTile >> 8))
                DrawTiles();

            if (MainWindow.window.x16E.selectedTile == selectedTile)
            {
                MainWindow.window.x16E.clutInt.Value = val;
                MainWindow.window.x16E.DrawTile();
            }
            if (MainWindow.window.x16E.tileCol == (selectedTile >> 8))
                MainWindow.window.x16E.DrawTiles();
        }

        private void colInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
            if (PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] == (byte)(int)e.NewValue)
                return;
            PSX.levels[Level.Id].tileInfo[(selectedTile * 4) + 3] = (byte)(int)e.NewValue;
            PSX.levels[Level.Id].edit = true;
        }
        private void Extra_Click(object sender, RoutedEventArgs e)
        {
            if (ListWindow.extraOpen)
                return;
            MainWindow.extraWindow = new ListWindow(2);
            MainWindow.extraWindow.Show();
        }
        private void Help_Click(object sender, RoutedEventArgs e)
        {
            HelpWindow h = new HelpWindow(2);
            h.ShowDialog();
        }
        private void SnapButton_Click(object sender, RoutedEventArgs e)
        {
            var result = MessageBox.Show("Do you want to save all screens?", "?", MessageBoxButton.YesNoCancel);

            if (result == MessageBoxResult.Cancel)
                return;
            if (result == MessageBoxResult.Yes) //Save All Screens
            {
                var sfd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
                sfd.Description = "Select Screens Save Location";
                sfd.UseDescriptionForTitle = true;

                if ((bool)sfd.ShowDialog())
                {
                    for (int i = 0; i < PSX.levels[Level.Id].screenData.Length / 0x200; i++)
                    {
                        Level.DrawScreen(i, 0, 0, 768, pixels);
                        screenBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels, 768, 0);
                        PngBitmapEncoder encoder = new PngBitmapEncoder();
                        encoder.Frames.Add(BitmapFrame.Create(screenBMP));
                        System.IO.FileStream fs = System.IO.File.Create(sfd.SelectedPath + "\\" + PSX.levels[Level.Id].pac.filename + "_SCREEN_" + Convert.ToString(i,16) + ".PNG");
                        encoder.Save(fs);
                        fs.Close();
                    }
                    DrawScreen();
                    MessageBox.Show("All Screens have been exported !!!");
                }
            }
            else //Save the Specfic Screen
            {
                using (var sfd = new System.Windows.Forms.SaveFileDialog())
                {
                    sfd.Filter = "PNG |*.png";
                    sfd.Title = "Select the Screen Save Location";
                    if (sfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        PngBitmapEncoder encoder = new PngBitmapEncoder();
                        encoder.Frames.Add(BitmapFrame.Create(screenBMP));
                        System.IO.FileStream fs = System.IO.File.Create(sfd.FileName);
                        encoder.Save(fs);
                        fs.Close();
                        MessageBox.Show("Screen Exported");
                    }
                }
            }
        }
        #endregion Events
    }
}
