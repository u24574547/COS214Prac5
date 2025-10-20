#include "DormantState.h"
#include "Plant.h"
#include "SeedlingState.h"

void DormantState::nextState(Plant* plant) {
    std::cout << "Dormant period over, transitioning to Seedling" << std::endl;
    plant->setState(new SeedlingState());
}
