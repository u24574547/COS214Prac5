#include "DeadState.h"
#include "Plant.h"
#include "BasePlant.h"

void DeadState::nextState(Plant* plant) {
    std::cout << "Plant has been died.End of lifecycle." << std::endl;
    // No further state change
}

void DeadState::grow(Plant* plant) {
    std::cout << "The plant has died.No growth is possible" << std::endl;
}

std::string DeadState::getName() {
    return "Dead State";
}