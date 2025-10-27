#ifndef DISPLAYBUNDLE_H
#define DISPLAYBUNDLE_H

#include "Bundle.h"
#include <vector>

#include <iostream>
#include <sstream>

/**
 * @class DisplayBundle
 * @brief Composite bundle that can contain multiple Bundles for display.
 * 
 * DisplayBundle implements the Composite pattern, allowing a bundle
 * to contain other Bundles (components). It provides functionality
 * to add sub-bundles and display the entire composition.
 */
class DisplayBundle : public Bundle {
private:
    /**
     * @brief Vector of pointers to child Bundles (components).
     */
    std::vector<Bundle*> components;
public:
    /**
     * @brief Adds a sub-bundle to the display bundle.
     * 
     * @param b Pointer to a Bundle object to add as a component.
     */
    void add(Bundle* b);

    /**
     * @brief Displays the bundle and all its components.
     */
    std::string toString() const;

    /**
     * @brief Destructor to clean up allocated resources.
     */
    ~DisplayBundle();
};

#endif
