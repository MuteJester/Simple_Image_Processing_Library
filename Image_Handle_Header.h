#pragma once

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
struct pixel {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	unsigned index_range;
	unsigned analysis;
};

class Pixel_C {
private:
	pixel data;
public:
	Pixel_C();
	Pixel_C(uint8_t r, uint8_t g, uint8_t b);
	~Pixel_C();

	char interpret_color() const;
	void set_refrence(uint8_t &r, uint8_t &g, uint8_t &b);
	uint8_t get_r() const;
	uint8_t get_g() const;
	uint8_t get_b() const;

	void set_r(const uint8_t r);
	void set_g(const uint8_t g);
	void set_b(const uint8_t b);
	void set_color(const char c);
	void set_color(const uint8_t &r, const uint8_t &g, const uint8_t &b);




};


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
	pixel **Pixel_Matrix;
	void init_pixel_matrix();
	pixel Avrage_Sigment_Color(pixel **pix_sigment,int rows,int cols);

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
	 void operator=(Image const &b);
	 bool operator==(Image const &b);
	 void Compress();
	 void Text_To_Image(const char *file_name);
	 void Image_To_Text(const char *Image_name);
	 void Get_Center(unsigned &center_x,unsigned &center_y)const;

	 void Insert_Text_Into_Image(const char *file_name, const char *Image_Name);
	 void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color);
	 void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color,const char *mode);
	 void Draw_Square(const int center_x, const int center_y, const int s_width,
		 const int s_height, const unsigned char color, const char *mode,const unsigned space);
	 void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color);
	 void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color, const char *mode);

};


