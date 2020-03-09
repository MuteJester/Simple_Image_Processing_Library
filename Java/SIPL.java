
	
public class SIPL {

	
	   public static void main(String args[]) throws Exception{
		   Image A = new Image();
		   Image B = new Image();
		   Image C = new Image();
		   Color_Palette cset = new Color_Palette();
		   A.Load_Image("Image9.jpg");
		   B.Load_Image("D7_1.jpg");
		   C.Load_Image("D7_2.jpg");
		   C.Mark_Different_Pixels(B, 50, 15, cset.Red);
		   //System.out.println(A.PixelMatirx[50][50]);
		   C.Write_Image("test.jpg");
		  Runtime.getRuntime().exec("cmd /c C:\\Users\\tomas\\eclipse-workspace\\SIPL\\test.jpg");		   
		   
	   }
	   
	   
	
}
