#include "FrostReadyBuilder.h"
#include <iostream>
#include <sstream>
#include "FrostNet.h"
#include "Fertiliser.h"
#include "Ribbon.h"

FrostReadyBuilder::FrostReadyBuilder() {
    bundle = new DisplayBundle();
}

void FrostReadyBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void FrostReadyBuilder::addBasicPlant(Plant* name) {
    bundle->add(name);    
}
void FrostReadyBuilder::addDecorativePlant(Plant* name) {
    Ribbon* decoratedPlant = new Ribbon(name);
    bundle->add(decoratedPlant);
    
    
}
void FrostReadyBuilder::addFertilisedPlant(Plant* name){
    // Decorate plant in fertiliser
    Fertiliser* decoratedPlant = new Fertiliser(name);
    bundle->add(decoratedPlant);
    
}
void FrostReadyBuilder::addFrostNetPlant(Plant* name){
    //Decorate plant in frost net 
    FrostNet* decoratedPlant = new FrostNet(name);
    bundle->add(decoratedPlant);
}


DisplayBundle* FrostReadyBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

FrostReadyBuilder::~FrostReadyBuilder() {
    if (bundle) delete bundle;
}
