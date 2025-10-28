#include "OrderCommand.h"
#include "Employee.h"
#include <iostream>

#include "Customer.h"

OrderCommand::OrderCommand(Customer *customer, Employee *mediator, const std::string &speciesName)
    : Command(customer), mediator(mediator), speciesName(speciesName) {}

void OrderCommand::execute()
{
    if (mediator != nullptr)
    {
        std::cout << "Processing order for species: " << this->getSpeciesName() << "...\n";
        Command *inter = this;
        mediator->handleOrder(inter);
    }
    else
    {
        std::cout << "Order could not be processed.\nNo mediator was set to handle it." << std::endl;
    }
}

std::string OrderCommand::getSpeciesName() const
{
    return speciesName;
}

string OrderCommand::toString()
{
    return "OrderCommand from " + this->getCustomer()->getName() + " [id = " + this->customer->getId() + "]\n";
}