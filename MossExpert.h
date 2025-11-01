/**
 * @file MossExpert.h
 * @author your name (you@domain.com)
 * @brief concrete mediator, concrete handler as part of the mediator and chain of command design patterns respectively. is a derived class of employee that specialises in answering inquiries about mosses
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef MossExpert_H
#define MossExpert_H

#include "Employee.h"

class MossExpert : public Employee
{
public:
    /**
     * @brief Construct a new Moss Expert object
     *
     * @param name
     * @param inventory
     */
    MossExpert(string name, Inventory *inventory);
    /**
     * @brief Destroy the Moss Expert object
     *
     */
    ~MossExpert();

    /**
     * @brief returns answers to the customer that created the command if they are about mosses, otherwise passing on the command to next employee or declaring the inquiry unhandled
     *
     * @param command
     */
    void handleInquiry(Command *command);
    /**
     * @brief ses on the command until a gardener is called
     *
     * @param environment
     */
    void handleWater(int environment);

protected:
private:
};

#endif