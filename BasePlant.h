#ifndef COS214PRAC5_BASEPLANT_H
#define COS214PRAC5_BASEPLANT_H
#include "Plant.h"
#include "SeedlingState.h"
#include "SoldState.h"
#include <iostream>
#include <sstream>


class BasePlant: public Plant {
public:
    BasePlant(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment, PlantState *state);
    virtual ~BasePlant();

    virtual std::string toString() const=0;
    virtual void water()=0;


    void setState(PlantState* newState) override;
    std::string getStateName() override;
    void markSold() override;
    bool isSold() override;
    int getGrowthLevel() override;
    std::string getSpecies() override;
    bool isWateredToday() override;
    int getPreferredEnvironment() override;

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
// End of BasePlant.h