import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Transparency;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.util.LinkedList;
import java.util.Iterator;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Collections;
class Point{
	
	public double x,y,z;
	Point(){
		x=y=z=0;
	}
	Point(double X,double Y,double Z){
		x=X;
		y=Y;
		z=Z;
	}
	Point(Point copy){
		this.x=copy.x;
		this.y=copy.y;
		this.z =copy.z;
	}
	void Add(Point B) {
		this.x+=B.x;
		this.y+=B.y;
		this.z+=B.z;
	}
	void Divide_All(int Divider) {
		this.x /= Divider;
		this.y /= Divider;
		this.z /= Divider;

	}
	@Override
	public String toString() {
		return "[X: " + this.x +"]" +" [Y: " + this.y +"]" + " [Z: " + this.z +"]"+ "\n";
	}
}


class Pixel {
	public Pixel(int r,int g,int b) {
		this.r=r;
		this.b=b;
		this.g=g;
		A =255;
		analysis=0;
	}
	public Pixel(int r,int g,int b,int i,int j) {
		this.r=r;
		this.b=b;
		this.g=g;
		this.i=i;
		this.j=j;
		A =255;
		analysis=0;
	}
	public Pixel() {
		this.r=0;
		this.b=0;
		this.g=0;
		this.A=255;
		analysis=0;
	}
	public Pixel(Pixel copy) {
		this.r = copy.r;
		this.g = copy.g;
		this.b = copy.b;
		this.A = copy.A;
		this.analysis = copy.analysis;
	}
	public int r;
	public int g;
	public int b;
	public int A;
	public int analysis;
	public int i,j;
	public Pixel Pixel_Mul(Pixel b) {
		Pixel ret = new Pixel();
		ret.r = this.r*b.r;
		if (ret.r > 255) {
			ret.r = ret.r % 255;
		}
		ret.g = this.g*b.g;
		if (ret.g > 255) {
			ret.g = ret.g % 255;
		}
		ret.b = this.b*b.b;
		if (ret.b > 255) {
			ret.b = ret.b % 255;
		}
		return ret;
	}
	public boolean is_Bigger(Pixel b) {
		if (this.r > b.r && this.g > b.g && this.b > b.b) {
			return true;
		}
		else {
			return false;
		}
	}
	public void Add_Location(int i,int j) {
		this.i = i;
		this.j =j;
	}
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
		Color_Serial_Number = new Pixel[138];
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
	public Pixel Get_Random_Color() {
		Random rand = new Random();
		return this.Color_Serial_Number[Math.abs(rand.nextInt()) % 137 + 1];
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
	public Blob(Blob copy) {
		this.Downright_X=copy.Downright_X;
		this.Downright_Y = copy.Downright_Y;
		this.Upleft_X = copy.Upleft_X;
		this.Upleft_Y = copy.Upleft_Y;
		this.Distnace_Treshold = copy.Distnace_Treshold;
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
		//return (double)Math.abs(this.Upleft_X - Downright_X)*(Upleft_Y - Downright_Y);
		return Math.sqrt((this.Downright_X-this.Upleft_X)*(this.Downright_X-this.Upleft_X) + (this.Downright_Y-this.Upleft_Y)*(this.Downright_Y-this.Upleft_Y));
	}

}






public class Image {
	
	
	
	
	
	
	
	private BufferedImage IMG;
	public Pixel Pixel_Matrix[][];
	public int Image_Width,Image_Height;
	public String F_Path;
	//public boolean hasAlphaChannel;
	
	//functionality
	Image(){

		
	}
	Image(Image copy){
		this.F_Path = copy.F_Path;
		this.Image_Width = copy.Image_Width;
		this.Image_Height = copy.Image_Height;
		this.IMG = copy.IMG;
		this.Pixel_Matrix = copy.Pixel_Matrix;
	}
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
    public void Set_Color(int i,int j,Pixel color) {
	  int p_value =0;
	  p_value = (255<<24) | (color.r<<16) | (color.g<<8) | color.b;
		  this.IMG.setRGB(j, i, p_value);
		  
	  }
    public void Set_Color(Pixel target,int r,int g,int b) {
		target.r=r;
		target.g=g;
		target.b=b;
	}
    public void Load_Image(String FilePath) throws IOException {
		try {
			this.F_Path = FilePath;
		this.IMG = ImageIO.read(Image.class.getResource(FilePath));
		//this.IMG = ImageIO.read(new File(FilePath));
		this.Image_Load_Wrapper();
		}catch(IOException e) {
			System.out.println("Error");
		}
		
		
	
	}
	public void Commint_Matrix_Changes() {
		for(int i=0;i<this.Image_Height;i++) {
			for(int j=0;j<this.Image_Width;j++) {
				this.Set_Color(i, j, this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b);
			}
		}
	}
    public void Update_Pixel_Matrix() {
    	this.init_pixel_matrix();
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
			
		      File f = new File(Filename);
		      ImageIO.write(IMG, "png", f);
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
	public void Load_Blank_Canvas(int height,int width,Pixel Background_Color) {
		this.IMG = new BufferedImage(width,height,BufferedImage.TYPE_3BYTE_BGR);
		this.init_pixel_matrix();
		this.Image_Load_Wrapper();
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++) {
				this.Pixel_Matrix[i][j] = Background_Color;
			}
		}
	}
	public void convertToARGB()
	{
	    BufferedImage newImage = new BufferedImage(
	        IMG.getWidth(), IMG.getHeight(),
	        BufferedImage.TYPE_INT_ARGB);
	    Graphics2D g = newImage.createGraphics();
	    g.drawImage(IMG, 0, 0, null);
	    g.dispose();
	    this.IMG = newImage;
	}
	public void Draw_Square(int center_x,int center_y,int square_Image_Width,int square_Image_Height,Pixel Color) {
		if (center_x + square_Image_Width >= this.Image_Width || center_y + square_Image_Height >= this.Image_Height || center_x - square_Image_Width < 0 || center_y - square_Image_Height < 0) {
			System.out.println("Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n");
			System.out.println("Image_Height Of Image: ");
			System.out.println("Image_Width Of Image: ");
			return;
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			this.Set_Color(center_y + square_Image_Height, i, Color);
			//Pixel_Matrix[center_y + square_Image_Height][i] = new Pixel(Color);
		}
		for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i++) {
			this.Set_Color(center_y - square_Image_Height, i, Color);
			//Pixel_Matrix[center_y - square_Image_Height][i]= new Pixel(Color);
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			this.Set_Color(i, center_x - square_Image_Width, Color);
			//Pixel_Matrix[i][center_x - square_Image_Width]= new Pixel(Color);
		}
		for (int i = center_y - square_Image_Height; i <= center_y + square_Image_Height; i++) {
			//Pixel_Matrix[i][center_x + square_Image_Width]= new Pixel(Color);
			this.Set_Color(i, center_x + square_Image_Width, Color);
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
				this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);
				//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);

