#ifndef LION_H
#define LION_H

#include "Animal.h"

class Lion : public Animal {
public:
    // Constructeurs hérités
    using Animal::Animal;

    void setAttaque() override;
    void deplace(int maxX, int maxY) override;
};

#endif
