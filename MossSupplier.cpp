#include "MossSupplier.h"

MossSupplier::MossSupplier() {
}

MossSupplier::~MossSupplier() {
}

Plant * MossSupplier::getPlant() {
    PlantState* oldState = state;
    state = new UnplantedState();
    return new Moss(species, currentEnvironment, growthLevel, amountWateredToday, growthRate, preferredEnvironment, oldState);
}
