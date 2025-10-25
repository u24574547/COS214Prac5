#ifndef COS214PRAC5_FERTILISER_H
#define COS214PRAC5_FERTILISER_H
#include "PlantDecorator.h"


class Fertiliser: public PlantDecorator {
    public:
    Fertiliser(Plant* plant);
    virtual ~Fertiliser();
    std::string toString() const;
};


#endif //COS214PRAC5_FERTILISER_H