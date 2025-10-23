#ifndef COS214PRAC5_FLOWERING_H
#define COS214PRAC5_FLOWERING_H
#include "BasePlant.h"


class Flowering: public BasePlant {
    public:
    Flowering();
    virtual ~Flowering();
    void toString() const;
};


#endif //COS214PRAC5_FLOWERING_H