#include "GiftBuilder.h"
#include <iostream>
#include <sstream>


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
    //I need to decorate the plants
    
}
void GiftBuilder::addFertilisedPlant(Plant* name){
    
}


DisplayBundle* GiftBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

GiftBuilder::~GiftBuilder() {
    if (bundle) delete bundle;
}
