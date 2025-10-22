
#ifndef TransactionHistory_CPP
#define TransactionHistory_CPP
#include "TransactionHistory.h"
TransactionHistory::TransactionHistory() : Aggregate() {}
TransactionHistory::~TransactionHistory() {}
Iterator *TransactionHistory::createIterator() {}
TransactionMemento *TransactionHistory::createMemento() {}

#endif