/**
 * @file UnderConstruction.h
 * @brief Header file for the UnderConstruction class, representing the state of a building that is under construction.
 */

#ifndef UNDERCONSTRUCTION_H
#define UNDERCONSTRUCTION_H

#include "BuildingState.h"

/**
 * @class UnderConstruction
 * @brief Class representing the "Under Construction" state of a building.
 * @details This class defines the behavior of a building while it is in the under construction state.
 */
class UnderConstruction : public BuildingState{
    
    public:
        /**
         * @brief Default constructor for the UnderConstruction class.
         */
        UnderConstruction() = default;  

        /**
         * @brief Destructor for the UnderConstruction class.
         */
        ~UnderConstruction(){};

        /**
         * @brief Method called when entering the Under Construction state.
         * @param building Pointer to the Building that is transitioning into this state.
         */
        void enterState(Building *building) override;

        /**
         * @brief Method called when exiting the Under Construction state.
         * @param building Pointer to the Building that is transitioning out of this state.
         */
        void exitState(Building* building) override;

        /**
         * @brief Transition to the next state from Under Construction.
         * @param building Pointer to the Building that is transitioning to the next state.
         */
        void nextState(Building* building) override;

        /**
         * @brief Get the current state as a string.
         * @return std::string The name of the current state.
         */
        std::string getCurrentState() override;
    

};


#endif // UNDERCONSTRUCTION_H