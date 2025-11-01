#include "GiftBuilder.h"
#include <iostream>
#include <sstream>
#include "Fertiliser.h"
#include "FrostNet.h"
#include "Ribbon.h"

GiftBuilder::GiftBuilder() {
    bundle = new DisplayBundle();
}

void GiftBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void GiftBuilder::addBasicPlant(Plant* name) {
    bundle->add(name);    
}
void GiftBuilder::addDecorativePlant(Plant* name) {
    Ribbon* decoratedPlant = new Ribbon(name);
    bundle->add(decoratedPlant);
    
}
void GiftBuilder::addFertilisedPlant(Plant* name){
    // decorate the plant and add it to the bundle
    Fertiliser* decoratedPlant = new Fertiliser(name);
    bundle->add(decoratedPlant);
}
void GiftBuilder::addFrostNetPlant(Plant* name){
    // decorate the plant and add it to the bundle
    FrostNet* decoratedPlant = new FrostNet(name);
    bundle->add(decoratedPlant);
}


DisplayBundle* GiftBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

GiftBuilder::~GiftBuilder() {
    if (bundle) delete bundle;
}
