#pragma once

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <vector>
using namespace std;

class Image {
protected:
	char f_name[50];
	unsigned char *image_data;
	int Height;
	int width;
	int channel;
	unsigned int im_size;
	int pos_X, pos_Y;
	unsigned short MODE = 0;
	void color_set(char color_choice, int &index);
	char decode_color(uint8_t r, uint8_t g, uint8_t b);
public:
	Image();
	Image(unsigned char *image_data, int Height, int width, int channel);
	Image(int Height, int width, int channel);
	~Image();
	void Set_Pixel_By_Inedx(int index, uint8_t value);
	void Load_Blank_Canvas();
	void Load_Blank_Canvas(int width,int height,char set_color);
	void printImdata();
	void printImdata(char color);
	void Manual_Draw();
	void Load_Image();
	void Load_Image(const char *f_name);
	void Write_Image();
	void Write_Image(const char *f_name);
	void Color_Spec(int w, int h, char color);
	void Color_Spec(int index, char color);
	 void operator+( Image const &a);
	 void operator-(Image const &b);
	 void operator/(Image const &b);
};


