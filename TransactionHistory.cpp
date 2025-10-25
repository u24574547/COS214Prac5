#include "TransactionHistory.h"
#include <algorithm>

Iterator<Command*>* TransactionHistory::createIterator() {
    return new TransactionIterator(this);
}
TransactionMemento* TransactionHistory::captureState() {
    //create new memento
    return new TransactionMemento(transactions);
}
void TransactionHistory::addOrder(Command* order) {
    transactions.push_back(order);
}
void TransactionHistory::removeOrder(Command* order) {
    auto pos = std::find(transactions.begin(), transactions.end(), order);
    if (pos != transactions.end()) {
        transactions.erase(pos);
    }
}

Command* TransactionHistory::getLastOrder() {
    return transactions.back();
}