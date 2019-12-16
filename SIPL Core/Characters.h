#pragma once

/*typedef struct cfB {
	int B[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfBlank;*/



typedef struct cfA {
	int A[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,1,0,0,0,
	  0,0,1,1,0,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfA;

typedef struct cfB {
	int B[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfB;

typedef struct cfC {
	int C[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,1,0,0,1,1,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,1,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfC;

typedef struct cfD {
	int D[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfD;

typedef struct cfE {
	int E[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfE;

typedef struct cfF {
	int F[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfF;

typedef struct cfG {
	int G[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,1,1,1,1,0,
	  0,1,1,0,0,1,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfG;

typedef struct cfH {
	int H[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfH;

typedef struct cfI {
	int I[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfI;

typedef struct cfJ {
	int J[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,1,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfJ;

typedef struct cfK {
	int K[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,1,1,0,0,
	  0,1,1,0,1,1,0,0,0,
	  0,1,1,1,1,0,0,0,0,
	  0,1,1,0,1,1,0,0,0,
	  0,1,1,0,0,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfK;

typedef struct cfL {
	int L[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfL;

typedef struct cfM {
	int M[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,0,1,1,1,0,
	  0,1,1,1,1,1,1,1,0,
	  0,1,1,0,1,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfM;

typedef struct cfN {
	int N[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,0,0,1,1,0,
	  0,1,1,1,1,0,1,1,0,
	  0,1,1,0,1,1,1,1,0,
	  0,1,1,0,0,1,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfN;

typedef struct cfO {
	int O[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfO;

typedef struct cfP {
	int P[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfP;

typedef struct cfQ {
	int Q[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,1,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfQ;

typedef struct cfR {
	int R[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,0,0,
	  0,1,1,0,0,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfR;

typedef struct cfS {
	int S[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,1,1,1,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,1,1,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfS;

typedef struct cfT {
	int T[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfT;

typedef struct cfU {
	int U[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,1,0,1,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfU;


typedef struct cfV {
	int V[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,0,1,1,0,0,
	  0,0,0,1,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfV;

typedef struct cfW {
	int W[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,1,0,1,1,0,
	  0,1,1,1,1,1,1,1,0,
	  0,1,1,1,0,1,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfW;

typedef struct cfX {
	int X[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,0,1,1,0,0,
	  0,0,0,1,1,1,0,0,0,
	  0,0,1,1,0,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfX;

typedef struct cfY {
	int Y[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,0,1,1,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfY;

typedef struct cfZ {
	int Z[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,1,1,1,1,1,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfZ;

typedef struct cf0 {
	int Zero[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,1,1,1,0,
	  0,1,1,0,1,0,1,1,0,
	  0,1,1,1,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf0;

typedef struct cf1 {
	int One[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf1;

typedef struct cf2 {
	int Two[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,1,1,1,1,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,1,1,1,1,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf2;

typedef struct cf3 {
	int Three[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf3;

typedef struct cf4 {
	int Four[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,1,0,0,
	  0,0,0,1,1,1,1,0,0,
	  0,0,1,1,0,1,1,0,0,
	  0,1,1,0,0,1,1,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf4;

typedef struct cf5 {
	int Five[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,1,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf5;

typedef struct cf6 {
	int Six[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,1,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,1,1,0,0,1,1,0,
	  0,0,0,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf6;

typedef struct cf7 {
	int Seven[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,1,1,1,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf7;

typedef struct cf8 {
	int Eight[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,1,0,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf8;

typedef struct cf9 {
	int Nine[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,0,0,0,
	  0,1,1,0,0,1,1,0,0,
	  0,1,1,0,0,1,1,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,1,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cf9;

typedef struct cfEP{
	int exclamation_point[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfEP;

typedef struct cfQM {
	int question_mark[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,1,1,1,1,1,0,0,
	  0,1,0,0,0,0,1,1,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfQM;

typedef struct cfRB {
	int Right_Braket[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfRB;

typedef struct cfLB {
	int Left_Braket[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,0,0,
	  0,0,1,1,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfLB;

typedef struct cfAS {
	int Ampersand[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,0,1,1,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfAS;

typedef struct cfPR {
	int Precent[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,0,0,0,0,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,1,1,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,1,1,0,0,1,1,0,
	  0,1,1,0,0,0,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfPR;
//

typedef struct cfCM {
	int Comma[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,1,1,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfCM;


typedef struct cfSBL {


	int Square_Braket_Left[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,1,1,1,0,0,0,0,0,
	  0,1,0,0,0,0,0,0,0,
	  0,1,0,0,0,0,0,0,0,
	  0,1,0,0,0,0,0,0,0,
	  0,1,0,0,0,0,0,0,0,
	  0,1,0,0,0,0,0,0,0,
	  0,1,1,1,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfSBL;

typedef struct cfSBR {
	int Square_Braket_Right[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,1,1,1,0,
	  0,0,0,0,0,0,0,1,0,
	  0,0,0,0,0,0,0,1,0,
	  0,0,0,0,0,0,0,1,0,
	  0,0,0,0,0,0,0,1,0,
	  0,0,0,0,0,0,0,1,0,
	  0,0,0,0,0,1,1,1,0,
	  0,0,0,0,0,0,0,0,0
	};

}cfSBR;

typedef struct cfCO {
	int Colon[81] =
	{ 0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,0,0,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,1,1,0,0,0,0,
	  0,0,0,0,0,0,0,0,0
	};
	


}cfCO;

typedef struct LibCharacters {


	//UpperCase
	cfA Letter_A;
	cfB Letter_B;
	cfC Letter_C;
	cfD Letter_D;
	cfE Letter_E;
	cfF Letter_F;
	cfG Letter_G;
	cfH Letter_H;
	cfI Letter_I;
	cfJ Letter_J;
	cfK Letter_K;
	cfL Letter_L;
	cfM Letter_M;
	cfN Letter_N;
	cfO Letter_O;
	cfP Letter_P;
	cfQ Letter_Q;
	cfR Letter_R;
	cfS Letter_S;
	cfT Letter_T;
	cfU Letter_U;
	cfV Letter_V;
	cfW Letter_W;
	cfX Letter_X;
	cfY Letter_Y;
	cfZ Letter_Z;

	//Numbers
	cf0 Number_Zero;
	cf1 Number_One;
	cf2 Number_Two;
	cf3 Number_Three;
	cf4 Number_Four;
	cf5 Number_Five;
	cf6 Number_Six;
	cf7 Number_Seven;
	cf8 Number_Eight;
	cf9 Number_Nine;

	//Symbols
	cfEP Exclamation_Point;
	cfQM Quesiton_Mark;
	cfRB Right_Braket;
	cfLB Left_Braket;
	cfAS Ampersand;
	cfCM Comma;
	cfSBL Squaure_Braket_Left;
	cfSBR Square_Braket_Right;
	cfCO Colon;



}LibCharacters;

