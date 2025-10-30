
#include "Inventory.h"
#include <iostream>


Iterator<Plant*>* Inventory::createIterator() {
    return new PlantIterator(this);
}

void Inventory::addPlant(Plant*  plant) {
    items.push_back(plant);
    std::cout << "Plant added: " << plant->getSpecies() << "\n";
}

Plant* Inventory::getPlant(string name) {
   Plant* plant = nullptr;
   for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getSpecies() == name) {
            plant = (*it);
            items.erase(it);
            break;
        }
   }
   return plant;
}

void Inventory::water(int environment) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getCurrentEnvironment() == environment) {
            (*it)->water(10);
        }
    }
}

void Inventory::endDay() {
    Iterator<Plant*>* iter = createIterator();
    while (!iter->isDone()) {
        iter->next()->endDay();
    }
}
