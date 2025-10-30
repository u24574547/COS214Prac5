#include "FrostReadyBuilder.h"
#include <iostream>
#include <sstream>
#include "FrostNet.h"
#include "Fertiliser.h"

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
    //I need to decorate the plants
    // For now till i get that decorator class ill add normal
    bundle->add(name);
    
    
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
