
#ifndef Gardener_CPP
#define Gardener_CPP
#include "Gardener.h"
#include "InquiryCommand.h"
#include "Customer.h"
Gardener::Gardener(string name, Inventory *inventory) : Employee(name, inventory) {}
Gardener::~Gardener() {}

void Gardener::handleInquiry(InquiryCommand *command)
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
void Gardener::handleWater(int environment)
{
    cout << " i am watering the plants now" << endl;
    inventory->water(environment);
}

#endif