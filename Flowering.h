#ifndef COS214PRAC5_FLOWERING_H
#define COS214PRAC5_FLOWERING_H
#include "BasePlant.h"

/**
 * @class Flowering
 * @brief Concrete Plant class representing flowering plants.
 * 
 * Flowering plants grow more slowly and implement behaviors for watering,
 * string representation, and growth multiplier calculations.
 */
class Flowering: public BasePlant {
private:
    /**
     * @brief Growth multiplier specific to Flowering plants.
     */
    const double GROWTH_MULTIPLIER = 0.8;
public:
    /**
     * @brief Constructs a Flowering object with the given attributes.
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
    Flowering(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState(), double price=19.99);

    /**
     * @brief Destructor for Flowering.
     */
    ~Flowering() override;

    /**
     * @brief Returns a string representation of the Flowering plant.
     * @return String description of the Flowering object.
     */
    std::string toString() const override;

    /**
     * @brief Returns the growth multiplier for Flowering plants.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_FLOWERING_H