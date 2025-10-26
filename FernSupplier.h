#ifndef COS214PRAC5_FERNSUPPLIER_H
#define COS214PRAC5_FERNSUPPLIER_H
#include "Supplier.h"
#include "Fern.h"
#include "UnplantedState.h"

/**
 * @class FernSupplier
 * @brief Concrete Supplier that produces Fern Plant objects.
 * 
 * Configures Fern plants with the appropriate initial state and attributes.
 */
class FernSupplier: public Supplier {
public:
    /**
     * @brief Constructs a FernSupplier object.
     */
    FernSupplier();

    /**
     * @brief Destructor for FernSupplier.
     */
    virtual ~FernSupplier();

    /**
     * @brief Returns a new Fern Plant object.
     * @return Pointer to the created Fern plant.
     */
    Plant* getPlant() override;
};


#endif //COS214PRAC5_FERNSUPPLIER_H