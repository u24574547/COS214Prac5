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
    Iterator<Command*>* it = createIterator();

    for (it->first(); !it->isDone(); it->next()) {
        if (it->current() == order) {
            auto& items = getItems();  // underlying vector
            auto pos = std::find(items.begin(), items.end(), it->current());
            if (pos != items.end()) {
            items.erase(pos);  
            }
            break;
        }
    }
    delete it;
}
Command* TransactionHistory::getLastOrder() {
    return transactions.back();
}