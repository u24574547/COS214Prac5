#include "FrostReadyBuilder.h"
#include <iostream>
#include "FrostNet.h"
#include "Fertiliser.h"
#include "Inventory.h"

FrostReadyBuilder::FrostReadyBuilder() {
    bundle = new DisplayBundle();
}

void FrostReadyBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void FrostReadyBuilder::addBasicPlant(Inventory* inventory) {
    // Get moss (naturally frost resistant)
    Plant* moss = inventory->getReadyForSalePlant("Bryum argenteum");
    if (moss) {
        std::cout << "FrostReadyBuilder: Adding frost-resistant moss\n";
        bundle->add(moss);
    }
}

void FrostReadyBuilder::addDecorativePlant(Inventory* inventory) {
    // Frost bundles don't use decorative plants
}

void FrostReadyBuilder::addFertilisedPlant(Inventory* inventory) {
    // Add fertiliser to riccia for winter growth
    Plant* riccia = inventory->getReadyForSalePlant("Riccia fluitans");
    if (riccia) {
        std::cout << "FrostReadyBuilder: Adding fertilised riccia for winter growth\n";
        bundle->add(new Fertiliser(riccia));
    }
}

void FrostReadyBuilder::addFrostNetPlant(Inventory* inventory) {
    static bool firstCall = true;
    if (firstCall) {
        Plant* riccia = inventory->getReadyForSalePlant("Riccia fluitans");
        if (riccia) {
            std::cout << "FrostReadyBuilder: Adding frost-protected riccia\n";
            bundle->add(new FrostNet(riccia));
        }
        firstCall = false;
    } else {
        Plant* fern = inventory->getReadyForSalePlant("Nephrolepis exaltata");
        if (fern) {
            std::cout << "FrostReadyBuilder: Adding frost-protected fern\n";
            bundle->add(new FrostNet(fern));
        }
        firstCall = true;
    }
}

DisplayBundle* FrostReadyBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = nullptr;
    return result;
}

FrostReadyBuilder::~FrostReadyBuilder() {
    if (bundle) delete bundle;
}