#ifndef COS214PRAC5_FERN_H
#define COS214PRAC5_FERN_H
#include "BasePlant.h"

/**
 * @class Fern
 * @brief Concrete Plant class representing fern plants.
 * 
 * Fern plants grow at a moderate rate and implement specific behaviors
 * for watering, string representation, and growth multiplier calculations.
 */
class Fern: public BasePlant {
private:
    const double GROWTH_MULTIPLIER = 1.2;
    /**
     * @brief Growth multiplier specific to Fern plants.
     */
public:
    /**
     * @brief Constructs a Fern object with the given attributes.
     * @param species Name of the species.
     * @param currentEnvironment Current environment index.
     * @param growthLevel Initial growth level.
     * @param isWatered Whether the plant has been watered today.
     * @param growthRate Growth rate multiplier.
     * @param preferredEnvironment Preferred environment type.
     * @param state Initial PlantState object.
     */
    Fern(std::string species, int currentEnvironment, int growthLevel, bool isWatered, double growthRate, int preferredEnvironment, PlantState* state);

    /**
     * @brief Destructor for Fern.
     */
    virtual ~Fern();

    /**
     * @brief Returns a string representation of the Fern plant.
     * @return String description of the Fern object.
     */
    std::string toString() const override;

    /**
     * @brief Waters the Fern plant.
     * 
     * Updates the state and watering flag accordingly.
     */
    void water() override;

    /**
     * @brief Returns the growth multiplier for Fern.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_FERN_H