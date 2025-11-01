#ifndef COS214PRAC5_DYINGSTATE_H
#define COS214PRAC5_DYINGSTATE_H
#include "PlantState.h"
#include "DeadState.h"
#include "Plant.h"

/**
 * @class DyingState
 * @brief Represents the state of a plant that has just started growing.
 *
 * The SeedlingState class defines the behavior of a Plant object when it has
 * been planted and has begun early growth. In this stage, the plant can
 * transition to the Mature state once sufficient growth occurs.
 *
 * This class is part of the State design pattern implementation, where each
 * state defines distinct behaviors for the Plant.
 */
class DyingState : public PlantState {
public:
    /**
     * @brief Transitions the plant to its next logical state.
     *
     * Plant dies.
     *
     * @param plant Pointer to the Plant object whose state will change.
     */
    void nextState(Plant* plant) override;

    /**
     * @brief Plant is already dying. Nothing happens
     *
     * @param plant Pointer to the Plant object that starts dying.
     */
    void startDying(Plant *plant) override;

    /**
     * @brief Retrieves the name of this state.
     *
     * @return A string representing the current state ("Dying State").
     */
    std::string getName() override;

    /**
     * @brief Simulates growth behavior specific to the Dying state.
     *
     * The plant checks if it has recovered from almost dying or not.
     * To die, it must have negative growth for 3 days.
     * To recover it must have positive growth for 3 days.
     *
     * @param plant Pointer to the Plant object performing the growth action.
     */
    void grow(Plant* plant) override;

    /**
     * @brief Virtual destructor for safe cleanup.
     */
    ~DyingState() override {}
private:
    int daysDying=0;
    int daysTakenCareOf=0;
};

#endif //COS214PRAC5_DYINGSTATE_H