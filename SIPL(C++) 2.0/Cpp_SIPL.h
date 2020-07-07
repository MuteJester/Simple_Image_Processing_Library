#pragma once
#ifndef Im
#define Im

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <assert.h>
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
#include <unordered_map>
#include <cctype>
#include <iomanip>
#include <future>
#include <mutex>
#include <numeric>
#include <type_traits>
#include <any>


enum Draw_Modes {
	HOLLOW					,
	FILLED			    	,
	ANTIALIAS_FILLED		,
	ANTIALIAS_HOLLOW		,
	DEFAULT					,
	ANTIALIAS_LINE			,
	CORNERS					,
	CHECKERED
};
enum Convolution_Kernels {
	 Median_Filter				,	
	 Mean_Blur					,	
	 Gaussian_Blur	 			,	
	 Low_Pass					,	
	 High_Pass					,	
	 High_Pass_Streached	 	,	
	 Unsharp_Mask				,	
	 Sobel_Kernel					
};
enum Histogram_Type {
	GREEN_HISTOGRAM		,
	BLUE_HISTOGRAM		,
	RED_HISTOGRAM		,
	RGB_HISTOGRAM

};

#define S_GRID 1236
#define S_JPG 1237
#define S_PNG 1238
#define S_CONNECTED 1338
#define degreesToRadians(angleDegrees) ((angleDegrees) * std::_Pi / 180.0)
#define radiansToDegrees(angleRadians) ((angleRadians) * 180.0 / std::_Pi)



template<class p_type>
class Point {
public:
	std::vector<p_type> p_members;
	Point() {};	
	Point(int const &amount_of_zeros) {
		for (int i = 0; i < amount_of_zeros; i++) {
			p_members.emplace_back(0);
		}
	};
	Point(std::initializer_list<p_type> args) {
		for (auto& i : args)
		{
			this->p_members.emplace_back(i);
		}
	}
	int size() const {
		return (int)this->p_members.size();
	}
	double get_Distance(Point<p_type> const &point_B) {
		assert(this->size() == point_B.size());
		double res = 0;
		for (int i = 0; i < this->size(); i++) {
			res += (point_B.p_members[i] -this->p_members[i])*(point_B.p_members[i] - this->p_members[i]);
		}
		return std::sqrt(res);
	}
	static double get_Squared_Distance(Point<p_type> const &point_A, Point<p_type> const &point_B) {
		double dist = point_A.get_Distance(point_B);
		return dist * dist;
	}
	Point<p_type> lerp(Point<p_type>  &B, double amount) {
		assert(this->size() == B.size());
		Point ret(this->size());
		for (int i = 0; i < this->size(); i++)
		{
			ret[i] = this->p_members[i] + (B[i] - this->p_members[i])*amount;
			
		}
		return ret;
	}
	void Divide_All(int &Divider) {
		for (auto& i : p_members)
		{
			i /= Divider;
		}
	}
	friend std::ostream &operator<<(std::ostream &out, Point const &pnt);

	p_type &operator[](int const &index) {
		assert(index < p_members.size());
		return this->p_members[index];
	}

};
void Quadratic_Equation(double const &a, double const &b, double const &c, double &result_root_a, double &result_root_b) {
	result_root_a = (-b + std::sqrt(((b*b) - 4 * a*c))) / 2 * a;
	result_root_b = ((-b - std::sqrt(((b*b) - 4 * a*c)))) / 2 * a;
}
template<class p_type> double Point_Dot_Product(Point<p_type> const &A, Point<p_type> const &B) {
	assert(A.size() == B.size());
	p_type res;
	for (int i = 0; i < A.size(); i++)
	{
		res += A[i] * B[i];
	}
	return res;
}
template<class p_type> std::ostream &operator<<(std::ostream &out, Point< p_type> &body) {
	out << "[ ";
	for (int i = 0; i < body.size(); i++)
	{
		if (i + 1 != body.size()) {
			out << body.p_members[i] << ", ";

		}
		else {
			out << body.p_members[i];

		}

	}

	out<< " ]";
	return out;
}
template<class p_type> std::ostream &operator<<(std::ostream &out, std::vector<Point< p_type> > const &body) {
	for (int i = 0; i < body.size(); i++) {
		out << body[i] << std::endl;
	}
	return out;
}
template<class p_type> bool operator<(Point<p_type> const &A, Point<p_type> const &B) {
	if (A[0] < B[0] || A[1] < B[1] || A[0] < B[0]) {
		return true;
	}
	else {
		return false;
	}
}
template<class p_type> Point<p_type> Get_Smallest_Point_In_Vector(std::vector<Point<p_type> > const & Points) {
	Point<p_type> cur_min = Points[0];
	for (int i = 1; i < Points.size(); i++) {
		if (Points[i] < cur_min) {
			cur_min = Points[i];
		}
	}
	return cur_min;
}
template<class p_type> Point<p_type> Get_Largest_Point_In_Vector(std::vector<Point<p_type> > const & Points) {
	Point<p_type> cur_max = Points[0];
	for (int i = 1; i < Points.size(); i++) {
		if (!(Points[i] < cur_max)) {
			cur_max = Points[i];
		}
	}
	return cur_max;
}

inline double Squared_Point_Distance(Point<double> first, Point<double> second) {
	return (first[0] - second[0])*(first[0] - second[0]) + (first[1] - second[1])*(first[1] - second[1]) + (first[2] - second[2])*(first[2] - second[2]);
}








#ifndef  SIPLCOMPLEXSYSTEMS
#define SIPLCOMPLEXSYSTEMS


class Complex {
public:
	double Real;
	double Imaginary;
	Complex() {
		this->Real = 0;
		this->Imaginary = 0;
	}
	Complex(double const &real, double const &imaginary) {
		this->Real = real;
		this->Imaginary = imaginary;
	}
	Complex(const Complex &Copy) {
		this->Real = Copy.Real;
		this->Imaginary = Copy.Imaginary;
	}
	static Complex I() {
		return Complex(0, 1);
	}
	static Complex Zero() {
		return Complex(0, 0);
	}

	void operator=(Complex const &source) {
		this->Real = source.Real;
		this->Imaginary = source.Imaginary;
	}
	void operator=(Complex &source) {
		this->Real = source.Real;
		this->Imaginary = source.Imaginary;
	}

	Complex operator+(Complex const &b) {
		return Complex(this->Real + b.Real, this->Imaginary + b.Imaginary);
	}
	Complex operator-(Complex const &b) {
		return Complex(this->Real - b.Real, this->Imaginary - b.Imaginary);

	}
	Complex operator*(Complex const &b) {
		return Complex(this->Real * b.Real - this->Imaginary * b.Imaginary,
			this->Real * b.Imaginary + this->Imaginary * b.Real);
	}
	Complex operator*(double const &b) {
		return Complex(this->Real * b, this->Imaginary*b);
	}
	Complex operator^(int const &B) {
		for (int i = 1; i < B; i++) {
			*this * *this;
		}
	}
	Complex operator^(Complex x) {
		return this->Log()*(x).Exp();

	}
	bool operator==(Complex const &b) {
		if (b.Imaginary == this->Imaginary && this->Real == b.Real) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(Complex const &b) {
		return *this == b ? false : true;
	}
	
	Complex Exp() {
		double expReal = std::exp(Real);
		return  Complex(expReal *  std::cos(Imaginary), expReal * std::sin(Imaginary));
	}
	Complex operator/(Complex const &divisor) {

		if ((divisor.Real == 0.0 && divisor.Imaginary == 0.0)) {
			std::abort();
		}


		if (std::abs(divisor.Real) < std::abs(divisor.Imaginary)) {
			double q = divisor.Real / divisor.Imaginary;
			double denominator = divisor.Real * q + divisor.Imaginary;
			return Complex((this->Real * q + this->Imaginary) / denominator, (this->Imaginary * q - this->Real) / denominator);
		}
		else {
			double q = divisor.Imaginary / divisor.Real;
			double denominator = divisor.Imaginary * q + divisor.Real;
			return Complex((this->Imaginary * q + this->Real) / denominator, (this->Imaginary - this->Real * q) / denominator);

		}
	}
	void Conjugate() {
		this->Imaginary *= -1;
	}
	double Abs() {
		if (std::abs(Real) < std::abs(Imaginary)) {
			if (Imaginary == 0.0) {
				return std::abs(Real);
			}
			double q = Real / Imaginary;
			return std::abs(Imaginary) * std::sqrt(1 + q * q);
		}
		else {
			if (Real == 0.0) {
				return std::abs(Imaginary);
			}
			double q = Imaginary / Real;
			return std::abs(Real) * std::sqrt(1 + q * q);
		}
	}
	Complex Log() {
		return Complex(std::log(Abs()),
			std::atan2(Imaginary, Real));
	}
	Complex Sqrt() {
		if (this->Real == 0.0 && Imaginary == 0.0) {
			return Complex(0.0, 0.0);
		}

		double t = std::sqrt((std::abs(Real) + this->Abs()) / 2.0);
		if (Real >= 0.0) {
			return Complex(t, Imaginary / (2.0 * t));
		}
		else {
			return Complex(std::abs(Imaginary) / (2.0 * t),
				std::copysign(1.0
					, Imaginary) * t);
		}
	}
	Complex &operator++(int) {
		this->Real++;
		return *this;
	}

};


std::vector<Complex> Discrete_Fourier_Transform(std::vector<int> &dat) {
	std::vector<Complex> Res;
	Res.reserve(dat.size());
	int d_size = dat.size();


	for (int k = 0; k < dat.size(); k++) {
		Complex sum(0, 0);
		for (int n = 0; n < dat.size(); n++) {
			Complex exp_power(0, ((-2 * std::_Pi)/ d_size) *(k*n));
			exp_power = exp_power.Exp();
			exp_power.Real *= dat[n];
			sum = sum + (exp_power);
		}
		Res.emplace_back(sum);
	}
	return Res;
}
std::vector<Complex> Discrete_Fourier_Transform(std::vector<Complex> &dat) {
	std::vector<Complex> Res;
	Res.reserve(dat.size());
	int d_size = dat.size();
	for (int k = 0; k < dat.size(); k++) {
		Complex sum(0, 0);
		//sum = std::accumulate(dat.begin(), dat.end(), Complex::Zero(), [](Complex &v) {return Complex(0, 0); });
		
		for (int n = 0; n < dat.size(); n++) {
			Complex exp_power(0, ((-2 * std::_Pi) / d_size) *(k*n));
			exp_power = exp_power.Exp();

			sum = sum + (dat[n] * exp_power);
		}
		Res.emplace_back(sum);
	}
	return Res;
}

std::vector<double> Reverse_Discrete_Fourier_Transform(std::vector<Complex> &dat) {
	std::vector<double> Res;
	Res.reserve(dat.size());
	int d_size = dat.size();
	for (int k = 0; k < dat.size(); k++) {
		Complex sum(0, 0);
		for (int n = 0; n < dat.size(); n++) {
			Complex exp_power(0, ((2 * std::_Pi)*(k*n))/ d_size);
			exp_power = exp_power.Exp();
			sum = sum + (dat[n] * exp_power);
		}
		sum = sum * (Complex(1, 0) / Complex(dat.size(), 0));
		Res.emplace_back(sum.Real);
	}
	return Res;
}
std::vector<Complex> Reverse_Discrete_Fourier_Transform_Complex(std::vector<Complex> &dat) {
	std::vector<Complex> Res;
	Res.reserve(dat.size());
	int d_size = dat.size();
	for (int k = 0; k < dat.size(); k++) {
		Complex sum(0, 0);
		for (int n = 0; n < dat.size(); n++) {
			Complex exp_power(0, ((2 * std::_Pi)*k*n)/d_size );
			exp_power = exp_power.Exp();
			sum = sum + (dat[n] * exp_power);
		}
		sum = sum * (Complex(1, 0) / Complex(dat.size(), 0));
		Res.push_back(sum);
	}
	return Res;
}



int bitReverse(int n, int bits) {
	int reversedN = n;
	int count = bits - 1;

	n >>= 1;
	while (n > 0) {
		reversedN = (reversedN << 1) | (n & 1);
		count--;
		n >>= 1;
	}

	return ((reversedN << count) & ((1 << bits) - 1));
}
void FFT(std::vector<Complex> &Values) {
	int length = Values.size();
	int bits = (int)(std::log(length) / std::log(2));
	for (int j = 1; j < length / 2; j++) {

		int swapPos = bitReverse(j, bits);
		Complex temp = Values[j];
		Values[j] = Values[swapPos];
		Values[swapPos] = temp;
	}

	for (int N = 2; N <= length; N <<= 1) {
		for (int i = 0; i < length; i += N) {
			for (int k = 0; k < N / 2; k++) {

				int evenIndex = i + k;
				int oddIndex = i + k + (N / 2);
				Complex even = Values[evenIndex];
				Complex odd = Values[oddIndex];

				double term = (-2 * std::_Pi * k) / (double)N;
				
				Complex exp = Complex(std::cos(term), std::sin(term))*(odd);

				Values[evenIndex] = even + (exp);
				Values[oddIndex] = even - (exp);
			}
		}
	}
}

Complex operator*(int const &num, Complex const &x) {
	Complex copy(num*x.Real, num*x.Imaginary);
	return copy;
}
Complex operator+(int const &num, Complex const &x) {
	return Complex(num+x.Real, x.Imaginary);
}
Complex operator"" i(unsigned long long const y) {
	return Complex(0, (double)y);
}


#endif // ! SIPLCOMPLEXSYSTEMS


std::ostream &operator<<(std::ostream &out, Complex const &source) {
	if (source.Imaginary > 0.0 && source.Real > 0.0) {
		out << source.Real << "+" << source.Imaginary << "i";
		return out;
	}
	else if (source.Imaginary == 0.0) {
		out << source.Real;
		return out;
	}
	else if (source.Imaginary > 0.0 && source.Real == 0.0) {
		out << source.Imaginary << "i";
		return out;
	}
	else if (source.Imaginary > 0.0 && source.Real < 0.0) {
		out << source.Real << "+" << source.Imaginary << "i";
		return out;
	}
	else {
		out << source.Real << source.Imaginary << "i";
		return out;
	}
}
std::istream &operator>>(std::istream &in, Complex &source) {
	in >> source.Real >> source.Imaginary;
	return in;
}
typedef std::vector<std::vector<Complex> > Complex_Matrix;



class LabPixel {
public:
	double L;
	double A;
	double B;
	int i, j;
	LabPixel(double l, double a, double b) {
		this->L = l;
		this->A = a;
		this->B = b;

	}

	LabPixel(double l, double a, double b, int i, int j) {
		this->L = l;
		this->A = a;
		this->B = b;
		this->i = i;
		this->j = j;
	}
	LabPixel() {
		this->L = 0;
		this->A = 0;
		this->B = 0;

	}
	LabPixel(LabPixel const &copy) {
		this->A = copy.A;
		this->B = copy.B;
		this->L = copy.L;
		this->i = copy.i;
		this->j = copy.j;
	}

	/*
	 * public void RGB_to_LAB(Pixel RGB) { Point XYZ = this->RGB_to_XYZ(RGB); double
	 * Xn = 95.0489; double Yn = 100; double Zn = 108.8840; this->L= 116 *
	 * (LavConvFunction((XYZ[1]/Yn))) - 16; this->A = 500 *
	 * (LavConvFunction((XYZ[0]/Xn)) - LavConvFunction((XYZ[1]/Yn))); this->B = 200 *
	 * (LavConvFunction((XYZ[1]/Yn)) - LavConvFunction((XYZ[2]/Zn)));
	 *
	 * }
	 */
	friend std::ostream &operator<<(std::ostream &out, LabPixel const &pix);
};

std::ostream &operator<<(std::ostream &out, LabPixel const &pix) {
	out << "( " << pix.L << ", " << pix.A << ", " << pix.B << ")\n";
	return out;
}

class Pixel {
public:
	int r;
	int g;
	int b;
	int A;
	int analysis;
	int i, j;
	Pixel(int r, int g, int b) {
		this->r = r;
		this->b = b;
		this->g = g;
		A = 255;
		analysis = 0;
	}
	Pixel(int r, int g, int b, int a) {
		this->r = r;
		this->b = b;
		this->g = g;
		A = a;
		analysis = 0;
	}

	Pixel(int r, int g, int b, int i, int j) {
		this->r = r;
		this->b = b;
		this->g = g;
		this->i = i;
		this->j = j;
		A = 255;
		analysis = 0;
	}
	Pixel() {
		this->r = 0;
		this->b = 0;
		this->g = 0;
		this->A = 255;
		analysis = 0;
	}
	Pixel(Pixel const &copy) {
		this->r = copy.r;
		this->g = copy.g;
		this->b = copy.b;
		this->A = copy.A;
		this->analysis = copy.analysis;
	}
	Pixel Pixel_Mul(Pixel b) {
		Pixel ret;
		ret.r = this->r*b.r;
		if (ret.r > 255) {
			ret.r = ret.r % 255;
		}
		ret.g = this->g*b.g;
		if (ret.g > 255) {
			ret.g = ret.g % 255;
		}
		ret.b = this->b*b.b;
		if (ret.b > 255) {
			ret.b = ret.b % 255;
		}
		return ret;
	}
	bool operator>(Pixel b) {
		if (this->r > b.r && this->g > b.g && this->b > b.b) {
			return true;
		}
		else {
			return false;
		}
	}
	Pixel operator+(int const &amount) {
		Pixel Res;
		Res.r = this->r + amount;
		Res.g = this->g + amount;
		Res.b = this->b + amount;
		Res.Clamp_Outliers();
		return Res;
	}
	Pixel operator+(Pixel const &amount) {
		Pixel Res;
		Res.r = this->r + amount.r;
		Res.g = this->g + amount.g;
		Res.b = this->b + amount.b;
		Res.Clamp_Outliers();
		return Res;
	}

	Pixel operator-(int const &amount) {
		Pixel Res;
		Res.r = this->r - amount;
		Res.g = this->g - amount;
		Res.b = this->b - amount;
		Res.Clamp_Outliers();
		return Res;
	}
	Pixel operator*(double const &amount) {
		Pixel Res;
		Res.r = (int)(this->r * amount);
		Res.g = (int)(this->g * amount);
		Res.b = (int)(this->b * amount);
		Res.Clamp_Outliers();
		return Res;
	}
	Pixel operator*(const Pixel &b) {
		Pixel ret;
		ret.r = this->r*b.r;
		if (ret.r > 255) {
			ret.r = ret.r % 255;
		}
		ret.g = this->g*b.g;
		if (ret.g > 255) {
			ret.g = ret.g % 255;
		}
		ret.b = this->b*b.b;
		if (ret.b > 255) {
			ret.b = ret.b % 255;
		}
		return ret;
	}
	void Add_Location(int i, int j) {
		this->i = i;
		this->j = j;
	}
	friend std::ostream &operator<<(std::ostream &out, Pixel const &pix);
	void Clamp_Outliers() {
		if (this->r > 255 || this->r < 0) {
			if (this->r > 255) {
				this->r = 255;
			}
			else {
				this->r = 0;
			}
		} if (this->g > 255 || this->g < 0) {
			if (this->g > 255) {
				this->g = 255;
			}
			else {
				this->g = 0;
			}
		}
		if (this->b > 255 || this->b < 0) {
			if (this->b > 255) {
				this->b = 255;
			}
			else {
				this->b = 0;
			}
		}
		if (A > 255 || A < 0) {
			if (this->A > 255) {
				this->A = 255;
			}
			else {
				this->A = 0;
			}
		}
	}

	bool operator==(Pixel const &Source) {
		if (this->r != Source.r || this->g != Source.g || this->b != Source.b) {
			return false;
		}
		else {
			return true;
		}
	}
	bool operator!=(Pixel const &source) {
		if (!(*this == source)) {
			return true;
		}
		else
		{
			return false;
		}
	}


};

std::ostream &operator<<(std::ostream &out, Pixel const &pix) {
	out << "( R:" << pix.r << ", G:" << pix.g << ", B:" << pix.b << " , A:" << pix.A << ")\n";
	return out;
}
Pixel TRI(Pixel const &color, Pixel const &bottom, double const &alpha) {
	int r = (int)std::round((color.r*alpha) + (bottom.r * (1 - alpha)));
	int g = (int)std::round((color.g*alpha) + (bottom.g * (1 - alpha)));
	int b = (int)std::round((color.b*alpha) + (bottom.b * (1 - alpha)));
	return Pixel(r, g, b);
}
LabPixel RGB_to_LAB(Pixel RGB) {

	double r, g, b, X, Y, Z, xr, yr, zr;

	// D65/2°
	double Xr = 95.047;
	double Yr = 100.0;
	double Zr = 108.883;


	// --------- RGB to XYZ ---------//

	r = RGB.r / 255.0;
	g = RGB.g / 255.0;
	b = RGB.b / 255.0;

	if (r > 0.04045)
		r = std::pow((r + 0.055) / 1.055, 2.4);
	else
		r = r / 12.92;

	if (g > 0.04045)
		g = std::pow((g + 0.055) / 1.055, 2.4);
	else
		g = g / 12.92;

	if (b > 0.04045)
		b = std::pow((b + 0.055) / 1.055, 2.4);
	else
		b = b / 12.92;

	r *= 100;
	g *= 100;
	b *= 100;

	X = 0.4124*r + 0.3576*g + 0.1805*b;
	Y = 0.2126*r + 0.7152*g + 0.0722*b;
	Z = 0.0193*r + 0.1192*g + 0.9505*b;


	// --------- XYZ to Lab --------- //

	xr = X / Xr;
	yr = Y / Yr;
	zr = Z / Zr;

	if (xr > 0.008856)
		xr = (float)std::pow(xr, 1 / 3.);
	else
		xr = (float)((7.787 * xr) + 16 / 116.0);

	if (yr > 0.008856)
		yr = (float)std::pow(yr, 1 / 3.);
	else
		yr = (float)((7.787 * yr) + 16 / 116.0);

	if (zr > 0.008856)
		zr = (float)std::pow(zr, 1 / 3.);
	else
		zr = (float)((7.787 * zr) + 16 / 116.0);


	std::vector<double> lab(3, 0.0);

	lab[0] = (116 * yr) - 16;
	lab[1] = 500 * (xr - yr);
	lab[2] = 200 * (yr - zr);

	LabPixel result(lab[0], lab[1], lab[2]);
	return result;
}
Point<double> LABtoXYZ(LabPixel &lab) {
	Point<double> xyz;

	float y = ((float)lab.L + (float)16.0) / (float)116.0;
	float x = (float)lab.A / (float)500.0 + y;
	float z = y - (float)lab.B / (float)200.0;

	//Y
	if (std::pow(y, 3) > 0.008856)
		y = (float)std::pow(y, 3);
	else
		y = (float)((y - 16 / 116) / 7.787);

	//X
	if (std::pow(x, 3) > 0.008856)
		x = (float)std::pow(x, 3);
	else
		x = (float)((x - 16 / 116) / 7.787);

	// Z
	if (std::pow(z, 3) > 0.008856)
		z = (float)std::pow(z, 3);
	else
		z = (float)((z - 16 / 116) / 7.787);

	xyz[0] = x * 95.0489;
	xyz[1] = y * 100;
	xyz[2] = z * 108.8840;

	return xyz;
}
Pixel XYZtoRGB(Point<double> XYZ) {
	float x = (float)XYZ[0], y = (float)XYZ[1], z = (float)XYZ[2];
	std::vector<int> rgb(3, 0);

	x /= 100;
	y /= 100;
	z /= 100;

	float r = 3.240479f * x - 1.53715f * y - 0.498535f * z;
	float g = -0.969256f * x + 1.875991f * y + 0.041556f * z;
	float b = 0.055648f * x - 0.204043f * y + 1.057311f * z;

	if (r > 0.0031308)
		r = 1.055f * ((float)std::pow(r, 0.4166f)) - 0.055f;
	else
		r = 12.92f * r;

	if (g > 0.0031308)
		g = 1.055f * ((float)std::pow(g, 0.4166f)) - 0.055f;
	else
		g = 12.92f * g;

	if (b > 0.0031308)
		b = 1.055f * ((float)std::pow(b, 0.4166f)) - 0.055f;
	else
		b = 12.92f * b;


	return Pixel((int)std::round(r * 255), (int)std::round(g * 255), (int)std::round(b * 255));

}

Pixel LAB_to_RGB(LabPixel lab) {
	Point<double> xyz = LABtoXYZ(lab);
	return XYZtoRGB(xyz);

}
typedef std::pair<std::pair<double, double>, Pixel > ScatterDot;



//matrix

#define IDENTITY_MATRIX 'i'
#define RANDOM_MATRIX 'r'


#ifndef RANDOMUTILITISDEFINE
#define RANDOMUTILITISDEFINE

class Random_Utilitis {
public:
	static int Random_INT(int minimum_value, int maximum_value) {
		static std::random_device seed;
		static std::mt19937 random_number_generator(seed());
		std::uniform_int_distribution<size_t> indices(minimum_value, maximum_value - 1);
		return (int)indices(random_number_generator);
	}

	static int Random_INT(int minimum_value, int maximum_value,int _seed) {
		static std::random_device seed;
		static std::mt19937 random_number_generator(_seed);
		std::uniform_int_distribution<size_t> indices(minimum_value, maximum_value - 1);
		return (int)indices(random_number_generator);
	}
	static double Random_DOUBLE(double minimum_value, double maximum_value) {
		static std::random_device seed;
		static std::mt19937 random_number_generator(seed());
		std::uniform_real_distribution<> indices(minimum_value, maximum_value);
		return indices(random_number_generator);
	}
	static double Random_DOUBLE(double minimum_value, double maximum_value, double _seed) {
		static std::random_device seed;
		static std::mt19937 random_number_generator(_seed);
		std::uniform_real_distribution<> indices(minimum_value, maximum_value);
		return indices(random_number_generator);
	}
};

#endif // !RANDOMUTILITISDEFINE



#ifndef MATRIX_STRUCTRE_THOTH

template<class MType> class Matrix {

public:
	Matrix(int Rows, int Cols) {
		Matrix_Body = std::vector<std::vector<MType> >(Rows, std::vector<MType>(Cols));
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] = 0;
			}
		}
		this->Rows = Rows;
		this->Cols = Cols;
	}
	Matrix(int Rows, int Cols,std::vector<MType> data) {
		Matrix_Body = std::vector<std::vector<MType> >(Rows, std::vector<MType>(Cols));
		int z = 0;
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] = data[z++];
			}
		}
		this->Rows = Rows;
		this->Cols = Cols;
	}

	Matrix(int N, char x = IDENTITY_MATRIX) {
		if (x == IDENTITY_MATRIX) {
			Matrix_Body = std::vector<std::vector<MType> >(N, std::vector<MType>(N));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Matrix_Body[i][j] = 0;
					if (i == j) {
						Matrix_Body[i][j] = 1;
					}
				}
			}
			this->Rows = N;
			this->Cols = N;
		}
		else if (x == RANDOM_MATRIX) {
			Matrix_Body = std::vector<std::vector<MType> >(N, std::vector<MType>(N));
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					Matrix_Body[i][j] = Random_Utilitis::Random_DOUBLE(0, 1);
				}
			}
			this->Rows = N;
			this->Cols = N;
		}
	}
	Matrix() {
		this->Rows = 0;
		this->Cols = 0;
	}
	template<class MCType> Matrix(Matrix<MCType> &copy) {
		this->Rows = copy.Rows;
		this->Cols = copy.Cols;
		for (int i = 0; i < this->Rows; i++) {
			this->Matrix_Body.push_back(std::vector<MType>(this->Cols));
			for (int j = 0; j < this->Cols; j++) {
				this->Matrix_Body[i][j] = copy[i][j];
			}
		}
	}
	int Rows, Cols;

	~Matrix() {};
	std::vector<MType> &operator[](int a) {
		return Matrix_Body[a];
	}
	void Random_Fill();
	void operator=(Matrix<MType> B) {
		this->Rows = B.Rows;
		this->Cols = B.Cols;
		this->Matrix_Body = std::vector<std::vector<MType> >(Rows, std::vector<MType>(Cols));
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] = B[i][j];
			}
		}

	}
	Matrix<MType> operator+(Matrix<MType> &B);
	Matrix<MType> operator-(Matrix<MType> &B);
	void operator/(int const &divide_by);
	Matrix<MType> Dot_Product(Matrix<MType> &B);
	Matrix<MType> Matrix_Transpose();
	void Multiply_By_Scalar(double const &scalar);
	Matrix<MType> Hadamard_Product(Matrix<MType> &Mul_By);
	Matrix<MType> Kronecker_Product(Matrix<MType> &Mul_By);
	void Horizontal_Matrix_Concatenation(Matrix<MType> &To_HConcat);
	void Convolve(Matrix<int> &Mask, int mask_h, int mask_w);
	std::vector<MType> Diagonal();
	Matrix<MType> Get_Upper_Matrix();
	Matrix<MType> Get_Lower_Matrix();
	double Get_Determinant();
	std::vector<double>  Gaussian_Elimination(std::vector<double> equals_to);
	template<class MType> friend std::ostream &operator<<(std::ostream &out, Matrix<MType> const &mat);
	Matrix<MType> Reshape(int Rows, int Cols);
	std::vector<MType> Flatten();
	void Remove_Row(int const &row_index);
	void Remove_Column(int const &column_index);
	void Apply_Function_To_Values(MType(*function)(MType));
	void Add_To_All(MType const &value);

	std::vector<std::vector<MType> > Matrix_Body;
};



template<class MType> std::ostream &operator<<(std::ostream &out, Matrix<MType> const &mat) {
	std::ios_base::sync_with_stdio(false);
	out << std::left;
	for (int i = 0; i < mat.Rows; i++) {
		for (int j = 0; j < mat.Cols; j++) {
			if (j < mat.Cols - 1) {
				out << std::setw(9) << mat.Matrix_Body[i][j] << "|";

			}
			else {
				out << std::setw(9) << mat.Matrix_Body[i][j];

			}
		}
		out << "\n";
	}
	return out;
}
template<class MType> Matrix<MType> Matrix<MType>::Matrix_Transpose() {


	Matrix<MType> temp(Cols, Rows);



	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			temp[i][j] = Matrix_Body[j][i];
		}
	}
	return  temp;
}
template<class MType> void Matrix<MType>::Multiply_By_Scalar(double const &scalar) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Matrix_Body[i][j] *= scalar;
		}
	}
}
template<class MType> Matrix<MType> Matrix<MType>::operator+(Matrix<MType> &B) {
	if (Rows != B.getRows() || Cols != B.getCols()) {
		return;
	}
	else {
		Matrix<MType> Res(this->Rows, this->Cols);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Res[i][j] = Matrix_Body[i][j] + B[i][j];
			}
		}
	}
}
template<class MType> Matrix<MType> Matrix<MType>::operator-(Matrix<MType> &B) {
	if (Rows != B.Rows || Cols != B.Cols) {
		return Matrix<double>();
	}
	else {
		Matrix<MType> Res(this->Rows, this->Cols);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Res[i][j] = Matrix_Body[i][j] - B[i][j];
			}
		}
		return Res;
	}
}
template<class MType> Matrix<MType> Matrix<MType>::Dot_Product(Matrix<MType> &B) {

	if (Cols != B.Rows) {
		std::cout << "Rows Of Matrix A Are != Cols Of Matrix B";
		return Matrix<MType>();

	}
	else {
		MType sum = 0;
		Matrix<MType> temp(Rows, B.Cols);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < B.Cols; j++) {
				for (int k = 0; k < Cols; k++) {
					sum += Matrix_Body[i][k] * B[k][j];

				}
				temp[i][j] = sum;
				sum = 0;
			}
		}
		return temp;
	}

}
template<class MType> Matrix<MType> Matrix<MType>::Hadamard_Product(Matrix<MType> &Mul_By) {

	if (Cols != Mul_By.getRows() || Rows != Mul_By.getRows()) {
		return;

	}
	else {
		Matrix<MType> Result(Rows, Cols);
		MType sum = 0;

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Mul_By.getCols(); j++) {
				Result[i][j] = Matrix_Body[i][j] * Mul_By.mat[i][j];
			}
		}
		return Result;

	}
}
template<class MType> Matrix<MType> Matrix<MType>::Kronecker_Product(Matrix<MType> &Mul_By) {
	Matrix<MType> Kronecker(Rows*Mul_By.getRows(), Cols*Mul_By.getCols());
	int startRow, startCol;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			startRow = i * Mul_By.getRows();
			startCol = j * Mul_By.getCols();
			for (int k = 0; k < Mul_By.getRows(); k++) {
				for (int l = 0; l < Mul_By.getCols(); l++) {
					Kronecker[startRow + k][startCol + l] = Matrix_Body[i][j] * Mul_By[k][l];
				}
			}
		}
	}
	return Kronecker;

}
template<class MType> void Matrix<MType>::Horizontal_Matrix_Concatenation(Matrix<MType> &To_HConcat) {
	if (this->Rows != To_HConcat.getRows())
		return;

	int  i, j, k, l = 0;
	Matrix<MType> ConcatH(Rows, Cols + To_HConcat.getCols());

	for (i = 0; i < Rows; i++) {
		for (j = 0; j < Cols; j++) {
			ConcatH[i][l] = Matrix_Body[i][j];
			l++;
		}
		for (k = 0; k < To_HConcat.getCols(); k++) {
			ConcatH[i][l] = To_HConcat[i][k];
			l++;
		}
		l = 0;
	}
	*this = ConcatH;
}
template<class MType> std::vector<MType> Matrix<MType>::Diagonal() {
	if (this->Cols != this->Rows) {
		std::cout << "Error Matrix Isnt Square (R != C)\n";
		return std::vector<MType>();
	}
	else {
		std::vector<MType> res(this->Cols);
		for (int i = 0; i < this->Cols; i++) {
			res[i] = this->Matrix_Body[i][i];
		}
		return res;
	}

}
template<class MType> void Matrix<MType>::Convolve(Matrix<int> &Mask, int mask_h, int mask_w) {

	Matrix<MType> sample(mask_h, mask_w);
	int accumulator = 0;
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {
			for (int k = -(mask_h / 2); k < (mask_h / 2); k++) {
				for (int m = -(mask_w / 2); m < (mask_w / 2); m++) {

					if (i + k < 0 && j + m < 0) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[this->Rows + k][this->Cols + m];

					}
					else if (i + k < 0 && j + m > 0) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[this->Rows + k][j + m];

					}
					else if (j + m < 0 && i + k > 0) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[i + k][this->Cols + m];

					}//till here before
					else if (i + k >= Rows && j + m >= Cols) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[(i + k) - Rows][(j + m) - Cols];
					}
					else if (i + k >= Rows && j + m < Cols) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[(i + k) - Rows][j + m];

					}
					else if (i + k < Rows && j + m >= Cols) {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[i + k][(j + m) - Cols];

					}
					else {
						sample[k + (mask_h / 2)][m + (mask_h / 2)] = Matrix_Body[i + k][j + m];

					}

				}
			}
			Mask.Matrix_Transpose();
			for (int k = 0; k < mask_h; k++) {
				for (int m = 0; m < mask_w; m++) {
					accumulator = +sample[k][m] * Mask[k][m];
				}
			}

			Matrix_Body[i][j] = accumulator;
			accumulator = 0;

		}
	}

}
template<class MType> void Matrix<MType>::operator/(int const &divide_by) {
	this->Multiply_By_Scalar((1.0 / divide_by));
}
template<class MType> Matrix<MType> Matrix<MType>::Get_Upper_Matrix() {
	if (this->Rows != this->Cols) {
		std::cout << "Matrix Needs To Be NxN\n";
		return Matrix<MType>(1, 1);
	}
	Matrix<MType> Upper(*this);
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < i; j++) {
			Upper[i][j] = 0;
		}
	}
	return Upper;
}
template<class MType> Matrix<MType>  Matrix<MType>::Get_Lower_Matrix() {
	if (this->Rows != this->Cols) {
		std::cout << "Matrix Needs To Be NxN\n";
		return Matrix<MType>(1, 1);
	}
	Matrix Lower(*this);
	for (int i = 0; i < this->Rows; i++) {
		for (int j = i + 1; j < Cols; j++) {
			Lower.Matrix_Body[i][j] = 0;
		}
	}
	return Lower;
}
template<class MType> void Matrix<MType>::Random_Fill() {
	Random_Utilitis rand;
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {
			this->Matrix_Body[i][j] = rand.Random_DOUBLE(0, 50);
		}
	}
}
template<class MType>  double Matrix<MType>::Get_Determinant() {
	if (this->Cols != this->Rows) {
		std::cout << "Matrix Needs To Be NxN\n";
		return 0;
	}
	std::vector<Matrix<double> > LU = this->LU_Decomposition();
	double det = LU[1][0][0];
	for (int i = 1; i < this->Cols; i++) {
		det *= LU[1][i][i];
	}
	int v = (LU[2][0][this->Cols - 1] - this->Cols - 1);
	if ((v % 2) == 0) {
		return det;
	}
	else {
		return -det;
	}
}

