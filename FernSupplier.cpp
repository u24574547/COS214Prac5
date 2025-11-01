#include "FernSupplier.h"

FernSupplier::FernSupplier() {
}

FernSupplier::~FernSupplier() {
}

Plant * FernSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new Fern(species, currentEnvironment, requiredWaterPerDay, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState, price);
}
