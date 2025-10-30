#include "FloweringSupplier.h"

FloweringSupplier::FloweringSupplier() {
}

FloweringSupplier::~FloweringSupplier() {
}

Plant * FloweringSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new Flowering(species, currentEnvironment, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState);
}
