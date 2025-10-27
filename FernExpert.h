#ifndef FernExpert_H
#define FernExpert_H

#include "Employee.h"

class FernExpert : public Employee
{
public:
    FernExpert(string name, Inventory *inventory);
    ~FernExpert();

    void handleInquiry(InquiryCommand *command);
    void handleWater(int environment);

protected:
private:
};

#endif