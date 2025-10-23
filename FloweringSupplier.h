#ifndef COS214PRAC5_FLOWERINGSUPPLIER_H
#define COS214PRAC5_FLOWERINGSUPPLIER_H
#include "Plant.h"
#include "Supplier.h"


class FloweringSupplier: public Supplier {
public:
    FloweringSupplier();
    virtual ~FloweringSupplier();
    virtual Plant* createPlant();
};


#endif //COS214PRAC5_FLOWERINGSUPPLIER_H