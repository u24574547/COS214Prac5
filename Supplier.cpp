#include "Supplier.h"

#include "Fertiliser.h"
#include "FrostNet.h"

Supplier::Supplier() {
    this->growthLevel= 0;
    this->species="unknown";
    this->amountWateredToday=0;
    this->requiredWaterPerDay = 50;
    this->growthRate=1.0;
    this->preferredEnvironment=0;
    this->currentEnvironment=0;
    this->state = new UnplantedState();
}

Supplier::~Supplier() {
    delete state;
}

void Supplier::setState(PlantState *state) {
    delete this->state;
    this->state = state;
}

void Supplier::setGrowthLevel(int growthLevel) {
    this->growthLevel = growthLevel;
}

void Supplier::setSpecies(std::string species) {
    this->species = species;
}

void Supplier::setAmountWateredToday(int amountWateredToday) {
    this->amountWateredToday=amountWateredToday;
}

void Supplier::setGrowthRate(double growthRate) {
    this->growthRate = growthRate;
}

void Supplier::setPreferredEnvironment(int env) {
    this->preferredEnvironment = env;
}

void Supplier::setCurrentEnvironment(int env) {
    this->currentEnvironment = env;
}

PlantState * Supplier::getState() {
    return this->state;
}

int Supplier::getGrowthLevel() {
    return this->growthLevel;
}

std::string Supplier::getSpecies() {
    return this->species;
}

int Supplier::getAmountWateredToday() {
    return this->amountWateredToday;
}

double Supplier::getGrowthRate() {
    return this->growthRate;
}

int Supplier::getPreferredEnvironment() {
    return this->preferredEnvironment;
}

int Supplier::getCurrentEnvironment() {
    return this->currentEnvironment;
}

Plant * Supplier::addFertiliser(Plant *plant) {
    return new Fertiliser(plant);
}

Plant * Supplier::addFrostNet(Plant *plant) {
    return new FrostNet(plant);
}

void Supplier::setRequiredWaterPerDay(int requiredWaterPerDay) {
    this->requiredWaterPerDay = requiredWaterPerDay;
}

int Supplier::getRequiredWaterPerDay() {
    return this->requiredWaterPerDay;
}
