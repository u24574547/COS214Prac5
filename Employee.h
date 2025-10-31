#ifndef Employee_H
#define Employee_H

class Command;
class InquiryCommand;
class OrderCommand;
class RefundCommand;

class Customer;

#include "Inventory.h"
#include "Observer.h"

#include <vector>
#include <iostream>

using namespace std;

class Employee : public Observer
{
public:
    Employee(string name, Inventory *inventory);
    virtual ~Employee();
    void setNext(Employee *next);

    void handleOrder(Command *command);
    void handleRefund(Command *command);
    virtual void handleInquiry(Command *command) = 0;
    virtual void handleWater(int environment) = 0;

    void update() override;

protected:
    string name;

    Employee *next;
    Inventory *inventory;

private:
};

#endif