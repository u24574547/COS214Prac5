#ifndef COS214PRAC5_FERTILISER_H
#define COS214PRAC5_FERTILISER_H
#include "PlantDecorator.h"

/**
 * @class Fertiliser
 * @brief Concrete PlantDecorator that adds fertiliser characteristics to a Plant.
 * 
 * Implements additional behavior for decorated plants, e.g., growth enhancement.
 */
class Fertiliser: public PlantDecorator {
public:
    /**
     * @brief Constructs a Fertiliser decorator for the given Plant.
     * @param plant Pointer to the Plant being decorated.
     */
    Fertiliser(Plant* plant, double price=10);

    /**
     * @brief Destructor for Fertiliser decorator.
     */
    virtual ~Fertiliser();

    /**
     * @brief Returns a string representation of the decorated Plant including Fertiliser effects.
     * @return String description of the decorated Plant.
     */
    std::string toString() const;
};


#endif //COS214PRAC5_FERTILISER_H