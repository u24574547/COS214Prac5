#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "PlantState.h"

class SoldState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override;
     virtual void grow(Plant* plant) override;
    ~SoldState() override {}
};

#endif // SOLDSTATE_H
// End of SoldState.h