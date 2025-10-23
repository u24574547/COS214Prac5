#include "MatureState.h"
#include "Plant.h"
#include "ReadyForSaleState.h"

void MatureState::nextState(Plant* plant) {
    //depending on conditions, transition to ReadyForSaleState
    std::cout << "Transitioning from Mature to ReadyForSale" << std::endl;
    plant->setState(new ReadyForSaleState());
}


void MatureState::grow(Plant* plant) {
    if (plant->isWateredToday()) {
        //plant->incrementGrowth(3); // slower growth amkes more sense
        std::cout << "Mature plant growing... growth level: " << plant->getGrowthLevel() << std::endl;

        if (plant->getGrowthLevel() >= 50) { // threshold for ReadyForSale
            nextState(plant);
        }
    }
}
std::string MatureState::getName() {
    return "Mature State";
}   