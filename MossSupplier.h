#ifndef COS214PRAC5_MOSSSUPPLIER_H
#define COS214PRAC5_MOSSSUPPLIER_H
#include "Supplier.h"


class MossSupplier: public Supplier {
public:
    MossSupplier();
    virtual ~MossSupplier();
    virtual Plant* createPlant();
};


#endif //COS214PRAC5_MOSSSUPPLIER_H