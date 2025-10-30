#include "UnplantedState.h"
#include "Plant.h"
#include "SeedlingState.h"

void UnplantedState::nextState(Plant* plant) {
    //depending on conditions, transition to SeedlingState
    std::cout << "Transitioning from Unplanted to Seedling" << std::endl;
    plant->setState(new SeedlingState());
}

void UnplantedState::grow(Plant* plant) {
    if (plant->getAmountWateredToday()) {
        std::cout << "Seed has been watered! It starts sprouting." << std::endl;
        nextState(plant); // move to Seedling
    } else {
        std::cout << "Seed is dry. Water it to start growing." << std::endl;
    }
}

std::string UnplantedState::getName() {
    return "Unplanted State";
}   