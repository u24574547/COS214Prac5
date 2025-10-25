#include "FrostReadyBundle.h"
#include <iostream>
#include <sstream>


FrostReadyBundle::FrostReadyBundle() {
    bundle = new DisplayBundle();
}

void FrostReadyBundle::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void FrostReadyBundle::addBasicPlant(Plant* name) {
    bundle->add(name);    
}
void FrostReadyBundle::addDecorativePlant(Plant* name) {
    //I need to decorate the plants
    
    
}
void FrostReadyBundle::addFertilisedPlant(Plant* name){
    // Decorate plant in fertiliser
    
}
void FrostReadyBundle::addFrostNetPlant(Plant* name){
    //Decorate plant in frost net 
}


DisplayBundle* FrostReadyBundle::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

FrostReadyBundle::~FrostReadyBundle() {
    if (bundle) delete bundle;
}