				break;
			}

			//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);
			this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);

			
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
	public void Draw_Line(int start_x,int start_y,int target_y,Pixel color) {
	
		if (target_y > this.Image_Height || start_y > this.Image_Height || start_y < 0 || start_x > Image_Width || start_x < 0) {
			System.out.println("Line Out Of Image Range\nDraw Action Aborted");
			return;
		}

		if (start_y < target_y) {
			for (int i = start_y; i < target_y; i++) {
				//Pixel_Matrix[i][start_x] = new Pixel(color);
				this.Set_Color(i, start_x, color);
			}
		}
		else {
			for (int i = start_y; i > target_y; i--) {
				//Pixel_Matrix[i][start_x]= new Pixel(color);
				this.Set_Color(i, start_x, color);
			}
		}

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
					this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0), color);
					//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = new Pixel(color);
					if (line_Image_Width > 0) {

						if (start_y != target_y) {
							for (int i = 1; i <= line_Image_Width; i++) {
							
								this.Set_Color((int)Math.floor(x0) + i, (int)Math.floor(y0), color);
								this.Set_Color((int)Math.floor(x0) - i,(int)Math.floor(y0), color);

								//Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = new Pixel(color);
								//Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] = new Pixel(color);
							}
						}
						else {
							for (int i = 1; i <= line_Image_Width; i++) {
								
								this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) + i, color);
								this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) - i, color);

								//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = new Pixel(color);
								//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = new Pixel(color);
							}
						}


					}



					break;
				}

				Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)] = color;
				if (line_Image_Width > 0) {
					if (start_y != target_y) {
						for (int i = 1; i <= line_Image_Width; i++) {
		
							this.Set_Color((int)Math.floor(x0) + i, (int)Math.floor(y0), color);
							this.Set_Color((int)Math.floor(x0) - i,(int)Math.floor(y0), color);
							//Pixel_Matrix[(int)Math.floor(x0) + i][(int)Math.floor(y0)] = color;				
							//Pixel_Matrix[(int)Math.floor(x0) - i][(int)Math.floor(y0)] =color;
						}
					}
					else {
						for (int i = 1; i <= line_Image_Width; i++) {
							
							this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) + i, color);
							this.Set_Color((int)Math.floor(x0), (int)Math.floor(y0) - i, color);

							//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) + i] = color;
							//Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0) - i] = color;
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
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this.Set_Color(j, i, Color);
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
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i +=8) {
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this.Set_Color(j, i, Color);
				}
			}
			
			for (int j = center_y - square_Image_Height; j <= center_y + square_Image_Height; j++) {
				for (int i = center_x - square_Image_Width; i <= center_x + square_Image_Width; i +=8) {
					//Pixel_Matrix[i][j] = new Pixel(Color);
					this.Set_Color(i, j, Color);
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
			this.Set_Color(center_y + y,center_x + x, color);
			this.Set_Color(center_y + y,center_x - x, color);

			//Pixel_Matrix[center_y + y][center_x + x] = color;
			//Pixel_Matrix[center_y + y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			this.Set_Color(center_y - y,center_x + x, color);
			this.Set_Color(center_y - y,center_x - x, color);
			//Pixel_Matrix[center_y - y][center_x + x] = color;
			//Pixel_Matrix[center_y - y][center_x - x] = color;
		}
		for (x = -c_radius; x <= c_radius; x++) {
			y = (int)(Math.sqrt(r2 - x * x) + 0.5);
			this.Set_Color(center_y - x,center_x + y, color);
			this.Set_Color(center_y - x,center_x - y, color);
			//Pixel_Matrix[center_y - x][center_x + y] = color;
			//Pixel_Matrix[center_y - x][center_x - y] = color;
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
						//Pixel_Matrix[center_y + y][center_x + x] = color;
						this.Set_Color(center_y + y, center_x + x, color);
		}
	}
	public void Draw_Text(int center_y,int center_x,String text, Pixel color) {

		int text_length = text.length();
		int start_x, draw_y, flag = 0, temp=0;
		LibCharacters Set = new LibCharacters();
		if (center_x + (9 * (text_length / 2)) > Image_Width || center_x - (9 * (text_length / 2)) < 0
			|| center_y + 4 > Image_Height || center_y - 4 < 0) {
			System.out.println("Text Longer The Image Frame, Aborting...\n");
			return;
		}

		start_x = center_x - (9 * (text_length / 2));
		draw_y = center_y - 4;

		for (int i = 0; i < text.length(); i++) {

			switch (text.charAt(i))
			{

			case '0':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Zero[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);
						//Pixel_Matrix[draw_y][start_x]=color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '1':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_One[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '2':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Two[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '3':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Three[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '4':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Four[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '5':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Five[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '6':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Six[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '7':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Seven[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '8':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Eight[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
			case '9':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Number_Nine[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'A':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_A[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'B':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_B[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'C':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_C[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'D':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_D[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'E':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_E[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'F':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_F[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'G':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_G[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'H':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_H[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'I':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_I[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'J':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_J[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'K':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_K[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'L':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_L[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'M':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_M[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'N':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_N[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'O':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_O[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'P':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_P[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Q':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Q[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case 'R':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_R[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'S':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_S[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'T':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_T[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'U':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_U[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'V':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_V[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'W':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_W[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;

				break;

			case 'X':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_X[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Y':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Y[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case 'Z':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Letter_Z[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '?':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Quesiton_Mark[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '!':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Exclamation_Point[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '(':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Left_Braket[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case ')':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Right_Braket[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '&':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Ampersand[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case ',':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Comma[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case '[':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Squaure_Braket_Left[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


			case ']':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Square_Braket_Right[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case ' ':
				temp += 9;
				break;

			case ':':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Colon[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case '=':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.EqualSign[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;

			case '+':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.PlusSign[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '%':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Precent[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '*':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Astersik[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case '.':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Dot[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;
				
			case ';':
				temp = start_x;
				while (flag != 81) {

					if ((flag + 1) % 9 == 0) {
						draw_y++;
						start_x = temp;
					}
					if (Set.Semi_Colon[flag] == 1) {
						this.Set_Color(draw_y, start_x, color);

						//Pixel_Matrix[draw_y][start_x] = color;
					}
					start_x++;
					flag++;
				}

				flag = 0;
				break;


		

			default:
				break;
				
				
			}
			
			

			draw_y = center_y - 4;
			start_x = temp;
			start_x += 9;

		}



	}
	public double Get_Square(double value) {
		return value * value;
	}
	public double squared_3Point_distance(Point first, Point second) {
		return Get_Square(first.x - second.x) + Get_Square(first.y - second.y) + Get_Square(first.z - second.z);
	}
	public void Grayscale(int alter) {
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
		if(alter == 1) {
			this.Commint_Matrix_Changes();
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
	public double Get_Neighbour_Mean_G(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].g * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].g * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].g * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].g * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].g * Kernel[0][0];
			Divider++;

		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g * Kernel[2][0];
			if (Kernel[2][0] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_R(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].r * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].r * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].r * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].r * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].r * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	public double Get_Neighbour_Mean_B(int i, int j, double Kernel[][], double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b * Kernel[1][1];

		if (i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].b * Kernel[2][1];
			if (Kernel[2][1] != 0) {
				Divider++;
			}
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].b * Kernel[0][1];
			if (Kernel[0][1] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].b * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].b * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].b * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	

	public void Mark_Identical_Pixels(Pixel Target) {
		Color_Palette cset = new Color_Palette();
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (Pixel_Matrix[i][j] == Target) {
					this.Draw_Square(j, i, 2, 2, cset.Red);
				}
			}
		}

	}
	
	public void singlePixelConvolution(int i_c ,int j_c,double [][] k,int kernelWidth,int kernelHeight){
		  Pixel output = new Pixel(0,0,0);
		  output.i = i_c;
		  output.j = j_c;
		  for(int i=0;i<kernelWidth;++i){
			  	for(int j=0;j<kernelHeight;++j){
			  		try {
			  			output.r = output.r + (this.Pixel_Matrix[i_c+i][j_c+j].r * (int)k[i][j]);
			  			output.g = output.g + (this.Pixel_Matrix[i_c+i][j_c+j].g * (int)k[i][j]);
			  			output.b = output.b + (this.Pixel_Matrix[i_c+i][j_c+j].b * (int)k[i][j]);
			  		}catch(Exception e) {
			  			continue;
			  		}

			  	}
		  }
		  this.Pixel_Matrix[i_c][j_c] = output;
		
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
		//Blob temp = new Blob(0, 0, Distnace_Treshold);
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
			this.Draw_Square(Blobs.get(m).Upleft_Y, Blobs.get(m).Upleft_X, Blobs.get(m).Downright_Y, Blobs.get(m).Downright_X, frame_color, "Corners");
			//System.out.format("UL-x: %d UL-y: %d DR-x: %d DR-y: %d\n",Blobs.get(m).Upleft_X, Blobs.get(m).Upleft_Y, Blobs.get(m).Downright_X, Blobs.get(m).Downright_Y);
		}
		



	}
	public void Write_Pixel_Difference(Image Source, String mode, int min_diff) {

		if (mode.equals("Copy")) {
			if (this.Image_Width != Source.Image_Width || this.Image_Height != Source.Image_Height) {
				return;
			}
			Image Temp = this;
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
	public void Write_Channel_Histogram() {
		int posR, PosG, PosB, H = 500, W = 1300;
		int bar_width = this.Image_Width / 300;
		if (bar_width == 0) {
			bar_width = 1;
		}
		int sR = 0, sG = 0, sB = 0;
		Image frame = new Image();
		Color_Palette CSET = new Color_Palette();
		frame.Load_Blank_Canvas(H, W, CSET.Azure);
		
		frame.Draw_Square(250, 250, 150, 150, CSET.Black);
		frame.Draw_Square(650, 250, 150, 150, CSET.Black);
		frame.Draw_Square(1050, 250, 150, 150, CSET.Black);
		frame.Draw_Square(250, 250, 151, 151, CSET.Black);
		frame.Draw_Square(650, 250, 151, 151, CSET.Black);
		frame.Draw_Square(1050, 250, 151, 151, CSET.Black);

		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 100, i, 400, CSET.Light_Gray);
		}

		for (int i = 503; i <= 800; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 500, i, 800, CSET.Light_Gray);
		}

		for (int i = 903; i <= 1200; i += 5) {
			frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
		}
		for (int i = 103; i <= 400; i += 5) {
			frame.Draw_Line(i, 900, i, 1200, CSET.Light_Gray);
		}

		frame.Draw_Text(90, 240, "RED GRAPH",CSET.Black);
		frame.Draw_Text(90, 640, "GREEN GRAPH",CSET.Black);
		frame.Draw_Text(90, 1040, "BLUE GRAPH",CSET.Black);


		posR = 101;
		PosG = 501;
		PosB = 901;

		

		for (int i = 0; i < this.Image_Width; i++) {
			for (int k = 0; k < bar_width; k++) {
				for (int j = 0; j < this.Image_Height; j++) {
					if (Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].g &&Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].b &&
							Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {
						
						sR++;
					}
					else if (Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].b
						&& Pixel_Matrix[j][i] != CSET.Black
						&&Pixel_Matrix[j][i] != CSET.White) {
						//sG += Pixel_Matrix[j][i].g;
						sG++;
					}
					else if (Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].g
						&& Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {
						//sB += Pixel_Matrix[j][i].b;
						sB++;
					}

				}
				if (bar_width > 1) {
					i++;
				}
			}

			sR /= bar_width;
			sG /= bar_width;
			sB /= bar_width;

			sR %= 300;
			sG %= 300;
			sB %= 300;

			
			if (posR < 399) {
				//frame.Draw_Line(posR, 399, 399 - sR, CSET.Red,bar_width);
				frame.Draw_Line(399, posR, 399 - sR, posR, CSET.Red,Math.max(1,bar_width/3));
			}
			if (PosG < 799) {
				//frame.Draw_Line(PosG, 399, 399 - sG, CSET.Green);
				frame.Draw_Line(399, PosG, 399 - sG, PosG, CSET.Green,Math.max(1,bar_width/3));

			}
			if (PosB < 1199) {
				//frame.Draw_Line(PosB, 399, 399 - sB, CSET.Blue);
				frame.Draw_Line(399, PosB, 399 - sB, PosB, CSET.Blue,Math.max(1,bar_width/3));

			}

			posR += bar_width;
			PosG += bar_width;
			PosB += bar_width;

			sR = sG = sB = 0;

		}




		frame.Write_Image("ChannelGraph.png");
	}
	public void Write_Channel(char color) {
		
		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g =0;
					Pixel_Matrix[i][j].b =0;

				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].r =0;
					Pixel_Matrix[i][j].b =0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g =0;
					Pixel_Matrix[i][j].r =0;

				}
			}
			break;
		default:
			break;
		}


	}
	public void Shutdown_Channel(char color) {
		
		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					
					Pixel_Matrix[i][j].r = 0;
				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].g = 0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].b = 0;
				}
			}
			break;
		default:
			break;
		}
	}
	public void Flip180() {
		Image temp = new Image();
		temp.Load_Blank_Canvas(this.Image_Height, this.Image_Width, new Pixel(0,0,0));
		int k=0,m=0;
		
		for (int i = Image_Height - 1; i >= 0; i--) {
			for (int j = Image_Width - 1; j >= 0; j--) {
				temp.Pixel_Matrix[k][m] = new Pixel(this.Pixel_Matrix[i][j]);
				m++;
			}
			
			k++;
			m=0;

		}

		for(int i=0;i<Image_Height;i++) {
			for(int j=0;j<Image_Width;j++) {
				this.Pixel_Matrix[i][j] = new Pixel(temp.Pixel_Matrix[i][j]);

			}
		}
	}
	public void Color_Flooring(String mode , int alter) {
	
		if (mode.equals("10")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					this.Pixel_Matrix[i][j].r = (this.Pixel_Matrix[i][j].r / 10) * 10;
					this.Pixel_Matrix[i][j].g = (this.Pixel_Matrix[i][j].g / 10) * 10;
					this.Pixel_Matrix[i][j].b = (this.Pixel_Matrix[i][j].b / 10) * 10;

				}
			}



		}
		else if (mode.equals("100")) {

			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					this.Pixel_Matrix[i][j].r = (this.Pixel_Matrix[i][j].r / 100) * 100;
					this.Pixel_Matrix[i][j].g = (this.Pixel_Matrix[i][j].g / 100) * 100;
					this.Pixel_Matrix[i][j].b = (this.Pixel_Matrix[i][j].b / 100) * 100;

				}
			}

		}
		if(alter == 1) {
			this.Commint_Matrix_Changes();
		}
	}
	public void Tresholding(String mode, int value ,int alter) {
		
		if (mode.equals("Trunc")) {
		
			this.Color_Flooring("10",1);
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 1; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j].r > value || Pixel_Matrix[i][j].g > value || Pixel_Matrix[i][j].b > value)
					{
						Pixel_Matrix[i][j].r = 255;
						Pixel_Matrix[i][j].g = 255;
						Pixel_Matrix[i][j].b = 255;



					}
					else {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;



					}

				}
			}
			
		}

		else if (mode.equals("EdgeTriggerd")) {
			Pixel prev = new Pixel();
			
			for (int i = 0; i < Image_Height; i++) {
				prev.r = Pixel_Matrix[i][0].r;
				prev.g = Pixel_Matrix[i][0].g;
				prev.b = Pixel_Matrix[i][0].b;

				Pixel_Matrix[i][0].r = 0;
				Pixel_Matrix[i][0].g = 0;
				Pixel_Matrix[i][0].b = 0;

				for (int j = 1; j < Image_Width; j++) {
					if (Color_Distance(prev, Pixel_Matrix[i][j]) > value)
					{
						Pixel_Matrix[i][j].r = 255;
						Pixel_Matrix[i][j].g = 255;
						Pixel_Matrix[i][j].b = 255;



					}
					else {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;



					}

				}
			}
			
		}
		if (alter == 1) {
			this.Commint_Matrix_Changes();
		}

	}
	public void Edge_Detection() {
		Pixel prev = new Pixel() ;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > 50)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
		

	}
	public void Edge_Detection(int max_color_gap) {
		
		Pixel prev = new Pixel() ;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
	}
	public void Mark_Contour(Pixel Color,int max_color_gap) {
		Pixel prev = new Pixel();

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j] = Color;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;



				}

			}
		}

		for (int i = 0; i < Image_Width; i++) {
			prev.r = Pixel_Matrix[0][i].r;
			prev.g = Pixel_Matrix[0][i].g;
			prev.b = Pixel_Matrix[0][i].b;

			for (int j = 1; j < Image_Height; j++) {
				if (Color_Distance(prev, Pixel_Matrix[j][i]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;

					Pixel_Matrix[j][i] = Color;



				}
				else {
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;



				}

			}
		}

	}
	public void Feature_Matching(int source_x,int source_y) {
		if ((source_x + 1 > Image_Width) || (source_x - 1 < 0) || (source_y + 1 > Image_Height) || (source_y - 1 < 0)) {
			//out of image border;
			return;
		}
		Pixel up=new Pixel(), down=new Pixel(), left=new Pixel(), right=new Pixel(), center = new Pixel();
		Color_Palette cset = new Color_Palette();
		int band = 5;
		center.r = Pixel_Matrix[source_y][source_x].r;
		center.g = Pixel_Matrix[source_y][source_x].g;
		center.b = Pixel_Matrix[source_y][source_x].b;

		up.r = Pixel_Matrix[source_y - 1][source_x].r;
		up.g = Pixel_Matrix[source_y - 1][source_x].g;
		up.b = Pixel_Matrix[source_y - 1][source_x].b;

		down.r = Pixel_Matrix[source_y + 1][source_x].r;
		down.g = Pixel_Matrix[source_y + 1][source_x].g;
		down.b = Pixel_Matrix[source_y + 1][source_x].b;

		left.r = Pixel_Matrix[source_y][source_x - 1].r;
		left.g = Pixel_Matrix[source_y][source_x - 1].g;
		left.b = Pixel_Matrix[source_y][source_x - 1].b;

		right.r = Pixel_Matrix[source_y][source_x + 1].r;
		right.g = Pixel_Matrix[source_y][source_x + 1].g;
		right.b = Pixel_Matrix[source_y][source_x + 1].b;

		Draw_Circle(source_x, source_y, 3, cset.Red);
		Draw_Circle(source_x, source_y, 2, cset.Blue);


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width && j - 1 > 0) {
					if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], down) < band &&Color_Distance(Pixel_Matrix[i - 1][j], up) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], right) < band &&Color_Distance(Pixel_Matrix[i][j - 1], left) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);
					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
				}
			}
		}



	}
	public void Quarantine_Pixel(Pixel sample,double max_difference,String mode) {

		if (mode.equals("Keep_Self")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) > max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}

		}
		else if (mode.equals("Drop_Self")) {
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) < max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}
			
		}
	}
	public void Kronecker_product(Image b, String mode,int Alter) {
		
		if (mode.equals("Mul")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
		    long startRow=0, startCol=0;
			Pixel temp = new Pixel();
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							temp = this.Pixel_Matrix[i][j].Pixel_Mul(b.Pixel_Matrix[k][l]);
							Kr_mat[(int)startRow + k][(int)startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;

			}


		}
		else if (mode.equals("Size")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							if (this.Pixel_Matrix[i][j].is_Bigger(b.Pixel_Matrix[k][l])) {
								temp = this.Pixel_Matrix[i][j];
							}
							else {
								temp = b.Pixel_Matrix[k][l];
							}

							Kr_mat[startRow + k][startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;
			}
		}
		else if (mode.equals("Build_From")) {
			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0;
			int flag = 0;
			for (int i = 0; i < this.Image_Height; i++) {
				for (int j = 0; j < this.Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							if (flag == 0) {
								temp = this.Pixel_Matrix[i][j];
								flag = 1;
							}
							else {
								temp = b.Pixel_Matrix[k][l];
								flag = 0;
							}

							Kr_mat[startRow + k][startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;

			}
		}
		else if (mode.equals("Mix")) {

			Pixel[][] Kr_mat = new Pixel[b.Image_Height*this.Image_Height][this.Image_Width*b.Image_Width];
			BufferedImage Kronecker =  new BufferedImage(this.Image_Width*b.Image_Width,b.Image_Height*this.Image_Height,BufferedImage.TYPE_3BYTE_BGR);
			
			Pixel temp = new Pixel();
			int startRow =0 , startCol= 0,flag =0;


			for (int i = 0; i < this.Image_Height; i++) {

				for (int j = 0; j < this.Image_Width; j++)
				{
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++)
					{
						if (flag == 1) {
							temp = this.Pixel_Matrix[i][j];
						}
						else if (flag == 0) {
							temp = b.Pixel_Matrix[i][j];
						}

						for (int l = 0; l < b.Image_Width; l++)
						{

							Kr_mat[startRow + k][startCol + l] = temp;
						}
						if (flag == 1) {
							flag = 0;
						}
						else {
							flag = 1;
						}
					}


				}

			}

			if (Alter == 1) {
				this.Image_Width *= b.Image_Width;
				this.Image_Height *= b.Image_Height;
				this.Pixel_Matrix = Kr_mat;
				this.IMG = Kronecker;
			}
		}


	}
	public void Image_Transpose() {
		int H = this.Image_Width, W = this.Image_Height;
		Pixel[][] tmat = new Pixel[H][W];
		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {
				tmat[j][i] = this.Pixel_Matrix[i][j];
			}
		}

		this.Pixel_Matrix = tmat;


	}
	public double Pixel_Dataframe_Difference(Pixel Pix, Point DF_point) {
		double distance;
		distance = ((DF_point.x - Pix.r)*(DF_point.x - Pix.r) + (DF_point.y - Pix.g)*(DF_point.y - Pix.g) + (DF_point.z - Pix.b)*(DF_point.z - Pix.b));
		return Math.sqrt(distance);
	}
	private ArrayList<Point> K_Means(ArrayList<Point> data, int k, int number_of_iterations) {
		Random random_machine = new Random();
		
		ArrayList<Point> means = new ArrayList<Point>(k);
		for(int i = 0 ; i<k;i++) {
			means.add(new Point());
		}
		
		
		for(int cluster =0 ;cluster < means.size();cluster++) {
			means.set(cluster, data.get(random_machine.nextInt(data.size())));
		}

		ArrayList<Integer> assignments = new ArrayList<Integer>(data.size());
		for(int i=0;i<data.size();i++) {
			assignments.add(0);
		}

		for (int iteration = 0; iteration < number_of_iterations; ++iteration) {
			// Find assignments.
			for (int point = 0; point < data.size(); ++point) {
				double best_distance = Double.MAX_VALUE;
				int best_cluster = 0;
				for (int cluster = 0; cluster < k; ++cluster) {
					double distance = squared_3Point_distance(data.get(point), means.get(cluster));
					if (distance < best_distance) {
						best_distance = distance;
						best_cluster = cluster;
					}
				}
				assignments.set(point, best_cluster);

			}

			// Sum up and count points for each cluster.
			ArrayList<Point> new_means = new ArrayList<Point>(k);
			for(int i = 0 ; i <k ; i++) {
				new_means.add(new Point());
			}
			ArrayList<Integer> counts = new ArrayList<>(k);
			for(int i=0;i<k;i++) {
				counts.add(0);
			}
		

			for (int point = 0; point < data.size(); ++point) {
				int cluster = assignments.get(point);
				double x,y,z;
				Point temp = new Point();
				x = new_means.get(cluster).x + data.get(point).x;
				y = new_means.get(cluster).y + data.get(point).y;
				z = new_means.get(cluster).z + data.get(point).z;
				temp.x=x;
				temp.y=y;
				temp.z=z;
				//System.out.println("Iter: "+iteration  + " temp: " + temp );

				new_means.set(cluster, temp);
				int c = counts.get(cluster);
				c++;
				counts.set(cluster, c);
			}

			// Divide sums by counts to get new centroids.
			for (int cluster = 0; cluster < k; ++cluster) {
				// Turn 0/0 into 0/1 to avoid zero division.
				int count = Math.max(1, counts.get(cluster));
				Point temp = new Point();
				temp.x = new_means.get(cluster).x / count;
				temp.y = new_means.get(cluster).y / count;
				temp.z = new_means.get(cluster).z / count;
				//System.out.println(temp);
				means.set(cluster, temp);
			
			}
		}

		return means;

		
		
		
	}
	public void Image_Segmentation(int k, int iterations) {
		
		ArrayList<Point> image_ThreeD_Mat = new ArrayList<Point>();
		ArrayList<Point> Result = new ArrayList<Point>();
	
		for(int i=0;i<Image_Height;i++) {
			for(int j=0;j<Image_Width;j++) {
				image_ThreeD_Mat.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,
						this.Pixel_Matrix[i][j].b));
			}
		}

		Result = this.K_Means(image_ThreeD_Mat, k, iterations);


		double best_dist;
		Point temp = new Point();

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = Double.MAX_VALUE;
				
				for(int m = 0 ;m < Result.size();m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Result.get(m)) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j],  Result.get(m));
						temp =  Result.get(m);
					}
				}
				
				Pixel_Matrix[i][j].r = (int)temp.x;
				Pixel_Matrix[i][j].g = (int)temp.y;
				Pixel_Matrix[i][j].b = (int)temp.z;

			}
		}






	}
	private void Blob_Framing(int distance_treshold, Pixel frame_color) {
		Color_Palette CSET = new Color_Palette();
		ArrayList<Blob> Blobs = new ArrayList<Blob>();

		Blob temp = new Blob(0, 0, distance_treshold);
		boolean detected = false;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {

				if (this.Pixel_Matrix[i][j].analysis == 42) {
				
					for (int k = 0; k < (int)Blobs.size(); ++k) {
						if (Blobs.get(k).Near(i, j) == true) {
							Blobs.get(k).add(i, j);
							detected = true;

							break;

						}

					}

					if (detected == false) {
						temp.SetProps(i, j);
						Blobs.add(new Blob(temp));
					}
					
					detected = false;

				}
			}
		}

		for (int k = 0; k < (int)Blobs.size(); k++) {
			if (Blobs.get(k).Size() < distance_treshold) {

				Blobs.remove(k);
			}

		}

		for (int k = 0; k < (int)Blobs.size(); ++k) {

			Draw_Square(Blobs.get(k).Downright_X, Blobs.get(k).Downright_Y, Blobs.get(k).Upleft_X, Blobs.get(k).Upleft_Y, frame_color, "Corners");
			//Pixel_Matrix[Blobs.get(k).Upleft_X][Blobs.get(k).Upleft_Y] = new Pixel(CSET.Yellow);
			//Pixel_Matrix[Blobs.get(k).Downright_X][Blobs.get(k).Downright_Y] = new Pixel(CSET.Green);



		}
	}
	public void Figure_Detection(int blob_distance_treshold, int color_distance_treshold, int Thresholding_level) {

		this.Tresholding("Trunc", Thresholding_level,0);
		
		int[][] adj_matrix = new int[Image_Height][Image_Width];
		int color_treshold = color_distance_treshold;
		Color_Palette C = new Color_Palette();
		for (int i = 0; i < this.Image_Height; i++) {
			for(int j=0;j<Image_Width;j++) {
				adj_matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width-1; j++) {
				if (Color_Delta(Pixel_Matrix[i][j], Pixel_Matrix[i][j + 1]) > color_treshold) {
					adj_matrix[i][j] = 1;


				}
			}
		}


		for (int i = 0; i < this.Image_Height; i++) {
			for (int j = 0; j < this.Image_Width; j++) {
				if (adj_matrix[i][j] == 1) {
					Pixel_Matrix[i][j].analysis = 42;
				}
			}
		}
		
		this.Blob_Framing(blob_distance_treshold, C.Red);
		this.Update_Pixel_Matrix();
	}
	public void Write_Average_Color_Palette(int palette_size) {
		int H, W, lx;
		Color_Palette CSET =new Color_Palette();
		Pixel palette_sample = new Pixel();
		ArrayList<Point> imData = new ArrayList<Point>(), Means = new ArrayList<Point>();
		Image palette_image = new Image();
		
		
		
		for(int i =0;i<Image_Height;i++) {
			for(int j =0 ;j<Image_Width;j++) {
				imData.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b));
			}
		}
		
		
		Means = K_Means(imData, palette_size, 200);
		H = 200;
		W = 200 * palette_size;
		palette_image.Load_Blank_Canvas(H, W, CSET.Black);
		lx = 0;

		for (int m = 0 ; m<Means.size();m++) {
			palette_sample.r = (int)Means.get(m).x;
			palette_sample.g = (int)Means.get(m).y;
			palette_sample.b = (int)Means.get(m).z;
			
			  for (int j = 0; j < 199; j++) {
				  palette_image.Draw_Line(j,lx,j,lx + 199,palette_sample);
			  
			  
			  }
			 

			lx += 199;
		}

		palette_image.Write_Image(palette_size + " Bit Palette.png");

	}
	public void Pixel_Griding() {
		double sigma = 1.0;
		double r, s = 2.0 * sigma * sigma;
		double GKernel[][] = new double[5][5];
		double sum = 0.0;
		for (int x = -2; x <= 2; x++) {
			for (int y = -2; y <= 2; y++) {
				r = Math.sqrt(x * x + y * y);
				GKernel[x + 2][y + 2] = (Math.exp(-(r * r) / s)) / (Math.PI * s);
				sum += GKernel[x + 2][y + 2];
			}
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				GKernel[i][j] /= sum;
			}
		}


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				Pixel_Matrix[i][j].r += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].r;
				Pixel_Matrix[i][j].g += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].g;
				Pixel_Matrix[i][j].b += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].b;

			}
		}



	}
	public ArrayList<Point> Get_Average_Color_Palette(int palette_size) {
		ArrayList<Point> imData = new ArrayList<Point>();

		for(int i =0;i<Image_Height;i++) {
			for(int j =0 ;j<Image_Width;j++) {
				imData.add(new Point(this.Pixel_Matrix[i][j].r,this.Pixel_Matrix[i][j].g,this.Pixel_Matrix[i][j].b));
			}
		}
		

		return this.K_Means(imData, palette_size, 200);

	}
	public	void Set_Colors_Using_Average_Palette(ArrayList<Point> Average_Colors) {
		double best_dist;
		Point temp = new Point();

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = Double.MAX_VALUE;
			
				
				for(int m = 0 ; m <Average_Colors.size();m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors.get(m)) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors.get(m));
						temp.x = Average_Colors.get(m).x;
						temp.y = Average_Colors.get(m).y;
						temp.z = Average_Colors.get(m).z;

					}
				}
				
				Pixel_Matrix[i][j] = new Pixel((int)temp.x,(int)temp.y,(int)temp.z);
			

			}
			
			
			
		}




	}
	public ArrayList<Pixel> Get_Line_Pixels(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;

		ArrayList<Pixel> Points = new ArrayList<Pixel>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(Math.abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.add(new Pixel(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
						Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b,(int)Math.floor(x0),(int)Math.floor(x0)));
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.add(new Pixel(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
					Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b,(int)Math.floor(x0),(int)Math.floor(x0)));
			
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



		return Points;
	}
	public void Register_PixelFrame(ArrayList<Pixel> Frame) {
		Pixel color= new Pixel();
		for(int i =0;i< Frame.size();i++) {
			color.r = Frame.get(i).r;
			color.g = Frame.get(i).g;
			color.b = Frame.get(i).b;
			this.Pixel_Matrix[Frame.get(i).i][Frame.get(i).j] = new Pixel(color.r,color.g,color.b);
		}
	}
	public Pixel Dominant_Color_Via_Line(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;
		Pixel Dom_Color = new Pixel();
		ArrayList<Point> Points = new ArrayList<Point>();
		ArrayList<Point> Res = new ArrayList<Point>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)Math.abs(target_y - start_y);
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.add(new Point(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
						Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b));
				
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.add(new Point(Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].r,Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].g,
					Pixel_Matrix[(int)Math.floor(x0)][(int)Math.floor(y0)].b));
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

		Res = K_Means(Points, 1, 100);
		Dom_Color.r = (int)Res.get(0).x;
		Dom_Color.g = (int)Res.get(0).y;
		Dom_Color.b = (int)Res.get(0).z;

		return Dom_Color;
	}
	public void Image_Rebuild_With_Lines(int Iterations) {
	
		Random x0_picks = new Random();
		Random x1_picks = new Random();
		Random y0_picks = new Random();
		Random y1_picks = new Random();
		
		Color_Palette CSET = new Color_Palette();
		Pixel dominant_color = new Pixel();
		ArrayList<Pixel> Line = new ArrayList<Pixel>();
		Image B = new Image(), C = new Image();
		B.Load_Blank_Canvas(this.Image_Height,this.Image_Width, CSET.Black);
		C.Load_Blank_Canvas(this.Image_Height,this.Image_Width, CSET.Black);

/*	#ifdef Line_StepByStep



		std::stringstream ss;
		std::string via;
		int counter = 0;

	#endif
*/
		int x0, y0, x1, y1;
		double cur_difference, temp_dif;

		cur_difference = this.Image_Difference_Value(B);

		for (int i = 0; i < Iterations; i++) {
			//Runtime.getRuntime().gc();
				
				  x0 = x0_picks.nextInt(Math.abs(Image_Width)); 
				  y0 = y0_picks.nextInt(Math.abs(Image_Height)); 
				  x1 = x1_picks.nextInt(Image_Width);
				  y1 = y1_picks.nextInt(Image_Height);
				 
			//System.out.println("Iter: " + i + " W/H: "+Image_Width +"/ "+Image_Height );
			
			/*
			 * x0 = (int)((double)(Image_Width-1) * Math.random()); y0 =
			 * (int)((double)(Image_Height-1) * Math.random()); x1 =
			 * (int)((double)(Image_Width-1) * Math.random()); y1 =
			 * (int)((double)(Image_Height-1) * Math.random());
			 */
			
			dominant_color = this.Dominant_Color_Via_Line(y0, x0, y1, x1);
			Line = B.Get_Line_Pixels(y0, x0, y1, x1);
			B.Draw_Line(y0, x0, y1, x1, dominant_color);


			temp_dif = this.Image_Difference_Value(B);

			if (temp_dif < cur_difference) {
				C.Draw_Line(y0, x0, y1, x1, dominant_color);
/*	#ifdef Line_StepByStep
				ss << counter;
				via = ss.str();
				if ((counter + 1) % 40 == 0) {
					C.Write_Image(via.c_str());

				}
				ss.str(std::string());
				counter++;


	#endif // Line_StepByStep
*/
				cur_difference = temp_dif;
				

			}
			else {
				B.Register_PixelFrame(Line);
				Line.clear();
				
			}


		}

		C.Write_Image("Build_From_Random_Lines.png");



	}
	public void Image_Convolution(int iterations,String Type,int alter) throws IOException {
		double Conv_Kernel[][] = new double[3][3];
		double Kernel_Normal = 0;
		if (Type.equals("Mean")) {
			Conv_Kernel[0][0] = 1;
			Conv_Kernel[0][1] = 1;
			Conv_Kernel[0][2] = 1;
			Conv_Kernel[1][0] = 1;
			Conv_Kernel[1][1] = 1;
			Conv_Kernel[1][2] = 1;
			Conv_Kernel[2][0] = 1;
			Conv_Kernel[2][1] = 1;
			Conv_Kernel[2][2] = 1;
		}
		else if (Type.equals("Gaussian")) {
			Conv_Kernel[0][0] = 0;
			Conv_Kernel[0][1] = 1;
			Conv_Kernel[0][2] = 0;
			Conv_Kernel[1][0] = 1;
			Conv_Kernel[1][1] = 4;
			Conv_Kernel[1][2] = 1;
			Conv_Kernel[2][0] = 0;
			Conv_Kernel[2][1] = 1;
			Conv_Kernel[2][2] = 0;
		}
		else if (Type.equals("Sobol_X")) {
			Conv_Kernel[0][0] = 1;
			Conv_Kernel[0][1] = 0;
			Conv_Kernel[0][2] = -1;
			Conv_Kernel[1][0] = 2;
			Conv_Kernel[1][1] = 0;
			Conv_Kernel[1][2] = -2;
			Conv_Kernel[2][0] = 1;
			Conv_Kernel[2][1] = 0;
			Conv_Kernel[2][2] = -1;
		}
		else if (Type.equals("Sobol_Y")) {
			Conv_Kernel[0][0] = -1;
			Conv_Kernel[0][1] = -2;
			Conv_Kernel[0][2] = -1;
			Conv_Kernel[1][0] = 0;
			Conv_Kernel[1][1] = 0;
			Conv_Kernel[1][2] = 0;
			Conv_Kernel[2][0] = 1;
			Conv_Kernel[2][1] = 2;
			Conv_Kernel[2][2] = 1;
		}
		else if (Type.equals("Edge_D")) {
			Conv_Kernel[0][0] = -1;
			Conv_Kernel[0][1] = -1;
			Conv_Kernel[0][2] = -1;
			Conv_Kernel[1][0] = -1;
			Conv_Kernel[1][1] =  8;
			Conv_Kernel[1][2] = -1;
			Conv_Kernel[2][0] = -1;
			Conv_Kernel[2][1] = -1;
			Conv_Kernel[2][2] = -1;
		}else {
			Conv_Kernel[0][0] = 0;
			Conv_Kernel[0][1] = 0;
			Conv_Kernel[0][2] = 0;
			Conv_Kernel[1][0] = 0;
			Conv_Kernel[1][1] = 1;
			Conv_Kernel[1][2] = 0;
			Conv_Kernel[2][0] = 0;
			Conv_Kernel[2][1] = 0;
			Conv_Kernel[2][2] = 0;
		}


		int divider =0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Kernel_Normal += Math.abs(Conv_Kernel[i][j]);
				if(Conv_Kernel[i][j] != 0) {
					divider++;
				}
			}
		}
		//Kernel_Normal = divider;
		Image Mid = new Image(this);
		//Mid.Load_Image(this.F_Path);
		Mid.Set_Scale(Image_Height,Image_Width);
		Mid.Image_Width = this.Image_Width;
		Mid.Image_Height = this.Image_Height;
		for (int i = 1; i < Image_Height; i++) {
			for (int j = 1; j < Image_Width; j++) {

				//Mid.Pixel_Matrix[i][j].r = (int)(this.Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
				//Mid.Pixel_Matrix[i][j].g = (int)(this.Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal));
				//Mid.Pixel_Matrix[i][j].b = (int)(this.Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal));
				Mid.singlePixelConvolution(i, j, Conv_Kernel, 3, 3);
				Mid.Pixel_Matrix[i][j].r /= Kernel_Normal;
				Mid.Pixel_Matrix[i][j].g /= Kernel_Normal;
				Mid.Pixel_Matrix[i][j].b /= Kernel_Normal;


			}


		}

		for (int k = 0; k < iterations; k++) {

			for (int i = 1; i < Image_Height; i++) {
				for (int j = 1; j < Image_Width; j++) {

					//if (i >= 1 && j >= 1 && i < this.Image_Height - 1 && j < width - 1) {
					//Mid.Pixel_Matrix[i][j].r = (int)(Mid.Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
					//Mid.Pixel_Matrix[i][j].g = (int)(Mid.Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal));
					//Mid.Pixel_Matrix[i][j].b = (int)(Mid.Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal));
					Mid.singlePixelConvolution(i, j, Conv_Kernel, 3, 3);
					Mid.Pixel_Matrix[i][j].r /= Kernel_Normal;
					Mid.Pixel_Matrix[i][j].g /= Kernel_Normal;
					Mid.Pixel_Matrix[i][j].b /= Kernel_Normal;
					//}
				}


			}

		}


			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					this.Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
				}
			}
			
			if(alter == 1) {
				this.Commint_Matrix_Changes();
			}

	}

	public ArrayList<Point> GetCoordinateFrame(int start_y,int start_x,int target_y,int target_x) {
		double dx, sx, dy, sy, err, e2;
		
		ArrayList<Point> Points = new ArrayList<Point>();
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(Math.abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-Math.abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				Points.add(new Point((int)x0,(int)y0 ,0));
				break;
			}

			Points.add(new Point((int)x0,(int)y0 ,0));

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



		return Points;
	}
	public void Up_Scale() {

		//BufferedImage scaled = new BufferedImage(this.Image_Width * 3,	this.Image_Height * 3,BufferedImage.TYPE_3BYTE_BGR);
		
		
		Image scaled = new Image();
		int p=0,z=0;
		scaled.Load_Blank_Canvas((Image_Height*3), (Image_Width*3), new Pixel(0,0,0));
		for(int i=0;i<scaled.Image_Height;i+=3) {
			for(int j =0 ; j <scaled.Image_Width;j+=3) {
				for(int k =0 ;k<3;k++) {
					for(int m = 0 ; m<3;m++) {
						scaled.Pixel_Matrix[i+k][j+m] = new Pixel(this.Pixel_Matrix[p][z]);
					}
				}
				z++;
			}
			p++;
			z=0;
		}
		



		//quality enchancment


		for (int i = 0; i < this.Image_Height - 3; i += 3) {
			for (int j = 0; j < this.Image_Width - 3; j += 3) {

				if (j < 3) {
					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;
					}

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;

					}
				}

				else {

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;

						scaled.Pixel_Matrix[i + k][j + 3].r = (scaled.Pixel_Matrix[i + k][j + 3].r + scaled.Pixel_Matrix[i + k][j + 2].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].g = (scaled.Pixel_Matrix[i + k][j + 3].g + scaled.Pixel_Matrix[i + k][j + 2].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].b = (scaled.Pixel_Matrix[i + k][j + 3].b + scaled.Pixel_Matrix[i + k][j + 2].b) / 2;

					}


					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;


						scaled.Pixel_Matrix[i + 3][j + k].r = (scaled.Pixel_Matrix[i + 3][j + k].r + scaled.Pixel_Matrix[i + 2][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].g = (scaled.Pixel_Matrix[i + 3][j + k].g + scaled.Pixel_Matrix[i + 2][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].b = (scaled.Pixel_Matrix[i + 3][j + k].b + scaled.Pixel_Matrix[i + 2][j + k].b) / 2;
					}

				}


			}
		}
		this.Pixel_Matrix = scaled.Pixel_Matrix;
		this.IMG=scaled.IMG;
		this.Image_Height *=3;
		this.Image_Width*=3;

	}
	public void Set_Scale(int Height ,int Width) {
	    BufferedImage bi = new BufferedImage(Width, Height, this.IMG.getTransparency() == Transparency.OPAQUE ? BufferedImage.TYPE_INT_RGB : BufferedImage.TYPE_INT_ARGB);
	    Graphics2D g2d = bi.createGraphics();
	    g2d.setRenderingHint(RenderingHints.KEY_INTERPOLATION, RenderingHints.VALUE_INTERPOLATION_BILINEAR); //produces a balanced resizing (fast and decent quality)
	    g2d.drawImage(this.IMG, 0, 0, Width, Height, null);
	    g2d.dispose();
	    this.IMG =bi;
	    this.Image_Height =  Height;
	    this.Image_Width = Width;
	    this.init_pixel_matrix();
	}
	public void Detect_Faces() {
		short flag = 0;
		Color_Palette CSET = new Color_Palette();
		int distance = 0 ,min_d = 355, skin_thresh = 15, grap_thresh = 60;
		float treshold = 45;
		int validation_level = 0;
		int n_valid_bounty = 10;
		Point left_eye = new Point(), right_eye= new Point();
		left_eye.x = right_eye.x = 0;
		left_eye.y = right_eye.y = 0;
		Pixel black = new Pixel();
		Pixel skin_graph= new Pixel(), nose_graph= new Pixel(), forhead_graph = new Pixel(), chin_graph = new Pixel();
		black.r = black.g = black.b = 0;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (flag == 0) {
					if (Pixel_Matrix[i][j].r < treshold  && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold) {
						left_eye.x = j;
						left_eye.y = i;
						flag = 1;
	//#ifdef FaceDebug	



						Draw_Circle(j, i, 3, CSET.Green); //detected eye loctaion -left eye-

	//#endif
					}
				}
				else if (flag == 1) {
					if (distance > Image_Width / 3) {
						break;
					}
					else if (Pixel_Matrix[i][j].r < treshold && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold && distance > 30) {
						right_eye.x = j;
						right_eye.y = i;
						flag = 2;
						//i += 4;
	//#ifdef FaceDebug


						Draw_Circle(j, i, 3, CSET.Red); //detected eye location -right eye
						Draw_Circle((int)left_eye.x, (int)left_eye.y, 3, CSET.Green); //detected eye location -right eye
	//#endif


						//defenition of skin graphs for validation sequance
						skin_graph = Pixel_Matrix[(int)(left_eye.y)][(int)(left_eye.x) + (distance / 2)];
						if ((left_eye.y) + (distance / 2) < Image_Height && (left_eye.x) + (distance / 2) < Image_Width) {
							nose_graph = Pixel_Matrix[(int)(left_eye.y) + (distance / 2)][(int)(left_eye.x) + (distance / 2)];
						}
						if (left_eye.y - (distance / 4) > 0) {
							forhead_graph = Pixel_Matrix[(int)(left_eye.y - (distance / 4))][(int)(left_eye.x) + (distance / 2)];
						}
						if (left_eye.y + 1.3*distance < Image_Height) {
							int temp = (int)1.3*distance;
							chin_graph = Pixel_Matrix[(int)(left_eye.y + (temp))][(int)(left_eye.x) + (distance / 2)];
						}
						//

						//in case skin graph is black -> most likely not a skin color
						if (Color_Distance(black, skin_graph) < 30) {
							flag = 0;
							break;
						}
					}
					distance++;
				}

			}
			if (flag == 2 && distance > 50 && left_eye.x + (distance / 2) < Image_Width &&
				left_eye.y + (distance / 2) < Image_Height &&Color_Distance(Pixel_Matrix[(int)(left_eye.y) + (distance / 2)][(int)(left_eye.x) + (distance / 2)], black) > min_d) {


				skin_graph = Pixel_Matrix[(int)(left_eye.y)][(int)(left_eye.x) + (distance / 2)];

				if (skin_graph.r < 120 && skin_graph.g < 120 && skin_graph.b < 120) {
					continue;
				}






	//#ifdef FaceDebug

				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 3, CSET.Blue); //sking graph location
				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 4, CSET.Red); //sking graph location
				Draw_Circle((int)(left_eye.x) + (distance / 2), (int)(left_eye.y), 2, CSET.Green); //sking graph location

				Draw_Line((int)left_eye.y, (int)left_eye.x, (int)left_eye.y, (int)left_eye.x + distance / 2, CSET.Black); // line to cetner point 
	//#endif
				if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye.y + distance / 2][(int)left_eye.x]) < grap_thresh) {

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye.y + distance / 2][(int)left_eye.x]) < skin_thresh) { // left chick cmp

						validation_level++; //level 1

						if (Distance_Neighbors(treshold, (int)left_eye.y + distance / 2, (int)left_eye.x)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated --Neighbor-- left chick: " + validation_level);

						}
	//#ifdef FaceDebug
						Draw_Circle((int)(left_eye.x), (int)(left_eye.y) + (distance / 2), 3, CSET.White); //chick graph location -left eye-
						Draw_Line((int)left_eye.y, (int)left_eye.x, (int)left_eye.y + distance / 2, (int)left_eye.x, CSET.White); // line to chick point -left eye-
						System.out.println("Validated left chick: " + validation_level);
	//#endif // FaceDebug


					}

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)right_eye.y + distance / 2][(int)right_eye.x]) < skin_thresh) {//right chick
						validation_level++; //level 2
						System.out.println("Validated Right chick: " + validation_level);

						if (Distance_Neighbors(treshold, (int)right_eye.y + distance / 2, (int)right_eye.x)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- right chick: " + validation_level);

						}

					}



					if (Color_Distance(skin_graph, forhead_graph) < grap_thresh) { //forhead vs skin center cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)left_eye.y - (distance / 4), 3, CSET.White); //at forhead
						Draw_Line((int)left_eye.y, (int)left_eye.x + distance / 2, (int)left_eye.y - (distance / 4), (int)left_eye.x + distance / 2, CSET.White);

	//#endif
						validation_level++; //level 3
						System.out.println("Validated Forhead - Center: " + validation_level );

						if (Distance_Neighbors(treshold, (int)left_eye.y - (distance / 4), (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Forhead - Center: "+validation_level);

						}

					}





					if (Color_Distance(nose_graph, skin_graph) < grap_thresh) {//nose vs middle face cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)left_eye.y + distance / 2, 3, CSET.White);
						//Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y + (distance / 2), 'W');

	//#endif
						validation_level++; //level 4
						System.out.println("Validated Nose - Center: " + validation_level );

						if (Distance_Neighbors(treshold, (int)left_eye.y + distance / 2, (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Nose - Center: " + validation_level);

						}
					}


					if (Color_Distance(chin_graph, skin_graph) < grap_thresh) {//chin vs middle face cmp
	//#ifdef FaceDebug
						Draw_Circle((int)left_eye.x + distance / 2, (int)(left_eye.y + 1.3*distance), 3, CSET.White);
						Draw_Line((int)left_eye.y, (int)left_eye.x + distance / 2, (int)(left_eye.y + 1.3*(distance)), (int)left_eye.x + distance / 2, CSET.White);

	//#endif
						validation_level++; //level 5
						System.out.println("Validated Chin - Center: " + validation_level);

						if (Distance_Neighbors(treshold, (int)left_eye.y + (int)(1.3*distance), (int)left_eye.x + distance / 2)) {
							validation_level += n_valid_bounty;
							System.out.println("Validated  --Neighbor-- Chin - Center: " + validation_level);

						}
					}





	//#ifdef FaceDebug




					//right eye validate for v2 yet to be added to calculation
					Draw_Line((int)right_eye.y, (int)right_eye.x, (int)right_eye.y, (int)right_eye.x - distance / 2, CSET.Black); // line to cetner point from -right eye-
					Draw_Circle((int)(right_eye.x), (int)(right_eye.y) + (distance / 2), 3, CSET.White); //chick graph location -right eye- 
					Draw_Line((int)right_eye.y, (int)right_eye.x, (int)right_eye.y + distance / 2, (int)right_eye.x, CSET.White); // line to chick point -right eye-

	//#endif

					if (validation_level >= 30) {
						Draw_Square((int)left_eye.x + distance / 2, (int)left_eye.y + distance / 2, distance, distance, CSET.Red);
						i += 4;
						validation_level = 0;
					}

				}

				flag = 0;
				distance = 0;
			}
			else {
				flag = 0;
				distance = 0;
			}

		}

		
		
		
		
		
		
	}
	

	
	
	




}





	
class LibCharacters {
	
	

