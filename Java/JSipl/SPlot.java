package JSipl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;

public class SPlot extends Image {
	public double Last_Known_Max_X;
	public double Last_Known_Max_Y;
	public double Last_Known_Min_X;
	public double Last_Known_Min_Y;
	public void Show_Bar_Plot(ArrayList<Integer> data, ArrayList<String> Categories) {
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		double max_y = tlb.getMax_From_ArrayList(data);
		int spaces = 400 / data.size();
		spaces+=10;
		double divider = 1;

		if(max_y >= 400) {
		 divider = (int)max_y/400;
		}else {
			divider =  1/((double)400/max_y);
		}
		Image histo = new Image();
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100,100,500,640,CSET.Black,"Corners");
		histo.Draw_Square(99,99,501,641,CSET.Black,"Corners");
		histo.Draw_Square(98,98,502,642,CSET.Black,"Corners");
		
		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		histo.Draw_Text(102, 40, String.valueOf(max_y), CSET.Black);
		for(int i = 0; i <= 400; i+=101) {
			histo.Draw_Line(501-(i), 100 , 501-(i) , 92, CSET.Black);

		}
		histo.Draw_Text(400, 40, String.valueOf((max_y/100)*25), CSET.Black);
		histo.Draw_Text(299, 40, String.valueOf((max_y/100)*50), CSET.Black);
		histo.Draw_Text(198, 40, String.valueOf((max_y/100)*75), CSET.Black);

		
		
		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);
		
		for(int i = 0; i <=400;i+=spaces) {
			histo.Draw_Line(499, 108 + i , 499+10 , 108+i, CSET.Black);

		}
		int n=0;
		for(int i = 0; i <400 ;i+=spaces) {
			if(n<Categories.size()) {
			histo.Draw_Text(520, 108 + i, Categories.get(n), CSET.Black);
			n++;
			}else {
				histo.Draw_Text(520, 108 + i, " ", CSET.Black);

			}
		}
		int j =0,k=0;
		n=0;
		for(int i = 0;i<400 && j <data.size();i+=spaces) {
				Pixel rc = CSET.Get_Random_Color();
				rc.r=30;
			histo.Draw_Line(499, 109 + i , 499-(int)(data.get(j)/divider) , 109 + i, rc);
			histo.Draw_Line(499, 108 + i , 499-(int)(data.get(j)/divider) , 108 + i, rc);
			histo.Draw_Line(499, 107 + i , 499-(int)(data.get(j)/divider) , 107 + i, rc);
			j++;		
		}

		histo.Draw_Text(90, 345, "BAR PLOT", CSET.Black);

			
		
			
		
		
		histo.Show_Image();
		//histo.Write_Image("BarPlot" + ".png");
	}
	public void Write_Bar_Plot(ArrayList<Integer> data, ArrayList<String> Categories) {
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		double max_y = tlb.getMax_From_ArrayList(data);
		int spaces = 400 / data.size();
		double divider = 1;

		if(max_y >= 400) {
		 divider = (int)max_y/400;
		}else {
			divider =  1/((double)400/max_y);
		}
		Image histo = new Image();
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100,100,500,640,CSET.Black,"Corners");
		histo.Draw_Square(99,99,501,641,CSET.Black,"Corners");
		histo.Draw_Square(98,98,502,642,CSET.Black,"Corners");
		
		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		histo.Draw_Text(102, 40, String.valueOf(max_y), CSET.Black);
		for(int i = 0; i <= 400; i+=101) {
			histo.Draw_Line(501-(i), 100 , 501-(i) , 92, CSET.Black);

		}
		histo.Draw_Text(400, 40, String.valueOf((max_y/100)*25), CSET.Black);
		histo.Draw_Text(299, 40, String.valueOf((max_y/100)*50), CSET.Black);
		histo.Draw_Text(198, 40, String.valueOf((max_y/100)*75), CSET.Black);

		
		
		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);
		
		for(int i = 0; i <=400;i+=spaces) {
			histo.Draw_Line(499, 108 + i , 499+10 , 108+i, CSET.Black);

		}
		int n=0;
		for(int i = 0; i <400 ;i+=spaces) {
			if(n<Categories.size()) {
			histo.Draw_Text(520, 108 + i, Categories.get(n), CSET.Black);
			n++;
			}else {
				histo.Draw_Text(520, 108 + i, " ", CSET.Black);

			}
		}
		int j =0;
		for(int i = 0;i<400 && j <data.size();i+=spaces) {
			Pixel rc = CSET.Get_Random_Color();
			rc.r=30;
		histo.Draw_Line(499, 108 + i , 499-(int)(data.get(j)/divider) , 108 + i, rc);
		histo.Draw_Line(499, 107 + i , 499-(int)(data.get(j)/divider) , 107 + i, rc);
		j++;		
	}

		histo.Draw_Text(90, 345, "BAR PLOT", CSET.Black);

			
		
			
		
		
		histo.Write_Image("BarPlot" + ".png");
	}
	public void Write_Histogram(Image source,String Channel,String output_name) {
		int xxR[] = new int[256];
		int xxG[] = new int[256];
		int xxB[] = new int[256];
		Math_Toolbox tlb = new Math_Toolbox();
		Arrays.fill(xxR, 0);
		Arrays.fill(xxG, 0);
		Arrays.fill(xxB, 0);
		//ArrayList<Integer> xxG = new ArrayList<Integer>(Collections.nCopies(255, 0));
		//ArrayList<Integer> xxB = new ArrayList<Integer>(Collections.nCopies(255, 0));
		int max_y = source.Image_Height*source.Image_Width;
		int max_val=Integer.MIN_VALUE;
		int Multiplyer=1;
		Color_Palette CSET = new Color_Palette();
		for(int i =0;i<source.Image_Height;i++) {
			for(int j =0;j<source.Image_Width;j++) {
				xxR[source.Pixel_Matrix[i][j].r]++;
				xxG[source.Pixel_Matrix[i][j].g]++;
				xxB[source.Pixel_Matrix[i][j].b]++;

			}
		}

		for(int i = 0 ;i<256;i++) {
			if(xxR[i] > max_val) {
				max_val = xxR[i];
			}
			if(xxG[i] > max_val) {
				max_val = xxG[i];
			}
			if(xxB[i] > max_val) {
				max_val = xxB[i];
			}
		}
		while(max_val * Multiplyer < max_y) {
			
			if((Multiplyer+1)*max_val > max_y ) {
				break;
			}else {
				Multiplyer++;
			}
		}
		
		Image histo = new Image();
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100,100,500,640,CSET.Black,"Corners");
		histo.Draw_Square(99,99,501,641,CSET.Black,"Corners");
		histo.Draw_Square(98,98,502,642,CSET.Black,"Corners");
		
		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		for(int i = 0; i <= 400; i+=101) {
			histo.Draw_Line(501-(i), 100 , 501-(i) , 92, CSET.Black);

		}
		histo.Draw_Text(400, 40, String.valueOf(((max_y/Multiplyer)/100)*25), CSET.Black);
		histo.Draw_Text(299, 40, String.valueOf(((max_y/Multiplyer)/100)*50), CSET.Black);
		histo.Draw_Text(198, 40, String.valueOf(((max_y/Multiplyer)/100)*75), CSET.Black);
		histo.Draw_Text(102, 40, String.valueOf(max_y/Multiplyer), CSET.Black);

		
		
		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);
		
		for(int i = 0; i <=512;i+=64) {
			histo.Draw_Line(499, 108 + i , 499+10 , 108+i, CSET.Black);

		}
		for(int i = 512; i >=0;i-=64) {
			histo.Draw_Text(520, 108 + i, String.valueOf(i/2), CSET.Black);
		}
		
		if(Channel.equals("Red")) {
			histo.Draw_Text(90, 345, "RED HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Red);

			}
			
		}
		else if(Channel.equals("Green")) {
			histo.Draw_Text(90, 345, "GREEN HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Green);
			}
			
		}else if(Channel.equals("Blue")) {
			histo.Draw_Text(90, 345, "BLUE HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Blue);

			}
			
		}
		else if(Channel.equals("RGB")) {
			histo.Draw_Text(90, 345, "RGB HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Red);

				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Green);

				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Blue);

			}
			
		}
			
		
		
		
		histo.Write_Image(output_name + ".png");
	}
	public void Show_Histogram(Image source,String Channel,String output_name) {
		int xxR[] = new int[256];
		int xxG[] = new int[256];
		int xxB[] = new int[256];
		Arrays.fill(xxR, 0);
		Arrays.fill(xxG, 0);
		Arrays.fill(xxB, 0);
		Math_Toolbox tlb = new Math_Toolbox();
		//ArrayList<Integer> xxG = new ArrayList<Integer>(Collections.nCopies(255, 0));
		//ArrayList<Integer> xxB = new ArrayList<Integer>(Collections.nCopies(255, 0));
		int max_y = source.Image_Height*source.Image_Width;
		int Multiplyer = 1;
		int max_val=Integer.MIN_VALUE;
		
		Color_Palette CSET = new Color_Palette();
		for(int i =0;i<source.Image_Height;i++) {
			for(int j =0;j<source.Image_Width;j++) {
				xxR[source.Pixel_Matrix[i][j].r]++;
				xxG[source.Pixel_Matrix[i][j].g]++;
				xxB[source.Pixel_Matrix[i][j].b]++;

			}
		}
	
		for(int i = 0 ;i<256;i++) {
			if(xxR[i] > max_val) {
				max_val = xxR[i];
			}
			if(xxG[i] > max_val) {
				max_val = xxG[i];
			}
			if(xxB[i] > max_val) {
				max_val = xxB[i];
			}
		}
		while(max_val * Multiplyer < max_y) {
			
			if((Multiplyer+1)*max_val > max_y ) {
				break;
			}else {
				Multiplyer++;
			}
		}
		
		Image histo = new Image();
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100,100,500,640,CSET.Black,"Corners");
		histo.Draw_Square(99,99,501,641,CSET.Black,"Corners");
		histo.Draw_Square(98,98,502,642,CSET.Black,"Corners");
		
		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		for(int i = 0; i <= 400; i+=101) {
			histo.Draw_Line(501-(i), 100 , 501-(i) , 92, CSET.Black);

		}
		histo.Draw_Text(400, 40, String.valueOf(((max_y/Multiplyer)/100)*25), CSET.Black);
		histo.Draw_Text(299, 40, String.valueOf(((max_y/Multiplyer)/100)*50), CSET.Black);
		histo.Draw_Text(198, 40, String.valueOf(((max_y/Multiplyer)/100)*75), CSET.Black);
		histo.Draw_Text(102, 40, String.valueOf(max_y/Multiplyer), CSET.Black);

		
		
		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);
		
		for(int i = 0; i <=512;i+=64) {
			histo.Draw_Line(499, 108 + i , 499+10 , 108+i, CSET.Black);

		}
		for(int i = 512; i >=0;i-=64) {
			histo.Draw_Text(520, 108 + i, String.valueOf(i/2), CSET.Black);
		}
		
		if(Channel.equals("Red")) {
			histo.Draw_Text(90, 345, "RED HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Red);

			}
			
		}
		else if(Channel.equals("Green")) {
			histo.Draw_Text(90, 345, "GREEN HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Green);
			}
			
		}else if(Channel.equals("Blue")) {
			histo.Draw_Text(90, 345, "BLUE HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Blue);

			}
			
		}
		else if(Channel.equals("RGB")) {
			histo.Draw_Text(90, 345, "RGB HISTOGRAM", CSET.Black);
			for(int i =0;i<512;i+=2) {
				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxR[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Red);

				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxG[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Green);

				histo.Draw_Line(499, 108 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i , 499-(int)tlb.Remap(xxB[i/2], 0, max_y, 0, 399*Multiplyer) , 107 + i, CSET.Blue);

			}
			
		}
			
		
		
		
		histo.Show_Image();
	}
	public void Show_Scatter_Plot(ArrayList<Point> data,String X_Label,String Y_Label) {
		Image Scatter_Plot = new Image();
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		double Max_X = Double.MIN_VALUE,Max_Y = Double.MIN_VALUE;
		double Min_X = Double.MAX_VALUE,Min_Y = Double.MAX_VALUE;

		for(int i = 0 ;i<data.size();i++) {
			if(data.get(i).x > Max_X) {
				Max_X = data.get(i).x;
			}
			if(data.get(i).x < Min_X) {
				Min_X = data.get(i).x;
			}
			if(data.get(i).y > Max_Y) {
				Max_Y = data.get(i).y;
			}
			if(data.get(i).y < Min_Y) {
				Min_Y = data.get(i).y;
			}
		}
		Max_X+=Max_X/4;
		Max_Y+=Max_Y/4;
		
		Max_X = Math.round(Max_X);
		Max_Y = Math.round(Max_Y);

		
		Scatter_Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
		Scatter_Plot.Draw_Square(75, 100, 575, 725, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(74, 99, 576, 726, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(73, 98, 577, 727, CSET.Black, "Corners");
		Scatter_Plot.Draw_Text(325, 750, Y_Label, CSET.Black);
		Scatter_Plot.Draw_Text(65, 400, X_Label, CSET.Black);
		double distX = (Math.abs(Min_X)+Math.abs(Max_X))/4;
		double distY = (Math.abs(Min_Y)+Math.abs(Max_Y))/4;

		Scatter_Plot.Draw_Text(595, 90 + 0 * 78*2,String.format("%.2f",((Min_X))), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 1 * 78*2,String.format("%.2f",((Min_X)+distX*1)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 2 * 78*2,String.format("%.2f",((Min_X)+distX*2)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 3 * 78*2,String.format("%.2f",((Min_X)+distX*3)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 4 * 78*2,String.format("%.2f",((Max_X))), CSET.Black);

		Scatter_Plot.Draw_Text(575 - 0 * 62*2, 40,String.format("%.2f",(Min_Y)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 1 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*1)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 2 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*2)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 3 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*3)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 4 * 62*2, 40,String.format("%.2f",((Max_Y))), CSET.Black);


		for(int i = 0 ;i<5;i++) {
			Scatter_Plot.Draw_Line(575 - 62 * i*2,100,575 - 62 * i*2,90,CSET.Black);
			
			Scatter_Plot.Draw_Line(575,100 + i * 78*2 ,575 + 10,100 + i * 78*2,CSET.Black);
			Scatter_Plot.Draw_Line(575,99 + i * 78*2 ,575 + 10,99 + i * 78*2,CSET.Black);



		}
		
		double tx,ty;
		Point b;
		Scatter_Plot.Update_Pixel_Matrix();
		for(int i = 0 ;i<data.size();i++) {
			b = data.get(i);
			tx = tlb.Remap((float)b.x, (float)Min_X, (float)Max_X, 105, 720 );
			ty = tlb.Remap((float)b.y, (float)(Min_Y), (float)Max_Y, 565, 80);
			
			Scatter_Plot.Draw_Circle((int)tx, (int)ty, 3, CSET.Royal_Blue,"Fill");
			Scatter_Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke);


		
		}
		
		Scatter_Plot.Commint_Matrix_Changes();

		
		
		Scatter_Plot.Show_Image();
		
	}
	public Image Get_Scatter_Plot(ArrayList<Point> data,String X_Label,String Y_Label) {
		Image Scatter_Plot = new Image();
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		double Max_X = Double.MIN_VALUE,Max_Y = Double.MIN_VALUE;
		double Min_X = Double.MAX_VALUE,Min_Y = Double.MAX_VALUE;

		for(int i = 0 ;i<data.size();i++) {
			if(data.get(i).x > Max_X) {
				Max_X = data.get(i).x;
			}
			if(data.get(i).x < Min_X) {
				Min_X = data.get(i).x;
			}
			if(data.get(i).y > Max_Y) {
				Max_Y = data.get(i).y;
			}
			if(data.get(i).y < Min_Y) {
				Min_Y = data.get(i).y;
			}
		}
		Max_X+=Max_X/4;
		Max_Y+=Max_Y/4;
		Max_X = Math.round(Max_X);
		Max_Y = Math.round(Max_Y);
		Scatter_Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
		Scatter_Plot.Draw_Square(75, 100, 575, 725, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(74, 99, 576, 726, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(73, 98, 577, 727, CSET.Black, "Corners");
		Scatter_Plot.Draw_Text(325, 750, Y_Label, CSET.Black);
		Scatter_Plot.Draw_Text(65, 400, X_Label, CSET.Black);
		double distX = (Math.abs(Min_X)+Math.abs(Max_X))/4;
		double distY = (Math.abs(Min_Y)+Math.abs(Max_Y))/4;

		Scatter_Plot.Draw_Text(595, 90 + 0 * 78*2,String.format("%.2f",((Min_X))), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 1 * 78*2,String.format("%.2f",((Min_X)+distX*1)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 2 * 78*2,String.format("%.2f",((Min_X)+distX*2)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 3 * 78*2,String.format("%.2f",((Min_X)+distX*3)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 4 * 78*2,String.format("%.2f",((Max_X))), CSET.Black);

		Scatter_Plot.Draw_Text(575 - 0 * 62*2, 40,String.format("%.2f",(Min_Y)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 1 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*1)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 2 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*2)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 3 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*3)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 4 * 62*2, 40,String.format("%.2f",((Max_Y))), CSET.Black);


		this.Last_Known_Max_X=Max_X;
		this.Last_Known_Max_Y=Max_Y;
		this.Last_Known_Min_X=Min_X;
		this.Last_Known_Min_X=Min_Y;

		for(int i = 0 ;i<5;i++) {
			Scatter_Plot.Draw_Line(575 - 62 * i*2,100,575 - 62 * i*2,90,CSET.Black);
			
			Scatter_Plot.Draw_Line(575,100 + i * 78*2 ,575 + 10,100 + i * 78*2,CSET.Black);
			Scatter_Plot.Draw_Line(575,99 + i * 78*2 ,575 + 10,99 + i * 78*2,CSET.Black);



		}
		double tx,ty;
		Point b;
		Scatter_Plot.Update_Pixel_Matrix();
		for(int i = 0 ;i<data.size();i++) {
			b = data.get(i);
			tx = tlb.Remap((float)b.x, (float)Min_X, (float)Max_X, 105, 720 );
			ty = tlb.Remap((float)b.y, (float)Min_Y, (float)Max_Y, 565, 80);
			
			Scatter_Plot.Draw_Circle((int)tx, (int)ty, 3, CSET.Royal_Blue,"Fill");
			Scatter_Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke);


		
		}
		
		Scatter_Plot.Commint_Matrix_Changes();

		
		
		return Scatter_Plot;
		
	}
	public Image Get_Scatter_Plot(String X_Label,String Y_Label,double Max_X_Value,double Max_Y_Value) {
		Image Scatter_Plot = new Image();
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		double Max_X = Max_X_Value;
		double Max_Y = Max_Y_Value;
		double Min_X = 0;
		double Min_Y = 0;
		
		Max_X+=Max_X/4;
		Max_Y+=Max_Y/4;
		Max_X = Math.round(Max_X);
		Max_Y = Math.round(Max_Y);
		Scatter_Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
		Scatter_Plot.Draw_Square(75, 100, 575, 725, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(74, 99, 576, 726, CSET.Black, "Corners");
		Scatter_Plot.Draw_Square(73, 98, 577, 727, CSET.Black, "Corners");
		Scatter_Plot.Draw_Text(325, 750, Y_Label, CSET.Black);
		Scatter_Plot.Draw_Text(65, 400, X_Label, CSET.Black);
		double distX = (Math.abs(Min_X)+Math.abs(Max_X))/4;
		double distY = (Math.abs(Min_Y)+Math.abs(Max_Y))/4;

		Scatter_Plot.Draw_Text(595, 90 + 0 * 78*2,String.format("%.2f",((Min_X))), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 1 * 78*2,String.format("%.2f",((Min_X)+distX*1)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 2 * 78*2,String.format("%.2f",((Min_X)+distX*2)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 3 * 78*2,String.format("%.2f",((Min_X)+distX*3)), CSET.Black);
		Scatter_Plot.Draw_Text(595, 99 + 4 * 78*2,String.format("%.2f",((Max_X))), CSET.Black);

		Scatter_Plot.Draw_Text(575 - 0 * 62*2, 40,String.format("%.2f",(Min_Y)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 1 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*1)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 2 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*2)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 3 * 62*2, 40,String.format("%.2f",((Min_Y)+distY*3)), CSET.Black);
		Scatter_Plot.Draw_Text(575 - 4 * 62*2, 40,String.format("%.2f",((Max_Y))), CSET.Black);


		for(int i = 0 ;i<5;i++) {
			Scatter_Plot.Draw_Line(575 - 62 * i*2,100,575 - 62 * i*2,90,CSET.Black);
			
			Scatter_Plot.Draw_Line(575,100 + i * 78*2 ,575 + 10,100 + i * 78*2,CSET.Black);
			Scatter_Plot.Draw_Line(575,99 + i * 78*2 ,575 + 10,99 + i * 78*2,CSET.Black);



		}
		Scatter_Plot.Update_Pixel_Matrix();

		
		
		return Scatter_Plot;
		
	}
	public void Add_Point_Scatter_Plot(Image Plot,int Radius,Pixel Color,double X_pos,double Y_pos) {
		double tx,ty;
		Color_Palette CSET = new Color_Palette();
		Math_Toolbox tlb = new Math_Toolbox();
		Plot.Update_Pixel_Matrix();
			tx = tlb.Remap((float)X_pos, (float)this.Last_Known_Min_X, (float)this.Last_Known_Max_X, 105, 720 );
			ty = tlb.Remap((float)Y_pos, (float)this.Last_Known_Min_Y, (float)this.Last_Known_Max_Y, 565, 80);
			
			Plot.Draw_Circle((int)tx, (int)ty, Radius+1, CSET.White_Smoke,"Fill");
			Plot.Draw_Circle((int)tx, (int)ty, Radius, Color,"Fill");

			Plot.Commint_Matrix_Changes();
	}
	public void Show_Pie_Plot(double Sizes[],ArrayList<String> Labels) {
		if(Labels.size() != Sizes.length) {
			System.out.println("Number Of Labels And Number Of Sizes Do Not Match");
			return;
		}
		int sum_of_sizes = 0;
		for(int i =0;i<Sizes.length;i++) {
			sum_of_sizes+=Sizes[i];
		}
		if(sum_of_sizes != 100) {
			System.out.println("Total Sum Of Sizes Has To Be 100");
			return;
		}
		
		
		Color_Palette CSET = new Color_Palette();
		Pixel Colors[] = new Pixel[Sizes.length];
		Random rand = new Random();

		for(int i =0;i<Sizes.length;i++) {
			Colors[i] = CSET.Color_Serial_Number[10+i];
			
		}
		Image Pie = new Image();
		int divider = Sizes.length;
		
		Pie.Load_Blank_Canvas(1200,1600,new Pixel(240,240,240));
		
		
		
		double l_start=0;
		for(int j = 0 ;j<Sizes.length;j++) {
			for(double i =l_start;i<=l_start+(Sizes[j]*3.6);i+=0.001) {
				Pie.Draw_Line(600, 600, 600 +(int)Math.round(400 * Math.sin(Math.toRadians(-i))), 600+(int)Math.round((400 * Math.cos(Math.toRadians(-i)))), Colors[j]);
			}
			l_start+=(Sizes[j]*3.6);
		}
		
		Pie.Set_Scale(600, 800);
		 l_start=0;
		for(int j = 0 ;j<Sizes.length;j++) {
				//Pie.Draw_Line(600, 600, 600 +(int)Math.round(400 * Math.sin(Math.toRadians(-i))), 600+(int)Math.round((400 * Math.cos(Math.toRadians(-i)))), Colors[j]);
			
			Pie.Draw_Text(300 + (int)(162 *Math.sin(Math.toRadians(-(l_start+(Sizes[j]*3.6)/2)))), 300 + (int)(162 *Math.cos(Math.toRadians(-(l_start+(Sizes[j]*3.6)/2)))),String.format("%.2f", Sizes[j])+" %", CSET.Black);
			l_start+=(Sizes[j]*3.6);

		}
		
		int label_frame_h = 100;
		int addit = Sizes.length*45;
		Pie.Draw_Square(label_frame_h-1, 519, label_frame_h + addit -1, 749, new Pixel(50,50,50), "Corners");
		Pie.Draw_Square(label_frame_h, 520, label_frame_h + addit, 750, new Pixel(10,10,10), "Corners");
		Pie.Draw_Square(label_frame_h+1, 521, label_frame_h + addit +1, 751, CSET.Black, "Corners");
		
		Pie.Update_Pixel_Matrix();
		for(int i =1;i<=Sizes.length;i++) {
			Pie.Draw_Circle(545, label_frame_h-20 + i*45 , 8, Colors[i-1],"Fill");
		}
		Pie.Commint_Matrix_Changes();
		for(int i =1;i<=Sizes.length;i++) {
			Pie.Draw_Circle(545, label_frame_h-20 + i*45 , 9, CSET.Black);
			Pie.Draw_Circle(545, label_frame_h-20 + i*45 , 8, CSET.Black);

		}
		Pie.Draw_Text(80, 640, "LABELS", CSET.Black);
		for(int i =1;i<=Sizes.length;i++) {
			Pie.Draw_Text(label_frame_h-20 + i*45, 640, Labels.get(i-1), CSET.Black);
		}
		Pie.Show_Image();
		
	}

}
