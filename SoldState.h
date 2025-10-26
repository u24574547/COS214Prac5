#ifndef SOLDSTATE_H
#define SOLDSTATE_H

#include "PlantState.h"

/**
 * @class SoldState
 * @brief Represents a plant that has been sold.
 * 
 * This is the terminal state in the plant's lifecycle. Once a plant is sold,
 * no further state transitions occur.
 */
class SoldState : public PlantState {
public:
    /**
     * @brief Handles transition to the next state.
     * 
     * Since this is a terminal state, this function typically does nothing.
     * 
     * @param plant Pointer to the Plant object whose state would change.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Returns the name of this state.
     * 
     * @return A string "Sold".
     */
    std::string getName() override;

    /**
     * @brief Simulates growth behavior in the Sold state.
     * 
     * No growth occurs as the plant has been sold. This can remain empty or log info.
     * 
     * @param plant Pointer to the Plant object performing the growth action.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Destructor.
     */
    ~SoldState() override {}
};

#endif // SOLDSTATE_H