	//UpperCase
	int[] Letter_A;
	
	
	
	
	

	
	

	
	int[] Letter_B;
	int[] Letter_C;
	int[] Letter_D;
	int[] Letter_E;
	int[] Letter_F;
	int[] Letter_G;
	int[] Letter_H;
	int[] Letter_I;
	int[] Letter_J;
	int[] Letter_K;
	int[] Letter_L;
	int[] Letter_M;
	int[] Letter_N;
	int[] Letter_O;
	int[] Letter_P;
	int[] Letter_Q;
	int[] Letter_R;
	int[] Letter_S;
	int[] Letter_T;
	int[] Letter_U;
	int[] Letter_V;
	int[] Letter_W;
	int[] Letter_X;
	int[] Letter_Y;
	int[] Letter_Z;

	//Numbers
	int[] Number_Zero;
	int[] Number_One;
	int[] Number_Two;
	int[] Number_Three;
	int[] Number_Four;
	int[] Number_Five;
	int[] Number_Six;
	int[] Number_Seven;
	int[] Number_Eight;
	int[] Number_Nine;

	//Symbols
	int[] Exclamation_Point;
	int[] Quesiton_Mark;
	int[] Right_Braket;
	int[] Left_Braket;
	int[] Ampersand;
	int[] Comma;
	int[] Squaure_Braket_Left;
	int[] Square_Braket_Right;
	int[] Colon;
	int[] Semi_Colon;
	int[] EqualSign;
	int[] PlusSign;
	int[] Precent;
	int[] Astersik;
	int[] Dot;

