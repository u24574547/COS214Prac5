/* originator for the memento design pattern*/
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "Aggregate.h"
#include "Iterator.h"
#include "TransactionMemento.h"
#include "Command.h"
#include "TransactionIterator.h"
#include <vector>

class TransactionHistory : public Aggregate<Command*> {
    public:
        TransactionHistory() : Aggregate(transactions) {};
        ~TransactionHistory(){};
        Iterator<Command*>* createIterator() override;
        TransactionMemento* captureState();
        void addOrder(Command* order);
        void removeOrder(Command* order);
        Command* getLastOrder();
    private:
        std::vector<Command*> transactions;
};



#endif