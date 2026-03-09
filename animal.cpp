#include "animal.h"
using namespace std;
#include <stdlib.h>

Animal::Animal(int maxX, int maxY){
    x = rand() % maxX;
    y = rand() % maxY;
}

Animal::Animal(int maxX, int maxY, int a, int b){
    x = a % maxX;
    y = b % maxY;
}

string const Animal::getNom(){
    return nom;
}

int const Animal::getX(){
    return x;
}

int const Animal::getY(){
    return y;
}

bool const Animal::getVivant(){
    return vivant;
}

Attaque const Animal::getAttaque(){
    return typeAttaque;
}

