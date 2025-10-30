#include "NonFlowering.h"

NonFlowering::NonFlowering(std::string species, int currentEnvironment, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState()): BasePlant(species, currentEnvironment, growthLevel, amountWateredToday, growthRate, preferredEnvironment, state) {
}

NonFlowering::~NonFlowering() {
}

std::string NonFlowering::toString() const {
    std::stringstream ss;
    ss << "Plant Information:\n";
    ss << "  Plant sub-kingdom: Gymnosperms\n";
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

double NonFlowering::getGrowthMultiplier() {
    return GROWTH_MULTIPLIER;
}
