#include "Image_Header.h"
#include "Color_Catalog.h"



void main() {

	CoordinateFrame A, B;
	Image D;
	A.push_back(coordinate{1, 2});
	B.push_back(coordinate{ 1, 3 });
	bool a = A ^ B;
	cout << a;
	

	system("pause");
}
