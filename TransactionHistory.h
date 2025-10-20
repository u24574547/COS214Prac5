#ifndef TransactionHistory_H
#define TransactionHistory_H

#include "Aggregate.h"
#include "Command.h"
#include "TransactionIterator.h"

#include "TransactionMemento.h"

class TransactionHistory : public Aggregate
{
    friend class TransactionIterator;

public:
    TransactionHistory();
    ~TransactionHistory();

    Iterator *createIterator();

    TransactionMemento *createMemento();

protected:
private:
    vector<Command *> transactions;
};

#endif