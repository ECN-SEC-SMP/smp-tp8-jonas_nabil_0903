# TP - Jeu de Vie Artificielle

## Description

Mini jeu de vie artificielle où différents types d'animaux (Loups, Pierres, Lions, Ours) évoluent sur un plateau 10x10 et se battent en pierre-feuille-ciseaux.

## Structure du projet

```
.
├── Animal.h / Animal.cpp      # Classe abstraite Animal
├── Attaque.h / Attaque.cpp    # Classe Attaque (pierre-feuille-ciseaux)
├── Loup.h / Loup.cpp          # Classe Loup
├── Pierre.h / Pierre.cpp      # Classe Pierre
├── Lion.h / Lion.cpp          # Classe Lion
├── Ours.h / Ours.cpp          # Classe Ours
├── main.cpp                   # Programme principal
└── Makefile                   # Fichier de compilation
```

## Types d'animaux

### Loup (W)
- **Déplacement** : Aléatoire sur n'importe quelle cellule du plateau
- **Attaque** : Pierre, Feuille ou Ciseaux (aléatoire)

### Pierre (P)
- **Déplacement** : Immobile
- **Attaque** : Pierre uniquement

### Lion (L)
- **Déplacement** : Diagonale (1,1), (1,-1), (-1,-1) ou (-1,1)
- **Attaque** : Feuille ou Ciseaux (aléatoire)

### Ours (O)
- **Déplacement** : En L comme un cavalier d'échecs (8 directions possibles)
- **Attaque** : Feuille uniquement

## Règles du jeu

1. Le plateau est torique (les bords se rejoignent)
2. Chaque tour, tous les animaux se déplacent
3. Si plusieurs animaux sont sur la même case, ils se battent au chifoumi
4. Le perdant disparaît
5. Le jeu continue jusqu'à ce qu'il n'y ait plus qu'un type d'animal ou que l'utilisateur arrête

## Compilation

### Avec Makefile (Linux/Mac)
```bash
make
```

### Compilation manuelle
```bash
g++ -Wall -std=c++11 -o jeu main.cpp Animal.cpp Attaque.cpp Loup.cpp Pierre.cpp Lion.cpp Ours.cpp
```

### Windows
```bash
g++ -o jeu.exe main.cpp Animal.cpp Attaque.cpp Loup.cpp Pierre.cpp Lion.cpp Ours.cpp
```

## Exécution

```bash
./jeu          # Linux/Mac
jeu.exe        # Windows
```

ou avec Makefile:
```bash
make run
```

## Nettoyage

```bash
make clean
```

## Exemple d'affichage

```
  0 1 2 3 4 5 6 7 8 9
0 . W . . P . . L . .
1 . . . O . . . . . W
2 . . L . . . . . P .
3 P . . . W . O . . .
4 . . . . . L . . . .
5 . O . . . . . W . .
6 . . . P . . . . . L
7 W . . . . . . . . .
8 . . . . O . . . . .
9 . L . . . W . P . .
```

Légende:
- `W` : Loup (Wolf)
- `P` : Pierre
- `L` : Lion
- `O` : Ours
- `.` : Case vide

## Auteurs

Jonas & Nabil - SMP TP8
