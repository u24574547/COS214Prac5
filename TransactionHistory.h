/* originator for the memento design pattern*/
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "Aggregate.h"
#include "Iterator.h"
#include "TransactionMemento.h"
#include "Command.h"
#include "TransactionIterator.h"
#include <vector>

class TransactionHistory : public Aggregate {
    public:
    //note, the virtual createIterator doesnt have the same params in the UML
        Iterator* createIterator(std::vector<Command*> transactions) override;
        TransactionMemento* captureState();
        //capture state shouldnt be part of the aggregate interface
    private:
        std::vector<Command*> transactions;
};



#endif