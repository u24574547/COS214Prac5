
#ifndef Employee_CPP
#define Employee_CPP
#include "Employee.h"

#include "Command.h"
#include "Customer.h"

Employee::Employee() {}
Employee::Employee::~Employee() {}
void Employee::setNext(Employee *next) {}
void Employee::setCustomers(vector<Customer *> customers) {}

void Employee::handleOrder(Command *command) {}
void Employee::handleRefund(Command *command) {}

#endif