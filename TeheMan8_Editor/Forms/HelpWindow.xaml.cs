using System.Windows;

namespace TeheMan8_Editor.Forms
{
    /// <summary>
    /// Interaction logic for HelpWindow.xaml
    /// </summary>
    public partial class HelpWindow : Window
    {
        readonly string[] messages = new string[]
        {
            //0
            "Before you can start level editing you need to extract the game files. " +
            "You can do this by clicking on tools then clicking on the extract ISO 9960 button. " +
            "Make sure you all tracks are in a single file before you use that extractor! " +
            "You can also switch between Stage Files via F1 & F2 " +
            "along with that switch between tabs via CTRL + Left/Right and " +
            "Full-Screen via F11. " +
            "This Editor also supports real time level editing via PCSX Redux or NOPS. " +
            "For Redux make sure you  have the web server enabled. " +
            "If you want to use a real PS1 for the level editing then make sure you have foldering location of NOPS setup in your " +
            "envirment variables. " +
            "After that just click Reload (or CTRL + R) and watch the magic happen!",
            //1
            "This is where you can edit what screens go where (20hex width 20hex height). " +
            "You can move around by using W A S D . " +
            "Right Click = Copy , Left Click = Paste and " +
            "Hold Shift + Right Click = Selecting the Clicked screen in the Screen Tab. " +
            "Hold Shift + Left Click = Manually setting the screen Id. " +
            "Lastly if you press the Delete Key (Num Pad) it will delete the selected screen!",
            //2
            "This is where you can edit what tiles make up a screen , Left Click = Paste , Right Click = Copy . Clicking the flag icon will " +
            "bring up the tile flags window. " +
            "Right Click = Remove Flag , Left Click = Enable Flag." +
            "Clicking the toggle button will switch between editing Trasnperancy (BLUE) or Priority (RED). " +
            "for the 16x16 tab is mostly the same however you can set the texture location by just clicking on it. " +
            "Use your mouse wheel to cycle through the Clut (mouse must be above textures)",
            //3
            "This is where you can set the different Camera Setting for each type of transition. " +
            "You can also edit Left,Right,Top,Bottom Borders of each Camera Setting. " +
            "ID: 10 Type: 4 is for Horizontal Transitions , next ID is for Vertical , " +
            "and ID: 22 Type: 2 is for door transitions. " +
            "The most significant bit is normally a despawn flag (something like that)",
            //4
            "There isn't too much in this tab but I will go over how to setup checkpoints and doors. " +
            "Depending on what you set the upper 4 bits of ID: 4 Type: 4 Vars settings will determine the type of condition you want for hitting the check points. \n" +
            "0 = set checkpoint if megaman X > object X\n" +
            "1 = set checkpoint if megaman X < object X\n" +
            "2 = set checkpoint if megaman Y > object Y (lower Y means Higher on the screen)\n" +
            "3 = set checkpoint if megaman Y < object Y\n" +
            "the lower 4 bits is simply witch checkpoint. " +
            "Now Ill go over Object 10/11 (same type). " +
            "10 is for horizontal transitions 11 vertical. The Var setting is witch horizontal/vertical transition the object uses " +
            "(keep in mind the most significant bit is just the dispawn  flag)" +
            "These translate into the same ones in the Camera tab. " +
            "The Var for doors (ID: 22 Type 2) is pretty much the same just for door settings. "
        };
        public HelpWindow(int msgId)
        {
            InitializeComponent();
            box.Text = messages[msgId];
        }
    }
}
