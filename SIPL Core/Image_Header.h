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
typedef struct pixel {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	unsigned index_range;
	unsigned analysis;
}pixel;

struct coordinate {
	int x;
	int y;
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

#ifdef Extra_Slot
	pixel **Pixel_Matrix_2;
#endif // Extra_Slot


	void color_set(char color_choice, int &index);
	void color_set(pixel const &color, int &index);

	char decode_color(uint8_t r, uint8_t g, uint8_t b);
	void init_pixel_matrix();
	void init_pixel_matrix(const char *mode);
	pixel Avrage_Sigment_Color(pixel **pix_sigment, int rows, int cols);
	void Grayscale();
	int Color_Distance(pixel const &a, pixel const &b);
	float Color_DistanceSq(pixel const &a, pixel const &b);
	bool Distance_Neighbors(const float max_distance, int i, int j);
	float Get_Angle_Between_Coordinates(int const start_x, int const start_y, int const target_x, int const target_y,const char *mode);


public:
	pixel **Pixel_Matrix;
	Image();
	Image(unsigned char *image_data, int Height, int width, int channel);
	Image(int Height, int width, int channel);
	virtual ~Image();
	int getWidth() const;
	int getHeight()const;
	void Set_Pixel_By_Inedx(int index, uint8_t value);
	void Load_Blank_Canvas();
	void Load_Blank_Canvas(int width, int height, char set_color);
	void Load_Blank_Canvas(int width, int height, pixel const &background_color);

	void printImdata();
	void printImdata(char color);
	void Manual_Draw();
	void Load_Image();
	void Load_Image(const char *f_name);
	void Write_Image();
	void Write_Image(const char *f_name);
	void Color_Spec(int w, int h, char color);
	void Color_Spec(int index, char color);
	void Color_Spec(int index,pixel const &color);

	void operator+(Image const &a);
	void operator-(Image const &b);
	void operator/(Image const &b);
	void operator=(Image const &b);
	bool operator==(Image const &b);
	bool operator!=(Image const &b);

	void Compress();

	void Text_To_Image(const char *file_name);
	void Image_To_Text(const char *Image_name);
	void Get_Center(int &center_x, int &center_y)const;

	void Insert_Text_Into_Image(const char *file_name, const char *Image_Name);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color, const char *mode);
	void Draw_Square(const int center_x, const int center_y, const int s_width,
		const int s_height, const unsigned char color, const char *mode, const unsigned space);

	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color, const char *mode);
	void Draw_Square(const int center_x, const int center_y, const int s_width,
		const int s_height, pixel const &color, const char *mode, const unsigned space);

	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, pixel const &color);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color, const char *mode);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const pixel color, const char *mode);

	void Draw_Line(const int start_x, const int start_y, const int target_y, const unsigned char color);
	void Draw_Line(const int start_x, const int start_y, const int target_x, const int target_y, const unsigned char color);
	void Draw_Line(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color);




	void Convert_Grayscale();
	void Mark_Identical_Pixels(pixel const &Target);
	void Mark_Identical_Pixels(Image &Source);
	void Mark_Identical_Pixels(Image &Source, const char *mode);
	void Write_Pixel_Difference(Image &Source);
	void Write_Pixel_Difference(Image &Source, const char *mode, int min_diff);
	void Mark_Different_Pixels(Image &Source);
	void Mark_Different_Pixels(Image &Source, const char *mode);
	void Mark_Different_Pixels(Image &Source, const char *mode, int min_diff);
	void Write_ChannelGraph();
	void Write_Channel(const char color);
	void Shutdown_Channel(const char color);
	void Flip180();
	void Detect_Faces();
	void Tresholding(const char *mode, int value);
	void Edge_Detection();
	void Edge_Detection(const int max_color_gap);
	void Mark_Contour(const char color, const int max_color_gap);
	void Feature_Matching(const int source_x, const int source_y);
	void Pixel_Matrix_Multiplication(Image &b);
	void Quarantine_Pixel(pixel const &sample, const float max_difference, const char *mode, const int Alter);
	void Kronecker_product(Image &b, const char *mode, const int Alter);
	void Image_Transpose(const int Alter);
	void Draw_Text(const int center_y, const int center_x, const char *text);
	void Draw_Text(const int center_y, const int center_x, const char *text, const char color);
	void Draw_Text(const int center_y, const int center_x, const char *text, pixel const &color);

	void Draw_Graph(const int graph_height, const int graph_width, const int Space_Between_Lines);

};


