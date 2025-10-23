#ifndef INQUIRYCOMMAND_H
#define INQUIRYCOMMAND_H

#include "Command.h"
#include <iostream>

class Employee; // forward declaration


class InquiryCommand : public Command {
    private:
    Employee* mediator;
    std::string plantType;
    public:
    InquiryCommand(Customer* customer, Employee* mediator, const std::string& plantType);
    void execute() override;
    std::string getType() const ;

};

#endif // INQUIRYCOMMAND_H
 