#include "BasePlant.h"

BasePlant::BasePlant(std::string species, int growthLevel=0,  bool isWatered=false, double growthRate=10.0, int preferredEnvironment=0, int currentEnvironment, PlantState* state = new SeedlingState()) : Plant() {
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
    std::cout << "Plant Information:\n"
                  << "  Species: " << species << "\n"
                  << "  Growth Level: " << growthLevel << "\n"
                  << "  Growth Rate: " << growthRate << "\n"
                  << "  Has been Watered today: " << (isWatered ? "Yes" : "No") << "\n"
                  << "  Preferred Environment: " << preferredEnvironment << "\n"
                  << "  Current Environment: " << currentEnvironment << "\n"
                  << "  Life-cycle Stage: " << state->getName() << "\n";
}

void BasePlant::water() {
    isWatered = true;
    growthLevel+= growthRate-abs(preferredEnvironment-currentEnvironment);
    //TODO: state = state->grow(growthLevel);
}
