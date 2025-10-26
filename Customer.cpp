#include "Customer.h"
#include "Plant.h"
#include <iostream>

Customer::Customer(const std::string &name, Employee *mediator, const std::string &id)
    : name(name), mediator(mediator), id(id)
{
    history = new TransactionHistory(); // created history for the particular customer
}

void Customer::inquiry(const std::string &plantType)
{
    InquiryCommand inquiry(this, mediator, plantType);
    std::cout << name << " is inquiring about " << plantType << "..." << endl;
    inquiry.execute();
}

void Customer::order(const std::string &speciesName)
{
    OrderCommand *order = new OrderCommand(this, mediator, speciesName);
    std::cout << name << " is ordering species: " << speciesName << "..." << endl;
    order->execute();

    // Add the order to the customer's transaction history
    // history->addOrder(order);
}

void Customer::inquiryReceive(const std::string &plantType, const std::string &inquiryResponse)
{
    std::cout << name << " received inquiry response: " << plantType
              << " - " << inquiryResponse << "\n";
}

void Customer::orderReceive(Plant *plant, bool success)
{
    if (success)
    {
        std::cout << name << " received order confirmation for " << plant->getSpecies() << endl;
    }
    else
    {
        std::cout << name << " received order failure for " << plant->getSpecies() << endl;
    }
}

void Customer::refundReceive(bool success)
{
    if (success)
    {
        std::cout << name << " has been given a refund" << endl;
        // history->removeOrder(speciesName);
    }
    else
    {
        std::cout << name << " has failed to recieve a refund" << endl;
    }
}

void Customer::refund()
{
    // Retrieve the last order from history
    OrderCommand *lastOrder = dynamic_cast<OrderCommand *>(history->getLastOrder());
    if (lastOrder != nullptr)
    {
        RefundCommand refund(this, mediator, lastOrder);
        std::cout << name << " is requesting a refund for species: "
                  << lastOrder->getSpeciesName() << "..." << endl;
        ;
        refund.execute();

        // IDK IF THE REMOVAL IS HANDLED IN THE TRANSACTION HISTORY OR IN THE REFUND COMMAND
        // history->removeOrder(lastOrder);
    }
    else
    {
        std::cout << name << " has no orders to refund." << endl;
    }
}

Customer::~Customer()
{
    delete history; // clean up
}

std::string Customer::getName() const
{
    return name;
}

std::string Customer::getId() const
{
    return id;
}

TransactionHistory *Customer::getHistory() const
{
    return history;
}
