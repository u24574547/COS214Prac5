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
     * @brief Default constructor.
     * 
     * Initializes the DisplayBundle with an empty component list and a price of 0.0.
     */
    DisplayBundle();
    /**
     * @brief Adds a sub-bundle to the display bundle.
     * 
     * @param b Pointer to a Bundle object to add as a component.
     */
    void add(Bundle* b);
    /**
     * @brief Calculates the total price of this DisplayBundle.
     * 
     * Iterates through all contained Bundle components, sums their prices,
     * and returns the total price for the composite bundle.
     * @return The total price of all components within this DisplayBundle.
     */
    double getPrice() const;

    /**
     * @brief Returns a string representation of the DisplayBundle.
     * 
     * Should provide information about all contained components.
     * @return A string describing the contents of this DisplayBundle.
     */
    std::string toString() const override;

    /**
     * @brief Destructor to clean up allocated resources.
     */
    ~DisplayBundle();
};

#endif
