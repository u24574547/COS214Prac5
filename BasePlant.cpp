#include "BasePlant.h"

BasePlant::BasePlant(std::string species, int currentEnvironment, int growthLevel=0,  bool isWatered=false, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new SeedlingState()) : Plant() {
    this->growthLevel = growthLevel;
    this->species = species;
    this->isWatered=isWatered;
    this->growthRate=growthRate;
    this->preferredEnvironment=preferredEnvironment;
    this->currentEnvironment=currentEnvironment;
    this->state = state;
}

BasePlant::~BasePlant() {
    delete this->state;
}

void BasePlant::setState(PlantState *newState) {
    if (newState != this->state) delete this->state;
    this->state = newState;
}

std::string BasePlant::getStateName() {
    if (this->state==nullptr) {
        this->state=new SeedlingState();
    }
    return this->state->getName();
}

void BasePlant::markSold() {
    delete this->state;
    this->state=new SoldState();
}

bool BasePlant::isSold() {
    return state!=nullptr && state->getName()=="Sold";
}

int BasePlant::getGrowthLevel() {
    return this->growthLevel;
}

std::string BasePlant::getSpecies() {
    return this->species;
}

bool BasePlant::isWateredToday() {
    return this->isWatered;
}

int BasePlant::getPreferredEnvironment() {
    return this->preferredEnvironment;
}


// void BasePlant::incrementGrowth(int amount) {
//     growthLevel += amount;
//     // Optionally clamp max growth
// }

// void BasePlant::grow() {
//     if (state)
//         state->grow(this); // delegates to current state
        // else{
        //     std::cout << "No state assigned to plant. Cannot grow." << std::endl;
        // }
// }

