
#ifndef MossExpert_CPP
#define MossExpert_CPP
#include "MossExpert.h"
#include "InquiryCommand.h"
#include "Customer.h"
MossExpert::MossExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
MossExpert::~MossExpert() {}

void MossExpert::handleInquiry(Command *command)
{
    InquiryCommand *cmd = static_cast<InquiryCommand *>(command);

    cout << name << " is taking a look at the inquiry." << endl;
    if (cmd->getType() == "Moss")
    {
        cout << name << " is happy to help you." << endl;
        std::string response = inventory->stockSummary("Bryophyta")+"Did you know that Mosses (like Bryum argenteum) can actually come back to life after drying out completely?";
        cmd->getCustomer()->inquiryReceive(cmd->getType(), response);
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
void MossExpert::handleWater(int environment)
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

std::string MossExpert::toString() {
    return "Role: Salesman & Moss Expert\n"+Employee::toString();
}

#endif
