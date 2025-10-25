#ifndef GiftBundle_H
#define GiftBundle_H

#include "Builder.h"
#include "DisplayBundle.h"
#include "Plant.h"

class GiftBundle : public Builder {
private:
    DisplayBundle* bundle;
public:
    GiftBundle();
    void reset();
    void addBasicPlant(Plant* name);
    void addDecorativePlant(Plant* name);
    void addFertilisedPlant(Plant* name);
    DisplayBundle* getResult();
    ~GiftBundle();
};

#endif