template<class MType> std::vector<double>  Matrix<MType>::Gaussian_Elimination(std::vector<double> equals_to) {
	int n = this->Matrix_Body[0].size();
	for (int p = 0; p < n; p++) {
		int max = p;
		for (int i = p + 1; i < n; i++) {
			if (Mabs(this->Matrix_Body[i][p]) > Mabs(this->Matrix_Body[max][p])) {
				max = i;
			}
		}
		std::vector<double> temp(this->Matrix_Body[p]);
		this->Matrix_Body[p] = this->Matrix_Body[max];
		this->Matrix_Body[max] = temp;
		double t = equals_to[p];
		equals_to[p] = equals_to[max];
		equals_to[max] = t;
		if (Mabs(this->Matrix_Body[p][p]) <= std::numeric_limits<double>::min()) {
			std::cout << "\nMatrix is singular or nearly singular\n";
			return std::vector<double>();

		}
		for (int i = p + 1; i < n; i++) {
			double alpha = this->Matrix_Body[i][p] / this->Matrix_Body[p][p];
			equals_to[i] -= alpha * equals_to[p];
			for (int j = p; j < n; j++) {
				this->Matrix_Body[i][j] -= alpha * this->Matrix_Body[p][j];
			}
		}
	}
	std::vector<double> x(n);
	for (int i = n - 1; i >= 0; i--) {
		double sum = 0.0;
		for (int j = i + 1; j < n; j++) {
			sum += this->Matrix_Body[i][j] * x[j];
		}
		x[i] = (equals_to[i] - sum) / this->Matrix_Body[i][i];
	}

	return x;
}
template<class MType> Matrix<MType> Matrix<MType>::Reshape(int Rows, int Cols) {


	Matrix<MType> res(Rows, Cols);
	if (this->Rows*this->Cols == 0 || Rows * Cols != this->Rows * this->Cols) {
		std::cout << "Error Cannot Reshape Into " << Rows << "X" << Cols << "\n";
		throw(std::exception("Invalid_Shape"));
	}
	std::vector<MType>  F = this->Flatten();

	int z = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			res[i][j] = F[z++];
		}
	}
	return res;

}
template<class MType> std::vector<MType> Matrix<MType>::Flatten() {
	std::vector<MType> Result;
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {

			Result.push_back(this->Matrix_Body[i][j]);
		}
	}
	return Result;
}
template<class MType> void Matrix<MType>::Apply_Function_To_Values(MType(*function)(MType)) {
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {
			this->Matrix_Body[i][j] = function(this->Matrix_Body[i][j]);
		}
	}
}
template<class MType> void Matrix<MType>::Add_To_All(MType const &value) {
	for (int i = 0; i < this->Rows; i++) {
		for (int j = 0; j < this->Cols; j++) {
			this->Matrix_Body[i][j] += value;
		}
	}
}


template<class MType> void Matrix<MType>::Remove_Row(int const &row_index) {
	this->Matrix_Body.erase(this->Matrix_Body.begin() + row_index);
	this->Rows--;
}
template<class MType> void Matrix<MType>::Remove_Column(int const &column_index) {
	for (int i = 0; i < Rows; i++) {
		this->Matrix_Body[i].erase(Matrix_Body[i].begin() + column_index);
	}
	this->Cols--;
}

template<class MType> std::vector<Matrix<double> > LU_Decomposition(Matrix<MType>  &source) {
	if (source.Cols != source.Rows) {
		std::cout << " Error  - Matrix Needs To Be NxN\n";
		return  std::vector<Matrix<MType> >();
	}

	Matrix< double> LU(source.Rows, source.Cols);
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			LU[i][j] = source[i][j];
		}
	}

	double *pivot = new double[source.Cols];
	for (int i = 0; i < source.Cols; i++) {
		pivot[i] = i;
	}
	int pivsign = 1;

	std::vector<MType> LUrowi;
	std::vector<double> LUcolj(source.Cols);

	// Outer loop.

	for (int j = 0; j < source.Cols; j++) {
		for (int i = 0; i < source.Cols; i++) {
			LUcolj[i] = LU.Matrix_Body[i][j];
		}

		for (int i = 0; i < source.Cols; i++) {
			LUrowi = LU.Matrix_Body[i];
			int kmax = Mmin(i, j);
			double s = 0.0;
			for (int k = 0; k < kmax; k++) {
				s += LUrowi[k] * LUcolj[k];
			}

			LUrowi[j] = LUcolj[i] -= s;
		}

		int p = j;
		for (int i = j + 1; i < source.Cols; i++) {

			if (Mabs(LUcolj[i]) > Mabs(LUcolj[p])) {
				p = i;
			}
		}
		if (p != j) {
			for (int k = 0; k < source.Cols; k++) {
				double t = LU.Matrix_Body[p][k];
				LU.Matrix_Body[p][k] = LU.Matrix_Body[j][k];
				LU.Matrix_Body[j][k] = t;
			}
			double k = pivot[p];
			pivot[p] = pivot[j];
			pivot[j] = k;
			pivsign = -pivsign;
		}
		if ((j < source.Cols) & (LU[j][j] != 0.0)) {
			for (int i = j + 1; i < source.Cols; i++) {
				LU[i][j] /= LU[j][j];
			}
		}
	}


	//Matrix[] LUP = new Matrix[3];
	std::vector< Matrix<double> > LUP(3);
	Matrix<MType> Lower = LU.Get_Lower_Matrix();
	for (int i = 0; i < source.Cols; i++) {
		Lower[i][i] = 1;
	}
	Matrix<MType> pivot_mat(1, source.Cols);
	for (int i = 0; i < source.Cols; i++) {
		pivot_mat[0][i] = pivot[i];
	}
	LUP[0] = Lower;
	LUP[1] = LU.Get_Upper_Matrix();
	LUP[2] = pivot_mat;
	delete[] pivot;
	return LUP;
}
template<class MType> std::vector<Matrix<double> > QR_Decomposition(Matrix<MType>  &source) {
	Matrix<double> QR(source.Rows, source.Cols);
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			QR[i][j] = source[i][j];
		}
	}
	std::vector<double> R_diagonal(source.Rows);

	for (int k = 0; k < source.Rows; k++) {
		double nrm = 0;
		for (int i = k; i < source.Cols; i++) {
			nrm = std::sqrt(std::pow(nrm, 2) + std::pow(QR[i][k], 2));
		}

		if (nrm != 0.0) {
			if (QR[k][k] < 0) {
				nrm = -nrm;
			}
			for (int i = k; i < source.Cols; i++) {
				QR[i][k] /= nrm;
			}
			QR[k][k] += 1.0;

			for (int j = k + 1; j < source.Cols; j++) {
				double s = 0.0;
				for (int i = k; i < source.Cols; i++) {
					s += QR[i][k] * QR[i][j];
				}
				s = -s / QR.Matrix_Body[k][k];
				for (int i = k; i < source.Cols; i++) {
					QR[i][j] += s * QR[i][k];
				}
			}
		}
		R_diagonal[k] = -nrm;
	}

	int m = source.Rows;
	int n = source.Cols;
	Matrix<double> XQ(m, n);
	Matrix<double> Q(m, n);
	for (int k = n - 1; k >= 0; k--) {
		for (int i = 0; i < m; i++) {
			Q[i][k] = 0.0;
		}
		Q[k][k] = 1.0;
		for (int j = k; j < n; j++) {
			if (QR[k][k] != 0) {
				double s = 0.0;
				for (int i = k; i < m; i++) {
					s += QR[i][k] * Q[i][j];
				}
				s = -s / QR[k][k];
				for (int i = k; i < m; i++) {
					Q[i][j] += s * QR[i][k];
				}
			}
		}
	}
	XQ = Q;
	Matrix<double> XR(n, n);
	Matrix<double> R(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i < j) {
				R[i][j] = QR[i][j];
			}
			else if (i == j) {
				R[i][j] = R_diagonal[i];
			}
			else {
				R[i][j] = 0.0;
			}
		}
	}
	XR = R;

	Matrix<double> Xh(m, n);
	Matrix<double> H(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= j) {
				H[i][j] = QR[i][j];
			}
			else {
				H[i][j] = 0.0;
			}
		}
	}
	Xh = H;
	std::vector<Matrix<double> > Result(3);

	Result[0] = XQ;
	Result[1] = XR;
	Result[2] = Xh;
	return Result;
}

template<class MType>  std::vector<double> Get_Eigen_Values(Matrix<MType>  &source) {
	Matrix< double> A(source.Rows, source.Cols);
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			A[i][j] = source[i][j];
		}
	}
	std::vector<Matrix<double> > QR = QR_Decomposition(A);
	for (int i = 0; i < 20; i++) {
		A = QR[1].Dot_Product(QR[0]);
		QR = QR_Decomposition(A);
	}

	std::vector<double> EigenValues = A.Diagonal();
	return EigenValues;
}
template<class MType> Matrix<double> Get_Eigen_Vectors(Matrix<MType> const &source) {
	Matrix< double> A(source.Rows, source.Cols);
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			A[i][j] = source.Matrix_Body[i][j];
		}
	}
	std::vector<Matrix<double> > QR = QR_Decomposition(A);
	Matrix<double> Q(QR[0]);
	for (int i = 0; i < 30; i++) {
		A = QR[1].Dot_Product(QR[0]);
		QR = QR_Decomposition(A);
		Q = Q.Dot_Product(QR[0]);


	}
	return Q;
}

#endif MATRIX_STRUCTRE_THOTH




//



class Color_Palette {
public:
	//void Set_Color(pixel &target);
	Color_Palette() {
		this->Black.r = 0;
		this->Black.g = 0;
		this->Black.b = 0;

		this->White.r = 255;
		this->White.g = 255;
		this->White.b = 255;

		this->Red.r = 255;
		this->Red.g = 0;
		this->Red.b = 0;

		this->Lime.r = 0;
		this->Lime.g = 255;
		this->Lime.b = 0;

		this->Blue.r = 0;
		this->Blue.g = 0;
		this->Blue.b = 255;

		this->Yellow.r = 255;
		this->Yellow.g = 255;
		this->Yellow.b = 0;

		this->Cyan.r = 0;
		this->Cyan.g = 255;
		this->Cyan.b = 255;

		this->Magenta.r = 255;
		this->Magenta.g = 0;
		this->Magenta.b = 255;

		this->Silver.r = 192;
		this->Silver.g = 192;
		this->Silver.b = 192;

		this->Gray.r = 128;
		this->Gray.g = 128;
		this->Gray.b = 128;

		this->Maroon.r = 128;
		this->Maroon.g = 0;
		this->Maroon.b = 0;

		this->Green.r = 0;
		this->Green.g = 128;
		this->Green.b = 0;

		this->Purple.r = 128;
		this->Purple.g = 0;
		this->Purple.b = 128;

		this->Teal.r = 0;
		this->Teal.g = 128;
		this->Teal.b = 128;

		this->Navy.r = 0;
		this->Navy.g = 0;
		this->Navy.b = 128;

		this->Dark_Red.r = 139;
		this->Dark_Red.g = 0;
		this->Dark_Red.b = 0;

		this->Brown.r = 165;
		this->Brown.g = 42;
		this->Brown.b = 42;

		this->Firebrick.r = 178;
		this->Firebrick.g = 34;
		this->Firebrick.b = 34;

		this->Crimson.r = 220;
		this->Crimson.g = 20;
		this->Crimson.b = 60;

		this->Tomato.r = 255;
		this->Tomato.g = 99;
		this->Tomato.b = 71;

		this->Coral.r = 255;
		this->Coral.g = 127;
		this->Coral.b = 80;

		this->Indian_Red.r = 205;
		this->Indian_Red.g = 92;
		this->Indian_Red.b = 92;

		this->Light_Coral.r = 240;
		this->Light_Coral.g = 128;
		this->Light_Coral.b = 128;

		this->Dark_Salmon.r = 233;
		this->Dark_Salmon.g = 150;
		this->Dark_Salmon.b = 122;

		this->Salmon.r = 250;
		this->Salmon.g = 128;
		this->Salmon.b = 114;

		this->Light_Salmon.r = 255;
		this->Light_Salmon.g = 160;
		this->Light_Salmon.b = 122;

		this->Orange_Red.r = 255;
		this->Orange_Red.g = 69;
		this->Orange_Red.b = 0;

		this->Dark_Orange.r = 255;
		this->Dark_Orange.g = 140;
		this->Dark_Orange.b = 0;

		this->Orange.r = 255;
		this->Orange.g = 165;
		this->Orange.b = 0;

		this->Gold.r = 255;
		this->Gold.g = 215;
		this->Gold.b = 0;

		this->Dark_Golden_Rod.r = 184;
		this->Dark_Golden_Rod.g = 134;
		this->Dark_Golden_Rod.b = 11;

		this->Golden_Rod.r = 218;
		this->Golden_Rod.g = 165;
		this->Golden_Rod.b = 32;

		this->Pale_Golden_Rod.r = 238;
		this->Pale_Golden_Rod.g = 232;
		this->Pale_Golden_Rod.b = 170;

		this->Dark_Khaki.r = 189;
		this->Dark_Khaki.g = 183;
		this->Dark_Khaki.b = 107;

		this->Khaki.r = 240;
		this->Khaki.g = 230;
		this->Khaki.b = 140;

		this->Olive.r = 128;
		this->Olive.g = 128;
		this->Olive.b = 0;

		this->Yellow_Green.r = 154;
		this->Yellow_Green.g = 205;
		this->Yellow_Green.b = 50;

		this->Dark_Olive_Green.r = 85;
		this->Dark_Olive_Green.g = 107;
		this->Dark_Olive_Green.b = 47;

		this->Olive_Drab.r = 107;
		this->Olive_Drab.g = 142;
		this->Olive_Drab.b = 35;

		this->Lawn_Green.r = 142;
		this->Lawn_Green.g = 252;
		this->Lawn_Green.b = 0;

		this->Chart_Reuse.r = 127;
		this->Chart_Reuse.g = 255;
		this->Chart_Reuse.b = 0;

		this->Green_Yellow.r = 173;
		this->Green_Yellow.g = 255;
		this->Green_Yellow.b = 47;

		this->Dark_Green.r = 0;
		this->Dark_Green.g = 100;
		this->Dark_Green.b = 0;

		this->Forest_Green.r = 34;
		this->Forest_Green.g = 139;
		this->Forest_Green.b = 34;

		this->Lime_Green.r = 50;
		this->Lime_Green.g = 205;
		this->Lime_Green.b = 50;

		this->Light_Green.r = 144;
		this->Light_Green.g = 238;
		this->Light_Green.b = 144;

		this->Pale_Green.r = 152;
		this->Pale_Green.g = 251;
		this->Pale_Green.b = 152;

		this->Dark_Sea_Green.r = 143;
		this->Dark_Sea_Green.g = 188;
		this->Dark_Sea_Green.b = 143;

		this->Medium_Spring_Green.r = 0;
		this->Medium_Spring_Green.g = 250;
		this->Medium_Spring_Green.b = 154;

		this->Spring_Green.r = 0;
		this->Spring_Green.g = 255;
		this->Spring_Green.b = 127;

		this->Sea_Green.r = 46;
		this->Sea_Green.g = 139;
		this->Sea_Green.b = 87;

		this->Medium_Aqua_Marine.r = 102;
		this->Medium_Aqua_Marine.g = 205;
		this->Medium_Aqua_Marine.b = 170;

		this->Medium_Sea_Green.r = 60;
		this->Medium_Sea_Green.g = 179;
		this->Medium_Sea_Green.b = 113;

		this->Light_Sea_Green.r = 32;
		this->Light_Sea_Green.g = 178;
		this->Light_Sea_Green.b = 170;

		this->Dark_Slate_Gray.r = 47;
		this->Dark_Slate_Gray.g = 79;
		this->Dark_Slate_Gray.b = 79;

		this->Dark_Cyan.r = 0;
		this->Dark_Cyan.g = 139;
		this->Dark_Cyan.b = 139;

		this->Light_Cyan.r = 224;
		this->Light_Cyan.g = 255;
		this->Light_Cyan.b = 255;

		this->Dark_Turquoise.r = 0;
		this->Dark_Turquoise.g = 206;
		this->Dark_Turquoise.b = 209;

		this->Turquoise.r = 64;
		this->Turquoise.g = 224;
		this->Turquoise.b = 208;

		this->Medium_Turquoise.r = 72;
		this->Medium_Turquoise.g = 209;
		this->Medium_Turquoise.b = 204;

		this->Pale_Turquois.r = 175;
		this->Pale_Turquois.g = 238;
		this->Pale_Turquois.b = 238;

		this->Aqua_Marine.r = 127;
		this->Aqua_Marine.g = 255;
		this->Aqua_Marine.b = 212;

		this->Powder_Blue.r = 176;
		this->Powder_Blue.g = 224;
		this->Powder_Blue.b = 230;

		this->Cadet_Blue.r = 95;
		this->Cadet_Blue.g = 158;
		this->Cadet_Blue.b = 160;

		this->Steel_Blue.r = 70;
		this->Steel_Blue.g = 130;
		this->Steel_Blue.b = 180;

		this->Corn_Flower_Blue.r = 100;
		this->Corn_Flower_Blue.g = 149;
		this->Corn_Flower_Blue.b = 237;

		this->Deep_Sky_Blue.r = 0;
		this->Deep_Sky_Blue.g = 191;
		this->Deep_Sky_Blue.b = 255;

		this->Dodger_Blue.r = 30;
		this->Dodger_Blue.g = 144;
		this->Dodger_Blue.b = 255;

		this->Light_Blue.r = 173;
		this->Light_Blue.g = 216;
		this->Light_Blue.b = 230;

		this->Sky_Blue.r = 135;
		this->Sky_Blue.g = 206;
		this->Sky_Blue.b = 235;

		this->Light_Bky_Blue.r = 135;
		this->Light_Bky_Blue.g = 206;
		this->Light_Bky_Blue.b = 250;

		this->Midnight_Blue.r = 25;
		this->Midnight_Blue.g = 25;
		this->Midnight_Blue.b = 112;

		this->Dark_Blue.r = 0;
		this->Dark_Blue.g = 0;
		this->Dark_Blue.b = 139;

		this->Medium_Blue.r = 0;
		this->Medium_Blue.g = 0;
		this->Medium_Blue.b = 205;

		this->Royal_Blue.r = 65;
		this->Royal_Blue.g = 105;
		this->Royal_Blue.b = 225;

		this->Blue_Violet.r = 138;
		this->Blue_Violet.g = 43;
		this->Blue_Violet.b = 226;

		this->Indigo.r = 75;
		this->Indigo.g = 0;
		this->Indigo.b = 130;

		this->Dark_Slate_Blue.r = 72;
		this->Dark_Slate_Blue.g = 61;
		this->Dark_Slate_Blue.b = 139;

		this->Slate_Blue.r = 106;
		this->Slate_Blue.g = 90;
		this->Slate_Blue.b = 205;

		this->Medium_Slate_Blue.r = 123;
		this->Medium_Slate_Blue.g = 104;
		this->Medium_Slate_Blue.b = 238;

		this->Medium_Purple.r = 147;
		this->Medium_Purple.g = 112;
		this->Medium_Purple.b = 219;

		this->Dark_Magenta.r = 139;
		this->Dark_Magenta.g = 0;
		this->Dark_Magenta.b = 139;

		this->Dark_Violet.r = 148;
		this->Dark_Violet.g = 0;
		this->Dark_Violet.b = 211;

		this->Dark_Orchid.r = 153;
		this->Dark_Orchid.g = 50;
		this->Dark_Orchid.b = 204;

		this->Medium_Orchid.r = 186;
		this->Medium_Orchid.g = 85;
		this->Medium_Orchid.b = 211;

		this->Thistle.r = 216;
		this->Thistle.g = 191;
		this->Thistle.b = 216;

		this->Plum.r = 221;
		this->Plum.g = 160;
		this->Plum.b = 221;

		this->Violet.r = 238;
		this->Violet.g = 130;
		this->Violet.b = 238;

		this->Orchid.r = 218;
		this->Orchid.g = 112;
		this->Orchid.b = 214;

		this->Medium_Violet_Red.r = 199;
		this->Medium_Violet_Red.g = 21;
		this->Medium_Violet_Red.b = 133;

		this->Pale_Violet_Red.r = 219;
		this->Pale_Violet_Red.g = 112;
		this->Pale_Violet_Red.b = 147;

		this->Deep_Pink.r = 255;
		this->Deep_Pink.g = 20;
		this->Deep_Pink.b = 147;

		this->Hot_Pink.r = 255;
		this->Hot_Pink.g = 105;
		this->Hot_Pink.b = 180;

		this->Light_Pink.r = 255;
		this->Light_Pink.g = 182;
		this->Light_Pink.b = 193;

		this->Pink.r = 255;
		this->Pink.g = 192;
		this->Pink.b = 203;

		this->Antique_White.r = 250;
		this->Antique_White.g = 235;
		this->Antique_White.b = 215;

		this->Beige.r = 245;
		this->Beige.g = 245;
		this->Beige.b = 220;

		this->Bisque.r = 255;
		this->Bisque.g = 228;
		this->Bisque.b = 196;

		this->Blanched_Almond.r = 255;
		this->Blanched_Almond.g = 235;
		this->Blanched_Almond.b = 205;

		this->Wheat.r = 245;
		this->Wheat.g = 222;
		this->Wheat.b = 179;

		this->Corn_Silk.r = 255;
		this->Corn_Silk.g = 248;
		this->Corn_Silk.b = 220;

		this->Lemon_Chiffon.r = 255;
		this->Lemon_Chiffon.g = 250;
		this->Lemon_Chiffon.b = 205;

		this->Light_Golden_Rod_Yellow.r = 250;
		this->Light_Golden_Rod_Yellow.g = 250;
		this->Light_Golden_Rod_Yellow.b = 210;

		this->Light_Yellow.r = 255;
		this->Light_Yellow.g = 255;
		this->Light_Yellow.b = 224;

		this->Saddle_Brown.r = 139;
		this->Saddle_Brown.g = 69;
		this->Saddle_Brown.b = 19;

		this->Sienna.r = 160;
		this->Sienna.g = 82;
		this->Sienna.b = 45;

		this->Chocolate.r = 210;
		this->Chocolate.g = 105;
		this->Chocolate.b = 30;

		this->Peru.r = 205;
		this->Peru.g = 133;
		this->Peru.b = 63;

		this->Sandy_Brown.r = 244;
		this->Sandy_Brown.g = 164;
		this->Sandy_Brown.b = 96;

		this->Burly_Wood.r = 222;
		this->Burly_Wood.g = 184;
		this->Burly_Wood.b = 135;

		this->Tan.r = 210;
		this->Tan.g = 180;
		this->Tan.b = 140;

		this->Rosy_Brown.r = 188;
		this->Rosy_Brown.g = 143;
		this->Rosy_Brown.b = 143;

		this->Moccasin.r = 255;
		this->Moccasin.g = 228;
		this->Moccasin.b = 181;

		this->Navajo_White.r = 255;
		this->Navajo_White.g = 222;
		this->Navajo_White.b = 173;

		this->Peach_Puff.r = 255;
		this->Peach_Puff.g = 218;
		this->Peach_Puff.b = 185;

		this->Misty_Rose.r = 255;
		this->Misty_Rose.g = 228;
		this->Misty_Rose.b = 225;

		this->Lavender_Blush.r = 255;
		this->Lavender_Blush.g = 240;
		this->Lavender_Blush.b = 245;

		this->Linen.r = 250;
		this->Linen.g = 240;
		this->Linen.b = 230;


		this->Old_Lace.r = 253;
		this->Old_Lace.g = 245;
		this->Old_Lace.b = 230;

		this->Papaya_Whip.r = 255;
		this->Papaya_Whip.g = 239;
		this->Papaya_Whip.b = 213;

		this->Sea_Shell.r = 255;
		this->Sea_Shell.g = 245;
		this->Sea_Shell.b = 255;

		this->Mint_Cream.r = 245;
		this->Mint_Cream.g = 255;
		this->Mint_Cream.b = 250;

		this->Slate_Gray.r = 112;
		this->Slate_Gray.g = 128;
		this->Slate_Gray.b = 144;

		this->Light_Slate_Gray.r = 119;
		this->Light_Slate_Gray.g = 136;
		this->Light_Slate_Gray.b = 153;

		this->Light_Steel_Blue.r = 176;
		this->Light_Steel_Blue.g = 196;
		this->Light_Steel_Blue.b = 222;

		this->Lavender.r = 230;
		this->Lavender.g = 230;
		this->Lavender.b = 250;

		this->Floral_White.r = 255;
		this->Floral_White.g = 250;
		this->Floral_White.b = 240;

		this->Alice_Blue.r = 240;
		this->Alice_Blue.g = 248;
		this->Alice_Blue.b = 255;

		this->Ghost_White.r = 240;
		this->Ghost_White.g = 248;
		this->Ghost_White.b = 255;

		this->Honeydew.r = 240;
		this->Honeydew.g = 255;
		this->Honeydew.b = 240;

		this->Ivory.r = 255;
		this->Ivory.b = 255;
		this->Ivory.g = 240;

		this->Azure.r = 240;
		this->Azure.g = 255;
		this->Azure.b = 255;

		this->Snow.r = 255;
		this->Snow.g = 250;
		this->Snow.b = 250;

		this->Dim_Gray.r = 105;
		this->Dim_Gray.g = 105;
		this->Dim_Gray.b = 105;

		this->Gray.r = 128;
		this->Gray.g = 128;
		this->Gray.b = 128;

		this->Dark_Gray.r = 169;
		this->Dark_Gray.g = 169;
		this->Dark_Gray.b = 169;

		this->Light_Gray.r = 211;
		this->Light_Gray.g = 211;
		this->Light_Gray.b = 211;

		this->Gainsboro.r = 220;
		this->Gainsboro.g = 220;
		this->Gainsboro.b = 220;

		this->White_Smoke.r = 245;
		this->White_Smoke.g = 245;
		this->White_Smoke.b = 245;



		this->Color_Serial_Number[0] = Black;
		this->Color_Serial_Number[1] = White;
		this->Color_Serial_Number[2] = Red;
		this->Color_Serial_Number[3] = Lime;
		this->Color_Serial_Number[4] = Blue;
		this->Color_Serial_Number[5] = Yellow;
		this->Color_Serial_Number[6] = Cyan;
		this->Color_Serial_Number[7] = Magenta;
		this->Color_Serial_Number[8] = Silver;
		this->Color_Serial_Number[9] = Gray;
		this->Color_Serial_Number[10] = Maroon;
		this->Color_Serial_Number[11] = Olive;
		this->Color_Serial_Number[12] = Green;
		this->Color_Serial_Number[13] = Purple;
		this->Color_Serial_Number[14] = Teal;
		this->Color_Serial_Number[15] = Navy;
		this->Color_Serial_Number[16] = Dark_Red;
		this->Color_Serial_Number[17] = Brown;
		this->Color_Serial_Number[18] = Firebrick;
		this->Color_Serial_Number[19] = Crimson;
		this->Color_Serial_Number[20] = Tomato;
		this->Color_Serial_Number[21] = Coral;
		this->Color_Serial_Number[22] = Indian_Red;
		this->Color_Serial_Number[23] = Light_Coral;
		this->Color_Serial_Number[24] = Dark_Salmon;
		this->Color_Serial_Number[25] = Salmon;
		this->Color_Serial_Number[26] = Light_Salmon;
		this->Color_Serial_Number[27] = Orange_Red;
		this->Color_Serial_Number[28] = Dark_Orange;
		this->Color_Serial_Number[29] = Orange;
		this->Color_Serial_Number[30] = Gold;
		this->Color_Serial_Number[31] = Dark_Golden_Rod;
		this->Color_Serial_Number[32] = Golden_Rod;
		this->Color_Serial_Number[33] = Pale_Golden_Rod;
		this->Color_Serial_Number[34] = Dark_Khaki;
		this->Color_Serial_Number[35] = Khaki;
		this->Color_Serial_Number[36] = Yellow_Green;
		this->Color_Serial_Number[37] = Dark_Olive_Green;
		this->Color_Serial_Number[38] = Olive_Drab;
		this->Color_Serial_Number[39] = Lawn_Green;
		this->Color_Serial_Number[40] = Chart_Reuse;
		this->Color_Serial_Number[41] = Green_Yellow;
		this->Color_Serial_Number[42] = Dark_Green;
		this->Color_Serial_Number[43] = Forest_Green;
		this->Color_Serial_Number[44] = Lime_Green;
		this->Color_Serial_Number[45] = Light_Green;
		this->Color_Serial_Number[46] = Pale_Green;
		this->Color_Serial_Number[47] = Dark_Sea_Green;
		this->Color_Serial_Number[48] = Medium_Spring_Green;
		this->Color_Serial_Number[49] = Spring_Green;
		this->Color_Serial_Number[50] = Sea_Green;
		this->Color_Serial_Number[51] = Medium_Aqua_Marine;
		this->Color_Serial_Number[52] = Medium_Sea_Green;
		this->Color_Serial_Number[53] = Light_Sea_Green;
		this->Color_Serial_Number[54] = Dark_Slate_Gray;
		this->Color_Serial_Number[55] = Dark_Cyan;
		this->Color_Serial_Number[56] = Light_Cyan;
		this->Color_Serial_Number[57] = Dark_Turquoise;
		this->Color_Serial_Number[58] = Turquoise;
		this->Color_Serial_Number[59] = Medium_Turquoise;
		this->Color_Serial_Number[60] = Pale_Turquois;
		this->Color_Serial_Number[61] = Aqua_Marine;
		this->Color_Serial_Number[62] = Powder_Blue;
		this->Color_Serial_Number[63] = Cadet_Blue;
		this->Color_Serial_Number[64] = Steel_Blue;
		this->Color_Serial_Number[65] = Corn_Flower_Blue;
		this->Color_Serial_Number[66] = Deep_Sky_Blue;
		this->Color_Serial_Number[67] = Dodger_Blue;
		this->Color_Serial_Number[68] = Light_Blue;
		this->Color_Serial_Number[69] = Sky_Blue;
		this->Color_Serial_Number[70] = Light_Bky_Blue;
		this->Color_Serial_Number[71] = Midnight_Blue;
		this->Color_Serial_Number[72] = Dark_Blue;
		this->Color_Serial_Number[73] = Medium_Blue;
		this->Color_Serial_Number[74] = Royal_Blue;
		this->Color_Serial_Number[75] = Blue_Violet;
		this->Color_Serial_Number[76] = Indigo;
		this->Color_Serial_Number[77] = Dark_Slate_Blue;
		this->Color_Serial_Number[78] = Slate_Blue;
		this->Color_Serial_Number[79] = Medium_Slate_Blue;
		this->Color_Serial_Number[80] = Medium_Purple;
		this->Color_Serial_Number[81] = Dark_Magenta;
		this->Color_Serial_Number[82] = Dark_Violet;
		this->Color_Serial_Number[83] = Dark_Orchid;
		this->Color_Serial_Number[84] = Medium_Orchid;
		this->Color_Serial_Number[85] = Thistle;
		this->Color_Serial_Number[86] = Plum;
		this->Color_Serial_Number[87] = Violet;
		this->Color_Serial_Number[88] = Orchid;
		this->Color_Serial_Number[89] = Medium_Violet_Red;
		this->Color_Serial_Number[90] = Pale_Violet_Red;
		this->Color_Serial_Number[91] = Deep_Pink;
		this->Color_Serial_Number[92] = Hot_Pink;
		this->Color_Serial_Number[93] = Light_Pink;
		this->Color_Serial_Number[94] = Pink;
		this->Color_Serial_Number[95] = Antique_White;
		this->Color_Serial_Number[96] = Beige;
		this->Color_Serial_Number[97] = Bisque;
		this->Color_Serial_Number[98] = Blanched_Almond;
		this->Color_Serial_Number[99] = Wheat;
		this->Color_Serial_Number[100] = Corn_Silk;
		this->Color_Serial_Number[101] = Lemon_Chiffon;
		this->Color_Serial_Number[102] = Light_Golden_Rod_Yellow;
		this->Color_Serial_Number[103] = Light_Yellow;
		this->Color_Serial_Number[104] = Saddle_Brown;
		this->Color_Serial_Number[105] = Sienna;
		this->Color_Serial_Number[106] = Chocolate;
		this->Color_Serial_Number[107] = Peru;
		this->Color_Serial_Number[108] = Sandy_Brown;
		this->Color_Serial_Number[109] = Burly_Wood;
		this->Color_Serial_Number[110] = Tan;
		this->Color_Serial_Number[111] = Rosy_Brown;
		this->Color_Serial_Number[112] = Moccasin;
		this->Color_Serial_Number[113] = Navajo_White;
		this->Color_Serial_Number[114] = Peach_Puff;
		this->Color_Serial_Number[115] = Misty_Rose;
		this->Color_Serial_Number[116] = Lavender_Blush;
		this->Color_Serial_Number[117] = Linen;
		this->Color_Serial_Number[118] = Old_Lace;
		this->Color_Serial_Number[119] = Papaya_Whip;
		this->Color_Serial_Number[120] = Sea_Shell;
		this->Color_Serial_Number[121] = Mint_Cream;
		this->Color_Serial_Number[122] = Slate_Gray;
		this->Color_Serial_Number[123] = Light_Slate_Gray;
		this->Color_Serial_Number[124] = Light_Steel_Blue;
		this->Color_Serial_Number[125] = Lavender;
		this->Color_Serial_Number[126] = Floral_White;
		this->Color_Serial_Number[127] = Alice_Blue;
		this->Color_Serial_Number[128] = Ghost_White;
		this->Color_Serial_Number[129] = Honeydew;
		this->Color_Serial_Number[130] = Ivory;
		this->Color_Serial_Number[131] = Azure;
		this->Color_Serial_Number[132] = Snow;
		this->Color_Serial_Number[133] = Dim_Gray;
		this->Color_Serial_Number[134] = Dark_Gray;
		this->Color_Serial_Number[135] = Light_Gray;
		this->Color_Serial_Number[136] = Gainsboro;
		this->Color_Serial_Number[137] = White_Smoke;
	}
	Pixel Color_Serial_Number[138];
	Pixel Black, White, Red, Lime, Blue, Yellow, Cyan, Magenta, Silver, Gray, Maroon, Olive;
	Pixel Green, Purple, Teal, Navy, Dark_Red, Brown, Firebrick, Crimson, Tomato, Coral, Indian_Red;
	Pixel Light_Coral, Dark_Salmon, Salmon, Light_Salmon, Orange_Red, Dark_Orange, Orange, Gold;
	Pixel Dark_Golden_Rod, Golden_Rod, Pale_Golden_Rod, Dark_Khaki, Khaki, Yellow_Green, Dark_Olive_Green;
	Pixel Olive_Drab, Lawn_Green, Chart_Reuse, Green_Yellow, Dark_Green, Forest_Green, Lime_Green, Light_Green;
	Pixel Pale_Green, Dark_Sea_Green, Medium_Spring_Green, Spring_Green, Sea_Green, Medium_Aqua_Marine, Medium_Sea_Green;
	Pixel Light_Sea_Green, Dark_Slate_Gray, Dark_Cyan, Light_Cyan, Dark_Turquoise, Turquoise, Medium_Turquoise, Pale_Turquois;
	Pixel Aqua_Marine, Powder_Blue, Cadet_Blue, Steel_Blue, Corn_Flower_Blue, Deep_Sky_Blue, Dodger_Blue, Light_Blue, Sky_Blue;
	Pixel Light_Bky_Blue, Midnight_Blue, Dark_Blue, Medium_Blue, Royal_Blue, Blue_Violet, Indigo, Dark_Slate_Blue, Slate_Blue;
	Pixel Medium_Slate_Blue, Medium_Purple, Dark_Magenta, Dark_Violet, Dark_Orchid, Medium_Orchid, Thistle, Plum, Violet, Orchid;
	Pixel Medium_Violet_Red, Pale_Violet_Red, Deep_Pink, Hot_Pink, Light_Pink, Pink, Antique_White, Beige, Bisque, Blanched_Almond;
	Pixel Wheat, Corn_Silk, Lemon_Chiffon, Light_Golden_Rod_Yellow, Light_Yellow, Saddle_Brown, Sienna, Chocolate, Peru, Sandy_Brown;
	Pixel Burly_Wood, Tan, Rosy_Brown, Moccasin, Navajo_White, Peach_Puff, Misty_Rose, Lavender_Blush, Linen, Old_Lace, Papaya_Whip;
	Pixel Sea_Shell, Mint_Cream, Slate_Gray, Light_Slate_Gray, Light_Steel_Blue, Lavender, Floral_White, Alice_Blue, Ghost_White, Honeydew, Ivory, Azure, Snow;
	Pixel Dim_Gray, Dark_Gray, Light_Gray, Gainsboro, White_Smoke;
	Pixel Get_Random_Color() {
		Random_Utilitis rnd;
		return this->Color_Serial_Number[rnd.Random_INT(3, 134)];
	}

};




