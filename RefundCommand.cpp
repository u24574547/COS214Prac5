#include "RefundCommand.h"
#include "Employee.h"
#include <iostream>

RefundCommand::RefundCommand(Employee* mediator, const std::string& plantName)
    : mediator(mediator), plantName(plantName) {}

void RefundCommand::execute() {
    if (mediator!= nullptr){
         std::cout << "Processing refund..." << std::endl;
        mediator->handleRefund();
    } else {
        std::cout<<"Refund could not be processed.\nNo mediator was set to handle it.";
        return; 
    }
   
}
