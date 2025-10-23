#include "SoldState.h"
#include "Plant.h"

void SoldState::nextState(Plant* plant) {
    std::cout << "Plant has been sold. End of lifecycle." << std::endl;
    // No further state change
}
