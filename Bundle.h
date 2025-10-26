#ifndef BUNDLE_H
#define BUNDLE_H

#include <iostream>
/**
 * @class Bundle
 * @brief Abstract base class representing a plant bundle.
 * 
 * The Bundle class defines the interface for all bundles in the
 * system. Concrete bundles must implement the display() method.
 */
class Bundle {
public:
    /**
     * @brief Displays the bundle.
     * 
     * Concrete subclasses should implement this to show the bundle's content.
     */
    virtual void display() const = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Bundle() {}
};

#endif