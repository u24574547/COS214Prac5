#ifndef INQUIRYCOMMAND_H
#define INQUIRYCOMMAND_H

#include "Command.h"
#include <iostream>

class Employee; // forward declaration


class InquiryCommand : public Command {
    private:
    Employee* mediator;
    std::string plantName;
    public:
    InquiryCommand(Employee* mediator, const std::string& plantName);
    void execute() override;
};

#endif // INQUIRYCOMMAND_H
