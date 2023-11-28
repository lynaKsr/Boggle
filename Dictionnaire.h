// Dictionnaire.h

#pragma once
#include <map>
#include <string>
#include "Noeud.h"

class Dictionnaire
{
private:
    Noeud* racine;

public:
    Dictionnaire();
    ~Dictionnaire();

    Dictionnaire(const Dictionnaire& other); 
    Dictionnaire& operator=(const Dictionnaire& other); 

    void chargerDictionnaire(const std::string& nomFichier);
    bool estMotValide(const std::string& mot) const;
    void ajouterMotDansArbre(const std::string& mot);
    bool estMotDansArbre(const std::string& mot) const;
   
};
