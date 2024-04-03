#include "Gauss.h"
#include "stdio.h"
#include "stdlib.h"

//Check the matrix's condition
void condition(struct matrix *matr) {

	if (matr->strings < matr->columns-1) {  matr->condition = 8; } //неопределённая
	else {
		if (matr->strings > matr->columns - 1) {  matr->condition = 9; } //несовместная
		else{
		if (matr->array == NULL) { error(); matr->condition = 5; }
		else { matr->condition = 0; }
		}
	}
}
