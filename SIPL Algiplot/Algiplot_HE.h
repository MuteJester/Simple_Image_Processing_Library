#pragma once
#include "Color_Catalog.h"
#include "Image_Header.h"
struct cord {
	int x, y;
};
class Plot {
private:
	Image Visual_Data;
	int canW, canH, step;
	float FXx, FXy, FYx, FYy;
	float three_D_Delta;
	float Tcx, Tcy;
public:
	Plot();
	void Define_3D_Plot(int const &x_axis_length, int const &y_axis_length, int const &Step, const char *mod);
	void Define_2D_Plot(int const &x_axis_length, int const &y_axis_length, int const &Step ,const char *mod);
	void Add_3D_Point(int const &x, int const &y, int const &z, pixel const &color);
	void Add_2D_Point(int const &x, int const &y,pixel const &color);

	void Save_Plot();

};