#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "Command.h"
#include <iostream>

class RefundCommand : public Command {
public:
    void execute() override;
};

#endif 
