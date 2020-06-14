#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void afficher_entete(char* atout, int atout_n, int numero_pli,char* contrat, int points, char* team_north_joueur, int points_north_joueur, int points_west_east){
	
	char* symbole = "x\0";

	clean;

	printf(title_barre1);
	printf(title_barre_top1);
	printf(title_g" Phase de Jeu! "title_d);
	printf(title_pli_left"%d",numero_pli);
	printf(title_pli_right);
		
	// On traduit numériquement l'atout pour plus tard (1 = Pique, 2 = Carreau, ...)
	if(strcmp(atout, "Pique") == 0){
		atout_n = 1;
		symbole = pique;
	}
	if(strcmp(atout, "Carreau") == 0){
		atout_n = 2;
		symbole = carreau;
	}
	if(strcmp(atout, "Coeur") == 0){
		atout_n = 3;
		symbole = coeur;
	}
	if(strcmp(atout, "Trèfle") == 0){
		atout_n = 4;
		symbole = trefle;
	}

	printf(title_info" - Atout  : %s %s\n",atout,symbole);
	printf(title_ninfo" - Contrat: %s (%d pts)\n",contrat,points);
	printf(title_ninfo" - %s : %d\n",team_north_joueur, points_north_joueur);
	printf(title_ninfo" - Ouest/Est : %d\n",points_west_east);
	printf(title_barre2);
}