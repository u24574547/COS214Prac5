#include "doctest.h"
#include "Fertiliser.h"
#include "FrostNet.h"
#include "Moss.h"
#include "Plant.h"
#include "Ribbon.h"


TEST_CASE("Single decorator tests") {
    SUBCASE("Ribbon") {
        Plant* base = new Moss("Phineas", 1,100);
        base = new Ribbon(base);
        std::string output = base->toString();
        CHECK(output.find("Ribbon") != std::string::npos);
        delete base;
    }

    SUBCASE("Fertiliser") {
        Plant* base = new Moss("Phineas", 1,100);
        base = new Fertiliser(base);
        std::string output = base->toString();
        CHECK(output.find("Fertiliser") != std::string::npos);
        delete base;
    }

    SUBCASE("Frost_net") {
        Plant* base = new Moss("Phineas", 1,100);
        base = new FrostNet(base);
        std::string output = base->toString();
        CHECK(output.find("Frost_net") != std::string::npos);
        delete base;
    }
}

TEST_CASE("Stacked decorator tests") {
    Plant* base = new Moss("Phineas", 1,100);
    base = new FrostNet(base);
    base = new Ribbon(base);
    std::string output = base->toString();
    CHECK(output.find("Frost_net") != std::string::npos);
    CHECK(output.find("Ribbon") != std::string::npos);
    base = new Fertiliser(base);
    output = base->toString();
    CHECK(output.find("Fertiliser") != std::string::npos);
    CHECK(output.find("Frost_net") != std::string::npos);
    CHECK(output.find("Ribbon") != std::string::npos);
    delete base;
}