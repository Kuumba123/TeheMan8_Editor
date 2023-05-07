using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for ListWindow.xaml
    /// </summary>
    public partial class ListWindow : Window
    {
        #region Fields
        public static bool screenViewOpen = false;
        public static bool extraOpen = false;
        public static bool fileViewOpen;
        public string tab = "";
        public static int layoutOffset = 0;
        public static bool enemyOpen = false;
        #endregion Fields

        #region Properties
        public int mode;
        #endregion Properties

        #region Constructors
        public ListWindow() //For viewering Serial Loading
        {
            InitializeComponent();
            this.Title = "NOPS Output";
            this.Width = 460;
            this.Height = 400;
            this.ResizeMode = ResizeMode.NoResize;
            this.mode = 0;
            TextBox t = new TextBox();
            t.FontSize = 16;
            t.TextWrapping = TextWrapping.NoWrap;
            t.AcceptsReturn = true;
            t.IsReadOnly = true;
            t.Foreground = Brushes.White;
            t.Background = Brushes.Black;
            this.grid.Children.Add(t);

            DispatcherTimer dt = new DispatcherTimer();
            dt.Interval = TimeSpan.FromMilliseconds(1000 / 30);
            dt.Tick += (s, e) =>
            {
                if(mode >= 66) //Done
                {
                    if (Settings.nops.HasExited)
                    {
                        Settings.nops.CancelOutputRead();
                        PSX.SerialCont();
                        mode = -1;
                        dt.Stop();
                        this.Close();
                    }
                    return;
                }
                if((mode & 1) == 1) //Wait
                {
                    if (Settings.nops.HasExited)
                        mode++;
                    return;
                }
                if(mode > 25 && mode < 46) //Checkpoint
                {
                    int stageId = (int)SpawnWindow.GetSpawnIndex();
                    int checkPoint = (mode - 26) / 2;
                    if (SpawnWindow.GetSpawnIndex() == -1 || checkPoint > Const.MaxPoints[stageId])
                    {
                        mode = 46;
                        return;
                    }
                    byte[] data = new byte[24];
                    uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.CheckPointPoiners + (stageId * 4))));
                    uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (checkPoint * 4)));
                    Array.Copy(PSX.exe, PSX.CpuToOffset(dataAddress), data, 0, data.Length);

                    Settings.nops.CancelOutputRead();
                    PSX.SerialWrite(dataAddress, data);
                    this.Title = "Writting Checkpoint Data";
                    Settings.nops.BeginOutputReadLine();
                    mode++;
                    return;
                }
                if(mode > 45 && mode < 66) //Background Info
                {
                    int checkPoint = (mode - 46) / 2;
                    int stageId = SpawnWindow.GetSpawnIndex();
                    if (SpawnWindow.GetSpawnIndex() == -1 || checkPoint > Const.MaxBGEffects[stageId])
                    {
                        mode = 66;
                        return;
                    }

                    byte[] data = new byte[12];
                    uint address = BitConverter.ToUInt32(PSX.exe, (int)PSX.CpuToOffset((uint)(Const.EffectsBGAddress + (stageId * 4))));
                    uint dataAddress = BitConverter.ToUInt32(PSX.exe, (int)(PSX.CpuToOffset(address) + (checkPoint * 4)));
                    Array.Copy(PSX.exe, PSX.CpuToOffset(dataAddress), data, 0, data.Length);

                    Settings.nops.CancelOutputRead();
                    PSX.SerialWrite(dataAddress, data);
                    this.Title = "Writting Background Info";
                    Settings.nops.BeginOutputReadLine();
                    mode++;
                    return;
                }

                switch (mode)
                {
                    case 0:
                        PSX.SerialHalt();
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 2: //Layout 1
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x8016ef34, PSX.levels[Level.Id].layout);
                        this.Title = "Writting LAYOUT 1 DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 4: //Layout 2
                        if (!PSX.levels[Level.Id].pac.ContainsEntry(1))
                        {
                            mode += 2;
                        }
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x8016f334, PSX.levels[Level.Id].layout2);
                        this.Title = "Writting LAYOUT 2 DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 6: //Layout 3
                        if (!PSX.levels[Level.Id].pac.ContainsEntry(1))
                        {
                            mode += 2;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x8016f734, PSX.levels[Level.Id].layout3);
                        this.Title = "Writting LAYOUT 3 DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;

                    case 8: //Screen Data
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x80171c3c, PSX.levels[Level.Id].screenData);
                        this.Title = "Writting Active Screen DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 10: //Screen Data (Backup)
                        if (MainWindow.settings.noScreenReload)
                        {
                            mode += 2;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x80190040, PSX.levels[Level.Id].screenData);
                        this.Title = "Writting Backup Screen DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 12: //Enemy Data
                        if (!PSX.levels[Level.Id].pac.ContainsEntry(10))
                        {
                            mode += 2;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        byte[] enemyData = new byte[0x800];
                        PSX.levels[Level.Id].DumpEnemyData(enemyData);
                        PSX.SerialWrite(0x801c2b3c, enemyData);
                        this.Title = "Writting Enemy Data";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 14: //Clut
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x80158f64, PSX.levels[Level.Id].pal);
                        this.Title = "Writting Clut DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 16: //Backup Clut
                        if (MainWindow.settings.noClutReload)
                        {
                            mode += 2;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x8015a064, PSX.levels[Level.Id].pal);
                        this.Title = "Writting Backup Clut DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;

                    case 18: //Tile Info
                        Settings.nops.CancelOutputRead();
                        PSX.SerialWrite(0x8015ea88, PSX.levels[Level.Id].tileInfo);
                        this.Title = "Writting Tile Info DATA";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 20: //Water Level
                        if (SpawnWindow.GetSpawnIndex() == -1)
                        {
                            mode += 4;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        uint stageId = (uint)SpawnWindow.GetSpawnIndex();
                        uint addr = Const.WaterLevelAddress;
                        if (SpawnWindow.MidCheck())
                            addr += 2;
                        addr += stageId * 4;

                        PSX.SerialWrite(0x801b2988, BitConverter.ToUInt16(PSX.exe, (int)PSX.CpuToOffset(addr)));
                        this.Title = "Writting Water Height";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 22: //Water ...
                        Settings.nops.CancelOutputRead();
                        stageId = (uint)SpawnWindow.GetSpawnIndex();
                        addr = Const.WaterLevelAddress;
                        if (SpawnWindow.MidCheck())
                            addr += 2;
                        addr += stageId * 4;
                        PSX.SerialWrite(addr, BitConverter.ToUInt16(PSX.exe, (int)PSX.CpuToOffset(addr)));
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    case 24: //Mid Point
                        if(SpawnWindow.GetSpawnIndex() == -1)
                        {
                            mode += 2;
                            break;
                        }
                        Settings.nops.CancelOutputRead();
                        stageId = (uint)SpawnWindow.GetSpawnIndex();
                        PSX.SerialWrite(Const.MidCheckPointAddress + stageId, PSX.exe[PSX.CpuToOffset(Const.MidCheckPointAddress + stageId)]);
                        this.Title = "Writting Mid Point";
                        Settings.nops.BeginOutputReadLine();
                        mode++;
                        break;


                    default:
                        break;
                }
            };
            dt.Start();
        }
        public ListWindow(PAC pac) //For Editing PAC files
        {
            InitializeComponent();
            this.ResizeMode = ResizeMode.NoResize;
            //Form Prep
            AddGrids(2, 1);
            foreach (var e in pac.entries)
                pannel.Children.Add(new PacEntry(e));
            if (pac.filename != null)
                this.Title = "Now editing - " + pac.filename;
            else
                this.Title = "Now editing - NEW PAC FILE";
            this.Width += 100;
            this.Height += 200;
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions[1].Height = GridLength.Auto;
            this.outGrid.RowDefinitions[2].Height = new GridLength(60);

            Separator gridSplitter = new Separator()
            {
                Background = Brushes.Gray,
                Height = 5
            };
            Grid.SetRow(gridSplitter, 1);
            Button addBtn = new Button()
            {
                Content = "Add",
                Width = 80,
                Height = 30,
                Margin = new Thickness(5, 2, 4, 0)
            };
            addBtn.Click += (s, e) =>
            {
                PacEntry p = new PacEntry();
                p.pathBox.Text = "...";
                pannel.Children.Add(p);
            };

            Button saveAsBtn = new Button()
            {
                Content = "Save As",
                Width = 80,
                Height = 30,
                Margin = new Thickness(5,2,4,0)
            };
            saveAsBtn.Click += (s, e) =>
            {
                if(pannel.Children.Count == 1) //No Pac Entries
                {
                    MessageBox.Show("You must have atleast 1 PAC entry before you can save the file");
                    return;
                }
                PAC newPAC = new PAC(); //New ouput PAC

                foreach (var c in pannel.Children) //Validation
                {
                    if (c.GetType() != typeof(PacEntry))
                        continue;

                    PacEntry pacE = c as PacEntry;
                    if(pacE.entry.data == null)
                    {
                        MessageBox.Show("Not all entries contain data");
                        return;
                    }
                    newPAC.entries.Add(pacE.entry);
                }
                //Time to Export new PAC file
                System.Windows.Forms.SaveFileDialog fd = new System.Windows.Forms.SaveFileDialog();
                fd.Filter = "PAC |*.PAC";

                if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    File.WriteAllBytes(fd.FileName, newPAC.GetEntriesData());
                }
            };
            Grid.SetRow(saveAsBtn, 2);

            CheckBox msbCheck = new CheckBox() //Sega Saturn support
            {
                Content = "Is MSB",
                FontSize = 18,
                VerticalAlignment = VerticalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
                IsChecked = pac.isMSB
            };

            StackPanel stackP = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                HorizontalAlignment = HorizontalAlignment.Right
            };
            Grid.SetRow(stackP, 2);

            //Add Contents to Pannel
            this.outGrid.Children.Add(stackP);
            this.outGrid.Children.Add(gridSplitter);
            stackP.Children.Add(addBtn);
            stackP.Children.Add(msbCheck);
            stackP.Children.Add(saveAsBtn);
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
                    int cordId = Convert.ToInt32((((Image)s).Name).Replace("_","")) & 0xFF;
                    int height = (int)((Image)s).Source.Height;
                    if (cordId > 4)
                    {
                        x = "?";
                        y = "?";
                    }
                    else
                    {
                        x = (Const.CordTabe[cordId] & 0xFFFF).ToString();
                        y = (Const.CordTabe[cordId] >> 16).ToString();
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
                var pal = new BitmapPalette(Const.GreyScale);
                var bmp = new WriteableBitmap(256, p.Length / 128, 96, 96, PixelFormats.Indexed4, pal);
                bmp.WritePixels(new Int32Rect(0, 0, 256, p.Length / 128), p, 128, 0);
                //Add to Window
                image.Source = bmp;
                b.Child = image;
                pannel.Children.Add(b);
            }
        }
        public ListWindow(bool t) //Dummy
        {
            InitializeComponent();
        }
        public ListWindow(int action) //Various
        {
            Action[] acts = new Action[] { ScreenGrid, LayoutEdit, ExtraGrid , EnemyTools , FileViewer};
            InitializeComponent();
            mode = -action;
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
            this.AddGrids(32, 32);
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
                        b.Content = Convert.ToString(PSX.levels[Level.Id].layout[x + (y * 32)], 16).ToUpper();
                    else if(Level.BG == 1)
                        b.Content = Convert.ToString(PSX.levels[Level.Id].layout2[x + (y * 32)], 16).ToUpper();
                    else
                        b.Content = Convert.ToString(PSX.levels[Level.Id].layout3[x + (y * 32)], 16).ToUpper();
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
            System.Drawing.Point point = System.Windows.Forms.Control.MousePosition;
            this.Left = point.X - 180;
            this.Top = point.Y - 50;
            //Setup INT UP/DOWN
            var integer = new NumInt();
            integer.Maximum = PSX.levels[Level.Id].screenData.Length / 0x200;
            integer.Minimum = 0;
            integer.ButtonSpinnerWidth = 45;
            integer.ParsingNumberStyle = System.Globalization.NumberStyles.HexNumber;
            integer.FormatString = "X";
            integer.FontSize = 40;
            integer.TextAlignment = TextAlignment.Center;
            integer.AllowTextInput = true;
            //Set current screen Value
            integer.Value = 1;
            if (Level.BG == 0)
                integer.Value = PSX.levels[Level.Id].layout[layoutOffset];
            else if (Level.BG == 1)
                integer.Value = PSX.levels[Level.Id].layout2[layoutOffset];
            else
                integer.Value = PSX.levels[Level.Id].layout3[layoutOffset];

            //Setup Confirm Button
            Button okBtn = new Button();
            okBtn.Content = "Modify";
            okBtn.Click += (s, e) =>
            {
                try
                {
                    if (Level.BG == 0)
                        PSX.levels[Level.Id].layout[layoutOffset] = (byte)integer.Value;
                    else if (Level.BG == 1)
                        PSX.levels[Level.Id].layout2[layoutOffset] = (byte)integer.Value;
                    else
                        PSX.levels[Level.Id].layout3[layoutOffset] = (byte)integer.Value;
                    PSX.levels[Level.Id].edit = true;
                    MainWindow.window.layoutE.DrawLayout();
                }catch(Exception ex)
                {
                    MessageBox.Show(ex.Message, "ERROR");
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
        private void ExtraGrid() //Change Extra flags in Screen
        {
            extraOpen = true;
            this.AddGrids(16, 16);
            this.scroll.VerticalScrollBarVisibility = ScrollBarVisibility.Hidden;
            this.Width = 592;
            this.Height = 646;
            this.Title = "Screen: " + Convert.ToString(MainWindow.window.screenE.screenId, 16).ToUpper() + " Tile Flags";
            this.ResizeMode = ResizeMode.CanMinimize;

            //Add Top Bar Controls
            DockPanel dock = new DockPanel();
            Rectangle rect = new Rectangle()
            {
                Width = 10,
                Height = 10,
                HorizontalAlignment = HorizontalAlignment.Right,
                Margin = new Thickness(5, 0, 5, 0),
                Fill = Brushes.Blue
            };
            Button bt1 = new Button()
            {
                Content = "Fill",
                Width = 55,
                Style = Application.Current.FindResource("TileButton") as Style
            };
            bt1.Click += (s, e) =>
            {
                byte arg;
                if (rect.Fill == Brushes.Blue) //Trans or Priority
                    arg = 0x20;
                else
                    arg = 0x10;

                for (int i = 0; i < 0x200; i++)
                {
                    byte flag = PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + i * 2];
                    flag |= arg;
                    PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + i * 2] = flag;
                }
                PSX.levels[Level.Id].edit = true;
                DrawExtra();
            };
            Button bt2 = new Button()
            {
                Content = "Clear",
                Width = 55,
                Style = Application.Current.FindResource("TileButton") as Style
            };
            bt2.Click += (s, e) =>
            {
                byte arg;
                if (rect.Fill == Brushes.Blue) //Trans or Priority
                    arg = 0x20;
                else
                    arg = 0x10;

                for (int i = 0; i < 0x200; i++)
                {
                    byte flag = PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + i * 2];
                    flag &= (byte)(arg ^ 0xFF);
                    PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + i * 2] = flag;
                }
                PSX.levels[Level.Id].edit = true;
                DrawExtra();
            };
            Button bt3 = new Button()
            {
                Content = "Toggle",
                Width = 65,
                Style = Application.Current.FindResource("TileButton") as Style
            };
            bt3.Click += (s, e) =>
            {
                if (rect.Fill == Brushes.Blue)
                    rect.Fill = Brushes.Red;
                else
                    rect.Fill = Brushes.Blue;
            };
            dock.Children.Add(bt1);
            dock.Children.Add(bt2);
            dock.Children.Add(bt3);
            dock.Children.Add(rect);
            this.pannel.Children.Insert(0, dock);

            //Add Grid
            for (int y = 0; y < 16; y++)
            {
                for (int x = 0; x < 16; x++)
                {
                    Rectangle r = new Rectangle();
                    Border b = new Border();
                    b.MouseDown += (s, e) => //Click event for changing flags
                    {
                        int col = Grid.GetColumn(s as UIElement);
                        int row = Grid.GetRow(s as UIElement);
                        byte flag = PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32];
                        byte arg;
                        if (rect.Fill == Brushes.Blue) //Trans or Priority
                            arg = 0x20;
                        else
                            arg = 0x10;
                        Rectangle re = ((Border)s).Child as Rectangle;
                        if (e.ChangedButton == System.Windows.Input.MouseButton.Right)
                        {
                            if ((flag & arg) == 0)
                                return;
                            flag &= (byte)(arg ^ 0xFF);
                            PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32] = flag;
                            PSX.levels[Level.Id].edit = true;
                            if (arg == 0x20)
                                re.Fill = Brushes.Black;
                            else
                                ((Border)s).BorderBrush = Brushes.White;
                        }
                        else
                        {
                            if ((flag & arg) != 0)
                                return;
                            flag |= arg;
                            PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32] = flag;
                            PSX.levels[Level.Id].edit = true;
                            if (arg == 0x20)
                                re.Fill = Brushes.Blue;
                            else
                                ((Border)s).BorderBrush = Brushes.Red;
                        }
                    };
                    b.MouseMove += (s, e) => //Ease of Use
                    {
                        if(e.RightButton == System.Windows.Input.MouseButtonState.Pressed || e.LeftButton == System.Windows.Input.MouseButtonState.Pressed)
                        {
                            Point p = e.GetPosition(grid);
                            HitTestResult result = VisualTreeHelper.HitTest(grid, p);
                            if (result != null)
                            {
                                int col = Grid.GetColumn(s as UIElement);
                                int row = Grid.GetRow(s as UIElement);
                                byte flag = PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32];
                                byte arg;

                                if (rect.Fill == Brushes.Blue) //Trans or Priority
                                    arg = 0x20;
                                else
                                    arg = 0x10;
                                Border bd = s as Border;
                                Rectangle re2 = bd.Child as Rectangle;

                                if (e.RightButton == System.Windows.Input.MouseButtonState.Pressed)
                                {
                                    if ((flag & arg) == 0)
                                        return;
                                    flag &= (byte)(arg ^ 0xFF);
                                    PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32] = flag;
                                    PSX.levels[Level.Id].edit = true;
                                    if (arg == 0x20)
                                        re2.Fill = Brushes.Black;
                                    else
                                        ((Border)s).BorderBrush = Brushes.White;
                                }
                                else
                                {
                                    if ((flag & arg) != 0)
                                        return;
                                    flag |= arg;
                                    PSX.levels[Level.Id].screenData[MainWindow.window.screenE.screenId * 0x200 + 1 + (col * 2) + row * 32] = flag;
                                    PSX.levels[Level.Id].edit = true;
                                    if (arg == 0x20)
                                        re2.Fill = Brushes.Blue;
                                    else
                                        ((Border)s).BorderBrush = Brushes.Red;
                                }
                            }
                        }
                    };
                    b.BorderThickness = new Thickness(2);
                    r.Width = 32;
                    r.Height = 32;
                    ushort tile = BitConverter.ToUInt16(PSX.levels[Level.Id].screenData, MainWindow.window.screenE.screenId * 0x200 + (x * 2) + y * 32);

                    //Set flags
                    if ((tile & 0x2000) == 0x2000)
                        r.Fill = Brushes.Blue;
                    else
                        r.Fill = Brushes.Black;
                    if ((tile & 0x1000) == 0x1000)
                        b.BorderBrush = Brushes.Red;
                    else
                        b.BorderBrush = Brushes.White;

                    //Prep for adding to Form
                    b.Child = r;
                    Grid.SetColumn(b, x);
                    Grid.SetRow(b, y);
                    this.grid.Children.Add(b);
                }
            }
        }
        private void EnemyTools() //Export Enemies for Enemy Tab etc
        {
            //Setup Form
            this.Title = PSX.levels[Level.Id].pac.filename + " Enemies " + Convert.ToString(PSX.levels[Level.Id].enemies.Count, 16).ToUpper();
            this.Height = 800;
            this.Width = 410;
            this.MaxWidth = this.Width;
            this.ResizeMode = ResizeMode.NoResize;
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions.Add(new RowDefinition());
            this.outGrid.RowDefinitions[1].Height = new GridLength(40);
            this.outGrid.RowDefinitions[2].Height = new GridLength(40);
            this.outGrid.RowDefinitions[3].Height = new GridLength(40);

            //Show List of Enemies
            ListView listView = new ListView();
            foreach (var e in PSX.levels[Level.Id].enemies) //Add each enemy
            {
                Label l = new Label();
                l.FontSize = 22;
                l.Content = "ID: " + (Convert.ToString(e.id, 16) + " TYPE: " + e.type.ToString() + " VAR: " + Convert.ToString(e.var, 16) + " X: " + Convert.ToString(e.x, 16) + " Y: " + Convert.ToString(e.y, 16)).ToUpper();
                l.Content.ToString().ToUpper();
                l.Foreground = Brushes.White;
                listView.Items.Add(l);
            }
            listView.Background = Brushes.Black;
            pannel.Children.Add(listView);



            //Remove
            Button rmvBtn = new Button();
            rmvBtn.Content = "Remove";
            rmvBtn.Click += (s, e) =>
            {
                if (listView.SelectedIndex == -1)
                    return;
                listView.Items.Remove(listView.SelectedItem);
                this.Title = PSX.levels[Level.Id].pac.filename + " Enemies " + Convert.ToString(listView.Items.Count, 16).ToUpper();
            };
            Grid.SetRow(rmvBtn, 1);


            //Export
            Button jsonExpBtn = new Button();
            jsonExpBtn.Content = "Export JSON";
            jsonExpBtn.Click += (s, e) =>
            {
                using(var fd = new System.Windows.Forms.SaveFileDialog())
                {
                    fd.Filter = "JSON |*.json";
                    
                    if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        try
                        {
                            string json = JsonConvert.SerializeObject(PSX.levels[Level.Id].enemies, Formatting.Indented);
                            File.WriteAllText(fd.FileName, json);
                            MessageBox.Show(PSX.levels[Level.Id].pac.filename + " enemy data has been exported!");
                        }catch(Exception ex)
                        {
                            MessageBox.Show("ERROR", ex.Message);
                        }
                    }
                }
            };
            Grid.SetRow(jsonExpBtn, 2);



            //Import
            Button jsonImpBtn = new Button();
            jsonImpBtn.Content = "Import JSON";
            jsonImpBtn.Click += (s, e) =>
            {
                using(var fd = new System.Windows.Forms.OpenFileDialog())
                {
                    fd.Filter = "JSON |*.json";

                    if(fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                    {
                        try
                        {
                            PSX.levels[Level.Id].enemies = JsonConvert.DeserializeObject<List<Enemy>>(File.ReadAllText(fd.FileName));
                            PSX.levels[Level.Id].edit = true;

                            listView.Items.Clear();
                            foreach (var en in PSX.levels[Level.Id].enemies) //Add enemies from JSON
                            {
                                Label l = new Label();
                                l.FontSize = 22;
                                l.Content = "ID: " + (Convert.ToString(en.id, 16) + " TYPE: " + en.type.ToString() + " VAR: " + Convert.ToString(en.var, 16) + " X: " + Convert.ToString(en.x, 16) + " Y: " + Convert.ToString(en.y, 16)).ToUpper();
                                l.Content.ToString().ToUpper();
                                l.Foreground = Brushes.White;
                                listView.Items.Add(l);
                            }
                            this.Title = PSX.levels[Level.Id].pac.filename + " Enemies " + Convert.ToString(listView.Items.Count, 16).ToUpper();
                        }
                        catch (Exception ex)
                        {
                            MessageBox.Show("ERROR", ex.Message);
                        }
                    }
                }
            };
            Grid.SetRow(jsonImpBtn, 3);

            this.outGrid.Children.Add(rmvBtn);
            this.outGrid.Children.Add(jsonExpBtn);
            this.outGrid.Children.Add(jsonImpBtn);
        }
        private void FileViewer() //For Viewing Game Files
        {
            InitializeComponent();
            this.Title = "Level Files";
            this.ResizeMode = ResizeMode.CanMinimize;
            this.Width = 400;
            this.Height = 500;
            fileViewOpen = true;
            int i = 0;
            foreach (var l in PSX.levels)
            {
                Button b = new Button();
                b.Content = l.pac.filename;
                b.Click += (s, e) =>
                {
                    Level.Id = Convert.ToInt32(b.Uid);
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    MainWindow.window.Update();
                };
                b.Uid = i.ToString();
                i++;
                pannel.Children.Add(b);
            }
        }
        public void DrawScreens()
        {
            if (this.Visibility != Visibility.Visible)
                return;
            foreach (var u in this.grid.Children)
            {
                if (u.GetType() != typeof(Button))
                    continue;
                //Prep for Button Screen Id Change
                var b = u as Button;
                int c = Grid.GetColumn(u as UIElement);
                int r = Grid.GetRow(u as UIElement);
                if (Level.BG == 0)
                    b.Content = Convert.ToString(PSX.levels[Level.Id].layout[c + (r * 32)], 16).ToUpper();
                else if (Level.BG == 1)
                    b.Content = Convert.ToString(PSX.levels[Level.Id].layout2[c + (r * 32)], 16).ToUpper();
                else
                    b.Content = Convert.ToString(PSX.levels[Level.Id].layout3[c + (r * 32)], 16).ToUpper();
            }
        }
        public void DrawExtra() //Draw Tile flags
        {
            this.Title = "Screen: " + Convert.ToString(MainWindow.window.screenE.screenId, 16).ToUpper() + " Tile Flags";
            foreach (var u in this.grid.Children)
            {
                var b = u as Border;
                var rect = b.Child as Rectangle;

                int c = Grid.GetColumn(u as UIElement);
                int r = Grid.GetRow(u as UIElement);

                ushort tile = BitConverter.ToUInt16(PSX.levels[Level.Id].screenData, MainWindow.window.screenE.screenId * 0x200 + (c * 2) + r * 32);

                //Set flags Color
                if ((tile & 0x2000) == 0x2000)
                {
                    if (rect.Fill != Brushes.Blue)
                        rect.Fill = Brushes.Blue;
                }
                else
                {
                    if (rect.Fill != Brushes.Black)
                        rect.Fill = Brushes.Black;
                }
                if ((tile & 0x1000) == 0x1000)
                {
                    if (b.BorderBrush != Brushes.Red)
                        b.BorderBrush = Brushes.Red;
                }
                else
                {
                    if (b.BorderBrush != Brushes.White)
                        b.BorderBrush = Brushes.White;
                }
            }
        }
        private void AddGrids(int c,int r,bool outer = false)
        {
            Grid g = grid;
            if (outer)
                g = outGrid;
            while (true)
            {
                if (g.ColumnDefinitions.Count == c)
                    break;
                g.ColumnDefinitions.Add(new ColumnDefinition());
                g.ColumnDefinitions[g.ColumnDefinitions.Count - 1].Width = GridLength.Auto;
            }
            while (true)
            {
                if (g.RowDefinitions.Count == r)
                    break;
                g.RowDefinitions.Add(new RowDefinition());
                g.RowDefinitions[g.RowDefinitions.Count - 1].Height = GridLength.Auto;
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
                    break;
                case -2:
                    extraOpen = false;
                    break;

                case -3: //Enemy Tools
                    ListView listView = pannel.Children[1] as ListView;
                    PSX.levels[Level.Id].enemies.Clear();

                    foreach (var i in listView.Items) //Apply Enemies to Form
                    {
                        Label l = i as Label;
                        string str = l.Content.ToString();
                        str = str.Replace("ID:", "");
                        str = str.Replace("TYPE:", "");
                        str = str.Replace("VAR:", "");
                        str = str.Replace("X:", "");
                        str = str.Replace("Y:", "");
                        str = str.Trim();
                        string[] parama = str.Split();
                        //Add Enemy
                        Enemy en = new Enemy();
                        en.id = Convert.ToByte(parama[0],16);
                        en.type = Convert.ToByte(parama[2]);
                        en.var = Convert.ToByte(parama[4],16);
                        en.x = Convert.ToInt16(parama[6],16);
                        en.y = Convert.ToInt16(parama[8],16);
                        PSX.levels[Level.Id].enemies.Add(en);
                    }

                    MainWindow.window.enemyE.DisableSelect();
                    MainWindow.window.enemyE.DrawEnemies();
                    break;
                case -4:
                    fileViewOpen = false;
                    break;
                default:
                    break;
            }
        }
        #endregion Events
    }
}
