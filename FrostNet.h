#ifndef COS214PRAC5_FROSTNET_H
#define COS214PRAC5_FROSTNET_H
#include "PlantDecorator.h"

/**
 * @class FrostNet
 * @brief Concrete PlantDecorator that adds frost net protection to a Plant.
 * 
 * Implements additional behavior for decorated plants, e.g., frost resistance.
 */
class FrostNet: public PlantDecorator {
public:
    /**
     * @brief Constructs a FrostNet decorator for the given Plant.
     * @param plant Pointer to the Plant being decorated.
     */
    FrostNet(Plant* plant, double price=5);

    /**
     * @brief Destructor for FrostNet decorator.
     */
    virtual ~FrostNet();

    /**
     * @brief Returns a string representation of the decorated Plant including FrostNet effects.
     * @return String description of the decorated Plant.
     */
    std::string toString() const;
};


#endif //COS214PRAC5_FROSTNET_H