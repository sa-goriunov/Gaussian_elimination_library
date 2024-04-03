#include "Gauss.h"
#include <stdio.h>
#include <stdlib.h>

//Solve the trianglized matrix (if system has any answers)
double *Answer(struct matrix *matr, double *answer){  
	if (answer == NULL) { error(); matr->condition = 5; return NULL; }
	else {
		answer[matr->columns - 2] = (matr->array[matr->columns * matr->strings - 1]) / (matr->array[matr->columns * matr->strings - 2]);
		for (int i = matr->strings - 2; i >= 0; i--) {
			double result_i = matr->array[(i + 1) * matr->columns - 1];
			for (int j = matr->columns - 2; j > i; j--)
				result_i -= (answer[j] * matr->array[i * matr->columns + j]);
			answer[i] = result_i / matr->array[i * matr->columns + i];
		}
		return answer;
	}
}