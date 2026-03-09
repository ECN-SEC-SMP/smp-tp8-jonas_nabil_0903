#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>

class Attaque {
private:
    int type; // 0 : pierre, 1 : feuille, 2 : ciseaux

public:
    Attaque();           // Crée une attaque random
    Attaque(int a);      // Crée une attaque spécifique
    
    int getTypeAttaque() const;
    bool resoudreAttaque(Attaque &a) const;
    std::string getNomAttaque() const;
};

#endif