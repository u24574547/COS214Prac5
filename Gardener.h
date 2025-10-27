#ifndef Gardener_H
#define Gardener_H

#include "Employee.h"

class Gardener : public Employee
{
public:
    Gardener(string name, Inventory *inventory);
    ~Gardener();

    void handleInquiry(InquiryCommand* command);

protected:
private:
};

#endif