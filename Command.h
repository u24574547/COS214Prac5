#ifndef COMMAND_H
#define COMMAND_H

/**
 * @brief Forward declaration of the Customer class.
 * Used to avoid circular dependencies between Command and Customer.
 */
class Customer;

/**
 * @class Command
 * @brief Abstract base class representing a general command issued by a Customer.
 *
 * The Command class defines the basic interface for all concrete commands
 * (e.g., OrderCommand, InquiryCommand, RefundCommand). Each command
 * maintains a pointer to the Customer who initiated it.
 */
class Command {
protected:
    /**
     * @brief Pointer to the Customer who created the command.
     */
    Customer* customer;  

public:
    /**
     * @brief Constructs a Command associated with a specific Customer.
     * 
     * @param customer Pointer to the Customer who initiated this command.
     */
    Command(Customer* customer);

    /**
     * @brief Executes the command's specific action.
     * 
     * This is a pure virtual function that must be implemented
     * by all derived command types.
     */
    virtual void execute() = 0;

    /**
     * @brief Virtual destructor for proper cleanup in derived classes.
     */
    virtual ~Command();

    /**
     * @brief Retrieves the Customer who created this command.
     * 
     * @return Pointer to the Customer associated with this command.
     */
    Customer* getCustomer() const;
};

#endif // COMMAND_H
