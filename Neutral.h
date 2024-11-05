/**
 * @file Neutral.h
 * @brief Defines the Neutral class, representing a neutral level in a satisfaction hierarchy.
 *
 * This file contains the definition of the Neutral class, which is a subclass of SatisfactionLevel.
 * The Neutral class models a state of neutral satisfaction with specific behaviors and attributes,
 * including a tax return rate and satisfaction rating.
 *
 * Dependencies:
 * - SatisfactionLevel.h: Base class for satisfaction levels.
 * - Dissatisfied.h: Related satisfaction level class.
 * - Satisfied.h: Related satisfaction level class.
 */

#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"
#include "Satisfied.h"

/**
 * @class Neutral
 * @brief Represents a neutral level of satisfaction.
 *
 * This class inherits from SatisfactionLevel and represents a neutral state with
 * specific behaviors and attributes, such as a tax return rate and satisfaction rating.
 */
class Neutral : public SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the neutral state.
     */
    float taxReturn = 1.0;

public:
    /**
     * @brief Satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Default constructor for Neutral class.
     */
    Neutral() {}

    /**
     * @brief Destructor for Neutral class.
     */
    ~Neutral() {}

    /**
     * @brief Enters the neutral state.
     *
     * This method is used to transition into the neutral state.
     */
    void enterState() override;

    /**
     * @brief Exits the neutral state.
     *
     * This method is used to transition out of the neutral state.
     */
    void exitState() override;

    /**
     * @brief Retrieves the current satisfaction level as a string.
     * @return A string representing the current satisfaction level.
     */
    std::string getCurrentSatisfactionLevel() override;

    /**
     * @brief Retrieves the tax return rate for the neutral state.
     * @return The tax return rate as a float.
     */
    float getTaxReturn() override { return taxReturn; }
};

#endif  // NEUTRAL_H
