/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	ramasser.c :
		- On reprend les cartes de chaque joueur sans les mélanger 
		  et on retourne un tableau de 32 int contenant les cartes

*/

#include <stdio.h>
#include <stdlib.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void ramasser(int redistribue, int distributeur, char * nom_joueur, int * cartes_west, int * cartes_north, int * cartes_east, int * cartes_joueur){
	printf(side_info" Ramassage des cartes... ");

	int cartes[32] = {0};

	switch(distributeur){
		case 1: // Joueur a distribué -> on ramasse en premier Ouest -> Nord -> Est -> Joueur
			printf("%s ramasse...",nom_joueur);
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_joueur[i]; }
			break;
		case 2: // Ouest a distribué -> on ramasse en premier Nord -> Est -> Joueur -> Ouest
			printf("Ouest ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_west[i];   }
			break; 
		case 3: // Nord a distribué -> on ramasse en premier Est -> Joueur -> Ouest -> Nord
			printf("Nord ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_north[i];  }
			break;
		case 4: // Est a distribué -> on ramasse en premier Joueur -> Ouest -> Nord -> Est
			printf("Est ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_east[i];   }
			break;
		default:
			printf(side_error" switch ramasser(%d)",distributeur);
			break;
	}
	
	// Les mains sont vides donc on vide chaque joueur (on met à 0)
	for(int i = 0; i < 8; i++){
		cartes_joueur[i] = 0;
		cartes_west[i]   = 0;
		cartes_north[i]  = 0;
		cartes_east[i]   = 0;
	}

	printf("Fait!\n");

	if(redistribue == 1){
		distribuer(distributeur+1, cartes, nom_joueur, cartes_west, cartes_north, cartes_east, cartes_joueur);
	}

}