
#ifndef Day_CPP
#define Day_CPP
#include "Day.h"
Day::Day() {}
Day::Day(vector<Observer *> observers)
{
    this->observers = observers;
}
void Day::addObserver(Observer *observer)
{
    this->observers.push_back(observer);
}
void Day::removeObserver(Observer *observer)
{
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i] == observer)
        {
            observers.erase(observers.begin() + i);
        }
    }
}
void Day::notify()
{
    for (Observer *observer : observers)
    {
        observer->update();
    }
}

#endif