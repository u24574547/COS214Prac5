#include "doctest.h"

// customer
#include "../Customer.h"

// command classes
#include "../Command.h"
#include "../OrderCommand.h"
#include "../RefundCommand.h"
#include "../InquiryCommand.h"

// mediator/chain classes
#include "../Employee.h"
#include "../FernExpert.h"
#include "../MossExpert.h"
#include "../FloweringExpert.h"
#include "../NonfloweringExpert.h"
#include "../Gardener.h"

// iterator classes
#include "../Aggregate.h"
#include "../TransactionHistory.h"
#include "../Inventory.h"

#include "../Iterator.h"
#include "../TransactionIterator.h"
#include "../PlantIterator.h"

// memento classes
#include "../TransactionMemento.h"
#include "../TransactionCaretaker.h"

// builder classes
#include "../Director.h"

#include "../Builder.h"
#include "../FrostReadyBuilder.h"
#include "../GiftBuilder.h"
#include "../TerrariumBuilder.h"

// composite classes
#include "../Bundle.h"
#include "../DisplayBundle.h"

// decorator classes
#include "../Plant.h"

#include "../PlantDecorator.h"
#include "../FrostNet.h"
#include "../Fertiliser.h"
#include "../BasePlant.h"

// factory method classes
#include "../Supplier.h"
#include "../FernSupplier.h"
#include "../MossSupplier.h"
#include "../FloweringSupplier.h"
#include "../NonFloweringSupplier.h"

#include "../Fern.h"
#include "../Moss.h"
#include "../Flowering.h"
#include "../NonFlowering.h"

// state classes
#include "../PlantState.h"
#include "../UnplantedState.h"
#include "../SeedlingState.h"
#include "../MatureState.h"
#include "../SoldState.h"

// observer classes
#include "../Day.h"
#include "../Observer.h"

#include <iostream>
#include <sstream>

using namespace std;

TEST_CASE("Day addObserver")
{
    SUBCASE("adding plant")
    {
        Day *day = new Day();
        Plant *plant = new Fern("fern", 0, 140, 0, false, 1.0, 0, new UnplantedState);
        Observer *observer = dynamic_cast<Observer *>(plant);
        day->addObserver(observer);
        CHECK(day->getObservers().size() == 1);
    }
    SUBCASE("adding employee")
    {
        Day *day = new Day();
        Employee *employee = new FernExpert("fernExpert", nullptr);
        Observer *observer = dynamic_cast<Observer *>(employee);
        day->addObserver(observer);
        CHECK(day->getObservers().size() == 1);
    }
}

TEST_CASE("Day removeObserver")
{
    SUBCASE("remove plant")
    {
        Day *day = new Day();
        Plant *plant = new Fern("fern", 0, 140, 0, false, 1.0, 0, new UnplantedState);
        Observer *observer = dynamic_cast<Observer *>(plant);
        day->addObserver(observer);
        day->removeObserver(observer);
        CHECK(day->getObservers().size() == 0);
    }
    SUBCASE("remove employee")
    {
        Day *day = new Day();
        Employee *employee = new FernExpert("fernExpert", nullptr);
        Observer *observer = dynamic_cast<Observer *>(employee);
        day->addObserver(observer);
        day->removeObserver(observer);
        CHECK(day->getObservers().size() == 0);
    }
}

TEST_CASE("plants update")
{
    Plant *plant = new Fern("fern", 0, 140, 0, false, 1.0, 0, new UnplantedState);
    Observer *observer = dynamic_cast<Observer *>(plant);
    observer->update();
}
TEST_CASE("employees update")
{
    Employee *employee = new FernExpert("employee", nullptr);
    Observer *observer = dynamic_cast<Observer *>(employee);
    observer->update();
}

TEST_CASE("day (subject) notify")
{
    SUBCASE("notify plants")
    {
        stringstream buffer;
        streambuf *old = cout.rdbuf(buffer.rdbuf());

        int nPlants = 2; // number of observer plants

        Plant **plants = new Plant *[nPlants]; // creating plants
        for (int i = 0; i < nPlants; i++)
        {
            plants[i] = new Fern("fern_" + to_string(i), 0, 140, 0, false, 1.0, 0, new UnplantedState);
        }

        Day *day = new Day(); // day subject

        for (int i = 0; i < nPlants; i++) // attaching plants (observers) to day (subject)
        {
            Observer *o = dynamic_cast<Observer *>(plants[i]);
            day->addObserver(o);
        }

        int d = 4; // number of days
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < nPlants; j++) // water all plants
            {
                plants[j]->water(200);
            }

            for (int j = 0; j < nPlants; j++) // output plant growth progress
            {
                cout << plants[j]->getSpecies() << " : " << plants[j]->getStateName() << " : " << plants[j]->getGrowthLevel() << endl;
            }

            day->notify(); // next day
        }

        cout.rdbuf(old);
        CHECK(!buffer.str().empty());
    }
    SUBCASE("notify employees")
    {
        stringstream buffer;
        streambuf *old = cout.rdbuf(buffer.rdbuf());

        int nEmployees = 2; // number of observer employees

        Employee **employees = new Employee *[nEmployees]; // creating employees
        for (int i = 0; i < nEmployees; i++)
        {
            employees[i] = new FernExpert("employee_" + to_string(i), nullptr);
        }

        Day *day = new Day(); // day subject

        for (int i = 0; i < nEmployees; i++) // attaching employees (observers) to day (subject)
        {
            Observer *o = dynamic_cast<Observer *>(employees[i]);
            day->addObserver(o);
        }

        int d = 4; // number of days
        for (int i = 0; i < d; i++)
        {
            day->notify(); // next day
        }

        cout.rdbuf(old);
        CHECK(!buffer.str().empty());
    }
    SUBCASE("notify mixed")
    {
        stringstream buffer;
        streambuf *old = cout.rdbuf(buffer.rdbuf());

        int nPlants = 2;    // number of observer plants
        int nEmployees = 2; // number of observer employees

        Plant **plants = new Plant *[nPlants]; // creating plants
        for (int i = 0; i < nPlants; i++)
        {
            plants[i] = new Fern("fern_" + to_string(i), 0, 140, 0, false, 1.0, 0, new UnplantedState);
        }

        Employee **employees = new Employee *[nEmployees]; // creating employees
        for (int i = 0; i < nEmployees; i++)
        {
            employees[i] = new FernExpert("employee_" + to_string(i), nullptr);
        }

        Day *day = new Day(); // day subject

        for (int i = 0; i < nPlants; i++) // attaching plants (observers) to day (subject)
        {
            Observer *o = dynamic_cast<Observer *>(plants[i]);
            day->addObserver(o);
        }

        for (int i = 0; i < nEmployees; i++) // attaching employees (observers) to day (subject)
        {
            Observer *o = dynamic_cast<Observer *>(employees[i]);
            day->addObserver(o);
        }

        int d = 4; // number of days
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < nPlants; j++) // water all plants
            {
                plants[j]->water(200);
            }

            for (int j = 0; j < nPlants; j++) // output plant growth progress
            {
                cout << plants[j]->getSpecies() << " : " << plants[j]->getStateName() << " : " << plants[j]->getGrowthLevel() << endl;
            }

            day->notify(); // next day
        }

        cout.rdbuf(old);
        CHECK(!buffer.str().empty());
    }
}