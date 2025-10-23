#ifndef READYFORSALESTATE_H
#define READYFORSALESTATE_H

#include "PlantState.h"

class ReadyForSaleState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override;
    virtual void grow(Plant* plant) override;
    ~ReadyForSaleState() override {}
};

#endif // READYFORSALESTATE_H
