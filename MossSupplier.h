#ifndef COS214PRAC5_MOSSSUPPLIER_H
#define COS214PRAC5_MOSSSUPPLIER_H
#include "Supplier.h"
#include "Moss.h"
#include "UnplantedState.h"

class MossSupplier: public Supplier {
public:
    MossSupplier();
    virtual ~MossSupplier();
    Plant* getPlant() override;
};


#endif //COS214PRAC5_MOSSSUPPLIER_H