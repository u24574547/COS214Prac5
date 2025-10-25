#include "Fertiliser.h"

Fertiliser::Fertiliser(Plant *plant): PlantDecorator(plant) {
}

Fertiliser::~Fertiliser() {
}

std::string Fertiliser::toString() const {
    return plant->toString()+" Fertiliser";
}
