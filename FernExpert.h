/**
 * @file FernExpert.h
 * @author your name (you@domain.com)
 * @brief concrete mediator, concrete handler as part of the mediator and chain of command design patterns respectively. is a derived class of employee that specialises in answering inquiries about ferns
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FernExpert_H
#define FernExpert_H

#include "Employee.h"

class FernExpert : public Employee
{
public:
    /**
     * @brief Construct a new Fern Expert object
     *
     * @param name
     * @param inventory
     */
    FernExpert(string name, Inventory *inventory);
    /**
     * @brief Destroy the Fern Expert object
     *
     */
    ~FernExpert();

    /**
     * @brief returns answers to the customer that created the command if they are about ferns, otherwise passing on the command to next employee or declaring the inquiry unhandled
     *
     * @param command
     */
    void handleInquiry(Command *command);
    /**
     * @brief passes on the command until a gardener is called
     *
     * @param environment
     */
    void handleWater(int environment);

protected:
private:
};

#endif