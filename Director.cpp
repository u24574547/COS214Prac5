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
    // Debugging checks
    if(tulip == NULL){
        std::cout << "Tulip not found in inventory.\n";
    }
    if(rose == NULL){
        std::cout << "Rose not found in inventory.\n";
    }
    if(fern == NULL){
        std::cout << "Fern not found in inventory.\n";
    }
    if (tulip && rose && fern) {
        // Add decorative plants with ribbons for gift presentation
        builder->addDecorativePlant(tulip);  // Will be decorated with ribbon
        builder->addDecorativePlant(rose);   // Will be decorated with ribbon
        builder->addBasicPlant(fern);        // Accent plant, no decoration
    }
    
    
    
}
void Director::constructFrostReadyBundle(){
    builder->reset();
    Plant* nonFlowering = inventory->getPlant("Riccia fluitans");
    Plant* fern = inventory->getPlant("Fern");
    Plant* moss = inventory->getPlant("Moss");
    if(nonFlowering == NULL){
        std::cout << "Riccia fluitan not found in inventory.\n";
    }
    if(fern == NULL){
        std::cout << "Fern not found in inventory.\n";
    }
    if(moss == NULL){
        std::cout << "Moss not found in inventory.\n";
    }
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