class Font_Sprite
{
public:
	std::vector<std::vector<Pixel> > font_s;
	Font_Sprite() {
		std::string data;
		data += "?Q`0001oOch0o01o@F40o0<AGD4090LAGD<090@A7ch0?00O7Q`0600>00000000";
		data += "O000000nOT0063Qo4d8>?7a14Gno94AA4gno94AaOT0>o3`oO400o7QN00000400";
		data += "Of80001oOg<7O7moBGT7O7lABET024@aBEd714AiOdl717a_=TH013Q>00000000";
		data += "720D000V?V5oB3Q_HdUoE7a9@DdDE4A9@DmoE4A;Hg]oM4Aj8S4D84@`00000000";
		data += "OaPT1000Oa`^13P1@AI[?g`1@A=[OdAoHgljA4Ao?WlBA7l1710007l100000000";
		data += "ObM6000oOfMV?3QoBDD`O7a0BDDH@5A0BDD<@5A0BGeVO5ao@CQR?5Po00000000";
		data += "Oc``000?Ogij70PO2D]??0Ph2DUM@7i`2DTg@7lh2GUj?0TO0C1870T?00000000";
		data += "70<4001o?P<7?1QoHg43O;`h@GT0@:@LB@d0>:@hN@L0@?aoN@<0O7ao0000?000";
		data += "OcH0001SOglLA7mg24TnK7ln24US>0PL24U140PnOgl0>7QgOcH0K71S0000A000";
		data += "00H00000@Dm1S007@DUSg00?OdTnH7YhOfTL<7Yh@Cl0700?@Ah0300700000000";
		data += "<008001QL00ZA41a@6HnI<1i@FHLM81M@@0LG81?O`0nC?Y7?`0ZA7Y300080000";
		data += "O`082000Oh0827mo6>Hn?Wmo?6HnMb11MP08@C11H`08@FP0@@0004@000000000";
		data += "00P00001Oab00003OcKP0006@6=PMgl<@440MglH@000000`@000001P00000000";
		data += "Ob@8@@00Ob@8@Ga13R@8Mga172@8?PAo3R@827QoOb@820@0O`0007`0000007P0";
		data += "O`000P08Od400g`<3V=P0G`673IP0`@3>1`00P@6O`P00g`<O`000GP800000000";
		data += "?P9PL020O`<`N3R0@E4HC7b0@ET<ATB0@@l6C4B0O`H3N7b0?P01L3R000000020";

		font_s.reserve(48);
		for (int i = 0; i < 48; i++) {
			font_s.push_back(std::vector<Pixel>(128));
		}

		int px = 0, py = 0;
		for (size_t b = 0; b < 1024; b += 4)
		{
			uint32_t sym1 = (uint32_t)data[b + 0] - 48;
			uint32_t sym2 = (uint32_t)data[b + 1] - 48;
			uint32_t sym3 = (uint32_t)data[b + 2] - 48;
			uint32_t sym4 = (uint32_t)data[b + 3] - 48;
			uint32_t r = sym1 << 18 | sym2 << 12 | sym3 << 6 | sym4;

			for (int i = 0; i < 24; i++)
			{
				int k = r & (1 << i) ? 255 : 0;
				font_s[py][px] = Pixel(k, k, k);
				if (++py == 48) { px++; py = 0; }
			}
		}
	}
};
Font_Sprite FSPRITE;




//
//class TypeForm {
//
//public:
//	int *A, *B, *C, *D, *E, *F, *G, *H, *I, *J, *K, *L, *M, *N, *O, *P, *Q, *R, *S, *T, *U, *V, *W, *X, *Y, *Z;
//	int *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *m, *n, *o, *p, *q, *r, *s, *t, *u, *v, *w, *x, *y, *z;
//	int *One, *Two, *Three, *Four, *Five, *Six, *Seven, *Eight, *Nine, *Zero;
//	int *exclamation_point, *question_mark, *Right_Braket, *Left_Braket,
//		*Ampersand, *Precent, *Comma, *Square_Braket_Left, *Square_Braket_Right, *Colon,
//		*Semi_Colon, *EqualSign, *PlusSign, *MinusSign, *Astersik, *Dot;
//
//	TypeForm() {
//		b = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//
//		//
//
//
//		A = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		a = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		B = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		b = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		C = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 1, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		c = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		D = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		d = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		E = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		e = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		F = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		f = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 1, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		G = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 1, 1, 1, 1, 0,
//			0, 1, 1, 0, 0, 1, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		g = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		H = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		h = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		I = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		i = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		J = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		j = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 1, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		K = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 1, 1, 0, 0, 0,
//			0, 1, 1, 1, 1, 0, 0, 0, 0,
//			0, 1, 1, 0, 1, 1, 0, 0, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		k = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 0, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 1, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		L = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		l = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		M = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 0, 1, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 1, 1, 0, 1, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		m = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 1, 0, 1, 0, 0,
//			0, 0, 1, 0, 1, 0, 1, 0, 0,
//			0, 0, 1, 0, 1, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		N = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 0, 1, 1, 0,
//			0, 1, 1, 0, 1, 1, 1, 1, 0,
//			0, 1, 1, 0, 0, 1, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		n = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		O = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		o = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		P = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		p = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Q = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		q = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		R = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		r = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		S = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		s = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		T = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		t = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		U = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 0, 1, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		u = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		V = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		v = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 0, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		W = new int[81]
//		{ 0,0,0,0,0,0,0,0,0,
//		  0,1,1,0,0,0,1,1,0,
//		  0,1,1,0,0,0,1,1,0,
//		  0,1,1,0,0,0,1,1,0,
//		  0,1,1,0,1,0,1,1,0,
//		  0,1,1,1,1,1,1,1,0,
//		  0,1,1,1,0,1,1,1,0,
//		  0,1,1,0,0,0,1,1,0,
//		  0,0,0,0,0,0,0,0,0
//		};
//		w = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 1, 0, 1, 0, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 0, 1, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		X = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		x = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 1, 0, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 0, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Y = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		y = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 0, 0, 1, 0, 0, 0,
//			0, 0, 1, 0, 0, 1, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 0, 0, 0,
//			0, 0, 1, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Z = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		z = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Zero = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 1, 1, 1, 0,
//			0, 1, 1, 0, 1, 0, 1, 1, 0,
//			0, 1, 1, 1, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		One = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Two = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Three = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Four = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 1, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Five = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Six = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 0, 0, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Seven = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Eight = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Nine = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 0, 0, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 1, 1, 0, 0, 1, 1, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		exclamation_point = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		question_mark = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Right_Braket = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Left_Braket = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Ampersand = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Precent = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 0, 0, 0, 0, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 1, 1, 0,
//			0, 1, 1, 0, 0, 0, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Comma = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Dot = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Square_Braket_Left = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 0, 0, 0, 0, 0,
//			0, 1, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Square_Braket_Right = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 1, 0,
//			0, 0, 0, 0, 0, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Colon = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Semi_Colon = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 1, 1, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		PlusSign = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		MinusSign = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		EqualSign = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 1, 1, 1, 1, 1, 1, 1, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//		Astersik = new int[81]
//		{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 1, 1, 1, 1, 1, 0, 0,
//			0, 0, 0, 1, 1, 1, 0, 0, 0,
//			0, 0, 0, 0, 1, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0,
//			0, 0, 0, 0, 0, 0, 0, 0, 0
//		};
//	}
//	~TypeForm() {
//		delete[] A;
//		delete[] B;
//		delete[] C;
//		delete[] D;
//		delete[] E;
//		delete[] F;
//		delete[] G;
//		delete[] H;
//		delete[] I;
//		delete[] J;
//		delete[] K;
//		delete[] L;
//		delete[] M;
//		delete[] N;
//		delete[] O;
//		delete[] P;
//		delete[] Q;
//		delete[] R;
//		delete[] S;
//		delete[] T;
//		delete[] U;
//		delete[] V;
//		delete[] W;
//		delete[] X;
//		delete[] Y;
//		delete[] Z;
//		delete[] a;
//		delete[] b;
//		delete[] c;
//		delete[] d;
//		delete[] e;
//		delete[] f;
//		delete[] g;
//		delete[] h;
//		delete[] i;
//		delete[] j;
//		delete[] k;
//		delete[] l;
//		delete[] m;
//		delete[] n;
//		delete[] o;
//		delete[] p;
//		delete[] q;
//		delete[] r;
//		delete[] s;
//		delete[] t;
//		delete[] u;
//		delete[] v;
//		delete[] w;
//		delete[] x;
//		delete[] y;
//		delete[] z;
//		delete[] One;
//		delete[] Two;
//		delete[] Three;
//		delete[] Four;
//		delete[] Five;
//		delete[] Six;
//		delete[] Seven;
//		delete[] Nine;
//		delete[] Zero;
//		delete[] exclamation_point;
//		delete[] question_mark;
//		delete[] Right_Braket;
//		delete[] Left_Braket;
//		delete[] Ampersand;
//		delete[] Precent;
//		delete[] Comma;
//		delete[] Square_Braket_Left;
//		delete[] Square_Braket_Right;
//		delete[] Colon;
//		delete[] Semi_Colon;
//		delete[] EqualSign;
//		delete[] PlusSign;
//		delete[] MinusSign;
//		delete[] Astersik;
//		delete[] Dot;
//
//	}
//
//
//}TYPELOADF;
//


//misc


double squared_3Point_distance(Point<double> first, Point<double> second) {
	return (first[0] - second[0])*(first[0] - second[0]) + (first[1] - second[1])*(first[1] - second[1]) + (first[2] - second[2])*(first[2] - second[2]);
}
double Color_DistanceSq(Pixel a, Pixel b) {
	double  recored;
	recored = (b.r - a.r)*(b.r - a.r) + (b.g - a.g)*(b.g - a.g) + (b.b - a.b)*(b.b - a.b);
	return std::sqrt(recored);
}
double AAipart(double x) {
	return std::floor(x);
}
double AAround(double x) {
	return AAipart((x + 0.5));
}
double AAfpart(double x) {
	return x - std::floor(x);
}
double AArfpart(double x) {
	return 1 - AAfpart(x);
}
double Color_Delta(Pixel A, Pixel B) {
	long  R_Gag = ((long)(A.r + (long)(B.r)) / 2);
	long  r = (long)A.r - (long)B.r;
	long  g = (long)A.g - (long)B.g;
	long  b = (long)A.b - (long)B.b;
	return (float)(std::sqrt((((512 + R_Gag)*r*r) >> 8) + 4 * g*g + (((767 - R_Gag)*b*b) >> 8)));
}
int Color_Distance(Pixel a, Pixel b) {
	int recored;
	recored = (a.b - b.b) + (a.r - b.r) + (a.g - b.g);
	if (recored < 0) {
		recored *= -1;
	}

	return recored;
}
//


template<class T> double getMean(std::vector<T> &Data) {
	double sum = 0;
	sum = std::accumulate(Data.begin(), Data.end(), 0);
	return sum / Data.size();
}
template<class T> double getMedian(std::vector<T> &Data) {
	std::vector<T> tmp(Data);
	std::sort(tmp.begin(), tmp.end());
	return tmp.size() % 2 == 0 ? (double)(tmp[tmp.size() / 2] + (double)tmp[(tmp.size() / 2) - 1]) / 2 : tmp[tmp.size() / 2];
}
template<class T>  double getStandard_Deviation(std::vector<T> Data) {
	double mean = getMean(Data);
	T sum = 0;
	for (int i = 0; i < Data.size(); i++) {
		sum += ((Data[i] - mean)*(Data[i] - mean));
	}
	sum /= (double)Data.size();
	sum = std::sqrt(sum);
	return sum;
}
template<class T> double getVariance(std::vector<T>  Data) {
	double Deviation = getStandard_Deviation(Data);
	return (Deviation)*(Deviation);
}
template<class T> T getMin(std::vector<T> &Data) {
	return *std::min_element(Data.begin(),Data.end());
}
double nthRoot(int A, int N) {
	double xPre = std::rand() % 10;
	double eps = 0.001;
	double delX = 2147483647;
	double xK = 0.0;
	while (delX > eps)
	{
		xK = ((N - 1.0) * xPre +
			(double)A / std::pow(xPre, N - 1)) / (double)N;
		delX = std::
			abs(xK - xPre);
		xPre = xK;
	}

	return xK;
}
template<class T> T getMax(std::vector<std::vector<T> > data) {
	int max = std::numeric_limits<T>::min();
	for (int i = 0; i < data.size(); i++) {
		//max = std::max_element(data[i].begin(), data[i].end());
		for (int j = 0; j < data[i].size(); j++) {
			std::vector<T> temp = data[i];
			if (temp[j] > max) {
				max = temp[j];
			}
		}
	}
	return max;

}
template<class T> T getMin(std::vector<std::vector<T> > data) {
	int max = std::numeric_limits<T>::max();
	for (int i = 0; i < data.size(); i++) {
		for (int j = 0; j < data[i].size(); j++) {
			std::vector<T> temp = data[i];
			if (temp[j] < max) {
				max = temp[j];
			}
		}
	}



	return max;

}
template<class T> T getMax(std::vector<T> &data) {
	return *std::max_element(data.begin(), data.end());
}
double Remap(double value, double fromMin, double fromMax, double toMin, double toMax)
{
	double fromAbs = value - fromMin;
	double fromMaxAbs = fromMax - fromMin;
	double normal;
	if (fromMaxAbs == 0) {
		normal = 0;
	}
	else {
		normal = fromAbs / fromMaxAbs;
	}

	double toMaxAbs = toMax - toMin;
	double toAbs = toMaxAbs * normal;

	double to = toAbs + toMin;

	return to;
}
double Linear_Interpolate(double const &a, double const &b, double const &x) {
	return  a * (1 - x) + b * x;
}
double Cosine_Interpolate(double const &a, double const &b, double const &x){
	double ft = x * std::_Pi;
	double f = (1 - std::cos(ft)) * .5;

	return  a * (1 - f) + b * f;
}
double Cubic_Interpolate(double const &Before_A, double const &A, double const &B, double const &After_B, double const &x){

	double	P = (After_B - B) - (Before_A - A);
	double	Q = (Before_A - A) - P;
	double	R = B - Before_A;
	double	S = A;
	return P * std::pow(x, 3) + Q * x*x + R * x + S;
}
double SmoothStep_Interpolate(double const &a, double const &b, double const &x) {
	double val = (x*x)*(3 - 2 * x);
	return Linear_Interpolate(a, b, val);
}
double Acceleration_Interpolate(double const &a, double const &b, double const &x) {
	return Linear_Interpolate(a, b, x*x);
}
double Deceleration_Interpolate(double const &a, double const &b, double const &x) {
	double val = 1.0 - std::pow(1.0-x, 2);
	return Linear_Interpolate(a, b, val);
}
std::string GetPointTwoPrecision(double number) {
	std::ostringstream streamObj;
	streamObj << std::fixed;
	streamObj << std::setprecision(2);
	streamObj << ((number));
	return streamObj.str();
}
//










class Blob {
public:
	int Upleft_X, Upleft_Y;
	int Downright_X, Downright_Y;
	int Distnace_Treshold;

	double Cordinate_Distance(int x0, int y0, int x1, int y1) {
		double Distance = (double)((x1 - x0)*(x1 - x0) + (y1 - y0)*(y1 - y0));
		return Distance;
	}

	Blob(int x, int y, int Distnace_Treshold) {
		this->Downright_X = x;
		this->Downright_Y = y;
		this->Upleft_X = x;
		this->Upleft_Y = y;
		this->Distnace_Treshold = Distnace_Treshold;
	}
	Blob(const Blob &copy) {
		this->Downright_X = copy.Downright_X;
		this->Downright_Y = copy.Downright_Y;
		this->Upleft_X = copy.Upleft_X;
		this->Upleft_Y = copy.Upleft_Y;
		this->Distnace_Treshold = copy.Distnace_Treshold;
	}
	bool Near(int x, int y) {
		double CentetX, CenterY, Dist;
		CentetX = std::fmax(std::fmin(x, Upleft_X), Downright_X);
		CenterY = std::fmax(std::fmin(y, Upleft_Y), Downright_Y);
		Dist = (double)(Cordinate_Distance((int)CentetX, (int)CenterY, (int)(x), (int)(y)));

		if (Dist < this->Distnace_Treshold*Distnace_Treshold) {
			return true;
		}
		else {

			return false;
		}
	}

	void add(int px, int py) {
		this->Downright_X = (int)std::fmin(Downright_X, px);
		this->Downright_Y = (int)std::fmin(Downright_Y, py);

		this->Upleft_X = (int)std::fmax(Upleft_X, px);
		this->Upleft_Y = (int)std::fmax(Upleft_Y, py);
	}

	void Clear() {
		this->Downright_X = this->Downright_Y = this->Upleft_X = this->Upleft_Y = -1;
	}

	void SetProps(int x, int y) {
		this->Downright_X = x;
		this->Downright_Y = y;
		this->Upleft_X = x;
		this->Upleft_Y = y;
	}

	double Size() {
		//return (double)std::abs(this->Upleft_X - Downright_X)*(Upleft_Y - Downright_Y);
		return std::sqrt((this->Downright_X - this->Upleft_X)*(this->Downright_X - this->Upleft_X) +
			(this->Downright_Y - this->Upleft_Y)*(this->Downright_Y - this->Upleft_Y));
	}


};



class Image {

private:
	unsigned char *image_data;
	int channel;
	unsigned int im_size;
	int pos_X, pos_Y;
	unsigned short MODE = 0;

	void init_pixel_matrix() {

		this->Pixel_Matrix.reserve(Image_Height);
		for (int i = 0; i < this->Image_Height; i++) {
			this->Pixel_Matrix.emplace_back();
			this->Pixel_Matrix[i].reserve(this->Image_Width);
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i].emplace_back( 0, 0, 0 );
			}
		}

		if (this->channel == 3) {

			int j = 0, k = 0, clock = 0;
			for (int i = 0; i < Image_Width*Image_Height * 3; i += 3) {
				if (clock == Image_Width) {
					j++;
					k = 0;
					clock = 0;
				}
				// Pixel_Matrix[j][k].index_range = i;
				Pixel_Matrix[j][k] = this->Get_Color(j, k);
				k++;
				clock++;
			}
		}
		else {

			int j = 0, k = 0, clock = 0;
			for (int i = 0; i < Image_Width*Image_Height * 4; i += 4) {
				if (clock == Image_Width) {
					j++;
					k = 0;
					clock = 0;
				}
				Pixel_Matrix[j][k] = this->Get_Color(j, k);
				k++;
				clock++;
			}

		}

	}
	void init_pixel_matrix(Pixel const &init_color) {

		this->Pixel_Matrix.reserve(Image_Height);
		for (int i = 0; i < this->Image_Height; i++) {
			this->Pixel_Matrix.emplace_back();
			this->Pixel_Matrix[i].reserve(this->Image_Width);
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i].emplace_back(init_color.r, init_color.g, init_color.b);
			}
		}

	}

	void BresenhamsLine(int start_y, int start_x, int target_y, int target_x, Pixel color) {
		double dx, sx, dy, sy, err, e2;
		double x0 = start_y, x1 = target_y, y0 = start_x, y1 = target_x;
		dx = std::abs(target_y - start_y);
		sx = start_y < target_y ? 1 : -1;
		dy = -std::abs(target_x - start_x);
		sy = start_x < target_x ? 1 : -1;
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				this->Set_Color((int)std::floor(x0), (int)std::floor(y0), color);
				//Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)] = new Pixel(color);

				break;
			}

			//Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)] = new Pixel(color);
			this->Set_Color((int)std::floor(x0), (int)std::floor(y0), color);


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
	std::vector<Point<double> > K_Means(const std::vector<Point<double> > &data, size_t k, size_t number_of_iterations) {
		static std::random_device seed; //seed for psudo random engine 
		static std::mt19937 random_number_generator(seed()); //merssene twisster using the PR seed
		std::uniform_int_distribution<std::size_t> indices(0, data.size() - 1);
		std::vector<Point<double> > means(k);

		for (auto& cluster : means) {
			cluster = data[indices(random_number_generator)];
		}

		std::vector<std::size_t> assignments(data.size());

		for (std::size_t iteration = 0; iteration < number_of_iterations; ++iteration) {
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
			std::vector<Point<double> > new_means(k);
			std::vector<size_t> counts(k, 0);

			for (size_t point = 0; point < data.size(); ++point) {
				const auto cluster = assignments[point];
				new_means[cluster][0] += data[point].p_members[0];
				new_means[cluster][1] += data[point].p_members[1];
				new_means[cluster][2] += data[point].p_members[2];
				counts[cluster] += 1;
			}

			// Divide sums by counts to get new centroids.
			for (size_t cluster = 0; cluster < k; ++cluster) {
				// Turn 0/0 into 0/1 to avoid zero division.
				const auto count = std::max<std::size_t>(1, counts[cluster]);
				means[cluster][0] = new_means[cluster][0] / count;
				means[cluster][1] = new_means[cluster][1] / count;
				means[cluster][2] = new_means[cluster][2] / count;

			}
		}

		return means;

	}
	void AAsetPixel4(int centerX, int centerY, int deltaX, int deltaY, Pixel const &Color, double alpha) {
		//assert((centerX + deltaX) > this->Image_Width);
		if ((centerX + deltaX) > this->Image_Width - 1 || (centerX - deltaX) < 0 || (centerY + deltaY) > this->Image_Height - 1 ||
			(centerY + deltaY) < 0) {
			std::cout << "OUT OF BOUNDS WHEN DRAWING CIRCLE\n";
			return;
		}

		this->Set_Color(centerY + deltaY, centerX + deltaX, TRI(Color, this->Get_Color(centerY + deltaY, centerX + deltaX), alpha));
		this->Pixel_Matrix[centerY + deltaY][centerX + deltaX] = TRI(Color, this->Pixel_Matrix[centerY + deltaY][centerX + deltaX], alpha);
		this->Set_Color(centerY + deltaY, centerX - deltaX, TRI(Color, this->Get_Color(centerY + deltaY, centerX - deltaX), alpha));
		this->Pixel_Matrix[centerY + deltaY][centerX - deltaX] = TRI(Color, this->Pixel_Matrix[centerY + deltaY][centerX - deltaX], alpha);
		this->Set_Color(centerY - deltaY, centerX + deltaX, TRI(Color, this->Get_Color(centerY - deltaY, centerX + deltaX), alpha));
		this->Pixel_Matrix[centerY - deltaY][centerX + deltaX] = TRI(Color, this->Pixel_Matrix[centerY - deltaY][centerX + deltaX], alpha);
		this->Set_Color(centerY - deltaY, centerX - deltaX, TRI(Color, this->Get_Color(centerY - deltaY, centerX - deltaX), alpha));
		this->Pixel_Matrix[centerY - deltaY][centerX - deltaX] = TRI(Color, this->Pixel_Matrix[centerY - deltaY][centerX - deltaX], alpha);


	}
