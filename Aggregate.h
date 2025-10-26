#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "Iterator.h"
#include <vector>
using namespace std;

template <typename T>
class Aggregate
{
    public:
        Aggregate(vector<T> items) : items(items) {};
        virtual ~Aggregate();
        virtual Iterator<T>* createIterator() = 0;
        //CONSIDER CHANGING THIS TO PURE VIRTUAL IF STUFF CRASHES
        std::vector<T>& getItems() {return items;};
    protected:
        vector<T> items;
};

#endif