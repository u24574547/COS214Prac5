#include "Command.h"

Command::Command(Customer* customer) : customer(customer) {}
Command::~Command(){}
Customer* Command::getCustomer() const { return customer; }