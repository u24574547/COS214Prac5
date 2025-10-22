#include "BasePlant.h"

BasePlant::BasePlant(std::string species, int growthLevel=0,  bool isWatered=false, double growthRate=1.0, int preferredEnvironment=0, int currentEnvironment, PlantState* state = new SeedlingState()) : Plant() {
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

void BasePlant::display() const {
}

void BasePlant::water() {
}
