#ifndef REFUNDCOMMAND_H
#define REFUNDCOMMAND_H

#include "Command.h"
#include <iostream>
#include <string>

class Employee; // Forward declaration

/**
 * @class RefundCommand
 * @brief Represents a command to process a refund for a previous customer order.
 *
 * This class is part of the Command design pattern. It encapsulates the details
 * of a refund request initiated by a customer and delegates the execution to
 * the appropriate Employee (mediator) responsible for handling refunds.
 */
class RefundCommand : public Command {
private:
    /**
     * @brief Pointer to the Employee (mediator) responsible for processing the refund.
     */
    Employee* mediator;

    /**
     * @brief Pointer to the original Command (e.g., OrderCommand) being refunded.
     */
    Command* commandToRefund;

public:
    /**
     * @brief Constructs a new RefundCommand.
     *
     * @param customer Pointer to the Customer requesting the refund.
     * @param mediator Pointer to the Employee handling the refund process.
     * @param commandToRefund Pointer to the Command being refunded.
     */
    RefundCommand(Customer* customer, Employee* mediator, Command* commandToRefund);

    /**
     * @brief Executes the refund command by delegating it to the mediator (Employee).
     */
    void execute() override;

    /**
     * @brief Retrieves the original command being refunded.
     *
     * @return A pointer to the Command object being refunded.
     */
    Command* getCommandToRefund() const { return commandToRefund; }
};

#endif // REFUNDCOMMAND_H
