/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	main.c : 
	- Changement de la table de caractère (si Windows)
	- Lancement de la fonction menu()
	- Reset des couleurs (remet sur la couleur par défaut du cmd == choisi par l'utilisateur )

*/

#include <stdio.h>
#include <time.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

// Main
int main(void){

	table_ascii;
	printf(reset);
	bbcolor;
	printf(white);

	clean;

	srand(time(NULL));

	menu();

	printf(reset);
	
	return 0;
}