#include "BundleBuilder.h"
#include <iostream>

BundleBuilder::BundleBuilder() {
    bundle = new DisplayBundle();
}

void BundleBuilder::reset() {
    if (bundle) delete bundle;
    bundle = new DisplayBundle();
}

void BundleBuilder::addBasicPlant(const std::string& name) {
    bundle->add(new Plant(name));
}

void BundleBuilder::addDecorativePlant(const std::string& name) {
    bundle->add(new Plant(name + " (decorative)"));
}

DisplayBundle* BundleBuilder::getResult() {
    DisplayBundle* result = bundle;
    bundle = 0;
    return result;
}

BundleBuilder::~BundleBuilder() {
    if (bundle) delete bundle;
}
