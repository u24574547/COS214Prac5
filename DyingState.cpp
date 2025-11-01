#include "DyingState.h"

void DyingState::nextState(Plant *plant) {
    std::cout <<"A "<< plant->getSpecies()<<" dies." << std::endl;
    plant->setState(new DeadState());
}

void DyingState::startDying(Plant *plant) {
    //stubbed
}

std::string DyingState::getName() {
    return "Dying State";
}

void DyingState::grow(Plant *plant) {
    if (oldGrowthLevel>=plant->getGrowthLevel()) {
        daysDying++;
        std::cout<<"Plant still dying. Days od life left without intervention: "<<3-daysDying<<std::endl;
    }
    else {
        daysTakenCareOf++;
        std::cout<<"Plant is recovering from almost dying."<<std::endl;
    }
    oldGrowthLevel=plant->getGrowthLevel();
    if (daysDying>=3) {
        this->nextState(plant);
    }
    if (daysTakenCareOf>=3) {
        if (plant->getGrowthLevel()<20) {
            plant->setState(new SeedlingState());
        }
        else if (plant->getGrowthLevel()<50) {
            plant->setState(new MatureState());
        }
        else {
            plant->setState(new ReadyForSaleState());
        }
    }
}
