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

TEST_CASE("Supplier setters")
{
    SUBCASE("setState")
    {
        Supplier *supplier = new MossSupplier();

        PlantState *state = new SeedlingState();
        supplier->setState(state);

        CHECK(supplier->getState() == state);
    }
    SUBCASE("setGrowthLevel")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setGrowthLevel(42);

        CHECK(supplier->getGrowthLevel() == 42);
    }
    SUBCASE("setSpecies")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setSpecies("test string");

        CHECK(supplier->getSpecies() == "test string");
    }
    SUBCASE("setAmountWateredToday")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setAmountWateredToday(42);

        CHECK(supplier->getAmountWateredToday() == 42);
    }
    SUBCASE("setRequiredWaterPerDay")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setRequiredWaterPerDay(42);

        CHECK(supplier->getRequiredWaterPerDay() == 42);
    }
    SUBCASE("setGrowthRate")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setGrowthRate(42);

        CHECK(supplier->getGrowthRate() == 42);
    }
    SUBCASE("setPreferredEnvironment")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setPreferredEnvironment(42);

        CHECK(supplier->getPreferredEnvironment() == 42);
    }
    SUBCASE("setCurrentEnvironment")
    {
        Supplier *supplier = new MossSupplier();

        supplier->setCurrentEnvironment(42);

        CHECK(supplier->getCurrentEnvironment() == 42);
    }
}

TEST_CASE("Supplier factory method")
{
    SUBCASE("MossSupplier factory method")
    {
        Supplier *supplier = new MossSupplier();

        Plant *plant0 = supplier->getPlant();

        CHECK(typeid(*plant0) == typeid(Moss));
    }
    SUBCASE("FloweringSupplier factory method")
    {
        Supplier *supplier = new FloweringSupplier();

        Plant *plant0 = supplier->getPlant();

        CHECK(typeid(*plant0) == typeid(Flowering));
    }
    SUBCASE("NonFloweringSupplier factory method")
    {
        Supplier *supplier = new NonFloweringSupplier();

        Plant *plant0 = supplier->getPlant();

        CHECK(typeid(*plant0) == typeid(NonFlowering));
    }
    SUBCASE("FernSupplier factory method")
    {
        Supplier *supplier = new FernSupplier();

        Plant *plant0 = supplier->getPlant();

        CHECK(typeid(*plant0) == typeid(Fern));
    }
}