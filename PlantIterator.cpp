
#ifndef PlantIterator_CPP
#define PlantIterator_CPP
#include "PlantIterator.h"

#include "Inventory.h"
#include "Plant.h"

PlantIterator::PlantIterator(Aggregate *inventory) : Iterator(inventory) {}
PlantIterator::~PlantIterator() {}
void PlantIterator::next() {}
bool PlantIterator::isDone() {}
Plant *PlantIterator::getCurrent() {}

#endif