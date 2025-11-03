#include "ReadyForSale.h"

void ReadyForSaleState::nextState(Plant* plant) {
    if (plant->isSold()) {
        std::cout << "Plant sold! Transitioning to Sold state." << std::endl;
        plant->setState(new SoldState());
    }
}

void ReadyForSaleState::grow(Plant* plant) {
    if (oldGrowthLevel>=plant->getGrowthLevel()) {
        startDying(plant);
    }
    oldGrowthLevel=plant->getGrowthLevel();
    if (plant->isSold()) {
        nextState(plant); // move to Sold
    }
    else {
        std::cout << plant->getSpecies()<<" is ready for sale." << std::endl;
    }
}

std::string ReadyForSaleState::getName() {
    return "Ready For Sale State";
}

void ReadyForSaleState::startDying(Plant *plant) {
    std::cout << "A plant that is ready for sale is in poor conditions and begins dying." << std::endl;
    plant->setState(new DyingState());
}
