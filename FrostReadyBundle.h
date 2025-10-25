#ifndef FrostReadyBundle_H
#define FrostReadyBundle_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class FrostReadyBundle : public Builder {
private:
    DisplayBundle* bundle;
public:
    FrostReadyBundle();
    void reset();
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    void addFertilisedPlant(Plant* name);
    void addFrostNetPlant(Plant* name);
    DisplayBundle* getResult();
    ~FrostReadyBundle();
};

#endif
