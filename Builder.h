#ifndef BUILDER_H
#define BUILDER_H

#include <string>

// Forward declaration
class DisplayBundle;

class Builder {
public:
    virtual void reset() = 0;
    virtual void addBasicPlant(const std::string& name) = 0;
    virtual void addDecorativePlant(const std::string& name) = 0;
    virtual DisplayBundle* getResult() = 0;
    virtual ~Builder() {}
};

#endif
