int enchere_bot(int * cartes_bot, char * bot, int score_estimation){
	////// COULEUR //////
	int total_carreau = 0;
	int total_coeur   = 0;
	int total_pique   = 0;
	int total_trefle  = 0;

	int total = 0; // Permet de différencier quelle couleur est la + forte
	int result = 0; // Sert à choisir entre 2...4 valeurs identiques (si 2/3/4 couleurs ont le même nbr de pts)

	int joue = 0; // 1 si le bot joue la couleur la + forte

	/////// TA ///////

	// Variables TA
	int ordi_bot_valet  = 0; // Valets présent dans la main du bot

	int suite_ta         = 0; // 1 si Le bot possède une suite pour TA
	int suite_coeur_ta   = 0;
	int suite_carreau_ta = 0;
	int suite_trefle_ta  = 0;
	int suite_pique_ta   = 0;

	/////// SA ///////

	// Variables SA
	int	ordi_bot_as     = 0; // As présent dans la main du bot
	
	int suite_sa         = 0; // 1 si le bot possède la suite pour SA
	int suite_coeur_sa   = 0;
	int suite_carreau_sa = 0;
	int suite_trefle_sa  = 0;
	int suite_pique_sa   = 0;

	printf("\n§ %s examine son jeu...",bot);

	// DEBUG : Affiches les cartes du bot
	/*
	printf("\n%s :",bot);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	*/
	
	// On regarde la valeur totale des cartes par couleur (en atout) et on garde la meilleure couleur
	for(int i = 0; i < 8; i++){
		switch(cartes_bot[i]){
			case 0 ... 8 :
				total_pique += dictionnaire_atout(cartes_bot[i]);
				break;
			case 9 ... 16 :
				total_carreau += dictionnaire_atout(cartes_bot[i]);
				break;
			case 17 ... 24 :
				total_coeur += dictionnaire_atout(cartes_bot[i]);
				break;
			case 25 ... 32 :
				total_trefle += dictionnaire_atout(cartes_bot[i]);
				break;
			default:
				printf("\n erreur switch cartes_bot() avec %s",bot);
				break;
		}
	}

	// DEBUG : Affiche les valeurs d'atout par couleur
	//printf("\nValeur en Atout : %d♠ / %d♦ / %d♥ / %d♣",total_pique,total_carreau,total_coeur,total_trefle);
			
	if(total_pique   >= total_carreau && total_pique   >= total_coeur   && total_pique   >= total_trefle){total += 1   ;}
	if(total_carreau >= total_pique   && total_carreau >= total_coeur   && total_carreau >= total_trefle){total += 10  ;}
	if(total_coeur   >= total_pique   && total_coeur   >= total_carreau && total_coeur   >= total_trefle){total += 100 ;}
	if(total_trefle  >= total_pique   && total_trefle  >= total_carreau && total_trefle  >= total_coeur ){total += 1000;}

	/*
		Possibilitées : Permet d'avoir une solution en cas d'égalité de pts (en atout)
		   1 :                            PIQUE -------
		  10 :                  CARREAU 		-------
		  11 :                  CARREAU + PIQUE
		 100 :          COEUR 					-------
		 101 :          COEUR           + PIQUE
		 110 :          COEUR + CARREAU
		 111 :          COEUR + CARREAU + PIQUE
		1000 : TREFLE                           -------
		1001 : TREFLE                   + PIQUE
		1010 : TREFLE         + CARREAU
		1011 : TREFLE         + CARREAU + PIQUE
		1100 : TREFLE + COEUR
		1101 : TREFLE + COEUR           + PIQUE
		1110 : TREFLE + COEUR + CARREAU
		1111 : TREFLE + COEUR + CARREAU + PIQUE
	*/
			
	switch(total){
		case 1:
			atout = "Pique";
			break;
		case 10:
			atout = "Carreau";
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Carreau";}else{atout = "Pique";}
			break;
		case 100:
			atout = "Coeur";
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Coeur";}else{atout = "Pique";}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){atout = "Coeur";}else{atout = "Carreau";}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Coeur";}else{if(result == 2){atout = "Carreau";}else{atout = "Pique";}}
			break;
		case 1000:
			atout = "Trèfle";
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Pique";}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Carreau";}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Carreau";}else{atout = "Pique";}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Coeur";}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{atout = "Pique";}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{atout = "Carreau";}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{if(result == 3){atout = "Carreau";}else{atout = "Pique";}}}
		break;
	}

	/*
		On regarde le score de la couleur la plus représentée et on estime si ça vaut le coup de jouer couleur
		ou de prendre TA ou SA.
	*/

	// Si le bot a un score supérireur à score_estimation et bien il annonce ces points et joue couleur;
	if(atout == "Carreau"){
		if(total_carreau > score_estimation){
			joue = 1;
			points = total_carreau * 2.5;
		}
	}
	if(atout == "Coeur"){
		if(total_coeur > score_estimation){
			joue = 1;
			points = total_coeur * 2.5;
		}
	}
	if(atout == "Pique"){
		if(total_pique > score_estimation){
			joue = 1;
			points = total_pique * 2.5;
		}
	}
	if(atout == "Trèfle"){
		if(total_trefle > score_estimation){
			joue = 1;
			points = total_trefle * 2.5;
		}
	}

	/*
		Le bot décide de ne pas jouer la couleur possédant le plus haut score, (car en dessous de score_estimation)
		il regarde alors s'il peut faire SA ou TA;
	*/

	if(joue == 0){
		/////// TA ///////
		// On compte les valets possédé par le bot
		for(int i = 0; i < 8; i++){
			if(cartes_bot[i] == 5 || cartes_bot[i] == 13 || cartes_bot[i] == 21 || cartes_bot[i] == 29){
				ordi_bot_valet++;
			}
		}

		// Si le bot n'a pas suffisament de valet, on regarde s'il possède une suite
		if( ordi_bot_valet < 3){
			for(int i = 0; i < 8; i++){
				// test de la suite dans les coeurs
				if(cartes_bot[i] ==  3 || cartes_bot[i] ==  5 || cartes_bot[i] ==  8){suite_coeur_ta++;   }

				// test de la suite dans les carreau
				if(cartes_bot[i] == 11 || cartes_bot[i] == 13 || cartes_bot[i] == 16){suite_carreau_ta++; }

				// test de la suite dans les trèfles
				if(cartes_bot[i] == 19 || cartes_bot[i] == 21 || cartes_bot[i] == 24){suite_trefle_ta++;  }

				// test de la suite dans les pique
				if(cartes_bot[i] == 27 || cartes_bot[i] == 29 || cartes_bot[i] == 32){suite_pique_ta++;   }
			}

			// si l'une des trois variables suites == 3 alors le bot possède une suite;
			if(suite_pique_ta == 3 || suite_trefle_ta == 3 || suite_carreau_ta == 3 || suite_coeur_ta == 3){suite_ta = 1;}
		}
		
		// Décision sur le choix du bot à "prendre" TA:
		if( ordi_bot_valet == 3 || suite_ta == 1 ){
			contrat = bot;
			atout = "TA";
			points = -1;
			printf("\n%s annonce Tout Atout ",bot);
		}
		else{
			/////// SA ///////
			// On compte les As possédé par le bot
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] == 8 || cartes_bot[i] == 16 || cartes_bot[i] == 24 || cartes_bot[i] == 32){ordi_bot_as++;}
			}

			// On vérifie que l'ordi possède la suite (dans tout les cas == elle est nécessaire)
			for(int i = 0; i < 8; i++){
				// test de la suite dans les coeurs
				if(cartes_bot[i] ==  4 || cartes_bot[i] ==  5 || cartes_bot[i] ==  6 || cartes_bot[i] ==  7 || cartes_bot[i] == 8){suite_coeur_sa++;    }
				// test de la suite dans les carreau
				if(cartes_bot[i] == 12 || cartes_bot[i] == 13 || cartes_bot[i] == 14 || cartes_bot[i] == 15 || cartes_bot[i] == 16){suite_carreau_sa++; }
				// test de la suite dans les trèfles
				if(cartes_bot[i] == 20 || cartes_bot[i] == 21 || cartes_bot[i] == 22 || cartes_bot[i] == 23 || cartes_bot[i] == 24){suite_trefle_sa++;  }
				// test de la suite dans les pique
				if(cartes_bot[i] == 28 || cartes_bot[i] == 29 || cartes_bot[i] == 30 || cartes_bot[i] == 31 || cartes_bot[i] == 32){suite_pique_sa++;   }
			}

			// si l'une des trois variables suites == 5 alors le bot possède une suite;
			if(suite_pique_sa == 5 || suite_trefle_sa == 5 || suite_carreau_sa == 5 || suite_coeur_sa == 5){suite_sa = 1;}
			
			if( ordi_bot_as >= 2 && suite_sa == 1 ){
				contrat = bot;
				atout = "SA";
				points = -1;
				printf("\n%s annonce Sans Atout ",bot);
			}
			else{
				/////// Passe ///////
				printf("\n§ %s choisit de passer son tours!",bot);
				atout = "undefined"; // car il ne choisit pas d'atout
				passe++;
			}
		}
	}
	else{ // joue == 1
		contrat = bot;
		points = (points / 10) * 10 + annonce_bot(cartes_bot, bot); // On décide de ne pas garder l'unité (afin d'avoir un nombre de pts rond) et on ajoute les points des annonces
		printf("\n§ %s annonce une couleur de %s avec %d pts",bot,atout,points);
	}
}

