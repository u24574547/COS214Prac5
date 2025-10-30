#include "PlantIterator.h" 
#include "Inventory.h"

PlantIterator::PlantIterator(Aggregate<Plant*>* plantsAggregate) 
    : Iterator<Plant*>(plantsAggregate),
      plants(plantsAggregate->getItems()),  
      index(0)
{}

PlantIterator::~PlantIterator() {

}

Plant* PlantIterator::first() {
    index = 0;
    return plants[0];
}

Plant* PlantIterator::next() {
    if (!isDone()) return plants[index++];
    return nullptr;
}

Plant* PlantIterator::current() {
    return plants[index];
}

Plant* PlantIterator::last() {
    index = plants.size() - 1;
    return plants[index];
}

bool PlantIterator::isDone() {
    return index >= plants.size();
}