#pragma once

#ifndef Im
#define Im

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "Image_Header.h"
#include "Color_Catalog.h"
#include "Characters.h"

#endif

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <random>
#include <limits>
#include <algorithm>


//using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

//#define FaceDebug


#define Line_StepByStep




Pixel_C::Pixel_C() {
	this->data.r = 0;
	this->data.g = 0;
	this->data.b = 0;
	this->data.index_range = 0;
	this->data.analysis = 0;
}
Pixel_C::Pixel_C(uint8_t r, uint8_t g, uint8_t b) {
	this->data.r = r;
	this->data.g = g;
	this->data.b = b;
	this->data.analysis = 0;

}
Pixel_C::~Pixel_C() {

}

char Pixel_C::interpret_color() const {
	if (data.r == 0 && data.b == 0 && data.g > 0) {//green
		return 'g';
	}
	else if (data.r > 0 && data.b == 0 && data.g == 0) {//red
		return 'r';
	}
	else if (data.r == 0 && data.b > 0 && data.g == 0) {//blue
		return 'b';
	}
	else if (data.r == 0 && data.b == 0 && data.g == 0) {//black
		return 'B';
	}
	else if (data.r <= 255 && data.r >= 240 && data.b <= 255 && data.b >= 240 && data.g <= 255 && data.g >= 240) {//white
		return 'W';
	}
	else if (data.r == data.g == data.b && data.r < 240 && data.b < 240 && data.g < 240) {//shades of gray
		return 'G';
	}
	else {
		return 'M';
	}
}

void Pixel_C::set_color(const char color) {
	switch (color)
	{
	case 'r':
		data.r = 255;
		data.g = 0;
		data.b = 0;
		break;
	case 'g':
		data.r = 0;
		data.g = 255;
		data.b = 0;
		break;
	case 'b':
		data.r = 0;
		data.g = 0;
		data.b = 255;
		break;
	case 'W':
		data.r = 255;
		data.g = 255;
		data.b = 255;
		break;
	case 'B':
		data.r = 0;
		data.g = 0;
		data.b = 0;
		break;
	case 'G':
		data.r = 165;
		data.g = 165;
		data.b = 165;
		break;
	default:
		break;
	}
}
void Pixel_C::set_color(const uint8_t &r, const uint8_t &g, const uint8_t &b) {

}

void Pixel_C::set_refrence(uint8_t &r, uint8_t &g, uint8_t &b) {
	r = this->data.r;
	g = this->data.g;
	b = this->data.b;
}
uint8_t Pixel_C::get_r() const {
	return this->data.r;
}
uint8_t Pixel_C::get_g() const {
	return this->data.g;
}
uint8_t Pixel_C::get_b() const {
	return this->data.b;
}

void Pixel_C::set_r(const uint8_t r) {
	this->data.r = r;
}
void Pixel_C::set_g(const uint8_t g) {
	this->data.g = g;
}
void Pixel_C::set_b(const uint8_t b) {
	this->data.b = b;
}









void gcd_list(int w, int h, std::vector<int> &list) {
	if (w > h) {
		for (int i = 1; i <= w; i++) {
			if (h % i == 0 && w % i == 0) {
				list.push_back(i);
			}
		}
	}
	else {
		for (int i = 1; i <= h; i++) {
			if (h %
				i == 0 && w % i == 0) {
				list.push_back(i);
			}
		}
	}
}
std::ostream &operator<<(std::ostream &out, pixel &in) {
	out << "Pixel Index: " << in.index_range;
	out << "\nR: " << (int)in.r;
	out << "\nG: " << (int)in.g;
	out << "\nB: " << (int)in.b;
	out << "\n";
	return out;

}
bool operator==(pixel &a, pixel &b) {
	if (a.r == b.r&&a.g == b.g&&a.b == b.b) {
		return true;
	}
	else {
		return false;
	}
}
void partition_pixels(int &rows, int &cols, int number_of_pix) {

	int sq = (int)sqrt(number_of_pix) + 1;
	rows = sq;
	cols = sq;
}
void set_pixel_color(pixel &pix, char color) {
	switch (color)
	{
	case 'r':
		pix.r = 255;
		pix.g = 0;
		pix.b = 0;
		break;
	case 'g':
		pix.r = 0;
		pix.g = 255;
		pix.b = 0;

		break;
	case 'b':
		pix.r = 0;
		pix.g = 0;
		pix.b = 255;
		break;
	case 'W':
		pix.r = 255;
		pix.g = 255;
		pix.b = 255;
		break;
	case 'B':
		pix.r = 0;
		pix.g = 0;
		pix.b = 0;
		break;
	default:
		break;
	}
}
void operator+(pixel &a, pixel  &b) {
	a.r += b.r;
	if (a.r > 255) {
		a.r = a.r % 255;
	}
	a.b += b.b;
	if (a.b > 255) {
		a.b = a.b % 255;
	}
	a.g += b.g;
	if (a.g > 255) {
		a.g = a.g % 255;
	}
}
bool operator==(pixel&a, pixel const &b) {
	if (a.r == b.r && a.g == b.g && a.b == b.b) {
		return true;
	}
	else { return false; }
}
bool operator!=(pixel&a, pixel const &b) {
	if (a.b != b.b || a.r != b.r || a.g != b.g) {
		return true;
	}
	else { return false; }
}
pixel operator*(pixel const &a, pixel const &b) {
	pixel ret;
	ret.r = a.r*b.r;
	if (ret.r > 255) {
		ret.r = ret.r % 255;
	}
	ret.g = a.g*b.g;
	if (ret.g > 255) {
		ret.g = ret.g % 255;
	}
	ret.b = a.b*b.b;
	if (ret.b > 255) {
		ret.b = ret.b % 255;
	}
	ret.index_range = a.index_range;
	return ret;
}
void operator+=(pixel &a, pixel &b) {
	a + b;
}
bool operator>(pixel &a, pixel &b) {
	if (a.r > b.r && a.g > b.g && a.b > b.b) {
		return true;
	}
	else {
		return false;
	}
}
double Get_Square(double value) {
	return value * value;
}
double squared_3Point_distance(Point first, Point second) {
	return Get_Square(first.x - second.x) + Get_Square(first.y - second.y) + Get_Square(first.z - second.z);
}
float GammaX(int const &color_value) {
	float conditionA = (float)0.04045, divisorB = (float)12.92;
	float Value = (float)color_value;
	Value /= 255;
	float result;
	if (Value > conditionA) {
		result = (float)pow(((Value + 0.055) / 1.055), 2.4);
		return Value;

	}
	else {
		Value = (float)(Value / 12.92);
		return Value;
	}
}
double LAB_Function(double &value) {
	if (value > pow((6 / 29), 3)) {
		return pow(value, 1 / 3);
	}
	else {
		return (double)(1 / 3 * (pow((29 / 6), 2)*value)) + (4 / 29);
	}
}
void RGB_XYZ_Transformation(pixel &value, double const M[3][3]) {

	double result[3][1];
	double XYZ[3][1];
	double sum = 0;
	double L, a, b;
	result[0][0] = GammaX(value.r);
	result[1][0] = GammaX(value.g);
	result[2][0] = GammaX(value.b);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 1; j++) {
			XYZ[i][j] = 0;
			for (int k = 0; k < 3; k++) {

				XYZ[i][j] += M[i][k] * result[k][j];

			}

		}

	}

	value.r *= (uint8_t)XYZ[0][0];
	value.g *= (uint8_t)XYZ[1][0];
	value.b *= (uint8_t)XYZ[2][0];

	L = (116 * (LAB_Function(XYZ[1][0])) - 16);
	a = (500 * (LAB_Function(XYZ[0][0]) - LAB_Function(result[2][0])));
	b = (200 * (LAB_Function(XYZ[0][0]) - LAB_Function(result[2][0])));

	//value.r = L;
	//value.g = a;
	//value.b = b;

}
float Pixel_Dataframe_Difference(pixel const &Pix, Point const &DF_point) {
	float distance;
	distance = (float)((DF_point.x - Pix.r)*(DF_point.x - Pix.r) + (DF_point.y - Pix.g)*(DF_point.y - Pix.g) + (DF_point.z - Pix.b)*(DF_point.z - Pix.b));
	return sqrt(distance);
}
pixel Image::Dominant_Color_Via_Line(const int start_y, const int start_x, const int target_y, const int target_x) {
	float dx, sx, dy, sy, err, e2;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	pixel Dom_Color;
	std::vector<pixel> dots;
	VectorFrame Points;
	VectorFrame Res;
	float x0 = (float)start_y, x1 = (float)target_y, y0 = (float)start_x, y1 = (float)target_x;
	dx = (float)abs(target_y - start_y);
	sx = (float)(start_y < target_y ? 1 : -1);
	dy = (float)(-abs(target_x - start_x));
	sy = (float)(start_x < target_x ? 1 : -1);
	err = dx + dy;  //error value
	while (true) {
		if (x0 == x1 && y0 == y1) {
			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.push_back({ (double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].r,
								(double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].g,
								(double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].b
				});
			break;
		}

		//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
		Points.push_back({ (double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].r,
							(double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].g,
							(double)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].b
			});
		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}

	}

	Res = K_Means(Points, 1, 100);
	Dom_Color.r = (uint8_t)Res[0].x;
	Dom_Color.g = (uint8_t)Res[0].y;
	Dom_Color.b = (uint8_t)Res[0].z;

	return Dom_Color;
}
bool operator==(coordinate A, coordinate B) {
	if (A.x == B.x && A.y == B.y) {
		return true;
	}
	else {
		return false;
	}
}
bool operator^(CoordinateFrame A, CoordinateFrame B) {
	if (A.size() >= B.size()) {
		for (unsigned i = 0; i < B.size(); i++) {
			if (A[i] == B[i]) {
				return true;
			}
		}
		return false;
	}
	else {

		for (unsigned i = 0; i < A.size(); i++) {
			if (A[i] == B[i]) {
				return true;
			}
		}
		return false;
	}
}
void Image::color_set(char color_choice, int &index) {


	switch (color_choice)
	{
	case 'r':
		image_data[index++] = 255;
		image_data[index++] = 0;
		image_data[index] = 0;
		index -= 2;
		break;
	case 'g':
		image_data[index++] = 0;
		image_data[index++] = 255;
		image_data[index] = 0;
		index -= 2;
		break;
	case 'b':
		image_data[index++] = 0;
		image_data[index++] = 0;
		image_data[index] = 255;
		index -= 2;
		break;
	case 'W':
		image_data[index++] = 255;
		image_data[index++] = 255;
		image_data[index] = 255;
		index -= 2;
		break;
	case 'B':
		image_data[index++] = 0;
		image_data[index++] = 0;
		image_data[index] = 0;
		index -= 2;
		break;
	default:
		break;
	}



}
void Image::color_set(pixel const &color, int &index) {
	image_data[index++] = color.r;
	image_data[index++] = color.g;
	image_data[index] = color.b;
	index -= 2;
}
char Image::decode_color(uint8_t r, uint8_t g, uint8_t b) {
	if (r == 0 && b == 0 && g > 0) {//green
		return 'g';
	}
	else if (r > 0 && b == 0 && g == 0) {//red
		return 'r';
	}
	else if (r == 0 && b > 0 && g == 0) {//blue
		return 'b';
	}
	else if (r == 0 && b == 0 && g == 0) {//black
		return 'B';
	}
	else if (r <= 255 && r >= 240 && b <= 255 && b >= 240 && g <= 255 && g >= 240) {//white
		return 'W';
	}
	else if (r >= 169 && b >= 169 && g >= 169) {//shades of gray
		return 'G';
	}

	else {//undefined color
		return 'M';
	}
}
Image::Image() {
	this->image_data = nullptr;
	this->Height = 0;
	this->width = 0;
	this->Pixel_Matrix = nullptr;
	this->channel = 0;
	this->im_size = 0;
	this->pos_X = 0;
	this->pos_Y = 0;

}
Image::Image(unsigned char *image_data, int Height, int width, int channel) {
	this->image_data = image_data;
	this->Height = Height;
	this->width = width;
	this->channel = channel;
	this->im_size = width * Height*channel;
	this->pos_X = 0;
	this->pos_Y = 0;
	this->Pixel_Matrix = nullptr;



}
Image::Image(int Height, int width, int channel) {
	this->Height = Height;
	this->width = width;
	this->channel = channel;
	this->pos_X = 0;
	this->pos_Y = 0;
	this->Pixel_Matrix = nullptr;

}
Image::~Image() {
	//free(image_data);
	stbi_image_free(image_data);
	if (Pixel_Matrix != nullptr) {
		/*for (int i = 0; i < this->Height; i++) {
			delete[] Pixel_Matrix[i];
		}*/
		delete[] Pixel_Matrix;
	}

}
int Image::getWidth() const {
	return this->width;
}
int Image::getHeight()const {
	return this->Height;
}
void Image::getPixelCopy(int Height, int Width, pixel &save_pixel) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	save_pixel.r = Pixel_Matrix[Height][Width].r;
	save_pixel.g = Pixel_Matrix[Height][Width].g;
	save_pixel.b = Pixel_Matrix[Height][Width].b;
	save_pixel.index_range = Pixel_Matrix[Height][Width].index_range;


}
float Cordinate_Distance(int const &x0, int const &y0, int const &x1, int const &y1) {
	float Distance = (float)((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
	return Distance;
}

Blob::Blob(int const &x, int const &y, int const &Distnace_Treshold) {
	this->Downright_X = x;
	this->Downright_Y = y;
	this->Upleft_X = x;
	this->Upleft_Y = y;
	this->Distnace_Treshold = Distnace_Treshold;
}

bool Blob::Near(int const &x, int const &y) {
	double CentetX, CenterY, Dist;
	/*CentetX = (Upleft_X + Downright_X) / 2;
	CenterY = (Upleft_Y + Downright_Y) / 2;*/

	CentetX = fmax(fmin(x, Upleft_X), Downright_X);
	CenterY = fmax(fmin(y, Upleft_Y), Downright_Y);
	Dist = (double)(Cordinate_Distance((int)CentetX, (int)CenterY, (int)(x), (int)(y)));

	if (Dist < this->Distnace_Treshold*Distnace_Treshold) {
		return true;
	}
	else {

		return false;
	}
}
void Blob::add(int const &px, int const &py) {
	this->Downright_X = (int)fmin(Downright_X, px);
	this->Downright_Y = (int)fmin(Downright_Y, py);

	this->Upleft_X = (int)fmax(Upleft_X, px);
	this->Upleft_Y = (int)fmax(Upleft_Y, py);
}
void Blob::Clear() {
	this->Downright_X = this->Downright_Y = this->Upleft_X = this->Upleft_Y = -1;
}
void Blob::SetProps(int const &x, int const &y) {
	this->Downright_X = x;
	this->Downright_Y = y;
	this->Upleft_X = x;
	this->Upleft_Y = y;
}
float Blob::Size() {
	return (float)abs(this->Upleft_X - Downright_X)*(Upleft_Y - Downright_Y);
}


void Image::Load_Blank_Canvas() {
	std::cout << "\nPlease Enter Height Of Image: ";
	std::cin >> Height;
	std::cout << "\nPlease Enter Width Of Image: ";
	std::cin >> width;
	std::cout << "\nPlease Enter Number Of Color Channels: ";
	std::cin >> channel;
	if (image_data != NULL) {

		stbi_image_free(image_data);
	}
	else {
		//image_data = (unsigned char*)calloc(width*Height*channel, sizeof(unsigned char));
		image_data = new unsigned char[width*Height*channel];
	}
}
void Image::Load_Blank_Canvas(int width, int height, char set_color) {
	this->channel = 3;
	this->width = width;
	this->Height = height;
	if (image_data != nullptr) {

		stbi_image_free(image_data);
	}

	image_data = new unsigned char[width*Height*channel];
	for (int i = 0; i < width*height*channel; i += 3) {
		Color_Spec(i, set_color);
	}
	return;

}
void Image::Load_Blank_Canvas(int width, int height, pixel const &background_color) {
	this->channel = 3;
	this->width = width;
	this->Height = height;
	if (image_data != nullptr) {

		stbi_image_free(image_data);
	}

	image_data = new unsigned char[width*Height*channel];
	for (int i = 0; i < width*height*channel; i += 3) {
		this->image_data[i] = background_color.r;
		this->image_data[i + 1] = background_color.g;
		this->image_data[i + 2] = background_color.b;

	}
	return;
}
void Image::printImdata() {
	int index = 0;
	system("cls");
	for (int i = 0; i < width*Height * 3; i += 3) {

		if (i % (width * 3) == 0) {
			std::cout << "\n";
		}

		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 1) {
			std::cout << "[]";
			index += 3;
		}
		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 2) {
			std::cout << "_" << " ";
			index += 3;
		}
		else {

			std::cout << decode_color(image_data[index], image_data[index + 1], image_data[index + 2]) << " ";
			index += 3;
		}

	}
}
void Image::printImdata(char color) {
	int index = 0;
	system("cls");
	for (int i = 0; i < width*Height * 3; i += 3) {

		if (i % (width * 3) == 0) {
			std::cout << "\n";
		}

		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 1) {
			std::cout << "[" << color << "] ";
			index += 3;
		}

		else {

			std::cout << decode_color(image_data[index], image_data[index + 1], image_data[index + 2]) << " ";
			index += 3;
		}

	}
}
void Image::Manual_Draw() {
	int index = 3;
	int key_movment;
	unsigned char choice = 'z', color_choice;
	short state = 1;
	MODE = 1;

	printImdata();
	while (state) {


		switch ((key_movment = _getch()))
		{

		case KEY_UP:
			if (pos_Y > 0) {
				pos_Y--;
				index -= 3 * width;
				printImdata();
				choice = _getch();

				if (choice == 'e') {
					MODE = 2;
					printImdata();
					MODE = 1;
					color_choice = _getch();

					color_set(color_choice, index);
					printImdata(color_choice);
					choice = 'z';
				}

			}
#ifdef DEBUG



			cout << "up Y: " << pos_Y << "  Index Is " << index << "\n";
#endif //debug
			break;
		case KEY_DOWN:
			if (pos_Y < Height) {
				pos_Y++;
				index += 3 * width;
				printImdata();
				choice = _getch();

				if (choice == 'e') {
					MODE = 2;
					printImdata();
					MODE = 1;
					color_choice = _getch();

					color_set(color_choice, index);
					printImdata(color_choice);
					choice = 'z';
				}
			}
#ifdef DEBUG



			cout << "down Y: " << pos_Y << "  Index Is " << index << "\n";
#endif //debug
			break;
		case KEY_LEFT:
			if (pos_X >= 0) {
				pos_X--;
				index -= 3;
				printImdata();
				choice = _getch();

				if (choice == 'e') {
					MODE = 2;
					printImdata();
					MODE = 1;
					color_choice = _getch();

					color_set(color_choice, index);
					printImdata(color_choice);
					choice = 'z';
				}
			}
#ifdef DEBUG
			cout << "left x: " << pos_X << "  Index Is " << index << "\n";
#endif DEBUG//debug
			break;
		case KEY_RIGHT:
			if (pos_X < width) {
				pos_X++;
				index += 3;
				printImdata();
				choice = _getch();

				if (choice == 'e') {
					MODE = 2;
					printImdata();
					MODE = 1;
					color_choice = _getch();

					color_set(color_choice, index);
					printImdata(color_choice);
					choice = 'z';
				}
			}
#ifdef DEBUG
			cout << "right x: " << pos_X << "  Index Is " << index << "\n";
#endif DEBUG//debug
			break;
		case '-':
			state = 0;
			break;

		default:
			break;
		}


	}

	MODE = 0;
}
void Image::Load_Image() {
	std::cout << "Please Enter Image Name Including .'Type': ";
	std::cin >> f_name;
	strcpy(this->f_name, f_name);
	this->image_data = stbi_load(f_name, &width, &Height, &channel, 3);
	this->im_size = width * Height;
	if (this->image_data == NULL) {
		std::cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
	}
	else {
		std::cout << "\nFile Loaded Succsesfully\n";
	}
}
void Image::Load_Image(const char *f_name) {
	strcpy(this->f_name, f_name);
	this->image_data = stbi_load((char*)f_name, &width, &Height, &channel, 3);
	this->im_size = width * Height;
	if (this->image_data == NULL) {
		std::cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
	}
	else {
		std::cout << "\nFile Loaded Succsesfully\n";
	}
}
void Image::Write_Image() {
	if (MODE == 4) {
		char solved[100];
		strcpy(solved, "Solved_");
		strcat(solved, this->f_name);
		if (channel > 3) {
			channel = 3;
		}
		stbi_write_jpg(solved, width, Height, channel, image_data, 100);
	}
	else {
		char s_name[50];
		char type[10];
		strcpy(type, ".jpg");
		std::cout << "Save As?: ";
		std::cin >> s_name;
		strcat(s_name, type);
		stbi_write_jpg(s_name, width, Height, channel, image_data, 100);

		std::cout << "\nFile Saved Succsfully As: " << s_name << std::endl;
	}
}
void Image::Write_Image(const char *f_name) {

	char s_name[50];
	char type[10];
	strcpy(type, ".jpg");
	strcpy(s_name, f_name);
	strcat(s_name, type);
	if (channel > 3) {
		channel = 3;
	}
	stbi_write_jpg(s_name, width, Height, channel, image_data, 100);

	std::cout << "\nFile Saved Succsfully As: " << s_name << std::endl;

}
void Image::Color_Spec(int w, int h, char color) {
	int pos = ((width * 3)*(h)+3 * (w));
	color_set(color, pos);
}
void Image::Color_Spec(int index, char color) {

	int pos = index;
	color_set(color, pos);
}
void Image::Color_Spec(int index, pixel const &color) {
	color_set(color, index);
}
void Image::Set_Pixel_By_Inedx(int index, uint8_t value) {
	this->image_data[index] = value;
}
float Image::Get_Angle_Between_Coordinates(int const start_x, int const start_y, int const target_x, int const target_y, const char *mode) {
	char m1[8], m2[8];
	strcpy(m1, "Radians");
	strcpy(m2, "Degrees");

	int product = start_x * target_x + start_y * target_y;
	double magnitde_start, magnitude_target, Alpha;
	magnitde_start = sqrt(pow(start_x, 2) + pow(start_y, 2));
	magnitude_target = sqrt(pow(target_x, 2) + pow(target_y, 2));
	Alpha = (product) / (magnitde_start*magnitude_target);
	if (strcmp(m2, mode) == 0) {
		return (float)(acos(Alpha) * (180) / PI);
	}
	else if (strcmp(m1, mode) == 0) {
		return (float)(acos(Alpha));
	}
	else {
		return NULL;
	}


	// +-------------+-------+------+
	// |     -1      | 180ø  |  ã   |
	// +-------------+-------+------+
	// | -0.8660254  | 150ø  | 5ã/6 |
	// | -0.7071068  | 135ø  | 3ã/4 |
	// |       -0.5  | 120ø  | 2ã/3 |
	// |          0  | 90ø   | ã/2  |
	// |        0.5  | 60ø   | ã/3  |
	// |  0.7071068  | 45ø   | ã/4  |
	// |  0.8660254  | 30ø   | ã/6  |
	// |          1  | 0ø    | 0    |
	// +-------------+-------+------+



}

