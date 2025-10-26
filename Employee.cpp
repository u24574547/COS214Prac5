
#ifndef Employee_CPP
#define Employee_CPP
#include "Employee.h"

#include "Command.h"
#include "InquiryCommand.h"
#include "OrderCommand.h"
#include "RefundCommand.h"

#include "Customer.h"

Employee::Employee(string name, Inventory *inventory)
{
    this->name = name;
    this->inventory = inventory;
}
Employee::Employee::~Employee() {}
void Employee::setNext(Employee *next)
{
    this->next = next;
}

void Employee::handleOrder(OrderCommand *command)
{
    Plant *plant = inventory->getPlant(command->getSpeciesName());
    if (plant == nullptr)
    {
        command->getCustomer()->orderReceive(nullptr, false);
    }
    else
    {
        command->getCustomer()->orderReceive(plant, true);
    }
}
void Employee::handleRefund(RefundCommand *command)
{
    Command *refund = command->getCommandToRefund();
    if (refund == nullptr)
    {
        // cout << "sorry, there is no record of this transaction.";
        command->getCustomer()->refundReceive(false);
    }
    else
    {
        command->getCustomer()->refundReceive(true);
    }
}

#endif