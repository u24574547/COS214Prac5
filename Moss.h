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
     * @param isWatered Whether the plant has been watered today.
     * @param growthRate Growth rate multiplier.
     * @param preferredEnvironment Preferred environment type.
     * @param state Initial PlantState object.
     */
    Moss(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);

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
     * @brief Waters the Moss plant.
     * 
     * Updates the state and watering flag accordingly.
     */
    void water() override;

    /**
     * @brief Returns the growth multiplier for Moss.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_MOSS_H