
#ifndef TransactionIterator_CPP
#define TransactionIterator_CPP
#include "TransactionIterator.h"

#include "TransactionHistory.h"
#include "Command.h"

TransactionIterator::TransactionIterator(Aggregate *transactionHistory) : Iterator(transactionHistory) {}
TransactionIterator::~TransactionIterator() {}
void TransactionIterator::next() {}
bool TransactionIterator::isDone() {}
Command *TransactionIterator::getCurrent() {}

#endif