#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>
class Employee; // forward declaration

class OrderCommand : public Command {
    private:
    Employee* mediator;
    std::string plantName;
    public:
    OrderCommand(Employee* mediator, const std::string& plantName);
    void execute() override;
};

#endif
