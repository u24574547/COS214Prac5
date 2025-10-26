#ifndef COS214PRAC5_PLANTDECORATOR_H
#define COS214PRAC5_PLANTDECORATOR_H
#include "Plant.h"


class PlantDecorator: public Plant {
protected:
    Plant* plant;
public:
    PlantDecorator(Plant* plant);
    virtual ~PlantDecorator();
    virtual std::string toString() const=0;
    void water();

    // Set a new state
    void setState(PlantState* newState);

    // Mark plant as sold
    void markSold();

    // Check if plant has been sold
    bool isSold();

    //getters
    int getGrowthLevel();
    std::string getSpecies();
    bool isWateredToday();
    int getPreferredEnvironment();
    double getGrowthMultiplier();
    std::string getStateName();

    void setCurrentEnvironment(int newEnv);

    void endDay();
};


#endif //COS214PRAC5_PLANTDECORATOR_H