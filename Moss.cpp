#include "Moss.h"

Moss::Moss(std::string species, int currentEnvironment, int growthLevel=0,  bool isWatered=false, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState()): BasePlant(species, currentEnvironment, growthLevel, isWatered, growthRate, preferredEnvironment, state) {
}

Moss::~Moss() {
}

std::string Moss::toString() const {
    std::stringstream ss;
    ss << "Plant Information:\n";
    ss << "  Plant sub-kingdom: Bryophyta\n";
    ss << "  Species: " << species << "\n";
    ss << "  Growth Level: " << growthLevel << "\n";
    ss << "  Growth Rate: " << growthRate << "\n";
    ss << "  Has been Watered today: " << (isWatered ? "Yes" : "No") << "\n";
    ss << "  Preferred Environment: " << preferredEnvironment << "\n";
    ss << "  Current Environment: " << currentEnvironment << "\n";
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    ss << "  Extras:";
    return ss.str();
}

void Moss::water() {
    isWatered = true;
}

double Moss::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}
