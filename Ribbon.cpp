#include "Ribbon.h"

Ribbon::Ribbon(Plant *plant, double price): PlantDecorator(plant, price) {
}

Ribbon::~Ribbon() {
}

std::string Ribbon::toString() const {
    return plant->toString()+" Ribbon";
}
