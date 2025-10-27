#include "TransactionHistory.h"
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
    items.push_back(order);
}
void TransactionHistory::removeOrder(Command* order) {
    auto pos = std::find(items.begin(), items.end(), order);
    if (pos != items.end()) {
        items.erase(pos);
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
    return ss.str();
}
