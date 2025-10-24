#ifndef READYFORSALESTATE_H
#define READYFORSALESTATE_H

#include "PlantState.h"

class ReadyForSaleState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override { return "ReadyForSale"; }
};

#endif // READYFORSALESTATE_H
// End of ReadyForSale.h