void Image::operator+(Image const &a) {
	int regulator;
	if (a.width != this->width || a.Height != this->Height) {
		std::cout << "Error image size invalid\n";
		return;
	}
	else {

		for (int i = 0; i < a.Height*a.width * 3; i++) {
			regulator = a.image_data[i] + this->image_data[i];
			if (regulator > 255) {
				regulator /= 3;
			}
			this->image_data[i] = regulator;
		}
	}


}
void Image::operator-(Image const &b) {
	int regulator;
	if (b.width != this->width || b.Height != this->Height) {
		std::cout << "Error image size invalid\n";
		return;
	}
	else {

		for (int i = 0; i < b.Height*b.width * 3; i++) {
			regulator = b.image_data[i] - this->image_data[i];
			if (regulator < 0) {
				regulator *= -2;
			}
			else if (regulator > 255) {
				regulator /= 2;
			}
			this->image_data[i] = regulator;
		}
	}
}
void Image::operator/(Image const &b) {
	int regulator;
	if (b.width != this->width || b.Height != this->Height) {
		std::cout << "Error image size invalid\n";
		return;
	}
	else {

		for (int i = 0; i < b.Height*b.width * 3; i++) {
			if (b.image_data[i] == 0) {
				regulator = this->image_data[i] / (b.image_data[i] + 1);
			}
			else if (this->image_data[i] == 0) {
				regulator = this->image_data[i] / (b.image_data[i]);
			}
			else {
				regulator = this->image_data[i] / (b.image_data[i]);
			}
			this->image_data[i] = regulator;
		}
	}

}
void Image::operator=(Image const &b) {
	this->channel = b.channel;
	this->image_data = b.image_data;
	this->Height = b.Height;
	this->width = b.width;
	strcpy(this->f_name, b.f_name);
	this->im_size = b.im_size;
	this->pos_X = b.pos_X;
	this->pos_Y = b.pos_Y;
	this->Pixel_Matrix = b.Pixel_Matrix;
}
bool Image::operator==(Image const &b) {
	if (this->Height != b.Height || this->width != b.width || this->channel != b.channel) {
		return false;
	}
	else {
		for (int i = 0; i < width*Height * 3; i++) {
			if (this->image_data[i] != b.image_data[i]) {
				return false;
			}
		}
		return true;
	}
}
bool Image::operator!=(Image const &b) {
	if (this->operator==(b) == true) {
		return false;
	}
	else {
		return true;
	}
}

void Image::init_pixel_matrix() {
	int j = 0, k = 0, clock = 0;
	Pixel_Matrix = new pixel*[Height];
	for (int i = 0; i < Height; i++) {
		Pixel_Matrix[i] = new pixel[width];
	}
	
	for (int i = 0; i < width*Height * 3; i += 3) {
		if (clock == width) {
			j++;
			k = 0;
			clock = 0;
		}
		Pixel_Matrix[j][k].index_range = i;
		Pixel_Matrix[j][k].r = (int)image_data[i];
		Pixel_Matrix[j][k].g = (int)image_data[i + 1];
		Pixel_Matrix[j][k].b = (int)image_data[i + 2];
		k++;
		clock++;
	}
}
void Image::init_pixel_matrix(const char *mode) {
	char m1[9];
	strcpy(m1, "Rewrite");
	if (strcmp(mode, m1) == 0) {
		if (Pixel_Matrix = nullptr) {
			this->Pixel_Matrix = new pixel*[Height];
			for (int i = 0; i < Height; i++) {
				Pixel_Matrix[i] = new pixel[width];
			}

		}
		else {
			//for (int i = 0; i < Height; i++) {
			//	free(Pixel_Matrix[i]);
			//}
			//free(Pixel_Matrix);

			//this->Pixel_Matrix = (pixel**)malloc(sizeof(pixel*)*Height);
			//for (int i = 0; i < Height; i++) {
			//	Pixel_Matrix[i] = (pixel*)malloc(sizeof(pixel)*width);
			//}

			int j = 0, k = 0, clock = 0, i = 0;
			for (i = 0; i < width*Height * 3; i += 3) {
				if (clock == width) {
					j++;
					k = 0;
					clock = 0;
				}
				Pixel_Matrix[j][k].index_range = i;
				Pixel_Matrix[j][k].r = image_data[i];
				Pixel_Matrix[j][k].g = image_data[i + 1];
				Pixel_Matrix[j][k].b = image_data[i + 2];
				k++;
				clock++;
			}
		}
	}
}
pixel Image::Avrage_Sigment_Color(pixel **pix_sigment, int rows, int cols) {

	//ver 1 un-if
	/*	vector<pixel> analysis;
	unsigned max_size=0, max_index=0;
	analysis.push_back(pix_sigment[0][0]);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {

			for (int k = 0; k < analysis.size(); k++) {
				if (analysis[k] == pix_sigment[i][j]) {
					analysis[k].analysis++;
					if (analysis[k].analysis > max_size) {
						max_index = k;
						max_size = analysis[k].analysis;
					}
				}
				else {
					analysis.push_back(pix_sigment[i][j]);
				}
			}

		}
	}

	return analysis[max_index];*/

	//ver2 soft
	/*
	pixel temp;
	temp.r = 0;
	temp.g = 0;
	temp.b = 0;
	int red = 0, green = 0, blue = 0, black = 0, white = 0, gray = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			switch (decode_color(pix_sigment[i][j].r, pix_sigment[i][j].g, pix_sigment[i][j].b))
			{
			case 'r':
				red++;
				break;
			case 'b':
				blue++;
				break;
			case 'g':
				green++;
				break;
			case 'W':
				white++;
				break;
			case 'B':
				black++;
				break;
			default:
				temp.r = pix_sigment[i][j].r;
				temp.g = pix_sigment[i][j].g;
				temp.b = pix_sigment[i][j].b;
				break;
			}
		}
	}



	return temp;
	*/

	//ver3 hard
	unsigned max_size = 0, max_index = 0;
	unsigned *hash_i = (unsigned*)calloc(255 * 3, sizeof(unsigned));
	unsigned *hash_j = (unsigned*)calloc(255 * 3, sizeof(unsigned));
	unsigned *hash_count = (unsigned*)calloc(255 * 3, sizeof(unsigned));
	pixel temp;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			hash_i[pix_sigment[i][j].r + pix_sigment[i][j].g + pix_sigment[i][j].b] = i;
			hash_j[pix_sigment[i][j].r + pix_sigment[i][j].g + pix_sigment[i][j].b] = j;
			hash_count[pix_sigment[i][j].r + pix_sigment[i][j].g + pix_sigment[i][j].b]++;


		}
	}

	for (int i = 0; i < 755; i++) {
		if (hash_count[i] > max_size) {
			max_size = hash_count[i];
			max_index = i;
		}
	}
	temp.r = pix_sigment[hash_i[max_index]][hash_j[max_index]].r;
	temp.g = pix_sigment[hash_i[max_index]][hash_j[max_index]].g;
	temp.b = pix_sigment[hash_i[max_index]][hash_j[max_index]].b;

	return temp;
}
void Image::Compress() {
	std::vector<int> comp_levels;
	int choice;
	gcd_list(this->width, this->Height, comp_levels);
	if (comp_levels.size() == 1) {
		std::cout << "No Possible Compression Option Found" << std::endl;
		return;
	}
	else {
		system("cls");
		std::cout << "Choose Compression Level:\n";
		for (unsigned i = 1; i < comp_levels.size(); i++) {
			std::cout << i << ") " << comp_levels[i] << std::endl;
		}
		std::cout << std::endl;
		std::cin >> choice;
		int j = 0, k = 0, start_row = 0, start_col = 0, si = 0, sj = 0, index = 0;
		pixel A_color;

		unsigned char *compressed = (unsigned char*)calloc((this->width)*(this->Height) * 3, sizeof(char));
		init_pixel_matrix();

		pixel **pixel_sigment = (pixel**)malloc(sizeof(pixel*)* comp_levels[choice]);
		for (int i = 0; i < comp_levels[choice]; i++) {
			pixel_sigment[i] = (pixel*)malloc(sizeof(pixel)*(comp_levels[choice]));
		}

		while (true) {

			for (int i = start_row; i < start_row + comp_levels[choice]; i++) {

				for (j = start_col; j < start_col + comp_levels[choice]; j++) {
					pixel_sigment[si][sj] = Pixel_Matrix[i][j];
					sj++;
				}
				si++;
				sj = 0;
			}
			A_color = Avrage_Sigment_Color(pixel_sigment, comp_levels[choice], comp_levels[choice]);
			si = sj = 0;


			for (int i = start_row; i < start_row + comp_levels[choice]; i++) {

				for (j = start_col; j < start_col + comp_levels[choice]; j++) {
					Pixel_Matrix[i][j].r = A_color.r;
					Pixel_Matrix[i][j].g = A_color.g;
					Pixel_Matrix[i][j].b = A_color.b;


				}

			}


			start_col += comp_levels[choice];
			if (start_col == width && start_row != Height) {
				start_row += comp_levels[choice];
				start_col = 0;
				if (start_row == Height) {
					break;
				}
			}



		}



		for (int i = 0; i < Height; i++) {
			for (j = 0; j < width; j++) {
				compressed[index++] = Pixel_Matrix[i][j].r;
				compressed[index++] = Pixel_Matrix[i][j].g;
				compressed[index++] = Pixel_Matrix[i][j].b;

			}

		}

		stbi_write_jpg("Compressed.jpg", width, Height, 3, compressed, 100);

	}





}

void Image::Text_To_Image(const char *file_name)
{
	std::fstream file;
	char cur_char;
	unsigned short mode;
	int number_of_chars = 0, pixel_num = 0, index = 0, width = 0, height = 0;
	unsigned char *new_image;
	file.open(file_name);

	if (!file.is_open()) {
		return;
	}

	std::cout << "Please Input Decode Mode:\n.)Press 1 For Raw\n.)Press 2 For Enhanced\nInput: ";
	std::cin >> mode;
	if (mode == 1) {
		while (!file.eof()) {
			file.get(cur_char);
			number_of_chars++;
		}

		file.clear();
		file.seekg(0, std::ios::beg);
		if (number_of_chars % 3 == 0) {
			pixel_num = number_of_chars / 3;
		}
		else {
			pixel_num = (number_of_chars / 3) + 1;
		}
		partition_pixels(height, width, pixel_num);
		new_image = (unsigned char*)calloc((width)*height * 3, sizeof(unsigned char));

		while (!file.eof()) {
			file.get(cur_char);
			new_image[index++] = (int)cur_char;
		}
	}
	else {
		while (!file.eof()) {
			file.get(cur_char);
			number_of_chars++;
		}

		file.clear();
		file.seekg(0, std::ios::beg);
		if (number_of_chars % 3 == 0) {
			pixel_num = number_of_chars / 3;
		}
		else {
			pixel_num = (number_of_chars / 3) + 1;
		}
		partition_pixels(height, width, pixel_num);
		new_image = (unsigned char*)calloc((width)*height * 3, sizeof(unsigned char));

		while (!file.eof()) {
			file.get(cur_char);
			new_image[index++] = (int)cur_char + rand() % 64;
		}
	}
	stbi_write_jpg("ImageFromText.jpg", width, height, 3, new_image, 100);

	file.close();
}
void Image::Image_To_Text(const char *Image_name) {
	this->Load_Image(Image_name);
	for (int i = 0; i < Height*width * 3; i++) {
		std::cout << (char)image_data[i];
	}
}
void Image::Insert_Text_Into_Image(const char *file_name, const char *Image_Name) {
	this->Load_Image(Image_Name);
	std::fstream file;
	char cur_char;
	int index = 0, number_of_chars = 0;
	file.open(file_name);

	if (!file.is_open()) {
		return;
	}

	while (!file.eof()) {
		file.get(cur_char);
		number_of_chars++;
	}

	file.clear();
	file.seekg(0, std::ios::beg);

	if (number_of_chars < (this->Height*this->width * 3)) {
		while (!file.eof()) {
			file.get(cur_char);
			if (index >= (this->Height*this->width * 3)) {
				break;
			}
			if (file.eof()) {
				file.clear();
				file.seekg(0, std::ios::beg);
			}
			if ((int)image_data[index] + (int)cur_char > 255) {
				image_data[index] = ((int)image_data[index] + (int)cur_char) % 255;
				index++;
			}
			else {
				image_data[index] = +(int)cur_char;
				index++;
			}
		}
	}
	else {
		while (!file.eof()) {
			file.get(cur_char);
			if (index >= (this->Height*this->width * 3)) {
				break;
			}
			if ((int)image_data[index] + (int)cur_char > 255) {
				image_data[index] = ((int)image_data[index] + (int)cur_char) % 255;
				index++;
			}
			else {
				image_data[index] = +(int)cur_char;
				index++;
			}
		}

	}
	this->Write_Image("AfterTextInsertion");

	file.close();
}


