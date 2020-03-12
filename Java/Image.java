import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.util.LinkedList;
import java.util.Iterator;
import java.util.ArrayList;

class Pixel {
	public Pixel(int r,int g,int b) {
		this.r=r;
		this.b=b;
		this.g=g;
		A =255;
	}
	public Pixel() {
		this.r=0;
		this.b=0;
		this.g=0;
		this.A=255;
	}
	public int r;
	public int g;
	public int b;
	public int A;
	
	@Override
    public String toString() {
        return "(" + r + ", " + g +  ", "+b+")";
    }
}

class Color_Palette{
	Pixel Color_Serial_Number[];
    Pixel Black;
	Pixel White;
	Pixel Red;
	Pixel Lime;
	Pixel Blue;
	Pixel Yellow;
	Pixel Cyan;
	Pixel Magenta;
	Pixel Silver;
	Pixel Gray;
	Pixel Maroon;
	Pixel Olive;
	Pixel Green;
	Pixel Purple;
	Pixel Teal;
	Pixel Navy;
	Pixel Dark_Red;
	Pixel Brown;
	Pixel Firebrick;
	Pixel Crimson;
	Pixel Tomato;
	Pixel Coral;
	Pixel Indian_Red;
	Pixel Light_Coral;
	Pixel Dark_Salmon;
	Pixel Salmon;
	Pixel Light_Salmon;
	Pixel Orange_Red;
	Pixel Dark_Orange;
	Pixel Orange;
	Pixel Gold;
	Pixel Dark_Golden_Rod;
	Pixel Golden_Rod;
	Pixel Pale_Golden_Rod;
	Pixel Dark_Khaki;
	Pixel Khaki;
	Pixel Yellow_Green;
	Pixel Dark_Olive_Green;
	Pixel Olive_Drab;
	Pixel Lawn_Green;
	Pixel Chart_Reuse;
	Pixel Green_Yellow;
	Pixel Dark_Green;
	Pixel Forest_Green;
	Pixel Lime_Green;
	Pixel Light_Green;
	Pixel Pale_Green;
	Pixel Dark_Sea_Green;
	Pixel Medium_Spring_Green;
	Pixel Spring_Green;
	Pixel Sea_Green;
	Pixel Medium_Aqua_Marine;
	Pixel Medium_Sea_Green;
	Pixel Light_Sea_Green;
	Pixel Dark_Slate_Gray;
	Pixel Dark_Cyan;
	Pixel Light_Cyan;
	Pixel Dark_Turquoise;
	Pixel Turquoise;
	Pixel Medium_Turquoise;
	Pixel Pale_Turquois;
	Pixel Aqua_Marine;
	Pixel Powder_Blue;
	Pixel Cadet_Blue;
	Pixel Steel_Blue;
	Pixel Corn_Flower_Blue;
	Pixel Deep_Sky_Blue;
	Pixel Dodger_Blue;
	Pixel Light_Blue;
	Pixel Sky_Blue;
	Pixel Light_Bky_Blue;
	Pixel Midnight_Blue;
	Pixel Dark_Blue;
	Pixel Medium_Blue;
	Pixel Royal_Blue;
	Pixel Blue_Violet;
	Pixel Indigo;
	Pixel Dark_Slate_Blue;
	Pixel Slate_Blue;
	Pixel Medium_Slate_Blue;
	Pixel Medium_Purple;
	Pixel Dark_Magenta;
	Pixel Dark_Violet;
	Pixel Dark_Orchid;
	Pixel Medium_Orchid;
	Pixel Thistle;
	Pixel Plum;
	Pixel Violet;
	Pixel Orchid;
	Pixel Medium_Violet_Red;
	Pixel Pale_Violet_Red;
	Pixel Deep_Pink;
	Pixel Hot_Pink;
	Pixel Light_Pink;
	Pixel Pink;
	Pixel Antique_White;
	Pixel Beige;
	Pixel Bisque;
	Pixel Blanched_Almond;
	Pixel Wheat;
	Pixel Corn_Silk;
	Pixel Lemon_Chiffon;
	Pixel Light_Golden_Rod_Yellow;
	Pixel Light_Yellow;
	Pixel Saddle_Brown;
	Pixel Sienna;
	Pixel Chocolate;
	Pixel Peru;
	Pixel Sandy_Brown;
	Pixel Burly_Wood;
	Pixel Tan;
	Pixel Rosy_Brown;
	Pixel Moccasin;
	Pixel Navajo_White;
	Pixel Peach_Puff;
	Pixel Misty_Rose;
	Pixel Lavender_Blush;
	Pixel Linen;
	Pixel Old_Lace;
	Pixel Papaya_Whip;
	Pixel Sea_Shell;
	Pixel Mint_Cream;
	Pixel Slate_Gray;
	Pixel Light_Slate_Gray;
	Pixel Light_Steel_Blue;
	Pixel Lavender;
	Pixel Floral_White;
	Pixel Alice_Blue;
	Pixel Ghost_White;
	Pixel Honeydew;
	Pixel Ivory;
	Pixel Azure;
	Pixel Snow;
	Pixel Dim_Gray;
	Pixel Dark_Gray;
	Pixel Light_Gray;
	Pixel Gainsboro;
	Pixel White_Smoke;
	public Color_Palette() {
		
		    Black = new Pixel();
			 White = new Pixel();
			 Red  = new Pixel();
			 Lime = new Pixel();
			 Blue = new Pixel();
			 Yellow = new Pixel();
			 Cyan = new Pixel();
			 Magenta = new Pixel();
			 Silver = new Pixel();
			 Gray = new Pixel();
			 Maroon = new Pixel();
			 Olive = new Pixel();
			 Green = new Pixel();
			 Purple = new Pixel();
			 Teal = new Pixel();
			 Navy = new Pixel();
			 Dark_Red = new Pixel();
			 Brown = new Pixel();
			 Firebrick = new Pixel();
			 Crimson = new Pixel();
			 Tomato = new Pixel();
			 Coral = new Pixel();
			 Indian_Red = new Pixel();
			 Light_Coral = new Pixel();
			 Dark_Salmon = new Pixel();
			 Salmon = new Pixel();
			 Light_Salmon = new Pixel();
			 Orange_Red = new Pixel();
			 Dark_Orange = new Pixel();
			 Orange = new Pixel();
			 Gold = new Pixel();
			 Dark_Golden_Rod = new Pixel();
			 Golden_Rod = new Pixel();
			 Pale_Golden_Rod = new Pixel();
			 Dark_Khaki = new Pixel();
			 Khaki = new Pixel();
			 Yellow_Green = new Pixel();
			 Dark_Olive_Green = new Pixel();
			 Olive_Drab = new Pixel();
			 Lawn_Green = new Pixel();
			 Chart_Reuse = new Pixel();
			 Green_Yellow = new Pixel();
			 Dark_Green = new Pixel();
			 Forest_Green = new Pixel();
			 Lime_Green = new Pixel();
			 Light_Green = new Pixel();
			 Pale_Green = new Pixel();
			 Dark_Sea_Green = new Pixel();
			 Medium_Spring_Green = new Pixel();
			 Spring_Green = new Pixel();
			 Sea_Green = new Pixel();
			 Medium_Aqua_Marine = new Pixel();
			 Medium_Sea_Green = new Pixel();
			 Light_Sea_Green = new Pixel();
			 Dark_Slate_Gray = new Pixel();
			 Dark_Cyan = new Pixel();
			 Light_Cyan = new Pixel();
			 Dark_Turquoise = new Pixel();
			 Turquoise = new Pixel();
			 Medium_Turquoise = new Pixel();
			 Pale_Turquois = new Pixel();
			 Aqua_Marine = new Pixel();
			 Powder_Blue = new Pixel();
			 Cadet_Blue = new Pixel();
			 Steel_Blue = new Pixel();
			 Corn_Flower_Blue = new Pixel();
			 Deep_Sky_Blue = new Pixel();
			 Dodger_Blue = new Pixel();
			 Light_Blue = new Pixel();
			 Sky_Blue = new Pixel();
			 Light_Bky_Blue = new Pixel();
			 Midnight_Blue = new Pixel();
			 Dark_Blue = new Pixel();
			 Medium_Blue = new Pixel();
			 Royal_Blue = new Pixel();
			 Blue_Violet = new Pixel();
			 Indigo = new Pixel();
			 Dark_Slate_Blue = new Pixel();
			 Slate_Blue = new Pixel();
			 Medium_Slate_Blue = new Pixel();
			 Medium_Purple = new Pixel();
			 Dark_Magenta = new Pixel();
			 Dark_Violet = new Pixel();
			 Dark_Orchid = new Pixel();
			 Medium_Orchid = new Pixel();
			 Thistle = new Pixel();
			 Plum = new Pixel();
			 Violet = new Pixel();
			 Orchid = new Pixel();
			 Medium_Violet_Red = new Pixel();
			 Pale_Violet_Red = new Pixel();
			 Deep_Pink = new Pixel();
			 Hot_Pink = new Pixel();
			 Light_Pink = new Pixel();
			 Pink = new Pixel();
			 Antique_White = new Pixel();
			 Beige = new Pixel();
			 Bisque = new Pixel();
			 Blanched_Almond = new Pixel();
			 Wheat = new Pixel();
			 Corn_Silk = new Pixel();
			 Lemon_Chiffon = new Pixel();
			 Light_Golden_Rod_Yellow = new Pixel();
			 Light_Yellow = new Pixel();
			 Saddle_Brown = new Pixel();
			 Sienna = new Pixel();
			 Chocolate = new Pixel();
			 Peru = new Pixel();
			 Sandy_Brown = new Pixel();
			 Burly_Wood = new Pixel();
			 Tan = new Pixel();
			 Rosy_Brown = new Pixel();
			 Moccasin = new Pixel();
			 Navajo_White = new Pixel();
			 Peach_Puff = new Pixel();
			 Misty_Rose = new Pixel();
			 Lavender_Blush = new Pixel();
			 Linen = new Pixel();
			 Old_Lace = new Pixel();
			 Papaya_Whip = new Pixel();
			 Sea_Shell = new Pixel();
			 Mint_Cream = new Pixel();
			 Slate_Gray = new Pixel();
			 Light_Slate_Gray = new Pixel();
			 Light_Steel_Blue = new Pixel();
			 Lavender = new Pixel();
			 Floral_White = new Pixel();
			 Alice_Blue = new Pixel();
			 Ghost_White = new Pixel();
			 Honeydew = new Pixel();
			 Ivory = new Pixel();
			 Azure = new Pixel();
			 Snow = new Pixel();
			 Dim_Gray = new Pixel();
			 Dark_Gray = new Pixel();
			 Light_Gray = new Pixel();
			 Gainsboro = new Pixel();
			 White_Smoke = new Pixel();
		
		
		
		
		
		this.Black.r = 0;
		this.Black.g = 0;
		this.Black.b = 0;

		this.White.r=255;
		this.White.g=255;
		this.White.b=255;

		this.Red.r=255;
		this.Red.g=0;
		this.Red.b=0;

		this.Lime.r=0;
		this.Lime.g=255;
		this.Lime.b=0;

		this.Blue.r=0;
		this.Blue.g=0;
		this.Blue.b=255;

		this.Yellow.r=255;
		this.Yellow.g=255;
		this.Yellow.b=0;

		this.Cyan.r=0;
		this.Cyan.g=255;
		this.Cyan.b=255;
		
		this.Magenta.r=255;
		this.Magenta.g=0;
		this.Magenta.b=255;

		this.Silver.r=192;
		this.Silver.g=192;
		this.Silver.b=192;

		this.Gray.r=128;
		this.Gray.g=128;
		this.Gray.b=128;

		this.Maroon.r=128;
		this.Maroon.g=0;
		this.Maroon.b=0;

		this.Green.r=0;
		this.Green.g=128;
		this.Green.b=0;

		this.Purple.r=128;
		this.Purple.g=0;
		this.Purple.b=128;

		this.Teal.r=0;
		this.Teal.g=128;
		this.Teal.b=128;

		this.Navy.r=0;
		this.Navy.g=0;
		this.Navy.b=128;

		this.Dark_Red.r=139;
		this.Dark_Red.g=0;
		this.Dark_Red.b=0;

		this.Brown.r=165;
		this.Brown.g=42;
		this.Brown.b=42;

		this.Firebrick.r=178;
		this.Firebrick.g=34;
		this.Firebrick.b=34;

		this.Crimson.r=220;
		this.Crimson.g=20;
		this.Crimson.b=60;

		this.Tomato.r=255;
		this.Tomato.g=99;
		this.Tomato.b=71;

		this.Coral.r=255;
		this.Coral.g=127;
		this.Coral.b=80;

		this.Indian_Red.r=205;
		this.Indian_Red.g=92;
		this.Indian_Red.b=92;

		this.Light_Coral.r=240;
		this.Light_Coral.g=128;
		this.Light_Coral.b=128;

		this.Dark_Salmon.r=233;
		this.Dark_Salmon.g=150;
		this.Dark_Salmon.b=122;

		this.Salmon.r=250;
		this.Salmon.g=128;
		this.Salmon.b=114;

		this.Light_Salmon.r=255;
		this.Light_Salmon.g=160;
		this.Light_Salmon.b=122;

		this.Orange_Red.r=255;
		this.Orange_Red.g=69;
		this.Orange_Red.b=0;

		this.Dark_Orange.r=255;
		this.Dark_Orange.g=140;
		this.Dark_Orange.b=0;

		this.Orange.r=255;
		this.Orange.g=165;
		this.Orange.b=0;

		this.Gold.r=255;
		this.Gold.g=215;
		this.Gold.b=0;

		this.Dark_Golden_Rod.r=184;
		this.Dark_Golden_Rod.g=134;
		this.Dark_Golden_Rod.b=11;

		this.Golden_Rod.r=218;
		this.Golden_Rod.g=165;
		this.Golden_Rod.b=32;

		this.Pale_Golden_Rod.r=238;
		this.Pale_Golden_Rod.g=232;
		this.Pale_Golden_Rod.b=170;

		this.Dark_Khaki.r=189;
		this.Dark_Khaki.g=183;
		this.Dark_Khaki.b=107;

		this.Khaki.r=240;
		this.Khaki.g=230;
		this.Khaki.b=140;

		this.Olive.r=128;
		this.Olive.g=128;
		this.Olive.b=0;

		this.Yellow_Green.r=154;
		this.Yellow_Green.g=205;
		this.Yellow_Green.b=50;

		this.Dark_Olive_Green.r=85;
		this.Dark_Olive_Green.g=107;
		this.Dark_Olive_Green.b=47;

		this.Olive_Drab.r=107;
		this.Olive_Drab.g=142;
		this.Olive_Drab.b=35;

		this.Lawn_Green.r=142;
		this.Lawn_Green.g=252;
		this.Lawn_Green.b=0;

		this.Chart_Reuse.r=127;
		this.Chart_Reuse.g=255;
		this.Chart_Reuse.b=0;

		this.Green_Yellow.r=173;
		this.Green_Yellow.g=255;
		this.Green_Yellow.b=47;

		this.Dark_Green.r=0;
		this.Dark_Green.g=100;
		this.Dark_Green.b=0;

		this.Forest_Green.r=34;
		this.Forest_Green.g=139;
		this.Forest_Green.b=34;

		this.Lime_Green.r=50;
		this.Lime_Green.g=205;
		this.Lime_Green.b=50;

		this.Light_Green.r=144;
		this.Light_Green.g=238;
		this.Light_Green.b=144;

		this.Pale_Green.r=152;
		this.Pale_Green.g=251;
		this.Pale_Green.b=152;

		this.Dark_Sea_Green.r=143;
		this.Dark_Sea_Green.g=188;
		this.Dark_Sea_Green.b=143;

		this.Medium_Spring_Green.r=0;
		this.Medium_Spring_Green.g=250;
		this.Medium_Spring_Green.b=154;

		this.Spring_Green.r=0;
		this.Spring_Green.g=255;
		this.Spring_Green.b=127;

		this.Sea_Green.r=46;
		this.Sea_Green.g=139;
		this.Sea_Green.b=87;

		this.Medium_Aqua_Marine.r=102;
		this.Medium_Aqua_Marine.g=205;
		this.Medium_Aqua_Marine.b=170;

		this.Medium_Sea_Green.r=60;
		this.Medium_Sea_Green.g=179;
		this.Medium_Sea_Green.b=113;

		this.Light_Sea_Green.r=32;
		this.Light_Sea_Green.g=178;
		this.Light_Sea_Green.b=170;

		this.Dark_Slate_Gray.r=47;
		this.Dark_Slate_Gray.g=79;
		this.Dark_Slate_Gray.b=79;

		this.Dark_Cyan.r=0;
		this.Dark_Cyan.g=139;
		this.Dark_Cyan.b=139;

		this.Light_Cyan.r=224;
		this.Light_Cyan.g=255;
		this.Light_Cyan.b=255;

		this.Dark_Turquoise.r=0;
		this.Dark_Turquoise.g=206;
		this.Dark_Turquoise.b=209;

		this.Turquoise.r=64;
		this.Turquoise.g=224;
		this.Turquoise.b=208;

		this.Medium_Turquoise.r=72;
		this.Medium_Turquoise.g=209;
		this.Medium_Turquoise.b=204;

		this.Pale_Turquois.r=175;
		this.Pale_Turquois.g=238;
		this.Pale_Turquois.b=238;

		this.Aqua_Marine.r=127;
		this.Aqua_Marine.g=255;
		this.Aqua_Marine.b=212;

		this.Powder_Blue.r=176;
		this.Powder_Blue.g=224;
		this.Powder_Blue.b=230;

		this.Cadet_Blue.r=95;
		this.Cadet_Blue.g=158;
		this.Cadet_Blue.b=160;

		this.Steel_Blue.r=70;
		this.Steel_Blue.g=130;
		this.Steel_Blue.b=180;

		this.Corn_Flower_Blue.r=100;
		this.Corn_Flower_Blue.g=149;
		this.Corn_Flower_Blue.b=237;

		this.Deep_Sky_Blue.r=0;
		this.Deep_Sky_Blue.g=191;
		this.Deep_Sky_Blue.b=255;

		this.Dodger_Blue.r=30;
		this.Dodger_Blue.g=144;
		this.Dodger_Blue.b=255;

		this.Light_Blue.r=173;
		this.Light_Blue.g=216;
		this.Light_Blue.b=230;

		this.Sky_Blue.r=135;
		this.Sky_Blue.g=206;
		this.Sky_Blue.b=235;

		this.Light_Bky_Blue.r=135;
		this.Light_Bky_Blue.g=206;
		this.Light_Bky_Blue.b=250;

		this.Midnight_Blue.r=25;
		this.Midnight_Blue.g=25;
		this.Midnight_Blue.b = 112;

		this.Dark_Blue.r=0;
		this.Dark_Blue.g=0;
		this.Dark_Blue.b=139;

		this.Medium_Blue.r=0;
		this.Medium_Blue.g=0;
		this.Medium_Blue.b=205;

		this.Royal_Blue.r=65;
		this.Royal_Blue.g=105;
		this.Royal_Blue.b=225;

		this.Blue_Violet.r=138;
		this.Blue_Violet.g=43;
		this.Blue_Violet.b=226;

		this.Indigo.r=75;
		this.Indigo.g=0;
		this.Indigo.b=130;

		this.Dark_Slate_Blue.r=72;
		this.Dark_Slate_Blue.g=61;
		this.Dark_Slate_Blue.b=139;

		this.Slate_Blue.r=106;
		this.Slate_Blue.g=90;
		this.Slate_Blue.b=205;

		this.Medium_Slate_Blue.r=123;
		this.Medium_Slate_Blue.g=104;
		this.Medium_Slate_Blue.b=238;

		this.Medium_Purple.r=147;
		this.Medium_Purple.g=112;
		this.Medium_Purple.b=219;

		this.Dark_Magenta.r=139;
		this.Dark_Magenta.g=0;
		this.Dark_Magenta.b=139;

		this.Dark_Violet.r=148;
		this.Dark_Violet.g=0;
		this.Dark_Violet.b=211;

		this.Dark_Orchid.r=153;
		this.Dark_Orchid.g=50;
		this.Dark_Orchid.b=204;

		this.Medium_Orchid.r=186;
		this.Medium_Orchid.g=85;
		this.Medium_Orchid.b=211;

		this.Thistle.r=216;
		this.Thistle.g=191;
		this.Thistle.b=216;

		this.Plum.r=221;
		this.Plum.g=160;
		this.Plum.b=221;

		this.Violet.r=238;
		this.Violet.g=130;
		this.Violet.b=238;

		this.Orchid.r=218;
		this.Orchid.g=112;
		this.Orchid.b=214;

		this.Medium_Violet_Red.r=199;
		this.Medium_Violet_Red.g=21;
		this.Medium_Violet_Red.b=133;

		this.Pale_Violet_Red.r=219;
		this.Pale_Violet_Red.g=112;
		this.Pale_Violet_Red.b=147;

		this.Deep_Pink.r=255;
		this.Deep_Pink.g=20;
		this.Deep_Pink.b=147;

		this.Hot_Pink.r=255;
		this.Hot_Pink.g=105;
		this.Hot_Pink.b=180;

		this.Light_Pink.r=255;
		this.Light_Pink.g=182;
		this.Light_Pink.b=193;

		this.Pink.r=255;
		this.Pink.g=192;
		this.Pink.b=203;

		this.Antique_White.r=250;
		this.Antique_White.g=235;
		this.Antique_White.b=215;

		this.Beige.r=245;
		this.Beige.g=245;
		this.Beige.b=220;

		this.Bisque.r=255;
		this.Bisque.g=228;
		this.Bisque.b=196;

		this.Blanched_Almond.r=255;
		this.Blanched_Almond.g=235;
		this.Blanched_Almond.b=205;

		this.Wheat.r=245;
		this.Wheat.g=222;
		this.Wheat.b=179;

		this.Corn_Silk.r=255;
		this.Corn_Silk.g=248;
		this.Corn_Silk.b=220;

		this.Lemon_Chiffon.r=255;
		this.Lemon_Chiffon.g=250;
		this.Lemon_Chiffon.b=205;

		this.Light_Golden_Rod_Yellow.r=250;
		this.Light_Golden_Rod_Yellow.g=250;
		this.Light_Golden_Rod_Yellow.b=210;

		this.Light_Yellow.r=255;
		this.Light_Yellow.g=255;
		this.Light_Yellow.b=224;

		this.Saddle_Brown.r=139;
		this.Saddle_Brown.g=69;
		this.Saddle_Brown.b=19;

		this.Sienna.r=160;
		this.Sienna.g=82;
		this.Sienna.b=45;

		this.Chocolate.r=210;
		this.Chocolate.g=105;
		this.Chocolate.b=30;

		this.Peru.r=205;
		this.Peru.g=133;
		this.Peru.b=63;

		this.Sandy_Brown.r=244;
		this.Sandy_Brown.g=164;
		this.Sandy_Brown.b=96;

		this.Burly_Wood.r=222;
		this.Burly_Wood.g=184;
		this.Burly_Wood.b=135;

		this.Tan.r=210;
		this.Tan.g=180;
		this.Tan.b=140;

		this.Rosy_Brown.r=188;
		this.Rosy_Brown.g=143;
		this.Rosy_Brown.b=143;

		this.Moccasin.r=255;
		this.Moccasin.g=228;
		this.Moccasin.b=181;

		this.Navajo_White.r=255;
		this.Navajo_White.g=222;
		this.Navajo_White.b=173;

		this.Peach_Puff.r=255;
		this.Peach_Puff.g=218;
		this.Peach_Puff.b=185;

		this.Misty_Rose.r=255;
		this.Misty_Rose.g=228;
		this.Misty_Rose.b=225;

		this.Lavender_Blush.r=255;
		this.Lavender_Blush.g=240;
		this.Lavender_Blush.b=245;

		this.Linen.r=250;
		this.Linen.g=240;
		this.Linen.b=230;


		this.Old_Lace.r=253;
		this.Old_Lace.g=245;
		this.Old_Lace.b=230;

		this.Papaya_Whip.r=255;
		this.Papaya_Whip.g=239;
		this.Papaya_Whip.b=213;

		this.Sea_Shell.r=255;
		this.Sea_Shell.g=245;
		this.Sea_Shell.b=255;

		this.Mint_Cream.r=245;
		this.Mint_Cream.g=255;
		this.Mint_Cream.b=250;

		this.Slate_Gray.r=112;
		this.Slate_Gray.g=128;
		this.Slate_Gray.b=144;

		this.Light_Slate_Gray.r=119;
		this.Light_Slate_Gray.g=136;
		this.Light_Slate_Gray.b=153;

		this.Light_Steel_Blue.r=176;
		this.Light_Steel_Blue.g=196;
		this.Light_Steel_Blue.b=222;

		this.Lavender.r=230;
		this.Lavender.g=230;
		this.Lavender.b=250;

		this.Floral_White.r=255;
		this.Floral_White.g=250;
		this.Floral_White.b=240;

		this.Alice_Blue.r=240;
		this.Alice_Blue.g=248;
		this.Alice_Blue.b=255;

		this.Ghost_White.r=240;
		this.Ghost_White.g=248;
		this.Ghost_White.b=255;

		this.Honeydew.r=240;
		this.Honeydew.g=255;
		this.Honeydew.b=240;

		this.Ivory.r=255;
		this.Ivory.b=255;
		this.Ivory.g=240;

		this.Azure.r=240;
		this.Azure.g=255;
		this.Azure.b=255;

		this.Snow.r=255;
		this.Snow.g=250;
		this.Snow.b=250;

		this.Dim_Gray.r=105;
		this.Dim_Gray.g=105;
		this.Dim_Gray.b=105;

		this.Gray.r=128;
		this.Gray.g=128;
		this.Gray.b=128;

		this.Dark_Gray.r=169;
		this.Dark_Gray.g=169;
		this.Dark_Gray.b=169;

		this.Light_Gray.r=211;
		this.Light_Gray.g=211;
		this.Light_Gray.b=211;

		this.Gainsboro.r=220;
		this.Gainsboro.g=220;
		this.Gainsboro.b=220;

		this.White_Smoke.r=245;
		this.White_Smoke.g=245;
		this.White_Smoke.b=245;
		

		this.Color_Serial_Number = new Pixel[138];
		this.Color_Serial_Number[0] = Black;
		this.Color_Serial_Number[1] = White;
		this.Color_Serial_Number[2] = Red;
		this.Color_Serial_Number[3] = Lime;
		this.Color_Serial_Number[4] = Blue;
		this.Color_Serial_Number[5] = Yellow;
		this.Color_Serial_Number[6] = Cyan;
		this.Color_Serial_Number[7] = Magenta;
		this.Color_Serial_Number[8] = Silver;
		this.Color_Serial_Number[9] = Gray;
		this.Color_Serial_Number[10] = Maroon;
		this.Color_Serial_Number[11] = Olive;
		this.Color_Serial_Number[12] = Green;
		this.Color_Serial_Number[13] = Purple;
		this.Color_Serial_Number[14] = Teal;
		this.Color_Serial_Number[15] = Navy;
		this.Color_Serial_Number[16] = Dark_Red;
		this.Color_Serial_Number[17] = Brown;
		this.Color_Serial_Number[18] = Firebrick;
		this.Color_Serial_Number[19] = Crimson;
		this.Color_Serial_Number[20] = Tomato;
		this.Color_Serial_Number[21] = Coral;
		this.Color_Serial_Number[22] = Indian_Red;
		this.Color_Serial_Number[23] = Light_Coral;
		this.Color_Serial_Number[24] = Dark_Salmon;
		this.Color_Serial_Number[25] = Salmon;
		this.Color_Serial_Number[26] = Light_Salmon;
		this.Color_Serial_Number[27] = Orange_Red;
		this.Color_Serial_Number[28] = Dark_Orange;
		this.Color_Serial_Number[29] = Orange;
		this.Color_Serial_Number[30] = Gold;
		this.Color_Serial_Number[31] = Dark_Golden_Rod;
		this.Color_Serial_Number[32] = Golden_Rod;
		this.Color_Serial_Number[33] = Pale_Golden_Rod;
		this.Color_Serial_Number[34] = Dark_Khaki;
		this.Color_Serial_Number[35] = Khaki;
		this.Color_Serial_Number[36] = Yellow_Green;
		this.Color_Serial_Number[37] = Dark_Olive_Green;
		this.Color_Serial_Number[38] = Olive_Drab;
		this.Color_Serial_Number[39] = Lawn_Green;
		this.Color_Serial_Number[40] = Chart_Reuse;
		this.Color_Serial_Number[41] = Green_Yellow;
		this.Color_Serial_Number[42] = Dark_Green;
		this.Color_Serial_Number[43] = Forest_Green;
		this.Color_Serial_Number[44] = Lime_Green;
		this.Color_Serial_Number[45] = Light_Green;
		this.Color_Serial_Number[46] = Pale_Green;
		this.Color_Serial_Number[47] = Dark_Sea_Green;
		this.Color_Serial_Number[48] = Medium_Spring_Green;
		this.Color_Serial_Number[49] = Spring_Green;
		this.Color_Serial_Number[50] = Sea_Green;
		this.Color_Serial_Number[51] = Medium_Aqua_Marine;
		this.Color_Serial_Number[52] = Medium_Sea_Green;
		this.Color_Serial_Number[53] = Light_Sea_Green;
		this.Color_Serial_Number[54] = Dark_Slate_Gray;
		this.Color_Serial_Number[55] = Dark_Cyan;
		this.Color_Serial_Number[56] = Light_Cyan;
		this.Color_Serial_Number[57] = Dark_Turquoise;
		this.Color_Serial_Number[58] = Turquoise;
		this.Color_Serial_Number[59] = Medium_Turquoise;
		this.Color_Serial_Number[60] = Pale_Turquois;
		this.Color_Serial_Number[61] = Aqua_Marine;
		this.Color_Serial_Number[62] = Powder_Blue;
		this.Color_Serial_Number[63] = Cadet_Blue;
		this.Color_Serial_Number[64] = Steel_Blue;
		this.Color_Serial_Number[65] = Corn_Flower_Blue;
		this.Color_Serial_Number[66] = Deep_Sky_Blue;
		this.Color_Serial_Number[67] = Dodger_Blue;
		this.Color_Serial_Number[68] = Light_Blue;
		this.Color_Serial_Number[69] = Sky_Blue;
		this.Color_Serial_Number[70] = Light_Bky_Blue;
		this.Color_Serial_Number[71] = Midnight_Blue;
		this.Color_Serial_Number[72] = Dark_Blue;
		this.Color_Serial_Number[73] = Medium_Blue;
		this.Color_Serial_Number[74] = Royal_Blue;
		this.Color_Serial_Number[75] = Blue_Violet;
		this.Color_Serial_Number[76] = Indigo;
		this.Color_Serial_Number[77] = Dark_Slate_Blue;
		this.Color_Serial_Number[78] = Slate_Blue;
		this.Color_Serial_Number[79] = Medium_Slate_Blue;
		this.Color_Serial_Number[80] = Medium_Purple;
		this.Color_Serial_Number[81] = Dark_Magenta;
		this.Color_Serial_Number[82] = Dark_Violet;
		this.Color_Serial_Number[83] = Dark_Orchid;
		this.Color_Serial_Number[84] = Medium_Orchid;
		this.Color_Serial_Number[85] = Thistle;
		this.Color_Serial_Number[86] = Plum;
		this.Color_Serial_Number[87] = Violet;
		this.Color_Serial_Number[88] = Orchid;
		this.Color_Serial_Number[89] = Medium_Violet_Red;
		this.Color_Serial_Number[90] = Pale_Violet_Red;
		this.Color_Serial_Number[91] = Deep_Pink;
		this.Color_Serial_Number[92] = Hot_Pink;
		this.Color_Serial_Number[93] = Light_Pink;
		this.Color_Serial_Number[94] = Pink;
		this.Color_Serial_Number[95] = Antique_White;
		this.Color_Serial_Number[96] = Beige;
		this.Color_Serial_Number[97] = Bisque;
		this.Color_Serial_Number[98] = Blanched_Almond;
		this.Color_Serial_Number[99] = Wheat;
		this.Color_Serial_Number[100] = Corn_Silk;
		this.Color_Serial_Number[101] = Lemon_Chiffon;
		this.Color_Serial_Number[102] = Light_Golden_Rod_Yellow;
		this.Color_Serial_Number[103] = Light_Yellow;
		this.Color_Serial_Number[104] = Saddle_Brown;
		this.Color_Serial_Number[105] = Sienna;
		this.Color_Serial_Number[106] = Chocolate;
		this.Color_Serial_Number[107] = Peru;
		this.Color_Serial_Number[108] = Sandy_Brown;
		this.Color_Serial_Number[109] = Burly_Wood;
		this.Color_Serial_Number[110] = Tan;
		this.Color_Serial_Number[111] = Rosy_Brown;
		this.Color_Serial_Number[112] = Moccasin;
		this.Color_Serial_Number[113] = Navajo_White;
		this.Color_Serial_Number[114] = Peach_Puff;
		this.Color_Serial_Number[115] = Misty_Rose;
		this.Color_Serial_Number[116] = Lavender_Blush;
		this.Color_Serial_Number[117] = Linen;
		this.Color_Serial_Number[118] = Old_Lace;
		this.Color_Serial_Number[119] = Papaya_Whip;
		this.Color_Serial_Number[120] = Sea_Shell;
		this.Color_Serial_Number[121] = Mint_Cream;
		this.Color_Serial_Number[122] = Slate_Gray;
		this.Color_Serial_Number[123] = Light_Slate_Gray;
		this.Color_Serial_Number[124] = Light_Steel_Blue;
		this.Color_Serial_Number[125] = Lavender;
		this.Color_Serial_Number[126] = Floral_White;
		this.Color_Serial_Number[127] = Alice_Blue;
		this.Color_Serial_Number[128] = Ghost_White;
		this.Color_Serial_Number[129] = Honeydew;
		this.Color_Serial_Number[130] = Ivory;
		this.Color_Serial_Number[131] = Azure;
		this.Color_Serial_Number[132] = Snow;
		this.Color_Serial_Number[133] = Dim_Gray;
		this.Color_Serial_Number[134] = Dark_Gray;
		this.Color_Serial_Number[135] = Light_Gray;
		this.Color_Serial_Number[136] = Gainsboro;
		this.Color_Serial_Number[137] = White_Smoke;
	}
	}





