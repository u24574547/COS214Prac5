#include "Customer.h"
#include "InquiryCommand.h"
#include "OrderCommand.h"
#include "RefundCommand.h"
#include <iostream>

Customer::Customer(const std::string& name, Employee* mediator,const std::string& id)
    : name(name), mediator(mediator),id(id) {}

void Customer::inquiry(const std::string& plantName) {
    InquiryCommand inquiry(mediator, plantName);
    std::cout << name << " is inquiring about " << plantName << "...\n";
    inquiry.execute();
}

void Customer::order(const std::string& plantName) {
    OrderCommand order(mediator, plantName);
    std::cout << name << " is ordering " << plantName << "...\n";
    order.execute();
}

void Customer::refund(const std::string& plantName) {
    RefundCommand refund(mediator, plantName);
    std::cout << name << " is requesting a refund for " << plantName << "...\n";
    refund.execute();
}
