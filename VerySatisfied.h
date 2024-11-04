/**
 * @file VerySatisfied.h
 * @brief Defines the VerySatisfied class, representing a very satisfied level in a satisfaction hierarchy.
 *
 * This file contains the definition of the VerySatisfied class, which is a subclass of SatisfactionLevel.
 * The VerySatisfied class models a highly satisfied state with specific attributes, such as a high tax return rate
 * and a satisfaction rating. It provides methods for entering and exiting this state, retrieving the current satisfaction
 * level as a string, and obtaining the tax return rate for this highly satisfied state.
 *
 * Dependencies:
 * - SatisfactionLevel.h: Base class for satisfaction levels.
 * - Satisfied.h: Related satisfaction level class representing a lower satisfaction level.
 */

#ifndef VERYSATISFIED_H
#define VERYSATISFIED_H

#include "SatisfactionLevel.h"
#include "Satisfied.h"

/**
 * @class VerySatisfied
 * @brief Represents a very satisfied level of satisfaction.
 *
 * This class inherits from SatisfactionLevel and represents a very satisfied state with
 * specific behaviors and attributes, such as a tax return rate and satisfaction rating.
 */
class VerySatisfied : public SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the very satisfied state.
     */
    float taxReturn = 1.5;

public:
    /**
     * @brief Satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Default constructor for the VerySatisfied class.
     */
    VerySatisfied() {}

    /**
     * @brief Destructor for the VerySatisfied class.
     */
    ~VerySatisfied() {}

    /**
     * @brief Enters the very satisfied state.
     *
     * This method is used to transition into the very satisfied state.
     */
    void enterState() override;

    /**
     * @brief Exits the very satisfied state.
     *
     * This method is used to transition out of the very satisfied state.
     */
    void exitState() override;

    /**
     * @brief Retrieves the current satisfaction level as a string.
     * @return A string representing the current satisfaction level.
     */
    std::string getCurrentSatisfactionLevel() override;

    /**
     * @brief Retrieves the tax return rate for the very satisfied state.
     * @return The tax return rate as a float.
     */
    float getTaxReturn() override { return taxReturn; }
};

#endif  // VERYSATISFIED_H
