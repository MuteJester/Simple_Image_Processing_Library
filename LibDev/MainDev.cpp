#include "Image_Header.h"
#include "Color_Catalog.h"



void main() {

	Image A;
	Color_Palette CSET;
	A.Load_Blank_Canvas(100, 100, CSET.White);
	A.Draw_Text(50, 50, "1+1");
	A.Write_Image("Test");
	system("Test.jpg");
}
