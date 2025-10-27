#include "RefundCommand.h"
#include "Employee.h"
#include <iostream>

RefundCommand::RefundCommand(Customer* customer, Employee* mediator, Command* commandToRefund)
    : Command(customer), mediator(mediator), commandToRefund(commandToRefund) {}


void RefundCommand::execute() {
    if (mediator!= nullptr){
         std::cout << "Processing refund..." << std::endl;
        Command* inter = this;
        mediator->handleRefund(inter);
    } else {
        std::cout<<"Refund could not be processed.\nNo mediator was set to handle it.";
        return; 
    }
}

Command* RefundCommand::getCommandToRefund() const { return commandToRefund; }

