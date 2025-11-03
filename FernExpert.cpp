
#ifndef FernExpert_CPP
#define FernExpert_CPP
#include "FernExpert.h"
#include "InquiryCommand.h"
#include "Customer.h"
FernExpert::FernExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
FernExpert::~FernExpert() {}

void FernExpert::handleInquiry(Command *command)
{
    InquiryCommand *cmd = static_cast<InquiryCommand *>(command);

    cout << name << " is taking a look at the inquiry." << endl;
    if (cmd->getType() == "Fern")
    {
        cout << name << " is happy to help you." << endl;
        std::string response = inventory->stockSummary("Pteridophyta")+"\n Did you know that ferns reproduce using tiny spores, not seeds or flowers — and some species can produce millions of spores on a single leaf?";
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
void FernExpert::handleWater(int environment)
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

std::string FernExpert::toString() {
    return "Role: Salesman & Fern Expert\n"+Employee::toString();
}

#endif
