#ifndef COS214PRAC5_BASEPLANT_H
#define COS214PRAC5_BASEPLANT_H
#include "Plant.h"
#include "UnplantedState.h"
#include "SoldState.h"
#include <iostream>
#include <sstream>


class BasePlant: public Plant {
public:
    BasePlant(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment, PlantState *state);
    virtual ~BasePlant();

    virtual std::string toString() const=0;
    virtual void water()=0;

    //sales functions
    void markSold() override;
    bool isSold() override;

    //getters
    std::string getStateName() override;
    int getGrowthLevel() override;
    std::string getSpecies() override;
    int getPreferredEnvironment() override;
    bool isWateredToday() override;

    //setters
    void setState(PlantState* newState) override;
    void setCurrentEnvironment(int newEnv) override;

    virtual void endDay();

protected:
    int growthLevel;
    std::string species;
    bool isWatered;
    double growthRate;
    int preferredEnvironment;
    int currentEnvironment;
    PlantState* state;
};


#endif //COS214PRAC5_BASEPLANT_H