#include "SeedlingState.h"

void SeedlingState::nextState(Plant* plant) {
    //depending on conditions, transition to MatureState
    std::cout << "Transitioning from Seedling to Mature" << std::endl;
    plant->setState(new MatureState());
}

void SeedlingState::grow(Plant* plant) {
    if (oldGrowthLevel>plant->getGrowthLevel()) {
        startDying(plant);
    }
    oldGrowthLevel=plant->getGrowthLevel();
    if (plant->getAmountWateredToday()) {
        std::cout << "Seedling growing... growth level: " << plant->getGrowthLevel() << std::endl;

        if (plant->getGrowthLevel() >= 20) { // threshold for Mature
            this->nextState(plant); // transition to MatureState
        }
    } else {
        std::cout << "Seedling not watered today. No growth." << std::endl;
    }
}

std::string SeedlingState::getName() {
    return "Seedling State";
}

void SeedlingState::startDying(Plant *plant) {
    std::cout << "Seedling has negative growth and begins dying." << std::endl;
    plant->setState(new DyingState());
}
