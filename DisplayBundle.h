#ifndef DISPLAYBUNDLE_H
#define DISPLAYBUNDLE_H

#include "Bundle.h"
#include <vector>

class DisplayBundle : public Bundle {
private:
    std::vector<Bundle*> components;
public:
    void add(Bundle* b);
    void display() const;
    ~DisplayBundle();
};

#endif
