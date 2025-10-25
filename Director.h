#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Inventory.h"

class Director {
private:
    Builder* builder;
    Inventory* inventory;
public:
    Director(Builder* b, Inventory* i);
    void constructSimpleBundle();
    void constructFancyBundle();
    void constructGiftBundle();
    void constructFrostReadyBundle();
};

#endif
