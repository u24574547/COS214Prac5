#include "TransactionIterator.h"
#include "TransactionHistory.h"
#include "Command.h"

TransactionIterator::TransactionIterator(Aggregate<Command*> *transactionHistory)
    :Iterator<Command*>(transactionHistory),
     transactions(transactionHistory->getItems()),
     index(0)
    {}


TransactionIterator::~TransactionIterator() {
    
}

Command* TransactionIterator::first() {
    index = 0;
    return transactions[0];
}

Command* TransactionIterator::next() {
    if (!isDone()) return transactions[index++];
    return nullptr;
}

Command* TransactionIterator::current() {
    return transactions[index];
}

Command* TransactionIterator::last() {
    index = transactions.size() - 1;
    return transactions[index];
}

bool TransactionIterator::isDone() {
    return index >= transactions.size();
}