/**
 * @file Employee.h
 * @author your name (you@domain.com)
 * @brief handler, mediator and receiver participants in the chain of command, mediator and command design patterns respectively. defines the abstract employees hold pointers to another employee and pass on recieved commands depending on the concrete employee's ability to handle them.
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef Employee_H
#define Employee_H

class Command;
class InquiryCommand;
class OrderCommand;
class RefundCommand;

class Customer;

#include "Inventory.h"
#include "Observer.h"

#include <vector>
#include <iostream>

using namespace std;

class Employee : public Observer
{
public:
    /**
     * @brief Construct a new Employee object
     *
     * @param name
     * @param inventory
     */
    Employee(string name, Inventory *inventory);
    /**
     * @brief Destroy the Employee object
     *
     */
    virtual ~Employee();
    /**
     * @brief Set the Next employee in the chain of command
     *
     * @param next
     */
    void setNext(Employee *next);

    /**
     * @brief function called by commands that returns a Plant* to the customer that orders them
     *
     * @param command
     */
    void handleOrder(Command *command);
    /**
     * @brief function called by commands that informs the customer of whether they have recieved a refund or not (bool)
     *
     * @param command
     */
    void handleRefund(Command *command);
    /**
     * @brief function called by command that returns answers as strings to customers that ask them.
     *
     * @param command
     */
    virtual void handleInquiry(Command *command) = 0;
    /**
     * @brief abstract function for watering plants in a specific environment. implemented in gardener
     *
     * @param environment
     */
    virtual void handleWater(int environment) = 0;

    /**
     * @brief function that represents the actions performed by the employee when a day passes.
     *
     */
    void update() override;

protected:
    /// @brief name of employee
    string name;

    /// @brief next employee as part of the chain of command
    Employee *next;
    /// @brief pointer to the inventory that is required for the refund and order actions
    Inventory *inventory;

private:
};

#endif