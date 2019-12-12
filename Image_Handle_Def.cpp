#pragma once

#ifndef Im
#define Im

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include "Image_Header.h"
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

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define FaceDebug



Pixel_C::Pixel_C(){
	this->data.r = 0;
	this->data.g = 0;
	this->data.b = 0;
	this->data.index_range = 0;
	this->data.analysis = 0;
}
Pixel_C::Pixel_C(uint8_t r, uint8_t g, uint8_t b){
	this->data.r = r;
	this->data.g = g;
	this->data.b = b;
	this->data.analysis = 0;

}
Pixel_C::~Pixel_C(){

}

char Pixel_C::interpret_color() const{
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
	else if (data.r== data.g== data.b && data.r <240 && data.b<240 && data.g< 240) {//shades of gray
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

void Pixel_C::set_refrence(uint8_t &r, uint8_t &g, uint8_t &b){
	r = this->data.r;
	g = this->data.g;
	b = this->data.b;
}
uint8_t Pixel_C::get_r() const{
	return this->data.r;
}
uint8_t Pixel_C::get_g() const{
	return this->data.g;
}
uint8_t Pixel_C::get_b() const{
	return this->data.b;
}

void Pixel_C::set_r(const uint8_t r){
	this->data.r = r;
}
void Pixel_C::set_g(const uint8_t g){
	this->data.g = g;
}
void Pixel_C::set_b(const uint8_t b){
	this->data.b = b;
}


void gcd_list(int w, int h, vector<int> &list) {
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
ostream &operator<<(ostream &out, pixel &in) {
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
	
	int sq = (int)sqrt(number_of_pix) +1;
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
		pix.g= 255;
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
pixel &operator*(pixel const &a, pixel const &b) {
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
void operator+=(pixel &a ,pixel &b) {
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
	this->image_data = NULL;
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
	stbi_image_free(image_data);

}
int Image::getWidth() const {
	return this->width;
}
int Image::getHeight()const {
	return this->Height;
}
void Image::Load_Blank_Canvas() {
	cout << "\nPlease Enter Height Of Image: ";
	cin >> Height;
	cout << "\nPlease Enter Width Of Image: ";
	cin >> width;
	cout << "\nPlease Enter Number Of Color Channels: ";
	cin >> channel;
	if (image_data != NULL) {

		stbi_image_free(image_data);
	}
	else {
		image_data = (unsigned char*)calloc(width*Height*channel, sizeof(unsigned char));
	}
}
void Image::Load_Blank_Canvas(int width, int height, char set_color) {
	this->channel = 3;
	this->width = width;
	this->Height = height;
	if (image_data != NULL) {

		stbi_image_free(image_data);
	}
	if (set_color == 'B') {
		image_data = (unsigned char*)calloc(width*Height*channel, sizeof(unsigned char));
	}
	else {
		image_data = (unsigned char*)calloc(width*Height*channel, sizeof(unsigned char));
		for (int i = 0; i < width*Height*channel; i++) {
			Color_Spec(i, set_color);
		}
	}
}
void Image::printImdata() {
	int index = 0;
	system("cls");
	for (int i = 0; i < width*Height * 3; i += 3) {

		if (i % (width * 3) == 0) {
			cout << "\n";
		}

		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 1) {
			cout << "[]";
			index += 3;
		}
		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 2) {
			cout << "_" << " ";
			index += 3;
		}
		else {

			cout << decode_color(image_data[index], image_data[index + 1], image_data[index + 2]) << " ";
			index += 3;
		}

	}
}
void Image::printImdata(char color) {
	int index = 0;
	system("cls");
	for (int i = 0; i < width*Height * 3; i += 3) {

		if (i % (width * 3) == 0) {
			cout << "\n";
		}

		if (i == (width * 3)*(pos_Y)+3 * (pos_X + 1) && MODE == 1) {
			cout << "[" << color << "] ";
			index += 3;
		}

		else {

			cout << decode_color(image_data[index], image_data[index + 1], image_data[index + 2]) << " ";
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
	cout << "Please Enter Image Name Including .'Type': ";
	cin >> f_name;
	strcpy(this->f_name, f_name);
	this->image_data = stbi_load(f_name, &width, &Height, &channel, 3);
	this->im_size = width * Height;
	if (this->image_data == NULL) {
		cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
	}
	else {
		cout << "\nFile Loaded Succsesfully\n";
	}
}
void Image::Load_Image(const char *f_name) {
	strcpy(this->f_name, f_name);
	this->image_data = stbi_load((char*)f_name, &width, &Height, &channel, 3);
	this->im_size = width * Height;
	if (this->image_data == NULL) {
		cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
	}
	else {
		cout << "\nFile Loaded Succsesfully\n";
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
		cout << "Save As?: ";
		cin >> s_name;
		strcat(s_name, type);
		stbi_write_jpg(s_name, width, Height, channel, image_data, 100);

		cout << "\nFile Saved Succsfully As: " << s_name << endl;
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

	cout << "\nFile Saved Succsfully As: " << s_name << endl;

}
void Image::Color_Spec(int w, int h, char color) {
	int pos = ((width * 3)*(h)+3 * (w));
	color_set(color, pos);
}
void Image::Color_Spec(int index, char color) {

	int pos = index;
	color_set(color, pos);
}
void Image::Set_Pixel_By_Inedx(int index,uint8_t value) {
	this->image_data[index] = value;
}

void Image::operator+(Image const &a){
	int regulator;
	if (a.width != this->width || a.Height != this->Height) {
		cout << "Error image size invalid\n";
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
void Image::operator-(Image const &b){
	int regulator;
	if (b.width != this->width || b.Height != this->Height) {
		cout << "Error image size invalid\n";
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
		cout << "Error image size invalid\n";
		return;
	}
	else {

		for (int i = 0; i < b.Height*b.width * 3; i++) {
			if (b.image_data[i] ==0) {
				regulator = this->image_data[i] / (b.image_data[i]+1);
			}
			else if (this->image_data[i] == 0) {
				regulator =this->image_data[i] / (b.image_data[i]);
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
	this->Pixel_Matrix = (pixel**)malloc(sizeof(pixel*)*Height);
	for (int i = 0; i < Height; i++) {
		Pixel_Matrix[i] = (pixel*)malloc(sizeof(pixel)*width);
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
			this->Pixel_Matrix = (pixel**)malloc(sizeof(pixel*)*Height);
			for (int i = 0; i < Height; i++) {
				Pixel_Matrix[i] = (pixel*)malloc(sizeof(pixel)*width);
			}
		}
		else {

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
	unsigned max_size=0, max_index=0;
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
	vector<int> comp_levels;
	int choice;
	gcd_list(this->width, this->Height, comp_levels);
	if (comp_levels.size() == 1) {
		cout << "No Possible Compression Option Found" << endl;
		return;
	}
	else {
		system("cls");
		cout << "Choose Compression Level:\n";
		for (unsigned i = 1; i < comp_levels.size(); i++) {
			cout << i << ") " << comp_levels[i] << endl;
		}
		cout << endl;
		cin >> choice;
		int j = 0, k = 0,start_row=0,start_col=0,si=0,sj=0,index=0;
		pixel A_color;

		unsigned char *compressed = (unsigned char*)calloc((this->width)*(this->Height )* 3, sizeof(char));
		init_pixel_matrix();

		pixel **pixel_sigment = (pixel**)malloc(sizeof(pixel*)* comp_levels[choice]);
		for (int i = 0; i <  comp_levels[choice]; i++) {
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
	

			start_col +=  comp_levels[choice];
			if (start_col == width && start_row != Height) {
				start_row += comp_levels[choice];
				start_col = 0;
				if ( start_row == Height) {
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

		stbi_write_jpg("Compressed.jpg", width , Height , 3, compressed, 100);

	}	



	
	
}

void Image::Text_To_Image(const char *file_name)
{
	fstream file;
	char cur_char;
	unsigned short mode;
	int number_of_chars = 0,pixel_num=0,index=0,width=0,height=0;
	unsigned char *new_image;
	file.open(file_name);

	if (!file.is_open()) {
		return;
	}

	cout << "Please Input Decode Mode:\n.)Press 1 For Raw\n.)Press 2 For Enhanced\nInput: ";
	cin >> mode;
	if (mode == 1) {
		while (!file.eof()) {
			file.get(cur_char);
			number_of_chars++;
		}

		file.clear();
		file.seekg(0, ios::beg);
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
		file.seekg(0, ios::beg);
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
			new_image[index++] = (int)cur_char + rand()%64;
		}
	}
	stbi_write_jpg("ImageFromText.jpg", width, height, 3, new_image, 100);

	file.close();
}
void Image::Image_To_Text(const char *Image_name) {
	this->Load_Image(Image_name);
	for (int i = 0; i < Height*width * 3; i++) {
		cout << (char)image_data[i];
	}
}
void Image::Insert_Text_Into_Image(const char *file_name, const char *Image_Name) {
	this->Load_Image(Image_Name);
	fstream file;
	char cur_char;
    int index = 0,number_of_chars= 0;
	file.open(file_name);

	if (!file.is_open()) {
		return;
	}

	while (!file.eof()) {
		file.get(cur_char);
		number_of_chars++;
	}

	file.clear();
	file.seekg(0, ios::beg);

	if (number_of_chars < (this->Height*this->width * 3)) {
		while (!file.eof()) {
			file.get(cur_char);
			if (index >= (this->Height*this->width * 3)) {
				break;
			}
			if (file.eof()) {
				file.clear();
				file.seekg(0, ios::beg);
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
		cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		cout << "Height Of Image: " << Height << endl;
		cout << "Width Of Image: " << width << endl;
		cout << endl;
		return;
	}
	for (int i = center_x - s_width; i <= center_x+s_width; i++) {
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
	char mode_f[5],mode_c[10];
	strcpy(mode_f, "Fill");
	strcpy(mode_c, "Checkered");
	if (strcmp(mode_f, mode) == 0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
			cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			cout << "Height Of Image: " << Height << endl;
			cout << "Width Of Image: " << width << endl;
			cout << endl;
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
			cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			cout << "Height Of Image: " << Height << endl;
			cout << "Width Of Image: " << width << endl;
			cout << endl;
			return;
		}
		for (int j = center_y - s_height; j <= center_y + s_height; j++) {
			for (int i = center_x - s_width; i <= center_x + s_width; i+=2) {
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
			cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			cout << "Height Of Image: " << Height << endl;
			cout << "Width Of Image: " << width << endl;
			cout << endl;
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
		cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
		cout << "Height Of Image: " << Height << endl;
		cout << "Width Of Image: " << width << endl;
		cout << endl;
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
	if (strcmp(mode_f, mode)==0) {
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		int x, y;
		unsigned i = 0;
		if (center_x + c_radius > width || center_x - c_radius <0 || center_y + c_radius > Height || center_y - c_radius < 0) {
			cout << "Circle Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
			cout << "Height Of Image: " << Height << endl;
			cout << "Width Of Image: " << width << endl;
			cout << endl;
			return;
		}
		for (y = -c_radius; y <= c_radius; y++)
			for (x = -c_radius; x <= c_radius; x++)
				if ((x * x) + (y * y) <= (c_radius * c_radius))
					Color_Spec(Pixel_Matrix[center_y+y][center_x +x].index_range, color);
	}
}
void Image::Draw_Line(const int start_x, const int start_y, const int target_y, const unsigned char color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	if (target_y > this->Height || start_y > this->Height || start_y < 0 || start_x > width || start_x < 0) {
		cout << "Line Out Of Image Range\nDraw Action Aborted\n";
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
void Image:: Draw_Line(const int start_x, const int start_y, const int target_x, const int target_y, const unsigned char color) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	if (target_y > this->Height || start_y > this->Height || start_y < 0 || start_x > width || start_x < 0 || target_x > width) {
		cout << "Line Out Of Image Range\nDraw Action Aborted\n";
		return;
	}
	int marker = 0;

	if (start_y == target_y) {
		
		if (target_x > start_x) {

			for (int i = start_x; i < target_x; i++) {
				Color_Spec(Pixel_Matrix[start_y][i].index_range, color);

			}
		}
		else {
			for (int i = start_x; i > target_x ; i--) {
				Color_Spec(Pixel_Matrix[start_y][i].index_range, color);

			}
		}
	}
	else if(start_x == target_x){

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
				marker = start_y;
				for (int i = start_x; i < target_x; i++) {
					Color_Spec(Pixel_Matrix[marker][i].index_range, color);
					if (marker > target_y) {
						marker--;
					}
				}
			}
			else {
				marker = start_y;
				for (int i = start_x; i > target_x; i--) {
					Color_Spec(Pixel_Matrix[marker][i].index_range, color);
					if (marker > target_y) {
						marker--;
					}
				}
			}
		}
		else {
			if (target_x > start_x) {
				marker = start_y;
				for (int i = start_x; i < target_x; i++) {
					Color_Spec(Pixel_Matrix[marker][i].index_range, color);
					if (marker < target_y) {
						marker++;
					}
				}
			}
			else {
				marker = start_y;
				for (int i = start_x; i > target_x; i--) {
					Color_Spec(Pixel_Matrix[marker][i].index_range, color);
					if (marker < target_y) {
						marker++;
					}
				}
			}
		}
	}
}
void Image::Get_Center(unsigned &center_x, unsigned &center_y)const {
	center_x = width / 2;
	center_y = Height / 2;
}
void Image::Grayscale() {
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

	for (int i = 0; i < Height; i++) {

		for (int j = 0; j < width; j++) {

			image_data[index++] = Pixel_Matrix[i][j].r;
			image_data[index++] = Pixel_Matrix[i][j].g;
			image_data[index++] = Pixel_Matrix[i][j].b;

		}
	}

}
void Image::Convert_Grayscale() {
	this->Grayscale();
}

int Image::Color_Distance(pixel const &a, pixel const &b){
	int recored;
	recored = (a.b - b.b) + (a.r - b.r) + (a.g - b.g);
	if (recored < 0) {
		recored *= -1;
	}

	return recored;
}
float Image::Color_DistanceSq(pixel const &a, pixel const &b) {
	float  recored;
	recored = (b.r - a.r)*(b.r - a.r) + (b.g - a.g)*(b.g - a.g) + (b.b - a.b)*(b.b - a.b);
	return sqrt(recored);
}
bool Image::Distance_Neighbors(const float max_distance, int i, int j) {
	pixel center, point;
	center = Pixel_Matrix[i][j];
	float dist = 0;
	if (i - 1 < 0 && j+1 <width && j-1 > 0 && i+1 < Height) {
		point = Pixel_Matrix[i][j+1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i][j-1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i + 1][j];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i+1][j - 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}
		point = Pixel_Matrix[i+1][j + 1];
		dist = Color_DistanceSq(point, center);
		if (dist > max_distance) {
			return false;
		}

	}
	 if(i+1 > Height && j + 1 < width && j - 1 > 0 && i-1 >0)
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
		 point = Pixel_Matrix[i-1][j];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i - 1][j+1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i - 1][j-1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }

	}
	 if (j-1 < 0 && i + 1 < Height && i - 1 > 0 && j +1 < width) {
		 point = Pixel_Matrix[i+1][j];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i + 1][j+1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i -1][j + 1];
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
	 if (j + 1 > width && i + 1 < Height && i - 1 > 0 && j-1 >0) {
		 point = Pixel_Matrix[i][j -1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i-1][j];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i-1][j - 1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i+1][j];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
		 point = Pixel_Matrix[i + 1][j-1];
		 dist = Color_DistanceSq(point, center);
		 if (dist > max_distance) {
			 return false;
		 }
	}

	 return true;

	
}

void Image::Mark_Identical_Pixels(pixel const &Target) {
	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}
	
	for (int i = 0; i < Height;i++) {
		for (int j = 0; j < width; j++) {
			if (Pixel_Matrix[i][j] == Target) {
				this->Draw_Square(j,i, 2, 2, 'r');
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
void Image::Mark_Identical_Pixels(Image &Source,const char *mode) {
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
					if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50 ) {
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
				diffrence[Pixel_Matrix[i][j].index_range+1] = 0;
				diffrence[Pixel_Matrix[i][j].index_range+2] = 0;
			}
		}
	}
	stbi_write_jpg("Pixel_Diffrence.jpg", this->width, this->Height, 3, diffrence, 100);
}
void Image::Write_Pixel_Difference(Image &Source,const char *mode, int min_diff) {
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
				if (Color_Distance(Pixel_Matrix[i][j],Source.Pixel_Matrix[i][j]) > min_diff){
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
	int posR, PosG, PosB, H = 500, W = 1300;
	int bar_width = this->width / 300;
	if (bar_width == 0) {
		bar_width = 1;
	}
	int sR = 0, sG = 0, sB = 0;
	Image frame;
	frame.Load_Blank_Canvas(W, H, 'B');
	frame.Draw_Square(250, 250, 150, 150, 'r');
	frame.Draw_Square(650, 250, 150, 150, 'g');
	frame.Draw_Square(1050, 250, 150, 150, 'b');
	frame.Draw_Square(250, 250, 151, 151, 'r');
	frame.Draw_Square(650, 250, 151, 151, 'g');
	frame.Draw_Square(1050, 250, 151, 151, 'b');
	posR = 101;
	PosG = 501;
	PosB = 901;

	if (this->Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}


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
	int index=0;
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
	unsigned char *flip = (unsigned char *)malloc(width*Height * 3*sizeof(unsigned char));
	int index = 0;
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	for (int i = Height-1; i >= 0; i--) {
		for (int j = width-1; j >= 0; j--) {
			flip[index++] = Pixel_Matrix[i][j].r;
			flip[index++] = Pixel_Matrix[i][j].g;
			flip[index++] = Pixel_Matrix[i][j].b;

		}
	}

	delete[] this->image_data;
	this->image_data = flip;
}
void Image::Tresholding(const char *mode,int value) {
	int index = 0;
	char m1[6];
	char m2[15];
	strcpy(m1, "Trunc");
	strcpy(m2, "EdgeTriggerd");
	if (strcmp(m1, mode) == 0) {
		if (Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < width; j++) {
				if (Pixel_Matrix[i][j].r > value || Pixel_Matrix[i][j].g > value || Pixel_Matrix[i][j].b > value) {
					image_data[index++] = 255;
					image_data[index++] = 255;
					image_data[index++] = 255;
				}
				else {
					image_data[index++] = 0;
					image_data[index++] = 0;
					image_data[index++] = 0;
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
			if (Color_Distance(prev,Pixel_Matrix[i][j]) > 50 )
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
	if (source_x + 1 > width | source_x - 1 < 0 || source_y + 1 > Height || source_y - 1 < 0) {
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
				else if(Color_Distance(Pixel_Matrix[i][j],center) < band && Color_Distance(Pixel_Matrix[i + 1][j],left)< band &&Color_Distance(Pixel_Matrix[i - 1][j],right)< band
					&&Color_Distance(Pixel_Matrix[i][j + 1],down)< band &&Color_Distance(Pixel_Matrix[i][j - 1],up)< band) {
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
		cout << "Cannot Multiply Pixel Please Make Sure Image A's Width = Image B's Height\n";
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
		pixel **n_mat = (pixel**)malloc(sizeof(pixel*)*this->Height);
		for (int i = 0; i < b.width; i++) {
			n_mat[i] = (pixel*)malloc(sizeof(pixel)*b.width);
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
		unsigned char *updated = (unsigned char*)malloc(this->Height *b.width * 3 * sizeof(unsigned char));
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

void Image::Quarantine_Pixel(pixel const &sample,const float max_difference, const char *mode, const int Alter) {
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
	else if (strcmp(m1,mode)==0) {
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

void Image::Kronecker_product(Image &b,const char *mode, const int Alter){
	char m1[4], m2[5],m3[15],m4[8];
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
		for (int i = 0; i < b.Height*this->Height;i++) {
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

// Under DEV

void Image::Mark_Different_Pixels(Image &Source, const char *mode, int min_diff) {
	char m2[6] = "Loose";
	char m3[6] = "Area";
	int frame_w = 0, frame_h = 0;


	if (strcmp(m2, mode) == 0) {
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
				if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
					this->Draw_Square(j, i, 2, 2, 'r');
				}
			}
		}

	}
	else if (strcmp(m3, mode) == 0) {
		if (this->width != Source.width || this->Height != Source.Height) {
			return;
		}
		if (this->Pixel_Matrix == nullptr) {
			init_pixel_matrix();
		}
		if (Source.Pixel_Matrix == nullptr) {
			Source.init_pixel_matrix();
		}

		for (int i = 0; i < Height; i++) { // marking all diffrent pixels
			for (int j = 0; j < width; j++) {
				if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
					this->Pixel_Matrix[i][j].r = 43;
					this->Pixel_Matrix[i][j].g = 43;
					this->Pixel_Matrix[i][j].b = 43;

				}
			}
		}
		//seaching with dymanic frame for 43,43,43 collored areas
		if (Height < 1000 && width < 100) {
			frame_h = this->Height / 10;
			frame_w = this->width / 10;
		}
		else {
			frame_h = frame_w = 6;
		}
		if (frame_h <= 1) {
			frame_h = 2;
		}
		if (frame_w <= 1) {
			frame_h = 2;
		}

		int start_row = 0, start_col = 0, j = 0, si = 0, sj = 0;
		short flag = 0;

		/*pixel **pixel_sigment = (pixel**)malloc(sizeof(pixel*)* frame_h);
		for (int i = 0; i < frame_w; i++) {
			pixel_sigment[i] = (pixel*)malloc(sizeof(pixel)*(frame_w));
		}*/

		while (true) {

			for (int i = start_row; i < start_row + (frame_h); i++) {

				for (j = start_col; j < start_col + (frame_w); j++) {

					if (Pixel_Matrix[i][j].r == 43 && Pixel_Matrix[i][j].g == 43 && Pixel_Matrix[i][j].b == 43) {
						flag = 1;
					}
					/*pixel_sigment[si][sj] = Pixel_Matrix[i][j];
					sj++;*/
				}
				//si++;
				//sj = 0;
			}
			//si = sj = 0;

			if (flag == 1)
			{
				/*
				for (int k = 0; k < frame_h; k++) {
					if (pixel_sigment[k][0].r == 43 && pixel_sigment[k][0].b == 43 && pixel_sigment[k][0].g == 43) {
						flag =0;
						break;
					}
				}
				if (flag != 0) {
					for (int k = 0; k < frame_h; k++) {
						if (pixel_sigment[k][frame_w-1].r == 43 && pixel_sigment[k][frame_w - 1].b == 43 && pixel_sigment[k][frame_w - 1].g == 43) {
							flag = 0;
							break;
						}
					}
				}
				if (flag != 0) {
					for (int k = 0; k < frame_w; k++) {
						if (pixel_sigment[0][k].r == 43 && pixel_sigment[0][k].b == 43 && pixel_sigment[0][k].g == 43) {
							flag = 0;
							break;
						}
					}
				}
				if (flag != 0) {
					for (int k = 0; k < frame_w; k++) {
						if (pixel_sigment[frame_h-1][k].r == 43 && pixel_sigment[frame_h - 1][k].b == 43 && pixel_sigment[frame_h - 1][k].g == 43) {
							flag = 0;
							break;
						}
					}*/


				for (int k = start_row; k < start_row + frame_h; k++) {
					if (Pixel_Matrix[k][start_col].r == 43 && Pixel_Matrix[k][start_col].g == 43 && Pixel_Matrix[k][start_col].b == 43) {
						flag = 0;
						break;
					}
				}
				for (int k = start_row; k < start_row + frame_h; k++) {
					if (Pixel_Matrix[k][start_col + frame_w].r == 43 && Pixel_Matrix[k][start_col + frame_w].g == 43 && Pixel_Matrix[k][start_col + frame_w].b == 43) {
						flag = 0;
						break;
					}
				}
				for (int k = start_col; k < start_col + frame_w; k++) {
					if (Pixel_Matrix[start_row][k].r == 43 && Pixel_Matrix[start_row][k].g == 43 && Pixel_Matrix[start_row][k].b == 43) {
						flag = 0;
						break;
					}
				}
				for (int k = start_col; k < start_col + frame_w; k++) {
					if (Pixel_Matrix[start_row + frame_h][k].r == 43 && Pixel_Matrix[start_row + frame_h][k].g == 43 && Pixel_Matrix[start_row + frame_h][k].b == 43) {
						flag = 0;
						break;
					}
				}
				//draw the square
				if (flag != 0) {
					//this->Draw_Square(start_col + frame_w / 2, start_row + frame_h / 2, frame_w, frame_h, 'r');
					this->Draw_Circle(start_col + frame_w, start_col + frame_h, frame_h, 'r');
					flag = 0;
				}
			}


			frame_h++;
			frame_w++;




			start_col += frame_w;

			if (start_col >= width) {
				start_row += frame_h;
				start_col = 0;
				if (start_row + frame_h >= Height || start_col + frame_w >= width) {
					break;
				}
			}



		}

	}
	else
	{
		return;
	}
}
//ver 1 under development

void Image::Detect_Faces() {
	if (Pixel_Matrix == nullptr) {
		init_pixel_matrix();
	}

	short flag = 0;
	int distance = 0,treshold =50,min_d = 15;
	int validation_level = 0;
	int n_valid_bounty = 10;
	coordinate left_eye, right_eye;
	left_eye.x = right_eye.x = 0;
	left_eye.y = right_eye.y = 0;
	pixel black;
	pixel skin_graph,nose_graph,forhead_graph,chin_graph;
	black.r = black.g = black.b = 0;

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < width; j++) {

			if (flag == 0) {
				if (/*Pixel_Matrix[i][j].r < treshold  && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold*/
					Color_DistanceSq(black,Pixel_Matrix[i][j])<30
					) {
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
				else if (/*Pixel_Matrix[i][j].r < treshold && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold && distance >min_d*/
					Color_DistanceSq(black, Pixel_Matrix[i][j]) < 30
					) {
					right_eye.x = j;
					right_eye.y = i;
					flag = 2;
					//i += 4;
#ifdef FaceDebug


					Draw_Circle(j, i, 3, 'r'); //detected eye location -right eye
					Draw_Circle(left_eye.x, left_eye.y , 3, 'g'); //detected eye location -right eye
#endif


					//defenition of skin graphs for validation sequance
					skin_graph = Pixel_Matrix[(left_eye.y)][(left_eye.x) + (distance / 2)];
					if ((left_eye.y) + (distance / 2) < Height && (left_eye.x) + (distance / 2) < width ){
					nose_graph = Pixel_Matrix[(left_eye.y) + (distance / 2)][(left_eye.x) + (distance / 2)];
					}
					if (left_eye.y - (distance / 4) > 0) {
						forhead_graph = Pixel_Matrix[(left_eye.y - (distance / 4))][(left_eye.x) + (distance / 2)];
					}
					if (left_eye.y + 1.3*distance < Height) {
						int temp = 1.3*distance;
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
		if (flag == 2 && distance > 50 && left_eye.x +(distance /2 ) <width && 	
			left_eye.y + (distance / 2) < Height &&Color_Distance(Pixel_Matrix[(left_eye.y) + (distance / 2)][(left_eye.x) + (distance / 2)], black) > 200 ){

			
			skin_graph = Pixel_Matrix[(left_eye.y)][(left_eye.x) + (distance / 2)];

			if (skin_graph.r <120 && skin_graph.g<120 && skin_graph.b<120) {
				continue;
			}


			



#ifdef FaceDebug

			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 3, 'b'); //sking graph location
			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 4, 'r'); //sking graph location
			Draw_Circle((left_eye.x) + (distance / 2), (left_eye.y), 2, 'g'); //sking graph location

			Draw_Line(left_eye.x, left_eye.y, left_eye.x + distance / 2, left_eye.y, 'b'); // line to cetner point 
#endif
			if (Color_Distance(skin_graph, Pixel_Matrix[left_eye.y + distance / 2][left_eye.x]) < 50) {

				if (Color_Distance(skin_graph, Pixel_Matrix[left_eye.y + distance /2 ][left_eye.x]) < 40) { // left chick cmp

					validation_level++; //level 1

					if (Distance_Neighbors(treshold, left_eye.y + distance / 2, left_eye.x)) {
						validation_level += n_valid_bounty;
						cout << "Validated --Neighbor-- left chick: " << validation_level << endl;

					}
#ifdef FaceDebug
					Draw_Circle((left_eye.x), (left_eye.y) + (distance / 2), 3, 'W'); //chick graph location -left eye-
					Draw_Line(left_eye.x, left_eye.y, left_eye.x, left_eye.y + distance / 2, 'W'); // line to chick point -left eye-
					cout << "Validated left chick: " << validation_level << endl;
#endif // FaceDebug


				}

				if (Color_Distance(skin_graph, Pixel_Matrix[right_eye.y + distance / 2][right_eye.x]) < 40) {//right chick
					validation_level++; //level 2
					cout << "Validated Right chick: " << validation_level << endl;

					if (Distance_Neighbors(treshold, right_eye.y + distance / 2, right_eye.x)) {
						validation_level += n_valid_bounty;
						cout << "Validated  --Neighbor-- right chick: " << validation_level << endl;

					}

				}



				if (Color_Distance(skin_graph, forhead_graph) < 70) { //forhead vs skin center cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y - (distance / 4), 3, 'W'); //at forhead
					Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y - (distance / 4), 'W');

#endif
					validation_level++; //level 3
					cout << "Validated Forhead - Center: " << validation_level << endl;
					
					if (Distance_Neighbors(treshold, left_eye.y - (distance / 4), left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						cout << "Validated  --Neighbor-- Forhead - Center: " << validation_level << endl;

					}

				}





				if (Color_Distance(nose_graph, skin_graph) < 70) {//nose vs middle face cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y + distance / 2, 3, 'W');
					Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y + (distance / 2), 'W');

#endif
					validation_level++; //level 4
					cout << "Validated Nose - Center: " << validation_level << endl;

					if (Distance_Neighbors(treshold, left_eye.y + distance / 2, left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						cout << "Validated  --Neighbor-- Nose - Center: " << validation_level << endl;

					}
				}


				if (Color_Distance(chin_graph, skin_graph) < 70) {//chin vs middle face cmp
#ifdef FaceDebug
					Draw_Circle(left_eye.x + distance / 2, left_eye.y + 1.3*distance, 3, 'W');
					Draw_Line(left_eye.x + distance / 2, left_eye.y, left_eye.x + distance / 2, left_eye.y + 1.3*(distance), 'W');

#endif
					validation_level++; //level 5
					cout << "Validated Chin - Center: " << validation_level << endl;

					if (Distance_Neighbors(treshold, left_eye.y + 1.3*distance, left_eye.x + distance / 2)) {
						validation_level += n_valid_bounty;
						cout << "Validated  --Neighbor-- Chin - Center: " << validation_level << endl;

					}
				}





#ifdef FaceDebug

				


				//right eye validate for v2 yet to be added to calculation
				Draw_Line(right_eye.x, right_eye.y, right_eye.x - distance / 2, right_eye.y, 'b'); // line to cetner point from -right eye-
				Draw_Circle((right_eye.x), (right_eye.y) + (distance / 2), 3, 'W'); //chick graph location -right eye- 
				Draw_Line(right_eye.x, right_eye.y, right_eye.x, right_eye.y + distance / 2, 'W'); // line to chick point -right eye-

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







  
