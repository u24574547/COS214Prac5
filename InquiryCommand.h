#ifndef INQUIRYCOMMAND_H
#define INQUIRYCOMMAND_H

#include "Command.h"
#include <iostream>

class Employee; // Forward declaration

/**
 * @class InquiryCommand
 * @brief Represents a command for handling customer plant inquiries.
 * 
 * This class encapsulates the action of a customer making an inquiry
 * about a specific plant type. It is part of the Command pattern implementation
 * used to decouple the request (customer inquiry) from its processing (employee handling).
 */
class InquiryCommand : public Command {
private:
    /**
     * @brief Pointer to the Employee (mediator) responsible for handling the command.
     */
    Employee* mediator;

    /**
     * @brief The type of plant being inquired about.
     */
    std::string plantType;

public:
    /**
     * @brief Constructs a new InquiryCommand.
     * 
     * @param customer Pointer to the Customer who initiated the inquiry.
     * @param mediator Pointer to the Employee who will handle the inquiry.
     * @param plantType The type of plant being inquired about.
     */
    InquiryCommand(Customer* customer, Employee* mediator, const std::string& plantType);

    /**
     * @brief Executes the inquiry command by delegating it to the mediator (Employee).
     */
    void execute() override;

    /**
     * @brief Retrieves the type of plant that was inquired about.
     * 
     * @return A string representing the plant type.
     */
    std::string getType() const;
};

#endif // INQUIRYCOMMAND_H