void Image::Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (center_x + s_width > width || center_y + s_height >= Height || center_x - s_width < 0 || center_y - s_height < 0) {
		std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		std::cout << "Height Of Image: " << Height << std::endl;
		std::cout << "Width Of Image: " << width << std::endl;
		std::cout << std::endl;
		return;
	}
	for (int i = center_x - s_width; i <= center_x + s_width; i++) {
		//set_pixel_color(Pixel_Matrix[center_y + s_width][i], color);
		Color_Spec(Pixel_Matrix[center_y + s_height][i].index_range, color);
	}
	for (int i = center_x - s_width; i <= center_x + s_width; i++) {
		//set_pixel_color(Pixel_Matrix[center_y - s_width][i], color);
		Color_Spec(Pixel_Matrix[center_y - s_height][i].index_range, color);
	}
	for (int i = center_y - s_height; i <= center_y + s_height; i++) {
		//set_pixel_color(Pixel_Matrix[i][center_x-s_width], color);
		Color_Spec(Pixel_Matrix[i][center_x - s_width].index_range, color);
	}
	for (int i = center_y - s_height; i <= center_y + s_height; i++) {
		//set_pixel_color(Pixel_Matrix[i][center_x + s_width], color);
		Color_Spec(Pixel_Matrix[i][center_x + s_width].index_range, color);
	}

}
void Image::Draw_Square(const int center_x, const int center_y,
	const int s_width, const int s_height, const unsigned char color, const char *mode)
{
	char mode_f[5], mode_c[10];
	strcpy(mode_f, "Fill");
	strcpy(mode_c, "Checkered");
	if (strcmp(mode_f, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i++) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
	if (strcmp(mode_c, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			if (this->Pixel_Matrix == nullptr) {
				init_pixel_matrix();
			}
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i += 2) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
}
void Image::Draw_Square(const int center_x, const int center_y, const int s_width,
	const int s_height, const unsigned char color, const char *mode, const unsigned space)
{
	char mode_c[10];
	strcpy(mode_c, "Checkered");
	if (strcmp(mode_c, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i += space) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
}

void Image::Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (center_x + s_width > width || center_y + s_height >= Height || center_x - s_width < 0 || center_y - s_height < 0) {
		std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		std::cout << "Height Of Image: " << Height << std::endl;
		std::cout << "Width Of Image: " << width << std::endl;
		std::cout << std::endl;
		return;
	}
	for (int i = center_x - s_width; i <= center_x + s_width; i++) {
		//set_pixel_color(Pixel_Matrix[center_y + s_width][i], color);
		Color_Spec(Pixel_Matrix[center_y + s_height][i].index_range, color);
	}
	for (int i = center_x - s_width; i <= center_x + s_width; i++) {
		//set_pixel_color(Pixel_Matrix[center_y - s_width][i], color);
		Color_Spec(Pixel_Matrix[center_y - s_height][i].index_range, color);
	}
	for (int i = center_y - s_height; i <= center_y + s_height; i++) {
		//set_pixel_color(Pixel_Matrix[i][center_x-s_width], color);
		Color_Spec(Pixel_Matrix[i][center_x - s_width].index_range, color);
	}
	for (int i = center_y - s_height; i <= center_y + s_height; i++) {
		//set_pixel_color(Pixel_Matrix[i][center_x + s_width], color);
		Color_Spec(Pixel_Matrix[i][center_x + s_width].index_range, color);
	}

}
void Image::Draw_Square(const int center_x, const int center_y,
	const int s_width, const int s_height, pixel const &color, const char *mode)
{
	char mode_f[5], mode_c[10], mode_C[10];
	strcpy(mode_f, "Fill");
	strcpy(mode_c, "Checkered");
	strcpy(mode_C, "Corners");

	if (strcmp(mode_f, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i++) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
	else if (strcmp(mode_c, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			if (this->Pixel_Matrix == nullptr) {
				init_pixel_matrix();
			}
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i += 2) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
	else if (strcmp(mode_C, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			if (this->Pixel_Matrix == nullptr) {
				init_pixel_matrix();
			}
		}

		if (center_x >= width || center_y >= Height || s_width >= width || s_height >= Height || center_x <= 0 || center_y <= 0 || s_width <= 0 || s_height <= 0
			|| center_x >= Height || center_y >= width || s_width >= Height || s_height >= width) {

			std::cout << "There Was A drawing Error\n";
			return;
		}
		this->Draw_Line(center_x, center_y, s_width, center_y, color);
		this->Draw_Line(center_x, center_y, center_x, s_height, color);
		this->Draw_Line(center_x, s_height, s_width, s_height, color);
		this->Draw_Line(s_width, center_y, s_width, s_height, color);



	}
}
void Image::Draw_Square(const int center_x, const int center_y, const int s_width,
	const int s_height, pixel const &color, const char *mode, const unsigned space)
{
	char mode_c[10];
	strcpy(mode_c, "Checkered");
	if (strcmp(mode_c, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << "\n";
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i += space) {
				Color_Spec(Pixel_Matrix[j][i].index_range, color);
			}
		}
	}
}



void Image::Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	int x, y, r2;
	unsigned i = 0;
	if (center_x + c_radius >= width || center_x - c_radius <= 0 || center_y + c_radius >= Height || center_y - c_radius <= 0) {
		std::cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		std::cout << "Height Of Image: " << Height << std::endl;
		std::cout << "Width Of Image: " << width << std::endl;
		std::cout << std::endl;
		return;
	}
	r2 = c_radius * c_radius;
	//ver1


	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y + y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y + y][center_x - x].index_range, color);
	}
	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y - y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x - x].index_range, color);
	}
	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y - x][center_x + y].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - x][center_x - y].index_range, color);
	}
	//ver2
	/*
	Color_Spec(Pixel_Matrix[center_y][center_x+c_radius].index_range, color);
	Color_Spec(Pixel_Matrix[center_y][center_x - c_radius].index_range, color);
	for (x = 1; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y +y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y + y][center_x - x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x - x].index_range, color);
	}*/

}
void Image::Draw_Circle(const int center_x, const int center_y, const int c_radius, pixel const &color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	int x, y, r2;
	unsigned i = 0;
	if (center_x + c_radius >= width || center_x - c_radius <= 0 || center_y + c_radius >= Height || center_y - c_radius <= 0) {
		std::cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		std::cout << "Height Of Image: " << Height << std::endl;
		std::cout << "Width Of Image: " << width << std::endl;
		std::cout << std::endl;
		return;
	}
	r2 = c_radius * c_radius;
	//ver1


	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y + y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y + y][center_x - x].index_range, color);
	}
	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y - y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x - x].index_range, color);
	}
	for (x = -c_radius; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y - x][center_x + y].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - x][center_x - y].index_range, color);
	}
	//ver2
	/*
	Color_Spec(Pixel_Matrix[center_y][center_x+c_radius].index_range, color);
	Color_Spec(Pixel_Matrix[center_y][center_x - c_radius].index_range, color);
	for (x = 1; x <= c_radius; x++) {
		y = (int)(sqrt(r2 - x * x) + 0.5);
		Color_Spec(Pixel_Matrix[center_y +y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y + y][center_x - x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x + x].index_range, color);
		Color_Spec(Pixel_Matrix[center_y - y][center_x - x].index_range, color);
	}*/

}

void Image::Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color, const char *mode) {
	char mode_f[5];
	strcpy(mode_f, "Fill");
	if (strcmp(mode_f, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		int x, y;
		unsigned i = 0;
		if (center_x + c_radius > width || center_x - c_radius <0 || center_y + c_radius > Height || center_y - c_radius < 0) {
			std::cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (y = -c_radius; y <= c_radius; y++)
			for (x = -c_radius; x <= c_radius; x++)
				if ((x * x) + (y * y) <= (c_radius * c_radius))
					Color_Spec(Pixel_Matrix[center_y + y][center_x + x].index_range, color);
	}
}
void Image::Draw_Circle(const int center_x, const int center_y, const int c_radius, const pixel color, const char *mode) {
	char mode_f[5];
	strcpy(mode_f, "Fill");
	if (strcmp(mode_f, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		int x, y;
		unsigned i = 0;
		if (center_x + c_radius > width || center_x - c_radius <0 || center_y + c_radius > Height || center_y - c_radius < 0) {
			std::cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			std::cout << "Height Of Image: " << Height << std::endl;
			std::cout << "Width Of Image: " << width << std::endl;
			std::cout << std::endl;
			return;
		}
		for (y = -c_radius; y <= c_radius; y++)
			for (x = -c_radius; x <= c_radius; x++)
				if ((x * x) + (y * y) <= (c_radius * c_radius))
					Color_Spec(Pixel_Matrix[center_y + y][center_x + x].index_range, color);
	}
}

void Image::Draw_Line(const int start_x, const int start_y, const int target_y, const unsigned char color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	if (target_y > this->Height || start_y > this->Height || start_y < 0 || start_x > width || start_x < 0) {
		std::cout << "Line Out Of Image Range\nDraw Action Aborted\n";
		return;
	}

	if (start_y < target_y) {
		for (int i = start_y; i < target_y; i++) {
			Color_Spec(Pixel_Matrix[i][start_x].index_range, color);
		}
	}
	else {
		for (int i = start_y; i > target_y; i--) {
			Color_Spec(Pixel_Matrix[i][start_x].index_range, color);
		}
	}

}
void Image::Draw_Line(const int start_y, const int start_x, const int target_y, const int target_x, const unsigned char color) {
	this->BresenhamsLine(start_y, start_x, target_y, target_x, color);
	/*
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	if (target_y > this->Height || start_y > this->Height || start_y < 0 || start_x > width || start_x < 0 || target_x > width) {
		cout << "Line Out Of Image Range\nDraw Action Aborted\n";
		return;
	}
	int marker = 0, Y;
	float Error, DeltaError, DeltaX, DeltaY;

	if (start_y == target_y) {

		if (target_x > start_x) {

			for (int i = start_x; i < target_x; i++) {
				Color_Spec(Pixel_Matrix[start_y][i].index_range, color);

			}
		}
		else {
			for (int i = start_x; i > target_x; i--) {
				Color_Spec(Pixel_Matrix[start_y][i].index_range, color);

			}
		}
	}
	else if (start_x == target_x) {

		if (target_y > start_y) {
			for (int i = start_y; i < target_y; i++) {
				Color_Spec(Pixel_Matrix[i][start_x].index_range, color);


			}
		}
		else {
			for (int i = start_y; i > target_y; i--) {
				Color_Spec(Pixel_Matrix[i][start_x].index_range, color);


			}
		}
	}


	else if (start_x != target_x || start_y != target_y) {
		int marker = 0;
		if (start_y > target_y) {
			if (target_x > start_x) {
				///
				DeltaY = start_y - target_y;
				DeltaX = start_x - target_x;
				Error = 0;
				DeltaError = abs(DeltaY / DeltaX);
				Y = start_y;

				for (int i = start_x; i <= target_x; i++) {
					Color_Spec(Pixel_Matrix[Y][i].index_range, color);
					Error += DeltaError;
					if (Error >= 0.5) {
						Error -= 1.0;
						Y--;
					}
				}
			}
			else {
				DeltaY = start_y - target_y;
				DeltaX = start_x - target_x;
				Error = 0;
				DeltaError = abs(DeltaY / DeltaX);
				Y = start_y;
				///
				for (int i = start_x; i >= target_x; i--) {
					Color_Spec(Pixel_Matrix[Y][i].index_range, color);
					Error += DeltaError;
					if (Error >= 0.5) {
						Error -= 1.0;
						Y--;
					}
				}
			}
		}
		else {
			if (target_x > start_x) {

				DeltaY = start_y - target_y;
				DeltaX = start_x - target_x;
				Error = 0;
				DeltaError = abs(DeltaY / DeltaX);
				Y = start_y;

				for (int i = start_x; i < target_x; i++) {
					Color_Spec(Pixel_Matrix[Y][i].index_range, color);
					Error += DeltaError;
					if (Error >= 0.5) {
						Error -= 1.0;
						Y++;
					}
				}
			}
			else {
				DeltaY = start_y - target_y;
				DeltaX = start_x - target_x;
				Error = 0;
				DeltaError = abs(DeltaY / DeltaX);
				Y = start_y;
				//
				for (int i = start_x; i > target_x; i--) {
					Color_Spec(Pixel_Matrix[Y][i].index_range, color);
					Error += DeltaError;
					if (Error >= 0.5) {
						Error -= 1.0;
						Y++;
					}
				}
			}
		}
	}*/

}
void Image::Draw_Line(const int start_y, const int start_x, const int target_y, const int target_x, pixel const &color) {

	this->BresenhamsLine(start_y, start_x, target_y, target_x, color);
}
void Image::Draw_Line(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color, int const &line_width) {
	if (line_width > 0) {
		float dx, sx, dy, sy, err, e2;
		int flag = line_width;
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		float x0 = (float)start_x, x1 = (float)target_x, y0 = (float)start_y, y1 = (float)target_y;
		dx = (float)abs(target_x - start_x);
		sx = (float)(start_x < target_x ? 1 : -1);
		dy = (float)(-abs(target_y - start_y));
		sy = (float)(start_y < target_y ? 1 : -1);
		err = dx + dy;  /* error value e_xy */
		while (true) {
			if (x0 == x1 && y0 == y1) {
				this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);
				if (line_width > 0) {

					if (start_y != target_y) {
						for (int i = 1; i <= line_width; i++) {
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) + i].index_range, color);

							this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0)].index_range, color);
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) + i].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) - i].index_range, color);
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) - i].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) - i].index_range, color);
							this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0)].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) + i].index_range, color);
						}
					}
					else {
						for (int i = 1; i <= line_width; i++) {
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) + i].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0)].index_range, color);
							this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) + i].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) - i].index_range, color);
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) - i].index_range, color);

							this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) - i].index_range, color);
							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0)].index_range, color);

							//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) + i].index_range, color);
						}
					}


				}



				break;
			}

			this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);
			if (line_width > 0) {
				if (start_y != target_y) {
					for (int i = 1; i <= line_width; i++) {
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) + i].index_range, color);

						this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0)].index_range, color);
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) + i].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) - i].index_range, color);
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) - i].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) - i].index_range, color);
						this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0)].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) + i].index_range, color);
					}
				}
				else {
					for (int i = 1; i <= line_width; i++) {
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) + i].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0)].index_range, color);
						this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) + i].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) - i].index_range, color);
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) + i][(int)floor(y0) - i].index_range, color);

						this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0) - i].index_range, color);
						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0)].index_range, color);

						//this->Color_Spec(this->Pixel_Matrix[(int)floor(x0) - i][(int)floor(y0) + i].index_range, color);
					}
				}




			}

			e2 = 2 * err;
			if (e2 >= dy) {
				err += dy; /* e_xy+e_x > 0 */
				x0 += sx;
			}
			if (e2 <= dx) {
				err += dx;
				y0 += sy;
			}

		}
	}
	else {
		this->BresenhamsLine(start_x, start_y, target_x, target_y, color);
	}
}

