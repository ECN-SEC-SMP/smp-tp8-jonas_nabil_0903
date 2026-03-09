#include <iostream>
#include "Animal.h"
#include <cstdlib>

Animal::Animal(int maxX, int maxY){
  this->x = rand() % maxX; // on veut que ce soit random mais inférieur a maxX ou maxY
  this->y = rand() % maxY;
  this->vivant = true;
}

Animal::Animal(int maxX, int maxY, int a, int b){
  this->x = a;
  this->y = b;
  this->vivant = true;
}

// Getters & Setters
std::string Animal::getNom() const{
  return this->nom;
}
int Animal::getX() const{
  return this->x;
}
int Animal::getY() const{
  return this->y;
}
bool Animal::getVivant() const{
  return this->vivant;
}

Attaque Animal::getAttaque() const{
  return this->typeAttaque;
}

void Animal::setVivant(bool v){
  this->vivant = v;
}

// Méthode pour attaquer un autre animal
// Renvoie true si this gagne, false sinon
bool Animal::attaque(Animal &a){
  // Les deux animaux définissent leur attaque
  this->setAttaque();
  a.setAttaque();

  // Résolution du combat
  bool result = this->typeAttaque.resoudreAttaque(a.typeAttaque);

  // Le perdant meurt
  if (result) {
    a.setVivant(false);
  } else {
    this->setVivant(false);
  }

  return result;
}