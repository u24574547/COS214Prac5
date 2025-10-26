#ifndef MossExpert_H
#define MossExpert_H

#include "Employee.h"

class MossExpert : public Employee
{
public:
    MossExpert(string name, Inventory *inventory);
    ~MossExpert();

    void handleInquiry(InquiryCommand* command);

protected:
private:
};

#endif