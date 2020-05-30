#include "Mole.h"
#define PI 3.14159265


Mole::Mole() {
	this->pos_x = 0;
	this->pos_y = 0;
}
Mole::Mole(int const &canvas_width, int const &canvas_height, pixel const &background_color) {
	this->pos_x = 0;
	this->pos_y = 0;
	this->Current_Angle =0;
	this->Load_Canvas(canvas_width, canvas_height, background_color);
	this->canvas_height = canvas_height;
	this->canvas_width = canvas_width;
	this->line_width = 0;
	this->CurrentMoleColor = ColorList.White;
	this->Stamp_Aux = 0;
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
	this->pos_x = (float)pos_x;
	this->pos_y = (float)pos_y;
//	this->Current_Angle = 0;
	this->CurrentTargetX = 0;
	this->CurrentTargetY = 0;
}
void Mole::SetLineWidth(int const &width) {
	this->line_width = width;
}


void Mole::GoForward(int const &distance) {
	//change target_x/Y
	float temp_y = ((cos(Current_Angle)) * distance) ;
	float temp_x = ((sin(Current_Angle)) * distance);


	if (pos_x + (int)temp_x < 0) {
		temp_x = 0;
	}
	if (pos_y + (int)temp_y < 0) {
		temp_y = 0;
	}
	if (pos_x + (int)temp_x  > this->canvas_width) {
		temp_x = (float)canvas_width;
	}
	if (pos_y + (int)temp_y > canvas_height) {
		temp_y = (float)canvas_height;
	}

	//*(180 / 3.1415926535)
	if (this->pos_x + (int)temp_x <= canvas_width && this->pos_y + (int)temp_y <= canvas_height && this->pos_x + (int)temp_x >=0 && this->pos_y + (int)temp_y >=0) {



		//if (abs((pos_y + (int)temp_y) - pos_y) < abs((pos_x + (int)temp_x) - pos_x)) {
		//	if (pos_x > pos_x + (int)temp_x) {
		//		Canvas.LineLow(pos_x + (int)temp_x, pos_y + (int)temp_y, pos_x, pos_y, this->CurrentMoleColor);
		//	}
		//	else {
		//		Canvas.LineLow(pos_x , pos_y, pos_x + (int)temp_x, pos_y + (int)temp_y, this->CurrentMoleColor);
		//	}
		//}
		//else {
		//	if (pos_y > pos_y + (int)temp_y) {
		//		Canvas.LineHigh(pos_x + (int)temp_x, pos_y + (int)temp_y, pos_x, pos_y, this->CurrentMoleColor);
		//	}
		//	else {
		//		Canvas.LineHigh(pos_x, pos_y, pos_x + (int)temp_x, pos_y + (int)temp_y, this->CurrentMoleColor);
		//	}
		//}

		this->Canvas.Draw_Line(pos_x, pos_y, pos_x + (int)temp_x, pos_y + (int)temp_y, this->CurrentMoleColor,this->line_width);

	}
	this->pos_x += temp_x;
	this->pos_y += temp_y;

// +-------------------+-------------------+
// |   Degrees         | Radian Equivalent |
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

	GoForward(-distance);

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
	this->Current_Angle -= (float)degree * PI / 180;


#ifdef DEBUG
	cout << Current_Angle << endl;

#endif // DEBUG


}
void Mole::TurnAround() {
	//flip head der
	this, TurnLeft(180);
}
void Mole::SetTarget(int const &pos_x, int const &pos_y) {
	//change target cord
	this->CurrentTargetX = pos_x;
	this->CurrentTargetY = pos_y;

}
void Mole::Set_Angle_Radians(float const &angle) {
	this->Current_Angle = angle;
}

void Mole::Get_To_Target() {
	this->Canvas.Draw_Line(pos_x, pos_y, CurrentTargetX, CurrentTargetY, this->CurrentMoleColor);
	this->pos_x = (float)CurrentTargetX;
	this->pos_y = (float)CurrentTargetY;
}
void Mole::StampMole(pixel const &color) {
	//draw mole pos
	this->Stamps.push_back(Stamp());
	this->Stamp_Aux++;

	pixel c = color;
	int k = 0, p = 0;
	Stamps.back().PositionX = this->pos_x;
	Stamps.back().PositionY = this->pos_y;
	for (int i = pos_x - 3; i < pos_x+3; i++) {
		for (int j = pos_y - 3; j < pos_y+3; j++) {
			 Canvas.getPixelCopy(i,j, Stamps.back().mem[k][p]);
			p++;
			if (p == 6) {
				p = 0;
				k++;
			}
		}
	}

	//for (int y = pos_x -3; y <= pos_x+3; y++) {
	//	for (int x = pos_y-3; x <= pos_y+3; x++) {
	//		if ((x * x) + (y * y) <= (3 * 3)) {
	//			Canvas.getPixelCopy(y, x, Stamps.back().mem[k][p]);
	//			p++;
	//			if (p == 6) {
	//				p = 0;
	//				k++;
	//			}
	//		}
	//		
	//	}

	//}

	Stamps.back().Stamp_Color = this->CurrentMoleColor;
	Stamps.back().Stamp_SerialNumber = this->Stamp_Aux;
	this->Canvas.Draw_Circle(pos_y, pos_x, 3,c, "Fill");
	
}
void Mole::Remove_Stamp(int const &stamp_id) {

	int index;
	int k = 0, p = 0,D=0;

	for (int i = 0; i < Stamps.size(); i++) {
		if (Stamps[i].Stamp_SerialNumber == stamp_id) {
			index = i;
			break;
		}
		D++;
	}

	pixel temp;


	for (int i = Stamps[index].PositionX - 3; i < Stamps[index].PositionX + 3; i++) {
		for (int j = Stamps[index].PositionY - 3; j < Stamps[index].PositionY + 3; j++) {
			temp = Stamps[index].mem[k][p];
			this->Canvas.Color_Spec(Stamps[index].mem[k][p].index_range, temp);
			p++;
			if (p == 6) {
				p = 0;
				k++;
			}
		}
	}
	
	this->Stamps.erase(Stamps.begin()+D);
}

void Mole::Print_Existing_Stamp_ID() {
	cout << endl;
	cout << "Stamps Alive:\n";
	for (int i = 0; i < Stamps.size(); i++) {
		cout << "Serial Number: "<<this->Stamps[i].Stamp_SerialNumber<<"  X: "<< this->Stamps[i] .PositionY<<"  Y: "<< this->Stamps[i] .PositionX<< endl;
	}
}

void Mole::StampMole(pixel const &color, int const &StampID) {

}
void Mole::SetMoleColor(pixel const &color) {
	this->CurrentMoleColor = color;
}
