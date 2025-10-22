#ifndef FernExpert_H
#define FernExpert_H

#include "Employee.h"

class FernExpert : public Employee
{
public:
    FernExpert();
    ~FernExpert();

    void handleInquiry(Command* command);

protected:
private:
};

#endif