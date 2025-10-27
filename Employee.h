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
// #include <string>

using namespace std;

class Employee
{
public:
    Employee(string name, Inventory *inventory);
    virtual ~Employee();
    void setNext(Employee *next);

    void handleOrder(OrderCommand *command);
    void handleRefund(RefundCommand *command);
    virtual void handleInquiry(InquiryCommand *command) = 0;
    virtual void handleWater(int environment) = 0;

protected:
    string name;

    Employee *next;
    Inventory *inventory;

private:
};

#endif