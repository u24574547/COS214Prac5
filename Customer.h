#ifndef Customer_H
#define Customer_H

class Command;
class TransactionHistory;

#include <string>

using namespace std;

class Customer
{
public:
    Customer();
    ~Customer();

    void Order();
    void Refund();
    void Inquiry();

protected:
private:
    string name;
    TransactionHistory *transactionHistory;
};

#endif