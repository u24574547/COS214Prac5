#ifndef PLANT_H
#define PLANT_H

#include "PlantState.h"
#include "Bundle.h"
#include <string>

/**
 * @class Plant
 * @brief Abstract base class representing a plant in the system.
 * 
 * Plant is a Bundle (Composite pattern) and defines the interface
 * for all plant types. It supports growth, watering, sales tracking,
 * and state management using the State pattern.
 */

class Plant : public Bundle{
public:
    /**
     * @brief Constructs a Plant object.
     */
    Plant();

    /**
     * @brief Virtual destructor for proper cleanup of derived plant classes.
     */
    virtual ~Plant();

    /**
     * @brief Returns a string representation of the plant.
     * @return A descriptive string of the plant.
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Waters the plant, affecting growth and state.
     */
    virtual void water(int waterAmount) = 0;

    // Sales-related functions

    /**
     * @brief Marks the plant as sold.
     */
    virtual void markSold() = 0;

    /**
     * @brief Checks if the plant has been sold.
     * @return True if sold, false otherwise.
     */
    virtual bool isSold() = 0;

    // Getters

    /**
     * @brief Retrieves the plant's growth level.
     * @return Integer representing growth level.
     */
    virtual int getGrowthLevel() = 0;

    /**
     * @brief Retrieves the plant's species.
     * @return Species name as a string.
     */
    virtual std::string getSpecies() = 0;

    /**
     * @brief Checks if the plant has been watered today.
     * @return Amount of water used to water the plant today.
     */
    virtual int getAmountWateredToday() = 0;

    /**
     * @brief Get how much water is needed per day to make the plant grow.
     * @return Amount of water need by the plant per day.
     */
    virtual int getRequiredWaterPerDay()=0;

    /**
     * @brief Retrieves the plant's preferred environment.
     * @return Integer representing the preferred environment type.
     */
    virtual int getPreferredEnvironment() = 0;

    /**
     * @brief Retrieves the plant's current environment.
     * @return Integer representing the current environment type.
     */
    virtual int getCurrentEnvironment() = 0;

    /**
     * @brief Retrieves the plant's growth multiplier.
     * @return Growth multiplier as a double.
     */
    virtual double getGrowthMultiplier() = 0;

    /**
     * @brief Returns the current state name of the plant.
     * @return Name of the current PlantState.
     */
    virtual std::string getStateName() = 0;

    // Setters

    /**
     * @brief Sets the current environment of the plant.
     * @param newEnv Integer representing the new environment.
     */
    virtual void setCurrentEnvironment(int newEnv) = 0;

    /**
     * @brief Updates the plant's state.
     * @param newState Pointer to the new PlantState object.
     */
    virtual void setState(PlantState* newState) = 0;

    /**
     * @brief Ends the day for the plant, updating state and growth as necessary.
     */
    virtual void endDay() = 0;
};

#endif // PLANT_H
