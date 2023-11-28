CC = g++
CFLAGS = -c -Wall
LDFLAGS =

# Liste de tous les fichiers objets
OBJS = Boggle.o Grille.o Dictionnaire.o Noeud.o ArbresEtJeuxDeLettres.o

# Nom du fichier executable
OUT = boggle

all: $(OBJS)
	$(CC) $(OBJS) -o $(OUT) $(LDFLAGS)

Boggle.o: Boggle.cpp Boggle.h Grille.h Dictionnaire.h
	$(CC) $(CFLAGS) Boggle.cpp 

Grille.o: Grille.cpp Grille.h
	$(CC) $(CFLAGS) Grille.cpp 

Dictionnaire.o: Dictionnaire.cpp Dictionnaire.h Noeud.h
	$(CC) $(CFLAGS) Dictionnaire.cpp 

Noeud.o: Noeud.cpp Noeud.h
	$(CC) $(CFLAGS) Noeud.cpp

ArbresEtJeuxDeLettres.o : ArbresEtJeuxDeLettres.cpp Boggle.h
	$(CC) $(CFLAGS) ArbresEtJeuxDeLettres.cpp 

clean:
	rm -f $(OBJS) $(OUT)
