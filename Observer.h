/**
 * @file Observer.h
 * @author your name (you@domain.com)
 * @brief the observer participant in the observer design patter. observers the passage of time by being notified by the day subject participant. is the abstract class that defines the basic update interface.
 * @version 0.1
 * @date 2025-11-01
 *
 * @copyright Copyright (c) 2025
 *
 */
#ifndef Observer_H
#define Observer_H

class Observer
{
public:
    // virtual ~Observer();
    /**
     * @brief abstract update function
     *
     */
    virtual void update() = 0;

protected:
private:
};

#endif