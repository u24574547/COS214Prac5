
#ifndef Gardener_CPP
#define Gardener_CPP
#include "Gardener.h"
#include "InquiryCommand.h"
#include "Customer.h"
Gardener::Gardener(string name, Inventory *inventory) : Employee(name, inventory) {}
Gardener::~Gardener() {}

void Gardener::handleInquiry(Command *command)
{
    if (next != nullptr)
    {
        cout << name << " is forwarding the problem." << endl;
        next->handleInquiry(command);
    }
    else
    {
        cout << "I'm sorry but we cannot help you, inquiry unhandled";
    }
}
void Gardener::handleWater(int environment)
{
    cout << " Gardener is watering the plants in environment "<<environment << endl;
    inventory->water(environment);
}

std::string Gardener::toString() {
    return "Role: Gardener\n"+Employee::toString();
}
void Gardener::removeDead()
{
    cout << "Gardener is removing all dead plants" << endl;
    inventory->removeDead();
}

void Gardener::update() {
    removeDead();
    Employee::update();
}

#endif
