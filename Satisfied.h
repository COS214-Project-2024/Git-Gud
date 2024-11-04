/**
 * @file Satisfied.h
 * @brief Defines the Satisfied class, representing a satisfied level in a satisfaction hierarchy.
 *
 * This file contains the definition of the Satisfied class, which is a subclass of SatisfactionLevel.
 * The Satisfied class models a satisfied state with specific attributes, such as a tax return rate
 * and a satisfaction rating. It provides methods for entering and exiting the state, retrieving the
 * current satisfaction level as a string, and obtaining the tax return rate for the satisfied state.
 *
 * Dependencies:
 * - SatisfactionLevel.h: Base class for satisfaction levels.
 * - VerySatisfied.h: Related satisfaction level class representing a higher satisfaction level.
 * - Neutral.h: Related satisfaction level class representing a neutral satisfaction level.
 */

#ifndef SATISFIED_H
#define SATISFIED_H

#include "SatisfactionLevel.h"
#include "VerySatisfied.h"
#include "Neutral.h"

/**
 * @class Satisfied
 * @brief Represents a satisfied level of satisfaction.
 *
 * This class inherits from SatisfactionLevel and represents a satisfied state with
 * specific behaviors and attributes, such as a tax return rate and satisfaction rating.
 */
class Satisfied : public SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the satisfied state.
     */
    float taxReturn = 1.2;

public:
    /**
     * @brief Satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Default constructor for the Satisfied class.
     */
    Satisfied() {}

    /**
     * @brief Destructor for the Satisfied class.
     */
    ~Satisfied() {}

    /**
     * @brief Enters the satisfied state.
     *
     * This method is used to transition into the satisfied state.
     */
    void enterState() override;

    /**
     * @brief Exits the satisfied state.
     *
     * This method is used to transition out of the satisfied state.
     */
    void exitState() override;

    /**
     * @brief Retrieves the current satisfaction level as a string.
     * @return A string representing the current satisfaction level.
     */
    std::string getCurrentSatisfactionLevel() override;

    /**
     * @brief Retrieves the tax return rate for the satisfied state.
     * @return The tax return rate as a float.
     */
    float getTaxReturn() override { return taxReturn; }
};

#endif  // SATISFIED_H
