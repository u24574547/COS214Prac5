#ifndef PLANTSTATE_H
#define PLANTSTATE_H

#include <iostream>
#include <string>

class Plant; ///< Forward declaration of Plant

/**
 * @class PlantState
 * @brief Abstract base class representing the state of a plant.
 * 
 * Each concrete state (e.g., SeedlingState, MatureState) inherits from this
 * class and defines specific behavior for growth and state transitions.
 */
class PlantState {
public:
    /**
     * @brief Transition the plant to the next appropriate state.
     * 
     * Concrete states implement this to handle conditions for moving
     * to the next stage in the plant's lifecycle.
     * 
     * @param plant Pointer to the Plant whose state may change.
     */
    virtual void nextState(Plant* plant) = 0;

    /**
     * @brief The plant starts dying when its growthLevel decreases.
     *
     * Concrete states implement this to handle conditions for dying.
     *
     * @param plant Pointer to the Plant that begins dying.
     */
    virtual void startDying(Plant* plant);

    /**
     * @brief Handles growth of the plant in this state.
     * 
     * Typically called when the plant is watered. Concrete states will
     * implement this to adjust the plant's growth level and possibly trigger
     * a state transition.
     * 
     * @param plant Pointer to the Plant object being grown.
     */
    virtual void grow(Plant* plant) = 0;

    /**
     * @brief Returns the name of the current state.
     * 
     * @return A string representing the state name.
     */
    virtual std::string getName() = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~PlantState() {}
protected:
    int oldGrowthLevel=0;
};

#endif // PLANTSTATE_H
