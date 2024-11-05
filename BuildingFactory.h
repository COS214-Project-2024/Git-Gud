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

  


public:

    BuildingFactory(){
        Rmanager=ResourceManager::getInstance();
    };

    /**
     * @brief Method used to retrieve a Building-object
     * 
     * @return Building* 
     */
    virtual Building* constructBuilding(){return nullptr;}

    /**
     * @brief Method sued to Decorate a building passed in
     * 
     * @param b 
     * @return Building* 
     */
    virtual Building* upgradeBuilding(Building* b){return nullptr;} // This method is used to Decorate buildings

    /**
     * @brief Method sued to clone a Building
     * 
     * @return Building* 
     */
    virtual Building* cloneBuilding(Building* b){return nullptr;}      

    /**
     * @brief Destroy the Building Factory object
     * 
     */
    virtual ~BuildingFactory();

      /// @brief ResourceManager used to check for available resources
    ResourceManager* Rmanager;


};


#endif // BUILDINGFACTORY_H