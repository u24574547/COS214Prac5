#ifndef COS214PRAC5_FLOWERINGSUPPLIER_H
#define COS214PRAC5_FLOWERINGSUPPLIER_H
#include "Plant.h"
#include "Supplier.h"
#include "Flowering.h"
#include "UnplantedState.h"


class FloweringSupplier: public Supplier {
public:
    FloweringSupplier();
    virtual ~FloweringSupplier();
    Plant* getPlant() override;
};


#endif //COS214PRAC5_FLOWERINGSUPPLIER_H