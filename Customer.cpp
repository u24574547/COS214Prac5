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
    std::cout << name << " is ordering species: " << speciesName << "...\n";
    order->execute();

    // Add the order to the customer's transaction history
    //history->addOrder(order);
}


void Customer::inquiryReceive(const std::string& plantType, const std::string& inquiryResponse) {
    std::cout << name << " received inquiry response: " << plantType 
              << " - " << inquiryResponse << "\n";
}

void Customer::orderReceive(const std::string& speciesName, bool success) {
    if (success) {
        std::cout << name << " received order confirmation for " << speciesName 
                  << "\n";
        // Record successful order in history
        //OrderCommand* orderRecord = new OrderCommand(this, mediator, speciesName);
        //history->addOrder(orderRecord);
    } else {
        std::cout << name << " received order failure for " << speciesName 
                  <<"\n";
    }
}

void Customer::refundReceive(const std::string& speciesName, bool success) {
    if (success) {
        std::cout << name << " received refund confirmation for " << speciesName 
                  << "\n";
        //history->removeOrder(speciesName);
    } else {
        std::cout << name << " received refund failure for " << speciesName 
                  << "\n";
    }
}

void Customer::refund() {
      // Retrieve the last order from history
    OrderCommand* lastOrder = history->getLastOrder();
    if (lastOrder != nullptr) {
        RefundCommand refund(this, mediator, lastOrder);
        std::cout << name << " is requesting a refund for species: " 
                  << lastOrder->getSpeciesName() << "...\n";
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


std::string Customer::getName() const { 
    return name; }

std::string Customer::getId() const { 
    return id; }

TransactionHistory* Customer::getHistory() const {
     return history; }
