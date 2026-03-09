#include "animal.h"
using namespace std;
#include <stdlib.h>

Animal::Animal(int maxX, int maxY){
    this->x = rand() % maxX;
    this->y = rand() % maxY;
}

Animal::Animal(int maxX, int maxY, int a, int b){
    this->x = a % maxX;
    this->y = b % maxY;
}

string const Animal::getNom(){
    return this->nom;
}

int const Animal::getX(){
    return this->x;
}

int const Animal::getY(){
    return this->y;
}

bool const Animal::getVivant(){
    return this->vivant;
}

Attaque const Animal::getAttaque(){
    return this->typeAttaque;
}

