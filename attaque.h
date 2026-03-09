using namespace std;

#include <string>

class Attaque {

private:

    int type; // 0 :pierre, 1: Feuille, 2:Ciseaux

public:

    Attaque();
    Attaque(int a);
    int const getTypeAttaque();
    bool const resoudreAttaque(Attaque &a);
    string const getNomAttaque();
    
};