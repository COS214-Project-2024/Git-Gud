/**
 * @file SatisfactionLevel.h
 * @brief Defines the SatisfactionLevel abstract base class for different satisfaction states.
 *
 * This file contains the definition of the SatisfactionLevel class, which serves as an abstract base class
 * for various satisfaction levels within a satisfaction hierarchy. Derived classes represent specific
 * satisfaction states and implement methods for state transitions, retrieving the current satisfaction
 * level, and obtaining the tax return rate associated with each state.
 *
 * Dependencies:
 * - Citizen.h: Provides context or entities that may interact with satisfaction levels.
 */

#ifndef SATISFACTIONLEVEL_H
#define SATISFACTIONLEVEL_H

#include <string>
#include "Citizen.h"

/**
 * @class SatisfactionLevel
 * @brief Abstract base class representing a satisfaction level.
 *
 * This class serves as the base class for different satisfaction states. It defines a common interface
 * with methods for entering and exiting states, retrieving the current satisfaction level as a string,
 * and obtaining the tax return rate for each specific state. Derived classes must implement these methods.
 */
class SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the satisfaction level.
     */
    float taxReturn;

public:
    /**
     * @brief Current satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Virtual destructor for the SatisfactionLevel class.
     *
     * This ensures proper cleanup of derived classes when deleted through a base class pointer.
     */
    virtual ~SatisfactionLevel() {}

    /**
     * @brief Method used to enter the next state.
     *
     * Derived classes must implement this method to define how to enter their specific state.
     */
    virtual void enterState() = 0;

    /**
     * @brief Method used to exit the current state.
     *
     * Derived classes must implement this method to define how to exit their specific state.
     */
    virtual void exitState() = 0;

    /**
     * @brief Method used to retrieve the current satisfaction level.
     * @return A string representing the current satisfaction level.
     */
    virtual std::string getCurrentSatisfactionLevel() = 0;

    /**
     * @brief Method used to retrieve the tax return for the current state.
     * @return The tax return rate as a float.
     */
    virtual float getTaxReturn() = 0;
};

#endif  // SATISFACTIONLEVEL_H
