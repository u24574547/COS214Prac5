#include "TransactionHistory.h"
#include "Customer.h"
#include <iostream>
#include <algorithm>

Iterator<Command*>* TransactionHistory::createIterator() {
    return new TransactionIterator(this);
}
TransactionMemento* TransactionHistory::captureState() {
    //create new memento
    return new TransactionMemento(items);
}

void TransactionHistory::addOrder(Command* order) {
    std::cout << "Adding order from: " << order->getCustomer()->getName()<< "\n";
    items.push_back(order);
}
void TransactionHistory::removeOrder(Command* order) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (*it == order) {
            std::cout << "Removing order from " << (*it)->getCustomer()->getName() << "\n";
            items.erase(it);
            break;
        }
    }
    
}

Command* TransactionHistory::getLastOrder() {
    return items.back();
}