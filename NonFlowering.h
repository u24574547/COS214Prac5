#ifndef COS214PRAC5_NONFLOWERING_H
#define COS214PRAC5_NONFLOWERING_H
#include "BasePlant.h"


class NonFlowering: public BasePlant {
private:
    const double GROWTH_MULTIPLIER = 1.0;
public:
    NonFlowering(std::string species, int currentEnvironment, int growthLevel,  bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);
    virtual ~NonFlowering();
    virtual std::string toString() const;
    virtual void water();
};


#endif //COS214PRAC5_NONFLOWERING_H