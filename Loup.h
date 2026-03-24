#ifndef LOUP_H
#define LOUP_H

#include "Animal.h"

class Loup : public Animal {
public:
    // Utilisation des constructeurs de la classe Animal
    using Animal::Animal;

    // Redéfinition des méthodes de mouvement et d'attaque
    void setAttaque() override; 
    void deplace(int maxX, int maxY) override;
};

#endif