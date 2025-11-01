#ifndef READYFORSALESTATE_H
#define READYFORSALESTATE_H

#include "PlantState.h"
#include "DyingState.h"
#include "Plant.h"
#include "SoldState.h"

/**
 * @class ReadyForSaleState
 * @brief Represents a plant that has matured and is ready for sale.
 *
 * In this state, the plant is considered fully grown and available for purchase.
 * The state can transition to Sold when purchased, or potentially back to Dormant
 * if not sold in the season.
 */
class ReadyForSaleState : public PlantState {
public:
    /**
     * @brief Handles transition to the next state.
     *
     * Typically moves to SoldState if the plant is purchased.
     *
     * @param plant Pointer to the Plant object whose state will change.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Plant begins dying because of negative growth.
     *
     * Plants can have negative growth from not being watered or being in a bad environment.
     *
     * @param plant Pointer to the Plant object that starts dying.
     */
    void startDying(Plant *plant) override;

    /**
     * @brief Returns the name of this state.
     *
     * @return A string "ReadyForSale".
     */
    std::string getName() override;

    /**
     * @brief Simulates growth behavior in the ReadyForSale state.
     *
     * This could trigger seasonal changes or check if the plant should revert
     * to a previous state if not sold.
     *
     * @param plant Pointer to the Plant object performing the growth action.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Destructor.
     */
    ~ReadyForSaleState() override {}
};

#endif // READYFORSALESTATE_H
