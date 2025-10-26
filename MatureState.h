#ifndef MATURESTATE_H
#define MATURESTATE_H

#include "PlantState.h"

/**
 * @class MatureState
 * @brief Represents the state of a plant that has reached maturity.
 *
 * The MatureState class defines the behavior of a Plant object that is fully
 * grown but not yet ready for sale. In this state, the plant may continue
 * growing slightly or prepare for the ReadyForSale state.
 *
 * This class is part of the State design pattern, allowing different
 * growth behaviors to be encapsulated per state.
 */
class MatureState : public PlantState {
public:
    /**
     * @brief Transitions the plant to its next logical state.
     *
     * Typically moves the plant from the Mature state to the ReadyForSale state
     * when growth and conditions meet the requirements.
     *
     * @param plant Pointer to the Plant object whose state will change.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Retrieves the name of this state.
     *
     * @return A string representing the current state ("Mature").
     */
    std::string getName() override;

    /**
     * @brief Simulates growth behavior specific to the Mature state.
     *
     * Allows the plant to grow further or trigger transitions toward the sale-ready state.
     *
     * @param plant Pointer to the Plant object performing the growth action.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Virtual destructor for safe cleanup.
     */
    ~MatureState() override {}
};

#endif // MATURESTATE_H
