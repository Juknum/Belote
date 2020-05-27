/*

		BELOTE COINCHEE EN C : Groupe F
		- Julien Constant
		- Ewen Bourdon
		- Théo Silva

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

#include "./header/fonctions.h"

/* 
	Permet le changement de la table des caractères de la console 
	> si le programme est utilisé sous Windows
*/
#ifdef _WIN32
#include <windows.h>
#endif

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Main
int main(void){
	/* 
		Change la table des caractères de la console 
		> si le programme est utilisé sous Windows
	*/
	#ifdef _WIN32
	    system("chcp 65001");
	    system("cls");
	#endif

	srand(time(NULL));

	printf(WHT); // On met le texte en blanc pendant l'execution

	menu();

	printf(RESET); // On remet la couleur de base de la console (si l'executeur a changer la couleur de base)
	
return 0;
}