switch(encherisseur){
		//////////////////////// Joueur ////////////////////////
		case 1: 
			printf("%s examine son jeu!\n\n",nom_joueur);

			if(tour_enrichisseur == 1){
				printf("Souhaitez-vous passer ou annoncer?\n1 | Annoncer\n2 | Passer\n");
				scanf("%d",&choix); // A ACTIVER
				//choix = 1; // A DESACTIVER
			}
			else{
				printf("Souhaitez-vous enchérir ou passer?\n1 | Enchérir\n2 | Passer\n");
				scanf("%d",&choix);
			}

			if(choix == 1 && tour_enrichisseur == 1){
				// l'encherisseur choisit la couleur de l'atout
				printf("Choisissez la couleur de l'atout:\n");
				printf("1 | Couleur Unique\n");
				printf("2 | Tout Atout (TA)\n");
				printf("3 | Sans Atout (SA)\n");

				scanf("%d",&type_enchere); // A ACTIVER
				//type_enchere = 1; // A DESACTIVER

				switch(type_enchere){
			    	case 1: //une seule couleur est choisit comme Atout
						do{
							printf("\nVeuillez choisir une des couleurs en marquant le nombre qui lui est attribué\n");
							printf("1 | Trèfle\n2 | Pique\n3 | Carreau\n4 | Coeur\n");
							
							scanf("%d",&choix_couleur); // A ACTIVER
							//choix_couleur = 1; // A DESACTIVER

			            }while(choix_couleur < 1 || choix_couleur > 4);

			            atout = "Couleur";
			           	
			            switch(choix_couleur){
			            	case 1:
			            		couleur = "Trèfle";
			            		break;
			            	case 2:
			            		couleur = "Pique";
			            		break;
			            	case 3:
			            		couleur = "Carreau";
			            		break;
			            	case 4:
			            		couleur = "Coeur";
			            		break;
			            	default:
			            		couleur = "couleur_error_switch";
			            		break;
			            }
			            printf("\n%s annonce une couleur de %s!",nom_joueur,couleur);
			            enchere(encherisseur+1);
			            break;

			        case 2: //toute les couleurs sont atout
			            atout = "TA";
			            printf("\n%s annonce un Tout Atout!",nom_joueur);
			            enchere(encherisseur+1);
			            break;

			        case 3: //toute les couleurs sont sans atout
			            atout = "SA";
			            printf("\n%s annonce un Sans Atout!",nom_joueur);
			            enchere(encherisseur+1);
			            break;
			        default :
			            printf("Erreur dans les enchères");
			    }
			}
			if(choix == 2){
				printf("\n%s passe!",nom_joueur);
				passer++;
				if(passer == 3){
					printf("\nLes enchères sont terminées, la partie démarre!\n"); // On lance la partie si 3 personnes consécutives décident de passer
					plis(1);
				} 
				else{
					enchere(encherisseur+1); // On passe au joueur suivant
				}
			}
			break;

		///////////////////// IA des ordis /////////////////////

		/*	A FAIRE
			Le bot doit prendre en compte l'annonce du joueur/bot précédent et de son coéquipier:
			> Peut-il faire mieux? Oui: annonce mieux; Non: passe
			> Qu'a fait le partenaire? Peut-il aider?
		*/

		/*	FAIT
			Le bot choisit Tout Atout (TA) si:
			> il possède 3 valet 
			> OU 1 ou 2 suite de cartes d'atout (Valet, 9, As)
				> de la même couleur donc
			> A priviliéger si le bot annonce en premier
		*/

		/*	FAIT
			Le bot choisit Sans Atout (SA) si:
			> il possède 3 ou 2 As ET possède une suite (As, 10, Roi, Dame, Valet)
			> A priviligier si le bot annonce en premier
		*/
		
		/*	A FAIRE
			Par défaut:
			> Le bot choisi une couleur unique: celle qu'il possède le plus
			> Calcul des points : annonce 20pts par plis remportable + 
		*/

		//////////////////////// Ouest ////////////////////////
		case 2: 
			printf("Ouest examine son jeu!\n");

			if(tour_enrichisseur == 1){

				int	ordi_west_as    = 0;
				int ordi_west_valet = 0;

				//////////////////////// Test si TA possible ////////////////////////
				/*
					Les Valets ont pour valeur : 5, 13, 21, 29
				*/
				/*
					Les suites ont pour valeur : 3, 5, 8 // 11, 13, 16 // 19, 21, 24 // 27, 29, 32
				*/

				// On compte les valets
				for(int i = 0; i < 8; i++){
					if(cartes_west[i] == 5 || cartes_west[i] == 13 || cartes_west[i] == 21 || cartes_west[i] == 29){
						ordi_west_valet++;
					}
				}
				// DEBUG : printf("\nOuest Valets : %d",ordi_west_valet);

				// On vérifie que Ouest possède une suite si il a moins de 3 valets
				

				if( ordi_west_valet == 3 || suite_ta == 1 ){
					atout = "TA";
					printf("\nOuest annonce Tout Atout");
				}
				else{
					//////////////////////// Test si SA possible ////////////////////////
					/*
						Les As ont pour valeur 8, 16, 24, 32
					*/
					/*
						Les suites 10,V,D,R,As ont pour valeur : 4,5,6,7,8 // 12,13,14,15,16 // 20,21,22,23,24 // 28,29,30,31,32
					*/

					// On compte les As
					for(int i = 0; i < 8; i++){
						if(cartes_west[i] == 8 || cartes_west[i] == 16 || cartes_west[i] == 24 || cartes_west[i] == 32){
							ordi_west_as++;
						}
					}
					// DEBUG : printf("\nOuest As     : %d",ordi_west_as);

					// On vérifie que l'ordi possède la suite (dans tout les cas == elle est nécessaire)
					int suite_sa = 0;
					int suite_coeur_sa   = 0;
					int suite_carreau_sa = 0;
					int suite_trefle_sa  = 0;
					int suite_pique_sa   = 0;

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

					// si l'une des trois variables suites == 5 alors Ouest possède une suite;
					if(suite_pique_sa == 5 || suite_trefle_sa == 5 || suite_carreau_sa == 5 || suite_coeur_sa == 5){
						suite_sa = 1;
						// DEBUG : printf("\nsuite : %d",suite);
					}

					if( ordi_west_as >= 2 && suite_sa == 1 ){
						atout = "SA";
						printf("\nOuest annonce Sans Atout");
					}
					else{
						atout = "Couleur";
					} 
				}
			}

			// compte chaque cartes par couleur
			for(int i=0; i < 32; i++){
				printf("%d",i);
			}

			// regarde le nombre de cartes hautes dans la couleur la plus représentée et annonce les pts

			break;

		default:
			printf("Erreur dans switch(encherisseur)");
			break;
	}