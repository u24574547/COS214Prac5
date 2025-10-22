#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"

#include <vector>
using namespace std;

template <typename T>
class Aggregate
{
    public:
        Aggregate();
        virtual ~Aggregate();
        virtual Iterator<T>* createIterator() = 0;
        std::vector<T>& getItems() {return items};
    private:
        vector<T> items;
};

#endif