public:


	std::vector<std::vector<Pixel> > Pixel_Matrix;
	int Image_Width, Image_Height;
	std::string F_Path;

	//functionality
	Image() {


	}
	Image(Image const &copy) {
		this->F_Path = copy.F_Path;
		this->image_data = copy.image_data;
		this->Pixel_Matrix = copy.Pixel_Matrix;
		this->Image_Width = copy.Image_Width;
		this->Image_Height = copy.Image_Height;
		this->channel = copy.channel;

	}
	void Set_Color(int i, int j, Pixel color) {
		if (channel == 3) {
			int pos = ((Image_Width * 3)*(i)+3 * (j));
			this->image_data[pos] = color.r;
			this->image_data[pos + 1] = color.g;
			this->image_data[pos + 2] = color.b;
		}
		else {
			int pos = ((Image_Width * 4)*(i)+4 * (j));
			this->image_data[pos] = color.r;
			this->image_data[pos + 1] = color.g;
			this->image_data[pos + 2] = color.b;
			this->image_data[pos + 3] = color.A;

		}


	}
	Pixel Get_Color(int i, int j) {
		Pixel res;
		if (channel == 3) {
			int pos = ((Image_Width * 3)*(i)+3 * (j));
			res = Pixel((int)image_data[pos], (int)image_data[pos + 1], (int)image_data[pos + 2]);
		}
		else {
			int pos = ((Image_Width * 4)*(i)+4 * (j));
			res = Pixel((int)image_data[pos], (int)image_data[pos + 1], (int)image_data[pos + 2], (int)image_data[pos + 3]);

		}
		return res;
	}
	void Set_Antialiased_Point(double const &x, double const &y,Pixel const &Color) {
		for (double i = std::floor(x); i < std::ceil(x); i++) {
			for (double j = std::floor(y); j < ceil(y);j++) {
				double percent_x = 1 - std::abs(x - i);
				double percent_y = 1 - std::abs(y - j);
				double	percent = percent_x * percent_y;
				

				Set_Color((int)j, (int)i, Pixel((int)Color.r*percent, (int)Color.g*percent, (int)Color.b*percent));
			}
		}
	}
	void Load_Image(std::string FilePath) {

		if (FilePath.find(".jpg") != std::string::npos) {

			this->image_data = stbi_load(FilePath.c_str(), &this->Image_Width, &Image_Height, &channel, 3);

			this->im_size = Image_Width * Image_Height;
			if (this->image_data == NULL) {
				std::cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
			}
			else {
				this->init_pixel_matrix();
				std::cout << "\n" << FilePath << " File Loaded Succsesfully\n";

			}
		}
		else if (FilePath.find(".png") != std::string::npos) {

			this->image_data = stbi_load(FilePath.c_str(), &this->Image_Width, &Image_Height, &channel, STBI_rgb_alpha);

			this->im_size = Image_Width * Image_Height;
			if (this->image_data == NULL) {
				std::cout << "\n There Was An Error While Openning Image\nPlease Check File Name / Diractory\n";
			}
			else {
				this->init_pixel_matrix();
				std::cout << "\n" << FilePath << " File Loaded Succsesfully\n";

			}
		}

	}

	/*
	void Crop_Image(int left_corner_y, int left_corner_x, int right_corner_y, int right_corner_x) {
	   int width = right_corner_x - left_corner_x;
	   int height = right_corner_y - left_corner_y;
	   Image tmp = new Image();
	   int x = 0, y = 0;
	   tmp.Load_Blank_Canvas(height, width, new Pixel(0, 0, 0));
	   for (int i = left_corner_y; i < right_corner_y; i++) {
		   for (int j = left_corner_x; j < right_corner_x; j++) {
			   tmp.Pixel_Matrix[y][x] = this->Pixel_Matrix[i][j];
			   x++;
		   }
		   y++;
		   x = 0;
	   }
	   tmp.Commint_Matrix_Changes();
	   this->IMG = tmp.IMG;
	   this->Image_Width = tmp.Image_Width;
	   this->Image_Height = tmp.Image_Height;
   }
	void Crop_Image(int left_corner_y, int left_corner_x, int right_corner_y, int right_corner_x, String save_as) {
	   int width = right_corner_x - left_corner_x;
	   int height = right_corner_y - left_corner_y;
	   Image tmp = new Image();
	   int x = 0, y = 0;
	   tmp.Load_Blank_Canvas(height, width, new Pixel(0, 0, 0));
	   for (int i = left_corner_y; i < right_corner_y; i++) {
		   for (int j = left_corner_x; j < right_corner_x; j++) {
			   tmp.Pixel_Matrix[y][x] = this->Pixel_Matrix[i][j];
			   x++;
		   }
		   y++;
		   x = 0;
	   }
	   tmp.Commint_Matrix_Changes();
	   tmp.Write_Image(save_as);
   }
	*/


	Image operator+(Image const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r += Arg.Pixel_Matrix[i][j].r;
				Res.Pixel_Matrix[i][j].g += Arg.Pixel_Matrix[i][j].g;
				Res.Pixel_Matrix[i][j].b += Arg.Pixel_Matrix[i][j].b;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator-(Image const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r -= Arg.Pixel_Matrix[i][j].r;
				Res.Pixel_Matrix[i][j].g -= Arg.Pixel_Matrix[i][j].g;
				Res.Pixel_Matrix[i][j].b -= Arg.Pixel_Matrix[i][j].b;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	std::vector<Pixel> &operator[](int row) {
		return this->Pixel_Matrix[row];
	}
	Image operator*(Image const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r *= Arg.Pixel_Matrix[i][j].r;
				Res.Pixel_Matrix[i][j].g *= Arg.Pixel_Matrix[i][j].g;
				Res.Pixel_Matrix[i][j].b *= Arg.Pixel_Matrix[i][j].b;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator/(Image const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r /= Arg.Pixel_Matrix[i][j].r;
				Res.Pixel_Matrix[i][j].g /= Arg.Pixel_Matrix[i][j].g;
				Res.Pixel_Matrix[i][j].b /= Arg.Pixel_Matrix[i][j].b;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator/(double const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r = (int)(Arg / Res.Pixel_Matrix[i][j].r);
				Res.Pixel_Matrix[i][j].g /= (int)(Arg / Res.Pixel_Matrix[i][j].g);
				Res.Pixel_Matrix[i][j].b /= (int)(Arg / Res.Pixel_Matrix[i][j].b);
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}

	Image operator+(int const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r += Arg;
				Res.Pixel_Matrix[i][j].g += Arg;
				Res.Pixel_Matrix[i][j].b += Arg;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator-(int const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r -= Arg;
				Res.Pixel_Matrix[i][j].g -= Arg;
				Res.Pixel_Matrix[i][j].b -= Arg;
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator*(double const &Arg) {
		Image Res(*this);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r = (int)(Arg* Res.Pixel_Matrix[i][j].r);
				Res.Pixel_Matrix[i][j].g = (int)(Arg*Res.Pixel_Matrix[i][j].g);
				Res.Pixel_Matrix[i][j].b = (int)(Arg* Res.Pixel_Matrix[i][j].b);
				Res.Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image Arithmetic_Union(Image to_Union) {
		Image Res(*this);
		if (to_Union.Image_Height != this->Image_Height || this->Image_Width != to_Union.Image_Width) {
			std::cout << "Operation Aborted: Images Are Different In Size\n";
			return Image();
		}

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r = (int)std::fmax(Res.Pixel_Matrix[i][j].r, to_Union.Pixel_Matrix[i][j].r);
				Res.Pixel_Matrix[i][j].g = (int)std::fmax(Res.Pixel_Matrix[i][j].g, to_Union.Pixel_Matrix[i][j].g);
				Res.Pixel_Matrix[i][j].b = (int)std::fmax(Res.Pixel_Matrix[i][j].b, to_Union.Pixel_Matrix[i][j].b);

			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator~() {
		Image Res(*this);

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Res.Pixel_Matrix[i][j].r = 255 - Res.Pixel_Matrix[i][j].r;
				Res.Pixel_Matrix[i][j].g = 255 - Res.Pixel_Matrix[i][j].g;
				Res.Pixel_Matrix[i][j].b = 255 - Res.Pixel_Matrix[i][j].b;


			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator&(Image to_AND) {
		if (to_AND.Image_Height != this->Image_Height || this->Image_Width != to_AND.Image_Width) {
			std::cout << "Operation Aborted: Images Are Different In Size\n";
			return Image();
		}
		Image Res(*this);
		int a, b;
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				a = Res.Pixel_Matrix[i][j].r / 255;
				b = to_AND.Pixel_Matrix[i][j].r / 255;
				if ((b & a) == 1) {
					Res.Pixel_Matrix[i][j].r = 255;
					Res.Pixel_Matrix[i][j].g = 255;
					Res.Pixel_Matrix[i][j].b = 255;

				}
				else {
					Res.Pixel_Matrix[i][j].r = 0;
					Res.Pixel_Matrix[i][j].g = 0;
					Res.Pixel_Matrix[i][j].b = 0;

				}

			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator|(Image to_OR) {
		if (to_OR.Image_Height != this->Image_Height || this->Image_Width != to_OR.Image_Width) {
			std::cout << "Operation Aborted: Images Are Different In Size\n";
			return Image();
		}
		Image Res(*this);
		int a, b;
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				a = Res.Pixel_Matrix[i][j].r / 255;
				b = to_OR.Pixel_Matrix[i][j].r / 255;
				if ((b | a) == 1) {
					Res.Pixel_Matrix[i][j].r = 255;
					Res.Pixel_Matrix[i][j].g = 255;
					Res.Pixel_Matrix[i][j].b = 255;

				}
				else {
					Res.Pixel_Matrix[i][j].r = 0;
					Res.Pixel_Matrix[i][j].g = 0;
					Res.Pixel_Matrix[i][j].b = 0;

				}

			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}
	Image operator^(Image to_XOR) {
		if (to_XOR.Image_Height != this->Image_Height || this->Image_Width != to_XOR.Image_Width) {
			std::cout << "Operation Aborted: Images Are Different In Size\n";
			return Image();
		}
		Image Res(*this);
		int a, b;
		for (int i = 0; i < Res.Image_Height; i++) {
			for (int j = 0; j < Res.Image_Width; j++) {
				a = Res.Pixel_Matrix[i][j].r / 255;
				b = to_XOR.Pixel_Matrix[i][j].r / 255;
				if ((b ^ a) == 1) {
					Res.Pixel_Matrix[i][j].r = 255;
					Res.Pixel_Matrix[i][j].g = 255;
					Res.Pixel_Matrix[i][j].b = 255;

				}
				else {
					Res.Pixel_Matrix[i][j].r = 0;
					Res.Pixel_Matrix[i][j].g = 0;
					Res.Pixel_Matrix[i][j].b = 0;

				}

			}
		}
		Res.Commint_Matrix_Changes();
		return Res;
	}

	void Commint_Matrix_Changes() {

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Set_Color(i, j, this->Pixel_Matrix[i][j]);
			}
		}
	}
	void Update_Pixel_Matrix() {
		if (channel == 3) {
			int j = 0, k = 0, clock = 0;
			for (int i = 0; i < Image_Width*Image_Height * 3; i += 3) {
				if (clock == Image_Width) {
					j++;
					k = 0;
					clock = 0;
				}
				// Pixel_Matrix[j][k].index_range = i;
				Pixel_Matrix[j][k] = this->Get_Color(j, k);
				k++;
				clock++;
			}
		}
		else {
			int j = 0, k = 0, clock = 0;
			for (int i = 0; i < Image_Width*Image_Height * 4; i += 4) {
				if (clock == Image_Width) {
					j++;
					k = 0;
					clock = 0;
				}
				// Pixel_Matrix[j][k].index_range = i;
				Pixel_Matrix[j][k] = this->Get_Color(j, k);
				k++;
				clock++;
			}
		}
	}
	void Write_Image(std::string Filename) {

		if (channel == 3) {
			stbi_write_jpg((Filename).c_str(), this->Image_Width, Image_Height, channel, image_data, 100);
			std::cout << "\nJpg File Saved Succsfully As: " << Filename << std::endl;

		}
		else if (channel == 4) {
			stbi_write_png((Filename).c_str(), Image_Width, Image_Height, channel, image_data, this->Image_Width * sizeof(int));
			std::cout << "\nPng File Saved Succsfully As: " << Filename << std::endl;


		}


	}
	void Load_Blank_Canvas(int height, int width, Pixel const &Background_Color, int mode = S_JPG) {

		if (mode == S_JPG) {
			this->channel = 3;
			this->Image_Width = width;
			this->Image_Height = height;
			if (image_data != nullptr) {

				stbi_image_free(image_data);
			}
			this->image_data = (unsigned char*)malloc(width*height*channel * sizeof(unsigned char));

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					this->Set_Color(i, j, Background_Color);
				}
			}

			this->init_pixel_matrix(Background_Color);

		}
		else if (mode == S_PNG) {
			this->channel = 4;
			this->Image_Width = width;
			this->Image_Height = height;
			if (image_data != nullptr) {

				stbi_image_free(image_data);
			}
			this->image_data = (unsigned char*)malloc(width*height*channel * sizeof(int));

			for (int i = 0; i < height; i++) {
				for (int j = 0; j < width; j++) {
					this->Set_Color(i, j, Background_Color);
				}
			}

			this->init_pixel_matrix();



		}
	}
	void Crop_Image(int left_corner_y, int left_corner_x, int right_corner_y, int right_corner_x) {
		int width = right_corner_x - left_corner_x;
		int height = right_corner_y - left_corner_y;
		Image tmp;
		int x = 0, y = 0;
		tmp.Load_Blank_Canvas(height, width, Pixel(0, 0, 0));
		for (int i = left_corner_y; i < right_corner_y; i++) {
			for (int j = left_corner_x; j < right_corner_x; j++) {
				tmp.Pixel_Matrix[y][x] = this->Pixel_Matrix[i][j];
				x++;
			}
			y++;
			x = 0;
		}
		tmp.Commint_Matrix_Changes();
		stbi_image_free(this->image_data);
		this->image_data = tmp.image_data;
		this->Pixel_Matrix = tmp.Pixel_Matrix;
		this->Image_Width = tmp.Image_Width;
		this->Image_Height = tmp.Image_Height;
	}

	void Draw_Square(int center_x, int center_y, int param_a, int param_b, Pixel Color, int Mode = Draw_Modes::FILLED) {

		if (Mode == Draw_Modes::FILLED) {

			if (center_x + param_a > this->Image_Width || center_y + param_b >= this->Image_Height || center_x - param_a < 0 || center_y - param_b < 0) {
				std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
				return;
			}

			for (int j = center_y - param_b; j <= center_y + param_b; j++) {
				for (int i = center_x - param_a; i <= center_x + param_a; i++) {
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this->Set_Color(j, i, Color);
				}
			}
			this->Update_Pixel_Matrix();

		}
		else if (Mode == Draw_Modes::CHECKERED) {
			if (center_x + param_a > this->Image_Width || center_y + param_b >= this->Image_Height || center_x - param_a < 0 || center_y - param_b < 0) {
				std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
				return;
			}

			for (int j = center_y - param_b; j <= center_y + param_b; j++) {
				for (int i = center_x - param_a; i <= center_x + param_a; i += 8) {
					//Pixel_Matrix[j][i] = new Pixel(Color);
					this->Set_Color(j, i, Color);
				}
			}

			for (int j = center_y - param_b; j <= center_y + param_b; j++) {
				for (int i = center_x - param_a; i <= center_x + param_a; i += 8) {
					//Pixel_Matrix[i][j] = new Pixel(Color);
					this->Set_Color(i, j, Color);
				}
			}
		}
		else if (Mode == Draw_Modes::CORNERS) {

			this->Draw_Line(center_x, center_y, param_a, center_y, Color);
			this->Draw_Line(center_x, center_y, center_x, param_b, Color);
			this->Draw_Line(center_x, param_b, param_a, param_b, Color);
			this->Draw_Line(param_a, center_y, param_a, param_b, Color);



		}
		else if (Mode == Draw_Modes::HOLLOW) {

			if (center_x + param_a >= this->Image_Width || center_y + param_b >=
				this->Image_Height || center_x - param_a < 0 || center_y - param_b < 0) {
				std::cout << "Square Out Of Image Range, Action Aborted\nPlease Specify Size And Position In Image Range\n";
				return;
			}
			for (int i = center_x - param_a; i <= center_x + param_a; i++) {
				this->Set_Color(center_y + param_b, i, Color);
			}
			for (int i = center_x - param_a; i <= center_x + param_a; i++) {
				this->Set_Color(center_y - param_b, i, Color);
			}
			for (int i = center_y - param_b; i <= center_y + param_a; i++) {
				this->Set_Color(i, center_x - param_a, Color);
			}
			for (int i = center_y - param_b; i <= center_y + param_a; i++) {
				this->Set_Color(i, center_x + param_a, Color);
			}
			this->Update_Pixel_Matrix();

		}
	}

	void Draw_Line(int start_Y, int start_X, int target_Y, int target_X, Pixel color, int Mode = Draw_Modes::DEFAULT) {
		if (Mode == Draw_Modes::DEFAULT) {
			this->BresenhamsLine(start_Y, start_X, target_Y, target_X, color);
			this->Update_Pixel_Matrix();
		}
		else if (Mode ==  Draw_Modes::ANTIALIAS_LINE) {

			int x0 = start_X;
			int y0 = start_Y;
			int x1 = target_X;
			int y1 = target_Y;

			const bool steep = abs(y1 - y0) > abs(x1 - x0);
			if (steep) {
				std::swap(x0, y0);
				std::swap(x1, y1);
			}
			if (x0 > x1) {
				std::swap(x0, x1);
				std::swap(y0, y1);
			}

			const float dx = (float)x1 - x0;
			const float dy = (float)y1 - y0;
			const float gradient = (dx == 0) ? 1 : dy / dx;

			int xpx11;
			float intery;
			{
				const float xend = (float)round(x0);
				const float yend = y0 + gradient * (xend - x0);
				const float xgap = (float)AArfpart(x0 + 0.5);
				xpx11 = int(xend);
				const int ypx11 = (int)AAipart(yend);
				if (steep) {

					Pixel Col = TRI(color, this->Get_Color(ypx11, xpx11), (AArfpart(yend) * xgap));

					Set_Color(ypx11, xpx11, Col);
					this->Pixel_Matrix[ypx11][xpx11] = Col;

					Col = TRI(color, this->Get_Color(ypx11 + 1, xpx11), (AArfpart(yend) * xgap));
					Set_Color(ypx11 + 1, xpx11, Col);
					this->Pixel_Matrix[ypx11 + 1][xpx11] = Col;

				}
				else {
					Pixel Col = TRI(color, this->Get_Color(xpx11, ypx11), (AArfpart(yend) * xgap));

					Set_Color(xpx11, ypx11, Col);
					this->Pixel_Matrix[xpx11][ypx11] = Col;

					Col = TRI(color, this->Get_Color(xpx11, ypx11 + 1), (AArfpart(yend) * xgap));
					Set_Color(xpx11, ypx11 + 1, Col);
					this->Pixel_Matrix[xpx11][ypx11 + 1] = Col;

				}
				intery = yend + gradient;
			}

			int xpx12;
			{
				const float xend = (float)round(x1);
				const float yend = y1 + gradient * (xend - x1);
				const float xgap = (float)AArfpart(x1 + 0.5);
				xpx12 = int(xend);
				const int ypx12 = (int)AAipart(yend);
				if (steep) {
					Pixel Col = TRI(color, this->Get_Color(ypx12, xpx12), (AArfpart(yend) * xgap));

					Set_Color(ypx12, xpx12, Col);
					Col = TRI(color, this->Get_Color(ypx12 + 1, xpx12), (AArfpart(yend) * xgap));
					Set_Color(ypx12 + 1, xpx12, Col);
				}
				else {

					Pixel Col = TRI(color, this->Get_Color(xpx12, ypx12), (AArfpart(yend) * xgap));

					Set_Color(xpx12, ypx12, Col);
					this->Pixel_Matrix[xpx12][ypx12] = Col;

					Col = TRI(color, this->Get_Color(xpx12, ypx12 + 1), (AArfpart(yend) * xgap));
					Set_Color(xpx12, ypx12 + 1, Col);
					this->Pixel_Matrix[xpx12][ypx12 + 1] = Col;

				}
			}

			if (steep) {
				for (int x = xpx11 + 1; x < xpx12; x++) {

					Pixel Col = TRI(color, this->Get_Color((int)AAipart(intery), x), (AArfpart(intery)));
					Set_Color((int)AAipart(intery), x, Col);
					this->Pixel_Matrix[(int)AAipart(intery)][x] = Col;

					Col = TRI(color, this->Get_Color((int)AAipart(intery) + 1, x), (AAfpart(intery)));
					Set_Color((int)AAipart(intery) + 1, x, Col);
					this->Pixel_Matrix[(int)AAipart(intery) + 1][x] = Col;

					intery += gradient;
				}
			}
			else {
				for (int x = xpx11 + 1; x < xpx12; x++) {
					Pixel Col = TRI(color, this->Get_Color(x, (int)AAipart(intery)), (AArfpart(intery)));
					Set_Color(x, (int)AAipart(intery), Col);
					this->Pixel_Matrix[x][(int)AAipart(intery)] = Col;
					Col = TRI(color, this->Get_Color(x, (int)AAipart(intery)) + 1, (AAfpart(intery)));
					Set_Color(x, (int)AAipart(intery) + 1, Col);
					this->Pixel_Matrix[x][(int)AAipart(intery) + 1] = Col;

					intery += gradient;
				}
			}


		}

	}

	void Draw_Circle(int center_x, int center_y, int c_radius, Pixel color, int Mode = Draw_Modes::HOLLOW) {

		if (Mode == Draw_Modes::FILLED) {

			int x = 0, y;
			if (center_x + c_radius > Image_Width || center_x - c_radius <0 || center_y + c_radius > Image_Height || center_y - c_radius < 0) {
				std::cout << "Line Out Of Image Range\nDraw Action Aborted\n";
				return;

			}
			for (y = -c_radius; y <= c_radius; y++) {
				for (x = -c_radius; x <= c_radius; x++) {
					if ((x * x) + (y * y) <= (c_radius * c_radius)) {
						Pixel_Matrix[center_y + y][center_x + x] = color;
						this->Set_Color(center_y + y, center_x + x, color);
					}
				}
			}
		}
		else if (Mode == Draw_Modes::HOLLOW) {
			int x, y, r2;
			if (center_x + c_radius >= this->Image_Width || center_x - c_radius <= 0 || center_y + c_radius >= this->Image_Height || center_y - c_radius <= 0) {
				std::cout << "Line Out Of Image Range\nDraw Action Aborted\n";
				return;

			}
			r2 = c_radius * c_radius;


			for (x = -c_radius; x <= c_radius; x++) {
				y = (int)(std::sqrt(r2 - x * x) + 0.5);
				this->Set_Color(center_y + y, center_x + x, color);
				this->Set_Color(center_y + y, center_x - x, color);

				Pixel_Matrix[center_y + y][center_x + x] = color;
				Pixel_Matrix[center_y + y][center_x - x] = color;
			}
			for (x = -c_radius; x <= c_radius; x++) {
				y = (int)(std::sqrt(r2 - x * x) + 0.5);
				this->Set_Color(center_y - y, center_x + x, color);
				this->Set_Color(center_y - y, center_x - x, color);
				Pixel_Matrix[center_y - y][center_x + x] = color;
				Pixel_Matrix[center_y - y][center_x - x] = color;
			}
			for (x = -c_radius; x <= c_radius; x++) {
				y = (int)(std::sqrt(r2 - x * x) + 0.5);
				this->Set_Color(center_y - x, center_x + y, color);
				this->Set_Color(center_y - x, center_x - y, color);
				Pixel_Matrix[center_y - x][center_x + y] = color;
				Pixel_Matrix[center_y - x][center_x - y] = color;
			}
		}
		else if (Mode ==  Draw_Modes::ANTIALIAS_HOLLOW) {
			if (center_x + c_radius >= this->Image_Width || center_x - c_radius <= 0 || center_y + c_radius >= this->Image_Height || center_y - c_radius <= 0) {
				std::cout << "Line Out Of Image Range\nDraw Action Aborted\n";
				return;

			}
			int x = 0, y = 0;
			double radiusX = c_radius;
			double radiusY = c_radius;
			double radiusX2 = radiusX * radiusX;
			double radiusY2 = radiusY * radiusY;
			int maxTransparency = 255;
			double quarter = (double)std::roundf((float)radiusX2 / (float)std::sqrt(radiusX2 + radiusY2));
			for (double y = 0; y <= quarter; y += 0.5) {
				double x = radiusX * std::sqrt(1 - y * y / radiusY2);
				double error = x - std::floor(x);
				int transparency = (int)std::round(error * maxTransparency);
				int alpha = transparency;
				int alpha2 = maxTransparency - transparency;

				this->AAsetPixel4((int)center_x, (int)center_y, (int)std::floor(x), (int)y, color, (double)alpha / 255);
				this->AAsetPixel4((int)center_x, (int)center_y, (int)std::floor(x) - 1, (int)y, color, (double)alpha2 / 255);
			}
			quarter = std::round(radiusX2 / std::sqrt(radiusX2 + radiusY2));
			for (double x = 0; x <= quarter; x += 0.5) {
				double y = radiusY * std::sqrt(1 - x * x / radiusX2);
				double error = y - std::floor(y);
				float transparency = std::roundf((float)error * (float)maxTransparency);
				int alpha = (int)transparency;
				int alpha2 = (int)(maxTransparency - transparency);


				this->AAsetPixel4((int)center_x, (int)center_y, (int)x, (int)std::floor(y), color, (double)alpha / 255);
				this->AAsetPixel4((int)center_x, (int)center_y, (int)x, (int)std::floor(y) - 1, color, (double)alpha2 / 255);
			}




		}
		else if (Mode == Draw_Modes::ANTIALIAS_FILLED) {
			this->Draw_Circle(center_x, center_y, c_radius - 1, color, Draw_Modes::FILLED);
			this->Draw_Circle(center_x, center_y, c_radius, color,  Draw_Modes::ANTIALIAS_HOLLOW);

		}
	}



	void Draw_Text(int const &y, int const &x, const std::string& sText, Pixel const &col = Pixel(0,0,0), uint32_t scale = 1) {

		int32_t sx = 0;
		int32_t sy = 0;
		Font_Sprite FSPRITE;
		for (auto c : sText)
		{
			if (c == '\n')
			{
				sx = 0; sy += 8 * scale;
			}
			else
			{
				int32_t ox = (c - 32) % 16;
				int32_t oy = (c - 32) / 16;

				if (scale > 1)
				{
					for (uint32_t i = 0; i < 8; i++)
						for (uint32_t j = 0; j < 8; j++)
							if (FSPRITE.font_s[j + oy * 8][i + ox * 8].r > 0)
								for (uint32_t is = 0; is < scale; is++)
									for (uint32_t js = 0; js < scale; js++)
										this->Set_Color(y + sy + (j*scale) + js, x + sx + (i*scale) + is, col);
				}
				else
				{
						for (uint32_t i = 0; i < 8; i++)
							for (uint32_t j = 0; j < 8; j++)
								if (FSPRITE.font_s[j + oy * 8][i + ox * 8].r > 0)
									this->Set_Color(y + sy + j, x + sx + i, col);
					

				}
				sx += 8 * scale;
			}
		}

	}

	void Grayscale(int alter) {
		for (int i = 0; i < Image_Height; i++) {

			for (int j = 0; j < Image_Width; j++) {
				double val = this->Pixel_Matrix[i][j].r*0.29 + this->Pixel_Matrix[i][j].g*0.59 + this->Pixel_Matrix[i][j].b*0.11;
				this->Pixel_Matrix[i][j].r = (int)std::round(val);
				this->Pixel_Matrix[i][j].g = (int)std::round(val);
				this->Pixel_Matrix[i][j].b = (int)std::round(val);
			}
		}
		if (alter == 1) {
			this->Commint_Matrix_Changes();
		}
	}

	double Image_Difference_Value(Image b) {

		double result = 0;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				result = result + Color_DistanceSq(Pixel_Matrix[i][j], b.Pixel_Matrix[i][j]);
			}
		}
		return result / Image_Height * Image_Width;

	}
	bool Distance_Neighbors(double max_distance, int i, int j) {
		Pixel center, point;
		center = Pixel_Matrix[i][j];
		double dist = 0;
		if (i - 1 < 0 && j + 1 < this->Image_Width && j - 1 > 0 && i + 1 < Image_Height) {
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
		if (i + 1 > Image_Height && j + 1 < Image_Width && j - 1 > 0 && i - 1 > 0)
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
		if (j - 1 < 0 && i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width) {
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
		if (j + 1 > Image_Width && i + 1 < Image_Height && i - 1 > 0 && j - 1 > 0) {
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
	double Get_Neighbour_Mean_R(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r;

		if (i + 1 <= this->Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].r;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].r;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
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
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r;
			Divider++;
		}
		return Mean / Divider;

	}
	double Get_Neighbour_Mean_G(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].g;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].g;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
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
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g;
			Divider++;
		}
		return Mean / Divider;

	}
	double Get_Neighbour_Mean_B(int i, int j) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b;

		if (i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j].b;
			Divider++;
		}
		if (i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j].b;
			Divider++;

		}
		if (j + 1 <= Image_Width) {
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
		if (j - 1 >= 0 && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i + 1 <= Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b;
			Divider++;
		}
		if (j + 1 <= Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b;
			Divider++;
		}
		return Mean / Divider;
	}
	double Get_Neighbour_Mean_G(int i, int j, Matrix<double> Kernel, double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].g * Kernel[1][1];

		if (i + 1 < Image_Height) {
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
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].g * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].g * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].g * Kernel[0][0];
			Divider++;

		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].g * Kernel[2][0];
			if (Kernel[2][0] != 0) {
				Divider++;
			}
		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].g * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].g * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	double Get_Neighbour_Mean_R(int i, int j, Matrix<double> Kernel, double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].r * Kernel[1][1];

		if (i + 1 < Image_Height) {
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
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].r * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].r * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].r * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].r * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].r * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].r * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	double Get_Neighbour_Mean_B(int i, int j, Matrix<double> Kernel, double Kernel_Normal) {
		double Mean = 0;
		int Divider = 1;
		Mean += Pixel_Matrix[i][j].b * Kernel[1][1];

		if (i + 1 < Image_Height) {
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
		if (j + 1 < Image_Width) {
			Mean += Pixel_Matrix[i][j + 1].b * Kernel[1][2];
			if (Kernel[1][2] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0) {
			Mean += Pixel_Matrix[i][j - 1].b * Kernel[1][0];
			if (Kernel[1][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j - 1].b * Kernel[0][0];
			if (Kernel[0][0] != 0) {
				Divider++;
			}
		}
		if (j - 1 >= 0 && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j - 1].b * Kernel[2][0];
			Divider++;

		}
		if (j + 1 < Image_Width && i + 1 < Image_Height) {
			Mean += Pixel_Matrix[i + 1][j + 1].b * Kernel[2][2];
			Divider++;

		}
		if (j + 1 < Image_Width && i - 1 >= 0) {
			Mean += Pixel_Matrix[i - 1][j + 1].b * Kernel[0][2];
			Divider++;

		}
		return Mean / Divider;

	}
	std::vector<Pixel*> &Get_4_Neighbours(int const &i, int const &j) {
		std::vector<Pixel*> N4;
		if (i == 0) {
			N4.push_back(nullptr);
		}
		else {
			N4.push_back(&this->Pixel_Matrix[i - 1][j]);
		}
		if (j == 0) {
			N4.push_back(nullptr);

		}
		else {
			N4.push_back(&this->Pixel_Matrix[i][j - 1]);
		}
		if (i == this->Image_Height - 1) {
			N4.push_back(nullptr);

		}
		else {
			N4.push_back(&this->Pixel_Matrix[i + 1][j]);

		}
		if (j == this->Image_Width + -1) {
			N4.push_back(nullptr);
		}
		else {
			N4.push_back(&this->Pixel_Matrix[i][j + 1]);

		}
		return N4;

	}
	std::vector<Pixel*> &Get_D_Neighbours(int const &i, int const &j) {
		std::vector<Pixel*> N4;
		if (i == 0 || j ==0) {
			N4.push_back(nullptr);
		}
		else {
			N4.push_back(&this->Pixel_Matrix[i - 1][j-1]);
		}
		if (j == 0 || i == Image_Height -1) {
			N4.push_back(nullptr);

		}
		else {
			N4.push_back(&this->Pixel_Matrix[i+1][j - 1]);
		}
		if (i == 0 || j == this->Image_Width-1) {
			N4.push_back(nullptr);

		}
		else {
			N4.push_back(&this->Pixel_Matrix[i - 1][j+1]);

		}
		if (j == this->Image_Width + -1 || i == Image_Height-1) {
			N4.push_back(nullptr);
		}
		else {
			N4.push_back(&this->Pixel_Matrix[i+1][j + 1]);

		}
		return N4;

	}

	void Mark_Identical_Pixels(Pixel Target) {
		Color_Palette cset;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (Pixel_Matrix[i][j] == Target) {
					this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
				}
			}
		}

	}
	void Mark_Identical_Pixels(Image Source) {
		Color_Palette cset;

		if (this->Image_Width*this->Image_Height <= Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
					}
				}
			}
		}
		else if (this->Image_Width*this->Image_Height > Source.Image_Height * Source.Image_Width) {
			for (int i = 0; i < Source.Image_Height; i++) {
				for (int j = 0; j < Source.Image_Width; j++) {
					if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
						this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
					}
				}
			}
		}

	}
	void Mark_Identical_Pixels(Image Source, std::string mode) {
		Color_Palette cset;
		if (mode == "Strict") {//strict
			if (this->Image_Width*this->Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
						}
					}
				}
			}
			else if (this->Image_Width*this->Image_Height > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j]) {
							this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
						}
					}
				}
			}
		}
		else if (mode == ("Loose")) {//loose

			if (this->Image_Width*this->Image_Height <= Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Image_Height; i++) {
					for (int j = 0; j < Image_Width; j++) {
						if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
						}
					}
				}
			}
			else if (this->Image_Width*this->Image_Height > Source.Image_Height * Source.Image_Width) {
				for (int i = 0; i < Source.Image_Height; i++) {
					for (int j = 0; j < Source.Image_Width; j++) {
						if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) < 50) {
							this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
						}
					}
				}
			}
		}
	}
	void Mark_Different_Pixels(Image Source, int Color_Treshold, int Distnace_Treshold, Pixel frame_color) {


		if (this->Image_Width != Source.Image_Width || this->Image_Height != Source.Image_Height) {
			return;
		}

		std::vector<Blob> Blobs;
		bool detected = false;

		for (int i = 0; i < this->Image_Width; i++)
		{
			for (int j = 0; j < this->Image_Height; j++)
			{

				if (Color_Delta(this->Pixel_Matrix[j][i], Source.Pixel_Matrix[j][i]) > Color_Treshold)
				{
					for (int m = 0; m < Blobs.size(); ++m) {
						if (Blobs[m].Near(i, j)) {
							Blobs[m].add(i, j);
							detected = true;
							break;
						}

					}

					if (!detected) {
						//temp.SetProps(i, j);
						Blobs.push_back(Blob(i, j, Distnace_Treshold));
					}
					detected = false;
				}
			}
		}



		for (int m = 0; m < Blobs.size(); ++m) {
			this->Draw_Square(Blobs[m].Upleft_Y, Blobs[m].Upleft_X, Blobs[m].Downright_Y, Blobs[m].Downright_X, frame_color, Draw_Modes::CORNERS);
		}




	}
	void Write_Pixel_Difference(Image Source, std::string mode, int min_diff) {

		if (mode == ("Copy")) {
			if (this->Image_Width != Source.Image_Width || this->Image_Height != Source.Image_Height) {
				return;
			}
			Image Temp(*this);
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					if (Color_Distance(Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > min_diff) {
						Temp.Pixel_Matrix[i][j] = Source.Pixel_Matrix[i][j];
					}
				}
			}
			this->Write_Image("Pixel_Diffrence.jpg");
		}
		else {
			return;
		}
	}
	void Mark_Different_Pixels(Image Source) {
		if (this->Image_Width != Source.Image_Width || this->Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				if (Color_Distance(this->Pixel_Matrix[i][j], Source.Pixel_Matrix[i][j]) > 2) {
					this->Draw_Square(i, j, 2, 2, cset.Red, Draw_Modes::HOLLOW);
				}
			}
		}


	}
	void Mark_Different_Pixels(Image Source, std::string mode) {



		if (this->Image_Width != Source.Image_Width || this->Image_Height != Source.Image_Height) {
			return;
		}
		Color_Palette cset;
		if (mode == ("Strict")) {
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					if (!(Pixel_Matrix[i][j] == Source.Pixel_Matrix[i][j])) {
						this->Draw_Square(j, i, 2, 2, cset.Red, Draw_Modes::HOLLOW);
					}
				}
			}
		}

	}
	void Write_Channel_Row_Level_Graph() {
		int posR, PosG, PosB, H = 500, W = 1300;
		int bar_width = this->Image_Width / 300;
		if (bar_width == 0) {
			bar_width = 1;
		}
		int sR = 0, sG = 0, sB = 0;
		Image frame;
		Color_Palette CSET;
		frame.Load_Blank_Canvas(H, W, CSET.Azure);

		frame.Draw_Square(250, 250, 150, 150, CSET.Black);
		frame.Draw_Square(650, 250, 150, 150, CSET.Black);
		frame.Draw_Square(1050, 250, 150, 150, CSET.Black);
		frame.Draw_Square(250, 250, 151, 151, CSET.Black);
		frame.Draw_Square(650, 250, 151, 151, CSET.Black);
		frame.Draw_Square(1050, 250, 151, 151, CSET.Black);

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

		frame.Draw_Text(90, 240, "RED GRAPH", CSET.Black);
		frame.Draw_Text(90, 640, "GREEN GRAPH", CSET.Black);
		frame.Draw_Text(90, 1040, "BLUE GRAPH", CSET.Black);


		posR = 101;
		PosG = 501;
		PosB = 901;



		for (int i = 0; i < this->Image_Width; i++) {
			for (int k = 0; k < bar_width; k++) {
				for (int j = 0; j < this->Image_Height; j++) {
					if (Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].g &&Pixel_Matrix[j][i].r >= Pixel_Matrix[j][i].b &&
						Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {

						sR++;
					}
					else if (Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].g >= Pixel_Matrix[j][i].b
						&& Pixel_Matrix[j][i] != CSET.Black
						&&Pixel_Matrix[j][i] != CSET.White) {
						//sG += Pixel_Matrix[j][i].g;
						sG++;
					}
					else if (Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].r &&Pixel_Matrix[j][i].b >= Pixel_Matrix[j][i].g
						&& Pixel_Matrix[j][i] != CSET.Black
						&& Pixel_Matrix[j][i] != CSET.White) {
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
				//frame.Draw_Line(posR, 399, 399 - sR, CSET.Red,bar_width);
				frame.Draw_Line(399, posR, (int)(399 - sR), posR, CSET.Red, (int)std::fmax(1, bar_width / 3));
			}
			if (PosG < 799) {
				//frame.Draw_Line(PosG, 399, 399 - sG, CSET.Green);
				frame.Draw_Line(399, PosG, 399 - sG, PosG, CSET.Green, (int)std::fmax(1, bar_width / 3));

			}
			if (PosB < 1199) {
				//frame.Draw_Line(PosB, 399, 399 - sB, CSET.Blue);
				frame.Draw_Line(399, PosB, 399 - sB, PosB, CSET.Blue, (int)std::fmax(1, bar_width / 3));

			}

			posR += bar_width;
			PosG += bar_width;
			PosB += bar_width;

			sR = sG = sB = 0;

		}



		frame.Write_Image("ChannelGraph.png");
	}
	void Write_Channel(char color) {

		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].b = 0;

				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].r = 0;
					Pixel_Matrix[i][j].b = 0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {
					Pixel_Matrix[i][j].g = 0;
					Pixel_Matrix[i][j].r = 0;

				}
			}
			break;
		default:
			break;
		}


	}

	void Shutdown_Channel(char color) {

		switch (color)
		{
		case 'R':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].r = 0;
				}
			}
			break;
		case 'G':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].g = 0;

				}
			}
			break;
		case 'B':
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 0; j < Image_Width; j++) {

					Pixel_Matrix[i][j].b = 0;
				}
			}
			break;
		default:
			break;
		}
	}
	void Flip180() {
		Image temp;
		temp.Load_Blank_Canvas(this->Image_Height, this->Image_Width, Pixel(0, 0, 0));
		int k = 0, m = 0;

		for (int i = Image_Height - 1; i >= 0; i--) {
			for (int j = Image_Width - 1; j >= 0; j--) {
				temp.Pixel_Matrix[k][m] = this->Pixel_Matrix[i][j];
				m++;
			}

			k++;
			m = 0;

		}

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				this->Pixel_Matrix[i][j] = temp.Pixel_Matrix[i][j];

			}
		}
	}
	void Color_Flooring(std::string mode, int alter) {

		if (mode == ("10")) {
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					this->Pixel_Matrix[i][j].r = (this->Pixel_Matrix[i][j].r / 10) * 10;
					this->Pixel_Matrix[i][j].g = (this->Pixel_Matrix[i][j].g / 10) * 10;
					this->Pixel_Matrix[i][j].b = (this->Pixel_Matrix[i][j].b / 10) * 10;

				}
			}



		}
		else if (mode == ("100")) {

			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					this->Pixel_Matrix[i][j].r = (this->Pixel_Matrix[i][j].r / 100) * 100;
					this->Pixel_Matrix[i][j].g = (this->Pixel_Matrix[i][j].g / 100) * 100;
					this->Pixel_Matrix[i][j].b = (this->Pixel_Matrix[i][j].b / 100) * 100;

				}
			}

		}
		if (alter == 1) {
			this->Commint_Matrix_Changes();
		}
	}
	void Thresholding(std::string mode, int value, int alter) {

		if (mode == ("Trunc")) {

			this->Color_Flooring("10", 1);
			for (int i = 0; i < Image_Height; i++) {
				for (int j = 1; j < Image_Width; j++) {
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

		}

		else if (mode == ("EdgeTriggerd")) {
			Pixel prev;

			for (int i = 0; i < Image_Height; i++) {
				prev.r = Pixel_Matrix[i][0].r;
				prev.g = Pixel_Matrix[i][0].g;
				prev.b = Pixel_Matrix[i][0].b;

				Pixel_Matrix[i][0].r = 0;
				Pixel_Matrix[i][0].g = 0;
				Pixel_Matrix[i][0].b = 0;

				for (int j = 1; j < Image_Width; j++) {
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

		}
		if (alter == 1) {
			this->Commint_Matrix_Changes();
		}

	}
	void Thresholding(int alter) {
		this->Grayscale(alter);
		//using otsus method
		std::vector<int> Histogram(256, 0);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Histogram[this->Pixel_Matrix[i][j].r]++;
			}
		}
		int total = this->Image_Height*this->Image_Width;
		float sum = 0;
		for (int t = 0; t < 256; t++) sum += t * Histogram[t];
		float varMax = 0;
		int threshold = 0;
		float sumB = 0;
		int wB = 0;
		int wF = 0;
		for (int t = 0; t < 256; t++) {
			wB += Histogram[t];               // Weight Background
			if (wB == 0) continue;

			wF = total - wB;                 // Weight Foreground
			if (wF == 0) break;

			sumB += (float)(t * Histogram[t]);

			float mB = sumB / wB;            // Mean Background
			float mF = (sum - sumB) / wF;    // Mean Foreground

			// Calculate Between Class Variance
			float varBetween = (float)wB * (float)wF * (mB - mF) * (mB - mF);

			// Check if new maximum found
			if (varBetween > varMax) {
				varMax = varBetween;
				threshold = t;
			}
		}

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (this->Pixel_Matrix[i][j].r <= threshold) {
					this->Pixel_Matrix[i][j] = Pixel(0, 0, 0);

				}
				else {
					this->Pixel_Matrix[i][j] = Pixel(255, 255, 255);

				}
			}
		}


		if (alter == 1) {
			this->Commint_Matrix_Changes();
		}

	}
	void Edge_Detection() {
		Pixel prev;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
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


	}
	void Edge_Detection(int max_color_gap) {

		Pixel prev;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			Pixel_Matrix[i][0].r = 0;
			Pixel_Matrix[i][0].g = 0;
			Pixel_Matrix[i][0].b = 0;

			for (int j = 1; j < Image_Width; j++) {
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
	}
	void Mark_Contour(Pixel Color, int max_color_gap) {
		Pixel prev;

		for (int i = 0; i < Image_Height; i++) {
			prev.r = Pixel_Matrix[i][0].r;
			prev.g = Pixel_Matrix[i][0].g;
			prev.b = Pixel_Matrix[i][0].b;

			for (int j = 1; j < Image_Width; j++) {
				if (Color_Distance(prev, Pixel_Matrix[i][j]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;

					Pixel_Matrix[i][j] = Color;



				}
				else {
					prev.r = Pixel_Matrix[i][j].r;
					prev.g = Pixel_Matrix[i][j].g;
					prev.b = Pixel_Matrix[i][j].b;



				}

			}
		}

		for (int i = 0; i < Image_Width; i++) {
			prev.r = Pixel_Matrix[0][i].r;
			prev.g = Pixel_Matrix[0][i].g;
			prev.b = Pixel_Matrix[0][i].b;

			for (int j = 1; j < Image_Height; j++) {
				if (Color_Distance(prev, Pixel_Matrix[j][i]) > max_color_gap)
				{
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;

					Pixel_Matrix[j][i] = Color;



				}
				else {
					prev.r = Pixel_Matrix[j][i].r;
					prev.g = Pixel_Matrix[j][i].g;
					prev.b = Pixel_Matrix[j][i].b;



				}

			}
		}

	}
	void Feature_Matching(int source_x, int source_y) {
		if ((source_x + 1 > Image_Width) || (source_x - 1 < 0) || (source_y + 1 > Image_Height) || (source_y - 1 < 0)) {
			//out of image border;
			return;
		}
		Pixel up, down, left, right, center;
		Color_Palette cset;
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

		Draw_Circle(source_x, source_y, 3, cset.Red);
		Draw_Circle(source_x, source_y, 2, cset.Blue);


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (i + 1 < Image_Height && i - 1 > 0 && j + 1 < Image_Width && j - 1 > 0) {
					if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], down) < band &&Color_Distance(Pixel_Matrix[i - 1][j], up) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], right) < band &&Color_Distance(Pixel_Matrix[i][j - 1], left) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);
					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
					else if (Color_Distance(Pixel_Matrix[i][j], center) < band && Color_Distance(Pixel_Matrix[i + 1][j], left) < band &&Color_Distance(Pixel_Matrix[i - 1][j], right) < band
						&&Color_Distance(Pixel_Matrix[i][j + 1], down) < band &&Color_Distance(Pixel_Matrix[i][j - 1], up) < band) {
						Draw_Circle(j, i, 3, cset.Red);
						Draw_Line(source_y, source_x, i, j, cset.Blue);

					}
				}
			}
		}



	}
	void Quarantine_Pixel(Pixel sample, double max_difference, std::string mode) {

		if (mode == ("Keep_Self")) {
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) > max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}

		}
		else if (mode == ("Drop_Self")) {
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					if (Color_DistanceSq(Pixel_Matrix[i][j], sample) < max_difference) {
						Pixel_Matrix[i][j].r = 0;
						Pixel_Matrix[i][j].g = 0;
						Pixel_Matrix[i][j].b = 0;

					}
				}
			}

		}
	}
	void Kronecker_product(Image b, std::string mode, int Alter) {
		if (mode == "Mul") {
			std::vector<std::vector<Pixel> > Kronecker_pixel_mat(b.Image_Height);
			for (int i = 0; i < b.Image_Height; i++) {
				Kronecker_pixel_mat[i] = std::vector<Pixel>(b.Image_Width);
			}
			unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Image_Height*b.Image_Height*b.Image_Width*this->Image_Width * 3));
			unsigned long long startRow, startCol, index = 0;
			Pixel temp;
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
							temp = this->Pixel_Matrix[i][j] * b.Pixel_Matrix[k][l];
							Kronecker_pixel_mat[startRow + k][startCol + l] = temp;

						}
					}
				}
			}

			if (Alter == 1) {
				this->Image_Width *= b.Image_Width;
				this->Image_Height *= b.Image_Height;
				stbi_image_free(this->image_data);

				this->Pixel_Matrix = Kronecker_pixel_mat;
				for (long long i = 0; i < this->Image_Height; i++) {
					for (long long j = 0; j < this->Image_Width; j++) {
						Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

					}
				}
				this->image_data = Kronecker;
				std::free(Kronecker);

			}


		}
		else if (mode == "Size") {
			std::vector<std::vector<Pixel> > Kronecker_pixel_mat(b.Image_Height);
			for (int i = 0; i < b.Image_Height; i++) {
				Kronecker_pixel_mat[i] = std::vector<Pixel>(b.Image_Width);
			}
			unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Image_Height*b.Image_Height*b.Image_Width*this->Image_Width * 3));
			unsigned long long startRow, startCol, index = 0;
			Pixel temp;

			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
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
				this->Image_Width *= b.Image_Width;
				this->Image_Height *= b.Image_Height;
				stbi_image_free(this->image_data);

				this->Pixel_Matrix = Kronecker_pixel_mat;
				for (long long i = 0; i < this->Image_Height; i++) {
					for (long long j = 0; j < this->Image_Width; j++) {
						Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

					}
				}
				this->image_data = Kronecker;
				std::free(Kronecker);

			}
		}
		else if (mode == "Build_From") {

			std::vector<std::vector<Pixel> > Kronecker_pixel_mat(b.Image_Height);
			for (int i = 0; i < b.Image_Height; i++) {
				Kronecker_pixel_mat[i] = std::vector<Pixel>(b.Image_Width);
			}
			unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Image_Height*b.Image_Height*b.Image_Width*this->Image_Width * 3));
			unsigned long long startRow, startCol, index = 0;
			Pixel temp;

			int flag = 0;
			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++) {
						for (int l = 0; l < b.Image_Width; l++) {
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
				this->Image_Width *= b.Image_Width;
				this->Image_Height *= b.Image_Height;
				stbi_image_free(this->image_data);

				this->Pixel_Matrix = Kronecker_pixel_mat;
				for (long long i = 0; i < this->Image_Height; i++) {
					for (long long j = 0; j < this->Image_Width; j++) {
						Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

					}
				}
				this->image_data = Kronecker;
				std::free(Kronecker);

			}
		}
		else if (mode == "Mix") {

			std::vector<std::vector<Pixel> > Kronecker_pixel_mat(b.Image_Height);
			for (int i = 0; i < b.Image_Height; i++) {
				Kronecker_pixel_mat[i] = std::vector<Pixel>(b.Image_Width);
			}
			unsigned char *Kronecker = (unsigned char*)malloc(sizeof(unsigned char)*(this->Image_Height*b.Image_Height*b.Image_Width*this->Image_Width * 3));
			unsigned long long startRow, startCol, index = 0;
			Pixel temp;

			int flag = 1;

			for (int i = 0; i < this->Image_Height; i++) {

				for (int j = 0; j < this->Image_Width; j++)
				{
					startRow = i * b.Image_Height;
					startCol = j * b.Image_Width;
					for (int k = 0; k < b.Image_Height; k++)
					{
						if (flag == 1) {
							temp = this->Pixel_Matrix[i][j];
						}
						else if (flag == 0) {
							temp = b.Pixel_Matrix[i][j];
						}

						for (int l = 0; l < b.Image_Width; l++)
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
				this->Image_Width *= b.Image_Width;
				this->Image_Height *= b.Image_Height;
				stbi_image_free(this->image_data);

				this->Pixel_Matrix = Kronecker_pixel_mat;
				for (long long i = 0; i < this->Image_Height; i++) {
					for (long long j = 0; j < this->Image_Width; j++) {
						Kronecker[index++] = Kronecker_pixel_mat[i][j].r;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].g;
						Kronecker[index++] = Kronecker_pixel_mat[i][j].b;

					}
				}
				this->image_data = Kronecker;
				std::free(Kronecker);

			}
		}



	}
	void Image_Transpose() {
		int H = this->Image_Width, W = this->Image_Height;
		std::vector < std::vector<Pixel> > tmat(H);
		for (int i = 0; i < H; i++) {
			tmat[i] = std::vector<Pixel>(W);
		}

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				tmat[j][i] = this->Pixel_Matrix[i][j];
			}
		}

		this->Pixel_Matrix = tmat;


	}
	double Pixel_Dataframe_Difference(Pixel Pix, Point<double> DF_point) {
		double distance;
		distance = ((DF_point[0] - Pix.r)*(DF_point[0] - Pix.r) + (DF_point[1] - Pix.g)*(DF_point[1] - Pix.g) + (DF_point[2] - Pix.b)*(DF_point[2] - Pix.b));
		return std::sqrt(distance);
	}
	void Image_Segmentation(int k, int iterations) {

		std::vector<Point<double> > image_ThreeD_Mat;
		std::vector<Point<double> > Result;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				image_ThreeD_Mat.push_back(Point<double>({ (double)this->Pixel_Matrix[i][j].r, (double)this->Pixel_Matrix[i][j].g,(double)this->Pixel_Matrix[i][j].b }));
			}
		}

		Result = this->K_Means(image_ThreeD_Mat, k, iterations);


		double best_dist;
		Point<double> temp;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = std::numeric_limits<double>::max();

				for (int m = 0; m < Result.size(); m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Result[m]) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Result[m]);
						temp = Result[m];
					}
				}

				Pixel_Matrix[i][j].r = (int)temp[0];
				Pixel_Matrix[i][j].g = (int)temp[1];
				Pixel_Matrix[i][j].b = (int)temp[2];

			}
		}






	}
	void Blob_Framing(int distance_treshold, Pixel frame_color) {
		Color_Palette CSET;
		std::vector<Blob> Blobs;

		Blob temp = Blob(0, 0, distance_treshold);
		bool detected = false;
		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {

				if (this->Pixel_Matrix[i][j].analysis == 42) {

					for (int k = 0; k < (int)Blobs.size(); ++k) {
						if (Blobs[k].Near(i, j) == true) {
							Blobs[k].add(i, j);
							detected = true;

							break;

						}

					}

					if (detected == false) {
						temp.SetProps(i, j);
						Blobs.push_back(Blob(temp));
					}

					detected = false;

				}
			}
		}

		for (int k = 0; k < (int)Blobs.size(); k++) {
			if (Blobs[k].Size() < distance_treshold) {

				Blobs.erase(Blobs.begin() + k);
			}

		}

		for (int k = 0; k < (int)Blobs.size(); ++k) {

			Draw_Square(Blobs[k].Downright_X, Blobs[k].Downright_Y, Blobs[k].Upleft_X, Blobs[k].Upleft_Y, frame_color, Draw_Modes::CORNERS);
			//Pixel_Matrix[Blobs.get(k).Upleft_X][Blobs.get(k).Upleft_Y] = new Pixel(CSET[1]ellow);
			//Pixel_Matrix[Blobs.get(k).Downright_X][Blobs.get(k).Downright_Y] = new Pixel(CSET.Green);


			
		}
	}

	void Figure_Detection(int blob_distance_treshold, int color_distance_treshold, int Thresholding_level) {

		this->Thresholding("Trunc", Thresholding_level, 0);

		std::vector<std::vector<int> > adj_matrix(Image_Height);
		for (int i = 0; i < this->Image_Height; i++) {
			adj_matrix[i] = std::vector<int>(Image_Width);
		}

		int color_treshold = color_distance_treshold;
		Color_Palette C;
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				adj_matrix[i][j] = 0;
			}
		}

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width - 1; j++) {
				if (Color_Delta(Pixel_Matrix[i][j], Pixel_Matrix[i][j + 1]) > color_treshold) {
					adj_matrix[i][j] = 1;


				}
			}
		}


		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (adj_matrix[i][j] == 1) {
					Pixel_Matrix[i][j].analysis = 42;
				}
			}
		}

		this->Blob_Framing(blob_distance_treshold, C.Red);
		this->Update_Pixel_Matrix();
	}
	void Write_Average_Color_Palette(int palette_size) {
		int H, W, lx;
		Color_Palette CSET;
		Pixel palette_sample;
		std::vector<Point<double> > imData, Means;
		Image palette_image;



		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				imData.push_back(Point<double>({ (double)this->Pixel_Matrix[i][j].r, (double)this->Pixel_Matrix[i][j].g, (double)this->Pixel_Matrix[i][j].b }));
			}
		}


		Means = K_Means(imData, palette_size, 200);
		H = 200;
		W = 200 * palette_size;
		palette_image.Load_Blank_Canvas(H, W, CSET.Black);
		lx = 0;

		for (int m = 0; m < Means.size(); m++) {
			palette_sample.r = (int)Means[m][0];
			palette_sample.g = (int)Means[m][1];
			palette_sample.b = (int)Means[m][2];

			for (int j = 0; j < 199; j++) {
				palette_image.Draw_Line(j, lx, j, lx + 199, palette_sample);


			}


			lx += 199;
		}

		palette_image.Write_Image(palette_size + " Bit Palette.png");

	}
	void Pixel_Griding() {
		double sigma = 1.0;
		double r, s = 2.0 * sigma * sigma;
		Matrix<double> GKernel(5, 5);
		double sum = 0.0;
		for (int x = -2; x <= 2; x++) {
			for (int y = -2; y <= 2; y++) {
				r = std::sqrt(x * x + y * y);
				GKernel[x + 2][y + 2] = (std::exp(-(r * r) / s)) / (std::_Pi * s);
				sum += GKernel[x + 2][y + 2];
			}
		}

		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				GKernel[i][j] /= sum;
			}
		}


		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				Pixel_Matrix[i][j].r += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].r;
				Pixel_Matrix[i][j].g += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].g;
				Pixel_Matrix[i][j].b += (int)GKernel[i % 5][j % 5] * Pixel_Matrix[i][j].b;

			}
		}



	}
	std::vector<Point<double> > Get_Average_Color_Palette(int palette_size, int number_of_iterations) {
		std::vector<Point<double> > imData;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				imData.push_back(Point<double>({ (double)this->Pixel_Matrix[i][j].r, (double)this->Pixel_Matrix[i][j].g, (double)this->Pixel_Matrix[i][j].b }));
			}
		}


		return this->K_Means(imData, palette_size, number_of_iterations);

	}

	void Set_Colors_Using_Average_Palette(std::vector<Point<double> > Average_Colors) {
		double best_dist;
		Point<double> temp;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {
				best_dist = std::numeric_limits<double>::max();


				for (int m = 0; m < Average_Colors.size(); m++) {
					if (Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors[m]) < best_dist) {
						best_dist = Pixel_Dataframe_Difference(Pixel_Matrix[i][j], Average_Colors[m]);
						temp[0] = Average_Colors[m][0];
						temp[1] = Average_Colors[m][1];
						temp[2] = Average_Colors[m][2];

					}
				}

				Pixel_Matrix[i][j] = Pixel((int)temp[0], (int)temp[1], (int)temp[2]);


			}



		}




	}
	std::vector<Pixel> Get_Line_Pixels(int start_y, int start_x, int target_y, int target_x) {
		double dx, sx, dy, sy, err, e2;

		std::vector<Pixel> Points;
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(std::abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-std::abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.push_back(Pixel(Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].r, Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].g,
					Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].b, (int)std::floor(x0), (int)std::floor(x0)));
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.push_back(Pixel(Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].r, Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].g,
				Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].b, (int)std::floor(x0), (int)std::floor(x0)));

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
	void Register_PixelFrame(std::vector<Pixel> Frame) {
		Pixel color;
		for (int i = 0; i < Frame.size(); i++) {
			this->Pixel_Matrix[Frame[i].i][Frame[i].j] = Frame[i];
		}
	}
	Pixel Dominant_Color_Via_Line(int start_y, int start_x, int target_y, int target_x) {
		double dx, sx, dy, sy, err, e2;
		Pixel Dom_Color;
		std::vector<Point<double> > Points;
		std::vector<Point<double> > Res;
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)std::abs(target_y - start_y);
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-std::abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
				Points.push_back(Point<double>({ (double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].r, (double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].g,
					(double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].b }));
				break;
			}

			//dots.push_back(this->Pixel_Matrix[(int)floor(x0)][(int)floor(y0)]);
			Points.push_back(Point<double>({ (double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].r, (double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].g,
				(double)Pixel_Matrix[(int)std::floor(x0)][(int)std::floor(y0)].b }));

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
		Dom_Color.r = (int)Res[0][0];
		Dom_Color.g = (int)Res[0][1];
		Dom_Color.b = (int)Res[0][2];

		return Dom_Color;
	}
	void Image_Rebuild_With_Lines(int Iterations) {
		Random_Utilitis rnd;

		Color_Palette CSET;
		Pixel dominant_color;
		std::vector<Pixel> Line;
		Image B, C;
		B.Load_Blank_Canvas(this->Image_Height, this->Image_Width, CSET.Black);
		C.Load_Blank_Canvas(this->Image_Height, this->Image_Width, CSET.Black);

#ifdef Line_StepByStep



		std::stringstream ss;
		std::string via;
		int counter = 0;

#endif

		int x0, y0, x1, y1;
		double cur_difference, temp_dif;

		cur_difference = this->Image_Difference_Value(B);

		for (int i = 0; i < Iterations; i++) {
			x0 = rnd.Random_INT(0, (Image_Width));
			y0 = rnd.Random_INT(0, (Image_Height));
			x1 = rnd.Random_INT(0, (Image_Width));
			y1 = rnd.Random_INT(0, (Image_Height));



			dominant_color = this->Dominant_Color_Via_Line(y0, x0, y1, x1);
			Line = B.Get_Line_Pixels(y0, x0, y1, x1);
			B.Draw_Line(y0, x0, y1, x1, dominant_color);


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


			}
			else {
				B.Register_PixelFrame(Line);
				Line.clear();

			}


		}

		C.Write_Image("Build_From_Random_Lines.png");



	}

	std::vector<Point<double> > GetCoordinateFrame(int start_y, int start_x, int target_y, int target_x) {
		double dx, sx, dy, sy, err, e2;

		std::vector<Point<double> > Points;
		double x0 = (double)start_y, x1 = (double)target_y, y0 = (double)start_x, y1 = (double)target_x;
		dx = (double)(std::abs(target_y - start_y));
		sx = (double)(start_y < target_y ? 1 : -1);
		dy = (double)(-std::abs(target_x - start_x));
		sy = (double)(start_x < target_x ? 1 : -1);
		err = dx + dy;  //error value
		while (true) {
			if (x0 == x1 && y0 == y1) {
				Points.push_back(Point<double>({ x0, y0, 0 }));
				break;
			}

			Points.push_back(Point<double>({ x0, y0, 0 }));

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
	void Up_Scale() {

		//BufferedImage scaled = new BufferedImage(this->Image_Width * 3,	this->Image_Height * 3,BufferedImage.TYPE_3BYTE_BGR);


		Image scaled;
		int p = 0, z = 0;
		scaled.Load_Blank_Canvas((Image_Height * 3), (Image_Width * 3), Pixel(0, 0, 0));
		for (int i = 0; i < scaled.Image_Height; i += 3) {
			for (int j = 0; j < scaled.Image_Width; j += 3) {
				for (int k = 0; k < 3; k++) {
					for (int m = 0; m < 3; m++) {
						scaled.Pixel_Matrix[i + k][j + m] = Pixel(this->Pixel_Matrix[p][z]);
					}
				}
				z++;
			}
			p++;
			z = 0;
		}




		//quality enchancment


		for (int i = 0; i < this->Image_Height - 3; i += 3) {
			for (int j = 0; j < this->Image_Width - 3; j += 3) {

				if (j < 3) {
					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;
					}

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;

					}
				}

				else {

					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + k][j + 2].r = (scaled.Pixel_Matrix[i + k][j + 2].r + scaled.Pixel_Matrix[i + k][j + 3].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].g = (scaled.Pixel_Matrix[i + k][j + 2].g + scaled.Pixel_Matrix[i + k][j + 3].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 2].b = (scaled.Pixel_Matrix[i + k][j + 2].b + scaled.Pixel_Matrix[i + k][j + 3].b) / 2;

						scaled.Pixel_Matrix[i + k][j + 3].r = (scaled.Pixel_Matrix[i + k][j + 3].r + scaled.Pixel_Matrix[i + k][j + 2].r) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].g = (scaled.Pixel_Matrix[i + k][j + 3].g + scaled.Pixel_Matrix[i + k][j + 2].g) / 2;
						scaled.Pixel_Matrix[i + k][j + 3].b = (scaled.Pixel_Matrix[i + k][j + 3].b + scaled.Pixel_Matrix[i + k][j + 2].b) / 2;

					}


					for (int k = 0; k < 3; k++) {
						scaled.Pixel_Matrix[i + 2][j + k].r = (scaled.Pixel_Matrix[i + 2][j + k].r + scaled.Pixel_Matrix[i + 3][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].g = (scaled.Pixel_Matrix[i + 2][j + k].g + scaled.Pixel_Matrix[i + 3][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 2][j + k].b = (scaled.Pixel_Matrix[i + 2][j + k].b + scaled.Pixel_Matrix[i + 3][j + k].b) / 2;


						scaled.Pixel_Matrix[i + 3][j + k].r = (scaled.Pixel_Matrix[i + 3][j + k].r + scaled.Pixel_Matrix[i + 2][j + k].r) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].g = (scaled.Pixel_Matrix[i + 3][j + k].g + scaled.Pixel_Matrix[i + 2][j + k].g) / 2;
						scaled.Pixel_Matrix[i + 3][j + k].b = (scaled.Pixel_Matrix[i + 3][j + k].b + scaled.Pixel_Matrix[i + 2][j + k].b) / 2;
					}

				}


			}
		}
		this->Pixel_Matrix = scaled.Pixel_Matrix;
		this->image_data = scaled.image_data;
		this->Image_Height *= 3;
		this->Image_Width *= 3;

	}
	void Set_Scale(int Height, int Width) {
		unsigned char* temp = (unsigned char*)malloc(Height*Width*channel * sizeof(unsigned char));
		std::vector<std::vector<Pixel> > NPM(Height);
		std::vector<Pixel> pixels(this->Image_Height*this->Image_Width);
		int z = 0;
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				pixels[z++] = this->Pixel_Matrix[i][j];
			}
		}
		for (int i = 0; i < Height; i++) {
			NPM[i] = std::vector<Pixel>(Width);
		}

		for (int i = 0; i < this->Image_Height; i++) {
			this->Pixel_Matrix[i].clear();
			std::vector<Pixel>().swap(this->Pixel_Matrix[i]);
		}
		this->Pixel_Matrix.clear();
		std::vector<std::vector<Pixel> >().swap(this->Pixel_Matrix);

		Pixel a, b, c, d;
		int index, x, y;
		float x_ratio = ((float)(this->Image_Width - 1)) / Width;
		float y_ratio = ((float)(this->Image_Height - 1)) / Height;
		float x_diff, y_diff, blue, red, green;
		int offset = 0;
		for (int i = 0; i < Height; i++) {
			for (int j = 0; j < Width; j++) {
				x = (int)(x_ratio * j);
				y = (int)(y_ratio * i);
				x_diff = (x_ratio * j) - x;
				y_diff = (y_ratio * i) - y;
				index = (y*this->Image_Width + x);
				a = pixels[index];
				b = pixels[index + 1];
				c = pixels[index + this->Image_Width];
				d = pixels[index + this->Image_Width + 1];

				blue = (float)(a.b *((1 - this->Image_Width)*(1 - this->Image_Height)) + b.b*this->Image_Width*(1 - this->Image_Height) + c.b*this->Image_Height*(1 - this->Image_Width) +
					d.b*this->Image_Height*this->Image_Width);

				green = (float)(a.g *((1 - this->Image_Width)*(1 - this->Image_Height)) + b.g*this->Image_Width*(1 - this->Image_Height) + c.g*this->Image_Height*(1 - this->Image_Width) +
					d.g*this->Image_Height*this->Image_Width);
				red = (float)(a.r *((1 - this->Image_Width)*(1 - this->Image_Height)) + b.r*this->Image_Width*(1 - this->Image_Height) + c.r*this->Image_Height*(1 - this->Image_Width) +
					d.r*this->Image_Height*this->Image_Width);

				NPM[i][j] = Pixel((int)red, (int)green, (int)blue);
			}
		}

		pixels.clear();
		std::vector<Pixel>().swap(pixels);

		this->Pixel_Matrix = NPM;
		stbi_image_free(this->image_data);
		this->Image_Height = Height;
		this->Image_Width = Width;
		this->image_data = temp;
	}

	void Detect_Faces() {
		short flag = 0;
		Color_Palette CSET;
		int distance = 0, min_d = 355, skin_thresh = 15, grap_thresh = 60;
		float treshold = 45;
		int validation_level = 0;
		int n_valid_bounty = 10;
		Point<double> left_eye, right_eye;
		left_eye[0] = right_eye[0] = 0;
		left_eye[1] = right_eye[1] = 0;
		Pixel black;
		Pixel skin_graph, nose_graph, forhead_graph, chin_graph;
		black.r = black.g = black.b = 0;

		for (int i = 0; i < Image_Height; i++) {
			for (int j = 0; j < Image_Width; j++) {

				if (flag == 0) {
					if (Pixel_Matrix[i][j].r < treshold  && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold) {
						left_eye[0] = j;
						left_eye[1] = i;
						flag = 1;
#ifdef FaceDebug	



						Draw_Circle(j, i, 3, CSET.Green); //detected eye loctaion -left eye-

#endif
					}
				}
				else if (flag == 1) {
					if (distance > Image_Width / 3) {
						break;
					}
					else if (Pixel_Matrix[i][j].r < treshold && Pixel_Matrix[i][j].g < treshold && Pixel_Matrix[i][j].b < treshold && distance > 30) {
						right_eye[0] = j;
						right_eye[1] = i;
						flag = 2;
						//i += 4;
#ifdef FaceDebug


						Draw_Circle(j, i, 3, CSET.Red); //detected eye location -right eye
						Draw_Circle((int)left_eye[0], (int)left_eye[1], 3, CSET.Green); //detected eye location -right eye
#endif


					//defenition of skin graphs for validation sequance
						skin_graph = Pixel_Matrix[(int)(left_eye[1])][(int)(left_eye[0]) + (distance / 2)];
						if ((left_eye[1]) + (distance / 2) < Image_Height && (left_eye[0]) + (distance / 2) < Image_Width) {
							nose_graph = Pixel_Matrix[(int)(left_eye[1]) + (distance / 2)][(int)(left_eye[0]) + (distance / 2)];
						}
						if (left_eye[1] - (distance / 4) > 0) {
							forhead_graph = Pixel_Matrix[(int)(left_eye[1] - (distance / 4))][(int)(left_eye[0]) + (distance / 2)];
						}
						if (left_eye[1] + 1.3*distance < Image_Height) {
							int temp = (int)1.3*distance;
							chin_graph = Pixel_Matrix[(int)(left_eye[1] + (temp))][(int)(left_eye[0]) + (distance / 2)];
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
			if (flag == 2 && distance > 50 && left_eye[0] + (distance / 2) < Image_Width &&
				left_eye[1] + (distance / 2) < Image_Height &&Color_Distance(Pixel_Matrix[(int)(left_eye[1]) + (distance / 2)][(int)(left_eye[0]) + (distance / 2)], black) > min_d) {


				skin_graph = Pixel_Matrix[(int)(left_eye[1])][(int)(left_eye[0]) + (distance / 2)];

				if (skin_graph.r < 120 && skin_graph.g < 120 && skin_graph.b < 120) {
					continue;
				}






#ifdef FaceDebug

				Draw_Circle((int)(left_eye[0]) + (distance / 2), (int)(left_eye[1]), 3, CSET.Blue); //sking graph location
				Draw_Circle((int)(left_eye[0]) + (distance / 2), (int)(left_eye[1]), 4, CSET.Red); //sking graph location
				Draw_Circle((int)(left_eye[0]) + (distance / 2), (int)(left_eye[1]), 2, CSET.Green); //sking graph location

				Draw_Line((int)left_eye[1], (int)left_eye[0], (int)left_eye[1], (int)left_eye[0] + distance / 2, CSET.Black); // line to cetner point 
#endif
				if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye[1] + distance / 2][(int)left_eye[0]]) < grap_thresh) {

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)left_eye[1] + distance / 2][(int)left_eye[0]]) < skin_thresh) { // left chick cmp

						validation_level++; //level 1

						if (Distance_Neighbors(treshold, (int)left_eye[1] + distance / 2, (int)left_eye[0])) {
							validation_level += n_valid_bounty;
							std::cout << ("Validated --Neighbor-- left chick: " + validation_level) << "\n";

						}
						//#ifdef FaceDebug
						Draw_Circle((int)(left_eye[0]), (int)(left_eye[1]) + (distance / 2), 3, CSET.White); //chick graph location -left eye-
						Draw_Line((int)left_eye[1], (int)left_eye[0], (int)left_eye[1] + distance / 2, (int)left_eye[0], CSET.White); // line to chick point -left eye-
						std::cout << ("Validated left chick: " + validation_level) << std::endl;
						//#endif // FaceDebug


					}

					if (Color_Distance(skin_graph, Pixel_Matrix[(int)right_eye[1] + distance / 2][(int)right_eye[0]]) < skin_thresh) {//right chick
						validation_level++; //level 2
						std::cout << ("Validated Right chick: " + validation_level) << std::endl;

						if (Distance_Neighbors(treshold, (int)right_eye[1] + distance / 2, (int)right_eye[0])) {
							validation_level += n_valid_bounty;
							std::cout << ("Validated  --Neighbor-- right chick: " + validation_level) << std::endl;

						}

					}



					if (Color_Distance(skin_graph, forhead_graph) < grap_thresh) { //forhead vs skin center cmp
#ifdef FaceDebug
						Draw_Circle((int)left_eye[0] + distance / 2, (int)left_eye[1] - (distance / 4), 3, CSET.White); //at forhead
						Draw_Line((int)left_eye[1], (int)left_eye[0] + distance / 2, (int)left_eye[1] - (distance / 4), (int)left_eye[0] + distance / 2, CSET.White);

#endif
						validation_level++; //level 3
						std::cout << ("Validated Forhead - Center: " + validation_level) << std::endl;

						if (Distance_Neighbors(treshold, (int)left_eye[1] - (distance / 4), (int)left_eye[0] + distance / 2)) {
							validation_level += n_valid_bounty;
							std::cout << ("Validated  --Neighbor-- Forhead - Center: " + validation_level) << std::endl;

						}

					}





					if (Color_Distance(nose_graph, skin_graph) < grap_thresh) {//nose vs middle face cmp
#ifdef FaceDebug
						Draw_Circle((int)left_eye[0] + distance / 2, (int)left_eye[1] + distance / 2, 3, CSET.White);
						//Draw_Line(left_eye[0] + distance / 2, left_eye[1], left_eye[0] + distance / 2, left_eye[1] + (distance / 2), 'W');

#endif
						validation_level++; //level 4
						std::cout << ("Validated Nose - Center: " + validation_level) << std::endl;

						if (Distance_Neighbors(treshold, (int)left_eye[1] + distance / 2, (int)left_eye[0] + distance / 2)) {
							validation_level += n_valid_bounty;
							std::cout << ("Validated  --Neighbor-- Nose - Center: " + validation_level) << std::endl;

						}
					}


					if (Color_Distance(chin_graph, skin_graph) < grap_thresh) {//chin vs middle face cmp
#ifdef FaceDebug
						Draw_Circle((int)left_eye[0] + distance / 2, (int)(left_eye[1] + 1.3*distance), 3, CSET.White);
						Draw_Line((int)left_eye[1], (int)left_eye[0] + distance / 2, (int)(left_eye[1] + 1.3*(distance)), (int)left_eye[0] + distance / 2, CSET.White);

#endif
						validation_level++; //level 5
						std::cout << ("Validated Chin - Center: " + validation_level) << std::endl;

						if (Distance_Neighbors(treshold, (int)left_eye[1] + (int)(1.3*distance), (int)left_eye[0] + distance / 2)) {
							validation_level += n_valid_bounty;
							std::cout << ("Validated  --Neighbor-- Chin - Center: " + validation_level) << std::endl;

						}
					}





#ifdef FaceDebug




					//right eye validate for v2 yet to be added to calculation
					Draw_Line((int)right_eye[1], (int)right_eye[0], (int)right_eye[1], (int)right_eye[0] - distance / 2, CSET.Black); // line to cetner point from -right eye-
					Draw_Circle((int)(right_eye[0]), (int)(right_eye[1]) + (distance / 2), 3, CSET.White); //chick graph location -right eye- 
					Draw_Line((int)right_eye[1], (int)right_eye[0], (int)right_eye[1] + distance / 2, (int)right_eye[0], CSET.White); // line to chick point -right eye-

#endif

					if (validation_level >= 30) {
						Draw_Square((int)left_eye[0] + distance / 2, (int)left_eye[1] + distance / 2, distance, distance, CSET.Red);
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
	std::vector<int> Get_Red_Histogram() {
		std::vector<int> Rh(256, 0);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Rh[this->Pixel_Matrix[i][j].r]++;
			}
		}
		return Rh;
	}
	std::vector<int> Get_Green_Histogram() {
		std::vector<int> Rh(256, 0);

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Rh[this->Pixel_Matrix[i][j].g]++;
			}
		}
		return Rh;
	}
	std::vector<int>Get_Blue_Histogram() {
		std::vector<int> Rh(256, 0);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				Rh[this->Pixel_Matrix[i][j].b]++;
			}
		}
		return Rh;
	}

	void Histogram_Equalization() {
		std::vector<int> xxR(256, 0);
		std::vector<int> xxG(256, 0);
		std::vector<int> xxB(256, 0);

		std::vector<double> xxRProp(256);
		std::vector<double> xxGProp(256);
		std::vector<double> xxBProp(256);

		std::vector<double> xxRCP(256);
		std::vector<double> xxGCP(256);
		std::vector<double> xxBCP(256);



		int max_y = this->Image_Height*this->Image_Width;

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				xxR[this->Pixel_Matrix[i][j].r]++;
				xxG[this->Pixel_Matrix[i][j].g]++;
				xxB[this->Pixel_Matrix[i][j].b]++;

			}
		}

		//propobility calculations
		for (int i = 0; i < 256; i++) {
			xxRProp[i] = (double)xxR[i] / (double)max_y;
			xxGProp[i] = (double)xxG[i] / (double)max_y;
			xxBProp[i] = (double)xxB[i] / (double)max_y;

		}
		double sumRP = 0, sumGP = 0, sumBP = 0;
		for (int i = 0; i < 256; i++) {
			sumRP += xxRProp[i];
			sumGP += xxGProp[i];
			sumBP += xxBProp[i];
			xxRCP[i] = sumRP;
			xxGCP[i] = sumGP;
			xxBCP[i] = sumBP;

		}
		//normalization to 255
		for (int i = 0; i < 256; i++) {
			xxRCP[i] *= 255;
			xxGCP[i] *= 255;
			xxBCP[i] *= 255;

		}

		std::vector<double> hvR(256);
		std::vector<double> hvG(256);
		std::vector<double> hvB(256);



		for (int i = 0; i < 256; i++) {
			hvR[i] = (int)std::round(xxRCP[i]);
			hvG[i] = (int)std::round(xxGCP[i]);
			hvB[i] = (int)std::round(xxBCP[i]);


		}


		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = (int)hvR[this->Pixel_Matrix[i][j].r];
				this->Pixel_Matrix[i][j].g = (int)hvG[this->Pixel_Matrix[i][j].g];
				this->Pixel_Matrix[i][j].b = (int)hvB[this->Pixel_Matrix[i][j].b];

			}
		}

		this->Commint_Matrix_Changes();
	}

	void Histogram_Linear_Correction() {
		int maxR = std::numeric_limits<int>::min(), maxG = std::numeric_limits<int>::min(), maxB = std::numeric_limits<int>::min(),
			minR = std::numeric_limits<int>::max(), minG = std::numeric_limits<int>::max(), minB = std::numeric_limits<int>::max();
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (this->Pixel_Matrix[i][j].r > maxR) {
					maxR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].r < minR) {
					minR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].g > maxG) {
					maxG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].g < minG) {
					minG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].b > maxB) {
					maxB = this->Pixel_Matrix[i][j].b;
				}
				if (this->Pixel_Matrix[i][j].b < minB) {
					minB = this->Pixel_Matrix[i][j].b;
				}

			}
		}



		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = ((this->Pixel_Matrix[i][j].r - minR) * 255) / maxR;
				this->Pixel_Matrix[i][j].g = ((this->Pixel_Matrix[i][j].g - minG) * 255) / maxG;
				this->Pixel_Matrix[i][j].b = ((this->Pixel_Matrix[i][j].b - minB) * 255) / maxB;

			}
		}

		this->Commint_Matrix_Changes();
	}
	void Histogram_Power_Correction() {
		int maxR = std::numeric_limits<int>::min(), maxG = std::numeric_limits<int>::min(), maxB = std::numeric_limits<int>::min(),
			minR = std::numeric_limits<int>::max(), minG = std::numeric_limits<int>::max(), minB = std::numeric_limits<int>::max();
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (this->Pixel_Matrix[i][j].r > maxR) {
					maxR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].r < minR) {
					minR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].g > maxG) {
					maxG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].g < minG) {
					minG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].b > maxB) {
					maxB = this->Pixel_Matrix[i][j].b;
				}
				if (this->Pixel_Matrix[i][j].b < minB) {
					minB = this->Pixel_Matrix[i][j].b;
				}

			}
		}


		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = ((this->Pixel_Matrix[i][j].r - minR));
				this->Pixel_Matrix[i][j].g = ((this->Pixel_Matrix[i][j].g - minG));
				this->Pixel_Matrix[i][j].b = ((this->Pixel_Matrix[i][j].b - minB));

			}
		}

		double powR = std::log(255) / std::log(maxR);
		double powG = std::log(255) / std::log(maxG);
		double powB = std::log(255) / std::log(maxB);

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = (int)(std::pow(this->Pixel_Matrix[i][j].r, powR));
				this->Pixel_Matrix[i][j].g = (int)(std::pow(this->Pixel_Matrix[i][j].g, powG));
				this->Pixel_Matrix[i][j].b = (int)(std::pow(this->Pixel_Matrix[i][j].b, powB));

			}
		}

		this->Commint_Matrix_Changes();
	}
	void Histogram_Log_Correction() {
		int maxR = std::numeric_limits<int>::min(), maxG = std::numeric_limits<int>::min(), maxB = std::numeric_limits<int>::min(),
			minR = std::numeric_limits<int>::max(), minG = std::numeric_limits<int>::max(), minB = std::numeric_limits<int>::max();
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (this->Pixel_Matrix[i][j].r > maxR) {
					maxR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].r < minR) {
					minR = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].g > maxG) {
					maxG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].g < minG) {
					minG = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].b > maxB) {
					maxB = this->Pixel_Matrix[i][j].b;
				}
				if (this->Pixel_Matrix[i][j].b < minB) {
					minB = this->Pixel_Matrix[i][j].b;
				}

			}
		}

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = ((this->Pixel_Matrix[i][j].r - minR + 1));
				this->Pixel_Matrix[i][j].g = ((this->Pixel_Matrix[i][j].g - minG + 1));
				this->Pixel_Matrix[i][j].b = ((this->Pixel_Matrix[i][j].b - minB + 1));

			}
		}

		double BaseR = nthRoot(maxR, 255);
		double BaseG = nthRoot(maxG, 255);
		double BaseB = nthRoot(maxB, 255);

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = (int)(std::log(this->Pixel_Matrix[i][j].r) / std::log(BaseR));
				this->Pixel_Matrix[i][j].g = (int)(std::log(this->Pixel_Matrix[i][j].g) / std::log(BaseG));
				this->Pixel_Matrix[i][j].b = (int)(std::log(this->Pixel_Matrix[i][j].b) / std::log(BaseB));

			}
		}

		this->Commint_Matrix_Changes();
	}


	void Zero_Padding() {
		Image padded;
		Color_Palette CSET;
		padded.Load_Blank_Canvas(this->Image_Height + 2, this->Image_Width + 2, CSET.Black);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				padded.Pixel_Matrix[i + 1][j + 1] = this->Pixel_Matrix[i][j];
			}
		}

		this->image_data = padded.image_data;
		this->Image_Height = padded.Image_Height;
		this->Image_Width = padded.Image_Width;
		this->Pixel_Matrix = padded.Pixel_Matrix;
		this->Commint_Matrix_Changes();
	}
	void Extended_Padding() {
		Image padded;
		Color_Palette CSET;
		padded.Load_Blank_Canvas(this->Image_Height + 2, this->Image_Width + 2, CSET.Black);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				padded.Pixel_Matrix[i + 1][j + 1] = this->Pixel_Matrix[i][j];
			}
		}
		for (int i = 0; i < this->Image_Height + 2; i++) {
			padded.Pixel_Matrix[i][0] = padded.Pixel_Matrix[i][1];
			padded.Pixel_Matrix[i][this->Image_Width + 1] = padded.Pixel_Matrix[i][this->Image_Width - 1];
		}
		for (int i = 0; i < this->Image_Width + 2; i++) {
			padded.Pixel_Matrix[0][i] = padded.Pixel_Matrix[1][i];
			padded.Pixel_Matrix[this->Image_Height + 1][i] = padded.Pixel_Matrix[this->Image_Height - 1][i];
		}


		this->image_data = padded.image_data;
		this->Image_Height = padded.Image_Height;
		this->Image_Width = padded.Image_Width;
		this->Pixel_Matrix = padded.Pixel_Matrix;
		this->Commint_Matrix_Changes();
	}


	void Image_Convolution(int Mode) {
		if (Mode == Convolution_Kernels::Median_Filter) {
			std::vector<int> GroupR(9);
			std::vector<int> GroupG(9);
			std::vector<int> GroupB(9);
			this->Extended_Padding();
			Image copy(*this);

			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					GroupR[0] = this->Pixel_Matrix[i][j].r;
					GroupR[1] = this->Pixel_Matrix[i - 1][j].r;
					GroupR[2] = this->Pixel_Matrix[i - 1][j - 1].r;
					GroupR[3] = this->Pixel_Matrix[i - 1][j + 1].r;
					GroupR[4] = this->Pixel_Matrix[i + 1][j].r;
					GroupR[5] = this->Pixel_Matrix[i + 1][j - 1].r;
					GroupR[6] = this->Pixel_Matrix[i + 1][j + 1].r;
					GroupR[7] = this->Pixel_Matrix[i][j + 1].r;
					GroupR[8] = this->Pixel_Matrix[i][j - 1].r;
					//green
					GroupG[0] = this->Pixel_Matrix[i][j].g;
					GroupG[1] = this->Pixel_Matrix[i - 1][j].g;
					GroupG[2] = this->Pixel_Matrix[i - 1][j - 1].g;
					GroupG[3] = this->Pixel_Matrix[i - 1][j + 1].g;
					GroupG[4] = this->Pixel_Matrix[i + 1][j].g;
					GroupG[5] = this->Pixel_Matrix[i + 1][j - 1].g;
					GroupG[6] = this->Pixel_Matrix[i + 1][j + 1].g;
					GroupG[7] = this->Pixel_Matrix[i][j + 1].g;
					GroupG[8] = this->Pixel_Matrix[i][j - 1].g;
					//blue
					GroupB[0] = this->Pixel_Matrix[i][j].b;
					GroupB[1] = this->Pixel_Matrix[i - 1][j].b;
					GroupB[2] = this->Pixel_Matrix[i - 1][j - 1].b;
					GroupB[3] = this->Pixel_Matrix[i - 1][j + 1].b;
					GroupB[4] = this->Pixel_Matrix[i + 1][j].b;
					GroupB[5] = this->Pixel_Matrix[i + 1][j - 1].b;
					GroupB[6] = this->Pixel_Matrix[i + 1][j + 1].b;
					GroupB[7] = this->Pixel_Matrix[i][j + 1].b;
					GroupB[8] = this->Pixel_Matrix[i][j - 1].b;

					copy.Pixel_Matrix[i][j].r = (int)getMedian(GroupR);
					copy.Pixel_Matrix[i][j].g = (int)getMedian(GroupG);
					copy.Pixel_Matrix[i][j].b = (int)getMedian(GroupB);


				}
			}
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					this->Pixel_Matrix[i][j].r = copy.Pixel_Matrix[i][j].r;
					this->Pixel_Matrix[i][j].g = copy.Pixel_Matrix[i][j].g;
					this->Pixel_Matrix[i][j].b = copy.Pixel_Matrix[i][j].b;


				}
			}
			this->Commint_Matrix_Changes();
			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);

		}
		else if (Mode == Convolution_Kernels::Mean_Blur) {

			std::vector<std::vector<int> > Kernel(3);
			Kernel[0] = std::vector<int>(3);
			Kernel[1] = std::vector<int>(3);
			Kernel[2] = std::vector<int>(3);
			Kernel[0][0] = 1;
			Kernel[0][1] = 1;
			Kernel[0][2] = 1;
			Kernel[1][0] = 1;
			Kernel[1][1] = 1;
			Kernel[1][2] = 1;
			Kernel[2][0] = 1;
			Kernel[2][1] = 1;
			Kernel[2][2] = 1;

			this->Extended_Padding();
			double scaling_factor = (double)1 / 9;
			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					this->Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
					this->Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
					this->Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}
			this->Commint_Matrix_Changes();
			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);

		}
		else if (Mode == Convolution_Kernels::Gaussian_Blur) {
			std::vector<std::vector<int> > Kernel(3);
			Kernel[0] = std::vector<int>(3);
			Kernel[1] = std::vector<int>(3);
			Kernel[2] = std::vector<int>(3);
			Kernel[0][0] = 1;
			Kernel[0][1] = 2;
			Kernel[0][2] = 1;
			Kernel[1][0] = 2;
			Kernel[1][1] = 4;
			Kernel[1][2] = 2;
			Kernel[2][0] = 1;
			Kernel[2][1] = 2;
			Kernel[2][2] = 1;

			this->Extended_Padding();
			double scaling_factor = (double)1 / 16;
			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					this->Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
					this->Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
					this->Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}
			this->Commint_Matrix_Changes();
			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);

		}
		else if (Mode == Convolution_Kernels::Low_Pass) {
			std::vector<std::vector<double> > Kernel(3);
			Kernel[0] = std::vector<double>(3);
			Kernel[1] = std::vector<double>(3);
			Kernel[2] = std::vector<double>(3);
			Kernel[0][0] = 0;
			Kernel[0][1] = (double)1 / 8;
			Kernel[0][2] = 0;
			Kernel[1][0] = (double)1 / 8;
			Kernel[1][1] = (double)1 / 2;
			Kernel[1][2] = (double)1 / 8;
			Kernel[2][0] = 0;
			Kernel[2][1] = (double)1 / 8;
			Kernel[2][2] = 0;

			this->Extended_Padding();
			double scaling_factor = (double)1 / 16;
			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					this->Pixel_Matrix[i][j].r = (int)((R_sum));
					this->Pixel_Matrix[i][j].g = (int)(G_sum);
					this->Pixel_Matrix[i][j].b = (int)(B_sum);

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}
			this->Commint_Matrix_Changes();
			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);

		}
		else if (Mode == Convolution_Kernels::High_Pass) {
			std::vector<std::vector<double> > Kernel(3);
			Kernel[0] = std::vector<double>(3);
			Kernel[1] = std::vector<double>(3);
			Kernel[2] = std::vector<double>(3);
			Kernel[0][0] = (double)-1 / 9;
			Kernel[0][1] = (double)-1 / 9;
			Kernel[0][2] = (double)-1 / 9;
			Kernel[1][0] = (double)-1 / 9;
			Kernel[1][1] = (double)1;
			Kernel[1][2] = (double)-1 / 9;
			Kernel[2][0] = (double)-1 / 9;
			Kernel[2][1] = (double)-1 / 9;
			Kernel[2][2] = (double)-1 / 9;
			Image copy(*this);
			this->Extended_Padding();
			copy.Extended_Padding();
			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					//clamping


					copy.Pixel_Matrix[i][j].r = (int)(((R_sum)));
					copy.Pixel_Matrix[i][j].g = (int)((G_sum));
					copy.Pixel_Matrix[i][j].b = (int)((B_sum));
					//copy.Pixel_Matrix[i][j].Clamp_Outliers();
					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}

			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);
			copy.Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);
			this->init_pixel_matrix();
			*this = *this + (copy);
			this->Commint_Matrix_Changes();

		}
		else if (Mode == Convolution_Kernels::High_Pass_Streached) {
			std::vector<std::vector<double> > Kernel(3);
			Kernel[0] = std::vector<double>(3);
			Kernel[1] = std::vector<double>(3);
			Kernel[2] = std::vector<double>(3);
			Kernel[0][0] = (double)-1 / 9;
			Kernel[0][1] = (double)-1 / 9;
			Kernel[0][2] = (double)-1 / 9;
			Kernel[1][0] = (double)-1 / 9;
			Kernel[1][1] = (double)-8 / 9;
			Kernel[1][2] = (double)-1 / 9;
			Kernel[2][0] = (double)-1 / 9;
			Kernel[2][1] = (double)-1 / 9;
			Kernel[2][2] = (double)-1 / 9;

			this->Extended_Padding();
			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					//clamping


					this->Pixel_Matrix[i][j].r = (int)(((R_sum / 2)) + 128);
					this->Pixel_Matrix[i][j].g = (int)((G_sum / 2) + 128);
					this->Pixel_Matrix[i][j].b = (int)((B_sum / 2) + 128);
					this->Pixel_Matrix[i][j].Clamp_Outliers();
					if (this->Pixel_Matrix[i][j].r < 0 || this->Pixel_Matrix[i][j].g < 0 || this->Pixel_Matrix[i][j].r < 0) {
						std::cout << ("Found <0 !\n");
					}

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}
			this->Commint_Matrix_Changes();
			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);
			this->Commint_Matrix_Changes();

		}
		else if (Mode == Convolution_Kernels::Unsharp_Mask) {
			std::vector<std::vector<double> > Kernel(3);
			Kernel[0] = std::vector<double>(3);
			Kernel[1] = std::vector<double>(3);
			Kernel[2] = std::vector<double>(3);
			Kernel[0][0] = (double)0;
			Kernel[0][1] = (double)1;
			Kernel[0][2] = (double)0;
			Kernel[1][0] = (double)1;
			Kernel[1][1] = (double)-4;
			Kernel[1][2] = (double)1;
			Kernel[2][0] = (double)0;
			Kernel[2][1] = (double)1;
			Kernel[2][2] = (double)0;



			this->Extended_Padding();
			Image Original(*this);
			Image Copy(*this);

			double R_sum = 0, G_sum = 0, B_sum = 0;
			for (int i = 1; i < this->Image_Height - 1; i++) {
				for (int j = 1; j < this->Image_Width - 1; j++) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					//clamping


					Copy.Pixel_Matrix[i][j].r = (int)(((R_sum)));
					Copy.Pixel_Matrix[i][j].g = (int)((G_sum));
					Copy.Pixel_Matrix[i][j].b = (int)((B_sum));

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
			}

			Copy.Commint_Matrix_Changes();
			Original = Original - (Copy);
			Copy.Write_Image("Masked.png");

			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					this->Pixel_Matrix[i][j] = Original.Pixel_Matrix[i][j];
				}
			}

			this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);



			this->Commint_Matrix_Changes();


		}
		else if (Mode == Convolution_Kernels::Sobel_Kernel) {
			std::vector<std::vector<double> > Kernel_x(3);
			Kernel_x[0] = std::vector<double>(3);
			Kernel_x[1] = std::vector<double>(3);
			Kernel_x[2] = std::vector<double>(3);
			std::vector<std::vector<double> > Kernel_y(3);
			Kernel_y[0] = std::vector<double>(3);
			Kernel_y[1] = std::vector<double>(3);
			Kernel_y[2] = std::vector<double>(3);
			Image copy_y(*this);
			Image copy(*this);
			Kernel_x[0][0] = (double)-1;
			Kernel_x[0][1] = (double)-2;
			Kernel_x[0][2] = (double)-1;
			Kernel_x[1][0] = (double)0;
			Kernel_x[1][1] = (double)0;
			Kernel_x[1][2] = (double)0;
			Kernel_x[2][0] = (double)1;
			Kernel_x[2][1] = (double)2;
			Kernel_x[2][2] = (double)1;

			Kernel_y[0][0] = (double)-1;
			Kernel_y[0][1] = (double)0;
			Kernel_y[0][2] = (double)1;
			Kernel_y[1][0] = (double)-2;
			Kernel_y[1][1] = (double)0;
			Kernel_y[1][2] = (double)2;
			Kernel_y[2][0] = (double)-1;
			Kernel_y[2][1] = (double)0;
			Kernel_y[2][2] = (double)1;

			copy_y.Extended_Padding();
			copy.Extended_Padding();
			double R_sum = 0, G_sum = 0, B_sum = 0;
			double R_sum_x = 0, G_sum_x = 0, B_sum_x = 0;

			for (int i = 1; i < copy_y.Image_Height - 1; i++) {
				for (int j = 1; j < copy_y.Image_Width - 1; j++) {
					//red
					R_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].r;
					R_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].g;
					G_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel_y[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel_y[0][1] * copy_y.Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel_y[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel_y[1][0] * copy_y.Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel_y[1][1] * copy_y.Pixel_Matrix[i][j].b;
					B_sum += Kernel_y[1][2] * copy_y.Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel_y[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel_y[2][1] * copy_y.Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel_y[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].b;



					//red
					R_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].r;
					R_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i - 1][j].r;
					R_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].r;
					R_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j - 1].r;
					R_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].r;
					R_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j + 1].r;
					R_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].r;
					R_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i + 1][j].r;
					R_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].g;
					G_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i - 1][j].g;
					G_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].g;
					G_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j - 1].g;
					G_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].g;
					G_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j + 1].g;
					G_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].g;
					G_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i + 1][j].g;
					G_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum_x += Kernel_x[0][0] * copy_y.Pixel_Matrix[i - 1][j - 1].b;
					B_sum_x += Kernel_x[0][1] * copy_y.Pixel_Matrix[i - 1][j].b;
					B_sum_x += Kernel_x[0][2] * copy_y.Pixel_Matrix[i - 1][j + 1].b;
					B_sum_x += Kernel_x[1][0] * copy_y.Pixel_Matrix[i][j - 1].b;
					B_sum_x += Kernel_x[1][1] * copy_y.Pixel_Matrix[i][j].b;
					B_sum_x += Kernel_x[1][2] * copy_y.Pixel_Matrix[i][j + 1].b;
					B_sum_x += Kernel_x[2][0] * copy_y.Pixel_Matrix[i + 1][j - 1].b;
					B_sum_x += Kernel_x[2][1] * copy_y.Pixel_Matrix[i + 1][j].b;
					B_sum_x += Kernel_x[2][2] * copy_y.Pixel_Matrix[i + 1][j + 1].b;

					//clamping


					copy.Pixel_Matrix[i][j].r = (int)std::round((std::sqrt(R_sum_x*R_sum_x + R_sum * R_sum)));
					copy.Pixel_Matrix[i][j].g = (int)std::round((std::sqrt(G_sum_x*G_sum_x + G_sum * G_sum)));
					copy.Pixel_Matrix[i][j].b = (int)std::round((std::sqrt(B_sum_x*B_sum_x + B_sum * B_sum)));
					copy.Pixel_Matrix[i][j].Clamp_Outliers();

					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
					R_sum_x = 0;
					B_sum_x = 0;
					G_sum_x = 0;
				}
			}
			R_sum = 0;
			B_sum = 0;
			G_sum = 0;
			copy.Commint_Matrix_Changes();
			copy.Crop_Image(1, 1, copy_y.Image_Height - 1, copy_y.Image_Width - 1);


			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					this->Pixel_Matrix[i][j].r = copy.Pixel_Matrix[i][j].r;
					this->Pixel_Matrix[i][j].g = copy.Pixel_Matrix[i][j].g;
					this->Pixel_Matrix[i][j].b = copy.Pixel_Matrix[i][j].b;
					this->Pixel_Matrix[i][j].Clamp_Outliers();
				}
			}
			this->Commint_Matrix_Changes();


		}




	}
	void Scale_Down_By_Convolution(std::string Mode) {
		if (Mode == ("Mean")) {
			std::vector<std::vector<int> > Kernel(3);
			Kernel[0] = std::vector<int>(3);
			Kernel[1] = std::vector<int>(3);
			Kernel[2] = std::vector<int>(3);
			Image Shrinked;
			Kernel[0][0] = 1;
			Kernel[0][1] = 1;
			Kernel[0][2] = 1;
			Kernel[1][0] = 1;
			Kernel[1][1] = 1;
			Kernel[1][2] = 1;
			Kernel[2][0] = 1;
			Kernel[2][1] = 1;
			Kernel[2][2] = 1;
			this->Extended_Padding();
			Shrinked.Load_Blank_Canvas(this->Image_Height / 3, this->Image_Width / 3, Pixel(0, 0, 0));
			double scaling_factor = (double)1 / 9;
			double R_sum = 0, G_sum = 0, B_sum = 0;
			int sh = 0, sw = 0;
			for (int i = 1; i < this->Image_Height - 1; i += 3) {
				for (int j = 1; j < this->Image_Width - 1; j += 3) {
					//red
					R_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].r;
					R_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].r;
					R_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].r;
					R_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].r;
					R_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].r;
					R_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].r;
					R_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].r;
					R_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].r;
					R_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].r;
					//green
					G_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].g;
					G_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].g;
					G_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].g;
					G_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].g;
					G_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].g;
					G_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].g;
					G_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].g;
					G_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].g;
					G_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].g;
					//Blue
					B_sum += Kernel[0][0] * this->Pixel_Matrix[i - 1][j - 1].b;
					B_sum += Kernel[0][1] * this->Pixel_Matrix[i - 1][j].b;
					B_sum += Kernel[0][2] * this->Pixel_Matrix[i - 1][j + 1].b;
					B_sum += Kernel[1][0] * this->Pixel_Matrix[i][j - 1].b;
					B_sum += Kernel[1][1] * this->Pixel_Matrix[i][j].b;
					B_sum += Kernel[1][2] * this->Pixel_Matrix[i][j + 1].b;
					B_sum += Kernel[2][0] * this->Pixel_Matrix[i + 1][j - 1].b;
					B_sum += Kernel[2][1] * this->Pixel_Matrix[i + 1][j].b;
					B_sum += Kernel[2][2] * this->Pixel_Matrix[i + 1][j + 1].b;

					this->Pixel_Matrix[i][j].r = (int)((R_sum * scaling_factor));
					this->Pixel_Matrix[i][j].g = (int)(G_sum * scaling_factor);
					this->Pixel_Matrix[i][j].b = (int)(B_sum * scaling_factor);

					Shrinked.Pixel_Matrix[sh][sw] = this->Pixel_Matrix[i][j];
					sw++;
					R_sum = 0;
					B_sum = 0;
					G_sum = 0;
				}
				sh++;
				sw = 0;
			}
			Shrinked.Commint_Matrix_Changes();
			this->image_data = Shrinked.image_data;
			this->Image_Width = Shrinked.Image_Width;
			this->Image_Height = Shrinked.Image_Height;
			this->Pixel_Matrix = Shrinked.Pixel_Matrix;
		}
		else if (Mode == ("Median")) {
			std::vector<int> GroupR(9);
			std::vector<int> GroupG(9);
			std::vector<int> GroupB(9);
			Image Shrinked;
			this->Extended_Padding();
			Shrinked.Load_Blank_Canvas(this->Image_Height / 3, this->Image_Width / 3, Pixel(0, 0, 0));
			int sh = 0, sw = 0;


			for (int i = 1; i < this->Image_Height - 1; i += 3) {
				for (int j = 1; j < this->Image_Width - 1; j += 3) {
					//red
					GroupR[0] = this->Pixel_Matrix[i][j].r;
					GroupR[1] = this->Pixel_Matrix[i - 1][j].r;
					GroupR[2] = this->Pixel_Matrix[i - 1][j - 1].r;
					GroupR[3] = this->Pixel_Matrix[i - 1][j + 1].r;
					GroupR[4] = this->Pixel_Matrix[i + 1][j].r;
					GroupR[5] = this->Pixel_Matrix[i + 1][j - 1].r;
					GroupR[6] = this->Pixel_Matrix[i + 1][j + 1].r;
					GroupR[7] = this->Pixel_Matrix[i][j + 1].r;
					GroupR[8] = this->Pixel_Matrix[i][j - 1].r;
					//green
					GroupG[0] = this->Pixel_Matrix[i][j].g;
					GroupG[1] = this->Pixel_Matrix[i - 1][j].g;
					GroupG[2] = this->Pixel_Matrix[i - 1][j - 1].g;
					GroupG[3] = this->Pixel_Matrix[i - 1][j + 1].g;
					GroupG[4] = this->Pixel_Matrix[i + 1][j].g;
					GroupG[5] = this->Pixel_Matrix[i + 1][j - 1].g;
					GroupG[6] = this->Pixel_Matrix[i + 1][j + 1].g;
					GroupG[7] = this->Pixel_Matrix[i][j + 1].g;
					GroupG[8] = this->Pixel_Matrix[i][j - 1].g;
					//blue
					GroupB[0] = this->Pixel_Matrix[i][j].b;
					GroupB[1] = this->Pixel_Matrix[i - 1][j].b;
					GroupB[2] = this->Pixel_Matrix[i - 1][j - 1].b;
					GroupB[3] = this->Pixel_Matrix[i - 1][j + 1].b;
					GroupB[4] = this->Pixel_Matrix[i + 1][j].b;
					GroupB[5] = this->Pixel_Matrix[i + 1][j - 1].b;
					GroupB[6] = this->Pixel_Matrix[i + 1][j + 1].b;
					GroupB[7] = this->Pixel_Matrix[i][j + 1].b;
					GroupB[8] = this->Pixel_Matrix[i][j - 1].b;

					this->Pixel_Matrix[i][j].r = (int)getMedian(GroupR);
					this->Pixel_Matrix[i][j].g = (int)getMedian(GroupG);
					this->Pixel_Matrix[i][j].b = (int)getMedian(GroupB);
					Shrinked.Pixel_Matrix[sh][sw] = this->Pixel_Matrix[i][j];
					sw++;

				}
				sh++;
				sw = 0;
			}
			Shrinked.Commint_Matrix_Changes();
			this->image_data = Shrinked.image_data;
			this->Image_Width = Shrinked.Image_Width;
			this->Image_Height = Shrinked.Image_Height;
			this->Pixel_Matrix = Shrinked.Pixel_Matrix;

		}
	}
	void Dithering_Floyd_Steinberg(int Palette_Size) {
		std::vector<Point<double> > ACP = this->Get_Average_Color_Palette(Palette_Size, 25);
		this->Extended_Padding();
		double minDistance = std::numeric_limits<double>::max();
		int pos = 0;
		for (int i = 1; i < this->Image_Height - 1; i++) {
			for (int j = 1; j < this->Image_Width - 1; j++) {
				Pixel oldpixel = this->Pixel_Matrix[i][j];
				Pixel newpixel;
				for (int k = 0; k < Palette_Size; k++) {
					double distance = ACP[k].get_Distance(Point<double>({ (double)oldpixel.r, (double)oldpixel.g, (double)oldpixel.b }));
					if (minDistance > distance) {
						minDistance = distance;
						//System.out.println(distance);

						pos = k;
					}
				}
				minDistance = std::numeric_limits<double>::max();
				newpixel = Pixel((int)ACP[pos][0], (int)ACP[pos][1], (int)ACP[pos][2]);
				this->Pixel_Matrix[i][j] = newpixel;
				double quant_error_r = (oldpixel.r - newpixel.r);
				double quant_error_g = (oldpixel.g - newpixel.g);
				double quant_error_b = (oldpixel.b - newpixel.b);
				this->Pixel_Matrix[i][j + 1].r += (int)std::round((quant_error_r * (double)7 / 16));
				this->Pixel_Matrix[i][j + 1].g += (int)std::round((quant_error_g * (double)7 / 16));
				this->Pixel_Matrix[i][j + 1].b += (int)std::round((quant_error_b * (double)7 / 16));

				this->Pixel_Matrix[i + 1][j - 1].r += (int)std::round((quant_error_r * (double)3 / 16));
				this->Pixel_Matrix[i + 1][j - 1].g += (int)std::round((quant_error_g * (double)3 / 16));
				this->Pixel_Matrix[i + 1][j - 1].b += (int)std::round((quant_error_b * (double)3 / 16));

				this->Pixel_Matrix[i + 1][j].r += (int)std::round((quant_error_r * (double)5 / 16));
				this->Pixel_Matrix[i + 1][j].g += (int)std::round((quant_error_g * (double)5 / 16));
				this->Pixel_Matrix[i + 1][j].b += (int)std::round((quant_error_b * (double)5 / 16));

				this->Pixel_Matrix[i + 1][j + 1].r += (int)std::round((quant_error_r * (double)1 / 16));
				this->Pixel_Matrix[i + 1][j + 1].g += (int)std::round((quant_error_g * (double)1 / 16));
				this->Pixel_Matrix[i + 1][j + 1].b += (int)std::round((quant_error_b * (double)1 / 16));

			}
		}
		this->Commint_Matrix_Changes();
		this->Crop_Image(1, 1, this->Image_Height - 1, this->Image_Width - 1);
	}
	void Circle_Packing(int amount_of_circles, int max_circle_size) {
		class circle {
		public:
			int x, y, r;
			Pixel Color;
			circle() {}
			circle(int x, int y, int r, Pixel Color) {
				this->x = x;
				this->y = y;
				this->r = r;
				this->Color = Color;
			}
			int intersect_check(int x2, int y2, int r2)
			{
				int distSq = (this->x - x2) * (this->x - x2) +
					(this->y - y2) * (this->y - y2);
				int radSumSq = (this->r + r2) * (this->r + r2);
				if (distSq == radSumSq)
					return 1;
				else if (distSq > radSumSq)
					return -1;
				else
					return 0;
			}
		};

		std::vector<circle> circles;
		Random_Utilitis tlb;

		for (int i = 0; i < amount_of_circles; i++) {
			int r = tlb.Random_INT(1, max_circle_size);
			int x = tlb.Random_INT(1 + r, this->Image_Width - 1 - r);
			int y = tlb.Random_INT(1 + r, this->Image_Height - 1 - r);
			Pixel Color = Pixel(this->Pixel_Matrix[y][x]);
			circle to_add = circle(x, y, r, Color);
			for (int j = 0; j < circles.size(); j++) {
				if (circles[j].intersect_check(x, y, r) == 0) {
					r = tlb.Random_INT(1, max_circle_size);
					x = tlb.Random_INT(1 + r, this->Image_Width - 2 - r);
					y = tlb.Random_INT(1 + r, this->Image_Height - 2 - r);
					Color = Pixel(this->Pixel_Matrix[y][x]);
					j = 0;
					to_add.r = r;
					to_add.x = x;
					to_add.Color = Color;
					to_add.y = y;
				}
			}
			circles.push_back(to_add);
		}
		this->Load_Blank_Canvas(this->Image_Height, this->Image_Width, Pixel(0, 0, 0));
		for (int i = 0; i < circles.size(); i++) {
			this->Draw_Circle(circles[i].x, circles[i].y, circles[i].r, circles[i].Color, Draw_Modes::FILLED);
		}


	}
	void Add_Salt_and_Pepper_Noise(double Salt_Propability, double Pepper_Probability) {
		double rand = 0;
		Random_Utilitis tlb;

		if (Salt_Propability < Pepper_Probability) {

			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					rand = tlb.Random_DOUBLE(0.0, 1.0);
					if (rand <= Salt_Propability) {
						this->Pixel_Matrix[i][j].r = 255;
						this->Pixel_Matrix[i][j].g = 255;
						this->Pixel_Matrix[i][j].b = 255;

					}
					else if (rand <= Pepper_Probability) {
						this->Pixel_Matrix[i][j].r = 0;
						this->Pixel_Matrix[i][j].g = 0;
						this->Pixel_Matrix[i][j].b = 0;
					}
				}
			}
		}
		else {

			for (int i = 0; i < this->Image_Height; i++) {
				for (int j = 0; j < this->Image_Width; j++) {
					rand = tlb.Random_DOUBLE(0.0, 1.0);
					if (rand <= Pepper_Probability) {
						this->Pixel_Matrix[i][j].r = 0;
						this->Pixel_Matrix[i][j].g = 0;
						this->Pixel_Matrix[i][j].b = 0;
					}
					else if (rand <= Salt_Propability) {
						this->Pixel_Matrix[i][j].r = 255;
						this->Pixel_Matrix[i][j].g = 255;
						this->Pixel_Matrix[i][j].b = 255;

					}
				}

			}

		}
		this->Commint_Matrix_Changes();
	}

	void Image_Averaging(std::vector<Image> Images) {
		int a_width = Images[0].Image_Width, a_height = Images[0].Image_Height;
		for (int i = 0; i < Images.size(); i++) {
			if (Images[i].Image_Height != a_height || Images[i].Image_Width != a_width) {
				std::cout << "Not All Images Match In Size: Problomatic Image:" + Images[i].F_Path << "\n";
			}
		}

		this->Load_Blank_Canvas(a_height, a_width, Pixel(0, 0, 0));
		for (int i = 0; i < Images.size(); i++) {
			Image temp = Images[i];
			for (int k = 0; k < a_height; k++) {
				for (int j = 0; j < a_width; j++) {
					this->Pixel_Matrix[k][j].r += temp.Pixel_Matrix[k][j].r;
					this->Pixel_Matrix[k][j].g += temp.Pixel_Matrix[k][j].g;
					this->Pixel_Matrix[k][j].b += temp.Pixel_Matrix[k][j].b;

				}
			}

		}

		*this = *this / (double)(Images.size());


	}
	Point<double> Get_Image_Color_Means() {
		std::vector<int> Histogram_R = this->Get_Red_Histogram();
		std::vector<int> Histogram_G = this->Get_Green_Histogram();
		std::vector<int> Histogram_B = this->Get_Blue_Histogram();
		Point<double> Var;
		double R_Mean = 0, G_Mean = 0, B_Mean = 0;
		for (int i = 0; i < 256; i++) {
			R_Mean += i * ((double)Histogram_R[i] / (this->Image_Height*this->Image_Width));
			G_Mean += i * ((double)Histogram_G[i] / (this->Image_Height*this->Image_Width));
			B_Mean += i * ((double)Histogram_B[i] / (this->Image_Height*this->Image_Width));

		}
		Var[0] = R_Mean;
		Var[1] = G_Mean;
		Var[2] = B_Mean;



		return Var;
	}
	Point<double> Get_Image_Color_Variance() {
		std::vector<int> Histogram_R = this->Get_Red_Histogram();
		std::vector<int> Histogram_G = this->Get_Green_Histogram();
		std::vector<int> Histogram_B = this->Get_Blue_Histogram();
		Point<double> Var;
		double R_Mean = 0, G_Mean = 0, B_Mean = 0;
		double R_Var = 0, G_Var = 0, B_Var = 0;

		for (int i = 0; i < 256; i++) {
			R_Mean += i * ((double)Histogram_R[i] / (this->Image_Height*this->Image_Width));
			G_Mean += i * ((double)Histogram_G[i] / (this->Image_Height*this->Image_Width));
			B_Mean += i * ((double)Histogram_B[i] / (this->Image_Height*this->Image_Width));

		}

		for (int i = 0; i < 256; i++) {
			R_Var += ((Histogram_R[i] - R_Mean)*(Histogram_R[i] - R_Mean)) * ((double)Histogram_R[i] / (this->Image_Height*this->Image_Width));
			G_Var += ((Histogram_G[i] - G_Mean)*(Histogram_G[i] - G_Mean)) * ((double)Histogram_G[i] / (this->Image_Height*this->Image_Width));
			B_Var += ((Histogram_B[i] - B_Mean)*(Histogram_B[i] - B_Mean)) * ((double)Histogram_B[i] / (this->Image_Height*this->Image_Width));

		}

		Var[0] = R_Var;
		Var[1] = G_Var;
		Var[2] = B_Var;



		return Var;
	}
	Point<double> Get_Image_Color_Variance(int nth_moment) {
		std::vector<int> Histogram_R = this->Get_Red_Histogram();
		std::vector<int> Histogram_G = this->Get_Green_Histogram();
		std::vector<int> Histogram_B = this->Get_Blue_Histogram();
		Point<double> Var;
		double R_Mean = 0, G_Mean = 0, B_Mean = 0;
		double R_Var = 0, G_Var = 0, B_Var = 0;

		for (int i = 0; i < 256; i++) {
			R_Mean += i * ((double)Histogram_R[i] / (this->Image_Height*this->Image_Width));
			G_Mean += i * ((double)Histogram_G[i] / (this->Image_Height*this->Image_Width));
			B_Mean += i * ((double)Histogram_B[i] / (this->Image_Height*this->Image_Width));

		}

		for (int i = 0; i < 256; i++) {
			R_Var += (std::pow((Histogram_R[i] - R_Mean), nth_moment)) * ((double)Histogram_R[i] / (this->Image_Height*this->Image_Width));
			G_Var += (std::pow((Histogram_G[i] - G_Mean), nth_moment)) * ((double)Histogram_G[i] / (this->Image_Height*this->Image_Width));
			B_Var += (std::pow((Histogram_B[i] - B_Mean), nth_moment)) * ((double)Histogram_B[i] / (this->Image_Height*this->Image_Width));

		}

		Var[0] = R_Var;
		Var[1] = G_Var;
		Var[2] = B_Var;



		return Var;
	}
	void Logarithmic_Transformation() {
		int max_mag_R = 0;
		int max_mag_G = 0;
		int max_mag_B = 0;

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (this->Pixel_Matrix[i][j].r > max_mag_R) {
					max_mag_R = this->Pixel_Matrix[i][j].r;
				}
				if (this->Pixel_Matrix[i][j].g > max_mag_G) {
					max_mag_G = this->Pixel_Matrix[i][j].g;
				}
				if (this->Pixel_Matrix[i][j].b > max_mag_B) {
					max_mag_B = this->Pixel_Matrix[i][j].b;
				}
			}
		}

		double scaling_R = (double)255 / std::log(1 + std::abs(max_mag_R));
		double scaling_G = (double)255 / std::log(1 + std::abs(max_mag_G));
		double scaling_B = (double)255 / std::log(1 + std::abs(max_mag_B));

		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = (int)(scaling_R * (std::log(1 + std::abs(this->Pixel_Matrix[i][j].r))));
				this->Pixel_Matrix[i][j].g = (int)(scaling_G * (std::log(1 + std::abs(this->Pixel_Matrix[i][j].g))));
				this->Pixel_Matrix[i][j].b = (int)(scaling_B * (std::log(1 + std::abs(this->Pixel_Matrix[i][j].b))));

			}
		}
		this->Commint_Matrix_Changes();

	}
	void Square_Root_Transformation() {
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = (int)std::sqrt(this->Pixel_Matrix[i][j].r);
				this->Pixel_Matrix[i][j].g = (int)std::sqrt(this->Pixel_Matrix[i][j].g);
				this->Pixel_Matrix[i][j].b = (int)std::sqrt(this->Pixel_Matrix[i][j].b);


			}
		}
		this->Commint_Matrix_Changes();
	}
	void Negative_Transformation() {
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				this->Pixel_Matrix[i][j].r = 255 - 1 - this->Pixel_Matrix[i][j].r;
				this->Pixel_Matrix[i][j].g = 255 - 1 - this->Pixel_Matrix[i][j].g;
				this->Pixel_Matrix[i][j].b = 255 - 1 - this->Pixel_Matrix[i][j].b;
				this->Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this->Commint_Matrix_Changes();
	}
	void Power_Law_Transformation(double Gamma) {
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {

				this->Pixel_Matrix[i][j].r = (int)Remap((double)std::pow(Pixel_Matrix[i][j].r, Gamma), 0, (double)std::pow(255, Gamma), 0, 255);
				this->Pixel_Matrix[i][j].g = (int)Remap((double)std::pow(Pixel_Matrix[i][j].g, Gamma), 0, (double)std::pow(255, Gamma), 0, 255);
				this->Pixel_Matrix[i][j].b = (int)Remap((double)std::pow(Pixel_Matrix[i][j].b, Gamma), 0, (double)std::pow(255, Gamma), 0, 255);

			}
		}
		this->Commint_Matrix_Changes();
	}
	void Bit_Plane_Slice(int Plane) {
		int plane = 0;
		plane = (int)std::pow(2, Plane);


		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				if (((this->Pixel_Matrix[i][j].r  & plane) == 0)) {
					this->Pixel_Matrix[i][j].r = 0;
				}
				if (((this->Pixel_Matrix[i][j].g  & plane) == 0)) {
					this->Pixel_Matrix[i][j].g = 0;
				}
				if (((this->Pixel_Matrix[i][j].b  & plane) == 0)) {
					this->Pixel_Matrix[i][j].b = 0;
				}


			}
		}
		this->Commint_Matrix_Changes();
	}

	void Add_Gaussian_Noise(double Variance) {

		double RDV = 0;
		std::default_random_engine generator;
		std::normal_distribution<double> distribution(128, 128);

		double SD = std::sqrt(Variance);
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				RDV = (SD*(distribution(generator)));
				this->Pixel_Matrix[i][j].r = (int)(RDV + this->Pixel_Matrix[i][j].r);
				this->Pixel_Matrix[i][j].g = (int)(RDV + this->Pixel_Matrix[i][j].g);
				this->Pixel_Matrix[i][j].b = (int)(RDV + this->Pixel_Matrix[i][j].b);
				this->Pixel_Matrix[i][j].Clamp_Outliers();
			}
		}
		this->Commint_Matrix_Changes();

	}
	void Connected_Components_Labeling() {
		this->Extended_Padding();
		this->Grayscale(1);
		this->Thresholding(1);
		this->Write_Image("thresh.jpg");
		this->Update_Pixel_Matrix();

		std::unordered_map<int, int> Labels;
		Matrix<double> States(this->Image_Height, this->Image_Width);
		int last_label = 0;
		Color_Palette CSET;

		for (int i = 1; i < this->Image_Height - 1; i++) {
			for (int j = 1; j < this->Image_Width - 1; j++) {
				if (this->Pixel_Matrix[i][j] != (CSET.Black)) {
					if (States[i - 1][j] == 0 && States[i][j - 1] == 0) {
						last_label++;
						Labels.insert(std::make_pair(last_label, last_label));
						States[i][j] = last_label;
					}
					else {
						if (States[i - 1][j] == 0 && States[i][j - 1] != 0) {

							States[i][j] = Labels[((int)States[i][j - 1])];

						}
						else if (States[i - 1][j] != 0 && States[i][j - 1] == 0) {
							States[i][j] = Labels[(int)States[i - 1][j]];
						}
						else {

							if (States[i][j - 1] <= States[i - 1][j]) {
								States[i][j] = States[i][j - 1];
								Labels.insert(std::make_pair((int)States[i - 1][j], Labels[(int)States[i][j - 1]]));
							}
							else {
								States[i][j] = States[i - 1][j];
								Labels.insert(std::make_pair((int)States[i][j - 1], Labels[(int)States[i - 1][j]]));
							}

						}
					}
				}
			}


		}

		for (int i = 1; i < this->Image_Height - 1; i++) {
			for (int j = 1; j < this->Image_Width - 1; j++) {
				if (States[i][j] != 0) {
					States[i][j] = Labels[(int)States[i][j]];
				}
			}
		}

		for (int i = 1; i < this->Image_Height - 1; i++) {
			for (int j = 1; j < this->Image_Width - 1; j++) {
				if (States[i][j] != 0) {
					this->Pixel_Matrix[i][j] = CSET.Color_Serial_Number[(int)States[i][j] % 134 + 2];
				}
			}
		}
		this->Commint_Matrix_Changes();




	}
	Matrix<double> Flatten() {
		Matrix<double> res(3, this->Image_Height*this->Image_Width);
		int index = 0;
		for (int i = 0; i < this->Image_Height; i++) {
			for (int j = 0; j < this->Image_Width; j++) {
				res[0][index] = this->Pixel_Matrix[i][j].r;
				res[1][index] = this->Pixel_Matrix[i][j].g;
				res[2][index] = this->Pixel_Matrix[i][j].b;
				index++;
			}
		}
		return res;
	}
	Image Slice(int y0, int x0, int x1, int y1) {
		Image res;
		res.Load_Blank_Canvas(std::abs(y1 - y0), std::abs(x1 - x0), Pixel(0, 0, 0));
		// std::cout << "W: " << std::abs(x1 - x0) << std::endl;

		int di = 0, dj = 0;
		for (int i = y0; i < y1; i++) {
			for (int j = x0; j < x1; j++) {
				res.Pixel_Matrix[di][dj] = this->Pixel_Matrix[i][j];
				res.Set_Color(di, dj, this->Get_Color(i, j));
				dj++;
			}
			di++;
			dj = 0;
		}
		return res;

	}
	Image MaxPooling(int filter_height, int filter_width, int stride) {
		Image output;

		this->Zero_Padding();
		output.Load_Blank_Canvas(this->Image_Height / (filter_height), (this->Image_Width / (filter_width)), Pixel(0, 0, 0));
		//std::cout << "H: " << this->Image_Height / (filter_height + stride) << " ,W : " << this->Image_Width / (filter_width+stride) << std::endl;

		Pixel max(0, 0, 0);

		int ddi = 0, ddj = 0;

		for (int i = 1; i < this->Image_Height - 1; i += stride) {
			for (int j = 1; j < this->Image_Width - 1; j += stride) {



				for (int di = i; di < i + filter_height; di++) {
					for (int dj = j; dj < (j + filter_width); dj++) {

						if (this->Pixel_Matrix[di][dj] > max) {
							max = this->Pixel_Matrix[di][dj];
						}

					}

				}


				output.Pixel_Matrix[ddi][ddj] = max;
				ddj++;
				max.r = max.g = max.b = 0;
			}
			ddi++;
			ddj = 0;

		}

		output.Commint_Matrix_Changes();
		return output;
	}

	Image Generate_Perlin_Noise(int const &im_height,int const &im_width) {

	}


