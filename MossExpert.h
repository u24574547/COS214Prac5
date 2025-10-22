#ifndef MossExpert_H
#define MossExpert_H

#include "Employee.h"

class MossExpert : public Employee
{
public:
    MossExpert();
    ~MossExpert();

    void handleInquiry(Command* command);

protected:
private:
};

#endif