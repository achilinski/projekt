#include "gauss.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int max_element(Matrix *mat, int col) {
	double maxi = -(double)(INFINITY -1);
	int row = col;
	for ( int i=col; i<mat->r; i++) {
		if (mat->data[i][col]>maxi) {
			row = i;
			maxi = mat->data[i][col];
		} else if (-mat->data[i][col]>maxi) {
			row = i;
			maxi = -mat->data[i][col];
		}
	}
	return row;
}


void swap(Matrix *mat, int row, Matrix *b) {
	int sw = max_element(mat, row);
	double temp;

	for (int i=0; i<mat->r; i++) {
		temp = mat->data[row][i];
		mat->data[row][i]=mat->data[sw][i];
		mat->data[row][i]=temp;
	}

	temp = b->data[row][0];
	b->data[row][0]=b->data[row][0];
	b->data[row][0]=temp;

}
int eliminate(Matrix *mat, Matrix *b){
	int nr=mat->r;
	int nc=mat->c;
	double **A=mat->data;
	double q;

	for (int i=0; i<nc; i++) {
		swap(mat, i, b);

		if (A[i][i] == 0) 
			return 1;

		for (int j=i+1; j<nr; j++) {
			q=A[j][i]/A[i][i];

			for (int k=0; k<nc; k++ ){
				A[j][k] = A[j][k] - q*A[i][k];
			}
			b->data[j][0]=b->data[j][0] - q*b->data[i][0];
		}
	}
	return 0;
}
