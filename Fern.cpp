#include "Fern.h"

Fern::Fern(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel,  int amountWateredToday, double growthRate, int preferredEnvironment, PlantState* state, double price): BasePlant(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, state, price) {
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
    ss << "  Has been Watered today: " << amountWateredToday << "\n";
    ss << "  Preferred Environment: " << preferredEnvironment << "\n";
    ss << "  Current Environment: " << currentEnvironment << "\n";
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    ss << "  Extras:";
    return ss.str();
}

double Fern::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}
