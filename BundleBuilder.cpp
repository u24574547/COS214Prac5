#include "BundleBuilder.h"
#include <iostream>
#include <sstream>


BundleBuilder::BundleBuilder() {
    bundle = new DisplayBundle();
}

void BundleBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void BundleBuilder::addBasicPlant(Plant* name) {
    bundle->add(name);
}
void BundleBuilder::addDecorativePlant(Plant* name) {
    //I DONT KNOW HOW DECORATIVE PLANTS WORK YET SO THIS IS JUST FOR NOW ADDING TEXT
    // capture output of name->display() (which prints to stdout) into a string and append "(decorative)"
    std::ostringstream oss;
    std::streambuf* oldBuf = std::cout.rdbuf(oss.rdbuf());
    name->display();
    std::cout.rdbuf(oldBuf);
    std::string decoratedName = oss.str() + " (decorative)";
    bundle->add(new Plant(decoratedName)); // I dont have any actual DecorativePlant class so just appending text
}


DisplayBundle* BundleBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

BundleBuilder::~BundleBuilder() {
    if (bundle) delete bundle;
}
