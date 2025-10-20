#ifndef COS214PRAC5_MOSS_H
#define COS214PRAC5_MOSS_H
#include "BasePlant.h"


class Moss: public BasePlant {
public:
    Moss();
    virtual ~Moss();
    void display() const;
};


#endif //COS214PRAC5_MOSS_H