#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	printf("read");
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("print");
	printToScreen(A);
	printToScreen(b);
	
	printf("zaczynam eliminacje");
	res = eliminate(A,b);
	printf("wykonano eliminate");
	x = createMatrix(b->r, 1);
	printf("strworznow matix");
	if (x != NULL) {
		res = backsubst(x,A,b);
		printf("wykonano backstub");

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
