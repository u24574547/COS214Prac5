#ifndef COS214PRAC5_MOSS_H
#define COS214PRAC5_MOSS_H
#include "BasePlant.h"

/**
 * @class Moss
 * @brief Concrete Plant class representing moss plants.
 * 
 * Moss grows quickly and has a specific growth multiplier. Implements
 * Plant-specific behavior for watering, string representation, and growth calculations.
 */
class Moss: public BasePlant {
private:
    /**
     * @brief Growth multiplier specific to Moss plants.
     */
    const double GROWTH_MULTIPLIER = 1.5;
public:
    /**
     * @brief Constructs a Moss object with the given attributes.
     * @param species Name of the species.
     * @param currentEnvironment Current environment index.
     * @param growthLevel Initial growth level.
     * @param amountWateredToday How much water was used to water this plant.
     * @param requiredWaterPerDay How much water the plant needs per day to grow.
     * @param growthRate Growth rate multiplier.
     * @param preferredEnvironment Preferred environment type.
     * @param state Initial PlantState object.
     * @param price Selling price of the plant.
     */
    Moss(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState(), double price=19.99);

    /**
     * @brief Destructor for Moss.
     */
    virtual ~Moss();

    /**
     * @brief Returns a string representation of the Moss plant.
     * @return String description of the Moss object.
     */
    std::string toString() const override;

    /**
     * @brief Returns the growth multiplier for Moss.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_MOSS_H