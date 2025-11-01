#ifndef COS214PRAC5_Ribbon_H
#define COS214PRAC5_Ribbon_H
#include "PlantDecorator.h"

/**
 * @class Ribbon
 * @brief Concrete PlantDecorator that adds frost net protection to a Plant.
 * 
 * Implements additional behavior for decorated plants, e.g., frost resistance.
 */
class Ribbon: public PlantDecorator {
public:
    /**
     * @brief Constructs a Ribbon decorator for the given Plant.
     * @param plant Pointer to the Plant being decorated.
     */
    Ribbon(Plant* plant, double price=5);

    /**
     * @brief Destructor for Ribbon decorator.
     */
    virtual ~Ribbon();

    /**
     * @brief Returns a string representation of the decorated Plant including Ribbon effects.
     * @return String description of the decorated Plant.
     */
    std::string toString() const;
};


#endif //COS214PRAC5_Ribbon_H