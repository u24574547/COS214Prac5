#ifndef INVENTORY_H
#define INVENTORY_H

#include "Aggregate.h"
#include "Command.h"
#include "Plant.h"
#include "PlantIterator.h"
#include "Day.h"
#include <string>
#include <map>

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
        Inventory() : Aggregate<Plant*>(){};
        Inventory(std::vector<Plant*> plants) : Aggregate(plants) {};

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

        /**
             * @brief Retrieves a plant from the inventory by name that is ready for sale.
             *
             * @param name The name of the plant to find.
             * @return Pointer to the Plant object if found and ready for sale, otherwise nullptr.
             */
        Plant* getReadyForSalePlant(string name);

        /**
         * @brief Links each plant with the passed in Day object.
         *
         * @param time The Day object that controls time.
         */
        void observeTime(Day* time);

        /**
         * @brief Waters all plants in the specified environment.
         *
         * @param environment The environment to have its plants watered.
         */
        void water(int environment);
        /**
         * @brief removes all the plants in the dead state from the inventory
         * 
         */
        void removeDead();

        /**
        * @brief Creates a summary of the stock availability
        *
        * @param type The type of plant for which the stock summary is being generated.
        * @return an std::string representing the stock summary.
        */
        std::string stockSummary(std::string type);
};

#endif