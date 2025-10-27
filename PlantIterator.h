#ifndef PLANTITERATOR_H
#define PLANTITERATOR_H

#include "Iterator.h"
#include "Plant.h"
//remove if there's no circular includes
class Inventory;

/**
 * @class PlantIterator
 * @brief Concrete iterator for traversing an Inventory collection of Plant objects.
 * 
 * This iterator implements the Iterator interface for Plant* types, providing
 * sequential access to the plants stored in an Inventory (Aggregate<Plant*>).
 */
class PlantIterator : public Iterator<Plant*> {
    public:
        /**
         * @brief Constructs a PlantIterator for the given collection of plants.
         * 
         * @param plants Pointer to the Aggregate<Plant*> to traverse.
         */
        PlantIterator(Aggregate<Plant*>* plants);

        /**
         * @brief Destroys the PlantIterator and cleans up resources.
         */
        ~PlantIterator();

        /**
         * @brief Positions the iterator at the first plant.
         * @return Pointer to the first Plant object.
         */
        Plant* first() override;

        /**
         * @brief Advances the iterator to the next plant.
         * @return Pointer to the next Plant object.
         */
        Plant* next() override;

        /**
         * @brief Retrieves the current plant.
         * @return Pointer to the current Plant object.
         */
        Plant* current() override;

        /**
         * @brief Positions the iterator at the last plant.
         * @return Pointer to the last Plant object.
         */
        Plant* last() override;

        /**
         * @brief Checks if the iterator has traversed all plants.
         * @return True if the end of the collection is reached, false otherwise.
         */
        bool isDone() override;

    private:
        /**
         * @brief Local copy of the plants to iterate over.
         */
        std::vector<Plant*>& plants;

        /**
         * @brief Current index of the iterator within the plants vector.
         */
        std::size_t index;
};

#endif