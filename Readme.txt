PROJET KESSOURI LYNA 

INTRODUCTION :
TP5 projet Boggle 

ARCHITECTURE DU PROJET :

- Boggle.cpp, Boggle.h : contiennent la classe principale Boggle qui coordonne les actions du jeu 
- Grille.cpp, Grille.h : definissent la classe Grille responsable de la génération et de la manipulation de la grille de lettres 
- Dictionnaire.cpp, Dictionnaire.h : définissent la classe Dictionnaire utilisant un arbre lexicographique (Noeud.cpp, Noeud.h) pour stocker les mots du dictionnaire 
- ArbresEtJeuxDeLettres.cpp : Fichier principal contenant la fonction main 

UTILISATION : 
	-> pour compiler le programme, exécutez la commande suivante : 
		make 
	
	-> pour exécuter le programme : 
		./boggle suivi de 16 lettres 
		exemple : ./boggle a h u i f g r v u i a e d z a g 

PERFORMANCES :

le programme mesure le temps d'execution pour le chargelent du dictionnaire, la recherche de tous les mots (toutes les combinaisons possibles) dans la grille supérieur à 2 lettres 
et aussi tous les mots possibles qui existe dans le dictionnaire (superieur à 3 lettres) 


