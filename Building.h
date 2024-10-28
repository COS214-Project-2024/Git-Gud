/**
 * @file Building.h
 * @author your name (you@domain.com)
 * @brief Base class of the Building hierarchy
 * @version 0.1
 * @date 2024-10-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDING_H
#define BUILDING_H

#include "Citizen.h"
#include "UnderConstruction.h"
#include "BuildingState.h"

class Building : public Subject{
    
    private:
        BuildingState* buildingState;

    protected:

        /// @brief State of the Building
        BuildingState* state;

        /// @brief Units of water consumed
        int water;

        /// @brief Units of power consumed
        int power;

        int cost;

    public:
    
        Building();

        /// @brief Generic function that provides a service to it's Citizens (e.g. CommercialBuilding wou,,d pay it's Citizens)
        virtual void provideService()=0;

        /// @brief  Get the cost of the Building
        /// @return int
        virtual int getCost()=0; 

        virtual void setState(BuildingState* s);
        void repairBuilding();
        std::string currentState();

};


#endif // BUILDING_H