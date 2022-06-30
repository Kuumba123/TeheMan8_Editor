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
        public Button past;
        #endregion Fields

        #region Constructors
        public LayoutEditor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void Load()
        {

        }
        public void DrawLayout()
        {
            if (Level.BG == 0)
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }else if(Level.BG == 1)
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }
            else
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 0, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 0, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 0, 512, 2304, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 256, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 256, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 1 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 256, 512, 2304, pixels);
                //X2
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + ((MainWindow.window.layoutE.viewerY >> 8) * 32)], 512, 0, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 1) * 32)], 512, 256, 2304, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(MainWindow.window.layoutE.viewerX >> 8) + 2 + (((MainWindow.window.layoutE.viewerY >> 8) + 2) * 32)], 512, 512, 2304, pixels);
            }
            layoutBMP.WritePixels(new Int32Rect(0, 0, 768, 768), pixels, 2304, 0);
            MainWindow.window.layoutE.layoutImage.Source = layoutBMP;
        }
        public void DrawScreen()
        {
            Level.DrawScreen(Level.selectedScreen, 768, pixels2);
            selectBMP.WritePixels(new Int32Rect(0, 0, 256, 256), pixels2, 768, 0);
            MainWindow.window.layoutE.selectImage.Source = selectBMP;
        }
        public void UpdateBtn()
        {
            if (past != null)
            {
                past.Background = Brushes.Black;
                past.Foreground = Brushes.White;
            }
            if (Level.BG == 0)
            {
                btn1.Background = Brushes.LightBlue;
                btn1.Foreground = Brushes.Black;
                past = btn1;
            }
            else if (Level.BG == 1)
            {
                btn2.Background = Brushes.LightBlue;
                btn2.Foreground = Brushes.Black;
                past = btn2;
            }
            else
            {
                btn3.Background = Brushes.LightBlue;
                btn3.Foreground = Brushes.Black;
                past = btn3;
            }
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
                        screen = ISO.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    else if(Level.BG == 1)
                        screen = ISO.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    else
                        screen = ISO.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                    MainWindow.window.screenE.screenInt.Value = screen;
                    return;
                }
                if (Level.BG == 0)
                    Level.selectedScreen = ISO.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                else if (Level.BG == 1)
                    Level.selectedScreen = ISO.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                else
                    Level.selectedScreen = ISO.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)];
                screenInt.Value = Level.selectedScreen;
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
                    ISO.levels[Level.Id].layout[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)Level.selectedScreen;
                else if (Level.BG == 1)
                    ISO.levels[Level.Id].layout2[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)Level.selectedScreen;
                else
                    ISO.levels[Level.Id].layout3[cX + (MainWindow.window.layoutE.viewerX >> 8) + ((cY + (MainWindow.window.layoutE.viewerY >> 8)) * 32)] = (byte)Level.selectedScreen;
                ISO.levels[Level.Id].edit = true;
                DrawLayout();
            }
        }
        private void IntegerUpDown_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (e.NewValue == null)
                return;
            if (Level.selectedScreen == (int)e.NewValue)
                return;
            Level.selectedScreen = (int)e.NewValue;
            if ((uint)Level.selectedScreen >= 0xEF)
                Level.selectedScreen = 0xEF;
            DrawScreen();
        }

        private void gridBtn_Click(object sender, RoutedEventArgs e)
        {
            if (layoutGrid.ShowGridLines)
                layoutGrid.ShowGridLines = false;
            else
                layoutGrid.ShowGridLines = true;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            var b = (Button)sender;
            int i = Convert.ToInt32(b.Content.ToString(), 16) - 1;
            if (Level.BG == i)
                return;
            Level.BG = i;
            if(past != null)
            {
                past.Background = Brushes.Black;
                past.Foreground = Brushes.White;
            }
            b.Background = Brushes.LightBlue;
            b.Foreground = Brushes.Black;
            past = b;
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
        #endregion Events
    }
}
