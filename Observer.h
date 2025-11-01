/**
 * @file Observer.h
 * @author your name (you@domain.com)
 * @brief The observer participant in the observer design pattern.
 * Observers the passage of time by being notified by the day subject participant.
 * Observer is the abstract class that defines the basic update interface.
 *
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