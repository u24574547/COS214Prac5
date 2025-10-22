#ifndef Inventory_H
#define Inventory_H

#include "Aggregate.h"
#include "Plant.h"
#include "PlantIterator.h"

class Inventory : public Aggregate
{
    friend class PlantIterator;

public:
    Inventory();
    ~Inventory();

    Iterator *createIterator();

protected:
private:
    vector<Plant *> plants;
};

#endif