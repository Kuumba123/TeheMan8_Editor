﻿using System;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for EnemyEditor.xaml
    /// </summary>
    public partial class EnemyEditor : UserControl
    {
        #region Properties
        WriteableBitmap bmp = new WriteableBitmap(512, 512, 96, 96, PixelFormats.Rgb24, null);
        byte[] pixels = new byte[0x100000];
        public int viewerX = 0x400;
        public int viewerY = 0;
        UIElement obj;
        FrameworkElement control = new FrameworkElement();
        bool down = false;
        Point point;
        #endregion Properties

        #region Constructors
        public EnemyEditor()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void Draw()
        {
            if (viewerX > 0x1E00)
                viewerX = 0x1E00;
            if (viewerY > 0x1E00)
                viewerY = 0x1E00;
            if (Level.BG == 0)
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout[(viewerX >> 8) + ((viewerY >> 8) * 32)], 0, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(viewerX >> 8) + (((viewerY >> 8) + 1) * 32)], 0, 256, 1536, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout[(viewerX >> 8) + 1 + ((viewerY >> 8) * 32)], 256, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout[(viewerX >> 8) + 1 + (((viewerY >> 8) + 1) * 32)], 256, 256, 1536, pixels);
            }else if(Level.BG == 1)
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(viewerX >> 8) + ((viewerY >> 8) * 32)], 0, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(viewerX >> 8) + (((viewerY >> 8) + 1) * 32)], 0, 256, 1536, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(viewerX >> 8) + 1 + ((viewerY >> 8) * 32)], 256, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout2[(viewerX >> 8) + 1 + (((viewerY >> 8) + 1) * 32)], 256, 256, 1536, pixels);
            }
            else
            {
                //X0
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(viewerX >> 8) + ((viewerY >> 8) * 32)], 0, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(viewerX >> 8) + (((viewerY >> 8) + 1) * 32)], 0, 256, 1536, pixels);
                //X1
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(viewerX >> 8) + 1 + ((viewerY >> 8) * 32)], 256, 0, 1536, pixels);
                Level.DrawScreen(ISO.levels[Level.Id].layout3[(viewerX >> 8) + 1 + (((viewerY >> 8) + 1) * 32)], 256, 256, 1536, pixels);
            }
            MainWindow.window.enemyE.bmp.WritePixels(new Int32Rect(0, 0, 512, 512), pixels, 1536, 0);
            MainWindow.window.enemyE.layoutImage.Source = bmp;
        }
        public void ReDraw()
        {
            Draw();
            DrawEnemies();
        }
        public void DrawEnemies()
        {
            DisableSelect();
            if (MainWindow.window.enemyE.canvas.Children.Count != 256)
            {
                while (true)
                {
                    if (MainWindow.window.enemyE.canvas.Children.Count == 256)
                        break;
                    var l = new EnemyLabel();
                    l.PreviewMouseDown += Label_PreviewMouseDown;
                    MainWindow.window.enemyE.canvas.Children.Add(l);
                }
            }
            foreach (var c in MainWindow.window.enemyE.canvas.Children)
            {
                if (c.GetType() != typeof(EnemyLabel))
                    continue;
                EnemyLabel l = (EnemyLabel)c;
                l.Visibility = Visibility.Hidden;
            }
            int offset = 0;
            //Add Each Enemy if ON SCREEN
            foreach (var e in ISO.levels[Level.Id].enemies)
            {
                if (e.x < viewerX || e.x > viewerX + 0x1FF || e.y < viewerY || e.y > viewerY + 0x1FF)
                    continue;
                if (MainWindow.window.enemyE.canvas.Children[offset].GetType() != typeof(EnemyLabel))
                    offset++;

                //New Enemy to Add to Viewer
                var l = new EnemyLabel();
                ((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset]).text.Content = Convert.ToString(e.id, 16).ToUpper();
                ((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset]).AssignTypeBorder(e.type);

                Canvas.SetLeft((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset], e.x - viewerX - Const.EnemyOffset);
                Canvas.SetTop((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset], e.y - viewerY - Const.EnemyOffset);

                ((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset]).Visibility = Visibility.Visible;
                ((EnemyLabel)MainWindow.window.enemyE.canvas.Children[offset]).Tag = e;
                offset++;
            }
        }
        public void DisableSelect()
        {
            control.Tag = null;
            //Disable
            idInt.IsEnabled = false;
            varInt.IsEnabled = false;
            typeInt.IsEnabled = false;
            xInt.IsEnabled = false;
            yInt.IsEnabled = false;
        }
        private void UpdateEnemyCordLabel(int x, int y)
        {
            MainWindow.window.enemyE.xInt.Value = x + viewerX + Const.EnemyOffset;
            MainWindow.window.enemyE.yInt.Value = y + viewerY + Const.EnemyOffset;
        }
        #endregion Methods

        #region Events
        private void Label_PreviewMouseDown(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Left)
            {
                if (!down)
                {
                    //Set Select Enemy
                    control.Tag = sender;
                    idInt.Value = ((Enemy)((EnemyLabel)control.Tag).Tag).id;
                    varInt.Value = ((Enemy)((EnemyLabel)control.Tag).Tag).var;
                    typeInt.Value = ((Enemy)((EnemyLabel)control.Tag).Tag).type;
                    xInt.Minimum = viewerX;
                    xInt.Maximum = viewerX + 0x1FF;
                    yInt.Minimum = viewerY;
                    yInt.Maximum = viewerY + 0x1FF;
                    //Enable
                    idInt.IsEnabled = true;
                    varInt.IsEnabled = true;
                    typeInt.IsEnabled = true;
                    xInt.IsEnabled = true;
                    yInt.IsEnabled = true;
                }
                down = true;
                obj = sender as UIElement;
                point = e.GetPosition(MainWindow.window.enemyE.canvas);
                point.X -= Canvas.GetLeft(obj);
                point.Y -= Canvas.GetTop(obj);
                MainWindow.window.enemyE.canvas.CaptureMouse();
            }
            else
            {
                //...
            }
        }
        private void canvas_PreviewMouseMove(object sender, MouseEventArgs e)
        {
            if (obj == null || !down)
                return;
            var pos = e.GetPosition(sender as IInputElement);
            double x = pos.X - point.X;
            double y = pos.Y - point.Y;

            //Border Checks
            if (x < 0 - Const.EnemyOffset)
                x = 0 - Const.EnemyOffset;
            if (y < 0 - Const.EnemyOffset)
                y = 0 - Const.EnemyOffset;
            if (x > 511 - Const.EnemyOffset)
                x = 511 - Const.EnemyOffset;
            if (y > 511 - Const.EnemyOffset)
                y = 511 - Const.EnemyOffset;

            Canvas.SetLeft(obj, x);
            Canvas.SetTop(obj, y);
            UpdateEnemyCordLabel((int)x, (int)y);
            var en = (Enemy)((EnemyLabel)obj).Tag;
            en.x = (short)((short)((viewerX & 0x1F00) + x) + Const.EnemyOffset);
            en.y = (short)((short)((viewerY & 0x1F00) + y) + Const.EnemyOffset);
            ISO.levels[Level.Id].edit = true;
        }
        private void canvas_PreviewMouseUp(object sender, MouseButtonEventArgs e)
        {
            if (e.ChangedButton == MouseButton.Right)
                return;
            obj = null;
            down = false;        
            canvas.ReleaseMouseCapture();
        }

        private void AddEnemy_Click(object sender, RoutedEventArgs e)
        {
            if(ISO.levels[Level.Id].enemies.Count == 255)
            {
                MessageBox.Show("Can only have up to 255 Enemies in a single Level");
                return;
            }
            //Add Enemy
            ISO.levels[Level.Id].edit = true;
            var en = new Enemy();
            en.x = (short)(viewerX + 0x100);
            en.y = (short)(viewerY + 0x100);
            en.id = 1; //Default is Met
            ISO.levels[Level.Id].enemies.Add(en);
            DrawEnemies();
        }
        private void RemoveEnemy_Click(object sender, RoutedEventArgs e)
        {
            if (control.Tag == null)
                return;
            ISO.levels[Level.Id].enemies.Remove((Enemy)((EnemyLabel)control.Tag).Tag);
            DrawEnemies();
        }
        private void idInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if(control.Tag == null || e.NewValue == null || e.OldValue == null)
                return;
            ((Enemy)((EnemyLabel)control.Tag).Tag).id = (byte)(int)e.NewValue;
            ((EnemyLabel)control.Tag).text.Content = Convert.ToString(((Enemy)((EnemyLabel)control.Tag).Tag).id, 16).ToUpper();
        }

        private void xInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (control.Tag == null || e.NewValue == null || e.OldValue == null)
                return;
            ((Enemy)((EnemyLabel)control.Tag).Tag).x = (short)(int)e.NewValue;
            Canvas.SetLeft((UIElement)control.Tag, ((int)e.NewValue) - viewerX - Const.EnemyOffset);
        }

        private void varInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (control.Tag == null || e.NewValue == null || e.OldValue == null)
                return;
            ((Enemy)((EnemyLabel)control.Tag).Tag).var = (byte)((int)e.NewValue & 0xFF);
        }

        private void yInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (control.Tag == null || e.NewValue == null || e.OldValue == null)
                return;
            ((Enemy)((EnemyLabel)control.Tag).Tag).y = (short)(int)e.NewValue;
            Canvas.SetTop((UIElement)control.Tag, ((int)e.NewValue) - viewerY - Const.EnemyOffset);
        }

        private void typeInt_ValueChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            if (control.Tag == null || e.NewValue == null || e.OldValue == null)
                return;
            ((Enemy)((EnemyLabel)control.Tag).Tag).type = (byte)((int)e.NewValue & 0xFF);
            ((EnemyLabel)control.Tag).AssignTypeBorder(((Enemy)((EnemyLabel)control.Tag).Tag).type);
        }
        #endregion Events
    }
}
