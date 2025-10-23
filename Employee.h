#ifndef Employee_H
#define Employee_H

class Command;
class Customer;

#include "Inventory.h"

#include <vector>
// #include <string>

using namespace std;

class Employee
{
public:
    Employee(int id, string name);
    virtual ~Employee();
    void setNext(Employee *next);
    // void setCustomers(vector<Customer *> customers);

    void handleOrder(Command *command);
    void handleRefund(Command *command);
    virtual void handleInquiry(Command *command) = 0;

protected:
    int id;
    string name;

    Employee *next;
    // vector<Customer *> customers;

private:
};

#endif