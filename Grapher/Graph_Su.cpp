#include "Graphs_Ut.h"
#include <sstream>
#include <string>
#include <time.h>

Graph::Graph(int const &Number_Of_Vertices) {
	this->number_of_vertices = Number_Of_Vertices;
	this->edges = (int**)malloc(sizeof(int*)*Number_Of_Vertices);
	for (int i = 0; i < Number_Of_Vertices; i++) {
		edges[i] = (int*)calloc(number_of_vertices, sizeof(int));
	}
}
void Graph::Add_Edge(int const &Vr, int const &Vl) {
	if (Vr > number_of_vertices || Vl > number_of_vertices) {
		return;
	}
	edges[Vr][Vl] = 1;
	edges[Vl][Vr] = 1;

}

void Graph::Print_Edges() {
	stringstream ss;
	string build;
	cout << endl << "Graph Edges" << endl << endl;
	for (int i = 0; i < number_of_vertices; i++) {
		for (int j = 0; j < number_of_vertices; j++) {
			if (edges[i][j] == 1) {
				ss << "{V" << i << ", " << "V" << j << "}";
				build = ss.str();
				cout << build << endl;
				ss.str(string());
			}
		}
	}
}

void Graph::Export_Graph_Image(const char *type) {
	char m1[5],m2[8];
	strcpy(m1, "Comp");
	strcpy(m2, "Regular");

	Image Output;
	Color_Palette CSET;
	stringstream ss;
	string via;
	int cx, cy, angle = 0,delta=1,draw_y =20;
	Output.Load_Blank_Canvas(number_of_vertices * 50+100, number_of_vertices * 50, CSET.Azure);
	Output.Get_Center(cx, cy);
	//Output.Draw_Circle(cx, cy, 4, CSET.Green);
	angle = 360 / number_of_vertices;
	vector<Vert> vertc;
	
		for (int i = 0; i < number_of_vertices; i++) {
			vertc.push_back({ (int)(cy + cos(angle)*(number_of_vertices * 10)), (int)(cx + sin(angle)*(number_of_vertices * 10)),CSET.Color_Serial_Number[i + 2 + rand() % 134 ] });
			Output.Draw_Circle((int)(cx + sin(angle)*(number_of_vertices * 10)), (int)(cy + cos(angle)*(number_of_vertices * 10)),4,vertc.back().Color,"Fill");
			//Output.Draw_Line(cy, cx, cy + cos(angle)*(number_of_vertices * 10), cx + sin(angle)*(number_of_vertices * 10), CSET.Black);
			angle += (360 / number_of_vertices - 1) +delta;
			delta++;
		}

		for (int i = 5; i < 80; i++) {
			Output.Draw_Line(15, i, draw_y*number_of_vertices-10, i, CSET.Dark_Gray);
		}
		Output.Draw_Text(4, 40, "VERTICES");
		for (int i = 0; i < number_of_vertices; i++) {
			ss << "V" << i;
			via = ss.str();
			Output.Draw_Text(draw_y, 25,via.c_str(),vertc[i].Color);
			ss.str(string());
			draw_y += 10;
		}

		if (strcmp(m1, type) == 0) {

			for (int i = 0; i < number_of_vertices; i++) {

				for (int j = 0; j < number_of_vertices; j++) {
					if (this->edges[i][j] != 1) {
						Output.Draw_Line(vertc[i].Right, vertc[i].Left, vertc[j].Right, vertc[j].Left, vertc[i].Color);
		/*				Output.Draw_Circle(vertc[i].Left, vertc[i].Right, 4, vertc[i].Color);
						Output.Draw_Circle(vertc[j].Left, vertc[j].Right, 4, vertc[j].Color);
*/
					}
				}

			}
			Output.Draw_Text(4, (number_of_vertices * 50 + 100) / 2 + 5, "G COMP ILLUSTRATION");

			Output.Write_Image("Graph_Output");
		}	
		else if (strcmp(m2, type) == 0) {
			for (int i = 0; i < number_of_vertices; i++) {

				for (int j = 0; j < number_of_vertices; j++) {
					if (this->edges[i][j] == 1) {
						Output.Draw_Line(vertc[i].Right, vertc[i].Left, vertc[j].Right, vertc[j].Left, vertc[i].Color);
				/*		Output.Draw_Circle(vertc[i].Left, vertc[i].Right, 4, vertc[i].Color);
						Output.Draw_Circle(vertc[j].Left, vertc[j].Right, 4, vertc[j].Color,"Fill");*/
					}
				
				}

			}
			Output.Draw_Text(4, (number_of_vertices * 50 + 100) / 2 + 5, "G ILLUSTRATION");
			Output.Write_Image("Graph_Output");
		}

}


