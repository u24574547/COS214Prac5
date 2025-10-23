#include "Fern.h"

Fern::Fern(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate,
    int preferredEnvironment, PlantState *state): BasePlant(species, currentEnvironment, growthLevel, isWatered, growthRate, preferredEnvironment, state) {
}

Fern::~Fern() {
}

std::string Fern::toString() const {
    std::stringstream ss;
    ss << "Plant Information:\n";
    ss << "  Plant sub-kingdom: Pteridophyta\n";
    ss << "  Species: " << species << "\n";
    ss << "  Growth Level: " << growthLevel << "\n";
    ss << "  Growth Rate: " << growthRate << "\n";
    ss << "  Has been Watered today: " << (isWatered ? "Yes" : "No") << "\n";
    ss << "  Preferred Environment: " << preferredEnvironment << "\n";
    ss << "  Current Environment: " << currentEnvironment << "\n";
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    return ss.str();
}

void Fern::water() {
    if (!isWatered) growthLevel+= GROWTH_MULTIPLIER*(growthRate-abs(preferredEnvironment-currentEnvironment));
    isWatered = true;
}
