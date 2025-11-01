/**
 * @file Day.h
 * @author bridge trolls member u24614582
 * @brief subject participant in the observer design pattern. subjects observer the passage of time by being notified a day has passed
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef Day_H
#define Day_H

#include "Observer.h"

#include <vector>

using namespace std;

class Day
{
public:
    /**
     * @brief Construct a new Day object
     *
     */
    Day();
    /**
     * @brief Construct a new Day object with a premade observer list
     *
     */
    Day(vector<Observer *>);
    /**
     * @brief adds an observer to the list of observers to be notified
     *
     * @param observer
     */
    void addObserver(Observer *observer);
    /**
     * @brief removes an observer to such that that observer is no longer notified when a day passes
     *
     * @param observer
     */
    void removeObserver(Observer *observer);
    /**
     * @brief notifies all observers in observers that a day has passed
     *
     */
    void notify();

protected:
private:
    /// @brief vector containing pointers to all observers
    vector<Observer *> observers;
};

#endif