#include "TerrariumBuilder.h"
#include <iostream>
#include "Fertiliser.h"
#include "Inventory.h"

TerrariumBuilder::TerrariumBuilder() {
    bundle = new DisplayBundle();
}

void TerrariumBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void TerrariumBuilder::addBasicPlant(Inventory* inventory) {
    // Get fittonia as accent plant
    Plant* fittonia = inventory->getPlant("Fittonia albivenis");
    if (fittonia) {
        std::cout << "TerrariumBuilder: Adding fittonia as accent plant\n";
        bundle->add(fittonia);
    }
}

void TerrariumBuilder::addDecorativePlant(Inventory* inventory) {
    // Terrariums don't use decorative plants
}

void TerrariumBuilder::addFertilisedPlant(Inventory* inventory) {
    static bool firstCall = true;
    if (firstCall) {
        Plant* moss = inventory->getPlant("Bryum argenteum");
        if (moss) {
            std::cout << "TerrariumBuilder: Adding fertilised moss\n";
            bundle->add(new Fertiliser(moss));
        }
        firstCall = false;
    } else {
        Plant* fern = inventory->getPlant("Adiantum raddianum");
        if (fern) {
            std::cout << "TerrariumBuilder: Adding fertilised fern\n";
            bundle->add(new Fertiliser(fern));
        }
        firstCall = true;
    }
}

void TerrariumBuilder::addFrostNetPlant(Inventory* inventory) {
    // Terrariums don't use frost protection
}

DisplayBundle* TerrariumBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = nullptr;
    return result;
}

TerrariumBuilder::~TerrariumBuilder() {
    if (bundle) delete bundle;
}