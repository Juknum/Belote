/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	tableau_tri_slaves.c : Permet de trier deux tableaux selon un autre


*/



#include <stdio.h>
#include <stdlib.h>

#include "./header/fonctions.h"

void tableau_tri_slaves(int * tableau_master, int * tableau_slave1, int * tableau_slave2){
	int N = 8; // Nombre d'itération du tri (plante au dessus de 32)

	int temp_master, temp_slave1, temp_slave2;
	
	for(int j = 1; j < N; j++){

		for(int i = 0; i < N-1; i++){

			if( tableau_master[i] > tableau_master[i+1]){
				temp_master = tableau_master[i];
				temp_slave1 = tableau_slave1[i];
				temp_slave2 = tableau_slave2[i];

				tableau_master[i] = tableau_master[i+1];
				tableau_slave1[i] = tableau_slave1[i+1];
				tableau_slave2[i] = tableau_slave2[i+1];

				tableau_master[i+1] = temp_master;
				tableau_slave1[i+1] = temp_slave1;
				tableau_slave2[i+1] = temp_slave2;
			}
		}
	}
}