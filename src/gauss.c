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
<<<<<<< HEAD
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

			for (int k=0; k<nc; k++ ) {
=======
	int nr = mat->r;
	int nc = mat->c;
	double **A = mat->data;
	double **B = b->data;
printf("\ninicjacja zmiennych\n");
	if (nr!=nc)
		return -1;
printf("\nreturn -1 widze\n");
	for(int i=0; i<nc ; i++ ) {
		double max = fabs(A[i][0]);
		int ind = 0;
		for (int t=i; t < nr; t++) {
printf("trafilem na fora");		
			if ( fabs(A[t][i]) > max ) {
				max = fabs(A[t][i]);
				ind = t;
			}
		}
printf("\n robie se jakis if\n");	
		double *tmp = A[ind];
		A[ind] = A[i];
		A[i] = tmp;
printf("\nrobie jakies podmiany w A\n");
		double *tmpb = B[ind];
		B[ind] = B[i];
		B[i] = tmpb;
printf("\nrobie jakies podmiany w B\n");
		for(int j=i+1; j<nr; j++) {
			if ( A[i][i] == 0 ) 
				return 1;
			double q = A[j][i]/A[i][i];
printf("\nsam nie wiem co\n");
			for ( int k = 0; k<nc; k++) {
>>>>>>> 7439d5e1eb6450e36fab413e1cf24eb3e91b30a5
				A[j][k] = A[j][k] - q*A[i][k];
			}
			b->data[j][0]=b->data[j][0] - q*b->data[i][0];
		}
	}
	return 0;
}
