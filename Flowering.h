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
     * @param isWatered Whether the plant has been watered today.
     * @param growthRate Growth rate multiplier.
     * @param preferredEnvironment Preferred environment type.
     * @param state Initial PlantState object.
     */
    Flowering(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);

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
     * @brief Waters the Flowering plant.
     * 
     * Updates the state and watering flag accordingly.
     */
    void water() override;

    /**
     * @brief Returns the growth multiplier for Flowering plants.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_FLOWERING_H