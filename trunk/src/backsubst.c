#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

				int n = mat->r;  // Assuming A is a square matrix

    // Back substitution loop
    for (int i = n - 1; i >= 0; i--) {
        float sum = 0.0;

        // Calculate the sum of known terms
        for (int j = i + 1; j < n; j++) {
            sum += mat->data[i][j] * x->data[j][0];
        }

        // Solve for the variable
        if (mat->data[i][i] == 0.0) {
            return 1;  }
        x->data[i][0] = (b->data[i][0] - sum) / mat->data[i][i];
    }

    return 0;  
	       }


