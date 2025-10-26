#ifndef TRANSACTIONCARETAKER_H
#define TRANSACTIONCARETAKER_H

#include "TransactionMemento.h"
#include <vector>

/**
 * @class TransactionCaretaker
 * @brief Manages the storage of TransactionMementos for undo functionality.
 * 
 * The TransactionCaretaker class acts as the caretaker in the Memento
 * design pattern. It stores snapshots of a TransactionHistory's state
 * and provides the ability to retrieve previous states.
 */
class TransactionCaretaker {
    private:
        /**
         * @brief Collection of saved transaction mementos.
         */
        std::vector<TransactionMemento*> mementos;
    public:
        /**
         * @brief Adds a memento to the caretaker's history.
         * 
         * @param memento Pointer to the TransactionMemento to store.
         */
        void add(TransactionMemento* memento);

        /**
         * @brief Retrieves the most recent memento and removes it from history.
         * 
         * @return Pointer to the last saved TransactionMemento, or nullptr if none exist.
         */
        TransactionMemento* undo();

};

#endif