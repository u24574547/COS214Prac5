#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Command.h"
#include "Employee.h"
#include "TransactionHistory.h" 
#include "InquiryCommand.h"
#include "OrderCommand.h"
#include "RefundCommand.h"

class Employee;

/**
 * @class Customer
 * @brief Represents a customer who interacts with the nursery system.
 * 
 * The Customer class allows a user to perform operations such as making inquiries,
 * placing orders, and requesting refunds. Each Customer communicates through a mediator
 * (Employee) and maintains their own TransactionHistory.
 */
class Customer {
private:
    /**
     * @brief The name of the customer.
     */
    std::string name;

    /**
     * @brief Pointer to the Employee acting as a mediator between the Customer and the nursery system.
     */
    Employee* mediator;

    /**
     * @brief Unique identifier for the customer.
     */
    std::string id;

    /**
     * @brief Each customer maintains their own transaction history of orders.
     */
    TransactionHistory* history; 

public:
    /**
     * @brief Constructs a Customer with a name, mediator, and unique ID.
     * 
     * @param name The name of the customer.
     * @param mediator Pointer to the Employee acting as a mediator.
     * @param id Unique identifier assigned to the customer.
     */
    Customer(const std::string& name, Employee* mediator, const std::string& id);

    /**
     * @brief Sends an inquiry about a specific plant type to the mediator.
     * 
     * @param plantType The type of plant the customer is inquiring about.
     */
    void inquiry(const std::string& plantType);

    /**
     * @brief Places an order for a specific plant species.
     * 
     * @param speciesName The species name of the plant being ordered.
     */
    void order(const std::string& speciesName);

    /**
     * @brief Requests a refund for the most recent order in the customer's history.
     */
    void refund();

    /**
     * @brief Receives the response from the mediator regarding a plant inquiry.
     * 
     * @param plantType The type of plant the inquiry was about.
     * @param inquiryResponse The mediator's response to the inquiry.
     */
    void inquiryReceive(const std::string& plantType, const std::string& inquiryResponse);

    /**
     * @brief Receives confirmation or failure feedback after placing an order.
     * 
     * @param speciesName The name of the ordered species.
     * @param success Indicates whether the order was successful.
     */
    void orderReceive(const std::string& speciesName, bool success);

    /**
     * @brief Receives confirmation or failure feedback after requesting a refund.
     * 
     * @param speciesName The name of the species being refunded.
     * @param success Indicates whether the refund was successful.
     */
    void refundReceive(const std::string& speciesName, bool success);

    /**
     * @brief Destructor that cleans up the customer's transaction history.
     */
    virtual ~Customer();

    /**
     * @brief Retrieves the name of the customer.
     * 
     * @return The customer's name as a string.
     */
    std::string getName() const;

    /**
     * @brief Retrieves the unique ID of the customer.
     * 
     * @return The customer's ID as a string.
     */
    std::string getId() const;

    /**
     * @brief Gets a pointer to the customer's TransactionHistory.
     * 
     * @return Pointer to the TransactionHistory object.
     */
    TransactionHistory* getHistory() const;
};

#endif // CUSTOMER_H
