#include "InquiryCommand.h"
#include "Employee.h"
#include <iostream>

InquiryCommand::InquiryCommand(Employee* mediator, const std::string& plantName)
    : mediator(mediator), plantName(plantName) {}

void InquiryCommand::execute() {
    if (mediator!= nullptr){
        std::cout << "Handling inquiry..." << std::endl;
                mediator->handleInquiry();
    }
        
    else{
        std::cout << "Inquiry could not be handled.\nNo mediator was set to handle it.";
    }
        
   
}
