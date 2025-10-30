#include "MatureState.h"
#include "Plant.h"
#include "ReadyForSale.h"

void MatureState::nextState(Plant* plant) {
    //depending on conditions, transition to ReadyForSaleState
    std::cout << "Transitioning from Mature to ReadyForSale" << std::endl;
    plant->setState(new ReadyForSaleState());
}


void MatureState::grow(Plant* plant) {
    if (plant->getAmountWateredToday()) {
        std::cout << "Mature plant growing... growth level: " << plant->getGrowthLevel() << std::endl;

        if (plant->getGrowthLevel() >= 50) { // threshold for ReadyForSale
            nextState(plant);
        }
    }
}
std::string MatureState::getName() {
    return "Mature State";
}   