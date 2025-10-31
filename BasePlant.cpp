#include "BasePlant.h"

BasePlant::BasePlant(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState()) : Plant() {
    this->growthLevel = growthLevel;
    this->species = species;
    this->amountWateredToday=amountWateredToday;
    this->requiredWaterPerDay = requiredWaterPerDay;
    this->growthRate=growthRate;
    this->preferredEnvironment=preferredEnvironment;
    this->currentEnvironment=currentEnvironment;
    this->state = state;
}

BasePlant::~BasePlant() {
    delete this->state;
}

void BasePlant::setState(PlantState *newState) {
    if (newState != this->state) delete this->state;
    this->state = newState;
}

std::string BasePlant::getStateName() {
    if (this->state==nullptr) {
        this->state=new UnplantedState();
    }
    return this->state->getName();
}

void BasePlant::markSold() {
    delete this->state;
    this->state=new SoldState();
}

bool BasePlant::isSold() {
    return state!=nullptr && state->getName()=="Sold";
}

int BasePlant::getGrowthLevel() {
    return this->growthLevel;
}

std::string BasePlant::getSpecies() {
    return this->species;
}

int BasePlant::getAmountWateredToday() {
    return this->amountWateredToday;
}

int BasePlant::getPreferredEnvironment() {
    return this->preferredEnvironment;
}

void BasePlant::setCurrentEnvironment(int newEnv) {
    this->currentEnvironment=newEnv;
}

void BasePlant::endDay() {
    grow();
    this->amountWateredToday=0;
}

void BasePlant::grow() {
    if (state) {
        if (amountWateredToday>=requiredWaterPerDay) growthLevel += getGrowthMultiplier() * (growthRate - abs(preferredEnvironment - currentEnvironment));
        state->grow(this); // delegates to current state
    } else {
        std::cout << "No state assigned to plant. Cannot grow." << std::endl;
    }
}

int BasePlant::getCurrentEnvironment() {
    return currentEnvironment;
}

void BasePlant::water(int waterAmount) {
    this->amountWateredToday+=waterAmount;
}

int BasePlant::getRequiredWaterPerDay() {
    return requiredWaterPerDay;
}
