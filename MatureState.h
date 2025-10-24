#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

class MatureState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override ;
    virtual void grow(Plant* plant) override;
    ~MatureState() override {}
};

#endif // MATURESTATE_H
// End of MatureState.h