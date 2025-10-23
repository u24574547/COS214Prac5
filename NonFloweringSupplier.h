#ifndef COS214PRAC5_NONFLOWERINGSUPPLIER_H
#define COS214PRAC5_NONFLOWERINGSUPPLIER_H
#include "Supplier.h"


class NonFloweringSupplier: public Supplier {
public:
    NonFloweringSupplier();
    virtual ~NonFloweringSupplier();
    virtual Plant* createPlant();
};


#endif //COS214PRAC5_NONFLOWERINGSUPPLIER_H