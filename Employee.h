#ifndef Employee_H
#define Employee_H

#include "Command.h"
#include "Customer.h"

#include <vector>

using namespace std;

class Employee
{
public:
    Employee();
    virtual ~Employee();
    void setNext(Employee *next);
    void setCustomers(vector<Customer *> customers);

    void handleOrder();
    void handleRefund();
    virtual void handleInquiry() = 0;

protected:
    Employee *next;
    vector<Customer *> customers;

private:
};

#endif