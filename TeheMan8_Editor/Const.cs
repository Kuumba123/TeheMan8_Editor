using System.Collections.Generic;
using System.Windows.Media;

namespace TeheMan8_Editor
{
    static class Const
    {
        public const uint CheckPointPoiners = 0x80138288;
        public static readonly byte[] MaxPoints = new byte[] { 2, 5, 5, 6, 5, 5, 6, 5, 5, 1, 2, 2, 3, 1 };
        public const int EnemyOffset = 8; //For Enemy Labels
        public static readonly List<Color> GreyScale = new List<Color>()
                            {

                                Color.FromRgb(0,0,0),
                                Color.FromRgb(0x11,0x11,0x11),
                                Color.FromRgb(0x22,0x22,0x22),
                                Color.FromRgb(0x33,0x33,0x33),
                                Color.FromRgb(0x44,0x44,0x44),
                                Color.FromRgb(0x55,0x55,0x55),
                                Color.FromRgb(0x66,0x66,0x66),
                                Color.FromRgb(0x77,0x77,0x77),
                                Color.FromRgb(0x88,0x88,0x88),
                                Color.FromRgb(0x99,0x99,0x99),
                                Color.FromRgb(0xAA,0xAA,0xAA),
                                Color.FromRgb(0xBB,0xBB,0xBB),
                                Color.FromRgb(0xCC,0xCC,0xCC),
                                Color.FromRgb(0xDD,0xDD,0xDD),
                                Color.FromRgb(0xEE,0xEE,0xEE),
                                Color.FromRgb(0xFF,0xFF,0xFF)
                            };

	}
}
