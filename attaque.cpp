#include "attaque.h"
#include <cstdlib>
using namespace std;

Attaque::Attaque(){
    this->type = rand() % 2;
}

Attaque::Attaque(int a){
    this->type = a;
}

int const Attaque::getTypeAttaque(){
    return this->type;
}

bool const Attaque::resoudreAttaque(Attaque &a){
    int J2 = this->type;
    int J1 = a.getTypeAttaque();

    if (J1  == J2){
        return rand() % 1; // generation true, false aleatoirement
    }

    if ((J1 == 0 && J2 == 2) || 
        (J1 == 1 && J2 == 0) || 
        (J1 == 2 && J2 == 1)) {
        return true;
    }
 
    else {
        return false;
    }
}

string const Attaque::getNomAttaque(){
    if (this->type == 0){
        return "Pierre";
    }
    if (this->type == 1){
        return "Feuille";
    }
    if (this->type == 2){
        return "Ciseaux";
    }
}