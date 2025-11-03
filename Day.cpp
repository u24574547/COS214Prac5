
#ifndef Day_CPP
#define Day_CPP
#include "Day.h"

#include "BasePlant.h"
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
            break;
        }
    }
}
void Day::notify()
{
    vector<Observer*> temp = vector<Observer*>();
    for (int i = 0; i < observers.size(); i++)
    {
        if (observers[i]->getObserverType()=="Plant") {
            observers[i]->update();
            BasePlant* plant = dynamic_cast<BasePlant*>(observers[i]);
            if (plant->getStateName()=="Dead State") {
                observers.erase(observers.begin() + i);
                i--;
            }
        }
        else {
            temp.push_back(observers[i]);
        }
    }
    for (Observer *observer : temp)
    {
        observer->update();
    }
}

#endif