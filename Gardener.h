/**
 * @file Gardener.h
 * @author your name (you@domain.com)
 * @brief concrete mediator, concrete handler as part of the mediator and chain of command design patterns respectively. is a derived class of employee that specialises in watering pants and is unable to answer inquiries
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef Gardener_H
#define Gardener_H

#include "Employee.h"

class Gardener : public Employee
{
public:
    /**
     * @brief Construct a new Gardener object
     *
     * @param name
     * @param inventory
     */
    Gardener(string name, Inventory *inventory);
    /**
     * @brief Destroy the Gardener object
     *
     */
    ~Gardener();

    /**
     * @brief passes the command to the next employee
     *
     * @param command
     */
    void handleInquiry(Command *command);
    /**
     * @brief waters all the plants in the inventory that belong to a certain environment
     *
     * @param environment
     */
    void handleWater(int environment);

protected:
private:
};

#endif