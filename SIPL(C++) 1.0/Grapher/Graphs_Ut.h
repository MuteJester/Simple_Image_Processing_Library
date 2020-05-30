#pragma once
#include "Image_Header.h"
#include "Color_Catalog.h"
#include "Mole.h"

typedef struct interval {
	int Right, Left;
}interval;

typedef struct Vert {
	int Right, Left;
	pixel Color;
}Vert;

//typedef struct Edge {
//	int Vr, Vl;
//}Edge;

class Graph {
protected:
	int number_of_vertices;
	int **edges;

public:
	Graph(int const &Number_Of_Vertices);
	void Add_Edge(int const &Vr, int const &Vl);
	void Print_Edges();
	void Export_Graph_Image(const char *type);


};

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
