#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>
class Employee; // forward declaration

class RefundCommand : public Command {
    private:
    Employee* mediator;
    Command* commandToRefund; // pointer to the command being refunded

    public:
    RefundCommand(Customer* customer, Employee* mediator, Command* commandToRefund);
    void execute() override;
    Command* getCommandToRefund() const { return commandToRefund; }
};
  
#endif 
