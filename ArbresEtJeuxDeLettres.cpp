// Main.cpp

#include <iostream>
#include <fstream>
#include <cstring>
#include <chrono> 
#include "Boggle.h"

int main(int argc, char* argv[]) {
    if (argc != 17) {
        std::cerr << "Erreur : Vous devez fournir exactement 16 lettres." << std::endl;
        return 1;
    }

    // Recuperer les lettres de la ligne de commande
    std::vector<char> lettres;
    for (int i = 1; i < argc; ++i) {
        if (strlen(argv[i]) != 1) {
            std::cerr << "Erreur : Chaque argument doit etre un seul caractere." << std::endl;
            return 1;
        }

        lettres.push_back(argv[i][0]);
    }

    Boggle boggle(4, 4,"dico.txt");
    
    boggle.jouerPartie(lettres);
    return 0;

}
