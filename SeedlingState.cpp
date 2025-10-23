#include "SeedlingState.h"
#include "Plant.h"
#include "MatureState.h"

void SeedlingState::nextState(Plant* plant) {
    //depending on conditions, transition to MatureState
    std::cout << "Transitioning from Seedling to Mature" << std::endl;
    plant->setState(new MatureState());
}
