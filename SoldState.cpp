#include "SoldState.h"
#include "Plant.h"
#include "BasePlant.h"

void SoldState::nextState(Plant* plant) {
    std::cout << "Plant has been sold.End of lifecycle." << std::endl;
    // No further state change
}

void SoldState::grow(Plant* plant) {
    std::cout << "The plant has been sold.No growth is possible" << std::endl;
}

std::string SoldState::getName() {
    return "Sold State";
}
// End of SoldState.cpp