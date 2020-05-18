CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=belote

SRC= meilleurs_score.c bot_enchere.c enchere.c nouvelle_partie.c menu.c tableau_tri.c ramasser.c distribuer.c melanger.c dictionnaire_atout.c dictionnaire.c main.c
OBJ= $(SRC: .c=.o)

all: $(EXEC)

belote: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o : header/fonctions.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)