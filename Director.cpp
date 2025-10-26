#include "Director.h"
#include <string>

Director::Director(Builder* b, Inventory* i){
    builder = b;
    inventory = i;
}

void Director::constructGiftBundle(){
    builder->reset();
    // I need to check if the plants exist in inventory
    Plant* tulip = inventory->getPlant("Tulip");
    Plant* rose = inventory->getPlant("Rose");
    Plant* fern = inventory->getPlant("Fern");
    
    if (tulip && rose && fern) {
        // Add decorative plants with ribbons for gift presentation
        builder->addDecorativePlant(tulip);  // Will be decorated with ribbon
        builder->addDecorativePlant(rose);   // Will be decorated with ribbon
        builder->addBasicPlant(fern);        // Accent plant, no decoration
    }
    
    
    
}
void Director::constructFrostReadyBundle(){
    builder->reset();
    Plant* nonFlowering = inventory->getPlant("NonFlowering");
    Plant* fern = inventory->getPlant("Fern");
    Plant* moss = inventory->getPlant("Moss");
    
    if (nonFlowering && fern && moss) {
        // All plants need frost protection
        builder->addFrostNetPlant(nonFlowering);
        builder->addFrostNetPlant(fern);
        builder->addBasicPlant(moss);  // Moss is naturally frost resistant
        
        // Add some fertilizer to help winter growth
        builder->addFertilisedPlant(nonFlowering);
    }
}

void Director::constructTerrariumBundle(){
    builder->reset();
    builder->reset();
    Plant* moss = inventory->getPlant("Moss");
    Plant* fern = inventory->getPlant("Fern");
    Plant* nonFlowering = inventory->getPlant("NonFlowering");
    
    if (moss && fern && nonFlowering) {
        // Terrarium plants need proper nutrients
        builder->addFertilisedPlant(moss);
        builder->addFertilisedPlant(fern);
        builder->addBasicPlant(nonFlowering);
    }
}

