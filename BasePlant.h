#ifndef COS214PRAC5_BASEPLANT_H
#define COS214PRAC5_BASEPLANT_H
#include "Plant.h"


class BasePlant: public Plant {
public:
    BasePlant();
    virtual ~BasePlant();
    void display() const;
};


#endif //COS214PRAC5_BASEPLANT_H