#include "Fertiliser.h"

Fertiliser::Fertiliser(Plant *plant, double price): PlantDecorator(plant, price) {
}

Fertiliser::~Fertiliser() {
}

std::string Fertiliser::toString() const {
    return plant->toString()+" Fertiliser";
}
