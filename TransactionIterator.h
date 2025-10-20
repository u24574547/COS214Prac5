#ifndef TransactionIterator_H
#define TransactionIterator_H

#include "Iterator.h"

class TransactionHistory;
class Command;

class TransactionIterator : public Iterator
{
public:
    TransactionIterator(Aggregate *transactionHistory);
    ~TransactionIterator();

    void next();
    bool isDone();

    Command *getCurrent();

protected:
private:
    vector<Command *> transactions;
};

#endif