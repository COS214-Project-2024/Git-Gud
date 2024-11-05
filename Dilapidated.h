/**
 * @file Dilapidated.h
 * @brief Header file for the Dilapidated class, representing a state where the building is in disrepair.
 */

#ifndef DILAPIDATED_H
#define DILAPIDATED_H

#include "BuildingState.h"

/**
 * @class Dilapidated
 * @brief Class representing the state of a building when it is dilapidated.
 * @details Inherits from the BuildingState class and provides specific implementations for state transitions and behavior in the dilapidated state.
 */

class Dilapidated : public BuildingState{

    public:

        /**
         * @brief Default constructor for the Dilapidated class.
         */
        Dilapidated() = default;  

        /**
         * @brief Destructor for the Dilapidated class.
         */
        ~Dilapidated(){};

        /**
         * @brief Enter the dilapidated state.
         * @param building Pointer to the Building object entering this state.
         */
        void enterState(Building *building) override;

        /**
         * @brief Exit the dilapidated state.
         * @param building Pointer to the Building object exiting this state.
         */
        void exitState(Building* building) override;

        /**
         * @brief Transition to the next state from the dilapidated state.
         * @param building Pointer to the Building object transitioning to the next state.
         */
        void nextState(Building* building) override;

        /**
         * @brief Get the current state as a string.
         * @return std::string representing the current state ("Dilapidated").
         */
        std::string getCurrentState() override;

};


#endif // DILAPIDATED_H