void Image::LineHigh(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color) {
	double DeltaX, DeltaY, xi, D, X;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}


	DeltaX = target_x - start_y;
	DeltaY = target_y - target_x;

	xi = 1;
	if (DeltaX < 0) {
		xi = -1;
		DeltaX = -DeltaX;
	}
	D = 2 * DeltaX - DeltaY;
	X = start_x;

	for (int y = start_y; y <= target_y; y++) {
		Color_Spec(this->Pixel_Matrix[y][(int)X].index_range, color);
		if (D > 0) {
			X = X + xi;
			D = D - 2 * DeltaY;
		}
		D = D + 2 * DeltaX;
	}

}
void Image::LineLow(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color) {
	double DeltaX, DeltaY, yi, D, Y;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	DeltaX = target_x - start_y;
	DeltaY = target_y - target_x;
	yi = 1;
	if (DeltaY < 0) {
		yi = -1;
		DeltaY = -DeltaY;
	}
	D = 2 * DeltaY - DeltaX;
	Y = start_y;

	for (int x = start_x; x <= target_x; x++) {
		Color_Spec(this->Pixel_Matrix[(int)Y][x].index_range, color);
		if (D > 0) {
			Y = Y + yi;
			D = D - 2 * DeltaX;
		}
		D = D + 2 * DeltaY;
	}
}
void Image::BresenhamsLine(const int start_y, const int start_x, const int target_y, const int target_x, const unsigned char color) {
	float dx, sx, dy, sy, err, e2;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	///

	float x0 = (float)start_y, x1 = (float)target_y, y0 = (float)start_x, y1 = (float)target_x;
	dx = (float)(abs(target_y - start_y));
	sx = (float)(start_y < target_y ? 1 : -1);
	dy = (float)(-abs(target_x - start_x));
	sy = (float)(start_x < target_x ? 1 : -1);
	err = dx + dy;  //error value
	while (true) {
		if (x0 == x1 && y0 == y1) {
			this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);
			break;
		}

		this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);

		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}

	}
}
void Image::BresenhamsLine(const int start_y, const int start_x, const int target_y, const int target_x, pixel const &color) {
	double dx, sx, dy, sy, err, e2;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	///

	double x0 = start_y, x1 = target_y, y0 = start_x, y1 = target_x;
	dx = abs(target_y - start_y);
	sx = start_y < target_y ? 1 : -1;
	dy = -abs(target_x - start_x);
	sy = start_x < target_x ? 1 : -1;
	err = dx + dy;  //error value
	while (true) {
		if (x0 == x1 && y0 == y1) {
			this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);
			break;
		}

		this->Color_Spec(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range, color);

		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}

	}
}



