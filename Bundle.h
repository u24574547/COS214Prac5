#ifndef BUNDLE_H
#define BUNDLE_H

#include <iostream>
//manditory change for commit
class Bundle {
public:
    virtual void display() const = 0;
    virtual ~Bundle() {}
};

#endif
