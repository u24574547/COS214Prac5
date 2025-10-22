#ifndef ITERATOR_H
#define ITERATOR_H

template <typename T>
class Aggregate;

#include <vector>

template <typename T>
class Iterator {
public:
    Iterator(Aggregate<T> *aggregate) : aggregate(aggregate){};
    virtual ~Iterator(){};

    //consider making the return type T& in the future
    virtual T first() = 0;
    virtual T next() = 0;
    virtual T current() = 0;
    virtual bool isDone() = 0;
    virtual T last() = 0;
protected:
    Aggregate<T>* aggregate;
};

#endif