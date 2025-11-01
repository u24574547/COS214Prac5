#include "NonFloweringSupplier.h"

NonFloweringSupplier::NonFloweringSupplier() {
}

NonFloweringSupplier::~NonFloweringSupplier() {
}

Plant * NonFloweringSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new NonFlowering(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState, price);
}