Interval_Graph::Interval_Graph() {
	this->vertices = nullptr;
	this->Adjacency_Matirx = nullptr;
}
Interval_Graph::Interval_Graph(int const &number_of_Intervals) {
	this->vertices = (interval*)malloc(sizeof(interval)*number_of_Intervals);
	this->Adjacency_Matirx = (int**)malloc(sizeof(int*)*number_of_Intervals);
	for (int i = 0; i < number_of_Intervals; i++) {
		Adjacency_Matirx[i] = (int*)calloc(number_of_Intervals, sizeof(int));
	}
	last_pos = 0;
	allocated_vertices = number_of_Intervals;
	Edges = Gcomp_Edges = Min_Degree = Max_Degree = Gcomp_Max_Degree = Gcomp_Min_Degree = Chromatic_Number= 0;
	max_value = min_value = 0;
}

Interval_Graph::~Interval_Graph() {
	delete[] this->vertices;
	delete[] this->Adjacency_Matirx;
}

void Interval_Graph::Add_Interval(int left, int right) {
	if (last_pos == allocated_vertices) {
		return;
	}
	static int flag = 0;
	vertices[last_pos].Left = left;
	vertices[last_pos].Right = right;
	if (left < min_value) {
		min_value = left;
	}
	if (right > max_value) {
		if (min_value == 0 && flag == 0) {
			min_value = right;
			flag = 1;
		}
		max_value = right;
	}
	last_pos++;
}
void Interval_Graph::Print_Graph_Intervals()const {
	for (int i = 0; i < last_pos; i++) {
		cout << "[" << vertices[i].Left << " , " << vertices[i].Right << "]   ";
		if ((i + 1) % 4 == 0) {
			cout << endl;
		}
	}
}

void Interval_Graph::Print_Adjacency_Matirx() {
	cout << endl << endl;
	cout << "  ";
	for (int i = 0; i < allocated_vertices; i++) {
		cout << " v" << i + 1 << "";
	}
	cout << endl;
	cout << "v1  ";
	for (int i = 0; i < allocated_vertices; i++) {
		for (int j = 0; j < allocated_vertices; j++) {
			cout << Adjacency_Matirx[i][j] << "  ";
		}
		cout << endl;
		if (i + 1 != allocated_vertices) {
			cout << "v" << i + 2 << "  ";
		}
	}
}


void Interval_Graph::Run_Analysis() {
	int Counter=0,min_flag=0;

	//update adj matrix
	for (int i = 0; i < allocated_vertices; i++) {
		for (int j = i+1; j < allocated_vertices; j++) {
			if (vertices[i].Left >= vertices[j].Left  &&vertices[i].Left <= vertices[j].Right || vertices[i].Right <= vertices[j].Right && vertices[i].Right >= vertices[j].Left) {
				Adjacency_Matirx[i][j] = 1;
				Adjacency_Matirx[j][i] = 1;

			}
		}
	}

	for (int i = 0; i < allocated_vertices; i++) {
		for (int j = 0; j < allocated_vertices; j++) {
			
			Edges += Adjacency_Matirx[i][j];
			Counter += Adjacency_Matirx[i][j];
		}
		if (Counter == 0) {
			Min_Degree = 0;
			min_flag = 1;
		}
		else if (Counter > Max_Degree) {
			Max_Degree = Counter;
			if (Min_Degree == 0 && min_flag != 1) {
				Min_Degree = Max_Degree;
			}

		}
		else if (Counter < Min_Degree) {
			Min_Degree = Counter;
		}

		Counter = 0;
	}

	Edges /= 2;
	Gcomp_Edges = ((allocated_vertices * (allocated_vertices - 1)) / 2) - Edges;
	Gcomp_Max_Degree = (allocated_vertices - 1) - Min_Degree;
	Gcomp_Min_Degree = (allocated_vertices - 1) - Max_Degree;
	if (Chromatic_Number == 0) {
		Chromatic_Number++;
	}

}

