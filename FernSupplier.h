#ifndef COS214PRAC5_FERNSUPPLIER_H
#define COS214PRAC5_FERNSUPPLIER_H
#include "Supplier.h"


class FernSupplier: public Supplier {
public:
    FernSupplier();
    virtual ~FernSupplier();
    virtual Plant* createPlant();
};


#endif //COS214PRAC5_FERNSUPPLIER_H