#include "Mole.h"
#define PI 3.14159265

Mole::Mole() {
	this->pos_x = 0;
	this->pos_y = 0;
}
Mole::Mole(int const &canvas_width, int const &canvas_height, pixel const &background_color) {
	this->pos_x = 0;
	this->pos_y = 0;
	this->Current_Angle = 90;
	this->Load_Canvas(canvas_width, canvas_height, background_color);
	this->canvas_height = canvas_height;
	this->canvas_width = canvas_width;
	this->CurrentMoleColor = ColorList.White;
}
void Mole::Load_Canvas(int const &width, int const &height, pixel const &background_color) {
	this->Canvas.~Image();
	this->Canvas.Load_Blank_Canvas(width, height, background_color);
	this->canvas_height = height;
	this->canvas_width = width;
	this->Canvas.init_pixel_matrix();
}
void Mole::Write_Canvas(const char *file_name) {
	this->Canvas.Write_Image(file_name);
}
void Mole::Set_Mole_Position(int const &pos_x, int const &pos_y) {
	this->pos_x = pos_x;
	this->pos_y = pos_y;
	this->Current_Angle = 0;
	this->CurrentTargetX = pos_x;
	this->CurrentTargetY = 0;
}

void Mole::GoForward(int const &distance) {
	//change target_x/Y
	float temp_x = ((cos(Current_Angle)) * distance) ;
	float temp_y = ((sin(Current_Angle)) * distance);


	if (pos_x + (int)temp_x < 0) {
		temp_x = 0;
	}
	if (pos_y + (int)temp_y < 0) {
		temp_y = 0;
	}
	if (pos_x + (int)temp_x  > this->canvas_width) {
		temp_x = canvas_width;
	}
	if (pos_y + (int)temp_y > canvas_height) {
		temp_y = canvas_height;
	}

	//*(180 / 3.1415926535)
	if (this->pos_x + (int)temp_x <= canvas_width && this->pos_y + (int)temp_y <= canvas_height && this->pos_x + (int)temp_x >=0 && this->pos_y + (int)temp_y >=0) {
		this->Canvas.Draw_Line(pos_x, pos_y, pos_x + (int)temp_x, pos_y + (int)temp_y, CurrentMoleColor);
	}
	this->pos_x += temp_x;
	this->pos_y += temp_y;

// +-------------------+-------------------+
// | Supported Degrees | Radian Equivalent |
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

}
void Mole::GoBackward(int const &distance) {
	//change target_x/Y

	this->Canvas.Draw_Line(pos_x, pos_y, this->CurrentTargetX, this->CurrentTargetY, CurrentMoleColor);

}
void Mole::TurnRight() {
	//turn 90'
	this->Current_Angle += 90 * (PI / 180);
	if (Current_Angle > 360) {
		Current_Angle -= 360;
	}
}
void Mole::TurnRight(float const &degree) {
	//change target_x/Y
	this->Current_Angle += degree * PI / 180;
	

#ifdef DEBUG


	cout << Current_Angle << endl;

#endif // DEBUG


}
void Mole::TurnLeft() {
	//turn 90'
	this->Current_Angle += 90;
	if (Current_Angle > 360) {
		Current_Angle -= 360;
	}
}
void Mole::TurnLeft(float const &degree) {
	//change target_x/Y
	this->Current_Angle -= degree * PI / 180;


#ifdef DEBUG
	cout << Current_Angle << endl;

#endif // DEBUG


}
void Mole::TurnAround() {
	//flip head der
	this, TurnRight(180);
}
void Mole::SetTarget(int const &pos_x, int const &pos_y) {
	//change target cord
	this->CurrentTargetX = pos_x;
	this->CurrentTargetY = pos_y;

}
void Mole::StampMole() {
	//draw mole pos
	this->Canvas.Draw_Circle(pos_x, pos_y, 3, this->ColorList.Red, "Fill");

}
void Mole::SetMoleColor(pixel const &color) {
	this->CurrentMoleColor = color;
}
