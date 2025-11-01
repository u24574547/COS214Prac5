
#ifndef NonfloweringExpert_CPP
#define NonfloweringExpert_CPP
#include "NonfloweringExpert.h"
#include "InquiryCommand.h"
#include "Customer.h"
NonfloweringExpert::NonfloweringExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
NonfloweringExpert::~NonfloweringExpert() {}

void NonfloweringExpert::handleInquiry(Command *command)
{
    InquiryCommand *cmd = static_cast<InquiryCommand *>(command);

    cout << name << " is taking a look at the inquiry." << endl;
    if (cmd->getType() == "Nonflowering")
    {
        cout << name << " is happy to help you." << endl;
        cmd->getCustomer()->inquiryReceive(cmd->getType(), "*a response about nonflowering plants");
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
void NonfloweringExpert::handleWater(int environment)
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