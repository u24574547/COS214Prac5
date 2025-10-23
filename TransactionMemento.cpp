#include "TransactionMemento.h"

TransactionMemento::TransactionMemento(std::vector<Command*> transactions) {
    this->transactions = transactions;
}

std::vector<Command*> TransactionMemento::getTransactions() {
    return transactions;
}
