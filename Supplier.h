#ifndef COS214PRAC5_SUPPLIER_H
#define COS214PRAC5_SUPPLIER_H
#include "Plant.h"


class Supplier {
public:
    Supplier();
    virtual ~Supplier();
    void setState(PlantState& state);
    Plant* getPlant();
protected:
    virtual Plant* createPlant()=0;
    Plant* plant;
private:
    PlantState& state;
};


#endif //COS214PRAC5_SUPPLIER_H