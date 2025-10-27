#ifndef NonfloweringExpert_H
#define NonfloweringExpert_H

#include "Employee.h"

class NonfloweringExpert : public Employee
{
public:
    NonfloweringExpert(string name, Inventory *inventory);
    ~NonfloweringExpert();

    void handleInquiry(Command *command);
    void handleWater(int environment);

protected:
private:
};

#endif