void Interval_Graph::Print_Graph_Stats() {
	cout << endl;

	cout << "Number Of Edges In G: " << Edges << endl;
	cout << "Maximum Degree Of G: " << Max_Degree << endl;
	cout << "Minimum Degree Of G: " << Min_Degree << endl;
	cout << "Chromatic Number Of G: " << Chromatic_Number << endl;
	cout << "G's Complement Edges: " << Gcomp_Edges << endl;
	cout << "Maximum Degree Of G Complement: " << Gcomp_Max_Degree << endl;
	cout << "Minimum Degree Of G Complement: " << Gcomp_Min_Degree << endl;
}

void Interval_Graph::Output_Graph_Image() {
	if (Adjacency_Matirx == nullptr) {
		return;
	}
	srand(time(NULL));
	int disntace = max_value - min_value;
	int cx, cy, ZeroGx, ZeroGy,draw_height,rand_select,select_flag=0;
	int W = max_value * 40 + 400, H = max_value * 40 + 100;
	int *selected_by_brush,m,circle_radius=12,circle_pos=25,text_V_pos=80,left_multiplyer=0,right_multipyer=0;
	if (W < 500) {
		W += 500;
	}
	if (H < 500) {
		H += 500;
	}
	Image graph;
	stringstream ss;
	string body;
	pixel brush;
	Color_Palette Palette;
	selected_by_brush = (int*)calloc(allocated_vertices, sizeof(int));
	

	ZeroGx = (W/2) - (max_value * 40) / 2;
	ZeroGy = (H/2) +(max_value * 40)/2;
	draw_height = 40;

	graph.Load_Blank_Canvas(W, H, Palette.Azure);

	graph.Draw_Graph(max_value * 40, max_value * 40, 40);
	graph.Get_Center(cx, cy);

	//header
	graph.Draw_Text(20, cx, "INTERVAL GRAPH ILLUSTRATION");
	//


	
	//fill the graph data
	for (int i = 0; i < allocated_vertices; i++) {
		rand_select = rand() % 137;
		for (m = 0; m < allocated_vertices; m++) {
			if (selected_by_brush[m] == rand_select || rand_select == 1 || rand_select == 134 || rand_select == 131) {
				rand_select = rand() % 137;
				m = 0;
			}
			else if (allocated_vertices > 137 && selected_by_brush[m] == rand_select) {
				selected_by_brush[i] = rand_select;	
				break;
			}
			else {
				selected_by_brush[i] = rand_select;
				break;
			}
		}
		
		graph.Draw_Line(ZeroGy - draw_height-1, ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height-1, ZeroGx + (40)*vertices[i].Right, Palette.Color_Serial_Number[rand_select],2);
		graph.Draw_Line(ZeroGy - draw_height, ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height,ZeroGx + (40)*vertices[i].Right,Palette.Dark_Red);
		graph.Draw_Line(ZeroGy - draw_height+1, ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height+1, ZeroGx + (40)*vertices[i].Right, Palette.Color_Serial_Number[rand_select],2);



		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height, 5, Palette.Color_Serial_Number[rand_select], "Fill");
		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height, 3, Palette.White, "Fill");
		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Left, ZeroGy - draw_height, 1, Palette.Black, "Fill");



		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Right, ZeroGy - draw_height, 5, Palette.Color_Serial_Number[rand_select], "Fill");
		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Right, ZeroGy - draw_height, 3, Palette.White, "Fill");
		graph.Draw_Circle(ZeroGx + (40)*vertices[i].Right, ZeroGy - draw_height, 1, Palette.Black, "Fill");



		draw_height += 40;
	}

	draw_height = 70;
	graph.Draw_Text(40, 80, "LIST OF VERTICES");

	//left info frame
	if (allocated_vertices < 10) {
		left_multiplyer = (4 * allocated_vertices) * 2 + 10;
	}
	else {
		left_multiplyer = (allocated_vertices) * 2 + 30;
	}



	for (int i = 5; i <= 140; i++) {
		graph.Draw_Line(55, i,55 + (allocated_vertices * left_multiplyer),i, Palette.Dark_Gray);
	}

	
	//left info build

	for (int i = 0; i < allocated_vertices; i++) {

		if (i == 9) {
			circle_radius += 5;
			draw_height += 20;
			circle_pos += 4;
			text_V_pos += 6;
		}

		ss << "V"<<i+1;
		body = ss.str();
		graph.Draw_Text(draw_height, 25, body.c_str(),Palette.White);
		ss.str(string());
		

		graph.Draw_Circle(circle_pos, draw_height, circle_radius,Palette.White);


		ss << "[" << vertices[i].Left << "," << vertices[i].Right << "] ";
		body = ss.str();
		graph.Draw_Text(draw_height, text_V_pos, body.c_str(), Palette.Color_Serial_Number[selected_by_brush[i]]);
		ss.str(string());
		
		if (i < 9) {
			draw_height += 30;
		}
		else {
			draw_height += 40;
		}
	}

	//right info build
	draw_height = 90;
	ss.str(string());
	
	//right info frame

	if (allocated_vertices < 10) {
		right_multipyer = (4 * allocated_vertices)*2 + 10;
	}
	else {
		right_multipyer = (allocated_vertices*2 + 10);

	}

	for (int i = W-200; i <= W-20; i++) {
		graph.Draw_Line(55,i,55 + (allocated_vertices * right_multipyer),i, Palette.Dark_Gray);
	}

	graph.Draw_Text(draw_height - 20, W - 150, "[G STATS]");



	graph.Draw_Text(draw_height, W - 160, "EDGES:");
	ss << this->Edges;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	draw_height += 20;
	ss.str(string());

	graph.Draw_Text(draw_height, W - 160, "MAX DEG:");
	ss << this->Max_Degree;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	ss.str(string());
	draw_height += 20;

	graph.Draw_Text(draw_height, W - 160, "MIN DEG:");
	ss << this->Min_Degree;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	ss.str(string());
	draw_height += 20;

	graph.Draw_Text(draw_height, W - 145, "CHROM NUMBER:");
	ss << this->Chromatic_Number;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 70, body.c_str(), Palette.Dark_Red);
	ss.str(string());
	draw_height += 50;

	//G comp's stats

	graph.Draw_Text(draw_height, W - 125, "[G COMP STATS]");
	draw_height += 20;

	graph.Draw_Text(draw_height, W - 160, "EDGES:");
	ss << this->Gcomp_Edges;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	draw_height += 20;
	ss.str(string());

	graph.Draw_Text(draw_height, W - 160, "MAX DEG:");
	ss << this->Gcomp_Max_Degree;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	ss.str(string());
	draw_height += 20;

	graph.Draw_Text(draw_height, W - 160, "MIN DEG:");
	ss << this->Gcomp_Min_Degree;
	body = ss.str();
	graph.Draw_Text(draw_height, W - 110, body.c_str(), Palette.Dark_Red);
	ss.str(string());
	draw_height += 20;

	//graph.Draw_Circle(W - 100, draw_height, 5, 'r');



	
	graph.Write_Image("Graph");
	delete[] selected_by_brush;
}
