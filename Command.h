#ifndef COMMAND_H
#define COMMAND_H

class Customer;

class Command {
protected:
    Customer* customer;  //Pointer to who created the command
 
public:
    Command(Customer* customer);
    virtual void execute() = 0;
    virtual ~Command();
    Customer* getCustomer()const;
};

#endif
