#ifndef Employee_H
#define Employee_H

class Command;
class Customer;

#include <vector>

using namespace std;

class Employee
{
public:
    Employee();
    virtual ~Employee();
    void setNext(Employee *next);
    void setCustomers(vector<Customer *> customers);

    void handleOrder(Command* command);
    void handleRefund(Command* command);
    virtual void handleInquiry(Command* command) = 0;

protected:
    Employee *next;
    vector<Customer *> customers;

private:
};

#endif