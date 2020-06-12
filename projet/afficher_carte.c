/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	afficher_carte.c : Affiche les cartes, en fonction de sa taille, d'un tableau contenant des int de 1 a 32
	- main == 0 : On affiche une seule carte : utilisé dans plis.c
	- main == 1 : On affiche les 8 cartes du joueur
		- nb_carte 1 ... 8 : affiche le nombre de carte restante en fonction du plis
	- main == 2 : On affiche 4 cartes, utilisé dans plis() à la fin d'un plis

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void afficher_carte(int * cartes, int nb_carte, int main){

	switch(main){
		case 0:
			printf(" et pose :\n");
			printf(carte_top_1);
			printf("║ ║ %s   %s ║\n",symbole(cartes[nb_carte]),symbole(cartes[nb_carte]));
			printf("║ ║  %s  ║\n",dictionnaire(cartes[nb_carte]));
			printf("║ ║ %s   %s ║\n",symbole(cartes[nb_carte]),symbole(cartes[nb_carte]));
			printf(carte_bottom_1);
			break;

		case 1:
			printf(side" Vos cartes :\n");
			switch(nb_carte){
			// Il ne manque aucune carte
			case 1:
				printf(carte_top);
				printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[0]),dictionnaire(cartes[1]),dictionnaire(cartes[2]),dictionnaire(cartes[3]),dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 2:
				printf(carte_top);
				printf("║ ║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[1]),dictionnaire(cartes[2]),dictionnaire(cartes[3]),dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 3:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[2]),dictionnaire(cartes[3]),dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 4:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[3]),dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 5:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 6:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 7:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║\n",symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║  %s  ║  %s  ║\n",dictionnaire(cartes[6]),dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║ %s   %s ║\n",symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			case 8:
				printf(carte_top);
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║\n",symbole(cartes[7]),symbole(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║  %s  ║\n",dictionnaire(cartes[7]));
				printf("║ ║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║░░░░░░░║ %s   %s ║\n",symbole(cartes[7]),symbole(cartes[7]));
				printf(carte_bottom);
				break;
			}
			break;

		case 2:
			printf(side" Cartes jouées pendant la manche:\n");
			printf(carte_top_4);
			printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]));
			printf("║ ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[0]),dictionnaire(cartes[1]),dictionnaire(cartes[2]),dictionnaire(cartes[3]));
			printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]));
			printf(carte_bottom_4);
			break;
		
		default:
			printf(side_error" Erreur lors du choix de la main dans afficher_carte()");
			break;
	}
}