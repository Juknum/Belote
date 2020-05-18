/*

		BELOTE COINCHEE EN C : Groupe F
		- Julien Constant
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

// Main
int main(void){
	/* 
		Change la table des caractères de la console 
		> si le programme est utilisé sous Windows
	*/
	#ifdef _WIN32
	    SetConsoleOutputCP(65001);
	#endif

	srand(time(NULL));

	menu();
	
return 0;
}