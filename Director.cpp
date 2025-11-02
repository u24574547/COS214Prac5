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
        if (species == "Tulipa gesneriana") hasTulip = true;
        else if (species == "Rosa chinensis") hasRose = true;
        else if (species == "Nephrolepis exaltata") hasFern = true;
    }
    delete it;

    if(!hasTulip) std::cout << "Tulipa gesneriana not found in inventory.\n";
    if(!hasRose)  std::cout << "Rosa chinensis not found in inventory.\n";
    if(!hasFern)  std::cout << "Nephrolepis exaltata not found in inventory.\n";

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
        if (species == "Riccia fluitans") hasRiccia = true;
        else if (species == "Nephrolepis exaltata") hasFern = true;
        else if (species == "Bryum argenteum") hasMoss = true;
    }
    delete it;

    if(!hasRiccia) std::cout << "Riccia fluitans not found in inventory.\n";
    if(!hasFern) std::cout << "Nephrolepis exaltata not found in inventory.\n";
    if(!hasMoss) std::cout << "Bryum argenteum not found in inventory.\n";
    
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
        if (species == "Bryum argenteum") hasMoss = true;
        else if (species == "Adiantum raddianum") hasFern = true;
        else if (species == "Fittonia albivenis") hasFittonia = true;
    }
    delete it;

    if (!hasMoss) std::cout << "Bryum argenteum not found in inventory.\n";
    if (!hasFern) std::cout << "Adiantum raddianum not found in inventory.\n";
    if (!hasFittonia) std::cout << "Fittonia albivenis not found in inventory.\n";
    
    if (hasMoss && hasFern && hasFittonia) {
        builder->addFertilisedPlant(inventory);  // TerrariumBuilder will get moss
        builder->addFertilisedPlant(inventory);  // TerrariumBuilder will get fern
        builder->addBasicPlant(inventory);       // TerrariumBuilder will get fittonia
        return true;
    }
    return false;
}