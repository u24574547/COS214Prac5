#ifndef GiftBuilder_H
#define GiftBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class GiftBuilder : public Builder {
private:
    DisplayBundle* bundle;
public:
    GiftBuilder();
    void reset();
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    void addFertilisedPlant(Plant* name);
    DisplayBundle* getResult();
    ~GiftBuilder();
};

#endif
