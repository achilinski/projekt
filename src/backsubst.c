#include "backsubst.h"
#include "mat_io.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int i, j;
	if(x->c != 1 || b->c != 1 || mat->r != mat->c || mat->r != x->r || mat->r != b->r)
		return 2;
	for(i = mat->r-1; i >= 0; i--) {
	       double sum = 0.0;
	       for(j = i+1; j< mat->r; j++)
			sum += mat->data[i][j]*x->data[j][0];
	       if(mat->data[i][i] == 0)
		       return 1;
	       x->data[i][0] = (b->data[i][0]-sum)/mat->data[i][i];
	}	
				//to ponizej jest przepisaniem b do x. Nalezy to poprawic! /

//				int i;
//				for (i =0; i < x->r; i++) {
//								x->data[i][0] = b->data[i][0];
//				}

				return 0;
}


