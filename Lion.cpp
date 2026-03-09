#include "Lion.h"
#include <cstdlib>

// Les lions attaquent avec feuille (1) ou ciseaux (2) au hasard
void Lion::setAttaque(){
  int typeAtq = 1 + (rand() % 2); // 1 ou 2
  this->typeAttaque = Attaque(typeAtq);
  this->nom = "Lion";
}

// Les lions se déplacent en diagonale: (1,1), (1,-1), (-1,-1) ou (-1,1)
void Lion::deplace(int maxX, int maxY){
  int directions[4][2] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}};
  int choix = rand() % 4;

  this->x += directions[choix][0];
  this->y += directions[choix][1];

  // Gestion du plateau torique (bords qui se rejoignent)
  if (this->x < 0) this->x = maxX - 1;
  if (this->x >= maxX) this->x = 0;
  if (this->y < 0) this->y = maxY - 1;
  if (this->y >= maxY) this->y = 0;
}
