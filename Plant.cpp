#include "Plant.h"

Plant::Plant(){}

Plant::~Plant() {
<<<<<<< HEAD
    if (state!= nullptr) {
        delete state;
    }
}

// Set a new state
void Plant::setState(PlantState* newState) {
    if (state!= nullptr) {
        delete state;
    }
    
    state = newState;
}

// Delegate to current state's nextState()
void Plant::nextState() {
    state->nextState(this);
}

std::string Plant::getStateName() {
    return state->getName();
}

void Plant::markSold() {
    sold = true;
}

bool Plant::isSold() {
    return sold;
=======
>>>>>>> c93fcd48edd09d98240de95c401b7939f30e3dc7
}
