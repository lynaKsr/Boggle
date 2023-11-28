#pragma once
#include "Grille.h"
 

class Boggle
{
private:
	Grille grille; 
	Dictionnaire dictionnaire;  

public: 
	Boggle(int lignes = 4, int colonnes = 4, const std::string& nomFichier="dico.txt");
	~Boggle(); 

	Boggle(const Boggle& other); 
	Boggle& operator=(const Boggle& other);

	std::vector<std::string> filtrerMots(const std::vector<std::string>& mots);
	void ecrireMotsDansFichier(const std::vector<std::string>& mots, const std::string& nomFichier);
	void obtenirEtEcrireMotsPossibles();

	// Fonction principale elle initialise la grille avec les lettres specifiees, affiche la grille,
	// trouve tous les mots possibles et mesure le temps d execution 
	void jouerPartie(const std::vector<char>&lettres); 

	// fonction qui charge le dictionnaire a partir d un fichier specifie et mesure le temps d execution 
	void chargerDictionnaire(const std::string& nomFichier); 

	// fonction qui verifie si un mot est valide en le comparant avec les mots du dictionnaire 
	bool estMotValide(const std::string& mot);

	// fonction qui affiche les resultats = les mots trouves dans la console 
	void afficherResultats(const std::vector<std::string>& motsTrouves) const; 

	// fonction qui affiche le temps d execution pour trouver tous les mots possibles dans la grille, mesure le temps d execution,
	// filtre les mots valides, affiche les resultats et ecris les mots valides dans un fichier 
	void afficherTousLesMotsGrille();


};

