#include "Image_Header.h"
#include "Color_Catalog.h"



int main() {

	Image A;
	Color_Palette CSET;
	//A.Load_Image("Image3.jpg");
	//A.Up_Scale();


	A.Write_Image("Test");
	system("Test.jpg");
	return 0;
}
