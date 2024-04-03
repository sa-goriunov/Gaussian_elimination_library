#include "Gauss.h"
#include "math.h"

//Swap two strings (numbers a and b) of a matrix
void swap(struct matrix *matr, int a, int b){
	for (int i = 0; i < matr->columns; i++) {
		double tmp = matr->array[a * matr->columns + i];
		matr->array[a * matr->columns + i] = matr->array[b * matr->columns + i];
		matr->array[b * matr->columns + i] = tmp;
	}
}

//Check if system has no answer
void check(struct matrix *matr, int i) {
	if (fabs(matr->array[i * matr->columns + i])<0.001 ) {
		int y = i; 
		while ((fabs(matr->array[y * matr->columns + i]) < 0.001) && (y < matr->strings-1)) {
			y++;
		}
		if (matr->array[y * matr->columns + i]==0) { matr->condition = 9;}
		else { swap(matr, i, y); }
	}
}

//Do a matrix trianglized as Gaussian elimination
void trianglize(struct matrix *matr) {
	for (int i = 0; i < matr->columns - 1; i++) {
		check(matr, i);
		double tmp = matr->array[i * matr->columns + i];
		if(matr->condition == 0){
			for (int j = i; j < matr->columns; j++)
				matr->array[i * matr->columns + j] /= tmp; 
			for (int j = i + 1; j < matr->strings; j++) {
				double ff = matr->array[j*matr->columns+i];
				for (int k = i; k < matr->columns; k++)
					matr->array[j * matr->columns + k] -= ff * matr->array[i*matr->columns+k];
			}
		}
		else { break; }
	}
}