private:
	Pixel get_Larget_Pixel(Image  &img) {

		Pixel max(0, 0, 0);

		for (int i = 0; i < img.Image_Height; i++) {
			for (int j = 0; j < img.Image_Width; j++) {
				if (img[i][j] > max) {
					max = img[i][j];
				}
			}
		}
		return max;



	}

};
std::vector<Matrix<int> > RGB_Decompose(Image &source) {
	std::vector<Matrix<int> > Result(3);
	for (int i = 0; i < 3; i++) {
		Result[i] = Matrix<int>(source.Image_Height, source.Image_Width);
	}

	for (int i = 0; i < source.Image_Height; i++) {
		for (int j = 0; j < source.Image_Width; j++) {
			Result[0][i][j] = source[i][j].r;
			Result[1][i][j] = source[i][j].g;
			Result[2][i][j] = source[i][j].b;

		}
	}

	return Result;

}

Image Matrix_To_Graysacle(Matrix<double> &source) {
	Image Res;
	Res.Load_Blank_Canvas(source.Rows, source.Cols, Pixel(0, 0, 0));
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			Res[i][j].r = (int)source[i][j];
			Res[i][j].g = (int)source[i][j];
			Res[i][j].b = (int)source[i][j];

		}
	}
	Res.Commint_Matrix_Changes();

	return Res;
}
Image Matrix_To_Graysacle(Matrix<int> &source) {
	Image Res;
	Res.Load_Blank_Canvas(source.Rows, source.Cols, Pixel(0, 0, 0));
	for (int i = 0; i < source.Rows; i++) {
		for (int j = 0; j < source.Cols; j++) {
			Res[i][j].r = (int)source[i][j];
			Res[i][j].g = (int)source[i][j];
			Res[i][j].b = (int)source[i][j];

		}
	}
	Res.Commint_Matrix_Changes();

	return Res;
}

