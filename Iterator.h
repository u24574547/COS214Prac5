#ifndef ITERATOR_H
#define ITERATOR_H


template<typename T> class Aggregate;
#include <vector>

/**
 * @brief The Iterator class defines the interface for traversing
 *        elements in an Aggregate without exposing its underlying structure.
 * 
 * This is a template class that provides a set of methods for controlled
 * sequential access to elements within an Aggregate. Concrete subclasses
 * will implement these traversal methods for specific collection types.
 * 
 * @tparam T The type of elements the iterator traverses.
 */
template <typename T>
class Iterator {
public:
    /**
     * @brief Constructs an Iterator associated with a given Aggregate.
     * @param aggregate A pointer to the Aggregate to be traversed.
     */
    Iterator(Aggregate<T> *aggregate) : aggregate(aggregate){};

    /**
     * @brief Virtual destructor.
     */    
    virtual ~Iterator(){};

    /**
     * @brief Positions the iterator at the first element.
     * @return The first element in the Aggregate.
     * @note Consider changing the return type to T& in the future
     *       for improved efficiency and consistency.
     */
    virtual T first() = 0;

    /**
     * @brief Advances the iterator to the next element.
     * @return The next element in the Aggregate.
     */
    virtual T next() = 0;

    /**
     * @brief Retrieves the current element in the Aggregate.
     * @return The current element.
     */  
    virtual T current() = 0;

    /**
     * @brief Checks whether the iterator has completed traversal.
     * @return True if there are no more elements, false otherwise.
     */
    virtual bool isDone() = 0;

    /**
     * @brief Positions the iterator at the last element.
     * @return The last element in the Aggregate.
     */
    virtual T last() = 0;
protected:
    /**
     * @brief The Aggregate being traversed by this iterator.
     */
    Aggregate<T>* aggregate;
};

#endif