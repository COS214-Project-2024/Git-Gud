/**
 * @file VeryDissatisfied.h
 * @brief Defines the VeryDissatisfied class, representing a very dissatisfied level in a satisfaction hierarchy.
 *
 * This file contains the definition of the VeryDissatisfied class, which is a subclass of SatisfactionLevel.
 * The VeryDissatisfied class models a highly dissatisfied state with specific attributes, including a low
 * tax return rate and a satisfaction rating. It provides methods for entering and exiting this state,
 * retrieving the current satisfaction level as a string, and obtaining the tax return rate for this state.
 *
 * Dependencies:
 * - SatisfactionLevel.h: Base class for satisfaction levels.
 * - Dissatisfied.h: Related satisfaction level class representing a higher level of satisfaction.
 */

#ifndef VERYDISSATISFIED_H
#define VERYDISSATISFIED_H

#include "SatisfactionLevel.h"
#include "Dissatisfied.h"

/**
 * @class VeryDissatisfied
 * @brief Represents a very dissatisfied level of satisfaction.
 *
 * This class inherits from SatisfactionLevel and represents a very dissatisfied state with
 * specific behaviors and attributes, such as a tax return rate and satisfaction rating.
 */
class VeryDissatisfied : public SatisfactionLevel {
protected:
    /**
     * @brief Tax return rate associated with the very dissatisfied state.
     */
    float taxReturn = 0.5;

public:
    /**
     * @brief Satisfaction rating associated with this state.
     */
    float satisfactionRating;

    /**
     * @brief Default constructor for the VeryDissatisfied class.
     */
    VeryDissatisfied() {}

    /**
     * @brief Destructor for the VeryDissatisfied class.
     */
    ~VeryDissatisfied() {}

    /**
     * @brief Enters the very dissatisfied state.
     *
     * This method is used to transition into the very dissatisfied state.
     */
    void enterState() override;

    /**
     * @brief Exits the very dissatisfied state.
     *
     * This method is used to transition out of the very dissatisfied state.
     */
    void exitState() override;

    /**
     * @brief Retrieves the current satisfaction level as a string.
     * @return A string representing the current satisfaction level.
     */
    std::string getCurrentSatisfactionLevel() override;

    /**
     * @brief Retrieves the tax return rate for the very dissatisfied state.
     * @return The tax return rate as a float.
     */
    float getTaxReturn() override { return taxReturn; }
};

#endif  // VERYDISSATISFIED_H