Image Matrix_To_Graysacle(std::vector<std::vector<double> > &source) {
	Image Res;
	Res.Load_Blank_Canvas((int)source.size(), (int)source[0].size(), Pixel(0, 0, 0));
	for (int i = 0; i < source.size(); i++) {
		for (int j = 0; j < source[0].size(); j++) {
			Res[i][j].r = (int)source[i][j];
			Res[i][j].g = (int)source[i][j];
			Res[i][j].b = (int)source[i][j];

		}
	}
	Res.Commint_Matrix_Changes();
	return Res;
}

Complex_Matrix Discrete_Fourier_Transform(Image &source) {
	std::vector<std::vector<Complex> > Fourier_Matrix;
	Fourier_Matrix.reserve(source.Image_Height);
	std::vector<std::vector<Complex> > Fourier_Matrix_B(source.Image_Height, std::vector<Complex>(source.Image_Width));
	Fourier_Matrix_B.reserve(source.Image_Height);

	std::vector<Matrix<int> > RGB = RGB_Decompose(source);

	for (int i = 0; i < source.Image_Height; i++) {
		std::vector<int> sample_row;
		sample_row.reserve(source.Image_Width);
		sample_row = RGB[0][i];
		Fourier_Matrix.emplace_back(Discrete_Fourier_Transform(sample_row));

	}

	for (int i = 0; i < source.Image_Width; i++) {
		std::vector<Complex> sample_row;
		sample_row.reserve(source.Image_Height);

		for (int j = 0; j < source.Image_Height; j++) {
			sample_row.emplace_back(Fourier_Matrix[j][i]);
		}

		//FFT(sample_row);
		sample_row = Discrete_Fourier_Transform(sample_row);

		


		for (int j = 0; j < source.Image_Height; j++) {
			Fourier_Matrix_B[j][i] = sample_row[j];
		}
	}

	return Fourier_Matrix_B;

}
Complex_Matrix Discrete_Fourier_Transform_Shift(Complex_Matrix &source) {

	Complex_Matrix shifted = Complex_Matrix(source);

	int h = source.size(), w = source[0].size();
	for (int i = 0; i < h / 2; i++) {
		for (int j = 0; j < w / 2; j++) {

			std::swap(shifted[i][j], shifted[(h / 2) + i][(w / 2) + j]);
		}
	}

	for (int i = h / 2; i < h ; i++) {
		for (int j = 0; j < w/2; j++) {
			std::swap(shifted[i][j], shifted[i - (h / 2)][j + (w / 2)]);
		}
	}

	return shifted;

}
Complex_Matrix Discrete_Fourier_Transform_Reverse_Shift(Complex_Matrix &source) {

	Complex_Matrix shifted = Complex_Matrix(source);

	int h = source.size(), w = source[0].size();
	for (int i = 0; i < h / 2; i++) {
		for (int j = 0; j < w / 2; j++) {

			std::swap(shifted[i][j], shifted[(h / 2) + i][(w / 2) + j]);
		}
	}

	for (int i = h / 2; i < h; i++) {
		for (int j = 0; j < w / 2; j++) {
			std::swap(shifted[i][j], shifted[i - (h / 2)][j + (w / 2)]);
		}
	}

	return shifted;

}
Matrix<double> Reverse_Discrete_Fourier_Transform(Complex_Matrix &source) {
	int h = source.size(), w = source[0].size();
	Complex_Matrix Fourier_Matrix;
	for (int i = 0; i < h; i++) {
		Fourier_Matrix.push_back(std::vector<Complex>(w));
	}
	

	Matrix<double> Fourier_Matrix_B(h,w);

	for (int i = 0; i < h; i++) {
		std::vector<Complex> sample_row;

		for (int j = 0; j < w; j++) {
			sample_row.push_back(source[i][j]);
		}

		sample_row = Reverse_Discrete_Fourier_Transform_Complex(sample_row);
		for (int j = 0; j < w; j++) {
			Fourier_Matrix[i][j] = sample_row[j];
		}

	}

	for (int i = 0; i < w; i++) {
		std::vector<Complex> sample_row;

		for (int j = 0; j < h; j++) {
			sample_row.push_back(Fourier_Matrix[j][i]);
		}

		std::vector<double> res = Reverse_Discrete_Fourier_Transform(sample_row);

		for (int j = 0; j < h; j++) {
			Fourier_Matrix_B[j][i] = res[j];
		}
	}

	return Fourier_Matrix_B;

}
std::pair<Image, Image> Fourier_Matrix_To_Image(std::vector<std::vector<Complex> > const &Complex_Matrix,int const& light_mag = 15) {
	Image amplitude, phase;
	int h = Complex_Matrix.size(), w = Complex_Matrix[0].size();
	Color_Palette CSET;
	amplitude.Load_Blank_Canvas(h, w, CSET.White);
	phase.Load_Blank_Canvas(h, w, CSET.White);

	int v = light_mag;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			amplitude.Set_Color(i, j, Pixel(v*std::log10(std::abs(Complex_Matrix[i][j].Real)), v*std::log10(std::abs(Complex_Matrix[i][j].Real)), v*std::log10(std::abs(Complex_Matrix[i][j].Real))));
			phase.Set_Color(i, j, Pixel(v*std::log10(std::abs(Complex_Matrix[i][j].Imaginary)), v*std::log10(std::abs(Complex_Matrix[i][j].Imaginary)), v*std::log10(std::abs(Complex_Matrix[i][j].Imaginary))));


		}
	}


	return std::pair<Image, Image>(amplitude, phase);
}








