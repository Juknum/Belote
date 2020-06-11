
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void afficher_carte(int * cartes){

	printf(side" Vos cartes :\n");

	printf(carte_top);
	printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
	printf("║ ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║  %s  ║\n",dictionnaire(cartes[0]),dictionnaire(cartes[1]),dictionnaire(cartes[2]),dictionnaire(cartes[3]),dictionnaire(cartes[4]),dictionnaire(cartes[5]),dictionnaire(cartes[6]),dictionnaire(cartes[7]));
	printf("║ ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║ %s   %s ║\n",symbole(cartes[0]),symbole(cartes[0]),symbole(cartes[1]),symbole(cartes[1]),symbole(cartes[2]),symbole(cartes[2]),symbole(cartes[3]),symbole(cartes[3]),symbole(cartes[4]),symbole(cartes[4]),symbole(cartes[5]),symbole(cartes[5]),symbole(cartes[6]),symbole(cartes[6]),symbole(cartes[7]),symbole(cartes[7]));
	printf(carte_bottom);
}