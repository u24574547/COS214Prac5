
#ifndef FernExpert_CPP
#define FernExpert_CPP
#include "FernExpert.h"
FernExpert::FernExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
FernExpert::~FernExpert() {}

void FernExpert::handleInquiry(Command *command)
{
    cout << name << " is taking a look at the inquiry." << endl;
    if (command->getType() == "Fern")
    {
        cout << name << " is happy to help you." << endl;
        command->getCustomer()->inquiryReceive("*a response about Fern");
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
            cout << "im sorry but we cannot help you, inquiry unhandled";
        }
    }
}

#endif