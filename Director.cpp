#include "Director.h"
#include <string>
#include "PlantIterator.h"

Director::Director(Builder* b, Inventory* i){
    builder = b;
    inventory = i;
}

bool Director::constructGiftBundle(){
    builder->reset();

    // Use iterator to only check availability (no removals)
    Iterator<Plant*>* it = inventory->createIterator();
    bool hasTulip = false;
    bool hasRose = false;
    bool hasFern = false;

    for (it->first(); !it->isDone(); it->next()) {
        Plant* p = it->current();
        if (!p) continue;
        std::string species = p->getSpecies();
        std::string state = p->getStateName();
        if (state=="Ready For Sale State") {
            if (species == "Tulipa gesneriana") hasTulip = true;
            else if (species == "Rosa chinensis") hasRose = true;
            else if (species == "Nephrolepis exaltata") hasFern = true;
        }
    }
    delete it;

    if(!hasTulip) std::cout << "No Tulipa gesneriana ready for sale were found in inventory.\n";
    if(!hasRose)  std::cout << "No Rosa chinensis ready for sale were found in inventory.\n";
    if(!hasFern)  std::cout << "No Nephrolepis exaltata ready for sale were found in inventory.\n";

    if (hasTulip && hasRose && hasFern) {
        builder->addDecorativePlant(inventory);  // GiftBuilder will get tulip
        builder->addDecorativePlant(inventory);  // GiftBuilder will get rose 
        builder->addBasicPlant(inventory);       // GiftBuilder will get fern
        return true;
    }
    return false;
}

bool Director::constructFrostReadyBundle(){
    builder->reset();

    Iterator<Plant*>* it = inventory->createIterator();
    bool hasRiccia = false;
    bool hasFern = false;
    bool hasMoss = false;

    for (it->first(); !it->isDone(); it->next()) {
        Plant* p = it->current();
        if (!p) continue;
        std::string species = p->getSpecies();
        std::string state = p->getStateName();
        if (state=="Ready For Sale State") {
            if (species == "Riccia fluitans") hasRiccia = true;
            else if (species == "Nephrolepis exaltata") hasFern = true;
            else if (species == "Bryum argenteum") hasMoss = true;
        }
    }
    delete it;

    if(!hasRiccia) std::cout << "No Riccia fluitans ready for sale were found in inventory.\n";
    if(!hasFern) std::cout << "No Nephrolepis exaltata ready for sale were found in inventory.\n";
    if(!hasMoss) std::cout << "No Bryum argenteum ready for sale were found in inventory.\n";
    
    if (hasRiccia && hasFern && hasMoss) {
        builder->addFrostNetPlant(inventory);    // FrostBuilder will get riccia
        builder->addFrostNetPlant(inventory);    // FrostBuilder will get fern
        builder->addBasicPlant(inventory);       // FrostBuilder will get moss
        builder->addFertilisedPlant(inventory);  // FrostBuilder will get riccia again
        return true;
    }
    return false;
}

bool Director::constructTerrariumBundle(){
    builder->reset();
    
    Iterator<Plant*>* it = inventory->createIterator();
    bool hasMoss = false;
    bool hasFern = false;
    bool hasFittonia = false;

    for (it->first(); !it->isDone(); it->next()) {
        Plant* p = it->current();
        if (!p) continue;
        std::string species = p->getSpecies();
        std::string state = p->getStateName();
        if (state=="Ready For Sale State") {
            if (species == "Bryum argenteum") hasMoss = true;
            else if (species == "Adiantum raddianum") hasFern = true;
            else if (species == "Fittonia albivenis") hasFittonia = true;
        }
    }
    delete it;

    if (!hasMoss) std::cout << "No Bryum argenteum ready for sale were found in inventory.\n";
    if (!hasFern) std::cout << "No Adiantum raddianum ready for sale were found in inventory.\n";
    if (!hasFittonia) std::cout << "No Fittonia albivenis ready for sale were found in inventory.\n";
    
    if (hasMoss && hasFern && hasFittonia) {
        builder->addFertilisedPlant(inventory);  // TerrariumBuilder will get moss
        builder->addFertilisedPlant(inventory);  // TerrariumBuilder will get fern
        builder->addBasicPlant(inventory);       // TerrariumBuilder will get fittonia
        return true;
    }
    return false;
}