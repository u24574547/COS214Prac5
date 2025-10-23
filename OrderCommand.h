#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>
class Employee; // forward declaration

class OrderCommand : public Command {
    private:
    Employee* mediator;
    std::string speciesName;
    public:
    OrderCommand(Customer* customer, Employee* mediator, const std::string& speciesName);
    void execute() override;
    std::string getSpeciesName() const ;
};

#endif
