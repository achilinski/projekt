#include "gauss.h"
#include <stdio.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */

int eliminate(Matrix *mat, Matrix *b){
	int nr = mat->r;
	int nc = mat->c;
	double **A = mat->data;
	double **B = b->data;
	if (nr!=nc)
		return -1;

	for(int i=0; i<nc ; i++ ) {
		double max = fabs(A[i][0]);
		int ind = 0;
		for (int t=i; t < nr; t++) {
			if ( fabs(A[t][i]) > max ) {
				max = fabs(A[t][i]);
				ind = t;
			}
		}
		double *tmp = A[ind];
		A[ind] = A[i];
		A[i] = tmp;

		double *tmpb = B[ind];
		B[ind] = B[i];
		B[i] = tmpb;

		for(int j=i+1; j<nr; j++) {
			if ( A[i][i] == 0 ) 
				return 1;
			double q = A[j][i]/A[i][i];

			for ( int k = 0; k<nc; k++) {
				A[j][k] = A[j][k] - q*A[i][k];
			}
			B[j][0] = B[j][0] - q*B[j][0];	
			
		}

	}	
	return 0;
}	
