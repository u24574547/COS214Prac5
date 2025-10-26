#ifndef COS214PRAC5_NONFLOWERINGSUPPLIER_H
#define COS214PRAC5_NONFLOWERINGSUPPLIER_H
#include "Supplier.h"
#include "NonFlowering.h"
#include "UnplantedState.h"

/**
 * @class NonFloweringSupplier
 * @brief Concrete Supplier that produces NonFlowering Plant objects.
 * 
 * Configures NonFlowering plants with the appropriate initial state and attributes.
 */
class NonFloweringSupplier: public Supplier {
public:
    /**
     * @brief Constructs a NonFloweringSupplier object.
     */
    NonFloweringSupplier();

    /**
     * @brief Destructor for NonFloweringSupplier.
     */
    virtual ~NonFloweringSupplier();

    /**
     * @brief Returns a new NonFlowering Plant object.
     * @return Pointer to the created NonFlowering plant.
     */
    virtual Plant* getPlant();
};


#endif //COS214PRAC5_NONFLOWERINGSUPPLIER_H