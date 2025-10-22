#include "OrderCommand.h"
#include "Employee.h"
#include <iostream>

OrderCommand::OrderCommand(Employee* mediator, const std::string& plantName)
    : mediator(mediator), plantName(plantName) {}

void OrderCommand::execute() {
    if (mediator!= nullptr){
    std::cout << "Processing order..." << std::endl;
        mediator->handleOrder();}
    else{
        std::cout << "Order could not be processed.\n
                    No mediator was set to handle it."; }}