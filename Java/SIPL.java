import java.util.ArrayList;

public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Color_Palette cset = new Color_Palette();
		  // A.Load_Image("IM/Giraffe.jpg");
		   //A.Load_Image("512x512/Image2.jpg");
		  // A.Load_Image("100x100/Image7.jpg");
		   A.Load_Image("1280x1280/Image3.jpg");
		  // A.Load_Image("DP3/Image1.tif");
		   //A.Load_Blank_Canvas(500, 500, cset.Azure);   
		   SPlot plt = new SPlot();
		   Math_Toolbox tlb = new Math_Toolbox();
		   LabPixel lab = new LabPixel();
		
		   long start_time = System.nanoTime();
		   //plt.Write_Histogram(A,"RGB","Before");
		   //A.Grayscale(1);
		   A.Dithering_Floyd_Steinberg(2);
		   A.Write_Image("test.png");
		
		   
		   
		   
		   
		   
		 // plt.Show_Histogram(A, "RGB","After");
		   long end_time = System.nanoTime();
		   long time_elapsed = end_time - start_time;
		   System.out.println("Finished After :[ "+(double)time_elapsed/1000000000+" ] Seconds");
		   
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.png");		   
		   
	   }
	   
	   
	
}
