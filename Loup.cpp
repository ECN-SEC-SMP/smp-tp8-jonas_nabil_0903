#include <iostream>
#include "Loup.h"
#include <cstdlib>

// Les loups attaquent avec pierre, feuille ou ciseaux au hasard
void Loup::setAttaque(){
  this->typeAttaque = Attaque(); // Attaque aléatoire
  this->nom = "Loup";
}

// Les loups se déplacent aléatoirement sur n'importe quelle cellule du plateau
void Loup::deplace(int maxX, int maxY){
  this->x = rand() % maxX;
  this->y = rand() % maxY;
}