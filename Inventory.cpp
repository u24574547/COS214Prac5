
#include "Inventory.h"

Iterator<Plant*>* Inventory::createIterator() {
    return new PlantIterator(this);
}

void Inventory::addPlant(Plant*  plant) {
    items.push_back(plant);
}

Plant* Inventory::getPlant(string name) {
   Plant* plant = nullptr;
   for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getSpecies() == name) {
            plant = (*it);
            items.erase(it);
        }
   }
   return plant;
}

void Inventory::water(int environment) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getCurrentEnvironment() == environment) {
            (*it)->water();
        }
    }
}
