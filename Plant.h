#ifndef PLANT_H
#define PLANT_H

#include "PlantState.h"
#include <string>

class Plant : public Bundle{
public:
    // Constructor
    Plant();

    // Destructor
    virtual ~Plant();

    virtual std::string toString() const=0;
    virtual void water()=0;

    // Set a new state
    virtual void setState(PlantState* newState)=0;

    // Get current state's name
    virtual std::string getStateName()=0;

    // Mark plant as sold
    virtual void markSold()=0;

    // Check if plant has been sold
    virtual bool isSold()=0;

    virtual int getGrowthLevel()=0;
    virtual std::string getSpecies()=0;
    virtual bool isWateredToday()=0;
    virtual int getPreferredEnvironment()=0;
    virtual void setCurrentEnvironment(int newEnv)=0;

    virtual void endDay()=0;
};

#endif // PLANT_H
