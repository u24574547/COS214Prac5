#ifndef Aggregate_H
#define Aggregate_H

#include "Iterator.h"

#include <vector>

using namespace std;

class Aggregate
{
    friend class Iterator;

public:
    Aggregate();
    virtual ~Aggregate();

    virtual Iterator *createIterator() = 0;

protected:
private:
};

#endif