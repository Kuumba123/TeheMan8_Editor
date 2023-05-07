using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for LayoutEditor.xaml
    /// </summary>
    public partial class LayoutEditor : UserControl
    {
        #region Fields
        WriteableBitmap layoutBMP = new WriteableBitmap(768, 768, 96, 96, PixelFormats.Rgb24, null);
        WriteableBitmap selectBMP = new WriteableBitmap(256, 256, 96, 96, PixelFormats.Rgb24, null);
        byte[] pixels = new byte[0x1B0000];
        byte[] pixels2 = new byte[0x30000];
        public int viewerX = 0;
        public int viewerY = 0;
        public int selectedScreen = 2;
        public Button pastLayer;
        #endregion Fields

        #region Constructors
        public LayoutEditor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void DrawLayout()
        {
            if (Level.BG == 0)
            {
                //X0
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }else if(Level.BG == 1)
            {
                //X0
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }
            else
            {
                //X0
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(PSX.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }
            layoutBMP.WritePixels(new Int32Rect(0, 0, 768, 768), pixels, 2304, 0);
            MainWindow.window.layoutE.layoutImage.Source = layoutBMP;
        }
        public void DrawScreen()
        {
            Level.DrawScreen(selectedScreen, 768, pixels2);
            selectBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels2, 768, 0);
            MainWindow.window.layoutE.selectImage.Source = selectBMP;
        }
        public void UpdateBtn()
        {
            if (pastLayer != null)
            {
                pastLayer.Background = Brushes.Black;
                pastLayer.Foreground = Brushes.White;
            }
            if (Level.BG == 0)
            {
                btn1.Background = Brushes.LightBlue;
                btn1.Foreground = Brushes.Black;
                pastLayer = btn1;
            }
            else if (Level.BG == 1)
            {
                btn2.Background = Brushes.LightBlue;
                btn2.Foreground = Brushes.Black;
                pastLayer = btn2;
            }
            else
            {
                btn3.Background = Brushes.LightBlue;
                btn3.Foreground = Brushes.Black;
                pastLayer = btn3;
            }
        }
        public void AssignLimits()
        {
            int screenAmount = PSX.levels[Level.Id].screenData.Length / 0x200;
            screenAmount--;
            //Max Screen Settings
            MainWindow.window.layoutE.screenInt.Maximum = screenAmount;
            if (MainWindow.window.layoutE.screenInt.Value > screenAmount)
            {
                MainWindow.window.layoutE.screenInt.Value = screenAmount;
            }
            DrawScreen();
        }
        #endregion Methods

        #region Events
        private void layoutImage_MouseDown(object sender, MouseButtonEventArgs e)
        {
            var p = e.GetPosition(layoutImage);
            int x = (int)p.X;
            int y = (int)p.Y;
            int cX = ScreenEditor.GetSelectedTile(x, layoutImage.ActualWidth, 3);
            int cY = ScreenEditor.GetSelectedTile(y, layoutImage.ActualHeight, 3);

            if (e.ChangedButton == MouseButton.Right)
            {
                if (Keyboard.IsKeyDown(Key.LeftShift))  //For Selecting in the Screen Tab
                {
                    byte screen = 0;
                    if(Level.BG == 0)
                        screen = PSX.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    else if(Level.BG == 1)
                        screen = PSX.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    else
                        screen = PSX.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    MainWindow.window.screenE.screenInt.Value = screen;
                    return;
                }
                if (Level.BG == 0)
                    selectedScreen = PSX.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                else if (Level.BG == 1)
                    selectedScreen = PSX.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                else
                    selectedScreen = PSX.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                screenInt.Value = selectedScreen;
                DrawScreen();
            }
            else
            {
                if (Keyboard.IsKeyDown(Key.LeftShift))  //For Modifying the Clicked Screen
                {
                    ListWindow.layoutOffset = cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32);
                    var l = new ListWindow(1);
                    l.ShowDialog();
                    return;
                }
                if (Level.BG == 0)
                    PSX.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)selectedScreen;
                else if (Level.BG == 1)
                    PSX.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)selectedScreen;
                else
                    PSX.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)selectedScreen;
                PSX.levels[Level.Id].edit = true;
                DrawLayout();
            }
        }
        private void IntegerUpDown_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null || PSX.levels.Count == 0)
                return;
            if (selectedScreen == (int)e.NewValue)
                return;
            selectedScreen = (int)e.NewValue;
            if ((uint)selectedScreen >= 0xEF)
                selectedScreen = 0xEF;
            DrawScreen();
        }

        private void gridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (layoutGrid.ShowGridLines)
                layoutGrid.ShowGridLines = false;
            else
                layoutGrid.ShowGridLines = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e) //Switch Layers Buttons
        {
            var b = (Button)sender;
            int i = Convert.ToInt32(b.Content.ToString(), 16) - 1;
            if (Level.BG == i)
                return;
            Level.BG = i;
            if(pastLayer != null)
            {
                pastLayer.Background = Brushes.Black;
                pastLayer.Foreground = Brushes.White;
            }
            b.Background = Brushes.LightBlue;
            b.Foreground = Brushes.Black;
            pastLayer = b;
            DrawLayout();
            if (MainWindow.layoutWindow != null)
                MainWindow.layoutWindow.DrawScreens();
        }
        private void ViewScreens_Click(object sender, RoutedEventArgs e)
        {
            if (ListWindow.screenViewOpen)
                return;
            MainWindow.layoutWindow = new ListWindow(0);
            MainWindow.layoutWindow.Show();
        }
        private void Help_Click(object sender, RoutedEventArgs e)
        {
            HelpWindow h = new HelpWindow(1);
            h.ShowDialog();
        }
        private void SnapButton_Click(object sender, RoutedEventArgs e)
        {
            using(var sfd = new System.Windows.Forms.SaveFileDialog())
            {
                sfd.Filter = "PNG |*.png";
                sfd.Title = "Select Level Layout Save Location";
                try
                {
                    if (sfd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        WriteableBitmap fileBmp = new WriteableBitmap(8192, 8192, 96, 96, PixelFormats.Rgb24, null);
                        for (int y = 0; y < 32; y++) //32 Screens  Tall
                        {
                            for (int x = 0; x < 32; x++) //32 Screens Wide
                            {
                                if (Level.BG == 0)
                                    Level.DrawScreen(PSX.levels[Level.Id].layout[y * 32 + x], 256 * 3, pixels);
                                else if (Level.BG == 1)
                                    Level.DrawScreen(PSX.levels[Level.Id].layout2[y * 32 + x], 256 * 3, pixels);
                                else
                                    Level.DrawScreen(PSX.levels[Level.Id].layout3[y * 32 + x], 256 * 3, pixels);
                                fileBmp.WritePixels(new Int32Rect(x * 256, y * 256, 256, 256), pixels, 256 * 3, 0);
                            }
                        }
                        PngBitmapEncoder encoder = new PngBitmapEncoder();
                        encoder.Frames.Add(BitmapFrame.Create(fileBmp));
                        System.IO.FileStream fs = System.IO.File.Create(sfd.FileName);
                        encoder.Save(fs);
                        fs.Close();
                        MessageBox.Show("Layout Exported");
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }
        private void UpButton_Click(object sender, RoutedEventArgs e)
        {
            if (MainWindow.window.layoutE.viewerY != 0)
            {
                MainWindow.window.layoutE.viewerY -= 0x100;
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.UpdateViewrCam();
            }
        }
        private void DownButton_Click(object sender, RoutedEventArgs e)
        {
            if (MainWindow.window.layoutE.viewerY != 0x1D00)
            {
                MainWindow.window.layoutE.viewerY += 0x100;
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.UpdateViewrCam();
            }
        }
        private void LeftButton_Click(object sender, RoutedEventArgs e)
        {
            if (MainWindow.window.layoutE.viewerX != 0)
            {
                MainWindow.window.layoutE.viewerX -= 0x100;
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.UpdateViewrCam();
            }
        }
        private void RightButton_Click(object sender, RoutedEventArgs e)
        {
            if (MainWindow.window.layoutE.viewerX != 0x1D00)
            {
                MainWindow.window.layoutE.viewerX += 0x100;
                MainWindow.window.layoutE.DrawLayout();
                MainWindow.window.UpdateViewrCam();
            }
        }
        #endregion Events
    }
}
