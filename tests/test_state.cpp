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

#include <vector>
#include <string>

TEST_CASE("Plant basic lifecycle test") {
    // Create all plants with test-friendly water/growth values
    std::vector<Plant*> plants;
    // requiredWaterPerDay = 1, growthRate = 5 for faster testing
    plants.push_back(new Moss("Moss", 0, 1, 0, 0, 5, 0, new UnplantedState()));
    plants.push_back(new Fern("Fern", 0, 1, 0, 0, 5, 0, new UnplantedState()));
    plants.push_back(new Flowering("Flowering", 0, 1, 0, 0, 5, 0, new UnplantedState()));
    plants.push_back(new NonFlowering("NonFlowering", 0, 1, 0, 0, 5, 0, new UnplantedState()));

    for (Plant* plant : plants) {
        // Start state
        CHECK(plant->getStateName() == "Unplanted State");

        // Water to transition to Seedling
        plant->water(1);   // enough to meet requiredWaterPerDay
        plant->endDay();
        CHECK(plant->getStateName() == "Seedling State");

        // Grow until Mature (threshold 20)
        while (plant->getGrowthLevel() < 20) {
            plant->water(1); // each day meets water requirement
            plant->endDay();
        }
        CHECK(plant->getStateName() == "Mature State");

        // Grow until ReadyForSale (threshold 50)
        while (plant->getGrowthLevel() < 50) {
            plant->water(1);
            plant->endDay();
        }
        CHECK(plant->getStateName() == "Ready For Sale State");

        // Sell the plant and advance day
        plant->markSold();
        plant->endDay();
        CHECK(plant->getStateName() == "Sold State");
    }

    // Clean up
    for (Plant* plant : plants) delete plant;
}