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
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    DisplayBundle* getResult();
    ~BundleBuilder();
};

#endif
