#include "TerrariumBuilder.h"
#include <iostream>
#include <sstream>


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
    //I need to decorate the plants
    
}
void TerrariumBuilder::addFertilisedPlant(Plant* name){
    
}


DisplayBundle* TerrariumBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

TerrariumBuilder::~TerrariumBuilder() {
    if (bundle) delete bundle;
}
