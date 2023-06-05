using Newtonsoft.Json;
using System;
using System.IO;
using System.Windows;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for SettingsWindow.xaml
    /// </summary>
    public partial class SettingsWindow : Window
    {
        #region Properties
        private bool enable = false;
        private bool edited = false;
        #endregion  Properties

        #region Constructors
        public SettingsWindow()
        {
            InitializeComponent();

            //Redux Settings
            webBox.Text = MainWindow.settings.webPort;

            //NOPS Settings
            comBox.Text = MainWindow.settings.comPort;
            useNopsCheck.IsChecked = MainWindow.settings.useNops;

            //Options
            dontUpdateCheck.IsChecked = MainWindow.settings.dontUpdate;
            saveReloadCheck.IsChecked = MainWindow.settings.saveOnReload;
            enable = true;
        }
        #endregion Constructors

        #region Events
        private void webBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.webPort = webBox.Text;
            edited = true;
        }
        private void comBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.comPort = comBox.Text;
            edited = true;
        }
        private void useNopsCheck_Change(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.useNops = (bool)useNopsCheck.IsChecked;
            edited = true;
        }
        private void screenBackupCheck_Change(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.noScreenReload = (bool)screenCheck.IsChecked;
            edited = true;
        }
        private void clutCheck_Change(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.noClutReload = (bool)clutCheck.IsChecked;
            edited = true;
        }
        private void dontUpdateCheck_Change(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.dontUpdate = (bool)dontUpdateCheck.IsChecked;
            edited = true;
        }
        private void saveOnReloadCheck_Change(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.saveOnReload = (bool)saveReloadCheck.IsChecked;
            edited = true;
        }
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (edited)
            {
                try
                {
                    var json = JsonConvert.SerializeObject(MainWindow.settings, Formatting.Indented);
                    File.WriteAllText("Settings.json", json);
                }catch(Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    Application.Current.Shutdown();
                }
            }
        }
        #endregion Events
    }
}