// Phase d'Enchère - l'atout a été choisi
int surenchere_bot(int * cartes_bot, char * bot){
	printf("\n§ %s examine son jeu...",bot);

	int total_pique   = 0;
	int total_carreau = 0;
	int total_coeur   = 0;
	int total_trefle  = 0;

	int total  = 0;
	int result = 0;

	char * atout_bot = "undefined";
	
	int points_bot = 0;

	// DEBUG : Affiches les cartes du bot	
	/*
	printf("\n%s :",bot);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	*/

	// On regarde la valeur totale des cartes (en atout) et on choisit ou non la sur-enchere via cette couleur
	for(int i = 0; i < 8; i++){
		switch(cartes_bot[i]){
			case 0 ... 8 :
				total_pique += dictionnaire_atout(cartes_bot[i]);
				break;
			case 9 ... 16 :
				total_carreau += dictionnaire_atout(cartes_bot[i]);
				break;
			case 17 ... 24 :
				total_coeur += dictionnaire_atout(cartes_bot[i]);
				break;
			case 25 ... 32 :
				total_trefle += dictionnaire_atout(cartes_bot[i]);
				break;
			default:
				printf("\n erreur switch cartes_bot() avec %s",bot);
				break;
		}
	}
			
	if(total_pique   >= total_carreau && total_pique   >= total_coeur   && total_pique   >= total_trefle){total += 1   ;}
	if(total_carreau >= total_pique   && total_carreau >= total_coeur   && total_carreau >= total_trefle){total += 10  ;}
	if(total_coeur   >= total_pique   && total_coeur   >= total_carreau && total_coeur   >= total_trefle){total += 100 ;}
	if(total_trefle  >= total_pique   && total_trefle  >= total_carreau && total_trefle  >= total_coeur ){total += 1000;}

	/*
		Possibilitées : Permet d'avoir une solution en cas d'égalité de pts (en atout)
		   1 :                            PIQUE -------
		  10 :                  CARREAU 		-------
		  11 :                  CARREAU + PIQUE
		 100 :          COEUR 					-------
		 101 :          COEUR           + PIQUE
		 110 :          COEUR + CARREAU
		 111 :          COEUR + CARREAU + PIQUE
		1000 : TREFLE                           -------
		1001 : TREFLE                   + PIQUE
		1010 : TREFLE         + CARREAU
		1011 : TREFLE         + CARREAU + PIQUE
		1100 : TREFLE + COEUR
		1101 : TREFLE + COEUR           + PIQUE
		1110 : TREFLE + COEUR + CARREAU
		1111 : TREFLE + COEUR + CARREAU + PIQUE
	*/
			
	switch(total){
		case 1:
			atout_bot = "Pique";
			break;
		case 10:
			atout_bot = "Carreau";
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Carreau";}else{atout_bot = "Pique";}
			break;
		case 100:
			atout_bot = "Coeur";
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Coeur";}else{atout_bot = "Pique";}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Coeur";}else{atout_bot = "Carreau";}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Coeur";}else{if(result == 2){atout_bot = "Carreau";}else{atout_bot = "Pique";}}
			break;
		case 1000:
			atout_bot = "Trèfle";
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Pique";}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Carreau";}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Carreau";}else{atout_bot = "Pique";}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Coeur";}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{atout_bot = "Pique";}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{atout_bot = "Carreau";}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{if(result == 3){atout_bot = "Carreau";}else{atout_bot = "Pique";}}}
		break;
	}

	// DEBUG: affiche l'atout considéré par le bot (peut être différente de l'atout déjà choisi)
	//printf("\n  atout_bot = %s",atout_bot);

	// Si le bot a un score supérireur à score_estimation et bien il annonce ces points et joue couleur;
	if(atout_bot == "Carreau"){
		points_bot = total_carreau * 2.5;
	}
	if(atout_bot == "Coeur"){
		points_bot = total_coeur * 2.5;
	}
	if(atout_bot == "Pique"){
		points_bot = total_pique * 2.5;
	}
	if(atout_bot == "Trèfle"){
		points_bot = total_trefle * 2.5;
	}

	points_bot = points_bot / 10 * 10; // Ex: 85 devient 80 (on décide de perdre l'unité)

	points_bot = points_bot + annonce_bot(cartes_bot,bot);

	// DEBUG : affiche les points de la couleur considérée
	//printf("\n  points_bot = %d",points_bot);

	if(points_bot >= points && points_bot >= 80){
		printf("\n§ %s sur-encherit et annonce une couleur de %s avec %d pts",bot,atout_bot,points_bot);
		contrat = bot;
		points = points_bot;
		atout = atout_bot;
	}else{
		printf("\n§ %s passe sont tours!",bot);
		passe++;
	}

}