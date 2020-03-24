
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Color_Palette cset = new Color_Palette();
		   A.Load_Image("HC/HC1.jpg");
		   //A.Load_Blank_Canvas(500, 500, cset.Azure);   
		   SPlot plt = new SPlot();
		   Math_Toolbox tlb = new Math_Toolbox();
		   //A.Write_Image("test.png");
		   //plt.Write_Histogram(A,"Red");
		   int test[] = new int[]{52,55,55,55,58,58
				   ,59,59,59,60,61,61,61,61
				   ,62,63,63,64,64,65,65,65
				   ,66,66,67,68,68,68,68,68,
				   69,69,69,70,70,70,70,71,71
				   ,72,73,73,75,76,77,78,79,79,
				   83,85,85,87,88,90,94,104,104,106
				   ,109,113,122,126,144,154};
		   
		   	double rank[] = tlb.getRank_Array(test);
		   
		   A.Histogram_Correction();
		   //System.out.println(tlb.getStandard_Deviation(test));
		   //System.out.println(tlb.getMean(test));

		   
		  //Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\Histogram.png");		   
		   
	   }
	   
	   
	
}
