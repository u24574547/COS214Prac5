#include "GiftBundle.h"
#include <iostream>
#include <sstream>


GiftBundle::GiftBundle() {
    bundle = new DisplayBundle();
}

void GiftBundle::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void GiftBundle::addBasicPlant(Plant* name) {
    bundle->add(name);    
}
void GiftBundle::addDecorativePlant(Plant* name) {
    //I need to decorate the plants
    
}
void GiftBundle::addFertilisedPlant(Plant* name){
    
}


DisplayBundle* GiftBundle::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

GiftBundle::~GiftBundle() {
    if (bundle) delete bundle;
}
