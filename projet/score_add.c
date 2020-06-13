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
        printf(side_error" Ouverture du fichier impossible - lecture");
    }

    // si son nom est identique au premier
    if(strcmp(nom_gagnant, nom_0) == 0){
        nbr[0] += 1;
        // S'il bat son score précédent, on actualise
        if(score_gagnant > score[0]){
            score[0] = score_gagnant;
        }
    }
    else{
        // Alors si son nom est identique au 2e
        if(strcmp(nom_gagnant, nom_1) == 0){
            nbr[1] += 1;

            // S'il bat son score précédent, on actualise
            if(score_gagnant > score[1]){
                score[1] = score_gagnant;

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
                        
                    }
                }
            }
        }
    }

    

    /*
    // Si le "nouveau" score dépasse le premier
    if(score_gagnant >= score[0]){
        score[2] = score[1];
        score[1] = score[0];
        score[0] = score_gagnant;

        strcpy(nom_3, nom_2);
        strcpy(nom_2, nom_1);
        strcpy(nom_1, nom_gagnant);
    }
    // Si le "nouveau" score dépasse le deuxième
    else if(score_gagnant >= score[1]){
        score[2] = score[1];
        score[1] = score_gagnant;

        strcpy(nom_3, nom_2);
        strcpy(nom_2, nom_gagnant);
    }
    // Si le "nouveau" score dépasse le troisième
    else if(score_gagnant >= score[2]){
        score[2] = score_gagnant;

        strcpy(nom_3, nom_gagnant);
    }*/

    score_fichier = fopen("./data/score.txt", "w+");

    if (score_fichier != NULL){
        fprintf(score_fichier, "%d %s %d %s %d %s", score[0], nom_0, score[1], nom_1, score[2], nom_2);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - réécriture");
    }        
}