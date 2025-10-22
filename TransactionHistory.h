#ifndef TransactionHistory_H
#define TransactionHistory_H

#include "Aggregate.h"
#include "Command.h"
#include "TransactionIterator.h"
#include <vector>

#include "TransactionMemento.h"

class TransactionHistory : public Aggregate<Command*> {
    friend class TransactionIterator;

public:
    TransactionHistory();
    ~TransactionHistory();

    Iterator<Command*>* createIterator();
    TransactionMemento* createMemento();

private:
    vector<Command*> transactions;
};

#endif