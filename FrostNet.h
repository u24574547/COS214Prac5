#ifndef COS214PRAC5_FROSTNET_H
#define COS214PRAC5_FROSTNET_H
#include "PlantDecorator.h"


class FrostNet: public PlantDecorator {
public:
    FrostNet(Plant* plant);
    virtual ~FrostNet();
    std::string toString() const;
};


#endif //COS214PRAC5_FROSTNET_H