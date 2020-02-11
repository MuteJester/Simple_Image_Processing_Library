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
#include <list>


using namespace std;
#define ALTER 1
#define PI 3.14159265





typedef struct pixel {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	int index_range;
	int analysis;
}pixel;

struct coordinate {
	int x;
	int y;
};

struct Point {
	double x{ 0 }, y{ 0 }, z{ 0 };
	//x = r, y = g, z =b
};

using VectorFrame = vector<Point>;
using PixelFrame = vector<pixel>;
using PixelPath = vector<pixel>;

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

class Blob {
public:
	int Upleft_X, Upleft_Y;
	int Downright_X, Downright_Y;
	int Distnace_Treshold;

	Blob(int const &x, int const &y, int const &Distnace_Treshold);
	void Clear();
	void SetProps(int const &x, int const &y);
	void add(int const &px, int const &py);
	bool Near(int const &x, int const &y);
	float Size();

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
	void init_pixel_matrix(const char *mode);
	pixel Avrage_Sigment_Color(pixel **pix_sigment, int rows, int cols);
	void Grayscale(int const &alter);
	int Color_Distance(pixel const &a, pixel const &b);
	double Color_DistanceSq(pixel const &a, pixel const &b);
	float Color_Delta(pixel const &A, pixel const &B);
	bool Distance_Neighbors(const float max_distance, int i, int j);
	float Get_Angle_Between_Coordinates(int const start_x, int const start_y, int const target_x, int const target_y, const char *mode);
	void LineHigh(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color);
	void LineLow(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color);
	void BresenhamsLine(const int start_x, const int start_y, const int target_x, const int target_y, pixel const &color);
	void BresenhamsLine(const int start_x, const int start_y, const int target_x, const int target_y, const unsigned char color);
	void Blob_Framing(int const &distance_treshold, pixel const &frame_color);
	VectorFrame K_Means(const VectorFrame& data, size_t k, size_t number_of_iterations);

public:

	Image();
	Image(unsigned char *image_data, int Height, int width, int channel);
	Image(int Height, int width, int channel);
	virtual ~Image();



	pixel **Pixel_Matrix;
	void init_pixel_matrix();
	void Update_Pixel_Matrix();
	int getWidth() const;
	int getHeight()const;
	void getPixelCopy(int Height, int Width, pixel &save_pixel);
	void Set_Pixel_By_Inedx(int index, uint8_t value);
	void Load_Blank_Canvas();
	void Load_Blank_Canvas(int width, int height, char set_color);
	void Load_Blank_Canvas(int width, int height, pixel const &background_color);
	void Get_Center(int &center_x, int &center_y)const;

	void printImdata();
	void printImdata(char color);
	void Manual_Draw();
	void Load_Image();
	void Load_Image(const char *f_name);
	void Write_Image();
	void Write_Image(const char *f_name);
	void Color_Spec(int w, int h, char color);
	void Color_Spec(int index, char color);
	void Color_Spec(int index, pixel const &color);
	void Fill_In_Pixel_Frame(PixelFrame &frame);
	void Connect_VectorFrame_Via_Lines(VectorFrame &frame);


	void operator+(Image const &a);
	void operator-(Image const &b);
	void operator/(Image const &b);
	void operator=(Image const &b);
	bool operator==(Image const &b);
	bool operator!=(Image const &b);


	void Text_To_Image(const char *file_name);
	void Image_To_Text(const char *Image_name);
	void Insert_Text_Into_Image(const char *file_name, const char *Image_Name);

	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, const unsigned char color, const char *mode);
	void Draw_Square(const int center_x, const int center_y, const int s_width,
		const int s_height, const unsigned char color, const char *mode, const unsigned space);

	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color, const char *mode);
	void Draw_Square(const int center_x, const int center_y, const int s_width, const int s_height, pixel const &color, const char *mode, const unsigned space);

	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, pixel const &color);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const unsigned char color, const char *mode);
	void Draw_Circle(const int center_x, const int center_y, const int c_radius, const pixel color, const char *mode);

	void Draw_Line(const int start_x, const int start_y, const int target_y, const unsigned char color);
	void Draw_Line(const int start_x, const int start_y, const int target_x, const int target_y, const unsigned char color);
	void Draw_Line(const int start_y, const int start_x, const int target_y, const int target_x, pixel const &color);
	void Draw_Line(const int start_y, const int start_x, const int target_y, const int target_x, pixel const &color, int const &line_width);

	void Draw_Graph(const int graph_height, const int graph_width, const int Space_Between_Lines);


	void Convert_Grayscale();
	void Compress();
	void Mark_Identical_Pixels(pixel const &Target);
	void Mark_Identical_Pixels(Image &Source);
	void Mark_Identical_Pixels(Image &Source, const char *mode);
	void Write_Pixel_Difference(Image &Source);
	void Write_Pixel_Difference(Image &Source, const char *mode, int min_diff);
	void Mark_Different_Pixels(Image &Source);
	void Mark_Different_Pixels(Image &Source, const char *mode);
	void Mark_Different_Pixels(Image &Source, int const &Color_Treshold, int const &Distnace_Treshold, pixel const &frame_color);
	void Write_ChannelGraph();
	double Image_Difference_Value(Image &b);
	void Write_Channel(const char color);
	void Shutdown_Channel(const char color);
	void Flip180();
	void Detect_Faces();
	void Tresholding(const char *mode, int const &value, int const &alter);
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
	void Color_Flooring(const char *mode, int const &alter);
	void Figure_Detection(int const &blob_distance_treshold, int const &color_distance_treshold, int const &Thresholding_level);
	void Image_Segmentation(int const &k, int const &iterations, int const &alter);
	pixel Dominant_Color_Via_Line(const int start_y, const int start_x, const int target_y, const int target_x);
	PixelFrame Get_Line_Pixels(const int start_y, const int start_x, const int target_y, const int target_x);
	void Write_Average_Color_Palette(int const &palette_size);
	VectorFrame Get_Average_Color_Palette(int const &palette_size);
	void Register_PixelFrame(PixelFrame const &Frame);
	void Set_Colors_Using_Average_Palette(VectorFrame const &Average_Colors);
	void Convert_RGB_To_LAB(int const &alter);
	void Pixel_Griding();
	void Image_Rebuild_With_Lines(int const &Iterations);
	double Get_Neighbour_Mean_R(int const &i, int const &j);
	double Get_Neighbour_Mean_G(int const &i, int const &j);
	double Get_Neighbour_Mean_B(int const &i, int const &j);
	double Get_Neighbour_Mean_R(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal);
	double Get_Neighbour_Mean_G(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal);
	double Get_Neighbour_Mean_B(int const &i, int const &j, double Kernel[3][3], double Kernel_Normal);
	bool is_PathCross(PixelFrame A, PixelFrame B);
	void Image_Convolution(int const &iterations, int const &alter, const char *Type);

	void Image_Convolution(double Kernel[3][3], int const &iterations, int const &alter);

	void Save_As_PNG(const char *name);
};


using ImageFrame = vector<Image>;

bool operator^(PixelFrame A, PixelFrame B);
