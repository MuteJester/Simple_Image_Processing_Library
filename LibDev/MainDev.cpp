#include "Image_Header.h"
#include "Color_Catalog.h"


int main() {

	Image A,B;
	Color_Palette CSET;
	A.Load_Image("Image1.jpg");
	B.Load_Image("Coin1.jpg");

	A.Write_Image("Test");
	system("Test.jpg");
	return 0;
}
