#include "Plant.h"

Plant::Plant(PlantState* initialState) : state(initialState) {}

Plant::~Plant() {
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
}

void Plant::display() const {
    std::cout << "Plant: " << name << std::endl;
}
