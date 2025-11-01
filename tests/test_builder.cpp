// language: cpp
#include "doctest.h"
#include "Director.h"
#include "Inventory.h"
#include "UnplantedState.h"
#include "NonFlowering.h"
#include "Fern.h"
#include "Moss.h"
#include <vector>
#include <string>

// Minimal test builder that records calls for verification
class TestBuilder : public Builder {
public:
    std::vector<std::string> calls;

    void reset() override {
        calls.clear();
    }
    void addBasicPlant(Plant* plant) override {
        calls.push_back("addBasicPlant:" + plant->getSpecies());
    }
    void addDecorativePlant(Plant* plant) override {
        calls.push_back("addDecorativePlant:" + plant->getSpecies());
    }
    void addFertilisedPlant(Plant* plant) override {
        calls.push_back("addFertilisedPlant:" + plant->getSpecies());
    }
    void addFrostNetPlant(Plant* plant) override {
        calls.push_back("addFrostNetPlant:" + plant->getSpecies());
    }
    DisplayBundle* getResult() override {
        return nullptr;
    }
};

TEST_CASE("Director::constructFrostReadyBundle calls builder methods correctly") {
    Inventory* inv = new Inventory();

    // Provide individual states to avoid ownership ambiguities in tests
    PlantState* s1 = new UnplantedState();
    PlantState* s2 = new UnplantedState();
    PlantState* s3 = new UnplantedState();

    Plant* nonFlowering = new NonFlowering("Riccia fluitans", 0, 0, false, 1.0, 0, s1);
    Plant* fern = new Fern("Fern", 0, 0, false, 1.0, 0, s2);
    Plant* moss = new Moss("Moss", 0, 0, false, 1.0, 0, s3);

    // Add plants to inventory
    inv->addPlant(nonFlowering);
    inv->addPlant(fern);
    inv->addPlant(moss);

    TestBuilder tb;
    Director director(&tb, inv);

    // Execute the director method under test
    director.constructFrostReadyBundle();

    // Validate the builder received the expected calls in order
    CHECK(tb.calls.size() == 4);
    if (tb.calls.size() >= 4) {
        CHECK(tb.calls[0] == "addFrostNetPlant:Riccia fluitans");
        CHECK(tb.calls[1] == "addFrostNetPlant:Fern");
        CHECK(tb.calls[2] == "addBasicPlant:Moss");
        CHECK(tb.calls[3] == "addFertilisedPlant:Riccia fluitans");
    }

    // Cleanup
    delete inv;
    delete s1;
    delete s2;
    delete s3;
    delete nonFlowering;
    delete fern;
    delete moss;
}