	public LibCharacters(){
		this.Letter_A =
				new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,0,1,1,1,0,0,0,
			  0,0,1,1,0,1,1,0,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,1,1,1,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,0,0,0,0,0,0,0,0
			};
		
		
		this.Letter_B = new int[] 
					{ 0,0,0,0,0,0,0,0,0,
					  0,0,1,1,1,1,1,0,0,
					  0,0,1,1,0,0,1,1,0,
					  0,0,1,1,0,0,1,1,0,
					  0,0,1,1,1,1,1,0,0,
					  0,0,1,1,0,0,1,1,0,
					  0,0,1,1,0,0,1,1,0,
					  0,0,1,1,1,1,1,0,0,
					  0,0,0,0,0,0,0,0,0
					};
		
		
		this.Letter_C = 	new int[]
					{ 0,0,0,0,0,0,0,0,0,
					  0,0,1,1,1,1,1,0,0,
					  0,1,1,1,0,0,1,1,0,
					  0,1,1,0,0,0,0,0,0,
					  0,1,1,0,0,0,0,0,0,
					  0,1,1,0,0,0,0,0,0,
					  0,1,1,1,0,0,1,1,0,
					  0,0,1,1,1,1,1,0,0,
					  0,0,0,0,0,0,0,0,0
					};
		
		
		this.Letter_D = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_E = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_F = new int[]
						{ 0,0,0,0,0,0,0,0,0,
						  0,1,1,1,1,1,1,0,0,
						  0,1,1,0,0,0,0,0,0,
						  0,1,1,0,0,0,0,0,0,
						  0,1,1,1,1,1,1,0,0,
						  0,1,1,0,0,0,0,0,0,
						  0,1,1,0,0,0,0,0,0,
						  0,1,1,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0
						};
		this.Letter_G = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,1,1,1,1,0,
				  0,1,1,0,0,1,1,1,0,
				  0,0,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_H = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,1,1,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_I = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_J = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,1,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_K = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,1,1,0,0,
				  0,1,1,0,1,1,0,0,0,
				  0,1,1,1,1,0,0,0,0,
				  0,1,1,0,1,1,0,0,0,
				  0,1,1,0,0,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_L = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_M = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,0,1,1,1,0,
				  0,1,1,1,1,1,1,1,0,
				  0,1,1,0,1,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_N = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,0,0,1,1,0,
				  0,1,1,1,1,0,1,1,0,
				  0,1,1,0,1,1,1,1,0,
				  0,1,1,0,0,1,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_O = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_P = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_Q = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,1,1,1,1,1,0,0,
				  0,0,0,0,0,1,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_R = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,0,0,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_S = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,1,1,1,0,
				  0,0,1,1,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,1,1,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_T = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_U = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,1,0,1,1,1,0,
				  0,0,1,1,1,1,1,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_V = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,1,1,0,1,1,0,0,
				  0,0,0,1,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_W = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,1,0,1,1,0,
				  0,1,1,1,1,1,1,1,0,
				  0,1,1,1,0,1,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_X = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,1,1,0,1,1,0,0,
				  0,0,0,1,1,1,0,0,0,
				  0,0,1,1,0,1,1,0,0,
				  0,1,1,0,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_Y = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,1,1,0,0,1,1,0,
				  0,0,1,1,0,0,1,1,0,
				  0,0,1,1,0,0,1,1,0,
				  0,0,0,1,1,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Letter_Z = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,1,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,1,1,0,0,0,0,0,
				  0,1,1,1,1,1,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		
		//Numbers
		
		
	this.Number_Zero = new int[]	
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,0,0,1,1,1,0,
			  0,1,1,0,1,0,1,1,0,
			  0,1,1,1,0,0,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_One = new int[]	
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,1,1,1,0,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Two = new int[]	
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,1,1,1,1,0,0,
			  0,0,1,1,0,0,0,0,0,
			  0,0,1,1,0,0,0,0,0,
			  0,0,1,1,1,1,1,1,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Three = new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,1,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,0,0,0,1,1,0,
			  0,1,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Four = new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,0,0,1,1,1,0,0,
			  0,0,0,1,1,1,1,0,0,
			  0,0,1,1,0,1,1,0,0,
			  0,1,1,0,0,1,1,0,0,
			  0,1,1,1,1,1,1,0,0,
			  0,0,0,0,0,1,1,0,0,
			  0,0,0,0,0,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Five = new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,1,1,1,1,1,1,0,
			  0,0,1,1,0,0,0,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,0,0,0,0,1,1,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Six = new int[]	
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,0,0,1,1,1,0,0,
			  0,0,0,1,1,0,0,0,0,
			  0,0,1,1,0,0,0,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,1,1,0,0,1,1,0,
			  0,0,1,1,0,0,1,1,0,
			  0,0,0,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Seven = new int[]	
			{ 0,0,0,0,0,0,0,0,0,
			  0,1,1,1,1,1,1,0,0,
			  0,0,0,0,0,1,1,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,0,1,1,0,0,0,0,
			  0,0,0,1,1,0,0,0,0,
			  0,0,0,1,1,0,0,0,0,
			  0,0,0,1,1,0,0,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Eight = new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,0,1,1,1,1,1,0,0,
			  0,1,1,0,0,0,1,1,0,
			  0,1,1,0,0,0,1,1,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,0,0,0,0
			};
	this.Number_Nine = new int[]
			{ 0,0,0,0,0,0,0,0,0,
			  0,0,1,1,1,1,0,0,0,
			  0,1,1,0,0,1,1,0,0,
			  0,1,1,0,0,1,1,0,0,
			  0,0,1,1,1,1,1,0,0,
			  0,0,0,0,0,1,1,0,0,
			  0,0,0,0,1,1,0,0,0,
			  0,0,1,1,1,0,0,0,0,
			  0,0,0,0,0,0,0,0,0
			};

