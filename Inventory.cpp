
#include "Inventory.h"
#include <iostream>

#include "BasePlant.h"


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
            (*it)->water(1000);
        }
    }
}

void Inventory::observeTime(Day *time) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        time->addObserver((*it)->getBase());
    }
}
void Inventory::removeDead()
{
    for (size_t i = 0; i < items.size(); i++)
    {
        if (items[i]->getStateName() == "Dead State") {
            items.erase(items.begin() + i);
            i = 0;
        }
    }
}
