#ifndef COS214PRAC5_NONFLOWERINGSUPPLIER_H
#define COS214PRAC5_NONFLOWERINGSUPPLIER_H
#include "Supplier.h"
#include "NonFlowering.h"
#include "UnplantedState.h"

class NonFloweringSupplier: public Supplier {
public:
    NonFloweringSupplier();
    virtual ~NonFloweringSupplier();
    virtual Plant* getPlant();
};


#endif //COS214PRAC5_NONFLOWERINGSUPPLIER_H