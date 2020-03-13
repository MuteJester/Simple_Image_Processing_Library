#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <limits>
#include <random>
#include <map>

//macros


//#define PI 3.14159265359
#define TWO_PI 2*PI

//conv
#define DEG_TO_RAD(A) A * PI/180
#define RAD_TO_DEG(A) A * 180/PI
#define SQUARE_IT(NUM) NUM*NUM
#define CUBE_IT(NUM) NUM*NUM*NUM
#define METER_TO_MILLIMETER(METER) METER * 1000
#define METER_TO_CENTIMETER(METER) METER * 100
#define METER_TO_KILOMETER(METER) METER / 1000
#define INCH_TO_CENTIMETER(INCH) INCH * 2.54
#define FOOT_TO_MILLIMETER(FOOT) FOOT * 304.8
#define MILE_TO_KILOMETER(MILE) MILE * 1.609344
#define CELSIUS_TO_FAHRENHEIT(CELSIUS) ((CELSIUS/5)*9)+32
#define FAHRENHEIT_TO_CELSIUS(FAHRENHEIT) ((FAHRENHEIT-32)*5)/9

#define IDENTITY_MATRIX 'i'
#define IMG_LIB




#ifndef IMG_LIB


//matirx ops


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
	Matrix(int N, char x = IDENTITY_MATRIX) {
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
	Matrix() {
		this->Rows = 0;
		this->Cols = 0;
	}
	~Matrix() {};
	int getRows() { return Rows; }
	int getCols() { return Cols; }
	void setRows(int &Rows) { this->Rows = Rows; }
	void setCols(int &Cols) { this->Cols = Cols; }
	std::vector<MType> &operator[](int a) {
		return Matrix_Body[a];
	}
	void operator=(Matrix<MType> B) {
		this->Rows = B.getRows();
		this->Cols = B.getCols();
		this->Matrix_Body = std::vector<std::vector<MType> >(Rows, std::vector<MType>(Cols));
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] = B[i][j];
			}
		}

	}
	void operator+(Matrix<MType> &B);
	void operator-(Matrix<MType> &B);
	void Dot_Product(Matrix<MType> &B);
	void Matrix_Transpose();
	void Multiply_By_Scalar(int const &scalar);
	Matrix<MType> Hadamard_Product(Matrix<MType> &Mul_By);
	Matrix<MType> Kronecker_Product(Matrix<MType> &Mul_By);
	void Horizontal_Matrix_Concatenation(Matrix<MType> &To_HConcat);
	void Convolve(Matrix<int> &Mask, int mask_h, int mask_w);
	template<class MType> friend std::ostream &operator<<(std::ostream &out, Matrix<MType> const &mat);

protected:
	std::vector<std::vector<MType> > Matrix_Body;
	int Rows, Cols;

};
template<class MType> std::ostream &operator<<(std::ostream &out, Matrix<MType> const &mat) {
	for (int i = 0; i < mat.Rows; i++) {
		for (int j = 0; j < mat.Cols; j++) {
			out << mat.Matrix_Body[i][j] << " ";
		}
		out << "\n";
	}
	return out;
}
template<class MType> void Matrix<MType>::Matrix_Transpose() {


	Matrix<MType> temp(Cols, Rows);



	for (int i = 0; i < Cols; i++) {
		for (int j = 0; j < Rows; j++) {
			temp[i][j] = Matrix_Body[j][i];
		}
	}
	*this = temp;
}

template<class MType> void Matrix<MType>::Multiply_By_Scalar(int const &scalar) {
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Cols; j++) {
			Matrix_Body[i][j] *= scalar;
		}
	}
}

template<class MType> void Matrix<MType>::operator+(Matrix<MType> &B) {
	if (Rows != B.getRows() || Cols != B.getCols()) {
		return;
	}
	else {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] += B[i][j];
			}
		}
	}
}

template<class MType> void Matrix<MType>::operator-(Matrix<MType> &B) {
	if (Rows != B.getRows() || Cols != B.getCols()) {
		return;
	}
	else {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				Matrix_Body[i][j] -= B[i][j];
			}
		}
	}
}

template<class MType> void Matrix<MType>::Dot_Product(Matrix<MType> &B) {

	if (Cols != B.getRows()) {
		return;

	}
	else {
		MType sum = 0;
		Matrix<MType> temp(Rows, B.getCols());
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < B.getCols(); j++) {
				for (int k = 0; k < Cols; k++) {
					sum += Matrix_Body[i][k] * B[k][j];

				}
				temp[i][j] = sum;
				sum = 0;
			}
		}
		*this = temp;
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


