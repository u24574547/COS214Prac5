#ifndef COS214PRAC5_MOSS_H
#define COS214PRAC5_MOSS_H
#include "BasePlant.h"


class Moss: public BasePlant {
private:
    const double GROWTH_MULTIPLIER = 1.5;
public:
    Moss(std::string species, int currentEnvironment, int growthLevel,  bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);
    virtual ~Moss();
    virtual std::string toString() const;
    virtual void water();
};


#endif //COS214PRAC5_MOSS_H