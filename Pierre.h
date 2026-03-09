#ifndef PIERRE_H
#define PIERRE_H

#include "Animal.h"

class Pierre : public Animal {
public:
    // Constructeurs hérités
    using Animal::Animal;

    // Une pierre pourrait avoir un déplacement nul (0,0) dans son .cpp
    void setAttaque() override;
    void deplace(int maxX, int maxY) override;
};

#endif