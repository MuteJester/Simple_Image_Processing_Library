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



}
Image::Image(int Height, int width, int channel) {
	this->Height = Height;
	this->width = width;
	this->channel = channel;
	this->pos_X = 0;
	this->pos_Y = 0;
}
Image::~Image() {
	stbi_image_free(image_data);

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
	init_pixel_matrix();
	if (center_x + s_width > width || center_y + s_height > Height || center_x - s_width < 0 || center_y - s_height < 0) {
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
		init_pixel_matrix();
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
		init_pixel_matrix();
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
		init_pixel_matrix();
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
	init_pixel_matrix();
	int x, y, r2;
	unsigned i = 0;
	if (center_x + c_radius > width || center_x - c_radius <0 || center_y + c_radius > Height || center_y - c_radius < 0) {
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
		init_pixel_matrix();
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
void Image::Get_Center(unsigned &center_x, unsigned &center_y)const {
	center_x = width / 2;
	center_y = Height / 2;
}




  
