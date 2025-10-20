#ifndef PlantIterator_H
#define PlantIterator_H

#include "Iterator.h"

class Inventory;
class Plant;

class PlantIterator : public Iterator
{
public:
    PlantIterator(Aggregate *inventory);
    ~PlantIterator();

    void next();
    bool isDone();

    Plant *getCurrent();

protected:
private:
    vector<Plant *> plants;
};

#endif