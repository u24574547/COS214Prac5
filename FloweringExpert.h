#ifndef FloweringExpert_H
#define FloweringExpert_H

#include "Employee.h"

class FloweringExpert : public Employee
{
public:
    FloweringExpert(string name, Inventory *inventory);
    ~FloweringExpert();

    void handleInquiry(InquiryCommand* command);

protected:
private:
};

#endif