#ifndef GAUSS
#define GAUSS

struct matrix {
	int columns;
	int strings;
	double* array;
	int condition; //решаема ли система
};

void trianglize(struct matrix* matr);

void condition(struct matrix* matr);

double* Answer(struct matrix* matr, double* answer);

void printTEST(struct matrix matr);

double* gauss(struct matrix* matr, double* answer);

void error();

#endif