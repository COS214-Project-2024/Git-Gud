/**
 * @file BuildingWithParkingFactory.h
 * @author GitGud
 * @brief Conctrete Factory class used to retrieve objects of type BuildingWithParking
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGWITHPARKINGFACTORY_H
#define BUILDINGWITHPARKINGFACTORY_H

#include "BuildingFactory.h"
#include "BuildingWithParking.h"

class BuildingWithParkingFactory : public BuildingFactory{

public:

    /**
     * @brief Construct a new Building With Parking Factory object
     * 
     */
    BuildingWithParkingFactory();

    /**
     * @brief Method used to decorate a building and to return a pointer to that object
     * 
     * @param b 
     * @return Building* 
     */
    virtual BuildingWithParking* upgradeBuilding(Building* b);

    /**
     * @brief Method sued to return a pointer to a copy of the object of this type
     * 
     * @return Building* 
     */
    virtual BuildingWithParking* cloneBuilding();

};

#endif