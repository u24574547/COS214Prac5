#include "TransactionHistory.h"

Iterator* TransactionHistory::createIterator(std::vector<Command*> transactions) {
    return new TransactionIterator(this);
}

TransactionMemento* TransactionHistory::captureState() {
    return new TransactionMemento(transactions);
}