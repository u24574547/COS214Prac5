
#ifndef Employee_CPP
#define Employee_CPP
#include "Employee.h"

#include "Command.h"
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

void Employee::handleOrder(Command *command)
{
    OrderCommand *cmd = static_cast<OrderCommand *>(command);

    Plant *plant = inventory->getPlant(cmd->getSpeciesName());
    if (plant == nullptr)
    {
        cmd->getCustomer()->orderReceive(nullptr, false);
    }
    else
    {
        cmd->getCustomer()->orderReceive(plant, true);
    }
}
void Employee::handleRefund(Command *command)
{
    RefundCommand *cmd = static_cast<RefundCommand *>(command);

    Command *refund = cmd->getCommandToRefund();
    if (refund == nullptr)
    {
        // cout << "sorry, there is no record of this transaction.";
        cmd->getCustomer()->refundReceive(false);
    }
    else
    {
        cmd->getCustomer()->refundReceive(true);
    }
}

#endif