#ifndef INVENTORY_H
#define INVENTORY_H

#include "Aggregate.h"
#include "Command.h"
#include "Plant.h"
#include "PlantIterator.h"
#include <string>

/**
 * @class Inventory
 * @brief Represents a collection (aggregate) of Plant objects.
 *
 * The Inventory class stores and manages a collection of Plant pointers.
 * It provides operations to add and retrieve plants, as well as create
 * an iterator (PlantIterator) to traverse the collection.
 */
class Inventory : public Aggregate<Plant*> {
    public:
        /**
         * @brief Constructs an empty Inventory.
         */
        Inventory() : Aggregate(plants) {};

        /**
         * @brief Destroys the Inventory and cleans up resources.
         */
        ~Inventory(){};

        /**
         * @brief Creates an iterator to traverse the collection of plants.
         * @return A pointer to an Iterator<Plant*> for this Inventory.
         */
        Iterator<Plant*>* createIterator() override;

        /**
         * @brief Adds a plant to the inventory.
         * @param plant Pointer to the Plant object to be added.
         */
        void addPlant(Plant* plant);

        /**
         * @brief Retrieves a plant from the inventory by name.
         *
         * @param name The name of the plant to find.
         * @return Pointer to the Plant object if found, otherwise nullptr.
         */
        Plant* getPlant(string name);

        void water(int environment);

    private:
        /**
         * @brief The underlying container that holds Plant pointers.
         */
        vector<Plant*> plants;
};

#endif