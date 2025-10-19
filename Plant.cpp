#include "PlantComponent.h"

Plant::Plant(const std::string& n) : name(n) {}

void Plant::display() const {
    std::cout << "Plant: " << name << std::endl;
}
