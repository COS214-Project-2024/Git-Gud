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

#include "Subject.h"
#include "Citizen.h"
#include "UnderConstruction.h"
#include "BuildingState.h"
#include <list>

enum BusinessType {LUXURY, FOOD, GENERAL, NONE};

enum Industry {MANUFACTURING, ENERGY, TECHNOLOGY};

class Building : public Subject{

    protected:

        int capacity;

        /// @brief State of the Building
        BuildingState* buildingState;

    public:
    
        Building(int capacity);
        Building();
        virtual ~Building();

        virtual Building* clone() const = 0;

        /// @brief Generic function that provides a service to it's Citizens (e.g. CommercialBuilding wou,,d pay it's Citizens)
        virtual void provideService()=0;

        /// @brief  Get the cost of the Building
        /// @return int
        virtual float getCost() = 0; 

        virtual void setState(BuildingState* s);

        virtual void repairBuilding();

        virtual std::string currentState();

        virtual void simulateConstruction();

        // Added these methods to ensure the type is preserved after decorated
        virtual int getNumStories(){return 0;};

        virtual BusinessType getBusinessType(){NONE;};

        virtual void addEmployees(){};

        virtual int getSize(){return 0;};

        virtual float getPollutionLevel(){return 0;};

        virtual void addCitizens(){};

        virtual std::list<Citizen*> getTenants(){
            std::list<Citizen*> c;
            return c;
        };

        virtual void addWorker(){};

        virtual Building* clone()=0;

};


#endif // BUILDING_H