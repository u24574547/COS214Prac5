#ifndef GiftBuilder_H
#define GiftBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class GiftBuilder : public Builder {
private:
    /**
     * @brief The DisplayBundle being constructed by this builder.
     */
    DisplayBundle* bundle;
public:
    /**
     * @brief Constructs a GiftBuilder and initializes internal state.
     */
    GiftBuilder();

    /**
     * @brief Resets the builder to start constructing a new gift bundle.
     */
    void reset() override;

    /**
     * @brief Adds a basic plant to the gift bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addBasicPlant(Plant* plant) override;

    /**
     * @brief Adds a decorative plant to the gift bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addDecorativePlant(Plant* plant) override;

    /**
     * @brief Adds a fertilised plant to the gift bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFertilisedPlant(Plant* plant) override;
    /**
     * @brief Adds a frost-protected plant to the gift bundle.
     * 
     * @param plant Pointer to the Plant object to add.
     */
    void addFrostNetPlant(Plant* plant) override;

    /**
     * @brief Retrieves the constructed gift bundle.
     * 
     * @return Pointer to the DisplayBundle representing the completed gift bundle.
     */
    DisplayBundle* getResult() override;

    /**
     * @brief Destructor to clean up allocated resources.
     */
    ~GiftBuilder();
};

#endif
