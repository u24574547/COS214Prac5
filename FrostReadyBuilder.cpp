#include "FrostReadyBuilder.h"
#include <iostream>
#include <sstream>


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
    
    
}
void FrostReadyBuilder::addFertilisedPlant(Plant* name){
    // Decorate plant in fertiliser
    
}
void FrostReadyBuilder::addFrostNetPlant(Plant* name){
    //Decorate plant in frost net 
}


DisplayBundle* FrostReadyBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

FrostReadyBuilder::~FrostReadyBuilder() {
    if (bundle) delete bundle;
}
