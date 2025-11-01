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
protected:
    /**
     * @brief The total price of the bundle or individual plant.
     */
    double price;

    /**
     * @brief Default constructor.
     * 
     * Initialises the price to 0.0 to ensure derived bundles start with
     * a defined value.
     */
    Bundle() : price(0.0) {}


public:
    /**
     * @brief Displays the bundle.
     * 
     * Concrete subclasses should implement this to show the bundle's content.
     */
    virtual std::string toString() const = 0;
    /**
     * @brief Calculates the total price of the bundle.
     * 
     * Concrete subclasses implement this function to return the total
     * price of the bundle. Composite bundles should sum the prices of their
     * contained components, while leaf objects
     * should return their individual price.
     * 
     * @return The total price of this bundle.
     */
    virtual double getPrice() const = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Bundle() {}
};

#endif