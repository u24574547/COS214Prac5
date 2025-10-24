#include "UnplantedState.h"
#include "Plant.h"
#include "SeedlingState.h"

void UnplantedState::nextState(Plant* plant) {
    //depending on conditions, transition to SeedlingState
    std::cout << "Transitioning from Unplanted to Seedling" << std::endl;
    plant->setState(new SeedlingState());
}
