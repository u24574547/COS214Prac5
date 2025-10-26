/* originator for the memento design pattern*/
#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include "Aggregate.h"
#include "Iterator.h"
#include "TransactionMemento.h"
#include "Command.h"
#include "TransactionIterator.h"
#include <vector>

/**
 * @class TransactionHistory
 * @brief Represents the originator in the Memento design pattern that manages transaction commands.
 * 
 * The TransactionHistory class stores a collection of Command objects representing transactions.
 * It supports creating iterators for traversal, capturing its current state into a TransactionMemento,
 * and modifying its collection by adding or removing orders.
 */
class TransactionHistory : public Aggregate<Command*> {
    public:
        /**
         * @brief Constructs an empty TransactionHistory object.
         */
        TransactionHistory() : Aggregate(transactions) {};

        /**
         * @brief Destroys the TransactionHistory and cleans up resources.
         */
        ~TransactionHistory(){};

        /**
         * @brief Creates an iterator for traversing the collection of transactions.
         * 
         * @return A pointer to an Iterator<Command*> for this TransactionHistory.
         */   
        Iterator<Command*>* createIterator() override;

        /**
         * @brief Captures the current state of the transaction history into a memento.
         * 
         * @return A pointer to a TransactionMemento representing the current state.
         */
        TransactionMemento* captureState();

        /**
         * @brief Adds a new order (command) to the transaction history.
         * 
         * @param order Pointer to the Command object to be added.
         */       
        void addOrder(Command* order);

        /**
         * @brief Removes a specific order (command) from the transaction history.
         * 
         * @param order Pointer to the Command object to be removed.
         */       
        void removeOrder(Command* order);

        /**
         * @brief Retrieves the most recent order from the transaction history.
         * 
         * @return Pointer to the last Command object, or nullptr if the history is empty.
         */
        Command* getLastOrder();
    private:
        /**
         * @brief The collection of Command objects representing transaction records.
         */
        std::vector<Command*> transactions;
};



#endif