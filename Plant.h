#ifndef PLANT_H
#define PLANT_H

#include "PlantState.h"
#include <string>

class Plant {
private:
    PlantState* state;
    bool sold = false;
public:
    // Constructor
    Plant();

    // Destructor
    ~Plant();

    // Set a new state
    void setState(PlantState* newState);

    // Advance to the next state
    void nextState();

    // Get current state's name
    std::string getStateName();

    // Mark plant as sold
    void markSold();

    // Check if plant has been sold
    bool isSold();
};

#endif // PLANT_H