void Image::Draw_Graph(const int graph_height, const int graph_width, const int Space_Between_Lines) {
	if (graph_height > this->Height || graph_width > this->width) {
		std::cout << "Selected Graph Size Is Larger Then Canvas Size\n";
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	int cx, cy, index = 0, xy_num = 0;
	std::stringstream conv;
	std::string catcher;
	this->Get_Center(cx, cy);

	Draw_Square(cx, cy, graph_width / 2, graph_height / 2, 'B');
	Draw_Square(cx, cy, (graph_width / 2) - 1, (graph_height / 2) - 1, 'B');
	Draw_Square(cx, cy, (graph_width / 2) - 2, (graph_height / 2) - 2, 'B');

	xy_num = graph_height / Space_Between_Lines;

	for (int i = (Height - graph_height) / 2; i <= Height - ((Height - graph_height) / 2); i += Space_Between_Lines) {
		if (i == (Height - graph_height) / 2) {
			Draw_Line(i, (width - graph_width) / 2, i, (width - graph_width) / 2 + graph_width, 'B');
			conv << xy_num;
			catcher = conv.str();
			Draw_Text(i, (width - graph_width) / 2 - 12, catcher.c_str());
		}
		else {
			Draw_Line(i, (width - graph_width) / 2 - 5, i, (width - graph_width) / 2 + graph_width, 'B');
			conv << xy_num;
			catcher = conv.str();
			Draw_Text(i, (width - graph_width) / 2 - 12, catcher.c_str());
		}
		xy_num--;
		catcher.clear();
		conv.str(std::string());
	}
	xy_num = 0;
	for (int i = (width - graph_width) / 2; i <= (width - graph_width) / 2 + graph_width; i += Space_Between_Lines) {

		Draw_Line((Height - graph_height) / 2, i, (Height - graph_height) / 2 + graph_height + 5, i, 'B');
		conv << xy_num;
		catcher = conv.str();
		Draw_Text((Height - graph_height) / 2 + graph_height + 7, i - 4, catcher.c_str());
		xy_num++;
		catcher.clear();
		conv.str(std::string());
	}





}
void Image::Draw_Text(const int center_y, const int center_x, const char *text) {
	int text_length = strlen(text);
	int start_x, end_x, draw_y, flag = 0, temp, count = 0;
	LibCharacters Set;
	if (center_x + (9 * (text_length / 2)) > width || center_x - (9 * (text_length / 2)) < 0
		|| center_y + 4 > Height || center_y - 4 < 0) {
		std::cout << "Text Longer The Image Frame, Aborting...\n";
		std::cout << "X selected + Text Length= " << center_x + (9 * (text_length / 2)) << "\n";
		std::cout << "X selected - Text Length= " << center_x - (9 * (text_length / 2)) << "\n";
		return;
	}

	start_x = center_x - (9 * (text_length / 2));
	draw_y = center_y - 4;
	end_x = center_x + (9 * (text_length / 2));


	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = 0; text[i] != '\0'; i++) {

		switch (text[i])
		{

		case '0':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Zero.Zero[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '1':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_One.One[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '2':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Two.Two[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '3':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Three.Three[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '4':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Four.Four[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '5':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Five.Five[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '6':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Six.Six[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '7':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Seven.Seven[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '8':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Eight.Eight[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '9':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Nine.Nine[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'A':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_A.A[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'B':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_B.B[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'C':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_C.C[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'D':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_D.D[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'E':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_E.E[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'F':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_F.F[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'G':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_G.G[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'H':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_H.H[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'I':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_I.I[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'J':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_J.J[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'K':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_K.K[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'L':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_L.L[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'M':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_M.M[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'N':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_N.N[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'O':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_O.O[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'P':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_P.P[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Q':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Q.Q[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'R':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_R.R[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'S':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_S.S[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'T':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_T.T[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'U':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_U.U[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'V':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_V.V[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'W':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_W.W[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;

			break;

		case 'X':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_X.X[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Y':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Y.Y[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Z':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Z.Z[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '?':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Quesiton_Mark.question_mark[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '!':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Exclamation_Point.exclamation_point[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '(':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Left_Braket.Left_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ')':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Right_Braket.Right_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '&':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Ampersand.Ampersand[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ',':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Comma.Comma[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '[':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Squaure_Braket_Left.Square_Braket_Left[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ']':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Square_Braket_Right.Square_Braket_Right[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ' ':
			temp += 9;
			break;

		case ':':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Colon.Colon[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '=':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.EqualSign.ES[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;



		case '+':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.PlusSign.PLS[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		default:
			break;
		}

		draw_y = center_y - 4;
		start_x = temp;
		start_x += 9;

	}


}
void Image::Draw_Text(const int center_y, const int center_x, const char *text, const char color) {
	int text_length = strlen(text);
	int start_x, end_x, draw_y, flag = 0, temp, count = 0;
	LibCharacters Set;
	if (center_x + (9 * (text_length / 2)) > width || center_x - (9 * (text_length / 2)) < 0
		|| center_y + 4 > Height || center_y - 4 < 0) {
		std::cout << "Text Longer The Image Frame, Aborting...\n";
		std::cout << "X selected + Text Length= " << center_x + (9 * (text_length / 2)) << "\n";
		std::cout << "X selected - Text Length= " << center_x - (9 * (text_length / 2)) << "\n";
		return;
	}

	start_x = center_x - (9 * (text_length / 2));
	draw_y = center_y - 4;
	end_x = center_x + (9 * (text_length / 2));


	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = 0; text[i] != '\0'; i++) {

		switch (text[i])
		{

		case '0':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Zero.Zero[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '1':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_One.One[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '2':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Two.Two[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '3':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Three.Three[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '4':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Four.Four[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '5':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Five.Five[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '6':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Six.Six[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '7':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Seven.Seven[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '8':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Eight.Eight[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '9':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Nine.Nine[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'A':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_A.A[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'B':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_B.B[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'C':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_C.C[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'D':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_D.D[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'E':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_E.E[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'F':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_F.F[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'G':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_G.G[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'H':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_H.H[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'I':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_I.I[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'J':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_J.J[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'K':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_K.K[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'L':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_L.L[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'M':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_M.M[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'N':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_N.N[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'O':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_O.O[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'P':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_P.P[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Q':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Q.Q[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'R':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_R.R[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'S':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_S.S[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'T':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_T.T[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'U':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_U.U[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'V':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_V.V[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'W':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_W.W[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;

			break;

		case 'X':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_X.X[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Y':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Y.Y[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Z':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Z.Z[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '?':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Quesiton_Mark.question_mark[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '!':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Exclamation_Point.exclamation_point[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '(':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Left_Braket.Left_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ')':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Right_Braket.Right_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '&':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Ampersand.Ampersand[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ',':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Comma.Comma[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '[':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Squaure_Braket_Left.Square_Braket_Left[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ']':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Square_Braket_Right.Square_Braket_Right[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ' ':
			temp += 9;
			break;

		case ':':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Colon.Colon[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case '=':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.EqualSign.ES[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case '+':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.PlusSign.PLS[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		default:
			break;
		}

		draw_y = center_y - 4;
		start_x = temp;
		start_x += 9;

	}


}
void Image::Draw_Text(const int center_y, const int center_x, const char *text, pixel const &color) {

	int text_length = strlen(text);
	int start_x, end_x, draw_y, flag = 0, temp, count = 0;
	LibCharacters Set;
	if (center_x + (9 * (text_length / 2)) > width || center_x - (9 * (text_length / 2)) < 0
		|| center_y + 4 > Height || center_y - 4 < 0) {
		std::cout << "Text Longer The Image Frame, Aborting...\n";
		std::cout << "X selected + Text Length= " << center_x + (9 * (text_length / 2)) << "\n";
		std::cout << "X selected - Text Length= " << center_x - (9 * (text_length / 2)) << "\n";
		return;
	}

	start_x = center_x - (9 * (text_length / 2));
	draw_y = center_y - 4;
	end_x = center_x + (9 * (text_length / 2));


	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = 0; text[i] != '\0'; i++) {

		switch (text[i])
		{

		case '0':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Zero.Zero[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '1':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_One.One[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '2':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Two.Two[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '3':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Three.Three[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '4':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Four.Four[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '5':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Five.Five[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '6':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Six.Six[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '7':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Seven.Seven[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '8':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Eight.Eight[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;
		case '9':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Number_Nine.Nine[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'A':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_A.A[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'B':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_B.B[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'C':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_C.C[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'D':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_D.D[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'E':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_E.E[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'F':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_F.F[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'G':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_G.G[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'H':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_H.H[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'I':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_I.I[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'J':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_J.J[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'K':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_K.K[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'L':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_L.L[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'M':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_M.M[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'N':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_N.N[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'O':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_O.O[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'P':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_P.P[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Q':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Q.Q[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case 'R':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_R.R[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'S':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_S.S[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'T':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_T.T[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'U':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_U.U[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'V':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_V.V[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'W':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_W.W[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;

			break;

		case 'X':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_X.X[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Y':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Y.Y[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case 'Z':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Letter_Z.Z[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '?':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Quesiton_Mark.question_mark[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '!':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Exclamation_Point.exclamation_point[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '(':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Left_Braket.Left_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ')':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Right_Braket.Right_Braket[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '&':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Ampersand.Ampersand[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ',':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Comma.Comma[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case '[':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Squaure_Braket_Left.Square_Braket_Left[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;


		case ']':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Square_Braket_Right.Square_Braket_Right[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case ' ':
			temp += 9;
			break;

		case ':':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.Colon.Colon[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, 'B');
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case '=':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.EqualSign.ES[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

		case '+':
			temp = start_x;
			while (flag != 81) {

				if ((flag + 1) % 9 == 0) {
					draw_y++;
					start_x = temp;
				}
				if (Set.PlusSign.PLS[flag] == 1) {
					Color_Spec(Pixel_Matrix[draw_y][start_x].index_range, color);
				}
				start_x++;
				flag++;
			}

			flag = 0;
			break;

	

		default:
			break;
		}

		draw_y = center_y - 4;
		start_x = temp;
		start_x += 9;

	}



}


void Image::Get_Center(int &center_x, int &center_y)const {
	center_x = width / 2;
	center_y = Height / 2;
}
void Image::Grayscale(int const &alter) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	int index = 0;
	for (int i = 0; i < Height; i++) {

		for (int j = 0; j < width; j++) {

			if (Pixel_Matrix[i][j].b >= Pixel_Matrix[i][j].r && Pixel_Matrix[i][j].b >= Pixel_Matrix[i][j].g) {
				Pixel_Matrix[i][j].r = Pixel_Matrix[i][j].b;
				Pixel_Matrix[i][j].g = Pixel_Matrix[i][j].b;
			}
			else if (Pixel_Matrix[i][j].r >= Pixel_Matrix[i][j].b &&Pixel_Matrix[i][j].r >= Pixel_Matrix[i][j].g) {
				Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].r;
				Pixel_Matrix[i][j].g = Pixel_Matrix[i][j].r;
			}
			else if (Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].r &&Pixel_Matrix[i][j].g >= Pixel_Matrix[i][j].b) {
				Pixel_Matrix[i][j].r = Pixel_Matrix[i][j].g;
				Pixel_Matrix[i][j].b = Pixel_Matrix[i][j].g;
			}

		}
	}
	if (alter == 1) {
		for (int i = 0; i < Height; i++) {

			for (int j = 0; j < width; j++) {

				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = Pixel_Matrix[i][j].b;

			}
		}
	}

}

void Image::Convert_Grayscale() {
	this->Grayscale(1);
}

int Image::Color_Distance(pixel const &a, pixel const &b) {
	int recored;
	recored = (a.b - b.b) + (a.r - b.r) + (a.g - b.g);
	if (recored < 0) {
		recored *= -1;
	}

	return recored;
}
double Image::Color_DistanceSq(pixel const &a, pixel const &b) {
	double  recored;
	recored = (b.r - a.r)*(b.r - a.r) + (b.g - a.g)*(b.g - a.g) + (b.b - a.b)*(b.b - a.b);
	return sqrt(recored);
}
void Image::Update_Pixel_Matrix() {
	int j = 0, k = 0, clock = 0;
	for (int i = 0; i < width*Height * 3; i += 3) {
		if (clock == width) {
			j++;
			k = 0;
			clock = 0;
		}
		Pixel_Matrix[j][k].index_range = i;
		Pixel_Matrix[j][k].r = (int)image_data[i];
		Pixel_Matrix[j][k].g = (int)image_data[i + 1];
		Pixel_Matrix[j][k].b = (int)image_data[i + 2];
		k++;
		clock++;
	}

}
void Image::Fill_In_Pixel_Frame(PixelFrame &frame) {
	for (auto k : frame) {
		Color_Spec(k.index_range, k);
	}
	this->Update_Pixel_Matrix();
}
void Image::Connect_VectorFrame_Via_Lines(VectorFrame &frame) {
	VectorFrame::iterator i;
	Color_Palette CSET;
	for (i = frame.begin(); i + 1 != frame.end(); i++) {
		this->Draw_Line((int)i->y, (int)i->x, (int)(i + 1)->y, (int)(i + 1)->x, CSET.Black);
	}
}

double Image::Image_Difference_Value(Image &b) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	if (b.Pixel_Matrix == nullptr) {
		b.init_pixel_matrix();
	}

	double result = 0;
	int index = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			result = result + Color_DistanceSq(Pixel_Matrix[i][j], b.Pixel_Matrix[i][j]);
		}
	}
	//for (int i = 0; i < this->Height*this->width * 3; i++) {
	//	result += this->image_data[i] - b.image_data[i];
	//}

	return result / Height * width;

}
float Image::Color_Delta(pixel const &A, pixel const &B) {
	long  R_Gag = ((long)(A.r + (long)(B.r)) / 2);
	long  r = (long)A.r - (long)B.r;
	long  g = (long)A.g - (long)B.g;
	long  b = (long)A.b - (long)B.b;
	return (float)(sqrt((((512 + R_Gag)*r*r) >> 8) + 4 * g*g + (((767 - R_Gag)*b*b) >> 8)));
}

bool Image::Distance_Neighbors(const float max_distance, int i, int j) {
	pixel center, point;
	center = Pixel_Matrix[i][j];
	double dist = 0;
	if (i - 1 < 0 && j + 1 < width && j - 1 > 0 && i + 1 < Height) {
		point = Pixel_Matrix[i][j + 1];
		dist = (double)(Color_DistanceSq(point, center));
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i][j - 1];
		dist = (double)Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j];
		dist = (double)Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j - 1];
		dist = (double)Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j + 1];
		dist = (double)Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}

	}
	if (i + 1 > Height && j + 1 < width && j - 1 > 0 && i - 1 > 0)
	{
		point = Pixel_Matrix[i][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}

	}
	if (j - 1 < 0 && i + 1 < Height && i - 1 > 0 && j + 1 < width) {
		point = Pixel_Matrix[i + 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
	}
	if (j + 1 > width && i + 1 < Height && i - 1 > 0 && j - 1 > 0) {
		point = Pixel_Matrix[i][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i - 1][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
	}

	return true;


}

double Image::Get_Neighbour_Mean_R(int const &i, int const &j) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].r;

	if (i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j].r;
		Divider++;
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].r;
		Divider++;

	}
	if (j + 1 <= width) {
		Mean += Pixel_Matrix[i][j + 1].r;
		Divider++;
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].r;
		Divider++;
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].r;
		Divider++;
	}
	if (j - 1 >= 0 && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].r;
		Divider++;
	}
	if (j + 1 <= width && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].r;
		Divider++;
	}
	if (j + 1 <= width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].r;
		Divider++;
	}
	return Mean / Divider;

}
double Image::Get_Neighbour_Mean_G(int const &i, int const &j) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].g;

	if (i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j].g;
		Divider++;
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].g;
		Divider++;

	}
	if (j + 1 <= width) {
		Mean += Pixel_Matrix[i][j + 1].g;
		Divider++;
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].g;
		Divider++;
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].g;
		Divider++;
	}
	if (j - 1 >= 0 && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].g;
		Divider++;
	}
	if (j + 1 <= width && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].g;
		Divider++;
	}
	if (j + 1 <= width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].g;
		Divider++;
	}
	return Mean / Divider;

}
double Image::Get_Neighbour_Mean_B(int const &i, int const &j) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].b;

	if (i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j].b;
		Divider++;
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].b;
		Divider++;

	}
	if (j + 1 <= width) {
		Mean += Pixel_Matrix[i][j + 1].b;
		Divider++;
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].b;
		Divider++;
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].b;
		Divider++;
	}
	if (j - 1 >= 0 && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].b;
		Divider++;
	}
	if (j + 1 <= width && i + 1 <= Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].b;
		Divider++;
	}
	if (j + 1 <= width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].b;
		Divider++;
	}
	return Mean / Divider;
}

double Image::Get_Neighbour_Mean_G(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].g * Kernel[1][1];

	if (i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j].g * Kernel[2][1];
		if (Kernel[2][1] != 0) {
			Divider++;
		}
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].g * Kernel[0][1];
		if (Kernel[0][1] != 0) {
			Divider++;
		}
	}
	if (j + 1 < width) {
		Mean += Pixel_Matrix[i][j + 1].g * Kernel[1][2];
		if (Kernel[1][2] != 0) {
			Divider++;
		}
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].g * Kernel[1][0];
		if (Kernel[1][0] != 0) {
			Divider++;
		}
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].g * Kernel[0][0];
		Divider++;

	}
	if (j - 1 >= 0 && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].g * Kernel[2][0];
		if (Kernel[2][0] != 0) {
			Divider++;
		}
	}
	if (j + 1 < width && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].g * Kernel[2][2];
		Divider++;

	}
	if (j + 1 < width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].g * Kernel[0][2];
		Divider++;

	}
	return Mean / Divider;

}
double Image::Get_Neighbour_Mean_R(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].r * Kernel[1][1];

	if (i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j].r * Kernel[2][1];
		if (Kernel[2][1] != 0) {
			Divider++;
		}
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].r * Kernel[0][1];
		if (Kernel[0][1] != 0) {
			Divider++;
		}
	}
	if (j + 1 < width) {
		Mean += Pixel_Matrix[i][j + 1].r * Kernel[1][2];
		if (Kernel[1][2] != 0) {
			Divider++;
		}
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].r * Kernel[1][0];
		if (Kernel[1][0] != 0) {
			Divider++;
		}
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].r * Kernel[0][0];
		if (Kernel[0][0]) {
			Divider++;
		}
	}
	if (j - 1 >= 0 && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].r * Kernel[2][0];
		Divider++;

	}
	if (j + 1 < width && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].r * Kernel[2][2];
		Divider++;

	}
	if (j + 1 < width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].r * Kernel[0][2];
		Divider++;

	}
	return Mean / Divider;

}
double Image::Get_Neighbour_Mean_B(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
	double Mean = 0;
	int Divider = 1;
	Mean += Pixel_Matrix[i][j].b * Kernel[1][1];

	if (i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j].b * Kernel[2][1];
		if (Kernel[2][1] != 0) {
			Divider++;
		}
	}
	if (i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j].b * Kernel[0][1];
		if (Kernel[0][1] != 0) {
			Divider++;
		}
	}
	if (j + 1 < width) {
		Mean += Pixel_Matrix[i][j + 1].b * Kernel[1][2];
		if (Kernel[1][2] != 0) {
			Divider++;
		}
	}
	if (j - 1 <= 0) {
		Mean += Pixel_Matrix[i][j - 1].b * Kernel[1][0];
		if (Kernel[1][0] != 0) {
			Divider++;
		}
	}
	if (j - 1 >= 0 && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j - 1].b * Kernel[0][0];
		if (Kernel[0][0]) {
			Divider++;
		}
	}
	if (j - 1 >= 0 && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j - 1].b * Kernel[2][0];
		Divider++;

	}
	if (j + 1 < width && i + 1 < Height) {
		Mean += Pixel_Matrix[i + 1][j + 1].b * Kernel[2][2];
		Divider++;

	}
	if (j + 1 < width && i - 1 >= 0) {
		Mean += Pixel_Matrix[i - 1][j + 1].b * Kernel[0][2];
		Divider++;

	}
	return Mean / Divider;

}



//double Image::Get_Neighbour_Mean_R(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
//	double Mean = 0;
//	
//
//	Mean += Pixel_Matrix[i][j].r * (Kernel[1][1] / Kernel_Normal);
//
//	if (i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j].r * (Kernel[2][1] / Kernel_Normal);
//
//	}
//
//
//	if (i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j].r * (Kernel[0][1] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width) {
//		Mean += Pixel_Matrix[i][j + 1].r *(Kernel[1][2] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 <= 0) {
//		Mean += Pixel_Matrix[i][j - 1].r * (Kernel[1][0] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 >= 0 && i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j - 1].r * (Kernel[0][0] / Kernel_Normal);
//
//
//	}
//
//
//	if (j - 1 >= 0 && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j - 1].r * (Kernel[2][0] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j + 1].r * (Kernel[2][2] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width && i - 1 >= 0) {
//		Mean += Pixel_Matrix[0][width - 1].r * (Kernel[0][2] / Kernel_Normal);
//
//	}
//
//
//	return Mean;
//
//}
//double Image::Get_Neighbour_Mean_G(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
//	double Mean = 0;
//
//
//	Mean += Pixel_Matrix[i][j].g * (Kernel[1][1] / Kernel_Normal);
//
//	if (i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j].g * (Kernel[2][1] / Kernel_Normal);
//
//	}
//
//
//	if (i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j].g * (Kernel[0][1] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width) {
//		Mean += Pixel_Matrix[i][j + 1].g *(Kernel[1][2] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 <= 0) {
//		Mean += Pixel_Matrix[i][j - 1].g * (Kernel[1][0] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 >= 0 && i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j - 1].g * (Kernel[0][0] / Kernel_Normal);
//
//
//	}
//
//
//	if (j - 1 >= 0 && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j - 1].g * (Kernel[2][0] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j + 1].g * (Kernel[2][2] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width && i - 1 >= 0) {
//		Mean += Pixel_Matrix[0][width - 1].g * (Kernel[0][2] / Kernel_Normal);
//
//	}
//
//
//	return Mean;
//
//}
//double Image::Get_Neighbour_Mean_B(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal) {
//	double Mean = 0;
//
//
//	Mean += Pixel_Matrix[i][j].b * (Kernel[1][1] / Kernel_Normal);
//
//	if (i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j].b * (Kernel[2][1] / Kernel_Normal);
//
//	}
//
//
//	if (i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j].b * (Kernel[0][1] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width) {
//		Mean += Pixel_Matrix[i][j + 1].b *(Kernel[1][2] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 <= 0) {
//		Mean += Pixel_Matrix[i][j - 1].b * (Kernel[1][0] / Kernel_Normal);
//
//	}
//
//
//	if (j - 1 >= 0 && i - 1 >= 0) {
//		Mean += Pixel_Matrix[i - 1][j - 1].b * (Kernel[0][0] / Kernel_Normal);
//
//
//	}
//	
//
//	if (j - 1 >= 0 && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j - 1].b * (Kernel[2][0] / Kernel_Normal);
//
//	}
//
//
//	if (j + 1 < width && i + 1 < Height) {
//		Mean += Pixel_Matrix[i + 1][j + 1].b * (Kernel[2][2] / Kernel_Normal);
//
//	}
//	
//
//	if (j + 1 < width && i - 1 >= 0) {
//		Mean += Pixel_Matrix[0][width - 1].b * (Kernel[0][2] / Kernel_Normal);
//
//	}
//	
//
//	return Mean;
//
//}


void Image::Mark_Identical_Pixels(pixel const &Target) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			if (Pixel_Matrix[i][j] == Target) {
				this->Draw_Square(j, i, 2, 2, 'r');
			}
		}
	}

}
void Image::Mark_Identical_Pixels(Image &Source) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}
	if (this->im_size <= Source.im_size) {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
					this->Draw_Square(j, i, 2, 2, 'r');
				}
			}
		}
	}
	else if (this->im_size > Source.im_size) {
		for (int i = 0; i < Source.Height; i++) {
			for (int j = 0; j < Source.width; j++) {
				if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
					this->Draw_Square(j, i, 2, 2, 'r');
				}
			}
		}
	}

}
void Image::Mark_Identical_Pixels(Image &Source, const char *mode) {
	char m1[7] = "Strict";
	char m2[6] = "Loose";

	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}
	if (strcmp(m1, mode) == 0) {//strict
		if (this->im_size <= Source.im_size) {
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this->Draw_Square(j, i, 2, 2, 'r');
					}
				}
			}
		}
		else if (this->im_size > Source.im_size) {
			for (int i = 0; i < Source.Height; i++) {
				for (int j = 0; j < Source.width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this->Draw_Square(j, i, 2, 2, 'r');
					}
				}
			}
		}
	}
	else if (strcmp(m2, mode) == 0) {//loose

		if (this->im_size <= Source.im_size) {
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
						this->Draw_Square(j, i, 2, 2, 'r');
					}
				}
			}
		}
		else if (this->im_size > Source.im_size) {
			for (int i = 0; i < Source.Height; i++) {
				for (int j = 0; j < Source.width; j++) {
					if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
						this->Draw_Square(j, i, 2, 2, 'r');
					}
				}
			}
		}
	}
}
void Image::Mark_Different_Pixels(Image &Source, int const &Color_Treshold, int const &Distnace_Treshold, pixel const &frame_color) {


	if (this->width != Source.width || this->Height != Source.Height) {
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}

	//for (int i = 0; i < Height; i++) { // marking all diffrent pixels
	//	for (int j = 0; j < width; j++) {
	//		if (Color_DistanceSq(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > Color_Treshold) {
	//			this->Pixel_Matrix[i][j].analysis = 42;

	//		}
	//	}
	//}

	std::list<Blob> Blobs;
	Blob temp(0, 0, Distnace_Treshold);
	bool detected = false;

	for (int i = 0; i < width; i++) { // marking all diffrent pixels
		for (int j = 0; j < Height; j++) {

			if (Color_Delta(this->Pixel_Matrix[j][i], Source.Pixel_Matrix[j][i]) > Color_Treshold) {
				for (std::list<Blob>::iterator k = Blobs.begin(); k != Blobs.end(); ++k) {
					if (k->Near(i, j)) {
						k->add(i, j);
						detected = true;
						break;
					}

				}

				if (!detected) {
					temp.SetProps(i, j);
					Blobs.push_back(temp);
				}
				detected = false;

			}
		}
	}

	for (std::list<Blob>::iterator k = Blobs.begin(); k != Blobs.end(); ++k) {
		Draw_Square(k->Upleft_X, k->Upleft_Y, k->Downright_X, k->Downright_Y, frame_color, "Corners");
	}




}

void Image::Write_Pixel_Difference(Image &Source) {
	if (this->width != Source.width || this->Height != Source.Height) {
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}
	unsigned char *diffrence = (unsigned char*)calloc(this->width*this->Height * 3, sizeof(unsigned char));
	int index = 0;
	for (int i = 0; i < this->Height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Pixel_Matrix[i][j] != Source.Pixel_Matrix[i][j]) {
				diffrence[Pixel_Matrix[i][j].index_range] = 255;
				diffrence[Pixel_Matrix[i][j].index_range + 1] = 0;
				diffrence[Pixel_Matrix[i][j].index_range + 2] = 0;
			}
		}
	}
	stbi_write_jpg("Pixel_Diffrence.jpg", this->width, this->Height, 3, diffrence, 100);
}
void Image::Write_Pixel_Difference(Image &Source, const char *mode, int min_diff) {
	char m1[5];
	strcpy(m1, "Copy");
	if (strcmp(m1, mode) == 0) {
		if (this->width != Source.width || this->Height != Source.Height) {
			return;
		}
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (Source.Pixel_Matrix == nullptr) {
			Source.init_pixel_matrix();
		}
		unsigned char *diffrence = (unsigned char*)calloc(this->width*this->Height * 3, sizeof(unsigned char));
		int index = 0;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				if (Color_Distance(Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
					diffrence[Pixel_Matrix[i][j].index_range] = Pixel_Matrix[i][j].r;
					diffrence[Pixel_Matrix[i][j].index_range + 1] = Pixel_Matrix[i][j].g;
					diffrence[Pixel_Matrix[i][j].index_range + 2] = Pixel_Matrix[i][j].b;
				}
			}
		}
		stbi_write_jpg("Pixel_Diffrence.jpg", this->width, this->Height, 3, diffrence, 100);
	}
	else {
		return;
	}
}

void Image::Mark_Different_Pixels(Image &Source) {
	if (this->width != Source.width || this->Height != Source.Height) {
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			if (Pixel_Matrix[i][j] != Source.Pixel_Matrix[i][j]) {
				this->Draw_Square(j, i, 2, 2, 'r');
			}
		}
	}


}
void Image::Mark_Different_Pixels(Image &Source, const char *mode) {
	char m1[7] = "Strict";


	if (this->width != Source.width || this->Height != Source.Height) {
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if (Source.Pixel_Matrix == nullptr) {
		Source.init_pixel_matrix();
	}

	if (strcmp(m1, mode) == 0) {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				if (Pixel_Matrix[i][j] != Source.Pixel_Matrix[i][j]) {
					this->Draw_Square(j, i, 2, 2, 'r');
				}
			}
		}
	}

}


void Image::Write_ChannelGraph() {

	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	int posR, PosG, PosB, H = 500, W = 1300;
	int bar_width = this->width / 300;
	if (bar_width == 0) {
		bar_width = 1;
	}
	int sR = 0, sG = 0, sB = 0;
	Image frame;
	Color_Palette CSET;
	frame.Load_Blank_Canvas(W, H, CSET.Azure);
	frame.Draw_Square(250, 250, 150, 150, 'B');
	frame.Draw_Square(650, 250, 150, 150, 'B');
	frame.Draw_Square(1050, 250, 150, 150, 'B');
	frame.Draw_Square(250, 250, 151, 151, 'B');
	frame.Draw_Square(650, 250, 151, 151, 'B');
	frame.Draw_Square(1050, 250, 151, 151, 'B');

	for (int i = 103; i <= 400; i += 5) {
		frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
	}
	for (int i = 103; i <= 400; i += 5) {
		frame.Draw_Line(i, 100, i, 400, CSET.Light_Gray);
	}

	for (int i = 503; i <= 800; i += 5) {
		frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
	}
	for (int i = 103; i <= 400; i += 5) {
		frame.Draw_Line(i, 500, i, 800, CSET.Light_Gray);
	}

	for (int i = 903; i <= 1200; i += 5) {
		frame.Draw_Line(100, i, 400, i, CSET.Light_Gray);
	}
	for (int i = 103; i <= 400; i += 5) {
		frame.Draw_Line(i, 900, i, 1200, CSET.Light_Gray);
	}

	frame.Draw_Text(90, 240, "RED GRAPH");
	frame.Draw_Text(90, 640, "GREEN GRAPH");
	frame.Draw_Text(90, 1040, "BLUE GRAPH");


	posR = 101;
	PosG = 501;
	PosB = 901;



	for (int i = 0; i < this->width; i++) {
		for (int k = 0; k < bar_width; k++) {
			for (int j = 0; j < this->Height; j++) {
				if (Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].g &&Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].b &&
					decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'B'
					&&decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'W') {
					//sR += Pixel_Matrix[j][i].r;
					sR++;
				}
				else if (Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].b
					&& decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'B'
					&&decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'W') {
					//sG += Pixel_Matrix[j][i].g;
					sG++;
				}
				else if (Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].g
					&&decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'B'
					&& decode_color(Pixel_Matrix[j][i].r, Pixel_Matrix[j][i].g, Pixel_Matrix[j][i].b) != 'W') {
					//sB += Pixel_Matrix[j][i].b;
					sB++;
				}

			}
			if (bar_width > 1) {
				i++;
			}
		}

		sR /= bar_width;
		sG /= bar_width;
		sB /= bar_width;

		sR %= 300;
		sG %= 300;
		sB %= 300;

		if (posR < 399) {
			frame.Draw_Line(posR, 399, 399 - sR, 'r');
		}
		if (PosG < 799) {
			frame.Draw_Line(PosG, 399, 399 - sG, 'g');
		}
		if (PosB < 1199) {
			frame.Draw_Line(PosB, 399, 399 - sB, 'b');
		}

		posR += bar_width;
		PosG += bar_width;
		PosB += bar_width;

		sR = sG = sB = 0;

	}




	frame.Write_Image("ChannelGraph");
}

void Image::Write_Channel(const char color) {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	int index = 0;
	switch (color)
	{
	case 'R':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = 0;
				image_data[index++] = 0;
			}
		}
		break;
	case 'G':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = 0;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = 0;
			}
		}
		break;
	case 'B':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = 0;
				image_data[index++] = 0;
				image_data[index++] = Pixel_Matrix[i][j].b;
			}
		}
		break;
	default:
		break;
	}


}
void Image::Shutdown_Channel(const char color) {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	int index = 0;
	switch (color)
	{
	case 'R':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = 0;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = Pixel_Matrix[i][j].b;
				Pixel_Matrix[i][j].r = 0;
			}
		}
		break;
	case 'G':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = 0;
				image_data[index++] = Pixel_Matrix[i][j].b;
				Pixel_Matrix[i][j].g = 0;

			}
		}
		break;
	case 'B':
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = 0;
				Pixel_Matrix[i][j].b = 0;
			}
		}
		break;
	default:
		break;
	}
}
void Image::Flip180() {
	unsigned char *flip = new unsigned char[(width*Height * 3)];

	int index = 0;
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = Height - 1; i >= 0; i--) {
		for (int j = width - 1; j >= 0; j--) {
			flip[index++] = Pixel_Matrix[i][j].r;
			flip[index++] = Pixel_Matrix[i][j].g;
			flip[index++] = Pixel_Matrix[i][j].b;

		}
	}

	delete[] this->image_data;
	this->image_data = flip;
}
void Image::Tresholding(const char *mode, int const &value, int const &alter) {
	int index = 0;
	char m1[6];
	char m2[15];
	strcpy(m1, "Trunc");
	strcpy(m2, "EdgeTriggerd");
	if (strcmp(m1, mode) == 0) {
		if (Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		this->Color_Flooring("10", 0);
		for (int i = 0; i < Height; i++) {
			for (int j = 1; j < width; j++) {
				if (Pixel_Matrix[i][j].r > value || Pixel_Matrix[i][j].g > value || Pixel_Matrix[i][j].b > value)
				{
					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
		if (alter == 1) {
			index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}
		}
	}

	else if (strcmp(m2, mode) == 0) {
		int index = 0, recored = 0, max_gap = 1;
		pixel prev;
		if (Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}

		for (int i = 0; i < Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > value)
				{
					Pixel_Matrix[i][j].r = 255;
					Pixel_Matrix[i][j].g = 255;
					Pixel_Matrix[i][j].b = 255;



				}
				else {
					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;



				}

			}
		}
		if (alter == 1) {
			index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}
		}
	}

}
void Image::Edge_Detection() {

	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	int index = 0, recored = 0, max_gap = 1;
	pixel prev;

	for (int i = 0; i < Height; i++) {
		prev.r = Pixel_Matrix[i][0].r;
		prev.g = Pixel_Matrix[i][0].g;
		prev.b = Pixel_Matrix[i][0].b;

		Pixel_Matrix[i][0].r = 0;
		Pixel_Matrix[i][0].g = 0;
		Pixel_Matrix[i][0].b = 0;

		for (int j = 1; j < width; j++) {
			if (Color_Distance(prev, Pixel_Matrix[i][j]) > 50)
			{
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;

				Pixel_Matrix[i][j].r = 255;
				Pixel_Matrix[i][j].g = 255;
				Pixel_Matrix[i][j].b = 255;



			}
			else {
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;

				Pixel_Matrix[i][j].r = 0;
				Pixel_Matrix[i][j].g = 0;
				Pixel_Matrix[i][j].b = 0;



			}

		}
	}
	index = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}
}
void Image::Edge_Detection(const int max_color_gap) {

	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	int index = 0, recored = 0, max_gap = 1;
	pixel prev;

	for (int i = 0; i < Height; i++) {
		prev.r = Pixel_Matrix[i][0].r;
		prev.g = Pixel_Matrix[i][0].g;
		prev.b = Pixel_Matrix[i][0].b;

		Pixel_Matrix[i][0].r = 0;
		Pixel_Matrix[i][0].g = 0;
		Pixel_Matrix[i][0].b = 0;

		for (int j = 1; j < width; j++) {
			if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
			{
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;

				Pixel_Matrix[i][j].r = 255;
				Pixel_Matrix[i][j].g = 255;
				Pixel_Matrix[i][j].b = 255;



			}
			else {
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;

				Pixel_Matrix[i][j].r = 0;
				Pixel_Matrix[i][j].g = 0;
				Pixel_Matrix[i][j].b = 0;



			}

		}
	}
	index = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}
}
void Image::Mark_Contour(const char color, const int max_color_gap) {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	int index = 0, recored = 0, max_gap = 1;
	pixel prev;

	for (int i = 0; i < Height; i++) {
		prev.r = Pixel_Matrix[i][0].r;
		prev.g = Pixel_Matrix[i][0].g;
		prev.b = Pixel_Matrix[i][0].b;

		for (int j = 1; j < width; j++) {
			if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
			{
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;

				Color_Spec(Pixel_Matrix[i][j].index_range, color);



			}
			else {
				prev.r = Pixel_Matrix[i][j].r;
				prev.g = Pixel_Matrix[i][j].g;
				prev.b = Pixel_Matrix[i][j].b;



			}

		}
	}

	for (int i = 0; i < width; i++) {
		prev.r = Pixel_Matrix[0][i].r;
		prev.g = Pixel_Matrix[0][i].g;
		prev.b = Pixel_Matrix[0][i].b;

		for (int j = 1; j < Height; j++) {
			if (Color_Distance(prev, Pixel_Matrix[j][i]) > max_color_gap)
			{
				prev.r = Pixel_Matrix[j][i].r;
				prev.g = Pixel_Matrix[j][i].g;
				prev.b = Pixel_Matrix[j][i].b;

				Color_Spec(Pixel_Matrix[j][i].index_range, color);



			}
			else {
				prev.r = Pixel_Matrix[j][i].r;
				prev.g = Pixel_Matrix[j][i].g;
				prev.b = Pixel_Matrix[j][i].b;



			}

		}
	}

}
void Image::Feature_Matching(const int source_x, const int source_y) {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	if ((source_x + 1 > width) || (source_x - 1 < 0) || (source_y + 1 > Height) || (source_y - 1 < 0)) {
		//out of image border;
		return;
	}
	pixel up, down, left, right, center;
	int band = 5;
	center.r = Pixel_Matrix[source_y][source_x].r;
	center.g = Pixel_Matrix[source_y][source_x].g;
	center.b = Pixel_Matrix[source_y][source_x].b;

	up.r = Pixel_Matrix[source_y - 1][source_x].r;
	up.g = Pixel_Matrix[source_y - 1][source_x].g;
	up.b = Pixel_Matrix[source_y - 1][source_x].b;

	down.r = Pixel_Matrix[source_y + 1][source_x].r;
	down.g = Pixel_Matrix[source_y + 1][source_x].g;
	down.b = Pixel_Matrix[source_y + 1][source_x].b;

	left.r = Pixel_Matrix[source_y][source_x - 1].r;
	left.g = Pixel_Matrix[source_y][source_x - 1].g;
	left.b = Pixel_Matrix[source_y][source_x - 1].b;

	right.r = Pixel_Matrix[source_y][source_x + 1].r;
	right.g = Pixel_Matrix[source_y][source_x + 1].g;
	right.b = Pixel_Matrix[source_y][source_x + 1].b;

	Draw_Circle(source_x, source_y, 3, 'r');
	Draw_Circle(source_x, source_y, 2, 'b');


	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {

			if (i + 1 < Height && i - 1 > 0 && j + 1 < width && j - 1 > 0) {
				if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], down) < band &&Color_Distance(Pixel_Matrix[i - 1][j], up) < band
					&&Color_Distance(Pixel_Matrix[i][j + 1], right) < band &&Color_Distance(Pixel_Matrix[i][j - 1], left) < band) {
					Draw_Circle(j, i, 3, 'r');
					Draw_Line(source_x, source_y, j, i, 'b');
				}
				else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
					&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
					Draw_Circle(j, i, 3, 'r');
					Draw_Line(source_x, source_y, j, i, 'b');

				}
				else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
					&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
					Draw_Circle(j, i, 3, 'r');
					Draw_Line(source_x, source_y, j, i, 'b');

				}
				else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
					&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
					Draw_Circle(j, i, 3, 'r');
					Draw_Line(source_x, source_y, j, i, 'b');

				}
			}
		}
	}



}
void Image::Pixel_Matrix_Multiplication(Image &b) {

	if (this->width != b.Height) {
		std::cout << "Cannot Multiply Pixel Please Make Sure Image A's Width = Image B's Height\n";
		return;
	}
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	if (b.Pixel_Matrix == nullptr) {
		b.init_pixel_matrix();
	}

	pixel sum;

	if (this->Height != b.width) {
		pixel **n_mat = new pixel*[this->Height];
		for (int i = 0; i < b.width; i++) {
			n_mat[i] = new pixel[b.width];
		}


		for (int i = 0; i < this->width; i++) {
			pixel temp;
			for (int j = 0; j < b.width; j++) {
				for (int k = 0; k < this->width; k++) {
					temp = Pixel_Matrix[i][k] * b.Pixel_Matrix[k][j];
					sum + temp;
				}
				n_mat[i][j] = sum;
				sum.r = 0;
				sum.g = 0;
				sum.b = 0;
			}
		}

		delete[] this->Pixel_Matrix;
		delete[] this->image_data;
		unsigned char *updated = new unsigned char[this->Height *b.width * 3];

		int index = 0;
		this->Pixel_Matrix = n_mat;
		this->width = b.width;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				updated[index++] = Pixel_Matrix[i][j].r;
				updated[index++] = Pixel_Matrix[i][j].g;
				updated[index++] = Pixel_Matrix[i][j].b;

			}
		}


	}
	else {/////////////

		for (int i = 0; i < this->width; i++) {
			pixel temp;
			for (int j = 0; j < b.width; j++) {
				for (int k = 0; k < this->width; k++) {
					temp = Pixel_Matrix[i][k] * b.Pixel_Matrix[k][j];
					sum + temp;
				}
				this->Pixel_Matrix[i][j] = sum;
				sum.r = 0;
				sum.g = 0;
				sum.b = 0;
			}
		}

		int index = 0;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = Pixel_Matrix[i][j].b;

			}
		}
	}

}
void Image::Quarantine_Pixel(pixel const &sample, const float max_difference, const char *mode, const int Alter) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	char m1[10], m2[10];
	strcpy(m1, "Drop_Self");
	strcpy(m2, "Keep_Self");
	if (strcmp(m2, mode) == 0) {
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				if (Color_DistanceSq(Pixel_Matrix[i][j], sample) > max_difference) {
					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;

				}
			}
		}

		if (Alter == 1) {
			int index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}
		}
	}
	else if (strcmp(m1, mode) == 0) {
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				if (Color_DistanceSq(Pixel_Matrix[i][j], sample) < max_difference) {
					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;

				}
			}
		}
		if (Alter == 1) {
			int index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}
		}
	}
}
void Image::Kronecker_product(Image &b, const char *mode, const int Alter) {
	char m1[4], m2[5], m3[15], m4[8];
	strcpy(m1, "Mul");
	strcpy(m2, "Size");
	strcpy(m3, "Build_From");
	strcpy(m4, "Mix");
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	if (b.Pixel_Matrix == nullptr) {
		b.init_pixel_matrix();
	}

	if (strcmp(m1, mode) == 0) {
		pixel **Kronecker_pixel_mat = (pixel**)malloc(sizeof(pixel*)*b.Height*this->Height);
		for (int i = 0; i < b.Height*this->Height; i++) {
			Kronecker_pixel_mat[i] = (pixel*)malloc(sizeof(pixel)*this->width*b.width);
		}

		unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Height*b.Height*b.width*this->width * 3));
		unsigned long long startRow, startCol, index = 0;
		pixel temp;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				startRow = i * b.Height;
				startCol = j * b.width;
				for (int k = 0; k < b.Height; k++) {
					for (int l = 0; l < b.width; l++) {
						temp = this->Pixel_Matrix[i][j] * b.Pixel_Matrix[k][l];
						Kronecker_pixel_mat[startRow + k][startCol + l] = temp;

					}
				}
			}
		}

		if (Alter == 1) {
			this->width *= b.width;
			this->Height *= b.Height;
			delete[] this->image_data;
			delete[] this->Pixel_Matrix;
			this->Pixel_Matrix = Kronecker_pixel_mat;
			for (long long i = 0; i < this->Height; i++) {
				for (long long j = 0; j < this->width; j++) {
					Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

				}
			}
			this->image_data = Kronecker;

		}


	}
	else if (strcmp(m2, mode) == 0) {
		pixel **Kronecker_pixel_mat = (pixel**)malloc(sizeof(pixel*)*b.Height*this->Height);
		for (int i = 0; i < b.Height*this->Height; i++) {
			Kronecker_pixel_mat[i] = (pixel*)malloc(sizeof(pixel)*this->width*b.width);
		}

		unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Height * b.Height * b.width * this->width * 3));
		pixel temp;
		unsigned long long startRow, startCol, index = 0;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				startRow = i * b.Height;
				startCol = j * b.width;
				for (int k = 0; k < b.Height; k++) {
					for (int l = 0; l < b.width; l++) {
						if (this->Pixel_Matrix[i][j] > b.Pixel_Matrix[k][l]) {
							temp = this->Pixel_Matrix[i][j];
						}
						else {
							temp = b.Pixel_Matrix[k][l];
						}

						Kronecker_pixel_mat[startRow + k][startCol + l] = temp;

					}
				}
			}
		}

		if (Alter == 1) {
			this->width *= b.width;
			this->Height *= b.Height;
			delete[] this->image_data;
			delete[] this->Pixel_Matrix;
			this->Pixel_Matrix = Kronecker_pixel_mat;
			for (long long i = 0; i < this->Height; i++) {
				for (long long j = 0; j < this->width; j++) {
					Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

				}
			}
			this->image_data = Kronecker;

		}
	}
	else if (strcmp(m3, mode) == 0) {

		pixel **Kronecker_pixel_mat = (pixel**)malloc(sizeof(pixel*)*b.Height*this->Height);
		for (int i = 0; i < b.Height*this->Height; i++) {
			Kronecker_pixel_mat[i] = (pixel*)malloc(sizeof(pixel)*this->width*b.width);
		}
		unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Height * b.Height * b.width * this->width * 3));
		pixel temp;
		unsigned long long startRow, startCol, index = 0;
		int flag = 0;
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				startRow = i * b.Height;
				startCol = j * b.width;
				for (int k = 0; k < b.Height; k++) {
					for (int l = 0; l < b.width; l++) {
						if (flag == 0) {
							temp = this->Pixel_Matrix[i][j];
							flag = 1;
						}
						else {
							temp = b.Pixel_Matrix[k][l];
							flag = 0;
						}

						Kronecker_pixel_mat[startRow + k][startCol + l] = temp;

					}
				}
			}
		}

		if (Alter == 1) {
			this->width *= b.width;
			this->Height *= b.Height;
			delete[] this->image_data;
			delete[] this->Pixel_Matrix;
			this->Pixel_Matrix = Kronecker_pixel_mat;
			for (long long i = 0; i < this->Height; i++) {
				for (long long j = 0; j < this->width; j++) {
					Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

				}
			}
			this->image_data = Kronecker;

		}
	}
	else if (strcmp(m4, mode) == 0) {

		unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Height * b.Height * b.width * this->width * 3));
		pixel temp;
		unsigned long long startRow, startCol, index = 0;
		int flag = 0;

		pixel **Kronecker_pixel_mat = (pixel**)malloc(sizeof(pixel*)*b.Height*this->Height);
		for (int i = 0; i < b.Height*this->Height; i++) {
			Kronecker_pixel_mat[i] = (pixel*)malloc(sizeof(pixel)*this->width*b.width);
		}

		for (int i = 0; i < this->Height; i++) {

			for (int j = 0; j < this->width; j++)
			{
				startRow = i * b.Height;
				startCol = j * b.width;
				for (int k = 0; k < b.Height; k++)
				{
					if (flag == 1) {
						temp = this->Pixel_Matrix[i][j];
					}
					else if (flag == 0) {
						temp = b.Pixel_Matrix[i][j];
					}

					for (int l = 0; l < b.width; l++)
					{

						Kronecker_pixel_mat[startRow + k][startCol + l] = temp;
					}
					if (flag == 1) {
						flag = 0;
					}
					else {
						flag = 1;
					}
				}


			}

		}

		if (Alter == 1) {
			this->width *= b.width;
			this->Height *= b.Height;
			delete[] this->image_data;
			delete[] this->Pixel_Matrix;
			this->Pixel_Matrix = Kronecker_pixel_mat;
			for (long long i = 0; i < this->Height; i++) {
				for (long long j = 0; j < this->width; j++) {
					Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
					Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

				}
			}
			this->image_data = Kronecker;

		}
	}


}
void Image::Image_Transpose(const int Alter) {
	int H = this->width, W = this->Height;
	//unsigned char *T = (unsigned char*)malloc(sizeof(unsigned char)*this->width*this->Height * 3);
	pixel **T_mat = (pixel**)malloc(sizeof(pixel*)*H);
	for (int i = 0; i < H; i++) {
		T_mat[i] = (pixel*)malloc(sizeof(pixel)*W);
	}

	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}

	for (int i = 0; i < this->Height; i++) {
		for (int j = 0; j < this->width; j++) {
			T_mat[j][i] = this->Pixel_Matrix[i][j];
		}
	}

	delete[] this->Pixel_Matrix;
	this->Pixel_Matrix = T_mat;

	if (Alter == 1) {
		int index = 0;
		this->Height = H;
		this->width = W;
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->image_data[index++] = Pixel_Matrix[i][j].r;
				this->image_data[index++] = Pixel_Matrix[i][j].g;
				this->image_data[index++] = Pixel_Matrix[i][j].b;

			}
		}
	}
}
VectorFrame Image::K_Means(const VectorFrame& data, size_t k, size_t number_of_iterations) {
	static std::random_device seed; //seed for psudo random engine 
	static std::mt19937 random_number_generator(seed()); //merssene twisster using the PR seed
	std::uniform_int_distribution<size_t> indices(0, data.size() - 1);

	VectorFrame means(k);

	for (auto& cluster : means) {
		cluster = data[indices(random_number_generator)];
	}

	std::vector<size_t> assignments(data.size());

	for (size_t iteration = 0; iteration < number_of_iterations; ++iteration) {
		// Find assignments.
		for (size_t point = 0; point < data.size(); ++point) {
			double best_distance = std::numeric_limits<double>::max();
			size_t best_cluster = 0;
			for (size_t cluster = 0; cluster < k; ++cluster) {
				const double distance =
					squared_3Point_distance(data[point], means[cluster]);
				if (distance < best_distance) {
					best_distance = distance;
					best_cluster = cluster;
				}
			}
			assignments[point] = best_cluster;
		}

		// Sum up and count points for each cluster.
		VectorFrame new_means(k);
		std::vector<size_t> counts(k, 0);

		for (size_t point = 0; point < data.size(); ++point) {
			const auto cluster = assignments[point];
			new_means[cluster].x += data[point].x;
			new_means[cluster].y += data[point].y;
			new_means[cluster].z += data[point].z;
			counts[cluster] += 1;
		}

		// Divide sums by counts to get new centroids.
		for (size_t cluster = 0; cluster < k; ++cluster) {
			// Turn 0/0 into 0/1 to avoid zero division.
			const auto count = std::max<size_t>(1, counts[cluster]);
			means[cluster].x = new_means[cluster].x / count;
			means[cluster].y = new_means[cluster].y / count;
			means[cluster].z = new_means[cluster].z / count;

		}
	}

	return means;

}


