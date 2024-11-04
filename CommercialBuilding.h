/**
 * @file CommercialBuilding.h
 * @brief Header file for the CommercialBuilding class, representing a type of building focused on business operations.
 */

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include <iostream>


/**
 * @class CommercialBuilding
 * @brief Class representing a commercial building that provides services to citizens and supports various business types.
 * @details Inherits from the Building class and includes specific attributes such as size, number of stories, and business type.
 */
class CommercialBuilding : public Building{

    private:
        /// @brief The size of the commercial building.
        int size;

        /// @brief The number of stories in the commercial building.
        int numStories;

        /// @brief The type of business the building operates.
        BusinessType businessType;

    public:

        /**
         * @brief Get the size of the commercial building.
         * @return int representing the size.
         */
        int getSize();

        /**
         * @brief Get the number of stories of the commercial building.
         * @return int representing the number of stories.
         */
        int getNumStories();

        /**
         * @brief Get the business type of the commercial building.
         * @return BusinessType indicating the type of business.
         */
        BusinessType getBusinessType();

        /**
         * @brief Add employees to the commercial building.
         */
        void addEmployees();

        /**
         * @brief Destructor for the CommercialBuilding class.
         */
        ~CommercialBuilding();

    //protected: Changed to accomodate factory
        /**
         * @brief Constructor for creating a CommercialBuilding with specified capacity, size, number of stories, and business type.
         * @param capacity The maximum number of occupants the building can hold.
         * @param size The size of the building.
         * @param numStories The number of stories in the building.
         * @param businessType The type of business the building operates.
         */
        CommercialBuilding(int capacity, int size, int numStories, BusinessType businessType);
        
         /**
         * @brief Constructor for creating a CommercialBuilding with a specified state, capacity, size, number of stories, and business type.
         * @param s Unique pointer to the initial state of the building.
         * @param capacity The maximum number of occupants the building can hold.
         * @param size The size of the building.
         * @param numStories The number of stories in the building.
         * @param businessType The type of business the building operates.
         */
        CommercialBuilding(std::unique_ptr<BuildingState> s, int capacity, int size, int numStories, BusinessType businessType);

        /**
         * @brief Provide a service specific to the commercial building.
         */
        virtual void provideService() override;

        /**
         * @brief Get the cost of the commercial building.
         * @return float representing the cost of the building.
         */
        virtual float getCost() override;

        /**
         * @brief Clone the commercial building object.
         * @return CommercialBuilding* Pointer to the cloned object.
         */
        virtual CommercialBuilding* clone();

};


#endif // COMMERCIALBUILDING_H