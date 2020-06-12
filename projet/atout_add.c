/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	atout_add.c : On compte les atout entre chaque carte posée (utile pour la gestion de bot_plis.c)
	- on regarde de quel atout il sagit
		- on regarde l'ensemble des cartes jouée
			- si une des cartes jouées est un atout on incrémente nb_atout
			- si ... on l'ajoute au tableau d'atout
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void atout_add(int nb_carte_jouee, int atout, int* tableau_pli, int* tableau_atout, int *nb_atout){

	// Compte du nombre d'atout
	switch(atout){
		case 1: // Pique est atout
			// On regarde les cartes jouées et on compte le nbr d'atouts
			for(int i = nb_carte_jouee; i < 4; i++){
				switch(tableau_pli[i]){
					case 1 ... 8 :
						*nb_atout = *nb_atout +1;
						tableau_atout[i] = tableau_pli[i];
						break;
					default:
						break;
					}
				}
			break;
		case 2: // Carreau est atout
			// On regarde les cartes jouées et on compte le nbr d'atouts
			for(int i = nb_carte_jouee; i < 4; i++){
				switch(tableau_pli[i]){
					case 9 ... 16 :
						*nb_atout = *nb_atout +1;
						tableau_atout[i] = tableau_pli[i];
						break;
					default:
						break;
				}
			}
			break;
		case 3: // Coeur est atout
			// On regarde les cartes jouées et on compte le nbr d'atouts
			for(int i = nb_carte_jouee; i < 4; i++){
				switch(tableau_pli[i]){
					case 17 ... 24 :
						*nb_atout = *nb_atout +1;
						tableau_atout[i] = tableau_pli[i];
						break;
					default:
						break;
				}
			}
			break;
		case 4: // Trefle est atout
			// On regarde les cartes jouées et on compte le nbr d'atouts
			for(int i = nb_carte_jouee; i < 4; i++){
				switch(tableau_pli[i]){
					case 25 ... 32 :
						*nb_atout = *nb_atout +1;
						tableau_atout[i] = tableau_pli[i];
						break;
					default:
						break;
				}
			}
			break;
		default:
			printf(side_error" switch(%d) atout",atout);
			break;
	}
}