#include "gauss.h"

int diag(Matrix *mat, Matrix  *b, int c){
	return 0;
}
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int c,r,w,ic,x;
	double pom;
	w=0;
	for (c=0; c<mat->c; c++){
		x=diag( mat, b, c);
		if (x==1)
			return 1;
		for (r=w+1; r<mat->r; r++){
			pom=mat->data[r][c];
			for (ic=c; ic<mat->c; ic++){
				mat->data[r][ic]-=pom*mat->data[c][ic]/mat->data[c][c];
			}
			b->data[r][0]=b->data[r][0]-pom*b->data[w][0]/mat->data[w][c];
		}
		w++;
	}
	
	return 0;

}

