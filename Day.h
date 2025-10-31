#ifndef Day_H
#define Day_H

#include "Observer.h"

#include <vector>

using namespace std;

class Day
{
public:
    Day();
    Day(vector<Observer *>);
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notify();

protected:
private:
    vector<Observer *> observers;
};

#endif