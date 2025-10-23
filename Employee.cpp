
#ifndef Employee_CPP
#define Employee_CPP
#include "Employee.h"

#include "Command.h"
#include "Customer.h"

Employee::Employee(int id, string name)
{
    this->id = id;
    this->name = name;
}
Employee::Employee::~Employee() {}
void Employee::setNext(Employee *next)
{
    this->next = next;
}
// void Employee::setCustomers(vector<Customer *> customers) {}

void Employee::handleOrder(Command *command) {}
void Employee::handleRefund(Command *command) {}

#endif