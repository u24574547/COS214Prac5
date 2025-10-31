#include "Ribbon.h"

Ribbon::Ribbon(Plant *plant): PlantDecorator(plant) {
}

Ribbon::~Ribbon() {
}

std::string Ribbon::toString() const {
    return plant->toString()+" Ribbon";
}
