/**
 * @file Landmark.h
 * @brief Header file for the LandmarkBuilding class, representing significant buildings with historical or architectural value.
 */

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"

/**
 * @class LandmarkBuilding
 * @brief Class representing a landmark building, which holds historical or architectural significance.
 * @details Inherits from the Building class and includes specific attributes and behaviors related to landmark buildings.
 */
class LandmarkBuilding : public Building{

    private:
        /// @brief An identifier for the landmark building
        int landmarkName;
    public:
        
        /**
         * @brief Default destructor for the LandmarkBuilding class.
         */
        ~LandmarkBuilding() = default;
   // protected: changed to accomodate factory

        /**
         * @brief Constructor for creating a LandmarkBuilding with a specified capacity.
         * @param capacity The maximum number of occupants the building can hold.
         */
        LandmarkBuilding(int capacity);

        /**
         * @brief Constructor for creating a LandmarkBuilding with a specified state and capacity.
         * @param s Unique pointer to the initial state of the building.
         * @param capacity The maximum number of occupants the building can hold.
         */
        LandmarkBuilding(std::unique_ptr<BuildingState> s, int capacity);

        /**
         * @brief Get the building type
         * @return string representing the building type
         */
        std::string getType() override;

        /**
         * @brief Provide a service specific to the landmark building.
         */
        virtual void provideService() override;

        /**
         * @brief Get the cost of the landmark building.
         * @return float representing the cost of the building.
         */
        virtual float getCost() override;

        /**
         * @brief Clone the landmark building object.
         * @return LandmarkBuilding* Pointer to the cloned object.
         */
        virtual LandmarkBuilding* clone();

};


#endif // LANDMARKBUILDING_H