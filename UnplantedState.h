#ifndef UNPLANTEDSTATE_H
#define UNPLANTEDSTATE_H

#include "PlantState.h"

class UnplantedState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override ;
    virtual void grow(Plant* plant) override;
    virtual ~UnplantedState() override {}
};

#endif // UNPLANTEDSTATE_H
// End of UnplantedState.h