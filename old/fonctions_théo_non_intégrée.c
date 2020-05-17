void attributions_des_couleurs_par_atouts(  choix_couleur ){


tab_Atout[0] = 20;
tab_Atout[1] = 14;
tab_Atout[2] = 11;
tab_Atout[3] = 10;
tab_Atout[4] = 4;
tab_Atout[5] = 3;
tab_Atout[6] = 0;

switch(choix_couleur){ /* prendre les cases du tableau dans le dictionnaire */
        case 1:
            7♣ = tab_Atout[6];
            8♣ = tab_Atout[6];
            9♣ = tab_Atout[1];
            10♣ = tab_Atout[3];
            V♣ = tab_Atout[0];
            D♣ = tab_Atout[5];
            R♣ = tab_Atout[4];
            AS♣ = tab_Atout[2];
            break;
        case 2:
            7♠ = tab_Atout[6];
            8♠ = tab_Atout[6];
            9♠ = tab_Atout[1];
            10♠ = tab_Atout[3];
            V♠ = tab_Atout[0];
            D♠ = tab_Atout[5];
            R♠ = tab_Atout[4];
            AS♠ = tab_Atout[2];
            break;
        case 3:
             7♦ = tab_Atout[6];
            8♦ = tab_Atout[6];
            9♦ = tab_Atout[1];
            10♦ = tab_Atout[3];
            V♦= tab_Atout[0];
            D♦ = tab_Atout[5];
            R♦ = tab_Atout[4];
            AS♦ = tab_Atout[2];
            break;
        case 4:
            7♥ = tab_Atout[6];
            8♥= tab_Atout[6];
            9♥ = tab_Atout[1];
            10♥ = tab_Atout[3];
            V♥ = tab_Atout[0];
            D♥ = tab_Atout[5];
            R♥ = tab_Atout[4];
            AS♥ = tab_Atout[2];
            break;
        default :
            printf("Erreur dans l'attribution des atouts");
            break;

}


}


void couleur_des_atouts(){

	if(&choix_couleur == 1 ){
		printf("Les trefles sont les atouts "); /* donnez ls valeur des cartes*/
	}
	else{ 
		if (&choix_couleur == 2){
			printf("Les piques sont les atouts");
	    } 
	    else {
	    	if (&choix_couleur ==3){
				printf("Les carreaux sont les atouts");
	        }else { 
	        	if (&choix_couleur == 4){
					printf("Les coeurs sont les atouts");
	            }else { 
	            	if (&atout == 'T'){
						printf("Toutes les couleurs sont des atouts");
	                }
	                else { 
	                	if (&atout == 'S'){
							printf("il n'y a pas d'atout");
	                    }
	                    else{
	                   		printf("Erreur dans l'attributions des couleurs");
	                    }
	                }
	            }
	        }
	    }
	}

	return 0;
}
