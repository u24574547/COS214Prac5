#ifndef INVENTORY_H
#define INVENTORY_H

#include "Aggregate.h"
#include "Command.h"
#include "Plant.h"
#include "PlantIterator.h"
#include <string>

class Inventory : public Aggregate<Plant*> {
    public:
        Inventory() : Aggregate(plants) {};
        ~Inventory(){};
        Iterator<Plant*>* createIterator() override;
        void addPlant(Plant* plant);
        Plant* getPlant(string name);
    private:
        vector<Plant*> plants;
};

#endif