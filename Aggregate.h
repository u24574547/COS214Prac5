#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"
#include <vector>
using namespace std;

/**
 * @brief The Aggregate class defines an interface for collections
 *        that can be traversed using an Iterator.
 *
 * This is a template class that represents a generic collection
 * of elements of type T. It provides a method to create an iterator
 * for external traversal and an accessor for the underlying items.
 *
 * @tparam T The type of elements stored in the collection.
 */
template <typename T>
class Aggregate {
    public:
        /**
         * @brief Constructs an Aggregate with the given items.
         */
        Aggregate(){};

        /**
         * @brief Virtual destructor.
         */
        virtual ~Aggregate(){};

        /**
         * @brief Creates an iterator to traverse the collection.
         * @return A pointer to an Iterator object for this Aggregate.
         */
        virtual Iterator<T>* createIterator() = 0;

        /**
         * @brief Provides access to the underlying items.
         * @return A reference to the internal vector of items.
         * @note Consider making this pure virtual if derived classes
         *       manage their own collections.
         */
        std::vector<T>& getItems() {return items;};
    protected:
        /**
         * @brief The internal collection of elements.
         */
        vector<T> items;
};

#endif