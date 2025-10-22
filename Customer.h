// Customer.h
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

class Customer {
private:
    std::string name;
    Employee* mediator;
    std::string id;
    TransactionHistory* history; // Each customer has their own history
public:
    Customer(const std::string& name, Employee* mediator,const std::string& id);
    void inquiry(const std::string& plantType);
    void order(const std::string& speciesName);
    void refund();//when we issue a refund, we refund the last order made in our history
    std::string getName() const;
    std::string getId() const;
    TransacrtionHistory* getHistory() const;
};

#endif
