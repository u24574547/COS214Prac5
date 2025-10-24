#ifndef TRANSACTIONMEMENTO_H
#define TRANSACTIONMEMENTO_H

#include <vector>
#include "Command.h"

class TransactionMemento {
    public:
        TransactionMemento(std::vector<Command*> transactions);
        std::vector<Command*> getTransactions();
    private:
        std::vector<Command*> transactions;
}

#endif