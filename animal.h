#ifndef ANIMAL.H
#define ANIMAL.H
#include "attaque.h"

using namespace std;
#include <string>;

class Animal {

protected:

    string nom;
    int x;
    int y;
    bool vivant;
    Attaque typeAttaque;

public: 

    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);

    string const getNom() ;

    int const getX();
    int const getY();

    bool const getVivant();
    Attaque const getAttaque();
    void setVivant(bool v);
    bool attaque(Animal &a);
    virtual void setAttaque(Attaque &a);
    virtual void deplace(int maxX, int maxY);

};

#endif