class LA_Masks {
public:
	LA_Masks() {
		Roberts_Mask_3x3 = Matrix<int>(3, 3);
		Sobel_Mask_3x3 = Matrix<int>(3, 3);
		Identity_3x3 = Matrix<int>(3, 3);
		Sharpen_3x3 = Matrix<int>(3, 3);
		Gaussian_Blur_3x3 = Matrix<double>(3, 3);

		Roberts_Mask_3x3[0][0] = 0;
		Roberts_Mask_3x3[0][1] = 0;
		Roberts_Mask_3x3[0][2] = 0;
		Roberts_Mask_3x3[1][0] = 0;
		Roberts_Mask_3x3[1][1] = 0;
		Roberts_Mask_3x3[1][2] = 1;
		Roberts_Mask_3x3[2][0] = 0;
		Roberts_Mask_3x3[2][1] = -1;
		Roberts_Mask_3x3[2][2] = 0;

		Sobel_Mask_3x3[0][0] = -1;
		Sobel_Mask_3x3[0][1] = 0;
		Sobel_Mask_3x3[0][2] = 1;
		Sobel_Mask_3x3[1][0] = -2;
		Sobel_Mask_3x3[1][1] = 0;
		Sobel_Mask_3x3[1][2] = 2;
		Sobel_Mask_3x3[2][0] = -1;
		Sobel_Mask_3x3[2][1] = 0;
		Sobel_Mask_3x3[2][2] = 1;

		Identity_3x3[0][0] = 0;
		Identity_3x3[0][1] = 0;
		Identity_3x3[0][2] = 0;
		Identity_3x3[1][0] = 0;
		Identity_3x3[1][1] = 1;
		Identity_3x3[1][2] = 0;
		Identity_3x3[2][0] = 0;
		Identity_3x3[2][1] = 0;
		Identity_3x3[2][2] = 0;

		Sharpen_3x3[0][0] = 0;
		Sharpen_3x3[0][1] = -1;
		Sharpen_3x3[0][2] = 0;
		Sharpen_3x3[1][0] = -1;
		Sharpen_3x3[1][1] = 5;
		Sharpen_3x3[1][2] = -1;
		Sharpen_3x3[2][0] = 0;
		Sharpen_3x3[2][1] = -1;
		Sharpen_3x3[2][2] = 0;


		Gaussian_Blur_3x3[0][0] = 1 / 16;
		Gaussian_Blur_3x3[0][1] = 1 / 8;
		Gaussian_Blur_3x3[0][2] = 1 / 16;
		Gaussian_Blur_3x3[1][0] = 1 / 8;
		Gaussian_Blur_3x3[1][1] = 1 / 4;
		Gaussian_Blur_3x3[1][2] = 1 / 8;
		Gaussian_Blur_3x3[2][0] = 1 / 16;
		Gaussian_Blur_3x3[2][1] = 1 / 8;
		Gaussian_Blur_3x3[2][2] = 1 / 16;



	}
	Matrix<int> Roberts_Mask_3x3;
	Matrix<int> Sobel_Mask_3x3;
	Matrix<int> Identity_3x3;
	Matrix<int> Sharpen_3x3;
	Matrix<double> Gaussian_Blur_3x3;

};


#endif // !IMG_LIB


//symbolic


class Monomial {
public:
	double Degree;
	double Coefficient;
	double Pry;
	bool is_monom;
	bool is_cos, is_sin, is_tan, is_lan, is_E;

	Monomial();
	Monomial(int const &Coeff,int const &Deg);
	Monomial(int const &Coeff);
	Monomial(std:: string const &form);
	friend std::ostream &operator<<(std::ostream &out, Monomial const &source);
	 int operator+(Monomial const&b);
	 void operator-(Monomial const&b);
	 void operator*( Monomial const&b);
	 void operator^( int const&b);
	 void operator/(Monomial const &b);
	 void Derive();
	 void Derive(int const &mag);
	 double operator[](double const &x_value);
	 
};


