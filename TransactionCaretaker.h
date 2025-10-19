#ifndef TRANSACTIONCARETAKER_H
#define TRANSACTIONCARETAKER_H

#include "TransactionMemento.h"
#include <vector>

class TransactionCaretaker {
    private:
        vector<TransactionMemento*> mementos;
    public:
        TransactionMemento* undo();

};

#endif