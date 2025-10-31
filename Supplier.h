#ifndef COS214PRAC5_SUPPLIER_H
#define COS214PRAC5_SUPPLIER_H
#include "Plant.h"
#include "SeedlingState.h"
#include "UnplantedState.h"

/**
 * @class Supplier
 * @brief Abstract class representing a supplier of Plant objects.
 * 
 * Handles the creation and configuration of Plant objects, including
 * setting growth levels, environment, state, and decorators like Fertiliser or FrostNet.
 */

class Supplier {
public:
    /**
     * @brief Constructs a Supplier object.
     */
    Supplier();

    /**
     * @brief Destructor for Supplier.
     */
    virtual ~Supplier();

    /** @name Setters */
    ///@{
    void setState(PlantState* state);           ///< Set the current PlantState.
    void setGrowthLevel(int growthLevel);       ///< Set the plant's growth level.
    void setSpecies(std::string species);       ///< Set the plant's species name.
    void setAmountWateredToday(int amountWateredToday);    ///< Set how many ml of water was used to water the plant today.
    void setRequiredWaterPerDay(int requiredWaterPerDay);  ///< Set much water is needed by this plant per day to grow
    void setGrowthRate(double growthRate);      ///< Set the plant's growth rate.
    void setPreferredEnvironment(int env);      ///< Set the plant's preferred environment type.
    void setCurrentEnvironment(int env);        ///< Set the plant's current environment type.
    ///@}

    /** @name Getters */
    ///@{
    PlantState* getState();                     ///< Get the current PlantState.
    int getGrowthLevel();                       ///< Get the plant's growth level.
    std::string getSpecies();                   ///< Get the plant's species name.
    int getAmountWateredToday();                ///< Get how many ml of water was used to water the plant today.
    int getRequiredWaterPerDay();               ///< Get how much water is needed by this plant per day to grow.
    double getGrowthRate();                     ///< Get the plant's growth rate.
    int getPreferredEnvironment();              ///< Get the plant's preferred environment type.
    int getCurrentEnvironment();                ///< Get the plant's current environment type.
    ///@}

    /**
     * @brief Decorates a plant with fertiliser.
     * @param plant Pointer to the Plant to decorate.
     * @return Decorated Plant pointer.
     */
    Plant* addFertiliser(Plant* plant);

    /**
     * @brief Decorates a plant with a frost net.
     * @param plant Pointer to the Plant to decorate.
     * @return Decorated Plant pointer.
     */
    Plant* addFrostNet(Plant* plant);

    /**
     * @brief Abstract method to return a Plant object.
     * @return Pointer to the created Plant.
     */
    virtual Plant* getPlant() = 0;
protected:
    int growthLevel;                 ///< Current growth level of the plant.
    std::string species;             ///< Species name of the plant.
    int amountWateredToday;          ///< How much the plant has been watered today.
    int requiredWaterPerDay;         ///< How much water is needed by this plant per day to grow.
    double growthRate;               ///< Growth rate multiplier.
    int preferredEnvironment;        ///< Preferred environment type.
    int currentEnvironment;          ///< Current environment type.
    PlantState* state;               ///< Current state of the plant.
};


#endif //COS214PRAC5_SUPPLIER_H