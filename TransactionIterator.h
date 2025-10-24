#ifndef TRANSACTIONITERATOR_H
#define TRANSACTIONITERATOR_H

#include "Iterator.h"

class TransactionHistory;
class Command;

class TransactionIterator : public Iterator<Command*> {
public:
    TransactionIterator(Aggregate<Command*> *transactionHistory);
    ~TransactionIterator();

    Command* first() override;
    Command* next() override;
    Command* current() override;
    Command* last() override;
    bool isDone() override;
private:
    vector<Command *> transactions;
    size_t index;
};

#endif