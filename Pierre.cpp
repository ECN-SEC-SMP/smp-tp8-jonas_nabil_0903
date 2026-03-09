#include "Pierre.h"

// Les pierres attaquent uniquement avec pierre (type 0)
void Pierre::setAttaque(){
  this->typeAttaque = Attaque(0); // Toujours pierre
  this->nom = "Pierre";
}

// Les pierres ne se déplacent pas
void Pierre::deplace(int maxX, int maxY){
  // Ne fait rien, les pierres restent immobiles
}
