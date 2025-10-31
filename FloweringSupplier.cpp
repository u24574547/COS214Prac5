#include "FloweringSupplier.h"

FloweringSupplier::FloweringSupplier() {
}

FloweringSupplier::~FloweringSupplier() {
}

Plant * FloweringSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new Flowering(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState);
}
