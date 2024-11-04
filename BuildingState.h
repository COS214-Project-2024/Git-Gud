/**
 * @file BuildingState.h
 * @brief Header file for the BuildingState class, representing the state of a building.
 */

#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include <iostream>

class Building; //Forward declartion

/**
 * @class BuildingState
 * @brief Abstract class representing the state of a building.
 * @details This class defines the interface for concrete building states, with methods for entering, exiting, transitioning to the next state, and getting the current state as a string.
 */
class BuildingState{

    public: 

        /**
         * @brief Virtual destructor for the BuildingState class.
         */
        virtual ~BuildingState(){};

        /**
         * @brief Enter the current state.
         * @param building Pointer to the Building object.
         */
        virtual void enterState(Building* building) = 0;

        /**
         * @brief Exit the current state.
         * @param building Pointer to the Building object.
         */
        virtual void exitState(Building* building) = 0;

        /**
         * @brief Transition to the next state.
         * @param building Pointer to the Building object.
         */
        virtual void nextState(Building* building) = 0;

        /**
         * @brief Get the current state as a string.
         * @return std::string representing the current state.
         */
        virtual std::string getCurrentState() = 0;

};


#endif // BUILDINGSTATE_H