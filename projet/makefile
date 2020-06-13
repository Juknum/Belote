
#	BELOTE COINCHEE EN C : Groupe F
#	- Julien Constant
#	- Ewen Bourdon
#	- Théo Silva
#
#	makefile : Sert à la compilation du projet en utilisant MingW
# 		- Pour ajouter une fonction : ajouter le nom du fichier et son extension dans SRC= ... main.c
# 		- Pour ajouter un header : ajouter le chemin du fichier et son extension dans main.o : header/fonctions.h ...
# 			*
#			  Peu importe l'odre des fichiers
#			*
#		- Tout ce qu'il se passe après .PHONY sert à la suppresion des fichier .o (créés pendant la compilation)

CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=belote

# Ajouter vos fonctions dans cette ligne :
SRC= tableau_tri_slaves.c tableau_tri_slave.c bot_plis.c afficher_carte.c symbole.c atout_add.c plis.c dictionnaire_non_atout.c bot_surenchere.c score_add.c meilleurs_score.c bot_enchere.c enchere.c nouvelle_partie.c menu.c tableau_tri.c ramasser.c distribuer.c melanger.c dictionnaire_atout.c dictionnaire.c main.c

OBJ= $(SRC: .c=.o)

all: $(EXEC)

belote: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

# Ajouter vos headers dans cette ligne :
main.o : header/fonctions.h header/syntax.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)