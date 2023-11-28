#pragma once
struct Noeud
{
    Noeud* enfants[26];
    bool estMotFin;
    Noeud();
    ~Noeud();

    Noeud(const Noeud& autre);
    Noeud& operator=(const Noeud& autre);
};

