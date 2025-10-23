#ifndef COS214PRAC5_FERN_H
#define COS214PRAC5_FERN_H
#include "BasePlant.h"


class Fern: public BasePlant {
    public:
    Fern();
    virtual ~Fern();
    void toString() const;
};


#endif //COS214PRAC5_FERN_H