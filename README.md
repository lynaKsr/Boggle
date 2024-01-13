# Projet Boggle
Ce projet implémente un assistant du jeu Boggle en C++, avec une conception orientée objet. Le jeu Boggle consiste à former des mots à partir d'une grille de lettres disposées aléatoirement.

# Fonctionnalités
- Génération d'une grille de jeu avec des lettres spécifiées en ligne de commande.
- Recherche de mots dans la grille en respectant la contrainte d'adjacence.
- Utilisation d'un dictionnaire pour valider l'existence des mots en français.
- Structure arborescente (arbre lexicographique) pour stocker et rechercher efficacement les mots du dictionnaire.
- Mesure des temps d'exécution pour le chargement du dictionnaire, la recherche des mots, etc.
- Filtre et tri des mots trouvés avant affichage et enregistrement dans un fichier.
  
# Structure du Projet
- Boggle.cpp/Boggle.h : La classe principale du jeu Boggle, gérant la grille, le dictionnaire, et les opérations principales du jeu.
- Grille.cpp/Grille.h : La classe représentant la grille de jeu et les opérations associées.
- Dictionnaire.cpp/Dictionnaire.h : La classe utilisant une structure arborescente pour stocker et rechercher les mots du dictionnaire.
- Noeud.cpp/Noeud.h : La structure de nœud utilisée pour construire l'arbre lexicographique.
- ArbresEtJeuxDeLettres.cpp : Le fichier source contenant la fonction main et les tests pour le jeu.
  
# Utilisation
Compiler le projet en utilisant make.

Le projet a été développé dans le cadre d'un TP universitaire (Master Informatique - Conception Orientée Objets, Université de Poitiers, Année 2023-2024).