namespace SPlot {
	class Scatter_Plot {
	private:
		Image Plot;
		std::vector<std::pair<std::pair<double, double>, Pixel > > Data;
		double Max_X, Max_Y, Min_Y, Min_X;
		std::string x_label, y_label;
		Color_Palette CSET;
		int mode;
	public:
		Scatter_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
			Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
			Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Scatter_Plot(std::vector<double> x_Values, std::vector<double> y_Values, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < x_Values.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(std::pair<double, double>(x_Values[i], y_Values[i]), CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (x_Values[i] > Max_X) {
					Max_X = x_Values[i];
				}
				if (x_Values[i] < Min_X) {
					Min_X = x_Values[i];
				}
				if (y_Values[i] > Max_Y) {
					Max_Y = y_Values[i];
				}
				if (y_Values[i] < Min_Y) {
					Min_Y = y_Values[i];
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Scatter_Plot(std::vector<ScatterDot > data, std::string X_Label, std::string Y_Label) {
			Data = data;
			x_label = X_Label;
			y_label = Y_Label;
			mode = Draw_Modes::DEFAULT;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (Data[i].first.first > Max_X) {
					Max_X = Data[i].first.first;
				}
				if (Data[i].first.first < Min_X) {
					Min_X = Data[i].first.first;
				}
				if (Data[i].first.second > Max_Y) {
					Max_Y = Data[i].first.second;
				}
				if (Data[i].first.second < Min_Y) {
					Min_Y = Data[i].first.second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);
		}
		Scatter_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label, Pixel const &color) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], color));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		void Save_Plot(std::string File_Name) {

			Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
			Plot.Draw_Square(75, 100, 575, 725, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(74, 99, 576, 726, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(73, 98, 577, 727, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Text(325, 750, y_label, CSET.Black);
			Plot.Draw_Text(65, 400, x_label, CSET.Black);
			double distX = (std::abs(Min_X) + std::abs(Max_X)) / 4;
			double distY = (std::abs(Min_Y) + std::abs(Max_Y)) / 4;

			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(2);

			Plot.Draw_Text(595, 90 + 0 * 78 * 2, GetPointTwoPrecision(Min_X), CSET.Black);

			Plot.Draw_Text(595, 99 + 1 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 1)), CSET.Black);

			Plot.Draw_Text(595, 99 + 2 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 2)), CSET.Black);