		this.Exclamation_Point = new int[]			
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		
		this.Quesiton_Mark = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,1,1,1,1,1,0,0,
				  0,1,0,0,0,0,1,1,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Right_Braket = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Left_Braket = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,1,1,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,0,0,
				  0,0,1,1,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Ampersand = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,0,1,1,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Precent = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,0,0,0,0,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,1,1,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,1,1,0,0,1,1,0,
				  0,1,1,0,0,0,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Comma = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Dot = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,1,1,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Squaure_Braket_Left = new int[]
				{ 0,0,0,0,0,0,0,0,0,
				  0,1,1,1,0,0,0,0,0,
				  0,1,0,0,0,0,0,0,0,
				  0,1,0,0,0,0,0,0,0,
				  0,1,0,0,0,0,0,0,0,
				  0,1,0,0,0,0,0,0,0,
				  0,1,0,0,0,0,0,0,0,
				  0,1,1,1,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Square_Braket_Right = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,1,1,1,0,
				  0,0,0,0,0,0,0,1,0,
				  0,0,0,0,0,0,0,1,0,
				  0,0,0,0,0,0,0,1,0,
				  0,0,0,0,0,0,0,1,0,
				  0,0,0,0,0,0,0,1,0,
				  0,0,0,0,0,1,1,1,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Colon = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.Semi_Colon = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,1,1,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		
		this.PlusSign = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,1,1,1,1,1,1,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,1,1,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		this.EqualSign = new int[]	
				{ 0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,1,0,
				  0,1,1,1,1,1,1,1,0,
				  0,0,0,0,0,0,0,0,0,
				  0,1,1,1,1,1,1,1,0,
				  0,1,1,1,1,1,1,1,0,
				  0,0,0,0,0,0,0,0,0,
				  0,0,0,0,0,0,0,0,0
				};
		
		this.Astersik = new int[]	
						{ 0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,
						  0,0,0,0,1,0,0,0,0,
						  0,0,0,1,1,1,0,0,0,
						  0,0,1,1,1,1,1,0,0,
						  0,0,0,1,1,1,0,0,0,
						  0,0,0,0,1,0,0,0,0,
						  0,0,0,0,0,0,0,0,0,
						  0,0,0,0,0,0,0,0,0
						};
	}
}


	
