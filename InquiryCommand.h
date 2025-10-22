#ifndef INQUIRYCOMMAND_H
#define INQUIRYCOMMAND_H

#include "Command.h"
#include <iostream>

class InquiryCommand : public Command {
public:
    void execute() override;
};

#endif // INQUIRYCOMMAND_H
