#ifndef TRANSACTIONCARETAKER_H
#define TRANSACTIONCARETAKER_H

#include "TransactionMemento.h"
#include <vector>

class TransactionCaretaker {
    private:
        std::vector<TransactionMemento*> mementos;
    public:
        void add(TransactionMemento* memento);
        TransactionMemento* undo();

};

#endif