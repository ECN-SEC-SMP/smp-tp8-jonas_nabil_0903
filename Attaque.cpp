#include "Attaque.h"
#include <cstdlib>

// Constructeur avec attaque aléatoire
Attaque::Attaque() {
    this->type = rand() % 3; // 0, 1 ou 2
}

// Constructeur avec attaque spécifique
Attaque::Attaque(int a) {
    this->type = a;
}

// Getter du type d'attaque
int Attaque::getTypeAttaque() const {
    return this->type;
}

// Renvoie le nom de l'attaque
std::string Attaque::getNomAttaque() const {
    switch(this->type) {
        case 0: return "Pierre";
        case 1: return "Feuille";
        case 2: return "Ciseaux";
        default: return "Inconnu";
    }
}

// Résout l'attaque : renvoie vrai si this bat l'attaque a
bool Attaque::resoudreAttaque(Attaque &a) const {
    int autreType = a.getTypeAttaque();

    // Si même type, on renvoie un résultat aléatoire
    if (this->type == autreType) {
        return (rand() % 2 == 0);
    }

    // Pierre (0) bat Ciseaux (2)
    if (this->type == 0 && autreType == 2) return true;

    // Feuille (1) bat Pierre (0)
    if (this->type == 1 && autreType == 0) return true;

    // Ciseaux (2) bat Feuille (1)
    if (this->type == 2 && autreType == 1) return true;

    // Sinon on a perdu
    return false;
}
