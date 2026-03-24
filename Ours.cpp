#include "Ours.h"
#include <cstdlib>

// Les ours attaquent uniquement avec feuille (1)
void Ours::setAttaque(){
  this->typeAttaque = Attaque(1); // Toujours feuille
  this->nom = "Ours";
}

// Les ours se déplacent selon 8 directions spécifiques
void Ours::deplace(int maxX, int maxY){
  int directions[8][2] = {{2,1}, {1,2}, {-1,2}, {-2,1}, {-2,-1}, {-1,-2}, {1,-2}, {2,-1}};
  int choix = rand() % 8;

  this->x += directions[choix][0];
  this->y += directions[choix][1];

  // Gestion du plateau torique (bords qui se rejoignent)
  while (this->x < 0) this->x += maxX;
  while (this->x >= maxX) this->x -= maxX;
  while (this->y < 0) this->y += maxY;
  while (this->y >= maxY) this->y -= maxY;
}