class Blob{
	
	public int Upleft_X, Upleft_Y;
	public int Downright_X, Downright_Y;
	public int Distnace_Treshold;

	private double Cordinate_Distance(int x0, int y0, int x1, int y1) {
		double Distance = (double)((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
		return Distance;
	}
	
	public Blob(int x, int y, int Distnace_Treshold) {
		this.Downright_X = x;
		this.Downright_Y = y;
		this.Upleft_X = x;
		this.Upleft_Y = y;
		this.Distnace_Treshold = Distnace_Treshold;
	}

	public boolean Near(int x, int y) {
		double CentetX, CenterY, Dist;
		CentetX = Math.max(Math.min(x, Upleft_X), Downright_X);
		CenterY = Math.max(Math.min(y, Upleft_Y), Downright_Y);
		Dist = (double)(Cordinate_Distance((int)CentetX, (int)CenterY, (int)(x), (int)(y)));

		if (Dist < this.Distnace_Treshold*Distnace_Treshold) {
			return true;
		}
		else {

			return false;
		}
	}
	
	public void add(int px, int py) {
		this.Downright_X = (int)Math.min(Downright_X, px);
		this.Downright_Y = (int)Math.min(Downright_Y, py);

		this.Upleft_X = (int)Math.max(Upleft_X, px);
		this.Upleft_Y = (int)Math.max(Upleft_Y, py);
	}
	
	public void Clear() {
		this.Downright_X = this.Downright_Y = this.Upleft_X = this.Upleft_Y = -1;
	}
	
	public void SetProps(int x, int y) {
		this.Downright_X = x;
		this.Downright_Y = y;
		this.Upleft_X = x;
		this.Upleft_Y = y;
	}
	
	public double Size() {
		return (double)Math.abs(this.Upleft_X - Downright_X)*(Upleft_Y - Downright_Y);
	}

}



public class Image {
	
	
	
	
	
	
	
	private BufferedImage IMG;
	public Pixel Pixel_Matrix[][];
	public int Image_Width,Image_Height;
	//public boolean hasAlphaChannel;
	
	//functionality

	private void Image_Load_Wrapper() {
		  this.Image_Width = IMG.getWidth();
		  this.Image_Height = IMG.getHeight();
		  this.init_pixel_matrix();

	  }
    public void Set_Color(int i,int j,int r,int g, int b) {
	  int p_value =0;
	  p_value = (255<<24) | (r<<16) | (g<<8) | b;
		  this.IMG.setRGB(j, i, p_value);
	  }
	public void Set_Color(Pixel target,int r,int g,int b) {
		target.r=r;
		target.g=g;
		target.b=b;
	}
    public void Load_Image(String FilePath) throws IOException {
		try {
		this.IMG = ImageIO.read(Image.class.getResource(FilePath));
		this.Image_Load_Wrapper();
		}catch(IOException e) {
			System.out.println("Error");
		}
		
		
	
	}

	public void Write_Image() {
		try{
		      File f = new File("Output.jpg");
		      ImageIO.write(IMG, "jpg", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

	}
	public void Write_Image(String Filename) {
		try{
				for(int i=0;i<this.Image_Height;i++) {
					for(int j=0;j<this.Image_Width;j++) {
						this.Set_Color(i, j, this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b);
					}
				}
		      File f = new File(Filename);
		      ImageIO.write(IMG, "jpg", f);
		    }catch(IOException e){
		      System.out.println(e);
		    }

	}
	public Pixel Get_Pixel(int i,int j) {
		Pixel temp = new Pixel();
		int holder =IMG.getRGB(j, i);
		temp.r = (holder & 0xff0000) >> 16;
		temp.g = (holder & 0xff00 ) >> 8;
		temp.b = holder & 0xff;
		temp.A = 255;
		return temp;
	}
	private void init_pixel_matrix() {
		this.Pixel_Matrix = new Pixel[this.Image_Height][this.Image_Width];
		for(int i=0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Pixel_Matrix[i][j] = this.Get_Pixel(i, j);
			}
		}
	}
	public void Draw_Square(int center_x,int center_y,int square_Image_Width,int square_Image_Height,Pixel Color) {
		if (center_x + square_Image_Width >= this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {
			System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			Pixel_Matrix[center_y + square_Image_Height][i] =Color;
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			Pixel_Matrix[center_y - square_Image_Height][i]=Color;
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			Pixel_Matrix[i][center_x - square_Image_Width]=Color;
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			Pixel_Matrix[i][center_x + square_Image_Height]=Color;
		}
	}
	private void BresenhamsLine(int start_y,int start_x,int target_y,int target_x, Pixel color) {
		double dx, sx, dy, sy, err, e2;
		double x0 = start_y, x1 = target_y, y0 = start_x, y1 = target_x;
		dx = Math.abs(target_y - start_y);
		sx = start_y < target_y ? 1 : -1;
		dy = -Math.abs(target_x - start_x);
		sy = start_x < target_x ? 1 : -1;
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
				break;
			}

			Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
					
			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy;
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}
	}
	public void Draw_Line(int start_y,int start_x,int target_y,int target_x, Pixel color) {

		this.BresenhamsLine(start_y, start_x, target_y, target_x, color);
	}
	public void Draw_Line(int start_x,int start_y,int target_x,int target_y, Pixel color, int line_Image_Width) {
		if (line_Image_Width > 0) {
			float dx, sx, dy, sy, err, e2;
			float x0 = (float)start_x, x1 = (float)target_x, y0 = (float)start_y, y1 = (float)target_y;
			dx = (float)Math.abs(target_x - start_x);
			sx = (float)(start_x < target_x ? 1 : -1);
			dy = (float)(-Math.abs(target_y - start_y));
			sy = (float)(start_y < target_y ? 1 : -1);
			err = dx + dy;  /* error value e_xy */
			while (true) {
				if (x0 == x1 && y0 == y1) {
					Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
					if (line_Image_Width > 0) {

						if (start_y != target_y) {
							for (int i = 1; i <= line_Image_Width; i++) {
							
								Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = color;
								Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] = color;
							}
						}
						else {
							for (int i = 1; i <= line_Image_Width; i++) {
								Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = color;
								Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = color;
							}
						}


					}



					break;
				}

				Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
				if (line_Image_Width > 0) {
					if (start_y != target_y) {
						for (int i = 1; i <= line_Image_Width; i++) {
		
							Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = color;				
							Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] =color;
						}
					}
					else {
						for (int i = 1; i <= line_Image_Width; i++) {
							Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = color;
							Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = color;
						}
					}




				}

				e2 = 2 * err;
				if (e2 >= dy) {
					err += dy; /* e_xy+e_x > 0 */
					x0 += sx;
				}
				if (e2 <= dx) {
					err += dx;
					y0 += sy;
				}

			}
		}
		else {
			this.BresenhamsLine(start_x, start_y, target_x, target_y, color);
		}
	}
	public void Draw_Square(int center_x,int center_y,int square_Image_Width,int square_Image_Height,Pixel Color,String Mode) {
	
		if (Mode.equals("Fill")) {
		
			if (center_x + square_Image_Width > this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {				System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
				System.out.println("Image_Height Of Image: ");
				System.out.println("Image_Width Of Image: ");
				return;
			}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
					Pixel_Matrix[j][i] = Color;
				}
			}
		}
		else if (Mode.equals("Checkered")) {
			if (center_x + square_Image_Width > this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {				System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
		}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i += 2) {
					Pixel_Matrix[j][i] = Color;
				}
			}
		}
		else if (Mode.equals("Corners")) {
			if (center_x >= Image_Width || center_y >= this.Image_Height || square_Image_Width >= Image_Width || square_Image_Height >= this.Image_Height || center_x <= 0 || center_y <= 0 || square_Image_Width <= 0 || square_Image_Height <= 0
				|| center_x >= this.Image_Height || center_y >= Image_Width || square_Image_Width >= this.Image_Height || square_Image_Height >= Image_Width) {

				System.out.println("There Was A drawing Error\n");
				return;
			}
			this.Draw_Line(center_x, center_y, square_Image_Width, center_y, Color);
			this.Draw_Line(center_x, center_y, center_x, square_Image_Height, Color);
			this.Draw_Line(center_x, square_Image_Height, square_Image_Width, square_Image_Height, Color);
			this.Draw_Line(square_Image_Width, center_y, square_Image_Width, square_Image_Height, Color);



		}
	}
	public void Draw_Circle(int center_x,int center_y,int c_radius, Pixel color) {
		int x, y, r2;
		if (center_x + c_radius >= this.Image_Width || center_x - c_radius <= 0 || center_y + c_radius >= this.Image_Height || center_y - c_radius <= 0) {
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
	
		}
		r2 = c_radius * c_radius;


		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			Pixel_Matrix[center_y + y][center_x + x] = color;
			Pixel_Matrix[center_y + y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			Pixel_Matrix[center_y - y][center_x + x] = color;
			Pixel_Matrix[center_y - y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			Pixel_Matrix[center_y - x][center_x + y] = color;
			Pixel_Matrix[center_y - x][center_x - y] = color;
		}


	}
	public void Draw_Circle(int center_x,int center_y,int c_radius, Pixel color,String Mode) {
	
		if (Mode.equals("Fill")) {
			
			int x, y;
			if (center_x + c_radius > Image_Width || center_x - c_radius <0 || center_y + c_radius > Image_Height || center_y - c_radius < 0) {
				System.out.println("Image_Height Of Image: ");
				System.out.println("Image_Width Of Image: ");
				return;
		
			}
			for (y = -c_radius; y <= c_radius; y++)
				for (x = -c_radius; x <= c_radius; x++)
					if ((x * x) + (y * y) <= (c_radius * c_radius))
						Pixel_Matrix[center_y + y][center_x + x] = color;
		}
	}
	
	public void Grayscale() {
		for (int i = 0; i < Image_Height; i++) {

			for (int j = 0; j < Image_Width; j++) {

				if (Pixel_Matrix[i][j].b >= Pixel_Matrix[i][j].r && Pixel_Matrix[i][j].b >= Pixel_Matrix[i][j].g) {
					Pixel_Matrix[i][j].r = Pixel_Matrix[i][j].b;
					Pixel_Matrix[i][j].g = Pixel_Matrix[i][j].b;
				}
				else if (Pixel_Matrix[i][j].r >= Pixel_Matrix[i][j].b &&Pixel_Matrix[i][j].r >= Pixel_Matrix[i][j].g) {
					Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].r;
					Pixel_Matrix[i][j].g = Pixel_Matrix[i][j].r;
				}
				else if (Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].r &&Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].b) {
					Pixel_Matrix[i][j].r = Pixel_Matrix[i][j].g;
					Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].g;
				}

			}
		}
	}

	
	
	public double Color_Delta(Pixel A, Pixel B) {
		long  R_Gag = ((long)(A.r + (long)(B.r)) / 2);
		long  r = (long)A.r - (long)B.r;
		long  g = (long)A.g - (long)B.g;
		long  b = (long)A.b - (long)B.b;
		return (float)(Math.sqrt((((512 + R_Gag)*r*r) >> 8) + 4 * g*g + (((767 - R_Gag)*b*b) >> 8)));
	}

	public int Color_Distance(Pixel a, Pixel b) {
		int recored;
		recored = (a.b - b.b) + (a.r - b.r) + (a.g - b.g);
		if (recored < 0) {
			recored *= -1;
		}

		return recored;
	}
	public double Color_DistanceSq(Pixel a, Pixel b) {
		double  recored;
		recored = (b.r - a.r)*(b.r - a.r) + (b.g - a.g)*(b.g - a.g) + (b.b - a.b)*(b.b - a.b);
		return Math.sqrt(recored);
	}
	public double Image_Difference_Value(Image b) {

		double result = 0;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				result = result + Color_DistanceSq(Pixel_Matrix[i][j], b.Pixel_Matrix[i][j]);
			}
		}
		return result / Image_Height * Image_Width;

	}
	public boolean Distance_Neighbors(double max_distance, int i, int j) {
		Pixel center, point;
		center = Pixel_Matrix[i][j];
		double dist = 0;
		if (i - 1 < 0 && j + 1 < this.Image_Width && j - 1 > 0 && i + 1 < Image_Height) {
			point = Pixel_Matrix[i][j + 1];
			dist = (double)(Color_DistanceSq(point, center));
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j - 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j - 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j + 1];
			dist = (double)Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}

		}
		if (i + 1 > Image_Height && j + 1 < Image_Width && j - 1 > 0 && i - 1 > 0)
		{
			point = Pixel_Matrix[i][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}

		}
		if (j - 1 < 0 && i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width) {
			point = Pixel_Matrix[i + 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i][j + 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
		}
		if (j + 1 > Image_Width && i + 1 < Image_Height && i - 1 > 0 && j - 1 > 0) {
			point = Pixel_Matrix[i][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i - 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
			point = Pixel_Matrix[i + 1][j - 1];
			dist = Color_DistanceSq(point, center);
			if (dist > max_distance) {
				return false;
			}
		}

		return true;


	}
	public double Get_Neighbour_Mean_R(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r;

		if (i + 1 <= this.Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].r;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].r;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].r;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].r;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].r;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r;
			Divider++;
		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_G(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].g;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].g;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].g;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].g;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].g;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g;
			Divider++;
		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_B(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].b;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].b;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].b;
			Divider++;
		}
		if (j - 1 <= 0) {
			Mean += Pixel_Matrix[i][j - 1].b;
			Divider++;
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].b;
			Divider++;
		}
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b;
			Divider++;
		}
		return Mean / Divider;
	}

	public void Mark_Identical_Pixels(Pixel Target) {
		Color_Palette cset = new Color_Palette();
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				if (Pixel_Matrix[i][j] == Target) {
					this.Draw_Square(j, i, 2, 2, cset.Red);
				}
			}
		}

	}
	public void Mark_Identical_Pixels(Image Source) {
		Color_Palette cset = new Color_Palette();

		if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}
		else if (this.Image_Width*this.Image_Height > Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Source.Image_Height; i++) {
				for (int j = 0; j < Source.Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}

	}
	public void Mark_Identical_Pixels(Image Source, String mode) {
		Color_Palette cset = new Color_Palette();
		if (mode.equals("Strict")) {//strict
			if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
			else if (this.Image_Width*this.Image_Height  > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
		}
		else if (mode.equals("Loose")) {//loose

			if (this.Image_Width*this.Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
			else if (this.Image_Width*this.Image_Height > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this.Draw_Square(j, i, 2, 2, cset.Red);
						}
					}
				}
			}
		}
	}
	
	public void Mark_Different_Pixels(Image Source, int Color_Treshold, int Distnace_Treshold, Pixel frame_color) {


		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		
		ArrayList<Blob> Blobs = new ArrayList<Blob>();
		Blob temp = new Blob(0, 0, Distnace_Treshold);
		boolean detected = false;

		for (int i = 0; i < this.Image_Width; i++)
		{ 
			for (int j = 0 ; j < this.Image_Height ; j++)
			{

				if (Color_Delta(this.Pixel_Matrix[j][i], Source.Pixel_Matrix[j][i]) > Color_Treshold)
				{
					for (int m = 0; m < Blobs.size(); ++m) {
						if (Blobs.get(m).Near(i, j)) {
							Blobs.get(m).add(i, j);
							detected = true;
							break;
						}

					}

					if (!detected) {
						//temp.SetProps(i, j);
						Blobs.add(new Blob(i,j,Distnace_Treshold));
					}
					detected = false;
			}
		}
		}

		
		
		for (int m = 0; m < Blobs.size(); ++m) {
			this.Draw_Square(Blobs.get(m).Upleft_X, Blobs.get(m).Upleft_Y, Blobs.get(m).Downright_X, Blobs.get(m).Downright_Y, frame_color, "Corners");
			System.out.format("UL-x: %d UL-y: %d DR-x: %d DR-y: %d\n",Blobs.get(m).Upleft_X, Blobs.get(m).Upleft_Y, Blobs.get(m).Downright_X, Blobs.get(m).Downright_Y);
		}
		



	}

	public void Write_Pixel_Difference(Image Source, String mode, int min_diff) {

		if (mode.equals("Copy")) {
			if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
				return;
			}
			Image Temp = this;
			int index = 0;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_Distance(Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
						Temp.Pixel_Matrix[i][j] = Source.Pixel_Matrix[i][j];
					}
				}
			}
			this.Write_Image("Pixel_Diffrence.jpg");
		}
		else {
			return;
		}
	}

	public void Mark_Different_Pixels(Image Source) {
		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset =new Color_Palette();
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (this.Color_Distance(this.Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > 2) {
					this.Draw_Square(i, j, 2, 2, cset.Red);
				}
			}
		}


	}
	public void Mark_Different_Pixels(Image Source, String mode) {
	


		if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset =new Color_Palette();

		if (mode.equals("Strict")) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j] != Source.Pixel_Matrix[i][j]) {
						this.Draw_Square(j, i, 2, 2, cset.Red);
					}
				}
			}
		}

	}

	
	

}
	


	
