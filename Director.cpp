#include "Director.h"
#include <string>

Director::Director(Builder* b) : builder(b) {}

void Director::constructSimpleBundle() {
    builder->reset();
    builder->addBasicPlant("Fern");
    builder->addBasicPlant("Cactus");
}

void Director::constructFancyBundle() {
    builder->reset();
    builder->addBasicPlant("Orchid");
    builder->addDecorativePlant("Rose");
    builder->addDecorativePlant("Bonsai");
}
void Director::constructGiftBundle(){
    builder->reset();
    // I need to check if the plants exist in inventory
    
}
