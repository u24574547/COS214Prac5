#ifndef COS214PRAC5_PLANTDECORATOR_H
#define COS214PRAC5_PLANTDECORATOR_H
#include "Plant.h"


class PlantDecorator: public Plant {
protected:
    Plant* plant;
public:
    PlantDecorator();
    virtual ~PlantDecorator();
    void display() const;
};


#endif //COS214PRAC5_PLANTDECORATOR_H