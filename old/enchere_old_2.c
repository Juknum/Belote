printf("Ouest examine son jeu...\n");

				/*
					Chaque bot possède cette partie du programme (elle est identique mais personnelle);
					Il regarde d'abord s'il peut effectuer un TA puis SA puis Couleur
					Il compte ses points en fonction du nombre de carte haute qu'il possède; 60 + x * cartes hautes
				*/

				// Le bot doit déjà savoir s'il peut réaliser une SA ou TA:
				
				/////// TA ///////
				
				// Variables TA
				int ordi_west_valet = 0;

				int suite_ta = 0;
				int suite_coeur_ta   = 0;
				int suite_carreau_ta = 0;
				int suite_trefle_ta  = 0;
				int suite_pique_ta   = 0;

				// On compte les valets possédé par le bot
				for(int i = 0; i < 8; i++){
					if(cartes_west[i] == 5 || cartes_west[i] == 13 || cartes_west[i] == 21 || cartes_west[i] == 29){
						ordi_west_valet++;
					}
				}

				// Si le bot n'a pas suffisament de valet, on regarde s'il possède une suite
				if( ordi_west_valet < 3){
					for(int i = 0; i < 8; i++){
						// test de la suite dans les coeurs
						if(cartes_west[i] == 3 || cartes_west[i] == 5 || cartes_west[i] == 8){
							suite_coeur_ta++;
						}

						// test de la suite dans les carreau
						if(cartes_west[i] == 11 || cartes_west[i] == 13 || cartes_west[i] == 16){
							suite_carreau_ta++;
						}

						// test de la suite dans les trèfles
						if(cartes_west[i] == 19 || cartes_west[i] == 21 || cartes_west[i] == 24){
							suite_trefle_ta++;
						}

						// test de la suite dans les pique
						if(cartes_west[i] == 27 || cartes_west[i] == 29 || cartes_west[i] == 32){
							suite_pique_ta++;
						}
					}

					// si l'une des trois variables suites == 3 alors le bot possède une suite;
					if(suite_pique_ta == 3 || suite_trefle_ta == 3 || suite_carreau_ta == 3 || suite_coeur_ta == 3){
						suite_ta = 1;
						// DEBUG : printf("\nsuite : %d",suite);
					}
				}

				// Décision sur le choix du bot à "prendre" TA:
				if( ordi_west_valet == 3 || suite_ta == 1 ){
					atout = "TA";
					points = -1;
					printf("\nOuest annonce Tout Atout ");
				}else{
					/////// SA ///////

					// Variables SA
					int	ordi_west_as    = 0;

					int suite_sa = 0;
					int suite_coeur_sa   = 0;
					int suite_carreau_sa = 0;
					int suite_trefle_sa  = 0;
					int suite_pique_sa   = 0;

					// On compte les As possédé par le bot
					for(int i = 0; i < 8; i++){
						if(cartes_west[i] == 8 || cartes_west[i] == 16 || cartes_west[i] == 24 || cartes_west[i] == 32){
							ordi_west_as++;
						}
					}

					// On vérifie que l'ordi possède la suite (dans tout les cas == elle est nécessaire)
					for(int i = 0; i < 8; i++){
						// test de la suite dans les coeurs
						if(cartes_west[i] == 4 || cartes_west[i] == 5 || cartes_west[i] == 6 || cartes_west[i] == 7 || cartes_west[i] == 8){
							suite_coeur_sa++;
						}

						// test de la suite dans les carreau
						if(cartes_west[i] == 12 || cartes_west[i] == 13 || cartes_west[i] ==  14 || cartes_west[i] == 15 || cartes_west[i] == 16){
							suite_carreau_sa++;
						}

						// test de la suite dans les trèfles
						if(cartes_west[i] == 20 || cartes_west[i] == 21 || cartes_west[i] == 22 || cartes_west[i] == 23 || cartes_west[i] == 24){
							suite_trefle_sa++;
						}

						// test de la suite dans les pique
						if(cartes_west[i] == 28 || cartes_west[i] == 29 || cartes_west[i] == 30 || cartes_west[i] == 31 || cartes_west[i] == 32){
							suite_pique_sa++;
						}
					}

					// si l'une des trois variables suites == 5 alors le bot possède une suite;
					if(suite_pique_sa == 5 || suite_trefle_sa == 5 || suite_carreau_sa == 5 || suite_coeur_sa == 5){
						suite_sa = 1;
					}

					if( ordi_west_as >= 2 && suite_sa == 1 ){
						atout = "SA";
						points = -1;
						printf("\nOuest annonce Sans Atout ");
					}
					else{
						/////// Couleur ///////

						// Variables :
						int num_pique   = 0;
						int num_carreau = 0;
						int num_trefle  = 0;
						int num_coeur   = 0;

						// Le bot choisi la couleur en fonction de celle qui est la plus représentée

						// On compte le nombre d'occurance de chaque couleur:
						for(int i = 0; i < 8; i++){
							switch(cartes_west[i]){
								case 0 ... 8 :
									num_pique++;
									break;
								case 9 ... 16 :
									num_carreau++;
									break;
								case 17 ... 24 :
									num_coeur++;
									break;
								case 25 ... 32 :
									num_trefle++;
									break;
							}
						}

						// DEBUG : Affiche le nombre de cartes par couleur :
						//printf("\n%d / %d / %d / %d = %d",num_pique,num_carreau,num_coeur,num_trefle,num_trefle+num_pique+num_carreau+num_coeur);

						int total = 0;
						if(num_pique>=num_carreau && num_pique>=num_coeur && num_pique>=num_trefle){
							total += 1;
						}
						if(num_carreau>=num_pique && num_carreau>=num_coeur && num_carreau>=num_trefle){
							total += 10;
						}
						if(num_coeur>=num_pique && num_coeur>=num_carreau && num_coeur>=num_trefle){
							total += 100;
						}
						if(num_trefle>=num_pique && num_trefle>=num_carreau && num_trefle>=num_coeur){
							total += 1000;
						}

						/*
							Possibilitée selon le total (occurance la + grande): 
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
						int result;
						
						/*
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
						*/
					} 
				}