using System.Windows.Controls;
using System.Windows.Media;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for EnemyLabel.xaml
    /// </summary>
    public partial class EnemyLabel : UserControl
    {
        #region Constructors
        public EnemyLabel()
        {
            InitializeComponent();
        }
        #endregion Constructors

        #region Methods
        public void AssignTypeBorder(byte type)
        {
            switch (type)
            {
                case 2: //Item Objects
                    {
                        this.border.BorderBrush = Brushes.Blue;
                        break;
                    }
                case 3: //Misc Objects
                    {
                        this.border.BorderBrush = Brushes.BlueViolet;
                        break;
                    }
                case 4:
                    {
                        this.border.BorderBrush = Brushes.HotPink;
                        break;
                    }
                default:
                    this.border.BorderBrush = Brushes.Red;
                    break;
            }
        }
        #endregion Methods
    }
}
