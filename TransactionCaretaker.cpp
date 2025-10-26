#include "TransactionCaretaker.h"

void TransactionCaretaker::add(TransactionMemento* memento) {
    mementos.push_back(memento);
}

TransactionMemento* TransactionCaretaker::undo() {
    if (mementos.empty()) return nullptr;
    TransactionMemento* mem = mementos.back();
    mementos.pop_back();
    return mem;
}