#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

class MatureState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override { return "Mature"; }
};

#endif // MATURESTATE_H
