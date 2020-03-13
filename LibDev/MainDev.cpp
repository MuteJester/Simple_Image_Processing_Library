#include "Image_Header.h"
#include "Color_Catalog.h"
#include "CPP_MP.h"

int main() {

	Image A,C,B;
	Color_Palette CSET;
	A.Load_Blank_Canvas(500, 500, CSET.Azure);
	A.Draw_Text(250, 250, ":;,./*[]()+%4^", CSET.Black);
	A.Write_Image("Test");

	system("Test.jpg");
	
	return 0;
}
