using Newtonsoft.Json;
using System;
using System.IO;
using System.Linq;
using System.Net.Http;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using TeheMan8_Editor.Forms;

namespace TeheMan8_Editor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        #region Fields
        internal static MainWindow window;
        internal static ListWindow fileWindow;
        internal static ListWindow layoutWindow;
        internal static ListWindow extraWindow;
        internal static ListWindow loadWindow;
        internal static Settings settings = Settings.SetDefaultSettings();
        #endregion Fields

        #region Properties
        private bool max = false;
        #endregion Properteis

        #region Constructors
        public MainWindow()
        {
            InitializeComponent();
            if (window == null)
            {
                window = this;
                PSX.lastSave = null;
                Settings.nops.EnableRaisingEvents = true;
                Settings.nops.OutputDataReceived += NOPS_OutputDataReceived;
                //Window Sizing
                {
                    int Y = (int)(40 * SystemParameters.PrimaryScreenWidth / 100);
                    window.layoutE.selectImage.MaxWidth = Y;
                    window.screenE.tileImage.MaxWidth = Y;
                    window.x16E.textureImage.MaxWidth = Y;
                }

                //Open Settings
                if (File.Exists("Settings.json"))
                {
                    try
                    {
                        settings = JsonConvert.DeserializeObject<Settings>(File.ReadAllText("Settings.json"));
                        settings.CheckForValidSettings();
                    }catch(Exception e)
                    {
                        MessageBox.Show(e.Message, "ERROR");
                        Application.Current.Shutdown();
                    }
                }
                //Get Arguments
                string[] args = Environment.GetCommandLineArgs();

                if (args.Length == 2) //Open Game Files using args
                {
                    if (!Directory.Exists(args[1]))
                    {
                        MessageBox.Show("The directory: " + args[1] + " does not exist.");
                        return;
                    }
                    //Look for all Game Files
                    if (!File.Exists(args[1] + "/SLUS_004.53"))
                    {
                        MessageBox.Show("The PSX.EXE (SLUS_004.53) was not found");
                        return;
                    }
                    //PSX.EXE was Found
                    Level.LoadLevels(args[1]);

                    if (PSX.levels.Count == 0) //Check for any PAC Level Files
                    {
                        MessageBox.Show("No PAC level files were found.");
                        return;
                    }
                    PSX.exe = File.ReadAllBytes(args[1] + "/SLUS_004.53");
                    PSX.time = File.GetLastWriteTime(args[1] + "/SLUS_004.53");
                    PSX.edit = false;
                    PSX.filePath = args[1];
                    Level.Id = 0;
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    //Draw Everything
                    Update();
                    hub.Visibility = Visibility.Visible;
                }
            }
            else
            {
                this.Title = "Tehe Sub Window";
                this.dockBar.Visibility = Visibility.Collapsed;
                this.hub.Visibility = Visibility.Visible;
            }
        }
        #endregion Constructors

        #region Methods
        public void Update()
        {
            window.layoutE.DrawLayout();
            window.layoutE.AssignLimits();
            window.screenE.AssignLimits();
            window.x16E.AssignLimits();
            window.enemyE.ReDraw();
            window.clutE.DrawTextures();
            window.clutE.DrawClut();
            window.clutE.UpdateClutTxt();
            window.spawnE.SetSpawnSettings();
            window.bgE.SetBackgroundSettings();
            if (ListWindow.screenViewOpen)
                layoutWindow.DrawScreens();
            if (ListWindow.extraOpen)
                extraWindow.DrawExtra();
            UpdateViewrCam();
            UpdateEnemyViewerCam();
            window.cameraE.SetupTab();
            SetFileTitle();
        }
        public void UpdateViewrCam()
        {
            if (window.layoutE.viewerX > 0x1D00)
                window.layoutE.viewerX = 0x1D00;
            if (window.layoutE.viewerY > 0x1D00)
                window.layoutE.viewerY = 0x1D00;
            window.layoutE.camLbl.Content = "X:" + Convert.ToString(window.layoutE.viewerX >> 8, 16).PadLeft(2, '0').ToUpper() + " Y:" + Convert.ToString(window.layoutE.viewerY >> 8, 16).PadLeft(2, '0').ToUpper();
        }
        public void UpdateEnemyViewerCam()
        {
            window.enemyE.camLbl.Content = "X:" + Convert.ToString(window.enemyE.viewerX >> 8, 16).PadLeft(2, '0').ToUpper() + " Y:" + Convert.ToString(window.enemyE.viewerY >> 8, 16).PadLeft(2, '0').ToUpper();
        }
        private void OpenGame()
        {
            var fd = new Ookii.Dialogs.Wpf.VistaFolderBrowserDialog();
            fd.Multiselect = false;
            fd.Description = "Select the Folder Containing the Game Files";
            fd.UseDescriptionForTitle = true;
            if ((bool)fd.ShowDialog())
            {
                //Look for all Game Files
                if (!File.Exists(fd.SelectedPath + "/SLUS_004.53"))
                {
                    MessageBox.Show("The PSX.EXE (SLUS_004.53) was not found");
                    return;
                }
                //PSX.EXE was Found
                Level.LoadLevels(fd.SelectedPath);

                if (PSX.levels.Count == 0) //Check for any PAC Level Files
                {
                    MessageBox.Show("No PAC level files were found.");
                    return;
                }
                PSX.exe = File.ReadAllBytes(fd.SelectedPath + "/SLUS_004.53");
                PSX.time = File.GetLastWriteTime(fd.SelectedPath + "/SLUS_004.53");
                PSX.filePath = fd.SelectedPath;
                Level.Id = 0;
                Level.AssignPallete();
                PSX.levels[Level.Id].LoadTextures();
                //Draw Everything
                Update();
                hub.Visibility = Visibility.Visible;
            }
        }
        public void MainKeyCheck(string key)
        {
            if (key == "F1")
            {
                if (Level.Id != 0)
                {
                    Level.Id--;
                    //RE-Update
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    Update();
                }
                else
                {
                    Level.Id = PSX.levels.Count - 1;
                    //RE-Update
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    Update();
                }
            }
            else if (key == "F2")
            {
                if (Level.Id != PSX.levels.Count - 1)
                {
                    Level.Id++;
                    //RE-Update
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    Update();
                }
                else
                {
                    Level.Id = 0;
                    //RE-Update
                    Level.AssignPallete();
                    PSX.levels[Level.Id].LoadTextures();
                    Update();
                }
            }
        }
        private void LayoutKeyCheck(string key, bool notFocus)
        {
            if (key == "Delete")
            {
                var result = MessageBox.Show("Are you sure you want to delete all of Layer " + (Level.BG + 1) + "?", "", MessageBoxButton.YesNo);

                if (result == MessageBoxResult.Yes)
                {
                    for (int i = 0; i < 0x400; i++)
                    {
                        if (Level.BG == 0)
                            PSX.levels[Level.Id].layout[i] = 0;
                        else if (Level.BG == 1)
                            PSX.levels[Level.Id].layout2[i] = 0;
                        else
                            PSX.levels[Level.Id].layout3[i] = 0;
                    }
                    window.layoutE.DrawLayout();
                    if (ListWindow.screenViewOpen)
                        layoutWindow.DrawScreens();
                }
                return;
            }
            if (!notFocus)  //check if NumInt is focused
                return;
            if (key == "W")
            {
                if (window.layoutE.viewerY != 0)
                {
                    window.layoutE.viewerY -= 0x100;
                    window.layoutE.DrawLayout();
                    UpdateViewrCam();
                }
            }
            else if (key == "S")
            {
                if (window.layoutE.viewerY != 0x1D00)
                {
                    window.layoutE.viewerY += 0x100;
                    window.layoutE.DrawLayout();
                    UpdateViewrCam();
                }
            }
            else if (key == "D")
            {
                if (window.layoutE.viewerX != 0x1D00)
                {
                    window.layoutE.viewerX += 0x100;
                    window.layoutE.DrawLayout();
                    UpdateViewrCam();
                }
            }
            else if (key == "A")
            {
                if (window.layoutE.viewerX != 0)
                {
                    window.layoutE.viewerX -= 0x100;
                    window.layoutE.DrawLayout();
                    UpdateViewrCam();
                }
            }
            else if (key == "D1")
            {
                if (Level.BG != 0)
                {
                    Level.BG = 0;
                    window.layoutE.DrawLayout();
                    window.layoutE.UpdateBtn();
                    if (ListWindow.screenViewOpen)
                    {
                        layoutWindow.DrawScreens();
                        layoutWindow.Title = "All Screens in Layer " + (Level.BG + 1);
                    }

                }
            }
            else if (key == "D2")
            {
                if (Level.BG != 1)
                {
                    Level.BG = 1;
                    window.layoutE.DrawLayout();
                    window.layoutE.UpdateBtn();
                    if (ListWindow.screenViewOpen)
                    {
                        layoutWindow.DrawScreens();
                        layoutWindow.Title = "All Screens in Layer " + (Level.BG + 1);
                    }
                }
            }
            else if (key == "D3")
            {
                if (Level.BG != 2)
                {
                    Level.BG = 2;
                    window.layoutE.DrawLayout();
                    window.layoutE.UpdateBtn();
                    if (ListWindow.screenViewOpen)
                    {
                        layoutWindow.DrawScreens();
                        layoutWindow.Title = "All Screens in Layer " + (Level.BG + 1);

                    }
                }
            }
        }
        private void ScreenKeyCheck(string key)
        {
            //Clear Screen
            if(key == "Delete")
            {
                Array.Clear(PSX.levels[Level.Id].screenData, window.screenE.screenId * 0x200, 0x200);
                PSX.levels[Level.Id].edit = true;
                window.layoutE.DrawLayout();
                if (window.layoutE.selectedScreen == window.screenE.screenId)
                    window.layoutE.DrawScreen();

                window.screenE.DrawScreen();
                window.enemyE.Draw();
            }
        }
        private void ClutKeyCheck(string key)
        {
            if (key == "Up")
            {
                ClutWindow.clut = (ClutWindow.clut - 1) & 0x3F;
                window.clutE.DrawTextures();
                window.clutE.UpdateClutTxt();
            }
            else if (key == "Down")
            {
                ClutWindow.clut = (ClutWindow.clut + 1) & 0x3F;
                window.clutE.DrawTextures();
                window.clutE.UpdateClutTxt();
            }
            else if (key == "Left")
            {
                window.clutE.UpdateTpageButton((ClutWindow.page - 1) & 7);
            }
            else if (key == "Right")
            {
                window.clutE.UpdateTpageButton((ClutWindow.page + 1) & 7);
            }
            else if (key == "D1")
            {
                window.clutE.UpdateSelectedTexture(0);
            }
            else if (key == "D2")
            {
                window.clutE.UpdateSelectedTexture(1);
            }
        }
        private void EnemyKeyCheck(string key, bool notFocus)
        {
            if (key == "Delete" && window.enemyE.control.Tag != null)
            {
                PSX.levels[Level.Id].enemies.Remove((Enemy)((EnemyLabel)window.enemyE.control.Tag).Tag);
                window.enemyE.DrawEnemies();
                PSX.levels[Level.Id].edit = true;
                return;
            }
            if (!notFocus)  //check if NumInt is focused
                return;
            if (key == "W")
            {
                if (window.enemyE.viewerY != 0)
                {
                    window.enemyE.viewerY -= 0x100;
                    window.enemyE.ReDraw();
                    UpdateEnemyViewerCam();
                }
            }
            else if (key == "S")
            {
                if (window.enemyE.viewerY != 0x1E00)
                {
                    window.enemyE.viewerY += 0x100;
                    window.enemyE.ReDraw();
                    UpdateEnemyViewerCam();
                }
            }
            else if (key == "D")
            {
                if (window.enemyE.viewerX != 0x1E00)
                {
                    window.enemyE.viewerX += 0x100;
                    window.enemyE.ReDraw();
                    UpdateEnemyViewerCam();
                }
            }
            else if (key == "A")
            {
                if (window.enemyE.viewerX != 0)
                {
                    window.enemyE.viewerX -= 0x100;
                    window.enemyE.ReDraw();
                    UpdateEnemyViewerCam();
                }
            }
        }
        internal bool SaveFiles(bool current = false /*option for saving current file*/)
        {
            if (PSX.exe == null)
                return false;
            if (current)
            {
                try
                {
                    if (File.Exists(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename))
                    {
                        if (!PSX.levels[Level.Id].edit && PSX.levels[Level.Id].time == File.GetLastWriteTime(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename))
                            return true;
                        File.WriteAllBytes(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename, PSX.levels[Level.Id].pac.GetEntriesData());
                        PSX.levels[Level.Id].time = File.GetLastWriteTime(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename);
                        PSX.levels[Level.Id].edit = false;
                    }
                    else
                    {
                        File.WriteAllBytes(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename, PSX.levels[Level.Id].pac.GetEntriesData());
                        PSX.levels[Level.Id].time = File.GetLastWriteTime(PSX.levels[Level.Id].pac.path + "/STDATA/" + PSX.levels[Level.Id].pac.filename);
                        PSX.levels[Level.Id].edit = false;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "ERROR");
                    return false;
                }
                return true;
            }
            foreach (var l in PSX.levels) //Save PAC Files
            {
                try
                {
                    l.ApplyLevelsToPAC();
                    if (File.Exists(l.pac.path + "/STDATA/" + l.pac.filename))
                    {
                        if (!l.edit && l.time == File.GetLastWriteTime(l.pac.path + "/STDATA/" + l.pac.filename))
                            continue;
                        File.WriteAllBytes(l.pac.path + "/STDATA/" + l.pac.filename, l.pac.GetEntriesData());
                        l.time = File.GetLastWriteTime(l.pac.path + "/STDATA/" + l.pac.filename);
                        l.edit = false;
                    }
                    else
                    {
                        File.WriteAllBytes(l.pac.path + "/STDATA/" + l.pac.filename, l.pac.GetEntriesData());
                        l.time = File.GetLastWriteTime(l.pac.path + "/STDATA/" + l.pac.filename);
                        l.edit = false;
                    }
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "ERROR");
                    return false;
                }
            }
            try
            {
                if (File.Exists(PSX.filePath + "/SLUS_004.53"))
                {
                    if (!PSX.edit && PSX.time == File.GetLastWriteTime(PSX.filePath + "/SLUS_004.53"))
                        return true;
                    File.WriteAllBytes(PSX.filePath + "/SLUS_004.53", PSX.exe);
                    PSX.time = File.GetLastWriteTime(PSX.filePath + "/SLUS_004.53");
                    PSX.edit = false;
                }
                else
                {
                    File.WriteAllBytes(PSX.filePath + "/SLUS_004.53", PSX.exe);
                    PSX.time = File.GetLastWriteTime(PSX.filePath + "/SLUS_004.53");
                    PSX.edit = false;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "ERROR");
                return false;
            }
            return true;
        }
        public void SetFileTitle()
        {
            window.Title = "TeheMan 8  Editor - " + PSX.levels[Level.Id].pac.filename;
        }
        async private void ReLoad(bool single = false)
        {
            try
            {
                if (settings.saveOnReload)
                    SaveFiles(true);

                if (settings.useNops) //use NOPS
                {
                    ListWindow.tab = ((TabItem)hub.SelectedItem).Name;
                    loadWindow = new ListWindow(single);
                    loadWindow.ShowDialog();
                }
                else // use REDUX
                {
                    await Redux.Pause();

                    //General Level Data
                    if (PSX.levels[Level.Id].pac.ContainsEntry(0))
                        await Redux.Write(0x8016ef34, PSX.levels[Level.Id].layout);
                    if (PSX.levels[Level.Id].pac.ContainsEntry(1))
                        await Redux.Write(0x8016f334, PSX.levels[Level.Id].layout2);
                    if (PSX.levels[Level.Id].pac.ContainsEntry(2))
                        await Redux.Write(0x8016f734, PSX.levels[Level.Id].layout3);
                    if (PSX.levels[Level.Id].pac.ContainsEntry(3))
                    {
                        await Redux.Write(0x80190040, PSX.levels[Level.Id].screenData);
                        await Redux.Write(0x80171c3c, PSX.levels[Level.Id].screenData);
                    }
                    if (PSX.levels[Level.Id].pac.ContainsEntry(4))
                        await Redux.Write(0x8015ea88, PSX.levels[Level.Id].tileInfo);
                    if (PSX.levels[Level.Id].pac.ContainsEntry(9))
                    {
                        await Redux.Write(0x8015a064, PSX.levels[Level.Id].pal);
                        await Redux.Write(0x80158f64, PSX.levels[Level.Id].pal);
                    }
                    //Enemy Data
                    byte[] enemyData = new byte[0x800];
                    PSX.levels[Level.Id].DumpEnemyData(enemyData);
                    await Redux.Write(0x801c2b3c, enemyData);

                    //Check Point Data
                    await SpawnWindow.WriteCheckPoints();

                    //Textures
                    byte[] data = new byte[0x8000];

                    foreach (var e in PSX.levels[Level.Id].pac.entries)
                    {
                        if (e.type >> 8 != 1)
                            continue;
                        int x = Const.CordTabe[e.type & 0xFF] & 0xFFFF;
                        int y = Const.CordTabe[e.type & 0xFF] >> 16;

                        int height = e.data.Length / 128;
                        int pages = height / 256; //full pages
                        Array.Clear(data, 0, data.Length);

                        for (int i = 0; i < pages; i++)
                        {
                            Array.Copy(e.data, i * 0x8000, data, 0, 0x8000);
                            await Redux.DrawRect(new Int32Rect(x + i * 64, y, 64, 256), data);
                        }
                        if (e.data.Length % 256 != 0)
                        {
                            Array.Clear(data, 0, data.Length);
                            int pageHeight = e.data.Length % 256;
                            Array.Copy(e.data, pages * 0x8000, data, 0, pageHeight * 128);
                            await Redux.DrawRect(new Int32Rect(x + pages * 64, y, 64, pageHeight), data);
                        }
                    }

                    //Done
                    await Redux.Resume();
                }
            }catch(HttpRequestException e)
            {
                MessageBox.Show(e.Message, "REDUX ERROR");
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message, "ERROR");
            }
        }
        private int GetHubIndex()
        {
            System.Collections.Generic.IEnumerable<Dragablz.DragablzItem> tabs = this.hub.GetOrderedHeaders();

            int index = 0;
            foreach (var t in tabs)
            {
                if (((TabItem)t.Content).Name == ((TabItem)this.hub.SelectedItem).Name)
                    return index;
                index++;
            }

            return index;
        }
        private int GetActualIndex(int i /*Visual Index*/) 
        {
            var tabs = this.hub.GetOrderedHeaders().ToList();

            int index = 0;
            foreach (var item in this.hub.Items)
            {
                if (((TabItem)item).Name == ((TabItem)tabs[i].Content).Name)
                    return index;
                index++;
            }
            return -1;
        }
        #endregion Methods

        #region Events
        private async void Window_Loaded(object sender, RoutedEventArgs e)
        {
            //Check for Update
            if (settings.dontUpdate) return;
            using (HttpClient client = new HttpClient())
            {
                client.DefaultRequestHeaders.UserAgent.ParseAdd("Mozilla/5.0 (compatible; Grand/3.0)");
                try
                {
                    HttpResponseMessage response = await client.GetAsync(Const.reproURL);
                    response.EnsureSuccessStatusCode();
                    string json = await response.Content.ReadAsStringAsync();
                    dynamic release = JsonConvert.DeserializeObject(json);
                    string tag = release.tag_name;
                    if (tag != Const.Version && !Settings.IsPastVersion(tag))
                    {
                        var result = MessageBox.Show($"There is a new version of this editor ({tag}) do you want to download the update?", "New Version", MessageBoxButton.YesNo);
                        if (result == MessageBoxResult.Yes)
                        {
                            //Start Downloading
                            string url = release.assets[0].browser_download_url;
                            response = await client.GetAsync(url);
                            response.EnsureSuccessStatusCode();
                            using (Stream contentStream = await response.Content.ReadAsStreamAsync())
                            {
                                using (FileStream fileStream = new FileStream("TeheMan8 Editor " + tag + ".exe", FileMode.Create, FileAccess.Write, FileShare.None))
                                {
                                    await contentStream.CopyToAsync(fileStream);
                                }
                            }
                            System.Diagnostics.Process.Start(Directory.GetCurrentDirectory() + "/" + "TeheMan8 Editor " + tag + ".exe");
                            Application.Current.Shutdown();
                        }
                    }
                }
                catch(HttpRequestException)
                {
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }
        private void Window_MouseDown(object sender, MouseButtonEventArgs e)
        {
            Xceed.Wpf.Toolkit.WatermarkTextBox num = Keyboard.FocusedElement as Xceed.Wpf.Toolkit.WatermarkTextBox;
            if (num != null)
            {
                TraversalRequest tRequest = new TraversalRequest(FocusNavigationDirection.Next);
                num.MoveFocus(tRequest);

                while (true)
                {
                    if (Keyboard.FocusedElement.GetType() != typeof(Xceed.Wpf.Toolkit.WatermarkTextBox))
                        break;
                    ((Xceed.Wpf.Toolkit.WatermarkTextBox)Keyboard.FocusedElement).MoveFocus(tRequest);
                }
            }
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (Dragablz.TabablzControl.GetIsClosingAsPartOfDragOperation(this) && this == window)
            {
                e.Cancel = true;
            }
            else if (this == window)
            {
                foreach (var l in PSX.levels)
                {
                    if (l.edit)
                    {
                        var result = MessageBox.Show("You have edited some of your game files without saving.\nAre you sure you want to exit the editor?", "WARNING", MessageBoxButton.YesNo);
                        if (result != MessageBoxResult.Yes)
                        {
                            e.Cancel = true;
                            return;
                        }
                        else
                        {
                            Application.Current.Shutdown();
                        }
                    }
                }
                if (PSX.edit)
                {
                    var result = MessageBox.Show("You have edited the PSX.EXE without saving.\nAre you sure you want to exit the editor?", "WARNING", MessageBoxButton.YesNo);
                    if (result != MessageBoxResult.Yes)
                    {
                        e.Cancel = true;
                        return;
                    }
                }
                Application.Current.Shutdown();
            }
        }
        private void Window_PreviewKeyDown(object sender, System.Windows.Input.KeyEventArgs e) //HotKeys & Stuff
        {
            var key = e.Key.ToString();
            if (key == "F11")
            {
                if (max)
                {
                    this.WindowStyle = WindowStyle.SingleBorderWindow;
                    this.WindowState = WindowState.Normal;
                    max = false;
                }
                else
                {
                    this.WindowStyle = WindowStyle.None;
                    this.WindowState = WindowState.Maximized;
                    max = true;
                }
                return;
            }
            if (e.KeyboardDevice.Modifiers == System.Windows.Input.ModifierKeys.Control)
            {
                if (key == "O") //Open
                {
                    OpenGame();
                }
                else if (key == "S" && PSX.levels.Count != 0) //Save
                {
                    SaveFiles();
                }
                else if (key == "R" && PSX.levels.Count != 0)
                {
                    ReLoad();
                    return;
                }
                else if(key == "E" && PSX.levels.Count != 0)
                {
                    ReLoad(true);
                    return;
                }
                else if (key == "Left" && PSX.levels.Count != 0 && this.hub.Items.Count > 1)
                {
                    int hubIndex = GetHubIndex();
                    if (hubIndex == 0)
                    {
                        this.hub.SelectedIndex = GetActualIndex(this.hub.Items.Count - 1);
                        return;
                    }
                    this.hub.SelectedIndex = GetActualIndex(hubIndex - 1);
                }
                else if (key == "Right" && PSX.levels.Count != 0 && this.hub.Items.Count > 1)
                {
                    int hubIndex = GetHubIndex();
                    if (hubIndex == this.hub.Items.Count - 1)
                    {
                        this.hub.SelectedIndex = GetActualIndex(0);
                        return;
                    }
                    this.hub.SelectedIndex = GetActualIndex(hubIndex + 1);
                }
                return;
            }
            if (PSX.levels.Count == 0)
                return;
            MainKeyCheck(key);
            if (hub.SelectedItem == null)
                return;
            bool nonNumInt = false;
            if (Keyboard.FocusedElement.GetType() != typeof(Xceed.Wpf.Toolkit.WatermarkTextBox)) nonNumInt = true;
            var tab = (TabItem)hub.SelectedItem;
            switch (tab.Name)
            {
                case "layoutTab":
                    {
                        LayoutKeyCheck(key, nonNumInt);
                        break;
                    }
                case "screenTab":
                    {
                        ScreenKeyCheck(key);
                        break;
                    }
                case "enemyTab":
                    {
                        EnemyKeyCheck(key, nonNumInt);
                        break;
                    }
                case "clutTab":
                    {
                        ClutKeyCheck(key);
                        break;
                    }
                default:
                    {
                        break;
                    }
            }
        }
        private void toolsBtn_Click(object sender, RoutedEventArgs e)
        {
            ToolsWindow tools = new ToolsWindow();
            tools.ShowDialog();
        }

        private void aboutBtn_Click(object sender, RoutedEventArgs e)
        {
            AboutWindow about = new AboutWindow();
            about.ShowDialog();
        }

        private void openBtn_Click(object sender, RoutedEventArgs e)
        {
            OpenGame();
        }
        private void saveAsButn_Click(object sender, RoutedEventArgs e)
        {
            if (PSX.exe == null)
                return;
            using (var fd = new System.Windows.Forms.SaveFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Save " + PSX.levels[Level.Id].pac.filename;
                fd.FileName = PSX.levels[Level.Id].pac.filename; ;
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    foreach (var l in PSX.levels)
                        l.ApplyLevelsToPAC();
                    try
                    {
                        File.WriteAllBytes(fd.FileName, PSX.levels[Level.Id].pac.GetEntriesData());
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message);
                    }
                }
            }
        }
        private void saveBtn_Click(object sender, RoutedEventArgs e)
        {
            SaveFiles();
        }
        private void settingsBtn_Click(object sender, RoutedEventArgs e)
        {
            SettingsWindow s = new SettingsWindow();
            s.ShowDialog();
        }
        private void filesBtn_Click(object sender, RoutedEventArgs e)
        {
            if (PSX.levels.Count == 0 || ListWindow.fileViewOpen)
                return;
            fileWindow = new ListWindow(4);
            fileWindow.Show();
        }
        private void sizeBtn_Click(object sender, RoutedEventArgs e)
        {
            if (PSX.levels.Count == 0)
                return;
            SizeWindow s = new SizeWindow();
            s.ShowDialog();
        }
        private void helpBtn_Click(object sender, RoutedEventArgs e)
        {
            HelpWindow h = new HelpWindow(0);
            h.ShowDialog();
        }
        private void reloadBtn_Click(object sender, RoutedEventArgs e)
        {
            if (PSX.levels.Count != 0)
                ReLoad();
        }
        public void NOPS_OutputDataReceived(object sender, System.Diagnostics.DataReceivedEventArgs e)
        {
            if (loadWindow.mode > 1)
            {
                loadWindow.Dispatcher.Invoke(() =>
                {
                    TextBox t = loadWindow.grid.Children[0] as TextBox;
                    t.Text += "\n" + e.Data;
                    ScrollViewer s = loadWindow.outGrid.Children[0] as ScrollViewer;
                    s.ScrollToEnd();
                });
            }
        }
        #endregion Events
    }
}
