
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
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getStateName() == "Dead State") {
            Plant* plant= *it;
            items.erase(it);
            --it;
            delete plant;
        }
    }
}

Plant * Inventory::getReadyForSalePlant(string name) {
    Plant* plant = nullptr;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->getSpecies() == name && (*it)->getStateName()=="Ready For Sale State") {
            plant = (*it);
            plant->setState(new SoldState());
            items.erase(it);
            break;
        }
    }
    return plant;
}

std::string Inventory::stockSummary(std::string type) {
    std::map<std::string, int> counts;

    for (const auto& item : items) {
        if (item->getSubKingdom()==type && item->getStateName()=="Ready For Sale State")++counts[item->getSpecies()];
    }

    std::stringstream ss;
    for (const pair<const string, int>& pair : counts) {
        ss << pair.first << ": " << pair.second << "\n";
    }

    if (!ss.str().empty())return ss.str();
    return "No "+type+" plants are for sale at the moment.";
}
