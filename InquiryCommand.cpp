#include "InquiryCommand.h"
#include "Employee.h"
#include <iostream>

#include "Customer.h"

InquiryCommand::InquiryCommand(Customer *customer, Employee *mediator, const std::string &plantType)
    : Command(customer), mediator(mediator), plantType(plantType) {}

void InquiryCommand::execute()
{
    if (mediator != nullptr)
    {
        std::cout << "Handling inquiry..." << std::endl;
        mediator->handleInquiry(this);
    }
    else
    {
        std::cout << "Inquiry could not be handled.\nNo mediator was set to handle it.";
    }
}

std::string InquiryCommand::getType() const
{
    return plantType;
}

string InquiryCommand::toString()
{
    return "InquiryCommand from " + this->getCustomer()->getName() + " [id = " + this->customer->getId() + "]\n";
}