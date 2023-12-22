#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL || b==NULL || A->r<1 || A->c<1 || b->r<1 || b->c<1){
		fprintf(stderr, "Błąd! Niepoprawne dane. \n");
		return 2;
	}
	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);
	if (res!=0){
		fprintf(stderr, "Błąd! Eliminacja Gaussa nie powiodła się. \n");
		return 3;
	}

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);
		printToScreen(x);
	  freeMatrix(x);
	} else {
		fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
		return 1;
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