			Plot.Draw_Text(595, 99 + 3 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 3)), CSET.Black);



			Plot.Draw_Text(595, 99 + 4 * 78 * 2, GetPointTwoPrecision(Max_X), CSET.Black);


			Plot.Draw_Text(575 - 0 * 62 * 2, 40, GetPointTwoPrecision(Min_Y), CSET.Black);

			Plot.Draw_Text(575 - 1 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 1)), CSET.Black);

			Plot.Draw_Text(575 - 2 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 2)), CSET.Black);


			Plot.Draw_Text(575 - 3 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 3)), CSET.Black);

			Plot.Draw_Text(575 - 4 * 62 * 2, 40, GetPointTwoPrecision(Max_Y), CSET.Black);


			if (mode == S_GRID) {

				for (int i = 0; i < 5; i++) {
					Plot.Draw_Line(575 - 62 * i * 2, 90, 575 - 62 * i * 2, 725, CSET.Black);

					Plot.Draw_Line(575, 100 + i * 78 * 2, 75, 100 + i * 78 * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * 78 * 2, 575 + 10, 99 + i * 78 * 2, CSET.Black);



				}

			}
			else if (mode == Draw_Modes::DEFAULT) {
				for (int i = 0; i < 5; i++) {

					Plot.Draw_Line(575 - 62 * i * 2, 100, 575 - 62 * i * 2, 90, CSET.Black);

					Plot.Draw_Line(575, 100 + i * 78 * 2, 575 + 10, 100 + i * 78 * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * 78 * 2, 575 + 10, 99 + i * 78 * 2, CSET.Black);



				}
			}

			double tx, ty;
			std::pair<double, double> b;
			Plot.Update_Pixel_Matrix();
			for (int i = 0; i < Data.size(); i++) {
				b = Data[i].first;
				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);
				Plot.Draw_Circle((int)tx, (int)ty, 3, Data[i].second, Draw_Modes::ANTIALIAS_FILLED);
				Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);
			}

			Plot.Write_Image(File_Name);
		}
		void Add_Point(double const &x, double const &y, Pixel const &color) {
			for (int i = 0; i < Data.size(); i++) {
				if (x > Max_X) {
					Max_X = x;
				}
				if (x < Min_X) {
					Min_X = x;
				}
				if (y > Max_Y) {
					Max_Y = y;
				}
				if (y < Min_Y) {
					Min_Y = y;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;
			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			Data.push_back(ScatterDot(std::pair<double, double>(x, y), color));
		}
		Image Get_Image() {
			return Plot;
		}
		void Set_Mode(int Mode) {
			this->mode = Mode;
		}
	};

	class Stem_Plot {
	private:
		Image Plot;
		std::vector<std::pair<std::pair<double, double>, Pixel > > Data;
		double Max_X, Max_Y, Min_Y, Min_X;
		std::string x_label, y_label;
		Color_Palette CSET;
		int mode = Draw_Modes::DEFAULT;
		std::vector<int> seperators;

	public:
		Stem_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Stem_Plot(std::vector<std::pair<int, double> > data, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			//Max_X += Max_X / 1000;
			//Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}

		Stem_Plot(std::vector<double> x_Values, std::vector<double> y_Values, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < x_Values.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(std::pair<double, double>(x_Values[i], y_Values[i]), CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (x_Values[i] > Max_X) {
					Max_X = x_Values[i];
				}
				if (x_Values[i] < Min_X) {
					Min_X = x_Values[i];
				}
				if (y_Values[i] > Max_Y) {
					Max_Y = y_Values[i];
				}
				if (y_Values[i] < Min_Y) {
					Min_Y = y_Values[i];
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Stem_Plot(std::vector<ScatterDot > data, std::string X_Label, std::string Y_Label) {
			Data = data;
			x_label = X_Label;
			y_label = Y_Label;
			mode = Draw_Modes::DEFAULT;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (Data[i].first.first > Max_X) {
					Max_X = Data[i].first.first;
				}
				if (Data[i].first.first < Min_X) {
					Min_X = Data[i].first.first;
				}
				if (Data[i].first.second > Max_Y) {
					Max_Y = Data[i].first.second;
				}
				if (Data[i].first.second < Min_Y) {
					Min_Y = Data[i].first.second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);
		}
		Stem_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label, Pixel const &color) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], color));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		void Save_Plot(std::string File_Name,int mod=0) {
			
			Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
			Plot.Draw_Square(75, 100, 575, 725, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(74, 99, 576, 726, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(73, 98, 577, 727, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Text(325, 750, y_label, CSET.Black);
			Plot.Draw_Text(65, 400, x_label, CSET.Black);
			double xx, yy;

			if (this->Min_X < 0) {
				xx = Remap((float)0, (float)Min_X, (float)Max_X, 105, 720);
				yy = Remap((float)0, (float)(Min_Y), (float)Max_Y, 565, 80);
				Plot.Draw_Line(575, xx, 76, xx, CSET.Black);
				Plot.Draw_Line(620, xx + 1, 76, xx + 1, CSET.Dark_Gray);
				Plot.Draw_Text(630, (int)xx - 4, "0", CSET.Black);

			}
			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(2);
			double amount = 419 / 4;
			double amounty = 335 / 4;
			double distX = (std::abs(Min_X) + std::abs(Max_X)) / 4;
			double distY = (std::abs(Min_Y) + std::abs(Max_Y)) / 4;
			for (int m = 0; m < 4 - 1; m++) {
				xx = Remap((float)99 + m * amount * 2, (float)105, (float)720, Min_X, Max_X);


				Plot.Draw_Text(595, (int)(99 + m * amount * 2), GetPointTwoPrecision((xx)), CSET.Black);

			}
			Plot.Draw_Text(595, (int)(90 + (4 - 1) * amount * 2), GetPointTwoPrecision(Max_X), CSET.Black);





			for (int m = 0; m < 4 - 1; m++) {
				yy = Remap((float)575 - m * amounty * 2, (float)(565), (float)80, Min_Y, Max_Y);

				Plot.Draw_Text((int)(575 - m * amounty * 2), 40, GetPointTwoPrecision(yy), CSET.Black);

			}
			Plot.Draw_Text((int)(575 - (4 - 1) * amounty * 2), 40, GetPointTwoPrecision(Max_Y), CSET.Black);



			if (mode == S_GRID) {

				for (int i = 0; i < 5; i++) {
					Plot.Draw_Line(575 - 62 * i * 2, 90, 575 - 62 * i * 2, 725, CSET.Black);

					Plot.Draw_Line(575, 100 + i * 78 * 2, 75, 100 + i * 78 * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * 78 * 2, 575 + 10, 99 + i * 78 * 2, CSET.Black);



				}

			}
			else if (mode == Draw_Modes::DEFAULT) {
				for (int i = 0; i < 4; i++) {

					double amount = 419 / 4;
					double amounty = 335 / 4;
					for (int i = 0; i < 4; i++) {
						Plot.Draw_Line(575 - amounty * i * 2, 100, 575 - amounty * i * 2, 90, CSET.Black);

						Plot.Draw_Line(575, 100 + i * amount * 2, 575 + 10, 100 + i * amount * 2, CSET.Black);
						Plot.Draw_Line(575, 99 + i * amount * 2, 575 + 10, 99 + i * amount * 2, CSET.Black);



					}


				}
			}


			Plot.Draw_Line(327, 100, 327, 725, CSET.Black);
			Plot.Draw_Line(326, 100, 326, 725, CSET.Black);


			if (mod == 0) {
				double tx, ty;
				std::pair<double, double> b;
				Plot.Update_Pixel_Matrix();
				for (int i = 0; i < Data.size(); i++) {
					b = Data[i].first;
					tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
					ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);
					Plot.Draw_Line((int)ty, (int)tx, 326, (int)tx, Data[i].second);
					Plot.Draw_Circle((int)tx, (int)ty, 3, Data[i].second, Draw_Modes::ANTIALIAS_FILLED);
					Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);

				}
			}
			else if (mod == S_CONNECTED) {
				double tx, ty, tx2, ty2;
			std::pair<double, double> b, b2;
			Plot.Update_Pixel_Matrix();
			for (int i = 0; i < Data.size() - 1; i++) {
				b = Data[i].first;
				b2 = Data[i + 1].first;

				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

				tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
				ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);


				if (seperators.size() != 0 && i == seperators[0]) {
					seperators.erase(seperators.begin());
				}
				else {
					for (double z = 0; z <= 1; z += 0.001) {
						int nty = SmoothStep_Interpolate(ty, ty2, z);
						int ntx = Remap(z, 0, 1, tx, tx2);
						Plot.Set_Color(nty, ntx, Data[i].second);

					}
					Plot.Draw_Line((int)ty, (int)tx, 326, (int)tx, Data[i].second);			
				}
			}
				b = Data[Data.size()- 2].first;
				b2 = Data[Data.size() - 1].first;

				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

				tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
				ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);

				for (double z = 0; z <= 1; z += 0.001) {
					int nty = Cosine_Interpolate(ty, ty2, z);
					int ntx = Remap(z, 0, 1, tx, tx2);
					Plot.Set_Color(nty, ntx, Data[Data.size() - 1].second);

				}

				Plot.Draw_Line((int)ty2, (int)tx2, 326, (int)tx2, Data[Data.size() - 1].second);



				for (int i = 0; i < Data.size() - 1; i++) {
					b = Data[i].first;
					b2 = Data[i + 1].first;

					tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
					ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

					tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
					ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);


					Plot.Draw_Circle((int)tx, (int)ty, 3, Data[i].second, Draw_Modes::ANTIALIAS_FILLED);
					Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);

				}

				//last point
				b = Data[Data.size() - 1].first;
				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);
				Plot.Draw_Circle((int)tx, (int)ty, 3, Data[Data.size()-1].second, Draw_Modes::ANTIALIAS_FILLED);
				Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);
			}
			Plot.Write_Image(File_Name);
		}

		void Add_Point(double const &x, double const &y, Pixel const &color) {
			for (int i = 0; i < Data.size(); i++) {
				if (x > Max_X) {
					Max_X = x;
				}
				if (x < Min_X) {
					Min_X = x;
				}
				if (y > Max_Y) {
					Max_Y = y;
				}
				if (y < Min_Y) {
					Min_Y = y;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;
			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			Data.push_back(ScatterDot(std::pair<double, double>(x, y), color));
		}
		void Add_Point(std::vector<std::pair<double, double> > new_points, Pixel const &color) {
			seperators.push_back((int)(this->Data.size() - 1));
			for (int i = 0; i < new_points.size(); i++) {
				if (new_points[i].first > Max_X) {
					Max_X = new_points[i].first;
				}
				if (new_points[i].first < Min_X) {
					Min_X = new_points[i].first;
				}
				if (new_points[i].second > Max_Y) {
					Max_Y = new_points[i].second;
				}
				if (new_points[i].second < Min_Y) {
					Min_Y = new_points[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			for (int i = 0; i < new_points.size(); i++) {
				Data.push_back(ScatterDot(new_points[i], color));

			}
		}
		void Add_Point(std::vector<std::pair<int, double> > new_points, Pixel const &color) {
			seperators.push_back((int)(this->Data.size() - 1));
			for (int i = 0; i < new_points.size(); i++) {
				if (new_points[i].first > Max_X) {
					Max_X = new_points[i].first;
				}
				if (new_points[i].first < Min_X) {
					Min_X = new_points[i].first;
				}
				if (new_points[i].second > Max_Y) {
					Max_Y = new_points[i].second;
				}
				if (new_points[i].second < Min_Y) {
					Min_Y = new_points[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			for (int i = 0; i < new_points.size(); i++) {
				Data.push_back(ScatterDot(new_points[i], color));

			}
		}


		Image Get_Image() {
			return Plot;
		}
		void Set_Mode(int Mode) {
			this->mode = Mode;
		}
	};

	class Line_Plot {
	private:
		Image Plot;
		std::vector<std::pair<std::pair<double, double>, Pixel > > Data;
		double Max_X, Max_Y, Min_Y, Min_X;
		std::string x_label, y_label;
		Color_Palette CSET;
		int mode;
		std::vector<int> seperators;
	public:
		Line_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Line_Plot(std::vector<std::pair<int, double> > data, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
	

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}


		Line_Plot(std::vector<double> x_Values, std::vector<double> y_Values, std::string X_Label, std::string Y_Label) {
			for (int i = 0; i < x_Values.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(std::pair<double, double>(x_Values[i], y_Values[i]), CSET.Royal_Blue));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (x_Values[i] > Max_X) {
					Max_X = x_Values[i];
				}
				if (x_Values[i] < Min_X) {
					Min_X = x_Values[i];
				}
				if (y_Values[i] > Max_Y) {
					Max_Y = y_Values[i];
				}
				if (y_Values[i] < Min_Y) {
					Min_Y = y_Values[i];
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		Line_Plot(std::vector<ScatterDot > data, std::string X_Label, std::string Y_Label) {
			Data = data;
			x_label = X_Label;
			y_label = Y_Label;
			mode = Draw_Modes::DEFAULT;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (Data[i].first.first > Max_X) {
					Max_X = Data[i].first.first;
				}
				if (Data[i].first.first < Min_X) {
					Min_X = Data[i].first.first;
				}
				if (Data[i].first.second > Max_Y) {
					Max_Y = Data[i].first.second;
				}
				if (Data[i].first.second < Min_Y) {
					Min_Y = Data[i].first.second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);
		}
		Line_Plot(std::vector<std::pair<double, double> > data, std::string X_Label, std::string Y_Label, Pixel const &color) {
			for (int i = 0; i < data.size(); i++) {
				Data.push_back(std::pair<std::pair<double, double>, Pixel >(data[i], color));
			}
			mode = Draw_Modes::DEFAULT;
			x_label = X_Label;
			y_label = Y_Label;
			Max_X = std::numeric_limits<double>::min(),
				Max_Y = std::numeric_limits<double>::min();
			Min_X = std::numeric_limits<double>::max(),
				Min_Y = std::numeric_limits<double>::max();

			for (int i = 0; i < Data.size(); i++) {
				if (data[i].first > Max_X) {
					Max_X = data[i].first;
				}
				if (data[i].first < Min_X) {
					Min_X = data[i].first;
				}
				if (data[i].second > Max_Y) {
					Max_Y = data[i].second;
				}
				if (data[i].second < Min_Y) {
					Min_Y = data[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);


		}
		void Save_Plot(std::string File_Name, int markings=4) {

			Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
			Plot.Draw_Square(75, 100, 575, 725, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(74, 99, 576, 726, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(73, 98, 577, 727, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Text(325, 730, y_label, CSET.Black);
			Plot.Draw_Text(65, 400, x_label, CSET.Black);
			double xx, yy;

			if (this->Min_X < 0) {
				xx = Remap((float)0, (float)Min_X, (float)Max_X, 105, 720);
				yy = Remap((float)0, (float)(Min_Y), (float)Max_Y, 565, 80);
				Plot.Draw_Line(575, (int)(xx), 76, xx, CSET.Dark_Gray);
				Plot.Draw_Line(620, (int)(xx + 1), 76, xx + 1, CSET.Dark_Gray);
				Plot.Draw_Text(630, (int)(xx-4), "0", CSET.Black);

			}


			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(2);
			double amount = 419 / markings;
			double amounty = 335 / markings;
			double distX = (std::abs(Min_X) + std::abs(Max_X)) / markings;
			double distY = (std::abs(Min_Y) + std::abs(Max_Y)) / markings;

			for (int m = 0; m < markings-1; m++) {
				xx = Remap((float)99 + m * amount * 2, (float)105, (float)720, Min_X, Max_X);


				Plot.Draw_Text(595, (int)(99 + m * amount * 2), GetPointTwoPrecision((xx)), CSET.Black);

			}
			Plot.Draw_Text(595, (int)(90 + (markings-1) * amount * 2), GetPointTwoPrecision(Max_X), CSET.Black);





			for (int m = 0; m < markings-1 ; m++) {
				yy = Remap((float)575 - m * amounty * 2, (float)(565), (float)80, Min_Y, Max_Y);

				Plot.Draw_Text((int)(575 - m * amounty * 2), 40, GetPointTwoPrecision(yy), CSET.Black);

			}
			Plot.Draw_Text((int)(575 - (markings - 1) * amounty * 2), 40, GetPointTwoPrecision(Max_Y), CSET.Black);





			if (mode == S_GRID) {
				amount = 419 / markings;
				amounty = 335 / markings;;
				for (int i = 0; i < markings; i++) {
					Plot.Draw_Line(575 - amounty * i * 2, 90, 575 - amounty * i * 2, 725, CSET.Black);

					Plot.Draw_Line(575, 100 + i * amount * 2, 75, 100 + i * amount * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * amount * 2, 575 + 10, 99 + i * amount * 2, CSET.Black);



				}

			}
			else if (mode == Draw_Modes::DEFAULT) {
				 amount = 419 / markings;
				 amounty = 335 / markings;
				for (int i = 0; i < markings; i++) {

					Plot.Draw_Line(575 - amounty * i * 2, 100, 575 - amounty * i * 2, 90, CSET.Black);

					Plot.Draw_Line(575, 100 + i * amount * 2, 575 + 10, 100 + i * amount * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * amount * 2, 575 + 10, 99 + i * amount * 2, CSET.Black);



				}
			}

			double tx, ty, tx2, ty2;
			std::pair<double, double> b, b2;
			Plot.Update_Pixel_Matrix();
			for (int i = 0; i < Data.size() - 1; i++) {
				b = Data[i].first;
				b2 = Data[i + 1].first;

				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

				tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
				ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);


				if (seperators.size() != 0 && i == seperators[0]) {
					seperators.erase(seperators.begin());
				}
				else {
					//Plot.Draw_Circle(tx, ty, 5, CSET.Red,  Draw_Modes::ANTIALIADraw_Modes::FILLED);
					//Cosine_Interpolate()


					for (double z = 0; z <= 1; z += 0.001) {
						int nty = SmoothStep_Interpolate(ty, ty2, z);
						int ntx = Remap(z, 0, 1, tx, tx2);
						Plot.Set_Color(nty, ntx, Data[i].second);


					}


					//Plot.Draw_Line((int)tx, (int)ty, (int)tx2, (int)nty, Data[i].second,  Draw_Modes::ANTIALIAS_LINE);
			
				}

				//Plot.Draw_Circle((int)tx, (int)ty, 3, Data[i].second,  Draw_Modes::ANTIALIADraw_Modes::FILLED);
				//Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);
			}
			b = Data[Data.size()- 2].first;
			b2 = Data[Data.size() - 1].first;

			tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
			ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

			tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
			ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);

			for (double z = 0; z <= 1; z += 0.001) {
				int nty = SmoothStep_Interpolate(ty, ty2, z);
				int ntx = Remap(z, 0, 1, tx, tx2);
				Plot.Set_Color(nty, ntx, Data[Data.size() - 1].second);

			}

			//Plot.Draw_Circle((int)tx, (int)ty, 3, Data[Data.size() - 1].second,  Draw_Modes::ANTIALIADraw_Modes::FILLED);
			//Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);

		
			Plot.Write_Image(File_Name);
		}
		void Add_Point(double const &x, double const &y, Pixel const &color) {
			seperators.push_back((int)(this->Data.size() - 1));
			for (int i = 0; i < Data.size(); i++) {
				if (x > Max_X) {
					Max_X = x;
				}
				if (x < Min_X) {
					Min_X = x;
				}
				if (y > Max_Y) {
					Max_Y = y;
				}
				if (y < Min_Y) {
					Min_Y = y;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;
			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			Data.push_back(ScatterDot(std::pair<double, double>(x, y), color));
		}
		void Add_Point(std::vector<std::pair<double, double> > new_points, Pixel const &color) {
			seperators.push_back((int)(this->Data.size() - 1));
			
			for (int i = 0; i < new_points.size(); i++) {
				if (new_points[i].first > Max_X) {
					Max_X = new_points[i].first;
				}
				if (new_points[i].first < Min_X) {
					Min_X = new_points[i].first;
				}
				if (new_points[i].second > Max_Y) {
					Max_Y = new_points[i].second;
				}
				if (new_points[i].second < Min_Y) {
					Min_Y = new_points[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			for (int i = 0; i < new_points.size(); i++) {
				Data.push_back(ScatterDot(new_points[i], color));

			}
		}
		void Add_Point(std::vector<std::pair<int, double> > new_points, Pixel const &color) {
			seperators.push_back((int)(this->Data.size() - 1));
			for (int i = 0; i < new_points.size(); i++) {
				if (new_points[i].first > Max_X) {
					Max_X = new_points[i].first;
				}
				if (new_points[i].first < Min_X) {
					Min_X = new_points[i].first;
				}
				if (new_points[i].second > Max_Y) {
					Max_Y = new_points[i].second;
				}
				if (new_points[i].second < Min_Y) {
					Min_Y = new_points[i].second;
				}
			}
			Max_X += Max_X / 1000;
			Max_Y += Max_Y / 1000;

			Max_X = std::round(Max_X);
			Max_Y = std::round(Max_Y);

			for (int i = 0; i < new_points.size(); i++) {
				Data.push_back(ScatterDot(new_points[i], color));

			}
		}



		Image Get_Image() {
			Plot.Load_Blank_Canvas(650, 800, CSET.White_Smoke);
			Plot.Draw_Square(75, 100, 575, 725, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(74, 99, 576, 726, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Square(73, 98, 577, 727, CSET.Black, Draw_Modes::CORNERS);
			Plot.Draw_Text(325, 750, y_label, CSET.Black);
			Plot.Draw_Text(65, 400, x_label, CSET.Black);
			double distX = (std::abs(Min_X) + std::abs(Max_X)) / 4;
			double distY = (std::abs(Min_Y) + std::abs(Max_Y)) / 4;

			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(2);

			Plot.Draw_Text(595, 90 + 0 * 78 * 2, GetPointTwoPrecision(Min_X), CSET.Black);

			Plot.Draw_Text(595, 99 + 1 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 1)), CSET.Black);

			Plot.Draw_Text(595, 99 + 2 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 2)), CSET.Black);

			Plot.Draw_Text(595, 99 + 3 * 78 * 2, GetPointTwoPrecision(((Min_X)+distX * 3)), CSET.Black);



			Plot.Draw_Text(595, 99 + 4 * 78 * 2, GetPointTwoPrecision(Max_X), CSET.Black);


			Plot.Draw_Text(575 - 0 * 62 * 2, 40, GetPointTwoPrecision(Min_Y), CSET.Black);

			Plot.Draw_Text(575 - 1 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 1)), CSET.Black);

			Plot.Draw_Text(575 - 2 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 2)), CSET.Black);


			Plot.Draw_Text(575 - 3 * 62 * 2, 40, GetPointTwoPrecision(((Min_Y)+distY * 3)), CSET.Black);

			Plot.Draw_Text(575 - 4 * 62 * 2, 40, GetPointTwoPrecision(Max_Y), CSET.Black);


			if (mode == S_GRID) {

				for (int i = 0; i < 5; i++) {
					Plot.Draw_Line(575 - 62 * i * 2, 90, 575 - 62 * i * 2, 725, CSET.Black);

					Plot.Draw_Line(575, 100 + i * 78 * 2, 75, 100 + i * 78 * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * 78 * 2, 575 + 10, 99 + i * 78 * 2, CSET.Black);



				}

			}
			else if (mode == Draw_Modes::DEFAULT) {
				for (int i = 0; i < 5; i++) {

					Plot.Draw_Line(575 - 62 * i * 2, 100, 575 - 62 * i * 2, 90, CSET.Black);

					Plot.Draw_Line(575, 100 + i * 78 * 2, 575 + 10, 100 + i * 78 * 2, CSET.Black);
					Plot.Draw_Line(575, 99 + i * 78 * 2, 575 + 10, 99 + i * 78 * 2, CSET.Black);



				}
			}

			double tx, ty, tx2, ty2;
			std::pair<double, double> b, b2;
			Plot.Update_Pixel_Matrix();
			for (int i = 0; i < Data.size() - 1; i++) {
				b = Data[i].first;
				b2 = Data[i + 1].first;

				tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
				ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);

				tx2 = Remap((float)b2.first, (float)Min_X, (float)Max_X, 105, 720);
				ty2 = Remap((float)b2.second, (float)(Min_Y), (float)Max_Y, 565, 80);



				Plot.Draw_Line((int)tx, (int)ty, (int)tx2, (int)ty2, Data[i].second,  Draw_Modes::ANTIALIAS_LINE);

				Plot.Draw_Circle((int)tx, (int)ty, 3, Data[i].second,  Draw_Modes::ANTIALIAS_FILLED);
				Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);
			}
			b = Data[Data.size() - 1].first;
			tx = Remap((float)b.first, (float)Min_X, (float)Max_X, 105, 720);
			ty = Remap((float)b.second, (float)(Min_Y), (float)Max_Y, 565, 80);
			Plot.Draw_Circle((int)tx, (int)ty, 3, Data[Data.size() - 1].second, Draw_Modes::ANTIALIAS_FILLED);
			Plot.Draw_Circle((int)tx, (int)ty, 4, CSET.White_Smoke,  Draw_Modes::ANTIALIAS_HOLLOW);

			return Plot;
		}
		void Set_Mode(int Mode) {
			this->mode = Mode;
		}
	};




	void Save_Bar_Plot(std::vector<int> data, std::vector<std::string> Categories, std::string file_name) {
		Color_Palette CSET;
		double max_y = getMax(data);
		int spaces = 400 / (int)data.size();
		double divider = 1;

		if (max_y >= 400) {
			divider = (int)max_y / 400;
		}
		else {
			divider = 1 / ((double)400 / max_y);
		}
		Image histo;
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100, 100, 500, 640, CSET.Black, Draw_Modes::CORNERS);
		histo.Draw_Square(99, 99, 501, 641, CSET.Black, Draw_Modes::CORNERS);
		histo.Draw_Square(98, 98, 502, 642, CSET.Black, Draw_Modes::CORNERS);

		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		histo.Draw_Text(102, 40, std::to_string(max_y), CSET.Black);
		for (int i = 0; i <= 400; i += 101) {
			histo.Draw_Line(501 - (i), 100, 501 - (i), 92, CSET.Black);

		}


		histo.Draw_Text(400, 40, std::to_string((max_y / 100) * 25), CSET.Black);
		histo.Draw_Text(299, 40, std::to_string((max_y / 100) * 50), CSET.Black);
		histo.Draw_Text(198, 40, std::to_string((max_y / 100) * 75), CSET.Black);



		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);

		for (int i = 0; i <= 400; i += spaces) {
			histo.Draw_Line(499, 108 + i, 499 + 10, 108 + i, CSET.Black);

		}
		int n = 0;
		for (int i = 0; i < 400; i += spaces) {
			if (n < Categories.size()) {
				histo.Draw_Text(520, 108 + i, Categories[n], CSET.Black);
				n++;
			}
			else {
				histo.Draw_Text(520, 108 + i, " ", CSET.Black);

			}
		}
		int j = 0;
		for (int i = 0; i < 400 && j < data.size(); i += spaces) {
			Pixel rc = CSET.Get_Random_Color();
			rc.r = 30;
			histo.Draw_Line(499, 108 + i, 499 - (int)(data[j] / divider), 108 + i, rc);
			histo.Draw_Line(499, 107 + i, 499 - (int)(data[j] / divider), 107 + i, rc);
			j++;
		}

		histo.Draw_Text(90, 345, "BAR PLOT", CSET.Black);





		histo.Write_Image(file_name);
	}
	void Save_Histogram(Image source, int Channel, std::string output_name, std::string file_name) {
		std::vector<int> xxR(256, 0);
		std::vector<int> xxG(256, 0);
		std::vector<int> xxB(256, 0);


		int max_y = source.Image_Height*source.Image_Width;
		int Multiplyer = 1;
		int max_val = std::numeric_limits<int>::min();

		Color_Palette CSET;
		for (int i = 0; i < source.Image_Height; i++) {
			for (int j = 0; j < source.Image_Width; j++) {
				xxR[source.Pixel_Matrix[i][j].r]++;
				xxG[source.Pixel_Matrix[i][j].g]++;
				xxB[source.Pixel_Matrix[i][j].b]++;

			}
		}

		for (int i = 0; i < 256; i++) {
			if (xxR[i] > max_val) {
				max_val = xxR[i];
			}
			if (xxG[i] > max_val) {
				max_val = xxG[i];
			}
			if (xxB[i] > max_val) {
				max_val = xxB[i];
			}
		}
		while (max_val * Multiplyer < max_y) {

			if ((Multiplyer + 1)*max_val > max_y) {
				break;
			}
			else {
				Multiplyer++;
			}
		}

		Image histo;
		histo.Load_Blank_Canvas(600, 755, CSET.White);
		histo.Draw_Square(100, 100, 500, 640, CSET.Black, Draw_Modes::CORNERS);
		histo.Draw_Square(99, 99, 501, 641, CSET.Black, Draw_Modes::CORNERS);
		histo.Draw_Square(98, 98, 502, 642, CSET.Black, Draw_Modes::CORNERS);

		histo.Draw_Line(102, 90, 102, 99, CSET.Black);
		for (int i = 0; i <= 400; i += 101) {
			histo.Draw_Line(501 - (i), 100, 501 - (i), 92, CSET.Black);

		}
		histo.Draw_Text(400, 40, std::to_string(((max_y / Multiplyer) / 100) * 25), CSET.Black);
		histo.Draw_Text(299, 40, std::to_string(((max_y / Multiplyer) / 100) * 50), CSET.Black);
		histo.Draw_Text(198, 40, std::to_string(((max_y / Multiplyer) / 100) * 75), CSET.Black);
		histo.Draw_Text(102, 40, std::to_string(max_y / Multiplyer), CSET.Black);



		histo.Draw_Line(501, 90, 501, 99, CSET.Black);
		histo.Draw_Text(501, 70, "0", CSET.Black);

		for (int i = 0; i <= 512; i += 64) {
			histo.Draw_Line(499, 108 + i, 499 + 10, 108 + i, CSET.Black);

		}
		for (int i = 512; i >= 0; i -= 64) {
			histo.Draw_Text(520, 108 + i, std::to_string(i / 2), CSET.Black);
		}

		if (Channel == Histogram_Type::RED_HISTOGRAM) {
			histo.Draw_Text(90, 345, "RED HISTOGRAM", CSET.Black);
			for (int i = 0; i < 512; i += 2) {
				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxR[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxR[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Red);

			}

		}
		else if (Channel == Histogram_Type::GREEN_HISTOGRAM) {
			histo.Draw_Text(90, 345, "GREEN HISTOGRAM", CSET.Black);
			for (int i = 0; i < 512; i += 2) {
				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxG[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxG[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Green);
			}

		}
		else if (Channel == Histogram_Type::BLUE_HISTOGRAM) {
			histo.Draw_Text(90, 345, "BLUE HISTOGRAM", CSET.Black);
			for (int i = 0; i < 512; i += 2) {
				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxB[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxB[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Blue);

			}

		}
		else if (Channel == Histogram_Type::RGB_HISTOGRAM) {
			histo.Draw_Text(90, 345, "RGB HISTOGRAM", CSET.Black);
			for (int i = 0; i < 512; i += 2) {
				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxR[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Red);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxR[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Red);

				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxG[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Green);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxG[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Green);

				histo.Draw_Line(499, 108 + i, 499 - (int)Remap(xxB[i / 2], 0, max_y, 0, 399 * Multiplyer), 108 + i, CSET.Blue);
				histo.Draw_Line(499, 107 + i, 499 - (int)Remap(xxB[i / 2], 0, max_y, 0, 399 * Multiplyer), 107 + i, CSET.Blue);

			}

		}




		histo.Write_Image(file_name);
	}
	void Save_Pie_Plot(std::vector<double> Sizes, std::vector<std::string> Labels, std::string file_name) {
		if (Labels.size() != Sizes.size()) {
			std::cout << ("Number Of Labels And Number Of Sizes Do Not Match\n");
			return;
		}
		double sum_of_sizes = 0;
		for (int i = 0; i < Sizes.size(); i++) {
			sum_of_sizes += Sizes[i];
		}
		if (sum_of_sizes != 100) {
			std::cout << ("Total Sum Of Sizes Has To Be 100\n");
			return;
		}


		Color_Palette CSET;
		std::vector<Pixel> Colors(Sizes.size());


		for (int i = 0; i < Sizes.size(); i++) {
			Colors[i] = CSET.Color_Serial_Number[10 + i];

		}
		Image Pie;
		int divider = (int)Sizes.size();

		Pie.Load_Blank_Canvas(1200, 1600, Pixel(240, 240, 240));



		double l_start = 0;
		for (int j = 0; j < Sizes.size(); j++) {
			for (double i = l_start; i <= l_start + (Sizes[j] * 3.6); i += 0.001) {
				Pie.Draw_Line(600, 600, 600 + (int)std::round(400 * std::sin(degreesToRadians(-i))), 600 + (int)std::round((400 * std::cos(degreesToRadians(-i)))), Colors[j]);
			}
			l_start += (Sizes[j] * 3.6);
		}

		Pie.Set_Scale(600, 800);
		l_start = 0;
		for (int j = 0; j < Sizes.size(); j++) {
			//Pie.Draw_Line(600, 600, 600 +(int)std::round(400 * std::sin(std::toRadians(-i))), 600+(int)std::round((400 * std::cos(std::toRadians(-i)))), Colors[j]);

			std::ostringstream streamObj;
			streamObj << std::fixed;
			streamObj << std::setprecision(2);

			streamObj << (Sizes[j]);

			Pie.Draw_Text(300 + (int)(162 * std::sin(degreesToRadians(-(l_start + (Sizes[j] * 3.6) / 2)))), 300 + (int)(162 * std::cos(degreesToRadians(-(l_start + (Sizes[j] * 3.6) / 2)))), streamObj.str() + " %", CSET.Black);
			l_start += (Sizes[j] * 3.6);

		}

		int label_frame_h = 100;
		int addit = (int)Sizes.size() * 45;
		Pie.Draw_Square(label_frame_h - 1, 519, label_frame_h + addit - 1, 749, Pixel(50, 50, 50), Draw_Modes::CORNERS);
		Pie.Draw_Square(label_frame_h, 520, label_frame_h + addit, 750, Pixel(10, 10, 10), Draw_Modes::CORNERS);
		Pie.Draw_Square(label_frame_h + 1, 521, label_frame_h + addit + 1, 751, CSET.Black, Draw_Modes::CORNERS);

		Pie.Update_Pixel_Matrix();
		for (int i = 1; i <= Sizes.size(); i++) {
			Pie.Draw_Circle(545, label_frame_h - 20 + i * 45, 8, Colors[i - 1], Draw_Modes::FILLED);
		}
		Pie.Commint_Matrix_Changes();
		for (int i = 1; i <= Sizes.size(); i++) {
			Pie.Draw_Circle(545, label_frame_h - 20 + i * 45, 9, CSET.Black);
			Pie.Draw_Circle(545, label_frame_h - 20 + i * 45, 8, CSET.Black);

		}
		Pie.Draw_Text(80, 640, "LABELS", CSET.Black);
		for (int i = 1; i <= Sizes.size(); i++) {
			Pie.Draw_Text(label_frame_h - 20 + i * 45, 640, Labels[i - 1], CSET.Black);
		}
		Pie.Write_Image(file_name);

	}



}






/*


int text_length = (int)text.length();
int start_x, draw_y, flag = 0, temp = 0;
if (center_x + (9 * (text_length / 2)) > Image_Width || center_x - (9 * (text_length / 2)) < 0
	|| center_y + 4 > Image_Height || center_y - 4 < 0) {
	std::cout << "Text Longer The Image Frame, Aborting...\n";
	return;
}

start_x = center_x - (9 * (text_length / 2));
draw_y = center_y - 4;

for (int i = 0; i < text.length(); i++) {

	switch (text[i])
	{

	case '0':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF[2]ero[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;
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
			if (TYPELOADF.One[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Two[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Three[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Four[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Five[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Six[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Seven[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Eight[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Nine[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.A[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.B[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.C[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


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
			if (TYPELOADF.D[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.E[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


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
			if (TYPELOADF.F[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.G[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.H[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.I[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.J[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.K[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.L[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.M[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.N[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.O[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.P[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Q[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.R[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.S[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.T[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.U[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.V[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.W[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.X[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF[1][flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Z[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'a':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.a[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'b':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.b[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'c':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.c[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'd':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.d[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'e':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.e[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'f':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.f[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'g':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.g[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'h':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.h[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'i':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.i[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'j':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.j[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'k':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.k[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'l':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.l[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'm':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.m[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'n':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.n[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'o':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.o[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'p':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.p[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'q':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.q[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case 'r':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.r[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 's':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.S[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 't':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.t[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'u':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.u[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'v':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.v[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'w':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.w[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;

		break;

	case 'x':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.x[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'y':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF[1][flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;


	case 'z':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.z[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.question_mark[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.exclamation_point[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Left_Braket[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Right_Braket[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Ampersand[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


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
			if (TYPELOADF.Comma[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Square_Braket_Left[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Square_Braket_Right[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.Colon[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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
			if (TYPELOADF.EqualSign[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


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
			if (TYPELOADF.PlusSign[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case '%':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.Precent[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case '*':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.Astersik[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case '.':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.Dot[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;

	case ';':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.Semi_Colon[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;


			}
			start_x++;
			flag++;
		}

		flag = 0;
		break;
	case '-':
		temp = start_x;
		while (flag != 81) {

			if ((flag + 1) % 9 == 0) {
				draw_y++;
				start_x = temp;
			}
			if (TYPELOADF.MinusSign[flag] == 1) {
				this->Set_Color(draw_y, start_x, color);
				Pixel_Matrix[draw_y][start_x] = color;

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



	}*/
