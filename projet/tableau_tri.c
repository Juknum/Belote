/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	tableau_tri.c : Permet de trier de manière croissante un tableau


*/

#include <stdio.h>
#include <stdlib.h>

#include "./header/fonctions.h" 

void tableau_tri(int * tableau){
	int N = 8; // Nombre d'itération du tri (plante au dessus de 32)

	// DEBUG : Affiche les cartes non triées
	/*
	printf(" Les cartes        :");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(tableau[i]));
	}
	printf("\n");
	*/
	
	for(int j = 1; j < N; j++){
		for(int i = 0; i < N-1; i++){
			if( tableau[i] > tableau[i+1]){
				int temp = tableau[i];
				tableau[i] = tableau[i+1];
				tableau[i+1] = temp;
			}
		}
	}

	// DEBUG : Affiche les cartes triées
	/*
	printf(" Les cartes triées :");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(tableau[i]));
	}
	printf("\n");
	*/
}