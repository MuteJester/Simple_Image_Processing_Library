#pragma once
#include "Image_Header.h"
#include "Color_Catalog.h"
 

class Mole {
private:
	
	int pos_x, pos_y;
	int canvas_width, canvas_height;
	int CurrentTargetX, CurrentTargetY;
	float Current_Angle;
	Image Canvas;
	pixel CurrentMoleColor;

public:
	Color_Palette ColorList;
	Mole();
	Mole(int const &canvas_width,int const &canvas_height,pixel const &background_color);
	void Load_Canvas(int const &width, int const &height, pixel const &background_color);
	void Write_Canvas(const char *file_name);
	void Set_Mole_Position(int const &pos_x, int const &pos_y);
	void GoForward(int const &distance);
	void GoBackward(int const &distance);
	void TurnRight();
	void TurnRight(float const &degree);
	void TurnLeft();
	void TurnLeft(float const &degree);
	void TurnAround();
	void SetTarget(int const &pos_x, int const &pos_y);
	void StampMole();
	void SetMoleColor(pixel const &color);


};
