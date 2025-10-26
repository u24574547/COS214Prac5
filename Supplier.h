#ifndef COS214PRAC5_SUPPLIER_H
#define COS214PRAC5_SUPPLIER_H
#include "Plant.h"
#include "SeedlingState.h"
#include "UnplantedState.h"


class Supplier {
public:
    Supplier();
    virtual ~Supplier();

    void setState(PlantState* state);
    void setGrowthLevel(int growthLevel);
    void setSpecies(std::string species);
    void setWatered(bool watered);
    void setGrowthRate(double growthRate);
    void setPreferredEnvironment(int env);
    void setCurrentEnvironment(int env);

    PlantState* getState();
    int getGrowthLevel();
    std::string getSpecies();
    bool getWatered();
    double getGrowthRate();
    int getPreferredEnvironment();
    int getCurrentEnvironment();
    Plant* addFertiliser(Plant* plant);
    Plant* addFrostNet(Plant* plant);

    virtual Plant* getPlant()=0;

protected:
    int growthLevel;
    std::string species;
    bool isWatered;
    double growthRate;
    int preferredEnvironment;
    int currentEnvironment;
    PlantState* state;
};


#endif //COS214PRAC5_SUPPLIER_H