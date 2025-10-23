#include "Moss.h"

Moss::Moss(std::string species, int currentEnvironment, int growthLevel=0,  bool isWatered=false, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new SeedlingState()): BasePlant(species, currentEnvironment, growthLevel, isWatered, growthRate, preferredEnvironment, state) {
}

Moss::~Moss() {
}

std::string Moss::toString() const {
    std::cout << "Plant Information:\n"
                  << "  Species: " << species << "\n"
                  << "  Growth Level: " << growthLevel << "\n"
                  << "  Growth Rate: " << growthRate << "\n"
                  << "  Has been Watered today: " << (isWatered ? "Yes" : "No") << "\n"
                  << "  Preferred Environment: " << preferredEnvironment << "\n"
                  << "  Current Environment: " << currentEnvironment << "\n"
                  << "  Life-cycle Stage: " << state->getName() << "\n";
}

void Moss::water() {
    isWatered = true;
    growthLevel+= growthRate-abs(preferredEnvironment-currentEnvironment);
    //TODO: state = state->grow(growthLevel);
}