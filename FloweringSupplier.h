#ifndef COS214PRAC5_FLOWERINGSUPPLIER_H
#define COS214PRAC5_FLOWERINGSUPPLIER_H
#include "Plant.h"
#include "Supplier.h"
#include "Flowering.h"
#include "UnplantedState.h"

/**
 * @class FloweringSupplier
 * @brief Concrete Supplier that produces Flowering Plant objects.
 * 
 * Configures Flowering plants with the appropriate initial state and attributes.
 */
class FloweringSupplier: public Supplier {
public:
    /**
     * @brief Constructs a FloweringSupplier object.
     */
    FloweringSupplier();

    /**
     * @brief Destructor for FloweringSupplier.
     */
    virtual ~FloweringSupplier();

    /**
     * @brief Returns a new Flowering Plant object.
     * @return Pointer to the created Flowering plant.
     */
    Plant* getPlant() override;
};


#endif //COS214PRAC5_FLOWERINGSUPPLIER_H