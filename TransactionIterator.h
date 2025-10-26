#ifndef TRANSACTIONITERATOR_H
#define TRANSACTIONITERATOR_H

#include "Iterator.h"
#include "Command.h"
//remvove if there's no circular includes
class TransactionHistory;

/**
 * @class TransactionIterator
 * @brief Concrete iterator for traversing a TransactionHistory collection.
 * 
 * This iterator provides sequential access to the Command objects stored
 * in a TransactionHistory (Aggregate<Command*>). It implements the Iterator
 * interface for Command* types.
 */
class TransactionIterator : public Iterator<Command*> {
    public:
        /**
         * @brief Constructs a TransactionIterator for the given transaction history.
         * 
         * @param transactionHistory Pointer to the Aggregate<Command*> to traverse.
         */
        TransactionIterator(Aggregate<Command*>* transactionHistory);

        /**
         * @brief Destroys the TransactionIterator and cleans up resources.
         */
        ~TransactionIterator();

        /**
         * @brief Positions the iterator at the first transaction.
         * @return Pointer to the first Command object.
         */
        Command* first() override;

        /**
         * @brief Advances the iterator to the next transaction.
         * @return Pointer to the next Command object.
         */
        Command* next() override;

        /**
         * @brief Retrieves the current transaction.
         * @return Pointer to the current Command object.
         */
        Command* current() override;

        /**
         * @brief Positions the iterator at the last transaction.
         * @return Pointer to the last Command object.
         */
        Command* last() override;

        /**
         * @brief Checks if the iterator has traversed all transactions.
         * @return True if the end of the collection is reached, false otherwise.
         */
        bool isDone() override;

    private:
        /**
         * @brief Local copy of the transactions to iterate over.
         */
        vector<Command*> transactions;

        /**
         * @brief Current index of the iterator within the transactions vector.
         */
        size_t index;
};


#endif