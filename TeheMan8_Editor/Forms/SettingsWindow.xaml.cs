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
        private bool editPacExpan = false;
        #endregion  Properties

        #region Constructors
        public SettingsWindow()
        {
            InitializeComponent();
            argsBox.Text = MainWindow.settings.buildArgs;
            outputBuildCheck.IsChecked = MainWindow.settings.outputBuild;
            saveOnExportCheck.IsChecked = MainWindow.settings.saveOnExport;
            enableExpandedPac.IsChecked = MainWindow.settings.enableExpandedPac;
            enable = true;
        }
        #endregion Constructors

        #region Events
        private void argsBox_TextChanged(object sender, System.Windows.Controls.TextChangedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.buildArgs = argsBox.Text;
            edited = true;
        }
        private void outputBuildCheck_Checked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.outputBuild = true;
            edited = true;
        }

        private void outputBuildCheck_Unchecked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.outputBuild = false;
            edited = true;
        }
        private void saveOnExportCheck_Checked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.saveOnExport = true;
            edited = true;
        }

        private void saveOnExportCheck_Unchecked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.saveOnExport = false;
            edited = true;
        }

        private void enableExpandedPac_Checked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.enableExpandedPac = true;
            edited = true;
            editPacExpan = true;
        }

        private void enableExpandedPac_Unchecked(object sender, RoutedEventArgs e)
        {
            if (!enable)
                return;
            MainWindow.settings.enableExpandedPac = false;
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
            if (editPacExpan && ISO.levels.Count != 0)
                MainWindow.window.SaveFiles();
        }
        #endregion Events
    }
}
