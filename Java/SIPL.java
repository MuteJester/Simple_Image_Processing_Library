
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Image B = new Image();
		   Image C = new Image();
		   Color_Palette cset = new Color_Palette();
		   A.Load_Image("FigureDetection/Image7.jpg");
		   A.Figure_Detection(10, 10, 110);
		   A.Write_Image("test.png");
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.png");		   
		   
	   }
	   
	   
	
}
