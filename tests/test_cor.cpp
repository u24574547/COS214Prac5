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

TEST_CASE("gardener water plants")
{
    Inventory *inventory = new Inventory();
    inventory->addPlant(new Fern("fern", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new Moss("moss", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new Flowering("flowering", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new NonFlowering("nonFlowering", 0, 140, 0, false, 1.0, 0, new UnplantedState));

    Employee *employee0 = new FernExpert("emp_name", inventory);
    Employee *employee1 = new Gardener("emp_name", inventory);

    employee0->setNext(employee1);

    employee0->handleWater(0);

    CHECK(inventory->getItems()[3]->getAmountWateredToday() > 0);
}

TEST_CASE("gardener delete dead")
{
    Inventory *inventory = new Inventory();
    inventory->addPlant(new Fern("fern", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new Moss("moss", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new Flowering("flowering", 0, 140, 0, false, 1.0, 0, new UnplantedState));
    inventory->addPlant(new NonFlowering("nonFlowering", 0, 140, 0, false, 1.0, 0, new DeadState));

    Employee *employee0 = new FernExpert("emp_name", inventory);
    Employee *employee1 = new Gardener("emp_name", inventory);

    employee0->setNext(employee1);

    employee0->removeDead();

    CHECK(inventory->getItems().size() == 3);
}