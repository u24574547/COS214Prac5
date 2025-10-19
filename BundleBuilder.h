#ifndef BUNDLEBUILDER_H
#define BUNDLEBUILDER_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class BundleBuilder : public Builder {
private:
    DisplayBundle* bundle;
public:
    BundleBuilder();
    void reset();
    void addBasicPlant(const std::string& name);
    void addDecorativePlant(const std::string& name);
    DisplayBundle* getResult();
    ~BundleBuilder();
};

#endif
