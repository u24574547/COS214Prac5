#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(Plant* plant) {
    this->plant=plant;
}

PlantDecorator::~PlantDecorator() {
    delete plant;
}

void PlantDecorator::water() {
    plant->water();
}

void PlantDecorator::setState(PlantState *newState) {
    plant->setState(newState);
}

std::string PlantDecorator::getStateName() {
    return plant->getStateName();
}

void PlantDecorator::markSold() {
    plant->markSold();
}

bool PlantDecorator::isSold() {
    return plant->isSold();
}

int PlantDecorator::getGrowthLevel() {
    return plant->getGrowthLevel();
}

std::string PlantDecorator::getSpecies() {
    return plant->getSpecies();
}

bool PlantDecorator::isWateredToday() {
    return plant->isWateredToday();
}

int PlantDecorator::getPreferredEnvironment() {
    return plant->getPreferredEnvironment();
}

void PlantDecorator::setCurrentEnvironment(int newEnv) {
    plant->setCurrentEnvironment(newEnv);
}

void PlantDecorator::endDay() {
    plant->endDay();
}

double PlantDecorator::getGrowthMultiplier() {
    plant->getGrowthMultiplier();
}
