
#ifndef Employee_CPP
#define Employee_CPP
#include "Employee.h"

#include "Command.h"
#include "OrderCommand.h"
#include "RefundCommand.h"

#include "Customer.h"
#include "Director.h"
#include "FrostReadyBuilder.h"
#include "GiftBuilder.h"
#include "TerrariumBuilder.h"

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

    if (cmd->getSpeciesName()=="Gift Bundle") {
        Builder* builder = new GiftBuilder();
        Director* director = new Director(builder, inventory);
        bool success = director->constructGiftBundle();
        if (success) cmd->getCustomer()->orderReceive(builder->getResult(), true);
        else cmd->getCustomer()->orderReceive(nullptr, false);
        delete builder;
        builder = nullptr;
        delete director;
        director = nullptr;
    }
    else if (cmd->getSpeciesName()=="FrostReady Bundle") {
        Builder* builder = new FrostReadyBuilder();
        Director* director = new Director(builder, inventory);
        bool success = director->constructFrostReadyBundle();
        if (success) cmd->getCustomer()->orderReceive(builder->getResult(), true);
        else cmd->getCustomer()->orderReceive(nullptr, false);
        delete builder;
        builder = nullptr;
        delete director;
        director = nullptr;
    }
    else if (cmd->getSpeciesName()=="Terrarium Bundle") {
        Builder* builder = new TerrariumBuilder();
        Director* director = new Director(builder, inventory);
        bool success = director->constructTerrariumBundle();
        if (success) cmd->getCustomer()->orderReceive(builder->getResult(), true);
        else cmd->getCustomer()->orderReceive(nullptr, false);
        delete builder;
        builder = nullptr;
        delete director;
        director = nullptr;

    }
    else
    {
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
void Employee::update()
{
    cout << name << "'s working day is finished." << endl;
}

std::string Employee::toString() {
    std::stringstream ss;
    ss<<"Name: "<<name;
    if (next!=nullptr)ss<<"\nPasses requests on to:\n"<<next->toString();
    return ss.str();
}
void Employee::removeDead(){
        if (next != nullptr)
    {
        cout << name << " is forwarding the task of removing the dead plants." << endl;
        next->removeDead();
    }
    else
    {
        cout << "The business doesn't have a gardener to remove the dead plants in the inventory. Please hire one." << endl;
    }

}

#endif
