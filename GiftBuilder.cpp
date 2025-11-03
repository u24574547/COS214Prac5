#include "GiftBuilder.h"
#include <iostream>
#include "Fertiliser.h"
#include "FrostNet.h"
#include "Ribbon.h"
#include "Inventory.h"

GiftBuilder::GiftBuilder() : firstDecorative(true) {
    bundle = new DisplayBundle();
}

void GiftBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
    firstDecorative = true;
}

void GiftBuilder::addBasicPlant(Inventory* inventory) {
    // Gift bundles use fern as accent plant
    Plant* fern = inventory->getReadyForSalePlant("Nephrolepis exaltata");
    if (fern) {
        std::cout << "GiftBuilder: Adding fern as accent plant\n";
        bundle->add(fern);
    }
}

void GiftBuilder::addDecorativePlant(Inventory* inventory) {
    if (firstDecorative) {
        // First decorative plant is always tulip
        Plant* tulip = inventory->getReadyForSalePlant("Tulipa gesneriana");
        if (tulip) {
            std::cout << "GiftBuilder: Adding tulip with ribbon\n";
            bundle->add(new Ribbon(tulip));
        }
        firstDecorative = false;
    } else {
        // Second decorative plant is always rose
        Plant* rose = inventory->getReadyForSalePlant("Rosa chinensis");
        if (rose) {
            std::cout << "GiftBuilder: Adding rose with ribbon\n";
            bundle->add(new Ribbon(rose));
        }
    }
}

void GiftBuilder::addFertilisedPlant(Inventory* inventory) {
    
}

void GiftBuilder::addFrostNetPlant(Inventory* inventory) {
    
}

DisplayBundle* GiftBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = nullptr;
    return result;
}

GiftBuilder::~GiftBuilder() {
    if (bundle) delete bundle;
}