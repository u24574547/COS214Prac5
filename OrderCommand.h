#ifndef ORDERCOMMAND_H
#define ORDERCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>

class Employee; // Forward declaration

/**
 * @class OrderCommand
 * @brief Represents a command for processing customer plant orders.
 *
 * This class encapsulates the action of a customer placing an order for a specific
 * plant species. It follows the Command design pattern, allowing requests to be
 * executed through a mediator (Employee) without the customer needing to know
 * the handling details.
 */
class OrderCommand : public Command
{
private:
    /**
     * @brief Pointer to the Employee (mediator) responsible for processing the order.
     */
    Employee *mediator;

    /**
     * @brief The name of the plant species being ordered.
     */
    std::string speciesName;

public:
    /**
     * @brief Constructs a new OrderCommand.
     *
     * @param customer Pointer to the Customer who initiated the order.
     * @param mediator Pointer to the Employee handling the order.
     * @param speciesName The name of the plant species being ordered.
     */
    OrderCommand(Customer *customer, Employee *mediator, const std::string &speciesName);

    /**
     * @brief Executes the order command by delegating the task to the mediator (Employee).
     */
    void execute() override;

    /**
     * @brief Retrieves the name of the plant species being ordered.
     *
     * @return A string representing the plant species name.
     */
    std::string getSpeciesName() const;

    string toString();
};

#endif // ORDERCOMMAND_H