void Image::Blob_Framing(int const &distance_treshold, pixel const &frame_color) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	Color_Palette CSET;
	std::vector<Blob> Blobs;

	Blob temp(0, 0, distance_treshold);
	bool detected = false;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < this->width; j++) {

			if (this->Pixel_Matrix[i][j].analysis == 42) {
				//Color_Spec(Pixel_Matrix[i][j].index_range, CSET.Yellow);
			/*	for (vector<Blob>::iterator k = Blobs.begin(); k != Blobs.end(); ++k) {
					if (k->Near(i, j)) {
						k->add(i, j);
						detected = true;

						break;

					}

				}*/
				for (int k = 0; k < (signed)Blobs.size(); ++k) {
					if (Blobs[k].Near(i, j)) {
						Blobs[k].add(i, j);
						detected = true;

						break;

					}

				}

				if (!detected) {
					temp.SetProps(i, j);
					Blobs.push_back(temp);
				}
				detected = false;

			}
		}
	}

	//for (list<Blob>::iterator k = Blobs.begin(); k != Blobs.end(); ++k) {
	//	if (((k->Upleft_X - k->Downright_X)*(k->Upleft_Y - k->Downright_Y)) > distance_treshold / 4) {
	//		
	//		Draw_Square(k->Downright_X, k->Downright_Y, k->Upleft_X, k->Upleft_Y, frame_color, "Corners");
	//		Color_Spec(Pixel_Matrix[k->Upleft_X][k->Upleft_Y].index_range, 'W');
	//		Color_Spec(Pixel_Matrix[k->Downright_X][k->Downright_Y].index_range, 'g');


	//	}
	//}


	for (int k = 0; k < (signed)Blobs.size(); k++) {
		if (Blobs[k].Size() < distance_treshold) {

			//std::cout << "Blob Size " << Blobs[k].Size() << endl;
			Blobs.erase(Blobs.begin() + k);
		}

	}

	for (int k = 0; k < (signed)Blobs.size(); ++k) {

		Draw_Square(Blobs[k].Downright_X, Blobs[k].Downright_Y, Blobs[k].Upleft_X, Blobs[k].Upleft_Y, frame_color, "Corners");
		Color_Spec(Pixel_Matrix[Blobs[k].Upleft_X][Blobs[k].Upleft_Y].index_range, CSET.Yellow);
		Color_Spec(Pixel_Matrix[Blobs[k].Downright_X][Blobs[k].Downright_Y].index_range, 'g');



	}
}
void Image::Figure_Detection(int const &blob_distance_treshold, int const &color_distance_treshold, int const &Thresholding_level) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	this->Tresholding("Trunc", Thresholding_level, 0);

	int **adj_matrix = (int**)malloc(sizeof(int**)*this->Height);
	int color_treshold = color_distance_treshold;
	Color_Palette C;
	for (int i = 0; i < this->Height; i++) {
		adj_matrix[i] = (int*)calloc(this->width, sizeof(int));
	}

	for (int i = 0; i < this->Height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (Color_Delta(Pixel_Matrix[i][j], Pixel_Matrix[i][j + 1]) > color_treshold) {
				adj_matrix[i][j] = 1;


			}
		}
	}


	for (int i = 0; i < this->Height; i++) {
		for (int j = 0; j < this->width; j++) {
			if (adj_matrix[i][j] == 1) {
				Pixel_Matrix[i][j].analysis = 42;
			}
		}
	}

	this->Blob_Framing(blob_distance_treshold, C.Red);

}
void Image::Color_Flooring(const char *mod, int const &alter) {
	char m1[3];
	char m2[4];
	int index = 0;
	strcpy(m1, "10");
	strcpy(m2, "100");

	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}

	if (strcmp(m1, mod) == 0) {
		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				this->Pixel_Matrix[i][j].r = (this->Pixel_Matrix[i][j].r / 10) * 10;
				this->Pixel_Matrix[i][j].g = (this->Pixel_Matrix[i][j].g / 10) * 10;
				this->Pixel_Matrix[i][j].b = (this->Pixel_Matrix[i][j].b / 10) * 10;

			}
		}

		if (alter == 1) {
			index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}

		}


	}
	else if (strcmp(m2, mod) == 0) {

		for (int i = 0; i < this->Height; i++) {
			for (int j = 0; j < this->width; j++) {
				this->Pixel_Matrix[i][j].r = (this->Pixel_Matrix[i][j].r / 100) * 100;
				this->Pixel_Matrix[i][j].g = (this->Pixel_Matrix[i][j].g / 100) * 100;
				this->Pixel_Matrix[i][j].b = (this->Pixel_Matrix[i][j].b / 100) * 100;

			}
		}

		if (alter == 1) {
			index = 0;
			for (int i = 0; i < Height; i++) {
				for (int j = 0; j < width; j++) {
					image_data[index++] = Pixel_Matrix[i][j].r;
					image_data[index++] = Pixel_Matrix[i][j].g;
					image_data[index++] = Pixel_Matrix[i][j].b;

				}
			}

		}
	}
}
void Image::Image_Segmentation(int const &k, int const &iterations, int const &alter) {
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	else {
		free(Pixel_Matrix);
		this->init_pixel_matrix();
	}

	VectorFrame image_ThreeD_Mat, Result;
	int index = 0;
	//for (int i = 0; i < Height; i++) {
	//	for (int j = 0; j < width; j++) {
	//		r = Pixel_Matrix[i][j].r;
	//		g = Pixel_Matrix[i][j].g;
	//		b = Pixel_Matrix[i][j].b;
	//		image_ThreeD_Mat.push_back({ r,g,b,/*i,j*/ });
	//	}
	//}

	for (int i = 0; i < Height*width * 3; i += 3) {
		image_ThreeD_Mat.push_back({ (float)image_data[i], (float)image_data[i + 1], (float)image_data[i + 2] });

	}

	Result = this->K_Means(image_ThreeD_Mat, k, iterations);

	//for (auto i : Result) {
	//	cout << i.x << " " << i.y << " " << i.z << endl;
	//}


	float best_dist;
	Point temp;

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			best_dist = std::numeric_limits<float>::max();
			for (auto k : Result) {
				if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], k) < best_dist) {
					best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], k);
					temp = k;
				}
			}
			Pixel_Matrix[i][j].r = (uint8_t)temp.x;
			Pixel_Matrix[i][j].g = (uint8_t)temp.y;
			Pixel_Matrix[i][j].b = (uint8_t)temp.z;

		}
	}

	//for (auto i : Result) {
	//	Pixel_Matrix[i.i][i.j].r = i.x;
	//	Pixel_Matrix[i.i][i.j].g = i.y;
	//	Pixel_Matrix[i.i][i.j].b = i.z;
	//}

	if (alter == 1) {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = Pixel_Matrix[i][j].b;

			}
		}
	}




}
void Image::Write_Average_Color_Palette(int const &palette_size) {
	int H, W, lx;
	pixel palette_sample;
	VectorFrame imData, Means;
	Image palette_image;
	std::stringstream ss;
	std::string via;
	for (int i = 0; i < Height*width * 3; i += 3) {
		imData.push_back({ (float)image_data[i], (float)image_data[i + 1], (float)image_data[i + 2] });

	}
	Means = K_Means(imData, palette_size, 200);
	H = 200, W = 200 * palette_size;
	palette_image.Load_Blank_Canvas(W, H, 'B');
	lx = 2;

	for (auto k : Means) {
		palette_sample.r = (uint8_t)k.x;
		palette_sample.g = (uint8_t)k.y;
		palette_sample.b = (uint8_t)k.z;

		for (int j = 0; j < 199; j++) {
			palette_image.Draw_Line(j, lx, j, lx + 199, palette_sample);
		}
		lx += 199;
	}

	ss << "Average_" << palette_size << "_Color_Palette";
	via = ss.str();
	palette_image.Write_Image(via.c_str());

}
void Image::Pixel_Griding() {
	double sigma = 1.0;
	double r, s = 2.0 * sigma * sigma;
	double GKernel[5][5];
	double sum = 0.0;
	int index = 0;
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}

	for (int x = -2; x <= 2; x++) {
		for (int y = -2; y <= 2; y++) {
			r = sqrt(x * x + y * y);
			GKernel[x + 2][y + 2] = (exp(-(r * r) / s)) / (PI * s);
			sum += GKernel[x + 2][y + 2];
		}
	}

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			GKernel[i][j] /= sum;


	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {

			Pixel_Matrix[i][j].r += (uint8_t)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].r;
			Pixel_Matrix[i][j].g += (uint8_t)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].g;
			Pixel_Matrix[i][j].b += (uint8_t)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].b;

		}
	}

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}


	//for (int i = 0; i < 5; i++) {
	//	for (int j = 0; j < 5; j++) {
	//		cout << GKernel[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}
