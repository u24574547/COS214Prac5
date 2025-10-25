#ifndef COS214PRAC5_FERNSUPPLIER_H
#define COS214PRAC5_FERNSUPPLIER_H
#include "Supplier.h"
#include "Fern.h"
#include "UnplantedState.h"


class FernSupplier: public Supplier {
public:
    FernSupplier();
    virtual ~FernSupplier();
    Plant* getPlant() override;
};


#endif //COS214PRAC5_FERNSUPPLIER_H