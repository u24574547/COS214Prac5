#ifndef FrostReadyBuilder_H
#define FrostReadyBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

/**
 * @class FrostReadyBuilder
 * @brief Concrete builder for constructing frost-ready plant bundles.
 * 
 * This builder implements the Builder interface to assemble a plant bundle
 * that is protected against frost. It maintains a DisplayBundle object
 * which is built step by step according to frost-ready specifications.
 */
class FrostReadyBuilder : public Builder {
private:
    /**
     * @brief The DisplayBundle being constructed by this builder.
     */
    DisplayBundle* bundle;
public:
    /**
     * @brief Constructs a FrostReadyBuilder and initializes internal state.
     */
    FrostReadyBuilder();

    /**
     * @brief Resets the builder to start constructing a new frost-ready bundle.
     */
    void reset() override;

    /**
     * @brief Adds a basic plant to the frost-ready bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addBasicPlant(Plant* plant) override;

    /**
     * @brief Adds a decorative plant to the frost-ready bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addDecorativePlant(Plant* plant) override;

    /**
     * @brief Adds a fertilised plant to the frost-ready bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFertilisedPlant(Plant* plant) override;

    /**
     * @brief Adds a frost-protected plant to the frost-ready bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFrostNetPlant(Plant* plant) override;

    /**
     * @brief Retrieves the constructed frost-ready bundle.
     * 
     * @return Pointer to the DisplayBundle representing the completed frost-ready bundle.
     */
    DisplayBundle* getResult() override;

    /**
     * @brief Destructor to clean up allocated resources.
     */
    ~FrostReadyBuilder();
};

#endif
