#include "Director.h"
#include <string>

Director::Director(Builder* b, Inventory* i){
    builder = b;
    inventory = i;
}

void Director::constructGiftBundle(){
    builder->reset();
    // I need to check if the plants exist in inventory
    Plant* tulip = inventory->getPlant("Tulipa gesneriana");
    Plant* rose = inventory->getPlant("Rosa chinensis");
    Plant* fern = inventory->getPlant("Nephrolepis exaltata");
    // Debugging checks
    if(tulip == NULL){
        std::cout << "Tulipa gesneriana not found in inventory.\n";
    }
    if(rose == NULL){
        std::cout << "Rosa chinensis not found in inventory.\n";
    }
    if(fern == NULL){
        std::cout << "Nephrolepis exaltata not found in inventory.\n";
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
    Plant* fern = inventory->getPlant("Nephrolepis exaltata");
    Plant* moss = inventory->getPlant("Bryum argenteum");
    if(nonFlowering == NULL){
        std::cout << "Riccia fluitan not found in inventory.\n";
    }
    if(fern == NULL){
        std::cout << "Nephrolepis exaltata not found in inventory.\n";
    }
    if(moss == NULL){
        std::cout << "Bryum argenteum not found in inventory.\n";
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
    Plant* moss = inventory->getPlant("Bryum argenteum");
    Plant* fern = inventory->getPlant("Adiantum raddianum");
    Plant* fittonia = inventory->getPlant("Fittonia albivenis");

    if (!moss) std::cout << "Bryum argenteum (Moss) not found in inventory.\n";
    if (!fern) std::cout << "Adiantum raddianum (Fern) not found in inventory.\n";
    if (!fittonia) std::cout << "Fittonia albivenis (Nerve plant) not found in inventory.\n";
    
    if (moss && fern && fittonia) {
        // Terrarium plants need proper nutrients
        builder->addFertilisedPlant(moss);
        builder->addFertilisedPlant(fern);
        builder->addBasicPlant(fittonia);
    }
}

