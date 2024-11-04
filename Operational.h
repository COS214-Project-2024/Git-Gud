/**
 * @file Operational.h
 * @brief Header file for the Operational class, representing the operational state of a building.
 */

#ifndef OPERATIONAL_H
#define OPERATIONAL_H

#include "BuildingState.h"


/**
 * @class Operational
 * @brief Class representing the operational state of a building.
 * @details This class inherits from BuildingState and defines behaviors when a building is in an operational state.
 */
class Operational : public BuildingState{

    public:

        /**
         * @brief Default constructor for the Operational state.
         */
        Operational() = default;

        /**
         * @brief Default destructor for the Operational state.
         */  
        ~Operational(){};

        /**
         * @brief Enter the operational state of the building.
         * @param building Pointer to the Building that is entering this state.
         */
        void enterState(Building *building) override;

        /**
         * @brief Exit the operational state of the building.
         * @param building Pointer to the Building that is exiting this state.
         */
        void exitState(Building* building) override;

        /**
         * @brief Transition to the next state from the operational state.
         * @param building Pointer to the Building that is transitioning states.
         */
        void nextState(Building* building) override;

        /**
         * @brief Get the current state of the building as a string.
         * @return std::string representing the current state.
         */
        std::string getCurrentState() override;

};


#endif // OPERATIONAL_H