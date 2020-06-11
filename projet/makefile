CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=belote

# Ajouter vos fonctions dans cette ligne :
SRC= atout_add.c bot_plis.c plis.c dictionnaire_non_atout.c bot_surenchere.c score_add.c meilleurs_score.c bot_enchere.c enchere.c nouvelle_partie.c menu.c tableau_tri.c ramasser.c distribuer.c melanger.c dictionnaire_atout.c dictionnaire.c main.c

OBJ= $(SRC: .c=.o)

all: $(EXEC)

belote: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o : header/fonctions.h header/syntax.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)