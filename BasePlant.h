#ifndef COS214PRAC5_BASEPLANT_H
#define COS214PRAC5_BASEPLANT_H
#include "Plant.h"
#include "UnplantedState.h"
#include "SoldState.h"
#include <iostream>
#include <sstream>

#include "Observer.h"

/**
 * @class BasePlant
 * @brief Concrete base class for plants providing core functionality.
 *
 * BasePlant implements common Plant functionality such as sales tracking,
 * growth, environment management, and state handling. Specific plant types
 * can inherit from BasePlant and implement specialized behavior.
 */

class BasePlant : public Plant, public Observer
{
public:
    /**
     * @brief Constructs a BasePlant object with the given attributes.
     *
     * @param species Name of the species.
     * @param currentEnvironment Current environment index.
     * @param growthLevel Initial growth level.
     * @param amountWateredToday Whether the plant has been watered.
     * @param requiredWaterPerDay How much water the plant needs per day to grow.
     * @param growthRate Growth rate multiplier.
     * @param preferredEnvironment Environment type preferred by the plant.
     * @param state Initial state of the plant.
     * @param price Selling price of the plant.
     */
    BasePlant(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel, int amountWateredToday, double growthRate, int preferredEnvironment, PlantState *state, double price);

    /**
     * @brief Destructor for BasePlant.
     */
    virtual ~BasePlant();

    /**
     * @brief Returns a string representation of the plant.
     *
     * Must be implemented by derived concrete plant classes.
     * @return String description of the plant.
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Waters the plant, affecting growth and state.
     *
     * Must be implemented by derived concrete plant classes.
     */
    virtual void water(int waterAmount);

    // Sales functions

    /**
     * @brief Marks the plant as sold.
     */
    void markSold() override;

    /**
     * @brief Checks if the plant has been sold.
     * @return True if sold, false otherwise.
     */
    bool isSold() override;

    // Getters

    /**
     * @brief Returns the name of the current state of the plant.
     * @return State name as string.
     */
    std::string getStateName() override;

    /**
     * @brief Returns the price of the plant.
     * @return Price of the plant.
     */
    double getPrice() override;

    /**
     * @brief Returns the current growth level of the plant.
     * @return Growth level as integer.
     */
    int getGrowthLevel() override;

    /**
     * @brief Returns the species of the plant.
     * @return Species name as string.
     */
    std::string getSpecies() override;

    /**
     * @brief Returns the preferred environment of the plant.
     * @return Integer representing the preferred environment.
     */
    int getPreferredEnvironment() override;

    /**
     * @brief Retrieves the plant's current environment.
     * @return Integer representing the current environment type.
     */
    int getCurrentEnvironment();

    /**
     * @brief Returns the growth multiplier for the plant.
     *
     * Must be implemented by derived concrete plant classes.
     * @return Growth multiplier as double.
     */
    virtual double getGrowthMultiplier() = 0;

    /**
     * @brief Get how much water was used to water this plant today.
     * @return Amount of water used to water the plant today.
     */
    int getAmountWateredToday() override;

    /**
     * @brief Get how much water is needed per day to make the plant grow.
     * @return Amount of water need by the plant per day.
     */
    int getRequiredWaterPerDay() override;

    // Setters

    /**
     * @brief Updates the plant's state.
     * @param newState Pointer to the new PlantState object.
     */
    void setState(PlantState *newState) override;

    /**
     * @brief Sets the current environment for the plant.
     * @param newEnv Integer representing the new environment.
     */
    void setCurrentEnvironment(int newEnv) override;

    /**
     * @brief Updates the plant's price.
     * @param price A double value representing the new price.
     */
    void setPrice(double price) override;

    /**
     * @brief Ends the day for the plant, updating growth and state.
     */
    void endDay() override;

    /**
     * @brief implementation for the update function as part of the observer design pattern
     *
     */
    void update() override;

    /**
     * @brief Returns the base plant of the Plant Decorator.
     * @return BasePlant pointer.
     */
    BasePlant* getBase() override;

    /**
     * @brief fetches the type of Observer as a string
     *@return a string ("Plant" or "Employee")
     */
    std::string getObserverType() override;

    /**
     * @brief Returns the sub-kingdom of the plant.
     * @return std::string representing the sub-kingdom.
     */
    virtual std::string getSubKingdom() = 0;

private:
    /**
     * @brief Handles plant growth logic for the day.
     */
    void grow();

protected:
    int growthLevel;          ///< Current growth level
    std::string species;      ///< Species name
    int amountWateredToday;   ///< How much water was used to water this plant
    int requiredWaterPerDay;  ///< How much water is needed by this plant per day to grow
    double growthRate;        ///< Growth rate multiplier
    int preferredEnvironment; ///< Preferred environment type
    int currentEnvironment;   ///< Current environment type
    PlantState *state;        ///< Current state object
    double price;             ///< Price of the plant
};

#endif // COS214PRAC5_BASEPLANT_H