/**
 * @file Dissatisfied.h
 * @brief Defines the Dissatisfied class, representing a dissatisfied level in a satisfaction hierarchy.
 *
 * This file contains the definition of the Dissatisfied class, which is a subclass of SatisfactionLevel.
 * The Dissatisfied class models a state with a specific satisfaction rating and tax return rate.
 * It includes methods for entering and exiting the state, as well as retrieving the current satisfaction
 * level and the tax return rate.
 *
 * Dependencies:
 * - SatisfactionLevel.h: Base class for satisfaction levels.
 * - Neutral.h: Potentially related satisfaction level class.
 * - VeryDissatisfied.h: Another potentially related satisfaction level class.
 */

#ifndef DISSATISFIED_H
#define DISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Neutral.h"
#include "VeryDissatisfied.h"

/**
 * @class Dissatisfied
 * @brief Represents a dissatisfied level of satisfaction.
 *
 * This class inherits from SatisfactionLevel and represents a dissatisfied state with
 * specific behaviors and attributes, such as a tax return rate and satisfaction rating.
 */
class Dissatisfied : public SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the dissatisfied state.
     */
    float taxReturn = 0.8;

public:
    /**
     * @brief Satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Default constructor for Dissatisfied class.
     */
    Dissatisfied() {}

    /**
     * @brief Destructor for Dissatisfied class.
     */
    ~Dissatisfied() {}

    /**
     * @brief Enters the dissatisfied state.
     *
     * This method is used to transition into the dissatisfied state.
     */
    void enterState() override;

    /**
     * @brief Exits the dissatisfied state.
     *
     * This method is used to transition out of the dissatisfied state.
     */
    void exitState() override;

    /**
     * @brief Retrieves the current satisfaction level as a string.
     * @return A string representing the current satisfaction level.
     */
    std::string getCurrentSatisfactionLevel() override;

    /**
     * @brief Retrieves the tax return rate for the dissatisfied state.
     * @return The tax return rate as a float.
     */
    float getTaxReturn() override { return taxReturn; }
};

#endif  // DISSATISFIED_H
