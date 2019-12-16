#pragma once
#include "Image_Header.h"
#include "Color_Catalog.h"

typedef struct interval {
	int Right, Left;
}interval;

class Interval_Graph {
protected:

	interval *vertices;
	int last_pos;
	int allocated_vertices;
	int max_value, min_value;

	int **Adjacency_Matirx;

	int Edges, Max_Degree, Min_Degree;
	int Gcomp_Edges, Gcomp_Max_Degree, Gcomp_Min_Degree, Chromatic_Number;


public:
	Interval_Graph();
	Interval_Graph( int const &number_of_Intervals);
	~Interval_Graph();
	void Add_Interval(int left, int right);
	void Print_Graph_Intervals()const;
	void Run_Analysis();
	void Print_Adjacency_Matirx();
	void Print_Graph_Stats();
	void Output_Graph_Image();

};
