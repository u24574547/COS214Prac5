#include "ReadyForSale.h"

void ReadyForSaleState::nextState(Plant* plant) {
    if (plant->isSold()) {
        std::cout << "Plant sold! Transitioning to Sold" << std::endl;
        plant->setState(new SoldState());
    }
}

void ReadyForSaleState::grow(Plant* plant) {
    if (oldGrowthLevel>plant->getGrowthLevel()) {
        startDying(plant);
    }
    oldGrowthLevel=plant->getGrowthLevel();
    if (plant->isSold()) {
        nextState(plant); // move to Sold
    }
    else {
        std::cout << "Plant is ready for sale. No further growth." << std::endl;
    }
}

std::string ReadyForSaleState::getName() {
    return "Ready For Sale State";
}

void ReadyForSaleState::startDying(Plant *plant) {
    std::cout << "Seedling has negative growth and begins dying." << std::endl;
    plant->setState(new DyingState());
}
