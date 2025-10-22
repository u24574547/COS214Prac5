#ifndef Iterator_H
#define Iterator_H

class Aggregate;

#include <vector>

using namespace std;

class Iterator
{
public:
    Iterator(Aggregate *aggregate);
    virtual ~Iterator();

    virtual void next() = 0;
    virtual bool isDone() = 0;

protected:
    int current;

private:
};

#endif