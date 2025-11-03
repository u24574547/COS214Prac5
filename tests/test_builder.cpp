// language: cpp
#include "doctest.h"
#include "../Director.h"
#include "../Inventory.h"
#include "../UnplantedState.h"
#include "../NonFlowering.h"
#include "../Fern.h"
#include "../Moss.h"
#include "../Flowering.h"
#include <vector>
#include <string>
#include "../DisplayBundle.h"
#include "../GiftBuilder.h"
#include "../FrostReadyBuilder.h"

// ---------------------------------------------------------------------------
// TestBuilder: mock Builder that records method calls for verification
// ---------------------------------------------------------------------------
class TestBuilder : public Builder {
public:
    std::vector<std::string> calls;
    DisplayBundle* result;

    TestBuilder() : result(NULL) {}

    void reset() override {
        calls.clear();
    }

    void addBasicPlant(Inventory* inventory) override {
        calls.push_back("addBasicPlant");
    }

    void addDecorativePlant(Inventory* inventory) override {
        calls.push_back("addDecorativePlant");
    }

    void addFertilisedPlant(Inventory* inventory) override {
        calls.push_back("addFertilisedPlant");
    }

    void addFrostNetPlant(Inventory* inventory) override {
        calls.push_back("addFrostNetPlant");
    }

    DisplayBundle* getResult() override {
        return result;
    }

    ~TestBuilder() {
        delete result;
    }
};

// ---------------------------------------------------------------------------
// TEST CASE 1: Verify Director's sequence of builder calls
// ---------------------------------------------------------------------------
TEST_CASE("Director constructs bundles correctly") {
    Inventory* inv = new Inventory();

    // Create and add plants
    PlantState* tulipState = new UnplantedState();
    PlantState* roseState  = new UnplantedState();
    PlantState* fernState  = new UnplantedState();

    Plant* tulip = new Flowering("Tulipa gesneriana", 0, 50, 0, 0, 1.0, 0, tulipState);
    Plant* rose  = new Flowering("Rosa chinensis", 0, 50, 0, 0, 1.0, 0, roseState);
    Plant* fern  = new Fern("Nephrolepis exaltata", 0, 50, 0, 0, 1.0, 0, fernState);

    inv->addPlant(tulip);
    inv->addPlant(rose);
    inv->addPlant(fern);

    TestBuilder* builder = new TestBuilder();
    Director director(builder, inv);

    SUBCASE("Gift Bundle Construction - all plants available") {
        director.constructGiftBundle();

        REQUIRE(builder->calls.size() == 3);
        CHECK(builder->calls[0] == "addDecorativePlant");  // Tulip
        CHECK(builder->calls[1] == "addDecorativePlant");  // Rose
        CHECK(builder->calls[2] == "addBasicPlant");       // Fern
    }

    SUBCASE("Gift Bundle missing plant after removal") {
        // getPlant() removes the first match (Tulipa gesneriana)
        inv->getPlant("Tulipa gesneriana");

        builder->reset();
        director.constructGiftBundle();

        // Since tulip is missing, Director should not call builder methods
        CHECK(builder->calls.empty());
    }

    delete inv;
    delete builder;
}

// ---------------------------------------------------------------------------
// TEST CASE 2: Verify concrete builders produce distinct decorated bundles
// ---------------------------------------------------------------------------
TEST_CASE("Concrete Builders implement different behaviors") {
    Inventory* inv = new Inventory();

    // Add test plants
    PlantState* state1 = new UnplantedState();
    PlantState* state2 = new UnplantedState();
    PlantState* state3 = new UnplantedState();

    Plant* tulip = new Flowering("Tulipa gesneriana", 0, 50, 0, 0, 1.0, 0, state1);
    Plant* rose  = new Flowering("Rosa chinensis", 0, 50, 0, 0, 1.0, 0, state2);
    Plant* fern  = new Fern("Nephrolepis exaltata", 0, 50, 0, 0, 1.0, 0, state3);

    inv->addPlant(tulip);
    inv->addPlant(rose);
    inv->addPlant(fern);

    SUBCASE("GiftBuilder decorates flowering plants with ribbons") {
        Builder* builder = new GiftBuilder();
        Director director(builder, inv);

        director.constructGiftBundle();
        DisplayBundle* result = builder->getResult();

        CHECK(result != NULL);
        std::string output = result->toString();
        CHECK(output.find("Ribbon") != std::string::npos);

        delete builder;
    }

    SUBCASE("FrostReadyBuilder adds frost net protection") {
        PlantState* ricciaState = new UnplantedState();
        PlantState* mossState   = new UnplantedState();

        Plant* riccia = new NonFlowering("Riccia fluitans", 0, 50, 0, 0, 1.0, 0, ricciaState);
        Plant* moss   = new Moss("Bryum argenteum", 0, 50, 0, 0, 1.0, 0, mossState);

        inv->addPlant(riccia);
        inv->addPlant(moss);

        Builder* builder = new FrostReadyBuilder();
        Director director(builder, inv);

        director.constructFrostReadyBundle();
        DisplayBundle* result = builder->getResult();

        CHECK(result != NULL);
        std::string output = result->toString();
        // Match the actual Frost decorator string ("FrostNet" or similar)
        CHECK(output.find("Frost_net") != std::string::npos);

        delete builder;
    }

    delete inv;
}
