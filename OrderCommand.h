#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

#include "Command.h"
#include <iostream>

class OrderCommand : public Command {
public:
    void execute() override;
};

#endif
