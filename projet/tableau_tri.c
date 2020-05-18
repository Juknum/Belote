#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

void tableau_tri(int * tableau){
	int N = 8; // Nombre d'itération du tri (plante au dessus de 32)

	for(int j = 1; j < N; j++){
		for(int i = 0; i < N-1; i++){
			if( tableau[i] > tableau[i+1]){
				int temp = tableau[i];
				tableau[i] = tableau[i+1];
				tableau[i+1] = temp;
			}
		}
	}

}