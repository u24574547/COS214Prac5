#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"

//remove if there's no circular includes
class Inventory;
class Plant;

class PlantIterator : public Iterator<Plant*> {
    public:
        PlantIterator(Aggregate<Plant*>* plants);
        ~PlantIterator();

        Plant* first() override;
        Plant* next() override;
        Plant* current() override;
        Plant* last() override;
        bool isDone() override;

    private:
        vector<Plant*> plants;
        size_t index;
};

#endif