#ifndef COS214PRAC5_FLOWERING_H
#define COS214PRAC5_FLOWERING_H
#include "BasePlant.h"


class Flowering: public BasePlant {
private:
    const double GROWTH_MULTIPLIER = 0.8;
public:
    Flowering(std::string species, int currentEnvironment, int growthLevel,  bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);
    ~Flowering() override;
    std::string toString() const override;
    void water() override;
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_FLOWERING_H