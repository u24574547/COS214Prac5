#ifndef COS214PRAC5_MOSSSUPPLIER_H
#define COS214PRAC5_MOSSSUPPLIER_H
#include "Supplier.h"
#include "Moss.h"
#include "UnplantedState.h"

/**
 * @class MossSupplier
 * @brief Concrete Supplier that produces Moss Plant objects.
 * 
 * Configures Moss plants with the appropriate initial state and attributes.
 */
class MossSupplier: public Supplier {
public:
    /**
     * @brief Constructs a MossSupplier object.
     */
    MossSupplier();

    /**
     * @brief Destructor for MossSupplier.
     */
    virtual ~MossSupplier();

    /**
     * @brief Returns a new Moss Plant object.
     * @return Pointer to the created Moss plant.
     */
    Plant* getPlant() override;
};


#endif //COS214PRAC5_MOSSSUPPLIER_H