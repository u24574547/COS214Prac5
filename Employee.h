/**
 * @brief handler, mediator and receiver participants in the chain of command, mediator and command design patterns respectively.
 * Defines the abstract employees hold pointers to another employee and pass on received commands depending on the concrete employee's ability to handle them.
 *
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

    /**
     * @brief Prints the employees details and the next employee in the Chain of Responsibility
     * @return a string representing the employee.
     */
    virtual std::string toString();
    /**
     * @brief handler method that removes all the plants in the inventory that are in the dead state. to be performed by the handler.
     *
     */
    virtual void removeDead();
    /**
     * @brief adds the next employee to the chain. appending employees to the 'tail' of the employee linked list structure
     * 
     * @param employee 
     */
    void add(Employee *employee);

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