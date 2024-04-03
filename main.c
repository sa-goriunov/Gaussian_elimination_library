#include "Gauss.h"
#include <stdio.h>

//Print a matrix (function for tests)
void printTEST(struct matrix matr){  
	for (int i = 0; i < matr.columns*matr.strings; i++)
		{
			printf("%.2lf ", matr.array[i]); 
			if ((i+1)%matr.columns == 0 ) printf("\n");
		}	printf("\n");
}

//Error warning if something went wrong
void error() { printf("Fatal system error"); }

//The function of Gaussian elimination
//Gets the matrix of system and the array to put answers in
//Returns the array of answers
double *gauss(struct matrix* matr, double *answer) {
	condition(matr);
	if (matr->condition == 0) { trianglize(matr); };
	switch (matr->condition) {
	case 0: return Answer(matr, answer);
	case 8: printf("Infinity number of answers. :("); break;
	case 9: printf("Can't find any answers. :("); break;
	case 5: error(); break;
	default: error();
	}
	return NULL;
}