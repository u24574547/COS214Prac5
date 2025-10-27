#ifndef Employee_H
#define Employee_H

class Command;
class InquiryCommand;
class OrderCommand;
class RefundCommand;

class Customer;

#include "Inventory.h"

#include <vector>
#include <iostream>

using namespace std;

class Employee
{
public:
    Employee(string name, Inventory *inventory);
    virtual ~Employee();
    void setNext(Employee *next);

    void handleOrder(Command *command);
    void handleRefund(Command *command);
    virtual void handleInquiry(Command *command) = 0;
    virtual void handleWater(int environment) = 0;

protected:
    string name;

    Employee *next;
    Inventory *inventory;

private:
};

#endif