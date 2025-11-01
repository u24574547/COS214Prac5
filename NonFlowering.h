#ifndef COS214PRAC5_NONFLOWERING_H
#define COS214PRAC5_NONFLOWERING_H
#include "BasePlant.h"

/**
 * @class NonFlowering
 * @brief Concrete Plant class representing non-flowering plants.
 * 
 * Non-flowering plants have a neutral growth rate and implement behaviors
 * for watering, string representation, and growth multiplier calculations.
 */
class NonFlowering: public BasePlant {
private:
    /**
     * @brief Growth multiplier specific to NonFlowering plants.
     */
    const double GROWTH_MULTIPLIER = 1.0;
public:
    /**
     * @brief Constructs a NonFlowering object with the given attributes.
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
    NonFlowering(std::string species, int currentEnvironment, int requiredWaterPerDay, int growthLevel=0,  int amountWateredToday=0, double growthRate=10.0, int preferredEnvironment=0, PlantState* state = new UnplantedState(), double price=19.99);

    /**
     * @brief Destructor for NonFlowering.
     */
    virtual ~NonFlowering();

    /**
     * @brief Returns a string representation of the NonFlowering plant.
     * @return String description of the NonFlowering object.
     */
    std::string toString() const override;

    /**
     * @brief Returns the growth multiplier for NonFlowering plants.
     * @return Growth multiplier as a double.
     */
    double getGrowthMultiplier() override;
};


#endif //COS214PRAC5_NONFLOWERING_H