#include "NonFlowering.h"

NonFlowering::NonFlowering(std::string species, int currentEnvironment, int growthLevel, bool isWatered,
    double growthRate, int preferredEnvironment, PlantState *state): BasePlant(species, currentEnvironment, growthLevel, isWatered, growthRate, preferredEnvironment, state) {
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
    ss << "  Has been Watered today: " << (isWatered ? "Yes" : "No") << "\n";
    ss << "  Preferred Environment: " << preferredEnvironment << "\n";
    ss << "  Current Environment: " << currentEnvironment << "\n";
    ss << "  Life-cycle Stage: " << state->getName() << "\n";
    return ss.str();
}

void NonFlowering::water() {
    isWatered = true;
    growthLevel+= growthRate-abs(preferredEnvironment-currentEnvironment);
    //TODO: state = state->grow(growthLevel);
}
