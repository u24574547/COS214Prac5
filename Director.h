#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"

class Director {
private:
    Builder* builder;
public:
    Director(Builder* b);
    void constructSimpleBundle();
    void constructFancyBundle();
};

#endif
