#ifndef DORMANTSTATE_H
#define DORMANTSTATE_H

#include "PlantState.h"

class DormantState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override { return "Dormant"; }
};

#endif // DORMANTSTATE_H
