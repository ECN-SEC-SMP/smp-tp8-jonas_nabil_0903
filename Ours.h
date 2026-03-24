#ifndef OURS_H
#define OURS_H

#include "Animal.h"

class Ours : public Animal {
public:
    // Constructeurs hérités
    using Animal::Animal;

    void setAttaque() override;
    void deplace(int maxX, int maxY) override;
};

#endif
