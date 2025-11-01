#include "FrostNet.h"

FrostNet::FrostNet(Plant *plant, double price): PlantDecorator(plant, price) {
}

FrostNet::~FrostNet() {
}

std::string FrostNet::toString() const {
    return plant->toString()+" Frost_net";
}
