#include <stdio.h>
#include <stdlib.h>

#include "./header/fonctions.h"

void tableau_tri_slave(int * tableau_master, int * tableau_slave){
	int N = 8; // Nombre d'itération du tri (plante au dessus de 32)

	int temp_master, temp_slave;
	
	for(int j = 1; j < N; j++){

		for(int i = 0; i < N-1; i++){

			if( tableau_master[i] > tableau_master[i+1]){
				temp_master = tableau_master[i];
				temp_slave  = tableau_slave[i];

				tableau_master[i] = tableau_master[i+1];
				tableau_slave[i]  = tableau_slave[i+1];

				tableau_master[i+1] = temp_master;
				tableau_slave[i+1]  = temp_slave;
			}
		}
	}
}