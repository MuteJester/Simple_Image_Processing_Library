
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Image B = new Image();
		   Image C = new Image();
		   Color_Palette cset = new Color_Palette();
		  // B.Load_Blank_Canvas(500, 500, cset.Lime);
		  B.Load_Image("1280x1280/Image7.jpg");
		//   B.Load_Blank_Canvas(1000, 1000, cset.Azure);

		 //  B.Write_Channel_Histogram(); //needs to be fixed
		   
		  // B.Draw_Square(500, 500, 30, 30, cset.Dark_Green,"Fill");
		   //B.Flip180(); // needs to be debugded
		  //B.Figure_Detection(2, 10, 100); needs to be debugged
		  
		  B.Image_Convolution(15, "Gaussian");
		   B.Write_Image("test.png");
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.png");		   
		   
	   }
	   
	   
	
}
