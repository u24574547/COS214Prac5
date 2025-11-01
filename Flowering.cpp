#include "Flowering.h"

Flowering::Flowering(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel,  int amountWateredToday, double growthRate, int preferredEnvironment, PlantState* state, double price): BasePlant(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, state, price) {
}

Flowering::~Flowering() {
}

std::string Flowering::toString() const {
    std::stringstream ss;
    ss << "Plant Information:\n";
    ss << "  Plant sub-kingdom: Angiosperms\n";
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

double Flowering::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}
