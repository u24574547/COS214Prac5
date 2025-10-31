#include "Moss.h"

Moss::Moss(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState()): BasePlant(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, state) {
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
    ss << "  Amount watered today: " << amountWateredToday << "\n";
    ss << "  Preferred Environment: " << preferredEnvironment << "\n";
    ss << "  Current Environment: " << currentEnvironment << "\n";
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    ss << "  Extras:";
    return ss.str();
}

double Moss::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}
