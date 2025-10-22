// Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Command.h"
class Employee;

class Customer {
private:
    std::string name;
    Employee* mediator;
    std::string id;
public:
    Customer(const std::string& name, Employee* mediator,const std::string& id);
    void inquiry(const std::string& plantName);
    void order(const std::string& plantName);
    void refund(const std::string& plantName);
};

#endif
