#include "Director.h"
#include <string>

Director::Director(Builder* b, Inventory* i){
    builder = b;
    inventory = i;
}

void Director::constructGiftBundle(){
    builder->reset();
    // I need to check if the plants exist in inventory
    builder->addDecorativePlant(inventory->getPlant("Tulip"));
    
    
}
void Director::constructFrostReadyBundle(){
    builder->reset();
}
