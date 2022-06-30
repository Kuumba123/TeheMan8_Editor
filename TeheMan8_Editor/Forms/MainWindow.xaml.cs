using Newtonsoft.Json;
using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;
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
        internal static ListWindow layoutWindow;
        internal static ListWindow buildWindow;
        internal static Settings settings = Settings.SetDefaultSettings();
        internal static bool building = false;
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
                ISO.lastSave = null;
                Settings.builder.EnableRaisingEvents = true;
                Settings.builder.OutputDataReceived += Builder_OutputDataReceived;
                Settings.builder.Exited += Builder_Exited;

                //Open Settings
                if (File.Exists("Settings.json"))
                {
                    try
                    {
                        settings = JsonConvert.DeserializeObject<Settings>(File.ReadAllText("Settings.json"));
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

                    if (ISO.levels.Count == 0) //Check for any PAC Level Files
                    {
                        MessageBox.Show("No PAC level files were found.");
                        return;
                    }
                    ISO.exe = File.ReadAllBytes(args[1] + "/SLUS_004.53");
                    ISO.time = File.GetLastWriteTime(args[1] + "/SLUS_004.53");
                    ISO.filePath = args[1];
                    Level.Id = 0;
                    Level.currentScreen = 1;
                    Level.AssignPallete();
                    ISO.levels[Level.Id].LoadTextures();
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

        #region Events
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (Dragablz.TabablzControl.GetIsClosingAsPartOfDragOperation(this) && this == window)
            {
                e.Cancel = true;
            }
            else if (this == window)
            {
                foreach (var l in ISO.levels)
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
                            break;
                        }
                    }
                }
                Application.Current.Shutdown();
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
                else if (key == "S" && ISO.levels.Count != 0) //Save
                {
                    SaveFiles();
                }
                else if (key == "E" && ISO.levels.Count != 0) //Export
                {
                    if(ISO.lastSave == null)
                    {
                        using(var fd = new System.Windows.Forms.SaveFileDialog())
                        {
                            fd.Filter = "ISO |*.bin";
                            fd.Title = "Select MegaMan 8 ISO File";
                            if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                            {
                                ISO.lastSave = fd.FileName;
                            }
                            else
                                return;
                        }
                    }
                    if (settings.saveOnExport)
                    {
                        if (!SaveFiles())
                            return;
                    }

                    //Start Builder
                    building = true;
                    if (settings.buildArgs == "")
                        Settings.builder.StartInfo.Arguments = "\"" + ISO.filePath + "\"" + ' ' + "\"" + ISO.lastSave + "\"";
                    else
                        Settings.builder.StartInfo.Arguments = "\"" + ISO.filePath + "\"" + ' ' + "\"" + ISO.lastSave + "\"" + " \"" + settings.buildArgs + "\"";
                    try
                    {
                        Settings.builder.Start();
                        Settings.builder.BeginOutputReadLine();
                    }catch(System.ComponentModel.Win32Exception)
                    {
                        MessageBox.Show("Cant find TeheMan8_Builder.exe .\nDid you put it in same folder as TeheMan 8 Editor?");
                        ISO.lastSave = null;
                        building = false;
                        return;
                    }
                    if (settings.outputBuild)
                    {
                        buildWindow = new ListWindow();
                        buildWindow.ShowDialog();
                        return;
                    }
                    else
                    {
                        Settings.builder.WaitForExit();
                        if (Settings.error)
                            MessageBox.Show(Settings.message, "BUILD ERROR"); //TODO: maybe let the user know if file exported correctly
                        return;
                    }
                }
                else if (key == "Left" && ISO.levels.Count != 0 && this.hub.Items.Count > 1)
                {
                    if (this.hub.SelectedIndex == 0)
                    {
                        this.hub.SelectedIndex = this.hub.Items.Count - 1;
                        return;
                    }
                    this.hub.SelectedIndex--;
                }
                else if (key == "Right" && ISO.levels.Count != 0 && this.hub.Items.Count > 1)
                {
                    if (this.hub.SelectedIndex == this.hub.Items.Count - 1)
                    {
                        this.hub.SelectedIndex = 0;
                        return;
                    }
                    this.hub.SelectedIndex++;
                }
                return;
            }
            if (ISO.levels.Count == 0)
                return;
            MainKeyCheck(key);
            if (hub.SelectedItem == null)
                return;
            var tab = (TabItem)hub.SelectedItem;
            switch (tab.Name)
            {
                case "layoutTab":
                    {
                        LayoutKeyCheck(key);
                        break;
                    }
                case "enemyTab":
                    {
                        EnemyKeyCheck(key);
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
        private void exportBtn_Click(object sender, RoutedEventArgs e)
        {
            if (ISO.exe == null)
                return;
            using (var fd = new System.Windows.Forms.SaveFileDialog())
            {
                fd.Filter = "ISO |*.bin";
                fd.Title = "Select MegaMan 8 ISO File";
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    if (settings.saveOnExport)
                    {
                        if (!SaveFiles())
                            return;
                    }

                    ISO.lastSave = fd.FileName;

                    //Start Builder
                    building = true;
                    if (settings.buildArgs == "")
                        Settings.builder.StartInfo.Arguments = "\"" + ISO.filePath + "\"" + ' ' + "\"" + fd.FileName + "\"";
                    else
                        Settings.builder.StartInfo.Arguments = "\"" + ISO.filePath + "\"" + ' ' + "\"" + fd.FileName + "\"" + " " + settings.buildArgs;
                    try
                    {
                        Settings.builder.Start();
                        Settings.builder.BeginOutputReadLine();
                    }catch (System.ComponentModel.Win32Exception)
                    {
                        MessageBox.Show("Cant find TeheMan8_Builder.exe .\nDid you put it in same folder as TeheMan 8 Editor?");
                        ISO.lastSave = null;
                        building = false;
                        return;
                    }
                    if (settings.outputBuild)
                    {
                        buildWindow = new ListWindow();
                        buildWindow.ShowDialog();
                        return;
                    }
                    else
                    {
                        Settings.builder.WaitForExit();
                        if (Settings.error)
                            MessageBox.Show(Settings.message, "BUILD ERROR");
                        else
                            MessageBox.Show("Export Completed!");
                    }
                }
            }
        }

        private void saveAsButn_Click(object sender, RoutedEventArgs e)
        {
            if (ISO.exe == null)
                return;
            using (var fd = new System.Windows.Forms.SaveFileDialog())
            {
                fd.Filter = "PAC |*.PAC";
                fd.Title = "Save " + ISO.levels[Level.Id].pac.filename;
                fd.FileName = ISO.levels[Level.Id].pac.filename; ;
                if (fd.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                {
                    Level.ApplyLevelsToPAC();
                    try
                    {
                        File.WriteAllBytes(fd.FileName, ISO.levels[Level.Id].pac.GetEntriesData());
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
        private void Builder_OutputDataReceived(object sender, System.Diagnostics.DataReceivedEventArgs e)
        {
            if (e.Data == null)
                return;
            if (e.Data.Contains("ERROR"))
            {
                Settings.message = e.Data;
                Settings.error = true;
            }
            if (!settings.outputBuild)
                return;
            buildWindow.Dispatcher.Invoke(() =>
            {
                if (PresentationSource.FromVisual(buildWindow) == null)
                {
                    Settings.builder.Kill();
                }
                string line = Environment.NewLine;
                if (((TextBox)buildWindow.grid.Children[0]).Text == "")
                    line = "";
                ((TextBox)buildWindow.grid.Children[0]).AppendText(line + e.Data);
            });
        }
        private void Builder_Exited(object sender, EventArgs e)
        {
            building = false;
            Settings.builder.CancelOutputRead();
        }
        #endregion Events

        #region Methods
        public void Update()
        {
            window.layoutE.DrawLayout();
            window.layoutE.DrawScreen();
            window.screenE.DrawScreen();
            window.screenE.DrawTiles();
            window.screenE.DrawTile();
            window.x16E.DrawTiles();
            window.x16E.DrawTextures();
            window.x16E.DrawTile();
            window.enemyE.ReDraw();
            window.clutE.DrawTextures();
            window.clutE.DrawClut();
            window.clutE.UpdateClutTxt();
            window.spawnE.SetSpawnSettings();
            if (ListWindow.screenViewOpen)
                layoutWindow.DrawScreens();
            UpdateViewrCam();
            UpdateEnemyViewerCam();
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
            fd.Description = "Select Game Folder";
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

                if (ISO.levels.Count == 0) //Check for any PAC Level Files
                {
                    MessageBox.Show("No PAC level files were found.");
                    return;
                }
                ISO.exe = File.ReadAllBytes(fd.SelectedPath + "/SLUS_004.53");
                ISO.time = File.GetLastWriteTime(fd.SelectedPath + "/SLUS_004.53");
                ISO.filePath = fd.SelectedPath;
                Level.Id = 0;
                Level.currentScreen = 1;
                Level.AssignPallete();
                ISO.levels[Level.Id].LoadTextures();
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
                    ISO.levels[Level.Id].LoadTextures();
                    Update();
                }
            }
            else if (key == "F2")
            {
                if (Level.Id != ISO.levels.Count - 1 && ISO.levels.Count != 0)
                {
                    Level.Id++;
                    //RE-Update
                    Level.AssignPallete();
                    ISO.levels[Level.Id].LoadTextures();
                    Update();
                }
            }
        }
        private void LayoutKeyCheck(string key)
        {
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
        private void EnemyKeyCheck(string key)
        {
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
        internal bool SaveFiles()
        {
            if (ISO.exe == null)
                return false;
            Level.ApplyLevelsToPAC();
            foreach (var l in ISO.levels) //Save PAC Files
            {
                try
                {
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
                if (File.Exists(ISO.filePath + "/SLUS_004.53"))
                {
                    if (!ISO.edit && ISO.time == File.GetLastWriteTime(ISO.filePath + "/SLUS_004.53"))
                        return true;
                    File.WriteAllBytes(ISO.filePath + "/SLUS_004.53", ISO.exe);
                    ISO.time = File.GetLastWriteTime(ISO.filePath + "/SLUS_004.53");
                    ISO.edit = false;
                }
                else
                {
                    File.WriteAllBytes(ISO.filePath + "/SLUS_004.53", ISO.exe);
                    ISO.time = File.GetLastWriteTime(ISO.filePath + "/SLUS_004.53");
                    ISO.edit = false;
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
            window.Title = "TeheMan 8  Editor - " + ISO.levels[Level.Id].pac.filename;
        }
        #endregion Methods
    }
}
