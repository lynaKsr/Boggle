#include "Boggle.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <algorithm>

Boggle::Boggle(int lignes, int colonnes, const std::string& nomFichier) : grille(lignes, colonnes), dictionnaire()
{
	chargerDictionnaire(nomFichier);
}

Boggle::~Boggle()
{
}

Boggle::Boggle(const Boggle& other) : grille(other.grille), dictionnaire(other.dictionnaire) 
{

}

Boggle& Boggle::operator=(const Boggle& other)
{
    if (this != &other)
    {
        grille = other.grille;
        dictionnaire = other.dictionnaire;
    }
    return *this;
}

void Boggle::jouerPartie(const std::vector<char>& lettres)
{
	grille.initGrilleAvecLettres(lettres);
    std::cout << "Grille :" << std::endl;
	grille.afficherGrille();

    afficherTousLesMotsGrille();
	obtenirEtEcrireMotsPossibles(); 
}

void Boggle::chargerDictionnaire(const std::string& nomFichier)
{
	auto debutChargementDico = std::chrono::high_resolution_clock::now();

    dictionnaire.chargerDictionnaire(nomFichier);

    auto finChargementDico = std::chrono::high_resolution_clock::now();
    auto dureeChargementDico = std::chrono::duration_cast<std::chrono::milliseconds>(finChargementDico - debutChargementDico);

    std::cout << "Temps chargement dico : " << dureeChargementDico.count() << " ms" << std::endl; 
}

void Boggle::afficherTousLesMotsGrille()
{
	auto debut = std::chrono::high_resolution_clock::now(); 

	std::vector<std::string> motsDansGrille = grille.obtenirTousLesMots();
	
    auto fin = std::chrono::high_resolution_clock::now();
    auto duree = std::chrono::duration_cast<std::chrono::milliseconds>(fin - debut);

	std::cout << "temps d execution pour chercher tous les mots dans toute la grille : " << duree.count() << " ms " << std::endl; 

    // Afficher les mots existants
    //afficherResultats(motsPossibles);


}

bool Boggle::estMotValide(const std::string& mot)
{
	return dictionnaire.estMotValide(mot);
}

void Boggle::afficherResultats(const std::vector<std::string>& motsTrouves) const
{
	std::cout << "Mots trouves : " << std::endl;
	for (const auto& mot : motsTrouves) {
		std::cout << mot << std::endl; 
	}
}

std::vector<std::string> Boggle::filtrerMots(const std::vector<std::string>& mots)
{
    std::vector<std::string> motsFiltres;
    
    for (const std::string& mot : mots) {
        std::string motEnMinuscule = mot;
        std::transform(motEnMinuscule.begin(), motEnMinuscule.end(), motEnMinuscule.begin(), ::tolower);
        if (dictionnaire.estMotValide(motEnMinuscule) && motEnMinuscule.length() > 2) {
            motsFiltres.push_back(mot);
        }
    }

    // Tri et suppression des doublons 
    std::sort(motsFiltres.begin(), motsFiltres.end());
    motsFiltres.erase(std::unique(motsFiltres.begin(), motsFiltres.end()), motsFiltres.end());

	// afficher le nombre de tous les mots possibles 
	std::cout << "Nombre total de mots possibles : " << motsFiltres.size() << std::endl;
    return motsFiltres;
}

void Boggle::ecrireMotsDansFichier(const std::vector<std::string>& mots, const std::string& nomFichier)
{
    std::ofstream fichier(nomFichier);
    
    if (fichier.is_open()) {
        for (const std::string& mot : mots) {
            fichier << mot << std::endl;
        }
        fichier.close();
    }
}

void Boggle::obtenirEtEcrireMotsPossibles()
{
	std::vector<std::string> tousLesMots = grille.obtenirTousLesMots();

    auto debutFiltrageMots = std::chrono::high_resolution_clock::now();

    std::vector<std::string> motsFiltres = filtrerMots(tousLesMots);

    auto finFiltrageMots = std::chrono::high_resolution_clock::now();
    auto dureeFiltrageMots = std::chrono::duration_cast<std::chrono::milliseconds>(finFiltrageMots - debutFiltrageMots);

    std::cout << "Temps filtrage des mots possibles : " << dureeFiltrageMots.count() << " ms" << std::endl;

    // ecrire les mots filtres dans le fichier "possiblewords.txt"
    ecrireMotsDansFichier(motsFiltres, "possiblewords.txt");
}


