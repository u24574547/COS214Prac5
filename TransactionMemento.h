#ifndef TRANSACTIONMEMENTO_H
#define TRANSACTIONMEMENTO_H

#include <vector>
#include "Command.h"

/**
 * @class TransactionMemento
 * @brief Represents a snapshot (memento) of a TransactionHistory's state.
 * 
 * This class stores a copy of the transactions in a TransactionHistory
 * to allow the Memento design pattern's undo/rollback functionality.
 */
class TransactionMemento {
    public:
        /**
         * @brief Constructs a TransactionMemento with the given transactions.
         * 
         * @param transactions A vector of Command pointers representing the current state.
         */
        TransactionMemento(std::vector<Command*> transactions);

        /**
         * @brief Retrieves the stored transactions.
         * 
         * @return A vector of Command pointers representing the saved state.
         */
        std::vector<Command*> getTransactions();
    private:
        /**
         * @brief The snapshot of transactions stored in the memento.
         */
        std::vector<Command*> transactions;
};

#endif