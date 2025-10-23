#ifndef COS214PRAC5_NONFLOWERING_H
#define COS214PRAC5_NONFLOWERING_H
#include "BasePlant.h"


class NonFlowering: public BasePlant {
public:
    NonFlowering();
    virtual ~NonFlowering();
    void toString() const;
};


#endif //COS214PRAC5_NONFLOWERING_H