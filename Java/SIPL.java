
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Color_Palette cset = new Color_Palette();
		  // A.Load_Image("IM/Giraffe.jpg");
		  // A.Load_Image("IM/DarkImage.jpg");
		   //A.Load_Image("Noise/SNP1.jpg");
		  //A.Load_Image("1280x1280/Image3.jpg");
		   A.Load_Image("STD/Image5.jpg");
		   //A.Load_Blank_Canvas(500, 500, cset.Azure);   
		   SPlot plt = new SPlot();
		   Math_Toolbox tlb = new Math_Toolbox();
		   
		   plt.Write_Histogram(A,"RGB","Before");
		   for(int i = 0; i<1;i++) {
		   A.Image_Convolution("Sobol_Y");
		   }
		   A.Write_Image("test.png");

		  // plt.Write_Histogram(A, "RGB","After");
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.png");		   
		   
	   }
	   
	   
	
}
