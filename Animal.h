#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include "Attaque.h"

class Animal {
protected:
    std::string nom;
    int x; // abscisse
    int y; // ordonnée
    bool vivant;
    Attaque typeAttaque;

public:
    // Constructeurs
    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);
    
    // Destructeur virtuel (important pour l'héritage !)
    virtual ~Animal() {}

    // Getters & Setters
    std::string getNom() const;
    int getX() const;
    int getY() const;
    bool getVivant() const;
    Attaque getAttaque() const;
    void setVivant(bool v);

    // Méthodes métier
    bool attaque(Animal &a);
    
    // Méthodes virtuelles pures (à implémenter dans les classes filles)
    virtual void setAttaque() = 0;
    virtual void deplace(int maxX, int maxY) = 0;
};

#endif