#include "Supplier.h"

#include "Fertiliser.h"
#include "FrostNet.h"

Supplier::Supplier() {
    this->growthLevel= 0;
    this->species="unknown";
    this->isWatered=false;
    this->growthRate=1.0;
    this->preferredEnvironment=0;
    this->currentEnvironment=0;
    this->state = new SeedlingState();
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

void Supplier::setWatered(bool watered) {
    this->isWatered = watered;
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

bool Supplier::getWatered() {
    return this->isWatered;
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

Plant * Supplier::addFrostnet(Plant *plant) {
    return new FrostNet(plant);
}
