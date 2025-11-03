#include "MatureState.h"

void MatureState::nextState(Plant* plant) {
    //depending on conditions, transition to ReadyForSaleState
    std::cout << "Transitioning from Mature to ReadyForSale" << std::endl;
    plant->setState(new ReadyForSaleState());
}


void MatureState::grow(Plant* plant) {
    if (oldGrowthLevel>=plant->getGrowthLevel()) {
        startDying(plant);
    }
    oldGrowthLevel=plant->getGrowthLevel();
    if (plant->getAmountWateredToday()) {
        std::cout << "Mature "<<plant->getSpecies()<<" plant growing... growth level: " << plant->getGrowthLevel() << std::endl;

        if (plant->getGrowthLevel() >= 50) { // threshold for ReadyForSale
            nextState(plant);
        }
    }
}
std::string MatureState::getName() {
    return "Mature State";
}

void MatureState::startDying(Plant *plant) {
    std::cout << "Mature plant is in poor and begins dying." << std::endl;
    plant->setState(new DyingState());
}
