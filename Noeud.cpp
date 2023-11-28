#include "Noeud.h"

Noeud::Noeud() : estMotFin(false)
{
    for (int i = 0; i < 26; ++i) {
        enfants[i] = nullptr;
    }
}


Noeud::~Noeud()
{
    for (int i = 0; i < 26; ++i)
    {
        delete enfants[i]; 
    }
}

Noeud::Noeud(const Noeud& autre) : estMotFin(autre.estMotFin)
{
    for (int i = 0; i < 26; ++i) {
        if (autre.enfants[i] != nullptr) {
            enfants[i] = new Noeud(*(autre.enfants[i]));
        } else {
            enfants[i] = nullptr;
        }
    }
}


Noeud& Noeud::operator=(const Noeud& autre)
{
    if (this != &autre) {
        estMotFin = autre.estMotFin;

        for (int i = 0; i < 26; ++i) {
            delete enfants[i];

            if (autre.enfants[i] != nullptr) {
                enfants[i] = new Noeud(*(autre.enfants[i]));
            } else {
                enfants[i] = nullptr;
            }
        }
    }
    return *this;
}