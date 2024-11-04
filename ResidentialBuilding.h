/**
 * @file ResidentialBuilding.h
 * @brief Header file for the ResidentialBuilding class, representing buildings designed for habitation.
 */

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include <list>

/**
 * @class ResidentialBuilding
 * @brief Class representing a residential building where citizens can live.
 * @details This class inherits from Building and includes functionalities specific to residential buildings.
 */
class ResidentialBuilding : public Building{

    private:
        /// @brief List of tenants residing in the residential building.
        std::list<Citizen*> tenants;
    public:

    //protected: Changed to accomodate factory
        /**
         * @brief Default destructor for the ResidentialBuilding class.
         */
        ~ResidentialBuilding();

        /**
         * @brief Constructor for creating a ResidentialBuilding with a specified capacity.
         * @param capacity The maximum number of occupants the building can hold.
         */
        ResidentialBuilding(int capacity);

        /**
         * @brief Constructor for creating a ResidentialBuilding with a specified state and capacity.
         * @param s Unique pointer to the initial state of the building.
         * @param capacity The maximum number of occupants the building can hold.
         */
        ResidentialBuilding(std::unique_ptr<BuildingState> s, int capacity);

        /**
         * @brief Provide a service specific to the residential building.
         */
        virtual void provideService() override;

        /**
         * @brief Get the cost of the residential building.
         * @return float representing the cost of the building.
         */
        virtual float getCost() override;

        /**
         * @brief Add citizens (tenants) to the residential building.
         */
        void addCitizens();

        /**
         * @brief Get the list of tenants in the residential building.
         * @return std::list<Citizen*> List of pointers to the citizens residing in the building.
         */
        std::list<Citizen*> getTenants();

        /**
         * @brief Clone the residential building object.
         * @return ResidentialBuilding* Pointer to the cloned object.
         */
        virtual ResidentialBuilding* clone();

};


#endif // RESIDENTIALBUILDING_H