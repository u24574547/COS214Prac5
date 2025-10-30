#include "TransactionHistory.h"
#include "Customer.h"
#include <iostream>
#include <algorithm>
#include <sstream>

TransactionHistory::TransactionHistory(std::vector<Command *> transactions): Aggregate(transactions) {
}

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
    if (!items.empty())return items.back();
    return nullptr;
}

std::string TransactionHistory::toString() const {
    std::stringstream ss;
    for (auto it = items.begin(); it != items.end(); ++it) {
        ss<<(*it)->toString();
    }
    if (ss.str().length() == 0) return "Customer has not made any transactions.";
    return ss.str();
}
