
#ifndef PLANT_H
#define PLANT_H

#include "Bundle.h"
#include <string>

class Plant : public Bundle {
private:
    std::string name;
public:
    Plant(const std::string& n);
    void display() const;
};

#endif
