#ifndef NonfloweringExpert_H
#define NonfloweringExpert_H

#include "Employee.h"

class NonfloweringExpert : public Employee
{
public:
    NonfloweringExpert();
    ~NonfloweringExpert();

    void handleInquiry(Command* command);

protected:
private:
};

#endif