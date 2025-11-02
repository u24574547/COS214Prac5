/**
 * @file FloweringExpert.h
 * @author your name (you@domain.com)
 * @brief concrete mediator, concrete handler as part of the mediator and chain of command design patterns respectively. is a derived class of employee that specialises in answering inquiries about flowering plants
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef FloweringExpert_H
#define FloweringExpert_H

#include "Employee.h"

class FloweringExpert : public Employee
{
public:
    /**
     * @brief Construct a new Flowering Expert object
     *
     * @param name
     * @param inventory
     */
    FloweringExpert(string name, Inventory *inventory);
    /**
     * @brief Destroy the Flowering Expert object
     *
     */
    ~FloweringExpert();

    /**
     * @brief returns answers to the customer that created the command if they are about flowering plants, otherwise passing on the command to next employee or declaring the inquiry unhandled
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

    /**
     * @brief Prints the employees details and the next employee in the Chain of Responsibility
     * @return a string representing the employee.
     */
    virtual std::string toString();

protected:
private:
};

#endif