#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#define TAILLE_MAX 1000

void score_add(int score_gagnant, char * nom_gagnant){

    FILE* score_fichier = NULL;
    char chaine[TAILLE_MAX];

    int score[3] = {0};
    int nbr[3] = {0};
    char nom_0[20] = {0};
    char nom_1[20] = {0};
    char nom_2[20] = {0};

    int temp;
    char nom_temp[20] = {0};
    
    // ouverture du fichier en mode lecture
    score_fichier = fopen("./data/score.txt", "r");
    
    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %d %s %d %d %s %d", &score[0], &nom_0, &nbr[0], &score[1], &nom_1, &nbr[1], &score[2], &nom_2, &nbr[2]);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - lecture\n");
    }

    // si son nom est identique au premier
    if(strcmp(nom_gagnant, nom_0) == 0){
        nbr[0] += 1;
        // S'il bat son score précédent, on actualise
        if(score_gagnant > score[0]){
            score[0] = score_gagnant;

            printf(side_info" Bravo, vous avez amélioré votre score de 1er!\n");
        }
    }
    else{
        // Alors si son nom est identique au 2e
        if(strcmp(nom_gagnant, nom_1) == 0){
            nbr[1] += 1;

            // S'il bat son score précédent, on actualise
            if(score_gagnant > score[1]){
                score[1] = score_gagnant;

                printf(side_info" Vous avez amélioré votre score de 2e!\n");

                // si son nouveau score est plus grand que celui du 1er on actualise les positions
                if(score[1] > score[0]){

                    // on inverse le 1er et le 2e
                    temp = score[0];
                    score[0] = score[1];
                    score[1] = temp;

                    temp = nbr[0];
                    nbr[0] = nbr[1];
                    nbr[1] = temp;

                    strcpy(nom_temp, nom_0);
                    strcpy(nom_0, nom_1);
                    strcpy(nom_1, nom_temp);

                    printf(side_info" Bravo, vous avez dépassé votre ancien score et passez de 2e à 1er!\n");
                }
            }
        }
        else{
            // Alors si son nom est identique au 3e
            if(strcmp(nom_gagnant, nom_2)){
                nbr[2] += 1;

                // s'il bat son score précédent, on actualise
                if(score_gagnant > score[2]){
                    score[2] = score_gagnant;

                    // Si son nouveau score est plus grand que celui du 1er on actualise les positions
                    if(score[2] > score[0]){

                        // on passe le 3e, 1er et le 2e en 3e
                        score[2] = score[1];
                        score[1] = score[0];
                        score[0] = score_gagnant;

                        temp = nbr[2];
                        nbr[2] = nbr[1];
                        nbr[1] = nbr[0];
                        nbr[0] = temp;

                        strcpy(nom_2, nom_1);
                        strcpy(nom_1, nom_0);
                        strcpy(nom_0, nom_gagnant);
                        
                        printf(side_info" Bravo, vous avez dépassé votre ancien score et passez de 3e à 1er!\n");
                    }
                    else{
                        // Si son nouveau score est plus grand que celui du 2e
                        if(score[2] > score[1]){

                            // on inverse les 2
                            temp = score[1];
                            score[1] = score[2];
                            score[2] = temp;

                            temp = nbr[1];
                            nbr[1] = nbr[2];
                            nbr[2] = temp;

                            strcpy(nom_temp, nom_1);
                            strcpy(nom_1, nom_2);
                            strcpy(nom_2, nom_temp);

                            printf(side_info" Bravo, vous avez dépassé votre ancien score et passez 2e!\n");
                        }
                    }
                }
            }
            // Son nom ne correspond a aucun enregistré
            else{
                // Il dépasse le score du premier
                if(score_gagnant > score[0]){
                    score[2] = score[1];
                    score[1] = score[0];
                    score[0] = score_gagnant;

                    nbr[2] = nbr[1];
                    nbr[1] = nbr[0];
                    nbr[0] = 0;

                    strcpy(nom_2, nom_1);
                    strcpy(nom_1, nom_0);
                    strcpy(nom_0, nom_gagnant);

                    printf(side_info" Le score obtenu vous mène à la 1ère place!\n");
                }
                // il depasse le score du deuxieme
                else{
                    if(score_gagnant > score[1]){
                        score[2] = score[1];
                        score[1] = score_gagnant;

                        nbr[2] = nbr[1];
                        nbr[1] = 0;

                        strcpy(nom_2, nom_1);
                        strcpy(nom_1, nom_gagnant);

                        printf(side_info" Le score obtenu vous mène a la 2e place!\n");
                    }
                    // il dépasse le score du 3e
                    else{
                        if(score_gagnant > score[2]){
                            score[2] = score_gagnant;
                            nbr[2] = 0;
                            strcpy(nom_2, nom_gagnant);

                            printf(side_info" Le score obtenu vous mène à la 3e place !\n");
                        }
                        else{
                            printf(side_info" Le score obtenu n'est pas suffisant pour obtenir une place!\n");
                        }
                    }
                }
            }
        }
    }

    score_fichier = fopen("./data/score.txt", "w+");

    if (score_fichier != NULL){
        fprintf(score_fichier, "%d %s %d %d %s %d %d %s %d", score[0], nom_0, nbr[0], score[1], nom_1, nbr[1], score[2], nom_2, nbr[2]);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - réécriture");
    }        
}