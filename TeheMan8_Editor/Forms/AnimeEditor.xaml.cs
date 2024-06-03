using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Shapes;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for AnimeEditor.xaml
    /// </summary>
    public partial class AnimeEditor : UserControl
    {
        #region Fields
        public static int clut;
        public static int copyId = -1;
        #endregion Fields

        #region Constructors
        public AnimeEditor()
        {
            InitializeComponent();

            /*Must be disabled until frame max issue can be solved...*/
            frameInt.IsEnabled = false;
            destInt.IsEnabled = false;
            setInt.IsEnabled = false;
            lengthInt.IsEnabled = false;
            timerint.IsEnabled = false;
            animeInt.IsEnabled = false;

        }
        #endregion Constructors

        #region Methods
        public void AssignLimits()
        {
            int index = PSX.levels[Level.Id].GetIndex();
            bool disable = false;

            if(index != -1)
            {
                if (Const.MaxClutAnimes[index] == 0xFF)
                    disable = true;
            }

            if (PSX.levels[Level.Id].clutAnime == null || index == -1 || disable) //Disable
            {
                MainWindow.window.animeE.animeInt.IsEnabled = false;
            }
            else
            {
                if (!MainWindow.window.animeE.IsEnabled)
                {

                }
                MainWindow.window.animeE.animeInt.Maximum = Const.MaxClutAnimes[index];
                copyId = -1;
            }
            DrawClut();
        }
        private void AssignClutSettings()
        {
            int index = PSX.levels[Level.Id].GetIndex();

            uint address = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.ClutInfoPointersAddress + (index * 4))));
            uint pointersAddress = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(address + (int)animeInt.Value * 4)));

            if(pointersAddress == Const.NullClutAddress)
            {
                //Disable Clut Settings
            }
            else
            {
                //TODO: need to find some way to automatically determine max frames amount...

                int offset = PSX.CpuToOffset(BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset(pointersAddress)));
                offset += (int)frameInt.Value * 4;

                MainWindow.window.animeE.destInt.Value = PSX.exe[offset];
                MainWindow.window.animeE.setInt.Value = PSX.exe[offset + 1];
                MainWindow.window.animeE.lengthInt.Value = PSX.exe[offset + 2];
                MainWindow.window.animeE.timerint.Value = PSX.exe[offset + 3];

                if (!MainWindow.window.animeE.frameInt.IsEnabled)
                {
                    MainWindow.window.animeE.frameInt.IsEnabled = true;
                    MainWindow.window.animeE.destInt.IsEnabled = true;
                    MainWindow.window.animeE.setInt.IsEnabled = true;
                    MainWindow.window.animeE.lengthInt.IsEnabled = true;
                    MainWindow.window.animeE.timerint.IsEnabled = true;
                }
            }
        }
        public void DrawClut()
        {
            if (PSX.levels[Level.Id].clutAnime != null)
            {
                int setCount = PSX.levels[Level.Id].clutAnime.Length / 32;


                while (MainWindow.window.animeE.clutGrid.RowDefinitions.Count != setCount)
                {
                    if (MainWindow.window.animeE.clutGrid.RowDefinitions.Count > setCount)
                    {
                        MainWindow.window.animeE.clutGrid.RowDefinitions.RemoveAt(0);
                        for (int i = 0; i < 16; i++)
                            MainWindow.window.animeE.clutGrid.Children.RemoveAt(0);
                    }
                    else
                    {
                        MainWindow.window.animeE.clutGrid.RowDefinitions.Add(new RowDefinition());
                        for (int i = 0; i < 16; i++)
                        {
                            Rectangle r = new Rectangle();
                            r.Focusable = false;
                            r.Width = 16;
                            r.Height = 16;
                            r.MouseDown += Color_Down;
                            r.HorizontalAlignment = HorizontalAlignment.Stretch;
                            r.VerticalAlignment = VerticalAlignment.Stretch;
                            MainWindow.window.animeE.clutGrid.Children.Add(r);
                        }
                    }
                }
                if (MainWindow.window.animeE.clutGrid.Visibility != Visibility.Visible)
                    MainWindow.window.animeE.clutGrid.Visibility = Visibility.Visible;

                for (int y = 0; y < setCount; y++)
                {
                    for (int x = 0; x < 16; x++)
                    {
                        //Create Color
                        Rectangle r = MainWindow.window.animeE.clutGrid.Children[x + y * 16] as Rectangle;

                        ushort val = BitConverter.ToUInt16(PSX.levels[Level.Id].clutAnime, (x + y * 16) * 2);
                        int rgb32 = Level.To32Rgb(val);

                        r.Fill = new SolidColorBrush(Color.FromRgb((byte)(rgb32 >> 16), (byte)((rgb32 >> 8) & 0xFF), (byte)(rgb32 & 0xFF)));

                        Grid.SetRow(r, y);
                        Grid.SetColumn(r, x);
                    }
                }
                MainWindow.window.animeE.canvas.Height = setCount * 16;
                MainWindow.window.animeE.clutGrid.Height = setCount * 16;
                int cord = (int)(Canvas.GetTop(MainWindow.window.animeE.cursor) / 16);
                if (cord > setCount)
                {
                    clut = setCount - 1;
                    UpdateClutTxt();
                }
            }
            else //Disable
            {
                MainWindow.window.animeE.clutGrid.Visibility = Visibility.Collapsed;
            }
        }
        public void UpdateClutTxt() //also update Cursor
        {
            MainWindow.window.animeE.clutTxt.Text = "CLUT: " + Convert.ToString(clut, 16).ToUpper().PadLeft(2, '0'); //Update Txt
            Canvas.SetTop(MainWindow.window.animeE.cursor, clut * 16);
        }
        public bool ContainsAnime()
        {
            if (PSX.levels[Level.Id].clutAnime == null)
            {
                MessageBox.Show("There is on Clut Anime in this Level");
                return false;
            }
            return true;
        }
        public void CopySet()
        {
            if (ContainsAnime())
                copyId = clut;
        }
        public void PasteSet()
        {
            if (ContainsAnime() && copyId != -1)
            {
                Array.Copy(PSX.levels[Level.Id].clutAnime, copyId * 32, PSX.levels[Level.Id].clutAnime, clut * 32, 32);
                PSX.levels[Level.Id].edit = true;
                DrawClut();
            }
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
                ushort oldC = BitConverter.ToUInt16(PSX.levels[Level.Id].clutAnime, (c + r * 16) * 2);

                var d = new ColorDialog(oldC, c, r);
                d.ShowDialog();
                if (d.confirm)
                {
                    ushort newC = (ushort)Level.To15Rgb(d.canvas.SelectedColor.Value.B, d.canvas.SelectedColor.Value.G, d.canvas.SelectedColor.Value.R);

                    if (newC != oldC)
                    {
                        BitConverter.GetBytes(newC).CopyTo(PSX.levels[Level.Id].clutAnime, (c + r * 16) * 2);
                        PSX.levels[Level.Id].edit = true;

                        //Convert & Change Clut in GUI
                        int rgb32 = Level.To32Rgb(newC);
                        ((Rectangle)sender).Fill = new SolidColorBrush(Color.FromRgb((byte)(rgb32 >> 16), (byte)((rgb32 >> 8) & 0xFF), (byte)(rgb32 & 0xFF)));
                    }
                }
            }
            else //Change selected Clut
            {
                clut = Grid.GetRow(sender as UIElement);
                UpdateClutTxt();
            }
        }
        private void destInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int index = PSX.levels[Level.Id].GetIndex();

            uint address = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.ClutInfoPointersAddress + (index * 4))));
            uint pointersAddress = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(address + (int)animeInt.Value * 4)));
            int offset = PSX.CpuToOffset(BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset(pointersAddress)));
            offset += (int)frameInt.Value * 4;

            if ((int)e.NewValue != PSX.exe[offset])
            {
                PSX.exe[offset] = (byte)(int)e.NewValue;
                PSX.edit = true;
            }
        }
        private void setInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int index = PSX.levels[Level.Id].GetIndex();

            uint address = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.ClutInfoPointersAddress + (index * 4))));
            uint pointersAddress = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(address + (int)animeInt.Value * 4)));
            int offset = PSX.CpuToOffset(BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset(pointersAddress)));
            offset += (int)frameInt.Value * 4;

            if ((int)e.NewValue != PSX.exe[offset] + 1)
            {
                PSX.exe[offset + 1] = (byte)(int)e.NewValue;
                PSX.edit = true;
            }
        }
        private void lengthInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int index = PSX.levels[Level.Id].GetIndex();

            uint address = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.ClutInfoPointersAddress + (index * 4))));
            uint pointersAddress = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(address + (int)animeInt.Value * 4)));
            int offset = PSX.CpuToOffset(BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset(pointersAddress)));
            offset += (int)frameInt.Value * 4;

            if ((int)e.NewValue != PSX.exe[offset + 2])
            {
                PSX.exe[offset + 2] = (byte)(int)e.NewValue;
                PSX.edit = true;
            }
        }
        private void timerint_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;

            int index = PSX.levels[Level.Id].GetIndex();

            uint address = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(Const.ClutInfoPointersAddress + (index * 4))));
            uint pointersAddress = BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset((uint)(address + (int)animeInt.Value * 4)));
            int offset = PSX.CpuToOffset(BitConverter.ToUInt32(PSX.exe, PSX.CpuToOffset(pointersAddress)));
            offset += (int)frameInt.Value * 4;

            if ((int)e.NewValue != PSX.exe[offset + 3])
            {
                PSX.exe[offset + 3] = (byte)(int)e.NewValue;
                PSX.edit = true;
            }
        }
        private void frameInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
        }
        private void animeInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (PSX.levels.Count == 0 || e.NewValue == null || e.OldValue == null)
                return;
        }
        private void CopyButton_Click(object sender, RoutedEventArgs e)
        {
            CopySet();
        }

        private void PasteButton_Click(object sender, RoutedEventArgs e)
        {
            PasteSet();
        }

        private void GearBtn_Click(object sender, RoutedEventArgs e)
        {
            if (ContainsAnime())
            {
                ListWindow.isAnime = true;
                ListWindow l = new ListWindow(5);
                l.ShowDialog();
            }
        }
        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            if (!ContainsAnime()) return;

            int setCount = PSX.levels[Level.Id].clutAnime.Length / 32;

            if (setCount == 256)
            {
                MessageBox.Show("You can't have more than 256 Clut Anime Sets");
                return;
            }
            Array.Resize(ref PSX.levels[Level.Id].clutAnime, (setCount + 1) * 32);
            setInt.Maximum++;
            PSX.levels[Level.Id].edit = true;
            DrawClut();
        }

        private void RemoveButton_Click(object sender, RoutedEventArgs e)
        {
            if (!ContainsAnime()) return;


            int setCount = PSX.levels[Level.Id].clutAnime.Length / 32;

            if (setCount != 1)
            {
                Array.Resize(ref PSX.levels[Level.Id].clutAnime, (setCount - 1) * 32);
                setInt.Maximum--;
                PSX.levels[Level.Id].edit = true;

                if (clut > setCount - 2)
                {
                    clut = setCount - 2;
                    UpdateClutTxt();
                }
                if (copyId > setCount - 2)
                    copyId = -1;
                DrawClut();
            }
        }
        #endregion Events
    }
}
