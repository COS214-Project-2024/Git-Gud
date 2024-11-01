/**
 * @file BuildingFactory.h
 * @author GitGud
 * @brief Base class Of the BuildingFactory hierarchy used to retrieve Building-objects
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGFACTORY_H
#define BUILDINGFACTORY_H

#include "Building.h"
#include "ResourceManager.h"

class BuildingFactory
{
protected:

    /// @brief ResourceManager used to check for available resources
    ResourceManager* Rmanager;

    /// @brief Building-object that will be cloned by cloneBuilding method
    Building* building;

    // Units of resources used to construct each building
    int wood;
    int steel;
    int concrete;
    int water;
    int power;

public:

    /**
     * @brief Method used to retrieve a Building-object
     * 
     * @return Building* 
     */
    virtual Building* constructBuilding(){};

    /**
     * @brief Method sued to Decorate a building passed in
     * 
     * @param b 
     * @return Building* 
     */
    virtual Building* upgradeBuilding(Building* b){}; // This method is used to Decorate buildings

    /**
     * @brief Method sued to clone a Building
     * 
     * @return Building* 
     */
    virtual Building* cloneBuilding(){};      

    /**
     * @brief Set the Building object
     * 
     * @param b 
     */
    virtual void setBuilding(Building* b);

    /**
     * @brief Destroy the Building Factory object
     * 
     */
    virtual ~BuildingFactory();

};


#endif // BUILDINGFACTORY_H