#include "Grille.h"
#include <ctime>
#include <iostream>
#include <algorithm>


Grille::Grille(int lignes, int colonnes) : nbLignes(lignes), nbColonnes(colonnes) {

	tab = new char* [nbLignes]; 

	for (int i = 0; i < nbLignes; i++) {
		tab[i] = new char[nbColonnes];
	}

}

Grille::~Grille() {
	for (int i = 0; i < nbLignes; i++) {
		delete[] tab[i];
	}
	delete[] tab; 
}

// Constructeur de copie
Grille::Grille(const Grille& other) : nbLignes(other.nbLignes), nbColonnes(other.nbColonnes)
{
    tab = new char*[nbLignes];
    for (int i = 0; i < nbLignes; ++i)
    {
        tab[i] = new char[nbColonnes];
        std::copy(other.tab[i], other.tab[i] + nbColonnes, tab[i]);
    }
}

Grille& Grille::operator=(const Grille& other)
{
    if (this != &other)
    {
        for (int i = 0; i < nbLignes; ++i)
        {
            delete[] tab[i];
        }
        delete[] tab;

        nbLignes = other.nbLignes;
        nbColonnes = other.nbColonnes;

        tab = new char*[nbLignes];
        for (int i = 0; i < nbLignes; ++i)
        {
            tab[i] = new char[nbColonnes];
            std::copy(other.tab[i], other.tab[i] + nbColonnes, tab[i]);
        }
    }
    return *this;
}

int Grille::getNbLignes()
{
	return nbLignes;
}

int Grille::getNbColonnes()
{
	return nbColonnes;
}

void Grille::initGrille() {
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	for (int i = 0; i < nbLignes; ++i) {
		for (int j = 0; j < nbColonnes; ++j) {
			tab[i][j] = (char)('A' + std::rand() % 26); 
		}
	}
}

void Grille::initGrilleAvecLettres(const std::vector<char>& lettres) {
    if (static_cast<int>(lettres.size()) != nbLignes * nbColonnes) {
        std::cerr << "Erreur : Nombre incorrect de lettres pour initialiser la grille." << std::endl;
        return;
    }

    int index = 0;
    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            tab[i][j] = lettres[index++];
        }
    }
}

void Grille::afficherGrille() {
	for (int i = 0; i < nbLignes; ++i) {
		for (int j = 0; j < nbColonnes; ++j) {
			std::cout << tab[i][j] ;
		}
		std::cout << std::endl;
	}
}

char Grille::getLetter(int ligne, int colonne) {
	if (ligne >= 0 && ligne < nbLignes && colonne >= 0 && colonne < nbColonnes) {
		return tab[ligne][colonne];
	}
	return ' '; 
}

void Grille::rechercherMots(int ligne, int colonne, std::string& motCourant, std::vector<std::vector<bool>>& lettresVues, std::vector<std::string>& motsTrouves) {
    if (ligne < 0 || ligne >= nbLignes || colonne < 0 || colonne >= nbColonnes || lettresVues[ligne][colonne]) {
        return;
    }

    lettresVues[ligne][colonne] = true;
    motCourant += getLetter(ligne, colonne);

    // Ajouter le motCourant a la liste si la longueur est superieure a 2
    if (motCourant.length() >= 2) {
        motsTrouves.push_back(motCourant);
    }

    // Deplacements possibles autour de la lettre actuelle
    int deplacements[3] = { -1, 0, 1 };

    for (int i : deplacements) {
        for (int j : deplacements) {
            if (i == 0 && j == 0) {
                continue;
            }

            int newLigne = ligne + i;
            int newColonne = colonne + j;

            rechercherMots(newLigne, newColonne, motCourant, lettresVues, motsTrouves);
        }
    }
    // Reinitialisation pour les explorations suivantes
    motCourant.pop_back();
    lettresVues[ligne][colonne] = false;
}

std::vector<std::string> Grille::obtenirTousLesMots()
{
    std::vector<std::string> tousLesMots;

    for (int i = 0; i < nbLignes; ++i) {
        for (int j = 0; j < nbColonnes; ++j) {
            std::string motCourant = "";
            std::vector<std::vector<bool>> lettresVues(nbLignes, std::vector<bool>(nbColonnes, false));
            rechercherMots(i, j, motCourant, lettresVues, tousLesMots);
        }
    }

    return tousLesMots;
}
