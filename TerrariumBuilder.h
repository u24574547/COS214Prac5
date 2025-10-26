#ifndef TerrariumBuilder_H
#define TerrariumBuilder_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class TerrariumBuilder : public Builder {
private:
    DisplayBundle* bundle;
public:
    TerrariumBuilder();
    void reset();
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    void addFertilisedPlant(Plant* name);
    DisplayBundle* getResult();
    ~TerrariumBuilder();
};

#endif
