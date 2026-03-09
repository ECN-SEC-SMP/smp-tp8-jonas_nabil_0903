#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Animal.h"
#include "Loup.h"
#include "Pierre.h"
#include "Lion.h"
#include "Ours.h"

using namespace std;

const int MAX_X = 10;
const int MAX_Y = 10;

// Fonction pour afficher le plateau
void afficherPlateau(vector<Animal*>& animaux) {
    char plateau[MAX_X][MAX_Y];

    // Initialiser le plateau avec des points
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_Y; j++) {
            plateau[i][j] = '.';
        }
    }

    // Placer les animaux vivants sur le plateau
    for (Animal* animal : animaux) {
        if (animal->getVivant()) {
            int x = animal->getX();
            int y = animal->getY();
            string nom = animal->getNom();

            if (nom == "Loup") plateau[x][y] = 'W';
            else if (nom == "Pierre") plateau[x][y] = 'P';
            else if (nom == "Lion") plateau[x][y] = 'L';
            else if (nom == "Ours") plateau[x][y] = 'O';
        }
    }

    // Afficher le plateau
    cout << "\n  ";
    for (int j = 0; j < MAX_Y; j++) {
        cout << j << " ";
    }
    cout << "\n";

    for (int i = 0; i < MAX_X; i++) {
        cout << i << " ";
        for (int j = 0; j < MAX_Y; j++) {
            cout << plateau[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Fonction pour compter les animaux vivants
int compterVivants(vector<Animal*>& animaux) {
    int count = 0;
    for (Animal* animal : animaux) {
        if (animal->getVivant()) {
            count++;
        }
    }
    return count;
}

// Fonction pour résoudre les conflits sur une cellule donnée
void resoudreConflits(vector<Animal*>& animaux) {
    // Pour chaque cellule du plateau
    for (int x = 0; x < MAX_X; x++) {
        for (int y = 0; y < MAX_Y; y++) {
            // Trouver tous les animaux vivants sur cette cellule
            vector<Animal*> animauxSurCase;
            for (Animal* animal : animaux) {
                if (animal->getVivant() && animal->getX() == x && animal->getY() == y) {
                    animauxSurCase.push_back(animal);
                }
            }

            // S'il y a plusieurs animaux sur la même case
            while (animauxSurCase.size() > 1) {
                // Sélectionner deux animaux au hasard
                int idx1 = rand() % animauxSurCase.size();
                Animal* a1 = animauxSurCase[idx1];
                animauxSurCase.erase(animauxSurCase.begin() + idx1);

                int idx2 = rand() % animauxSurCase.size();
                Animal* a2 = animauxSurCase[idx2];

                // Combat!
                a1->attaque(*a2);

                // Retirer le perdant de la liste
                if (!a2->getVivant()) {
                    animauxSurCase.erase(animauxSurCase.begin() + idx2);
                } else {
                    animauxSurCase.erase(animauxSurCase.begin() + idx1);
                }
            }
        }
    }
}

int main() {
    // Initialiser le générateur de nombres aléatoires
    srand(time(NULL));

    vector<Animal*> animaux;

    // Créer 25% du plateau rempli (25 animaux pour un plateau 10x10)
    // 6 de chaque type (6*4 = 24, on ajoute 1 loup pour avoir 25)
    int nbParType = 6;

    // Créer les loups
    for (int i = 0; i < nbParType + 1; i++) {
        animaux.push_back(new Loup(MAX_X, MAX_Y));
    }

    // Créer les pierres
    for (int i = 0; i < nbParType; i++) {
        animaux.push_back(new Pierre(MAX_X, MAX_Y));
    }

    // Créer les lions
    for (int i = 0; i < nbParType; i++) {
        animaux.push_back(new Lion(MAX_X, MAX_Y));
    }

    // Créer les ours
    for (int i = 0; i < nbParType; i++) {
        animaux.push_back(new Ours(MAX_X, MAX_Y));
    }

    cout << "=== JEU DE VIE ARTIFICIELLE ===" << endl;
    cout << "Plateau initial avec " << compterVivants(animaux) << " animaux" << endl;
    afficherPlateau(animaux);

    int tour = 0;
    char reponse = 'o';

    // Boucle de jeu
    while (reponse == 'o' || reponse == 'O') {
        tour++;
        cout << "\n--- Tour " << tour << " ---" << endl;

        // Déplacer tous les animaux vivants
        for (Animal* animal : animaux) {
            if (animal->getVivant()) {
                animal->deplace(MAX_X, MAX_Y);
            }
        }

        // Résoudre les conflits
        resoudreConflits(animaux);

        // Afficher le plateau
        int vivants = compterVivants(animaux);
        cout << "Animaux vivants : " << vivants << endl;
        afficherPlateau(animaux);

        // Vérifier s'il reste des animaux
        if (vivants == 0) {
            cout << "Tous les animaux sont morts! Fin du jeu." << endl;
            break;
        }

        // Demander si on continue
        cout << "Continuer? (o/n) : ";
        cin >> reponse;
    }

    // Libérer la mémoire
    for (Animal* animal : animaux) {
        delete animal;
    }

    cout << "\nFin du jeu après " << tour << " tours." << endl;

    return 0;
}
