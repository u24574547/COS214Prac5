#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>
class Employee; // forward declaration

class RefundCommand : public Command {
    private:
    Employee* mediator;
    std::string plantName;
    public:
    RefundCommand(Employee* mediator, const std::string& plantName);
    void execute() override;
};

#endif 
