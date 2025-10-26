#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "Builder.h"
#include "Inventory.h"

/**
 * @class Director
 * @brief Constructs various bundles of plants using the Builder pattern.
 * 
 * The Director class directs the construction process by invoking
 * different build steps on a Builder object. It uses an Inventory
 * to select plants and create predefined bundles.
 */
class Director {
private:
    /**
     * @brief Pointer to the Builder used to construct bundles.
     */
    Builder* builder;

    /**
     * @brief Pointer to the Inventory from which plants are selected.
     */
    Inventory* inventory;
public:
    /**
     * @brief Constructs a Director with a given Builder and Inventory.
     * 
     * @param b Pointer to the Builder object.
     * @param i Pointer to the Inventory object.
     */
    Director(Builder* b, Inventory* i);

    /**
     * @brief Constructs a gift-ready plant bundle.
     */
    void constructGiftBundle();

    /**
     * @brief Constructs a frost-ready plant bundle.
     */
    void constructFrostReadyBundle();

    /**
     * @brief Constructs a terrarium-style plant bundle.
     */
    void constructTerrariumBundle();
};

#endif
