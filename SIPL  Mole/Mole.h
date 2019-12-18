#pragma once
#include "Image_Header.h"
#include "Color_Catalog.h"

struct Stamp {
	int PositionX, PositionY;
	int Stamp_SerialNumber;
	pixel mem[6][6];
	pixel Stamp_Color;
};

class Mole {
private:
	
	float pos_x, pos_y;
	int canvas_width, canvas_height;
	int CurrentTargetX, CurrentTargetY;
	float Current_Angle;
	int line_width;
	
	Image Canvas;
	pixel CurrentMoleColor;
	vector<Stamp> Stamps;

public:
	 int Stamp_Aux;
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
	void SetLineWidth(int const &width);
	void Set_Angle_Radians(float const &angle);
	void Get_To_Target();
	void StampMole(pixel const &color);
	void StampMole(pixel const &color,int const &StampID);
	void SetMoleColor(pixel const &color);
	void Print_Existing_Stamp_ID();
	void Remove_Stamp(int const &stamp_id);


};
// +-------------------+-------------------+
// |     Degrees       | Radian Equivalent |
// +-------------------+-------------------+
// |               105 | 7p/12             |
// |               120 | 2p/3              |
// |               135 | 3p/4              |
// |               150 | 5p/6              |
// |               165 | 11p/12            |
// |               180 | p                 |
// |               195 | 13p/12            |
// |               210 | 7p/6              |
// |               225 | 5p/4              |
// |               240 | 4p/3              |
// |               255 | 17p/12            |
// |               270 | 3p/2              |
// |               285 | 19p/12            |
// |               300 | 5p/3              |
// |               315 | 7p/4              |
// |               330 | 11p/6             |
// |               345 | 23p/12            |
// |               360 | 2p                |
// |                 0 | 2p                |
// |                15 | p/12              |
// |                30 | p/6               |
// |                45 | p/4               |
// |                60 | p/3               |
// |                75 | 5p/12             |
// |                90 | p/2               |
// +-------------------+-------------------+
