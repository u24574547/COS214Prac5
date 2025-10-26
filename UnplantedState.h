#ifndef UNPLANTEDSTATE_H
#define UNPLANTEDSTATE_H

#include "PlantState.h"

/**
 * @class UnplantedState
 * @brief Represents the initial state of a plant before it has been planted.
 * 
 * This class is part of the State design pattern. It defines the behavior of a
 * Plant object when it is in the "Unplanted" stage. From this state, the plant
 * can transition to the Seedling state when growth is initiated.
 */
class UnplantedState : public PlantState {
public:
    /**
     * @brief Transitions the plant to its next logical state.
     * 
     * Typically, this moves the plant from the Unplanted state to the Seedling state.
     * 
     * @param plant Pointer to the Plant whose state will be updated.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Retrieves the name of this state.
     * 
     * @return A string representing the name of the state ("Unplanted").
     */
    std::string getName() override;

    /**
     * @brief Simulates the growth behavior specific to the Unplanted state.
     * 
     * Since the plant has not yet been planted, this may initiate the planting process
     * or simply indicate that growth cannot occur until planting.
     * 
     * @param plant Pointer to the Plant object attempting to grow.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Virtual destructor for safe cleanup in derived classes.
     */
    virtual ~UnplantedState() override {}
};

#endif // UNPLANTEDSTATE_H