VectorFrame Image::Get_Average_Color_Palette(int const &palette_size) {
	VectorFrame imData, Means;
	for (int i = 0; i < Height*width * 3; i += 3) {
		imData.push_back({ (float)image_data[i], (float)image_data[i + 1], (float)image_data[i + 2] });

	}

	return this->K_Means(imData, palette_size, 200);

}
void Image::Set_Colors_Using_Average_Palette(VectorFrame const &Average_Colors) {
	int index = 0;
	float best_dist;
	Point temp;
	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			best_dist = std::numeric_limits<float>::max();
			for (auto k : Average_Colors) {
				if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], k) < best_dist) {
					best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], k);
					temp = k;
				}
			}
			Pixel_Matrix[i][j].r = (uint8_t)temp.x;
			Pixel_Matrix[i][j].g = (uint8_t)temp.y;
			Pixel_Matrix[i][j].b = (uint8_t)temp.z;

		}
	}



	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}



}
PixelFrame Image::Get_Line_Pixels(const int start_y, const int start_x, const int target_y, const int target_x) {
	float dx, sx, dy, sy, err, e2;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	PixelFrame Points;
	float x0 = (float)start_y, x1 = (float)target_y, y0 = (float)start_x, y1 = (float)target_x;
	dx = (float)(abs(target_y - start_y));
	sx = (float)(start_y < target_y ? 1 : -1);
	dy = (float)(-abs(target_x - start_x));
	sy = (float)(start_x < target_x ? 1 : -1);
	err = dx + dy;  //error value
	while (true) {
		if (x0 == x1 && y0 == y1) {
			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.push_back({ (uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].r,
								(uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].g,
								(uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].b,
								(int)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range,
								0
				});
			break;
		}

		//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
		Points.push_back({ (uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].r,
										(uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].g,
										(uint8_t)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].b,
										(int)this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)].index_range,
										0
			});
		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}

	}



	return Points;
}
void Image::Register_PixelFrame(PixelFrame const &Frame) {
	pixel color;
	for (auto k : Frame) {
		color.r = k.r;
		color.g = k.g;
		color.b = k.b;
		this->Color_Spec(k.index_range, color);
	}
}
void Image::Image_Rebuild_With_Lines(int const &Iterations) {
	static std::random_device seed;
	static std::mt19937 random_number(seed());
	std::uniform_int_distribution<size_t> x0_picks(0, this->width - 1);
	std::uniform_int_distribution<size_t> x1_picks(0, this->width - 1);
	std::uniform_int_distribution<size_t> y0_picks(0, this->Height - 1);
	std::uniform_int_distribution<size_t> y1_picks(0, this->Height - 1);
	Color_Palette CSET;
	pixel dominant_color;
	PixelFrame Line;
	Image B, C;
	B.Load_Blank_Canvas(this->width, this->Height, CSET.Black);
	C.Load_Blank_Canvas(this->width, this->Height, CSET.Black);

#ifdef Line_StepByStep



	std::stringstream ss;
	std::string via;
	int counter = 0;

#endif

	int x0, y0, x1, y1;
	double cur_difference, temp_dif;

	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	if (B.Pixel_Matrix == nullptr) {
		B.init_pixel_matrix();
	}
	if (C.Pixel_Matrix == nullptr) {
		C.init_pixel_matrix();
	}

	cur_difference = this->Image_Difference_Value(B);

	for (int i = 0; i < Iterations; i++) {
		x0 = x0_picks(random_number);
		y0 = y0_picks(random_number);
		x1 = x1_picks(random_number);
		y1 = y1_picks(random_number);

		dominant_color = this->Dominant_Color_Via_Line(y0, x0, y1, x1);
		Line = B.Get_Line_Pixels(y0, x0, y1, x1);
		B.Draw_Line(y0, x0, y1, x1, dominant_color);
		B.Update_Pixel_Matrix();


		temp_dif = this->Image_Difference_Value(B);

		if (temp_dif < cur_difference) {
			C.Draw_Line(y0, x0, y1, x1, dominant_color);
#ifdef Line_StepByStep
			ss << counter;
			via = ss.str();
			if ((counter + 1) % 40 == 0) {
				C.Write_Image(via.c_str());

			}
			ss.str(std::string());
			counter++;


#endif // Line_StepByStep

			cur_difference = temp_dif;
			B.Update_Pixel_Matrix();

		}
		else {
			B.Register_PixelFrame(Line);
			Line.clear();
			B.Update_Pixel_Matrix();
		}


	}

	C.Write_Image("Build_From_Random_Lines");



}
void Image::Image_Convolution(int const &iterations, int const &alter, const char *Type) {
	char m1[5], m2[10];
	strcpy(m1, "Mean");
	strcpy(m2, "Gaussian");
	double Conv_Kernel[3][3];
	double Kernel_Normal = 0;
	if (strcmp(m1, Type) == 0) {
		Conv_Kernel[0][0] = 1;
		Conv_Kernel[0][1] = 1;
		Conv_Kernel[0][2] = 1;
		Conv_Kernel[1][0] = 1;
		Conv_Kernel[1][1] = 1;
		Conv_Kernel[1][2] = 1;
		Conv_Kernel[2][0] = 1;
		Conv_Kernel[2][1] = 1;
		Conv_Kernel[2][2] = 1;
	}
	else if (strcmp(m2, Type) == 0) {
		Conv_Kernel[0][0] = 0;
		Conv_Kernel[0][1] = 1;
		Conv_Kernel[0][2] = 0;
		Conv_Kernel[1][0] = 1;
		Conv_Kernel[1][1] = 4;
		Conv_Kernel[1][2] = 1;
		Conv_Kernel[2][0] = 0;
		Conv_Kernel[2][1] = 1;
		Conv_Kernel[2][2] = 0;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Kernel_Normal += Conv_Kernel[i][j];
		}
	}
	Image Mid;
	int index = 0;
	Mid.Load_Image(this->f_name);

	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	if (Mid.getHeight() != this->Height) {
		Mid.width = this->width;
		Mid.Height = this->Height;
	}
	Mid.init_pixel_matrix();

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {

			Mid.Pixel_Matrix[i][j].r = (uint8_t)(this->Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
			Mid.Pixel_Matrix[i][j].g = (uint8_t)(this->Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal));
			Mid.Pixel_Matrix[i][j].b = (uint8_t)(this->Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal));

		}


	}

	for (int k = 0; k < iterations; k++) {

		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {

				//if (i >= 1 && j >= 1 && i < Height - 1 && j < width - 1) {
				Mid.Pixel_Matrix[i][j].r = (uint8_t)(Mid.Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
				Mid.Pixel_Matrix[i][j].g = (uint8_t)(Mid.Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal));
				Mid.Pixel_Matrix[i][j].b = (uint8_t)(Mid.Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal));
				//}
			}


		}

	}





	if (alter == 1) {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].r;
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].g;
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].b;
				this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
			}
		}
	}

}
void Image::Image_Convolution(double Conv_Kernel[3][3], int const &iterations, int const &alter) {

	Image Mid;
	int index = 0;
	double Kernel_Normal = 0;
	Mid.Load_Image(this->f_name);

	if (this->Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	Mid.init_pixel_matrix();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			Kernel_Normal += Conv_Kernel[i][j];
		}
	}


	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {


			Mid.Pixel_Matrix[i][j].r = (uint8_t)(this->Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
			Mid.Pixel_Matrix[i][j].g = (uint8_t)(this->Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal));
			Mid.Pixel_Matrix[i][j].b = (uint8_t)(this->Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal));

		}


	}
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
		}
	}


	for (int k = 0; k < iterations; k++) {

		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {

				//if (i >= 1 && j >= 1 && i < Height - 1 && j < width - 1) {
				Mid.Pixel_Matrix[i][j].r = (uint8_t)(this->Get_Neighbour_Mean_R(i, j, Conv_Kernel, Kernel_Normal));
				Mid.Pixel_Matrix[i][j].g = (uint8_t)this->Get_Neighbour_Mean_G(i, j, Conv_Kernel, Kernel_Normal);
				Mid.Pixel_Matrix[i][j].b = (uint8_t)this->Get_Neighbour_Mean_B(i, j, Conv_Kernel, Kernel_Normal);
				//}
			}


		}

		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
			}
		}

	}





	if (alter == 1) {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].r;
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].g;
				this->image_data[index++] = Mid.Pixel_Matrix[i][j].b;
				this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
			}
		}
	}
	else {
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				this->Pixel_Matrix[i][j] = Mid.Pixel_Matrix[i][j];
			}
		}
	}

}
void Image::Save_As_PNG(const char *name) {
	char s_name[50];
	char type[10];
	strcpy(type, ".png");
	strcpy(s_name, name);
	strcat(s_name, type);
	if (channel > 3) {
		channel = 3;
	}
	stbi_write_jpg(s_name, width, Height, channel, image_data, 100);
	//stbi_write_png(s_name, this->width, this->Height, 8, this->image_data, 1);
	//stbi_write_bmp(s_name, this->width, this->Height, 8, this->image_data);
	std::cout << "\nFile Saved Succsfully As: " << s_name << std::endl;

}
CoordinateFrame Image::GetCoordinateFrame(const int start_y, const int start_x, const int target_y, const int target_x) {
	float dx, sx, dy, sy, err, e2;
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	CoordinateFrame Points;
	float x0 = (float)start_y, x1 = (float)target_y, y0 = (float)start_x, y1 = (float)target_x;
	dx = (float)(abs(target_y - start_y));
	sx = (float)(start_y < target_y ? 1 : -1);
	dy = (float)(-abs(target_x - start_x));
	sy = (float)(start_x < target_x ? 1 : -1);
	err = dx + dy;  //error value
	while (true) {
		if (x0 == x1 && y0 == y1) {
			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.push_back({ (int)x0,(int)y0 });
			break;
		}

		//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
		Points.push_back({ (int)x0,(int)y0 });

		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx) {
			err += dx;
			y0 += sy;
		}

	}



	return Points;
}
void Image::Update_Image_Data() {
	int index = 0;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}
}
void Image::Free_Pixel_Matrix() {
	if (Pixel_Matrix != nullptr) {
		for (int i = 0; i < this->Height;i++) {
			delete[] Pixel_Matrix[i];
		}
		//delete[] Pixel_Matrix;
	}
}
void Image::Up_Scale() {
	std::vector<unsigned char> temp;
	for (int i = 0; i < this->width*this->Height * 3; i++) {
		temp.push_back(this->image_data[i]);
	}
	this->image_data = (unsigned char*)realloc(this->image_data, this->width*this->Height * 3 * 9);
	this->width *= 3;
	this->Height *= 3;
	int z = 0;
	this->init_pixel_matrix();

	for (int i = 0; i < this->Height; i += 3) {
		for (int j = 0; j < this->width; j += 3) {
			for (int k = 0; k < 3; k++) {
				for (int m = 0; m < 3; m++) {
					Pixel_Matrix[i + k][j + m].r = temp[z];
					Pixel_Matrix[i + k][j + m].g = temp[z + 1];
					Pixel_Matrix[i + k][j + m].b = temp[z + 2];

				}
			}

			z += 3;
		}
	}



	//quality enchancment


	for (int i = 0; i < this->Height - 3; i += 3) {
		for (int j = 0; j < this->width - 3; j += 3) {

			if (j < 3) {
				for (int k = 0; k < 3; k++) {
					Pixel_Matrix[i + k][j + 2].r = (Pixel_Matrix[i + k][j + 2].r + Pixel_Matrix[i + k][j + 3].r) / 2;
					Pixel_Matrix[i + k][j + 2].g = (Pixel_Matrix[i + k][j + 2].g + Pixel_Matrix[i + k][j + 3].g) / 2;
					Pixel_Matrix[i + k][j + 2].b = (Pixel_Matrix[i + k][j + 2].b + Pixel_Matrix[i + k][j + 3].b) / 2;
				}

				for (int k = 0; k < 3; k++) {
					Pixel_Matrix[i + 2][j + k].r = (Pixel_Matrix[i + 2][j + k].r + Pixel_Matrix[i + 3][j + k].r) / 2;
					Pixel_Matrix[i + 2][j + k].g = (Pixel_Matrix[i + 2][j + k].g + Pixel_Matrix[i + 3][j + k].g) / 2;
					Pixel_Matrix[i + 2][j + k].b = (Pixel_Matrix[i + 2][j + k].b + Pixel_Matrix[i + 3][j + k].b) / 2;

				}
			}

			else {

				for (int k = 0; k < 3; k++) {
					Pixel_Matrix[i + k][j + 2].r = (Pixel_Matrix[i + k][j + 2].r + Pixel_Matrix[i + k][j + 3].r) / 2;
					Pixel_Matrix[i + k][j + 2].g = (Pixel_Matrix[i + k][j + 2].g + Pixel_Matrix[i + k][j + 3].g) / 2;
					Pixel_Matrix[i + k][j + 2].b = (Pixel_Matrix[i + k][j + 2].b + Pixel_Matrix[i + k][j + 3].b) / 2;

					Pixel_Matrix[i + k][j + 3].r = (Pixel_Matrix[i + k][j + 3].r + Pixel_Matrix[i + k][j + 2].r) / 2;
					Pixel_Matrix[i + k][j + 3].g = (Pixel_Matrix[i + k][j + 3].g + Pixel_Matrix[i + k][j + 2].g) / 2;
					Pixel_Matrix[i + k][j + 3].b = (Pixel_Matrix[i + k][j + 3].b + Pixel_Matrix[i + k][j + 2].b) / 2;

				}


				for (int k = 0; k < 3; k++) {
					Pixel_Matrix[i + 2][j + k].r = (Pixel_Matrix[i + 2][j + k].r + Pixel_Matrix[i + 3][j + k].r) / 2;
					Pixel_Matrix[i + 2][j + k].g = (Pixel_Matrix[i + 2][j + k].g + Pixel_Matrix[i + 3][j + k].g) / 2;
					Pixel_Matrix[i + 2][j + k].b = (Pixel_Matrix[i + 2][j + k].b + Pixel_Matrix[i + 3][j + k].b) / 2;


					Pixel_Matrix[i + 3][j + k].r = (Pixel_Matrix[i + 3][j + k].r + Pixel_Matrix[i + 2][j + k].r) / 2;
					Pixel_Matrix[i + 3][j + k].g = (Pixel_Matrix[i + 3][j + k].g + Pixel_Matrix[i + 2][j + k].g) / 2;
					Pixel_Matrix[i + 3][j + k].b = (Pixel_Matrix[i + 3][j + k].b + Pixel_Matrix[i + 2][j + k].b) / 2;
				}

			}


		}
	}

	Update_Image_Data();
	Free_Pixel_Matrix();


}



