#ifndef TransactionHistory_H
#define TransactionHistory_H

#include "Aggregate.h"
#include "Command.h"
#include "TransactionIterator.h"

class TransactionHistory : public Aggregate
{
    friend class TransactionIterator;

public:
    TransactionHistory();
    ~TransactionHistory();

    Iterator *createIterator();

protected:
private:
    vector<Command *> transactions;
};

#endif