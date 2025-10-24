#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"

class SeedlingState : public PlantState {
public:
    void nextState(Plant* plant) override;
    std::string getName() override { return "Seedling"; }
};

#endif // SEEDLINGSTATE_H
// End of SeedlingState.h