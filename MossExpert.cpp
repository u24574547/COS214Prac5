
#ifndef MossExpert_CPP
#define MossExpert_CPP
#include "MossExpert.h"
MossExpert::MossExpert(string name, Inventory *inventory) : Employee(name, inventory)  {}
MossExpert::~MossExpert() {}

void MossExpert::handleInquiry(Command* command) {
        cout << name << " is taking a look at the inquiry." << endl;
    if (command->getType() == "Moss")
    {
        cout << name << " is happy to help you." << endl;
        command->getCustomer()->inquiryReceive("*a response about Moss plants");
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