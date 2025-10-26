#ifndef FernExpert_H
#define FernExpert_H

#include "Employee.h"

class FernExpert : public Employee
{
public:
    FernExpert(string name, Inventory *inventory);
    ~FernExpert();

    void handleInquiry(Command* command);

protected:
private:
};

#endif