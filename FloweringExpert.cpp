
#ifndef FloweringExpert_CPP
#define FloweringExpert_CPP
#include "FloweringExpert.h"
#include "InquiryCommand.h"
#include "Customer.h"
FloweringExpert::FloweringExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
FloweringExpert::~FloweringExpert() {}

void FloweringExpert::handleInquiry(Command *command)
{
    InquiryCommand *cmd = static_cast<InquiryCommand *>(command);

    cout << name << " is taking a look at the inquiry." << endl;
    if (cmd->getType() == "Flowering")
    {
        cout << name << " is happy to help you." << endl;
        cmd->getCustomer()->inquiryReceive(cmd->getType(), "*a response about Flowering plants");
    }
    else
    {
        if (next != nullptr)
        {
            cout << name << " is forwarding the problem." << endl;
            next->handleInquiry(command);
        }
        else
        {
            cout << "I'm sorry but we cannot help you, inquiry unhandled." << endl;
        }
    }
}
void FloweringExpert::handleWater(int environment)
{
    if (next != nullptr)
    {
        cout << name << " is forwarding the problem." << endl;
        next->handleWater(environment);
    }
    else
    {
        cout << "The business doesn't have a gardener. Please hire one." << endl;
    }
}

#endif