#include "FernSupplier.h"

FernSupplier::FernSupplier() {
}

FernSupplier::~FernSupplier() {
}

Plant * FernSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new Fern(species, currentEnvironment, growthLevel, isWatered, growthRate, preferredEnvironment, oldState);
}
