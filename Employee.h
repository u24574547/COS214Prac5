#ifndef Employee_H
#define Employee_H

class Command;
class Customer;

#include "Inventory.h"

#include <vector>
#include <iostream>
// #include <string>

using namespace std;

class Employee
{
public:
    Employee(string name, Inventory* inventory);
    virtual ~Employee();
    void setNext(Employee *next);
    // void setCustomers(vector<Customer *> customers);

    void handleOrder(Command *command);
    void handleRefund(Command *command);
    virtual void handleInquiry(Command *command) = 0;

protected:
    string name;

    Employee *next;
    // vector<Customer *> customers;
    Inventory* inventory;

private:
};

#endif