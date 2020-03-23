
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Image B = new Image();
		   Image C = new Image();
		   int Conv_Kernel[][] = new int[3][3];
		   	Conv_Kernel[0][0] = 0;
			Conv_Kernel[0][1] = 1;
			Conv_Kernel[0][2] = 0;
			Conv_Kernel[1][0] = 1;
			Conv_Kernel[1][1] = 4;
			Conv_Kernel[1][2] = 1;
			Conv_Kernel[2][0] = 0;
			Conv_Kernel[2][1] = 1;
			Conv_Kernel[2][2] = 0;
			
		   Color_Palette cset = new Color_Palette();
		   A.Load_Image("1280x1280/Image7.jpg");
		  // A.Set_Scale(900, 900);
		   A.Image_Convolution(2, "Edge_D", 1);
		   A.Image_Convolution(4, "Mean", 1);
		   A.Write_Image("test.png");
		   
		   
		   
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.png");		   
		   
	   }
	   
	   
	
}
