#include "Customer.h"
#include "InquiryCommand.h"
#include "OrderCommand.h"
#include "RefundCommand.h"
#include <iostream>

Customer::Customer(const std::string& name, Employee* mediator,const std::string& id)
    : name(name), mediator(mediator),id(id) {
          history = new TransactionHistory(); // created history for the particular customer
    }

void Customer::inquiry(const std::string& plantType) {
    InquiryCommand inquiry(this,mediator, plantType);
    std::cout << name << " is inquiring about " << plantType << "...\n";
    inquiry.execute();
}

void Customer::order(const std::string& speciesName) {
    OrderCommand* order = new OrderCommand(this, mediator, speciesName);
    std::cout << name << " is ordering species: " << species << "...\n";
    order->execute();

    // Add the order to the customer's transaction history
    //history->addOrder(order);
}

void Customer::refund() {
      // Retrieve the last order from history
    OrderCommand* lastOrder = history->getLastOrder();
    if (lastOrder != nullptr) {
        RefundCommand refund(this, mediator, lastOrder);
        std::cout << name << " is requesting a refund for species: " 
                  << lastOrder->getSpecies() << "...\n";
        refund.execute();

        // IDK IF THE REMOVAL IS HANDLED IN THE TRANSACTION HISTORY OR IN THE REFUND COMMAND
        //history->removeOrder(lastOrder);
    } else {
        std::cout << name << " has no orders to refund.\n";
    }
}

Customer::~Customer() {
    delete history;  // clean up
}
