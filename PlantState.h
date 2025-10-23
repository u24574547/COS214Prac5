#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <iostream>
#include <string>

class Plant; // Forward declaration

class PlantState {
public:
    virtual void nextState(Plant* plant) = 0;
    virtual void grow(Plant* plant) = 0; // <-- handle watering & growth
    virtual std::string getName() = 0;
    virtual ~PlantState() {}
};

#endif // PLANTSTATE_H
