#include <math.h>
#include "gauss.h"

int diag(Matrix *mat, Matrix  *b, int c){
	int i;
	double tmp;
	double max=mat->data[c][c];
	int max_id=c;
	for(i=c; i<mat->c; i++)
		if (fabs(mat->data[i][c])>max){
			max=fabs(mat->data[i][c]);
			max_id=i;
		}
	for(i=c; i<mat->c; i++){
		tmp=mat->data[c][i];
		mat->data[c][i]=mat->data[max_id][i];
		mat->data[max_id][i]=tmp;
	}
	for (i=0; i<b->c; i++){
		tmp=b->data[c][i];
		b->data[c][i]=b->data[max_id][i];
		b->data[max_id][i]=tmp;
	}
	if (max==0.0)
		return 1;
	
	return 0;
}
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	int c, r, w, ic;
    double pom;

    w = 0;

    for (c = 0; c < mat->c; c++) {
        int x = diag(mat, b, c);

        if (x == 1) {
            return 1;
        }

        for (r = w + 1; r < mat->r; r++) {
            pom = mat->data[r][c];

            for (ic = c; ic < mat->c; ic++) {
                mat->data[r][ic] -= pom * mat->data[c][ic] / mat->data[c][c];
            }

            for (ic = 0; ic < b->c; ic++) {
                b->data[r][ic] -= pom * b->data[w][ic] / mat->data[w][c];
            }
        }

        w++;
    }

    return 0;

}

