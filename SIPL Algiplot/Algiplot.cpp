#include "Algiplot_HE.h"
#include <sstream>
Plot::Plot() {

}

void Plot::Define_3D_Plot(int const &x_axis_length, int const &y_axis_length,int const &Step, const char *mod) {
#define THREE_D
	float endXx, endXy, endYx,endYy,delta=0;
	int canvasH, canvasW, counter = 0;
	int centerX, centerY, angle = 70;
	vector<cord> diag_left;
	vector<cord> diag_right;
	stringstream ss;
	string via;
	Color_Palette CSET;
	char m1[10], m2[10];
	strcpy(m1, "Grid");
	strcpy(m2, "No_Grid");

	//canvas loading
	canvasH = 50 + y_axis_length * 50 + 100;
	canvasW = 100 + x_axis_length * 50 + 100;
	this->Visual_Data.Load_Blank_Canvas(canvasW, canvasH, CSET.Azure);

	this->Visual_Data.Get_Center(centerX, centerY);
	centerX -= 100;
	endXx = centerX + sin(-70)*y_axis_length * 20;
	endXy = centerY + cos(-70)*y_axis_length * 20;
	endYy = centerY;
	endYx = centerX + sin(angle)*y_axis_length * 50 - 100;
	this->FXx = endXx;
	this->FXy = endXy;
	this->FYx = endYx;
	this->FYy = endYy;
	this->Tcx = centerX;
	this->Tcy = centerY;
	this->step = Step;

	//Visual_Data.Draw_Circle(centerX, centerY, 3, CSET.Red);
	//z axis
	Visual_Data.Draw_Line(centerY, centerX, 50, centerX, CSET.Light_Gray);

	//x axis
	Visual_Data.Draw_Line(centerY, centerX,endXy , endXx, CSET.Light_Gray);
	//Visual_Data.Draw_Circle(endXx, endXy, 3, CSET.Red);

	//y axis
	Visual_Data.Draw_Line(centerY, centerX, centerY, endYx, CSET.Light_Gray);
	//Visual_Data.Draw_Circle(endYx, endYy, 3, CSET.Red);

	delta = endYx - centerX;
	this->three_D_Delta = delta;
	Visual_Data.Draw_Text(20, canvasW / 2, "3D PLOT", CSET.Black);
	
	Visual_Data.Draw_Line(endXy, endXx, endXy, endXx + delta, CSET.Black);
	counter = (endXx + delta-100) / Step;
	for (int i = endXx; i <= endXx + delta; i += Step) {
		ss << counter;
		via = ss.str();
		Visual_Data.Draw_Line(endXy, i, endXy + 3, i, CSET.Black);
		Visual_Data.Draw_Text(endXy+9, i-4, via.c_str(), CSET.Black);
		counter--;
		ss.str(string());
	}
	counter = 0;

	Visual_Data.Draw_Line(endYy, endYx, endXy, endXx + delta, CSET.Black);

	for (int i = endYy; i >= 50; i -= Step) {
		ss << counter;
		via = ss.str();
		Visual_Data.Draw_Line(i, endYx, i, endYx+3, CSET.Black);
		if (counter != 0) {
			Visual_Data.Draw_Text(i, endYx + 10, via.c_str(), CSET.Black);
		}
		counter++;
		ss.str(string());
	}

	Visual_Data.Draw_Line(endYy, endYx, 50, endYx, CSET.Black);
	//Visual_Data.Draw_Circle(endYx, endYy, 3, CSET.Red);

	Visual_Data.Draw_Line(50, endYx, 50, centerX, CSET.Light_Gray);

	Visual_Data.Draw_Line(50, centerX, endXy-delta, endXx, CSET.Light_Gray);
	Visual_Data.Draw_Line(endXy, endXx, endXy - delta, endXx, CSET.Light_Gray);


	float curx = endXx, cury = endXy;
	int A = -70, Dt = delta;
	short flag = 0;
	counter = 0;
	for (int i = curx; i < centerX; i -= sin(A)*Step) {
		if (i < endYx) {

			ss << counter;
			via = ss.str();
			//Visual_Data.Draw_Circle(i + delta + 15, cury, 2, CSET.Blue);
			Visual_Data.Draw_Line(cury, i + delta+2, cury, i + delta + 10, CSET.Black);
			Visual_Data.Draw_Text(cury,i + delta + 15,via.c_str(),CSET.Black);
			counter++;;
			ss.str(string());
		}
	
		cury -= cos(A)*Step;

		//curx -= sin(A)*Step;
	}

	if (strcmp(m1, mod) == 0) {
		counter = centerX;
		//xy
		for (int i = endXx; i <= endXx + delta; i += Step) {
	
			Visual_Data.Draw_Line(endXy, i, centerY, counter, CSET.Light_Gray);
			counter += Step;
		}
	
		//zy
		for (int i = endYy; i >= 50; i -= Step) {

			Visual_Data.Draw_Line(i, endYx, i, centerX, CSET.Light_Gray);
	
		}

		for (int i = centerX; i < endYx; i += Step-1) {

			Visual_Data.Draw_Line(centerY, i,50, i, CSET.Light_Gray);

		}
		
		//xz
		counter = centerY;
		for (int i = endXy; i > endXy-delta; i -= Step) {

			Visual_Data.Draw_Line(i, endXx, counter, centerX, CSET.Light_Gray);
			counter -= Step-1;
		}

		curx = endXx;
		cury = endXy;
		A = -70, Dt = delta;
		short flag = 0;
		for(int i=curx-2; i < centerX ;i -= sin(A)*Step){
			//Visual_Data.Draw_Circle(i, cury, 2, CSET.Blue);
			Visual_Data.Draw_Line(cury,i+2, cury-delta,i+2,CSET.Light_Gray);
			if (flag != 0) {
				Visual_Data.Draw_Line(cury, i, cury, i + Dt, CSET.Light_Gray);
			}
			flag = 1;

			delta-=2;
			cury -= cos(A)*Step;

			//curx -= sin(A)*Step;
		}

		return;


	}
	else if (strcmp(m2, mod) == 0) {

		return;
	}




}
void Plot::Define_2D_Plot(int const &x_axis_length, int const &y_axis_length, int const &Step, const char *mod) {
#define TWO_D
	int canvasH, canvasW,counter=0;
	stringstream ss;
	string via;
	Color_Palette CSET;
	char m1[10], m2[10];
	strcpy(m1, "Grid");
	strcpy(m2, "No_Grid");

	//canvas loading
	canvasH = 50 + y_axis_length * 50 + 100;
	canvasW = 100 + x_axis_length * 50 + 100;
	this->canW = canvasW;
	this->canH = canvasH;
	this->step = Step;
	this->Visual_Data.Load_Blank_Canvas(canvasW, canvasH, CSET.Azure);
	
	//Graph Creation (0,0) = (100,canvasH-50)

	Visual_Data.Draw_Line(canvasH - 50, 100, canvasH - 50, canvasW - 100, CSET.Black);
	Visual_Data.Draw_Line(canvasH - 51, 100, canvasH - 51, canvasW - 100, CSET.Black);
	Visual_Data.Draw_Line(canvasH - 52, 100, canvasH - 52, canvasW - 100, CSET.Black);

	Visual_Data.Draw_Line(canvasH - 50, 100, 50, 100,CSET.Black);
	Visual_Data.Draw_Line(canvasH - 50, 99, 50, 99,CSET.Black);
	Visual_Data.Draw_Line(canvasH - 50, 98, 50, 98, CSET.Black);

	Visual_Data.Draw_Line(canvasH - 50, canvasW-100, 50, canvasW - 100, CSET.Black);
	Visual_Data.Draw_Line(canvasH - 50, canvasW - 101, 50, canvasW - 101, CSET.Black);
	Visual_Data.Draw_Line(canvasH - 50, canvasW - 102, 50, canvasW - 102, CSET.Black);

	Visual_Data.Draw_Line( 50, 100, 50, canvasW - 100, CSET.Black);
	Visual_Data.Draw_Line(49, 100, 49, canvasW - 100, CSET.Black);
	Visual_Data.Draw_Line(48, 100, 48, canvasW - 100, CSET.Black);

	Visual_Data.Draw_Text(40, canvasW / 2, "2D PLOT", CSET.Black);

	for (int i = 100 + Step; i < canvasW - 100; i+=Step) {
		Visual_Data.Draw_Line(canvasH - 50, i, canvasH - 45, i, CSET.Black);
		ss << counter;
		via = ss.str();
		Visual_Data.Draw_Text(canvasH - 40, i-5, via.c_str());
		ss.str(string());
		counter++;
	}
	counter = 0;

	for (int i = canvasH-50 - Step; i > 50; i -= Step) {
		Visual_Data.Draw_Line(i, 100,i, 90, CSET.Black);
		ss << counter;
		via = ss.str();
		Visual_Data.Draw_Text(i, 80, via.c_str());
		ss.str(string());
		counter++;
	}
	Visual_Data.Draw_Text(canvasH - 52, canvasW - 91, "X",CSET.Blue);
	Visual_Data.Draw_Text(40,92, "Y", CSET.Blue);

	if (strcmp(m1, mod) == 0) {
		//vertical 
		for (int i = 100 + Step; i < canvasW - 100; i += Step) {
			Visual_Data.Draw_Line(canvasH - 50, i, 50, i, CSET.Light_Gray);

		}
		//diagonal
		for (int i = canvasH - 50 - Step; i > 50; i -= Step) {
			Visual_Data.Draw_Line(i, 100, i, canvasW-100, CSET.Light_Gray);

		}


		return;
	}
	else if (strcmp(m2, mod) == 0) {
		return;
	}






	
	


}

