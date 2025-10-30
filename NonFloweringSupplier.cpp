#include "NonFloweringSupplier.h"

NonFloweringSupplier::NonFloweringSupplier() {
}

NonFloweringSupplier::~NonFloweringSupplier() {
}

Plant * NonFloweringSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new NonFlowering(species, currentEnvironment, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState);
}
