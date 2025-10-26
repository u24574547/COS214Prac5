#ifndef BUILDER_H
#define BUILDER_H

#include <string>
#include "Plant.h"

// Forward declaration
class DisplayBundle;

/**
 * @class Builder
 * @brief Abstract interface for constructing plant bundles (Builder pattern).
 * 
 * The Builder class defines the interface for creating various parts of a plant bundle.
 * Concrete builders will implement these methods to assemble bundles according to different rules.
 */
class Builder {
public:
    /**
     * @brief Resets the builder to start constructing a new bundle.
     */
    virtual void reset() = 0;

    /**
     * @brief Adds a basic plant to the bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    virtual void addBasicPlant(Plant* plant) = 0;

    /**
     * @brief Adds a decorative plant to the bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    virtual void addDecorativePlant(Plant* plant) = 0;

    /**
     * @brief Adds a fertilised plant to the bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    virtual void addFertilisedPlant(Plant* plant) = 0;

    /**
     * @brief Adds a frost-protected plant to the bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    virtual void addFrostNetPlant(Plant* plant) = 0;

    /**
     * @brief Retrieves the final constructed bundle.
     * 
     * @return Pointer to a DisplayBundle object representing the completed bundle.
     */
    virtual DisplayBundle* getResult() = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Builder() {}
};

#endif
