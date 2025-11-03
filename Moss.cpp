#include "Moss.h"

Moss::Moss(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel,  int amountWateredToday, double growthRate, int preferredEnvironment, PlantState* state, double price): BasePlant(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, state, price) {
}

Moss::~Moss() {
}

std::string Moss::toString() const {
    std::stringstream ss;
    ss << "Plant Information:\n";
    ss << "  Plant sub-kingdom: Bryophyta\n";
    ss << "  Species: " << species << "\n";
    //ss << "  Growth Level: " << growthLevel << "\n";
    //ss << "  Growth Rate: " << growthRate << "\n";
    ss << "  Amount watered today: " << amountWateredToday << "\n";
    ss << "  Required water per today: " << requiredWaterPerDay << "\n";
    ss << "  Preferred Environment: " << ((preferredEnvironment==1)?"Tropical":(preferredEnvironment==2)?"Temperate":(preferredEnvironment==3)?"Continental":(preferredEnvironment==4)?"Dry":"unknown") << "\n";//Tropical/Temperate/Continental/Dry
    ss << "  Current Environment: " << ((currentEnvironment==1)?"Greenhouse":(currentEnvironment==2)?"Shadenet":(currentEnvironment==3)?"Semi-shaded":(currentEnvironment==4)?"Sunny":"unknown") << "\n";//Greenhouse/Shadenet/Semi-shaded/Sunny
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    ss << "  Price: R" << price << "\n";
    ss << "  Extras:";
    return ss.str();
}

double Moss::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}

std::string Moss::getSubKingdom() {
    return"Bryophyta";
}
