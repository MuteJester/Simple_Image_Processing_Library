#include "Image_Header.h"
#include "Color_Catalog.h"


int main() {

	Image A,B;
	Color_Palette CSET;
	LA_Masks masks;
	A.Load_Image("Image10.jpg");
	

	A.Write_Image("Test");
	system("Test.jpg");
	return 0;
}
