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

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

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