void get_Cof_Deg(std::string const &to_parse,double &cof, double &deg) {
	std::stringstream ss, ss2;
	std::string via, via2;
	std::size_t pos;
	pos = to_parse.find("*");
	if (pos == std::string::npos) {
		pos = to_parse.find("x");
		if (pos == std::string::npos) {
			return;
		}
		else {
			if (to_parse[pos + 1] == '^') {
				pos += 2;
				for (std::size_t i = pos; i < to_parse.size(); i++) {
					ss << to_parse[i];
				}
				via = ss.str();
				ss.str(std::string());
				deg = std::stod(via.c_str());
				
				cof = 1;
				return;
			}
			else {
				cof = 1;
				deg = 1;
			}
		}
	}
	else {
		for (std::size_t i = 0; i < pos; i++) {
			ss << to_parse[i];
		}
		via = ss.str();
		ss.str(std::string());
		cof = atoi(via.c_str());
		pos = to_parse.find("x");
		if (to_parse[pos + 1] == '^') {
			pos += 2;
			for (std::size_t i = pos; i < to_parse.size(); i++) {
				ss << to_parse[i];
			}
			via = ss.str();
			ss.str(std::string());
			std::string::size_type sz;
			deg = std::stod(via,&sz);
			return;
		}
		else {
			deg = 1;
			return;
		}
	}
}
Monomial::Monomial() {
	this->Degree = 0;
	this->Coefficient = 0;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = false;
}
Monomial::Monomial(int const &Coeff, int const &Deg) {
	this->Coefficient = Coeff;
	this->Degree = Deg;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = true;
	this->Pry = 1;
}
Monomial::Monomial(int const &Coeff) {
	this->Degree = 1;
	this->Coefficient = Coeff;
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = true;
	this->Pry = 1;
}
Monomial::Monomial(std::string const &form) {
	is_cos = is_sin = is_tan = is_lan = is_E = false;
	is_monom = false;
	this->Pry = 1;
	std::size_t pos, endp;
	std::stringstream ss, ss2;
	std::string via, via2,subs;
	double DEG,i=0;
	double COF;
	if (form.find("cos(") != std::string::npos) {
		this->is_cos = true;
		pos = form.find("cos(");
		if (pos > 0) {
			if (form[pos - 1] == '*') {
				for (std::size_t i = 0; i < pos - 1; i++) {
					ss << form[i];
				}
				via = ss.str();
				this->Pry = atoi(via.c_str());

				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
			else {
				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
		}
		else {
			pos += 3;
			endp = form.find(")", pos);
			subs = form.substr(pos + 1, endp - 1);
			get_Cof_Deg(subs, COF, DEG);
			this->Degree = DEG;
			this->Coefficient = COF;
		}

	}
	else if (form.find("sin(") != std::string::npos) {
		this->is_sin = true;
		pos = form.find("sin(");
		if (pos > 0) {
			if (form[pos - 1] == '*') {
				for (std::size_t i = 0; i < pos - 1; i++) {
					ss << form[i];
				}
				via = ss.str();
				this->Pry = atoi(via.c_str());

				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
			else {
				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
		}
		else {
			pos += 3;
			endp = form.find(")", pos);
			subs = form.substr(pos + 1, endp - 1);
			get_Cof_Deg(subs, COF, DEG);
			this->Degree = DEG;
			this->Coefficient = COF;
		}
	}
	else if (form.find("tan(") != std::string::npos) {
		this->is_tan = true;
		pos = form.find("tan(");
		if (pos > 0) {
			if (form[pos - 1] == '*') {
				for (std::size_t i = 0; i < pos - 1; i++) {
					ss << form[i];
				}
				via = ss.str();
				this->Pry = atoi(via.c_str());

				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
			else {
				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
		}
		else {
			pos += 3;
			endp = form.find(")", pos);
			subs = form.substr(pos + 1, endp - 1);
			get_Cof_Deg(subs, COF, DEG);
			this->Degree = DEG;
			this->Coefficient = COF;
		}
	}
	else if (form.find("ln(") != std::string::npos) {
		this->is_lan = true;
		pos = form.find("ln(");
		if (pos > 0) {
			if (form[pos - 1] == '*') {
				for (std::size_t i = 0; i < pos - 1; i++) {
					ss << form[i];
				}
				via = ss.str();
				this->Pry = atoi(via.c_str());

				pos += 2;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
			else {
				pos += 3;
				endp = form.find(")", pos);
				subs = form.substr(pos + 1, endp - 1);
				get_Cof_Deg(subs, COF, DEG);
				this->Degree = DEG;
				this->Coefficient = COF;
			}
		}
		else {
			pos += 3;
			endp = form.find(")", pos);
			subs = form.substr(pos + 1, endp - 1);
			get_Cof_Deg(subs, COF, DEG);
			this->Degree = DEG;
			this->Coefficient = COF;
		}
	}
	else {
		this->is_monom = true;
		get_Cof_Deg(form, COF, DEG);
		this->Degree = DEG;
		this->Coefficient = COF;
	}


}

std::ostream &operator<<(std::ostream &out, Monomial const &source) {
	if (source.is_cos == true) {
		if (source.Pry > 1) {
			std::cout <<source.Pry <<"*cos(";

		}
		else {
			std::cout << "cos(";
		}
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			if (source.Coefficient == 1) {
				out << "X";
				std::cout << ")";

				return out;
			}
			else {
				out << source.Coefficient << "*X";
				std::cout << ")";

				return out;
			}


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_sin == true) {
		if (source.Pry == 1) {
			std::cout << "sin(";
		}
		else {
			std::cout <<source.Pry << "*sin(";

		}
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			if (source.Coefficient == 1) {
				out << "X";
				std::cout << ")";

				return out;
			}
			else {
				out << source.Coefficient << "*X";
				std::cout << ")";

				return out;
			}


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_tan == true) {
		if (source.Pry == 1) {
			std::cout << "tan(";
		}
		else {
			std::cout<<source.Pry << "*tan(";

		}
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			if (source.Coefficient == 1) {
				out << "X";
				std::cout << ")";

				return out;
			}
			else {
				out << source.Coefficient << "*X";
				std::cout << ")";

				return out;
			}


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else if (source.is_monom == true) {
		if (source.Degree == 0) {
			out << source.Coefficient;

			return out;

		}
		else if (source.Degree == 1) {
			if (source.Coefficient == 1) {
				out << "X";

				return out;
			}
			else {
				out << source.Coefficient << "*X";

				return out;
			}


		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;

			return out;
		}
	}
	else if (source.is_lan == true) {
		if (source.Pry == 1) {
			std::cout << "ln(";
		}
		else {
			std::cout << source.Pry << "*ln(";

		}
		if (source.Degree == 0) {
			out << source.Coefficient;
			std::cout << ")";

			return out;

		}
		else if (source.Degree == 1) {
			if (source.Coefficient == 1) {
				out << "X";
				std::cout << ")";

				return out;
			}
			else {
				out << source.Coefficient << "*X";
				std::cout << ")";

				return out;
			}

		}
		else {
			out << source.Coefficient << "*X^" << source.Degree;
			std::cout << ")";

			return out;
		}
	}
	else {
	return out;
}



	
	
}
int Monomial::operator+(Monomial const&b) {
	if (this->is_monom == true) {
		if (this->Degree == b.Degree) {
			this->Coefficient += b.Coefficient;
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		if (this->Coefficient == b.Coefficient && this->Degree == this->Degree) {
			this->Pry++;
			return 1;
		}
		else {
			return 0;
		}
	}
}
void Monomial::operator-( Monomial const&b) {
	if (this->Degree == b.Degree) {
		this->Coefficient -= b.Coefficient;
	}
	else {
		return;
	}
}
void Monomial::operator*(Monomial const&b) {
	if (b.Degree == 0) {
		this->Coefficient *= b.Coefficient;
	}
	else {
		this->Coefficient *= b.Coefficient;
		this->Degree += b.Degree;
	}
}
void  Monomial::operator^(int const&b) {
	if (b == 0) {
		this->Coefficient = 0;
		this->Degree = 1;
	}
	else {
		this->Degree *= b;
		double p = this->Coefficient;
		for (int i = 1; i < b; i++) {
			this->Coefficient *= p;
		}
	}
}
void Monomial::operator/(Monomial const &b) {
	this->Coefficient /= b.Coefficient;
	this->Degree -= b.Degree;
}
void Monomial::Derive() {
	if (is_cos == true) {
		is_cos = false;
		is_sin = true;
		
		if (Degree == 1) {
			Pry *= -Coefficient;
			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {
	
		}
	}
	else if (is_sin == true) {
		is_cos = true;
		is_sin = false;

		if (Degree == 1) {
			Pry *= Coefficient;
			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {

		}
	}
	else if (is_tan==true) {
		is_tan = false;
		is_cos = true;

		if (Degree == 1) {
			Pry *= Coefficient;
			Degree = -2;

			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {

		}
	}
	else if (is_lan == true) {
			

		if (Degree == 1) {
			Pry *= Coefficient;
			Degree = -1;
			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {

		}
	}
	else if (is_monom == true) {
		if (Degree == 1) {
			Degree = 0;
			return;
		}
		else if (Degree == 0) {
			Coefficient = 0;
		}
		else {
			this->Coefficient *= Degree;
			this->Degree--;
		}
	}
	else {
		return;
	}
}
void Monomial::Derive(int const &mag) {
	for (int i = 0; i < mag; i++) {
		Derive();
	}
}
double Monomial::operator[](double const &x_value) {
	if (this->is_cos == true) {
		if (Degree == 0) {
			if (Pry == 1) {
				return cos(Coefficient);
			}
			else {
				return Pry * cos(Coefficient);

			}
		}
		else if (Degree == 1) {
			if (Pry == 1) {
				return cos(Coefficient * x_value);
			}
			else {
				return Pry * cos(Coefficient * x_value);

			}
		}
		else {
			double t_valv = x_value;

			for (int i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			if (Pry == 1) {
				return cos(t_valv);
			}
			else {
				return Pry * cos(t_valv);

			}
		}
	}
	else if (this->is_monom == true) {

		if (Degree == 0) {
			return Coefficient;
		}
		else if (Degree == 1) {
			return Coefficient * x_value;
		}
		else {
			double t_valv = x_value;

			for (int i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			return t_valv;
		}
	}
	else if (this->is_tan == true) {
		if (Degree == 0) {
			if (Pry == 1) {
				return std::tan(Coefficient);
			}
			else {
				return Pry * std::tan(Coefficient);

			}

		}
		else if (Degree == 1) {
			if (Pry == 1) {
				return std::tan(Coefficient * x_value);
			}
			else {
				return Pry *  std::tan(Coefficient * x_value);

			}
		}
		else {
			double t_valv = x_value;

			for (int i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			if (Pry == 1) {
				return std::tan(t_valv);
			}
			else {
				return Pry * std::tan(t_valv);

			}
		}
	}
	else if (this->is_lan == true) {
		if (Degree == 0) {
			if (Pry == 1) {
				return std::log(Coefficient);
			}
			else {
				return Pry * std::log(Coefficient);

			}

		}
		else if (Degree == 1) {
			if (Pry == 1) {
				return std::log(Coefficient * x_value);
			}
			else {
				return Pry * std::log(Coefficient * x_value);

			}
		}
		else {
			double t_valv = x_value;

			for (int i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			if (Pry == 1) {
				return std::log(t_valv);
			}
			else {
				return Pry *  std::log(t_valv);

			}
		}
	}
	else if (this->is_sin == true) {
		if (Degree == 0) {
			if (Pry == 1) {
				return std::sin(Coefficient);
			}
			else {
				return Pry * std::sin(Coefficient);

			}
			
		}
		else if (Degree == 1) {
			if (Pry == 1) {
				return std::sin((Coefficient) * x_value);
			}
			else {
				return Pry * std::sin(Coefficient * x_value);

			}
		}
		else {
			double t_valv = x_value;

			for (int i = 1; i < Degree; i++) {
				t_valv *= x_value;
			}
			t_valv *= Coefficient;
			if (Pry == 1) {
				return std::sin(t_valv);
			}
			else {
				return Pry * std::sin(t_valv);

			}
		}
	}
	else {
		return 0;
	}

}







class Function {
protected:

public:
	std::string input;
	std::vector<Monomial> Body;
	std::vector<char> signs;

	std::stack<char> operations;
	std::stack<Monomial> operands;
	Function();
	Function(const char *function);
	void operator=(Function const &B);
	double operator[](double const &x_value);
	friend std::ostream &operator<<(std::ostream &out, Function const &func);
	void Derive();
	void Derive(int const &mag);
	int Get_Highest_Degree();
	double Newton_Raphson_Method(double const &guess,double const &deg_of_accuracy,double const &check_slope);
	Function Taylor_Polynomial(int const &derivative_n);
	void operator+(Function const &B);
};

double commit_operation(char const &op, double const &a, double const &b) {
	double sum = 0;
	switch (op)
	{
	case '+':
		sum = a + b;
		return sum;
		break;
	case '-':
		sum = a - b;
		return sum;
		break;

	case '*':
		sum = a * b;
		return sum;
		break;

	case '/':

		sum = a / b;
		return sum;
		break;

	case '^':
		sum = pow(a, b);
		return sum;
		break;



	default:
		return 0;
		break;
	}
}
int sign_pt(char const &op) {
	switch (op)
	{
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;

	case '*':
		return 2;
		break;

	case '/':

		return 2;
		break;

	case '^':
		return 3;
		break;



	default:
		return 0;
		break;
	}
}
Function::Function() {
}
Function::Function(const char *function) {
	this->input = std::string(function);
	std::stringstream ss;
	std::string via;
	std::size_t pos, endp;
	if (input.find(' ') == std::string::npos) {

		operands.push(Monomial(input));
		Body.push_back(Monomial(input));

	}
	else {
		endp = input.find(' ');
		pos = 0;
		while (true) {
			for (std::size_t i = pos; i < endp; i++) {
				ss << input[i];
			}
			via = ss.str();
			ss.str(std::string());
			operands.push(Monomial(via));
			Body.push_back(Monomial(via));
			operations.push(input[endp + 1]);
			signs.push_back(input[endp + 1]);
			pos = endp +2;
		
			if (input.find(' ', pos+1) == std::string::npos) {
				for (std::size_t i = pos + 1; i < input.size(); i++) {
					ss << input[i];
				}
				via = ss.str();
				ss.str(std::string());
				operands.push(Monomial(via));
				Body.push_back(Monomial(via));
				break;
			}
			endp = input.find(' ', pos+1);
			
		}
	}

}
double Function::operator[](double const &x_value) {
	std::vector<double> infix;
	std::stack<char> opts;
	std::stack<double> oprnds;
	char temp;
	double a, b, sum;
	unsigned k = 0;
	for (unsigned i = 0; i < Body.size(); i++) {
		oprnds.push(Body[i][x_value]);
		if (k < signs.size()) {
			if (opts.empty()) {
				opts.push(signs[k]);
			}
			else {
				if (sign_pt(opts.top()) < sign_pt(signs[k])) {
					opts.push(signs[k]);
				}
				else {
					temp = opts.top();
					opts.pop();
					a = oprnds.top();
					oprnds.pop();
					b = oprnds.top();
					oprnds.pop();
					sum = commit_operation(temp, b, a);
					oprnds.push(sum);
					opts.push(signs[k]);
				}
			}
			k++;
		}

	}

	while (!opts.empty()) {
		a = oprnds.top();
		oprnds.pop();
		b = oprnds.top();
		oprnds.pop();
		temp = opts.top();
		opts.pop();
		sum = commit_operation(temp, b, a);
		oprnds.push(sum);
	}
	return oprnds.top();

}
void Function::operator=(Function const &B) {
	this->Body = B.Body;
	this->signs = B.signs;
	this->input = B.input;
}
std::ostream &operator<<(std::ostream &out, Function const &func) {
	unsigned k = 0;
	for (unsigned i = 0; i < func.Body.size(); i++) {

		out << func.Body[i] << " ";
		if (k < func.signs.size()) {
			out << func.signs[k] << " ";
			k++;
		}


	}
	for (unsigned i = 0; i < func.Body.size(); i++) {
	}
	return out;
}
void  Function::Derive() {
	for (unsigned i = 0; i < Body.size(); i++) {
		Body[i].Derive();
	}
}
void Function::Derive(int const &mag) {
	for (int i = 0; i < mag; i++) {
		this->Derive();
	}
}
int Function::Get_Highest_Degree() {
	int max = 0;
	for (auto i : Body) {
		(int)(max < (int)i.Degree ? max = (int)i.Degree : max = max);
	}
	return max;
}
double Function::Newton_Raphson_Method(double const &guess, double const &deg_of_accuracy, double const &check_slope=0.5) {
	Function f, f1;
	double fv,f1v,x = guess,x1 = 0;

	while(true){
		f = *this;
		f.Derive();
		f1 = f;
		f = *this;


		fv = f[x];
		f1v = f1[x];

		if (abs(f1[x]) < check_slope) {
			std::cout << "Slope is too small" << std::endl;
			break;
		}

		x1 = x - (fv / f1v);

		if ( abs((x1-x)/x1)< deg_of_accuracy) {
			return x1;
		}
		x = x1;
	
	}
	std::cout << "Method does not converge due to oscillation" << std::endl;
	return 0;
}
void  Function::operator+(Function const &B) {
	unsigned i = 0;
	unsigned j = 0;
	while (j <B.Body.size())
	{
		if (Body.size() == 0) {
			Body.push_back(B.Body[j]);
			return;
		}
		else {
			for (i; i < this->Body.size(); i++) {
				if ((Body[i] + B.Body[j]) == 1) {
					j++;
					break;
				}

			}
			if (i == Body.size()) {
				Body.push_back(B.Body[j]);
				signs.push_back('+');
				j++;
			}
		}
	}
}
Function Function::Taylor_Polynomial(int const &derivative_n) {
	Function TP;
	Function Temp = *this;
	for (int i = 0; i < derivative_n; i++) {
		TP + Temp;
		Temp.Derive();
	}
	return TP;
}






//complex

class Complex {
public:
	double a;
	double bi;
	Complex();
	Complex(double const &real, double const &imaginary);
	void Conjugate();
	void operator+(Complex const &B);
	void operator-(Complex const &B);
	void operator*(Complex const &B);
	void operator/(Complex const &B);
	void operator^(int const &B);
	friend std::ostream &operator<<(std::ostream &out, Complex const &source);
	friend std::istream &operator>>(std::istream &in, Complex &source);
	void operator=(Complex const &source);


};
Complex::Complex() {
	this->a = 0;
	this->bi = 0;
}
Complex::Complex(double const &real, double const &imaginary) {
	this->a = real;
	this->bi = imaginary;
}
void Complex::operator=(Complex const &source) {
	this->a = source.a;
	this->bi = source.bi;
}
void Complex::operator+(Complex const &B) {
	this->a += B.a;
	this->bi += B.bi;
}
void Complex::operator-(Complex const &B) {
	this->a -= B.a;
	this->bi -= B.bi;
}
void Complex::operator*(Complex const &B) {
	double aa = this->a*B.a - (this->bi*B.bi);
	double bb = this->a *B.bi + this->bi * B.a;
	this->a = aa;
	this->bi = bb;
}
void Complex::operator^(int const &B) {
	for (int i = 1; i < B; i++) {
		*this * *this;
	}
}
void Complex::operator/(Complex const &B) {
	double divisor = SQUARE_IT(B.a) + SQUARE_IT(B.bi);
	Complex t = B;
	t.Conjugate();
	*this * t;
	this->a /= divisor;
	this->bi /= divisor;
}
std::ostream &operator<<(std::ostream &out, Complex const &source) {
	if (source.bi > 0.0 && source.a > 0.0) {
		out << source.a << "+" << source.bi<<"i";
		return out;
	}
	else if (source.bi == 0.0) {
		out << source.a;
		return out;
	}
	else if (source.bi >0.0 && source.a ==0.0) {
		out << source.bi << "i";
		return out;
	}
	else if (source.bi > 0.0 && source.a < 0.0) {
		out << source.a << "+" << source.bi << "i";
		return out;
	}
	else {
		out << source.a << source.bi<<"i";
		return out;
	}
}
std::istream &operator>>(std::istream &in, Complex &source) {
	in >> source.a >> source.bi;
	return in;
}
void Complex::Conjugate() {
	this->bi *= -1;
}








//vecs
std::ostream &operator<<(std::ostream &out, std::vector<int> const &body) {
	out << "[";
	for (unsigned i = 0; i < body.size(); i++) {
		if (i + 1 != body.size())
			out << body[i] << ", ";
		else
			out << body[i];

	}
	out << "]";
	return out;
}
std::ostream &operator<<(std::ostream &out, std::vector<double> const &body) {
	out << "[";
	for (unsigned i = 0; i < body.size(); i++) {
		if (i + 1 != body.size())
			out << body[i] << ", ";
		else
			out << body[i];

	}
	out << "]";
	return out;
}
std::ostream &operator<<(std::ostream &out, std::vector<float> const &body) {
		out << "[";
		for (unsigned i = 0; i < body.size(); i++) {
			if (i + 1 != body.size())
				out << body[i] << ", ";
			else
				out << body[i];

		}
		out << "]";
		return out;
	}



double Vector_Mean(std::vector<int> const &num) {
	double sum = 0;
	for (auto i : num) {
		sum += i;
	}
	return sum / num.size();
}
double Vector_Mean(std::vector<double> const &num) {
	double sum = 0;
	for (auto i : num) {
		sum += i;
	}
	return sum / num.size();
}
float Vector_Mean(std::vector<float> const &num) {
	float sum = 0;
	for (auto i : num) {
		sum += i;
	}
	return sum / num.size();
}
double Vector_Median(std::vector<int> nums) {
	std::sort(nums.begin(), nums.end());
	if (nums.size() % 2 == 0) {
		return (double)(nums[nums.size() / 2] + nums[(nums.size() / 2) - 1]) / 2;
	}
	else {

		return nums[nums.size() / 2];
	}
}
double Vector_Median(std::vector<double> num) {
	std::sort(num.begin(), num.end());
	if (num.size() % 2 == 0) {
		return (num[num.size() / 2] + num[(num.size() / 2) - 1]) / 2;
	}
	else {

		return num[num.size() / 2];
	}
}
float Vector_Median(std::vector<float> num) {
	std::sort(num.begin(), num.end());
	if (num.size() % 2 == 0) {
		return (num[num.size() / 2] + num[(num.size() / 2) - 1]) / 2;
	}
	else {

		return num[num.size() / 2];
	}
}
int Vector_Mode(std::vector<int> const &num) {
	std::vector<int> counter(num.size(), 0);
	int max_val = 0, pos = 0;
	for (auto i : num) {
		counter[std::abs(i)]++;
	}
	for (unsigned i = 0; i < counter.size(); i++) {
		if (counter[i] != 0) {
			if (counter[i] > max_val) {
				max_val = counter[i];
				pos = i;
			}
		}
	}
	return pos;
}
double Vector_Mode(std::vector<double> const &num) {
	double result=0;
	int cur_max = 0;
	int counter = 0;
	for (unsigned i = 0; i < num.size(); i++) {
		for (unsigned j = 0; j < num.size(); j++) {
			if (num[i] == num[j]) {
				counter++;
			}
		}
		if (counter >= cur_max) {
			cur_max = counter;
			result = num[i];
		}
	}
	return result;
}
float Vector_Mode(std::vector<float> const &num) {
	float result;
	int cur_max = 0;
	int counter = 0;
	for (unsigned i = 0; i < num.size(); i++) {
		for (unsigned j = 0; j < num.size(); j++) {
			if (num[i] == num[j]) {
				counter++;
			}
		}
		if (counter >= cur_max) {
			cur_max = counter;
			result = num[i];
		}
	}
	return result;
}

double Vector_Standard_Deviation(std::vector<int> const &population) {
	double mean = Vector_Mean(population);
	double sum = 0;
	for (unsigned i = 0; i < population.size(); i++) {
		sum += (SQUARE_IT((population[i] - mean)));
	}
	sum /= (double)population.size();
	sum = std::sqrt(sum);
	return sum;
}
double Vector_Standard_Deviation(std::vector<double> const &population) {
	double mean = Vector_Mean(population);
	double sum = 0;
	for (unsigned i = 0; i < population.size(); i++) {
		sum += (SQUARE_IT((population[i] - mean)));
	}
	sum /= (double)population.size();
	sum = std::sqrt(sum);
	return sum;
}
float Vector_Standard_Deviation(std::vector<float> const &population) {
	float mean = Vector_Mean(population);
	float sum = 0;
	for (unsigned i = 0; i < population.size(); i++) {
		sum += (SQUARE_IT((population[i] - mean)));
	}
	sum /= (float)population.size();
	sum = std::sqrt(sum);
	return sum;
}
double Vector_Variance(std::vector<int> const &population) {
	double Deviation = Vector_Standard_Deviation(population);
	return SQUARE_IT(Deviation);
}
double Vector_Variance(std::vector<double> const &population) {
	double Deviation = Vector_Standard_Deviation(population);
	return SQUARE_IT(Deviation);
}
float Vector_Variance(std::vector<float> const &population) {
	float Deviation = Vector_Standard_Deviation(population);
	return SQUARE_IT(Deviation);
}
double Vector_Sample_Standard_Deviation(std::vector<int> const &sample) {
	double samples_mean = Vector_Mean(sample);
	double sum = 0;
	for (unsigned i = 0; i < sample.size(); i++) {
		sum += SQUARE_IT((sample[i] - samples_mean));
	}
	sum /= (sample.size() - 1);
	return sqrt(sum);
}
double Vector_Sample_Standard_Deviation(std::vector<double> const &sample) {
	double samples_mean = Vector_Mean(sample);
	double sum = 0;
	for (unsigned i = 0; i < sample.size(); i++) {
		sum += SQUARE_IT((sample[i] - samples_mean));
	}
	sum /= (sample.size() - 1);
	return sqrt(sum);
}
float Vector_Sample_Standard_Deviation(std::vector<float> const &sample) {
	float samples_mean = Vector_Mean(sample);
	float sum = 0;
	for (unsigned i = 0; i < sample.size(); i++) {
		sum += SQUARE_IT((sample[i] - samples_mean));
	}
	sum /= (sample.size() - 1);
	return sqrt(sum);
}
double Z_Score(int value_to_standardized, std::vector<int> const &population) {
	return (value_to_standardized - Vector_Mean(population)) / Vector_Standard_Deviation(population);
}
double Z_Score(int value_to_standardized, std::vector<double> const &population) {
	return (value_to_standardized - Vector_Mean(population)) / Vector_Standard_Deviation(population);
}
float Z_Score(int value_to_standardized, std::vector<float> const &population) {
	return (value_to_standardized - Vector_Mean(population)) / Vector_Standard_Deviation(population);
}
double Vector_Harmonic_Mean(std::vector<int> const &population) {
	double divider = 0;
	for (auto i : population) {
		divider += (1 / i);
	}
	return ((double)population.size()) / divider;
}
double Vector_Harmonic_Mean(std::vector<double> const &population) {
	double divider = 0;
	for (auto i : population) {
		divider += (1 / i);
	}
	return ((double)population.size()) / divider;
}
float Vector_Harmonic_Mean(std::vector<float> const &population) {
	float divider = 0;
	for (auto i : population) {
		divider += (1 / i);
	}
	return ((float)population.size()) / divider;
}
int Vector_Get_Max_Value(std::vector<int> const &set) {
	int cur_max = std::numeric_limits<int>::min();
	for (auto i : set) {
		i > cur_max ? cur_max = i : 0;
	}
	return cur_max;
}
double Vector_Get_Max_Value(std::vector<double> const &set) {
	double cur_max = std::numeric_limits<double>::min();
	for (auto i : set) {
		i > cur_max ? cur_max = i : 0;
	}
	return cur_max;
}
float Vector_Get_Max_Value(std::vector<float> const &set) {
	float cur_max = std::numeric_limits<float>::min();
	for (auto i : set) {
		i > cur_max ? cur_max = i : 0;
	}
	return cur_max;
}
int Vector_Get_Min_Value(std::vector<int> const &set) {
	int cur_min = std::numeric_limits<int>::max();
	for (auto i : set) {
		i < cur_min ? cur_min = i : 0;
	}
	return cur_min;
}
double Vector_Get_Min_Value(std::vector<double> const &set) {
	double cur_min = std::numeric_limits<double>::max();
	for (auto i : set) {
		i < cur_min ? cur_min = i : 0;
	}
	return cur_min;
}
float Vector_Get_Min_Value(std::vector<float> const &set) {
	float cur_min = std::numeric_limits<float>::max();
	for (auto i : set) {
		i < cur_min ? cur_min = i : 0;
	}
	return cur_min;
}
std::vector<int> Random_INT_Vector(int const &vector_size) {
	std::random_device seed; 
	std::mt19937 random_number_generator(seed()); 
	std::uniform_int_distribution<int> ind(0, std::numeric_limits<int>::max());
	std::vector<int> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<int> Random_INT_Vector(int const &vector_size, int const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_int_distribution<int> ind(0, Random_upper_boundary);
	std::vector<int> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<int> Random_INT_Vector(int const &vector_size, int const &Random_lower_boundary, int const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_int_distribution<int> ind(Random_lower_boundary, Random_upper_boundary);
	std::vector<int> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<double> Random_DOUBLE_Vector(int const &vector_size) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<double> ind(0, std::numeric_limits<double>::max());
	std::vector<double> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<double> Random_DOUBLE_Vector(int const &vector_size, double const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<double> ind(0, Random_upper_boundary);
	std::vector<double> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<double> Random_DOUBLE_Vector(int const &vector_size, double const &Random_lower_boundary, double const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	//std::uniform_int_distribution<size_t> indices(0, data.size() - 1);
	std::uniform_real_distribution<double> ind(Random_lower_boundary, Random_upper_boundary);
	std::vector<double> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<float> Random_FLOAT_Vector(int const &vector_size) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<float> ind(0, std::numeric_limits<float>::max());
	std::vector<float> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<float> Random_FLOAT_Vector(int const &vector_size, float const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<float> ind(0, Random_upper_boundary);
	std::vector<float> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
std::vector<float> Random_FLOAT_Vector(int const &vector_size, float const &Random_lower_boundary, float const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<float> ind(Random_lower_boundary, Random_upper_boundary);
	std::vector<float> result(vector_size);
	for (auto &i : result) {
		i = ind(random_number_generator);
	}
	return result;

}
int Random_INT() {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_int_distribution<int> ind(0, std::numeric_limits<int>::max());
	return ind(random_number_generator);
}
int Random_INT(int const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_int_distribution<int> ind(0, Random_upper_boundary);
	return ind(random_number_generator);
}
double Random_DOUBLE() {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<double> ind(0, std::numeric_limits<double>::max());
	return ind(random_number_generator);
}
double Random_DOUBLE(double const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<double> ind(0, Random_upper_boundary);
	return ind(random_number_generator);
}
float Random_FLOAT() {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<float> ind(0, std::numeric_limits<float>::max());
	return ind(random_number_generator);
}
float Random_FLOAT(float const &Random_upper_boundary) {
	std::random_device seed;
	std::mt19937 random_number_generator(seed());
	std::uniform_real_distribution<float> ind(0, Random_upper_boundary);
	return ind(random_number_generator);
}
int Factorial(int const &value) {
	int sum = 1;
	for (int i = 1; i < value+1; i++) {
		sum *= i;
	}
	return sum;
}
void Mandelbrot_Set() {
	Complex Z, C;
	Image A;
	Color_Palette CSET;
	A.Load_Blank_Canvas(500, 500, CSET.Azure); 
	A.init_pixel_matrix();
	int n = 0;
	for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 500; j++) {
			C.a = j * 500;
			C.bi = i * 500;


			while (n < 100) {
				double t;
				t = (Z.a * Z.a )- Z.bi*Z.bi + C.a;
				Z.a = t;
				Z.bi = 2 * Z.a + Z.bi + C.bi;

				if (Z.a + Z.bi > 16) {
					break;
				}
				n++;
			}
			if (n == 100) {
				A.Color_Spec(A.Pixel_Matrix[i][j].index_range, CSET.Black);
				n = 0;
			}
		}
	}
	A.Write_Image("Test");
	system("Test.jpg");
}


