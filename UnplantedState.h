#ifndef UNPLANTEDSTATE_H
#define UNPLANTEDSTATE_H

#include "PlantState.h"

class UnplantedState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override { return "Unplanted"; }
};

#endif // UNPLANTEDSTATE_H
