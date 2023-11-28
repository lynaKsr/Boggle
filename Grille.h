#pragma once

#include <vector>
#include "Dictionnaire.h"

class Grille
{
private:
	char** tab; 
	int nbLignes; 
	int nbColonnes;

public: 
	Grille(int lignes = 4, int colonnes = 4); 
	~Grille(); 

	Grille(const Grille& other); // Constructeur de copie
    Grille& operator=(const Grille& other); 
	
	int getNbLignes(); 
	int getNbColonnes(); 
	
	// initialisation de la grille avec des lettres aleatoires 
	void initGrille();

	// initialisation de la grille avec des lettres fourni en param
	void initGrilleAvecLettres(const std::vector<char>& lettres); 

	// obtention d'une lettre A partir d'une position dans la grille 
	char getLetter(int ligne, int colonne); 

	// affichage de la grille 
	void afficherGrille();

	// tous les mots presents dans la grille
    std::vector<std::string> obtenirTousLesMots();

	// Fonction recursive pour rechercher tous les mots possibles a partir d une position donnee dans la grille 
	void rechercherMots(int ligne, int colonne, std::string& motCourant, std::vector<std::vector<bool>>& lettresVues, std::vector<std::string>& motsTrouves);
	

};

