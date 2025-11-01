#include "PlantDecorator.h"

PlantDecorator::PlantDecorator(Plant* plant, double price=5) {
    this->plant=plant;
    this->price=price;
}

PlantDecorator::~PlantDecorator() {
    delete plant;
}

void PlantDecorator::water(int waterAmount) {
    plant->water(waterAmount);
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

int PlantDecorator::getAmountWateredToday() {
    return plant->getAmountWateredToday();
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
    return plant->getGrowthMultiplier();
}

int PlantDecorator::getCurrentEnvironment() {
    return plant->getCurrentEnvironment();
}

int PlantDecorator::getRequiredWaterPerDay() {
    return plant->getRequiredWaterPerDay();
}

double PlantDecorator::getPrice() {
    return plant->getPrice()+price;
}

void PlantDecorator::setPrice(double price) {
    plant->setPrice(price);
}
