#ifndef PIERRE.H
#define PIERRE.H

using namespace std;
#include "animal.h"

class Pierre : public Animal {

public:

    void setAttaque();
    void deplace(int maxX, int maxY);

};
#endif