#ifndef TerrariumBuilder_H
#define TerrariumBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

/**
 * @class TerrariumBuilder
 * @brief Concrete builder for constructing terrarium-style plant bundles.
 * 
 * This builder implements the Builder interface to assemble a plant bundle
 * optimized for terrarium display. It maintains a DisplayBundle object
 * that is built step by step according to terrarium specifications.
 */
class TerrariumBuilder : public Builder {
private:
    /**
     * @brief The DisplayBundle being constructed by this builder.
     */
    DisplayBundle* bundle;
public:
    /**
     * @brief Constructs a TerrariumBuilder and initializes internal state.
     */
    TerrariumBuilder();

    /**
     * @brief Resets the builder to start constructing a new terrarium bundle.
     */
    void reset() override;

    /**
     * @brief Adds a basic plant to the terrarium bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addBasicPlant(Plant* plant) override;

    /**
     * @brief Adds a decorative plant to the terrarium bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addDecorativePlant(Plant* plant) override;

    /**
     * @brief Adds a fertilised plant to the terrarium bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFertilisedPlant(Plant* plant) override;

    /**
     * @brief Adds a frost-protected plant to the terrarium bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFrostNetPlant(Plant* plant) override;
    /**
     * @brief Retrieves the constructed terrarium bundle.
     * 
     * @return Pointer to the DisplayBundle representing the completed terrarium bundle.
     */
    DisplayBundle* getResult() override;

    /**
     * @brief Destructor to clean up allocated resources.
     */
    ~TerrariumBuilder();
};

#endif
