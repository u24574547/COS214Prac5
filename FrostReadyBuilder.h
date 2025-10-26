#ifndef FrostReadyBuilder_H
#define FrostReadyBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class FrostReadyBuilder : public Builder {
private:
    DisplayBundle* bundle;
public:
    FrostReadyBuilder();
    void reset();
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    void addFertilisedPlant(Plant* name);
    void addFrostNetPlant(Plant* name);
    DisplayBundle* getResult();
    ~FrostReadyBuilder();
};

#endif
