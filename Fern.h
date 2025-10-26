#ifndef COS214PRAC5_FERN_H
#define COS214PRAC5_FERN_H
#include "BasePlant.h"


class Fern: public BasePlant {
private:
    const double GROWTH_MULTIPLIER = 1.2;
public:
    Fern(std::string species, int currentEnvironment, int growthLevel,  bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);
    virtual ~Fern();
    std::string toString() const override;
    void water() override;
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_FERN_H