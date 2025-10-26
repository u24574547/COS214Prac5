#include "FrostNet.h"

FrostNet::FrostNet(Plant *plant): PlantDecorator(plant) {
}

FrostNet::~FrostNet() {
}

std::string FrostNet::toString() const {
    return plant->toString()+" Frost net";
}