// Under DEV






void Image::Convert_RGB_To_LAB(int const &alter) {
	if (Pixel_Matrix == nullptr) {
		this->init_pixel_matrix();
	}
	double M[3][3] = { {0.4124,	0.3567,	0.1805},
					   {0.2126,	0.7152,	0.0722},
					   {0.0193,	0.1192,	0.9505} };

	int index;
	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {
			RGB_XYZ_Transformation(Pixel_Matrix[i][j], M);

		}
	}

	if (alter == 1) {
		index = 0;
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				image_data[index++] = Pixel_Matrix[i][j].r;
				image_data[index++] = Pixel_Matrix[i][j].g;
				image_data[index++] = Pixel_Matrix[i][j].b;

			}
		}

	}
}

//ver 1 under development

void Image::Detect_Faces() {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	short flag = 0;
	int distance = 0 ,min_d = 355, skin_thresh = 5, grap_thresh = 30;
	float treshold = 95;
	int validation_level = 0;
	int n_valid_bounty = 10;
	coordinate left_eye, right_eye;
	left_eye.x = right_eye.x = 0;
	left_eye.y = right_eye.y = 0;
	pixel black;
	Color_Palette CSET;
	pixel skin_graph, nose_graph, forhead_graph, chin_graph;
	black.r = black.g = black.b = 0;

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {

			if (flag == 0) {
				if (Pixel_Matrix[i][j].r < treshold  && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold) {
					left_eye.x = j;
					left_eye.y = i;
					flag = 1;
#ifdef FaceDebug	



					Draw_Circle(j, i, 3, 'g'); //detected eye loctaion -left eye-

#endif
				}
			}
			else if (flag == 1) {
				if (distance > width / 3) {
					break;
				}
				else if (Pixel_Matrix[i][j].r < treshold && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold && distance > 30) {
					right_eye.x = j;
					right_eye.y = i;
					flag = 2;
					//i += 4;
#ifdef FaceDebug


					Draw_Circle(j, i, 3, 'r'); //detected eye location -right eye
					Draw_Circle(left_eye.x, left_eye.y, 3, 'g'); //detected eye location -right eye
#endif


					//defenition of skin graphs for validation sequance
					skin_graph = Pixel_Matrix[(left_eye.y)][(left_eye.x) + (distance / 2)];
					if ((left_eye.y) + (distance / 2) < Height && (left_eye.x) + (distance / 2) < width) {
						nose_graph = Pixel_Matrix[(left_eye.y) + (distance / 2)][(left_eye.x) + (distance / 2)];
					}
					if (left_eye.y - (distance / 4) > 0) {
						forhead_graph = Pixel_Matrix[(left_eye.y - (distance / 4))][(left_eye.x) + (distance / 2)];
					}
					if (left_eye.y + 1.3*distance < Height) {
						int temp = (int)1.3*distance;
						chin_graph = Pixel_Matrix[(left_eye.y + (temp))][(left_eye.x) + (distance / 2)];
					}
					//

					//in case skin graph is black -> most likely not a skin color
					if (Color_Distance(black, skin_graph) < 30) {
						flag = 0;
						break;
					}
				}
				distance++;
			}

		}
		if (flag == 2 && distance > 50 && left_eye.x + (distance / 2) < width &&
			left_eye.y + (distance / 2) < Height &&Color_Distance(Pixel_Matrix[(left_eye.y) + (distance / 2)][(left_eye.x) + (distance / 2)], black) > min_d) {


			skin_graph = Pixel_Matrix[(left_eye.y)][(left_eye.x) + (distance / 2)];

			if (skin_graph.r < 120 && skin_graph.g < 120 && skin_graph.b < 120) {
				continue;
			}






#ifdef FaceDebug

			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 3, 'b'); //sking graph location
			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 4, 'r'); //sking graph location
			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 2, 'g'); //sking graph location

			Draw_Line(left_eye.y, left_eye.x, left_eye.y, left_eye.x + distance / 2, 'b'); // line to cetner point 
#endif
			if (Color_Distance(skin_graph, Pixel_Matrix[left_eye.y + distance / 2][left_eye.x]) < grap_thresh) {

				if (Color_Distance(skin_graph, Pixel_Matrix[left_eye.y + distance / 2][left_eye.x]) < skin_thresh) { // left chick cmp

					validation_level++; //level 1

					if (Distance_Neighbors(treshold, left_eye.y + distance / 2, left_eye.x)) {
						validation_level += n_valid_bounty;
						std::cout << "Validated --Neighbor-- left chick: " << validation_level << std::endl;

					}
#ifdef FaceDebug
					Draw_Circle((left_eye.x), (left_eye.y) + (distance / 2), 3, 'W'); //chick graph location -left eye-
					Draw_Line(left_eye.y, left_eye.x, left_eye.y + distance / 2, left_eye.x, 'W'); // line to chick point -left eye-
					cout << "Validated left chick: " << validation_level << endl;
#endif // FaceDebug


				}

				if (Color_Distance(skin_graph, Pixel_Matrix[right_eye.y + distance / 2][right_eye.x]) < skin_thresh) {//right chick
					validation_level++; //level 2
					std::cout << "Validated Right chick: " << validation_level << std::endl;

					if (Distance_Neighbors(treshold, right_eye.y + distance / 2, right_eye.x)) {
						validation_level += n_valid_bounty;
						std::cout << "Validated  --Neighbor-- right chick: " << validation_level << std::endl;

					}

				}



				if (Color_Distance(skin_graph, forhead_graph) < grap_thresh) { //forhead vs skin center cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y - (distance / 4), 3, 'W'); //at forhead
					Draw_Line(left_eye.y, left_eye.x + distance / 2, left_eye.y - (distance / 4), left_eye.x + distance / 2, 'W');

#endif
					validation_level++; //level 3
					std::cout << "Validated Forhead - Center: " << validation_level << std::endl;

					if (Distance_Neighbors(treshold, left_eye.y - (distance / 4), left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						std::cout << "Validated  --Neighbor-- Forhead - Center: " << validation_level << std::endl;

					}

				}





				if (Color_Distance(nose_graph, skin_graph) < grap_thresh) {//nose vs middle face cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y + distance / 2, 3, 'W');
					//Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y + (distance / 2), 'W');

#endif
					validation_level++; //level 4
					std::cout << "Validated Nose - Center: " << validation_level << std::endl;

					if (Distance_Neighbors(treshold, left_eye.y + distance / 2, left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						std::cout << "Validated  --Neighbor-- Nose - Center: " << validation_level << std::endl;

					}
				}


				if (Color_Distance(chin_graph, skin_graph) < grap_thresh) {//chin vs middle face cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y + 1.3*distance, 3, 'W');
					Draw_Line(left_eye.y, left_eye.x + distance / 2, left_eye.y + 1.3*(distance), left_eye.x + distance / 2, 'W');

#endif
					validation_level++; //level 5
					std::cout << "Validated Chin - Center: " << validation_level << std::endl;

					if (Distance_Neighbors(treshold, left_eye.y + (int)(1.3*distance), left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						std::cout << "Validated  --Neighbor-- Chin - Center: " << validation_level << std::endl;

					}
				}





#ifdef FaceDebug




				//right eye validate for v2 yet to be added to calculation
				Draw_Line(right_eye.y, right_eye.x, right_eye.y, right_eye.x - distance / 2, 'b'); // line to cetner point from -right eye-
				Draw_Circle((right_eye.x), (right_eye.y) + (distance / 2), 3, 'W'); //chick graph location -right eye- 
				Draw_Line(right_eye.y, right_eye.x, right_eye.y + distance / 2, right_eye.x, CSET.White); // line to chick point -right eye-

#endif

				if (validation_level >= 30) {
					Draw_Square(left_eye.x + distance / 2, left_eye.y + distance / 2, distance, distance, 'r');
					i += 4;
					validation_level = 0;
				}

			}

			flag = 0;
			distance = 0;
		}
		else {
			flag = 0;
			distance = 0;
		}

	}

}
//
//coordinate point_to_coordinate(Point const &point) {
//	coordinate result = { 0,0 };
//	int arb[2][3] = { {4,0,0},{0,0,4} };
//	int p[3][1] = { {point.x},{point.y},{point.z} };
//	int res[2][1] = { {0},{0} };
//
//	int sum;
//
//	for (int i = 0; i < 2; i++)
//	{
//		for (int j = 0; j < 1; j++)
//		{
//			res[i][j] = 0;
//			for (int k = 0; k < 3; k++)
//			{
//				res[i][j] += arb[i][k] * p[k][j];
//			}
//		}
//	}
//
//	result.x = res[0][0];
//	result.y = res[1][0];
//
//	return result;
//}
//
//coordinate homogeneous_transformation(Point const &point) {
//	coordinate result = { 0,0 };
//	int pv[4][4] = { {1,0,0,0},{0,1,0,0},{0,0,1,0} ,{0,0,1,0} };
//	int po[4][1] = { {point.x},{point.y},{point.z},1 };
//	int res[4][1] = { {0},{0},{0},{0} };
//
//	int sum;
//
//	for (int i = 0; i < 4; i++)
//	{
//		for (int j = 0; j < 1; j++)
//		{
//			res[i][j] = 0;
//			for (int k = 0; k < 4; k++)
//			{
//				res[i][j] += pv[i][k] * po[k][j];
//			}
//		}
//	}
//
//	result.x = res[0][0] / res[3][0];
//	result.y = res[1][0] / res[3][0];
//
//	return result;
//}
//
//coordinate orthographic_projection(Point const &point) {
//	coordinate result = { 0,0 };
//	Point FocalE{ 2,3,1 };
//	int arb[3][3] = { {1,0,FocalE.x / FocalE.z},{0,1,FocalE.y / FocalE.z},{0,0,1 / FocalE.z} };
//	int p[3][1] = { {point.x},{point.y},{point.z} };
//	int res[3][1] = { {0},{0},{0} };
//	int cx, cy;
//	cx = cy = 1;
//	int sum;
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 1; j++)
//		{
//			res[i][j] = 0;
//			for (int k = 0; k < 3; k++)
//			{
//				res[i][j] += arb[i][k] * p[k][j];
//			}
//		}
//	}
//
//	result.x = res[0][0] + cx;
//	result.y = res[1][0] + cy;
//
//	return result;
//}


//