void Plot::Add_3D_Point(int const &x, int const &y, int const &z, pixel const &color) {
#ifndef THREE_D
	return;
#endif // !THREE_D
	Color_Palette CSET;
	//(0,0) = (endX+delta,endy)
	stringstream ss;
	string via;
	
	int angle = 70;
	//three_D_Delta -= three_D_Delta/step;

	//for (int i = 0; i < 360; i++) {
	//	ss << i;
	//	via = ss.str();
	//	Visual_Data.Draw_Circle(FXx + three_D_Delta - (cos(angle)*step*(x)), FXy - (sin(angle)*step*(y)), 1, CSET.Red);
	//	Visual_Data.Write_Image(via.c_str());
	//	ss.str(string());
	//	angle++;
	//}

	Visual_Data.Draw_Circle(FXx + three_D_Delta - (cos(angle)*step*(x)), FXy - (sin(angle)*step*(y)) - (z+1)*step, 3, color,"Fill");


}
void Plot::Add_2D_Point(int const &x, int const &y, pixel const &color) {
#ifndef TWO_D
	return;
#endif // !TWO_D
	
	//(0,0) point at (100 + step,canH-100)
	
	this->Visual_Data.Draw_Circle((100+step) +(step*x) , (canH-50-step)-(step*y), 3, color,"Fill");

}

void Plot::Save_Plot() {
	this->Visual_Data.Write_Image("Algiplot_Savefile");
}
