
#ifndef NonfloweringExpert_CPP
#define NonfloweringExpert_CPP
#include "NonfloweringExpert.h"
NonfloweringExpert::NonfloweringExpert(string name, Inventory *inventory) : Employee(name, inventory) {}
NonfloweringExpert::~NonfloweringExpert() {}

void NonfloweringExpert::handleInquiry(Command *command) {
        cout << name << " is taking a look at the inquiry." << endl;
    if (command->getType() == "Nonflowering")
    {
        cout << name << " is happy to help you." << endl;
        command->getCustomer()->inquiryReceive("*a response about nonflowering plants");
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