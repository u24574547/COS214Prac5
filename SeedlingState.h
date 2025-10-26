#ifndef SEEDLINGSTATE_H
#define SEEDLINGSTATE_H

#include "PlantState.h"

/**
 * @class SeedlingState
 * @brief Represents the state of a plant that has just started growing.
 * 
 * The SeedlingState class defines the behavior of a Plant object when it has
 * been planted and has begun early growth. In this stage, the plant can
 * transition to the Mature state once sufficient growth occurs.
 * 
 * This class is part of the State design pattern implementation, where each
 * state defines distinct behaviors for the Plant.
 */
class SeedlingState : public PlantState {
public:
    /**
     * @brief Transitions the plant to its next logical state.
     * 
     * Typically moves the plant from the Seedling state to the Mature state
     * as it continues to grow.
     * 
     * @param plant Pointer to the Plant object whose state will change.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Retrieves the name of this state.
     * 
     * @return A string representing the current state ("Seedling").
     */
    std::string getName() override;

    /**
     * @brief Simulates growth behavior specific to the Seedling state.
     * 
     * May include logic to strengthen the plant or prepare it for maturity.
     * This function helps illustrate how behavior changes as the plant
     * transitions through states.
     * 
     * @param plant Pointer to the Plant object performing the growth action.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Virtual destructor for safe cleanup.
     */
    ~SeedlingState() override {}
};

#endif // SEEDLINGSTATE_H
