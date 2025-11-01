#include "TerrariumBuilder.h"
#include <iostream>
#include <sstream>
#include "Fertiliser.h"
#include "FrostNet.h"
#include "Ribbon.h"
TerrariumBuilder::TerrariumBuilder() {
    bundle = new DisplayBundle();
}

void TerrariumBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void TerrariumBuilder::addBasicPlant(Plant* name) {
    bundle->add(name);    
}
void TerrariumBuilder::addDecorativePlant(Plant* name) {
    Ribbon* decoratedPlant = new Ribbon(name);
    bundle->add(decoratedPlant);
    
}
void TerrariumBuilder::addFertilisedPlant(Plant* name){
    // decorate the plant and add it to the bundle
    Fertiliser* decoratedPlant = new Fertiliser(name);
    bundle->add(decoratedPlant);
    
}
void TerrariumBuilder::addFrostNetPlant(Plant* name){
    // decorate the plant and add it to the bundle
    FrostNet* decoratedPlant = new FrostNet(name);
    bundle->add(decoratedPlant);
    
}


DisplayBundle* TerrariumBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

TerrariumBuilder::~TerrariumBuilder() {
    if (bundle) delete bundle;
}
