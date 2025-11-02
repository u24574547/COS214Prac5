#ifndef COS214PRAC5_PLANTDECORATOR_H
#define COS214PRAC5_PLANTDECORATOR_H
#include "Plant.h"

/**
 * @class PlantDecorator
 * @brief Abstract decorator class for extending Plant functionality.
 * 
 * The PlantDecorator class implements the Decorator design pattern by
 * maintaining a reference to a Plant object and delegating most operations
 * to it. Subclasses can override specific methods to add new behavior or
 * modify existing behavior dynamically without altering the base Plant class.
 */

class PlantDecorator: public Plant {
protected:
    Plant* plant; ///< Pointer to the wrapped Plant object.
    double price;
public:
    /**
     * @brief Constructs a PlantDecorator with a given Plant.
     * @param plant Pointer to the Plant object being decorated.
     */
    PlantDecorator(Plant* plant, double price);

    /**
     * @brief Virtual destructor.
     */
    virtual ~PlantDecorator();

    /**
     * @brief Returns a string representation of the decorated plant.
     * 
     * This method must be implemented by all concrete decorators.
     * @return String description of the decorated plant.
     */
    virtual std::string toString() const = 0;

    /**
     * @brief Waters the decorated plant.
     * 
     * Delegates the watering operation to the underlying plant.
     *
     * @param waterAmount Waters the plant with this much water.
     */
    void water(int waterAmount) override;

    /**
     * @brief Sets a new state for the decorated plant.
     * @param newState Pointer to the new PlantState object.
     */
    void setState(PlantState* newState) override;

    /**
     * @brief Marks the decorated plant as sold.
     */
    void markSold() override;

    /**
     * @brief Checks if the decorated plant has been sold.
     * @return True if sold, false otherwise.
     */
    bool isSold() override;

    /**
     * @brief Returns the current growth level of the decorated plant.
     * @return Integer representing growth level.
     */
    int getGrowthLevel() override;

    /**
     * @brief Returns the species name of the decorated plant.
     * @return Species name as a string.
     */
    std::string getSpecies() override;

    /**
     * @brief Checks if the plant has been watered today.
     * @return Amount of water used to water the plant today.
     */
    int getAmountWateredToday() override;

    /**
     * @brief Returns the preferred environment type of the decorated plant.
     * @return Integer representing preferred environment.
     */
    int getPreferredEnvironment() override;

    /**
     * @brief Get how much water is needed per day to make the plant grow.
     * @return Amount of water need by the plant per day.
     */
    int getRequiredWaterPerDay() override;

    /**
     * @brief Retrieves the plant's current environment.
     * @return Integer representing the current environment type.
     */
    int getCurrentEnvironment() override;

    /**
     * @brief Returns the growth multiplier for the decorated plant.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;

    /**
     * @brief Returns the current state name of the decorated plant.
     * @return Current state name as a string.
     */
    std::string getStateName() override;

    /**
     * @brief Returns the price of the plant.
     * @return Price of the plant.
     */
    double getPrice() override;

    /**
     * @brief Sets the current environment for the decorated plant.
     * @param newEnv Integer representing the new environment type.
     */
    void setCurrentEnvironment(int newEnv) override;

    /**
     * @brief Updates the plant's price.
     * @param price A double value representing the new price.
     */
    void setPrice(double price) override;

    /**
     * @brief Ends the day for the decorated plant.
     * 
     * Delegates the end-of-day behavior to the underlying plant.
     */
    void endDay() override;

    /**
     * @brief Returns the base plant of the Plant Decorator.
     * @return BasePlant pointer.
     */
    BasePlant* getBase() override;
};


#endif //COS214PRAC5_PLANTDECORATOR_H