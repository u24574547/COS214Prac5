#ifndef COS214PRAC5_BASEPLANT_H
#define COS214PRAC5_BASEPLANT_H
#include "Plant.h"
#include "SeedlingState.h"
#include <iostream>


class BasePlant: public Plant {
public:
    BasePlant(std::string species, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment,
              int currentEnvironment, PlantState *state);

    virtual ~BasePlant();
    void display() const;
    void water();
private:
    int growthLevel;
    std::string species;
    bool isWatered;
    double growthRate;
    int preferredEnvironment;
    int currentEnvironment;
    PlantState* state;
};


#endif //COS214PRAC5_BASEPLANT_H