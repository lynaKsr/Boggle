// Dictionnaire.cpp

#include "Dictionnaire.h"
#include <fstream>
#include <iostream>
#include <cctype>

Dictionnaire::Dictionnaire() 
{
    racine = new Noeud(); 
}

Dictionnaire::~Dictionnaire()
{
    if (racine != nullptr)
    {
        delete racine;
        racine = nullptr;
    }
}

Dictionnaire::Dictionnaire(const Dictionnaire& autre) : racine(new Noeud(*(autre.racine))) {
}

Dictionnaire& Dictionnaire::operator=(const Dictionnaire& autre) {
    if (this != &autre) {
        delete racine;
        racine = new Noeud(*(autre.racine));

    }
    return *this;
}

void Dictionnaire::ajouterMotDansArbre(const std::string& mot)
{
    Noeud* courant = racine;

    for (char lettre : mot)
    {
        int index = lettre - 'a';

        if (!courant->enfants[index])
        {
            courant->enfants[index] = new Noeud();
        }

        courant = courant->enfants[index];
    }

    courant->estMotFin = true;
}

bool Dictionnaire::estMotDansArbre(const std::string& mot) const
{
    Noeud* courant = racine;

    for (char lettre : mot)
    {
        int index = lettre - 'a';

        if (!courant)
        {
            return false;
        }

        if (index < 0 || index >= 26 || !courant->enfants[index])
        {
            return false;
        }

        courant = courant->enfants[index];
    }

    if (courant && courant->estMotFin)
    { 
        return true;
    }
    return false;
}


void Dictionnaire::chargerDictionnaire(const std::string& nomFichier)
{
    std::ifstream dicoFile(nomFichier);

    if (!dicoFile.is_open()) {
        return;
    }

    std::string line;

    int nombreTotalDeMots = 0;
    int nombreMotsCharges = 0;

    while (std::getline(dicoFile, line))
    {
        ++nombreTotalDeMots;

        // Nettoyer le mot en minuscules et enlever les caracteres non alphabetiques
        std::string motNettoye;
        for (char c : line) {
            if (std::isalpha(c)) {
                motNettoye += std::tolower(c);
            }
        }

        if (!motNettoye.empty()) {
            ajouterMotDansArbre(motNettoye);
            ++nombreMotsCharges;
        }
    }

    // affichage des statistiques sur le dictionnaire
    std::cout << "Nombre total de mots dans le dictionnaire : " << nombreTotalDeMots << std::endl;
    std::cout << "Nombre de mots charges dans l arbre : " << nombreMotsCharges << std::endl;
}


bool Dictionnaire::estMotValide(const std::string& mot) const
{
    return estMotDansArbre(mot);
}

