/**
 * @file BuildingWithCoffeeShopFactory.h
 * @author GitGud
 * @brief Concrete Factory used to retrieve an object of type BuildingWithCoffeeShop
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGWITHCOFFEESHOPFACTORY_H
#define BUILDINGWITHCOFFEESHOPFACTORY_H

#include "BuildingFactory.h"
#include "BuildingWithCoffeeshop.h"

class BuildingWithCoffeeShopFactory : public BuildingFactory{

public:

    /**
     * @brief Construct a new Building With Coffee Shop Factory object
     * 
     */
    BuildingWithCoffeeShopFactory(){};

    /**
     * @brief Method used to construct an object of type BuildingWithCoffeeShop
     * 
     * @param b 
     * @return Building* 
     */
    virtual BuildingWithCoffeeShop* upgradeBuilding(Building* b);

    /**
     * @brief Method used to return a pointer to a copy of the desired Building object
     * 
     * @return BuildingWithCoffeeShop* 
     */
    virtual BuildingWithCoffeeShop* cloneBuilding();

    /**
     * @brief Destroy the Building With Coffee Shop Factory object
     * 
     */
    virtual ~BuildingWithCoffeeShopFactory(){};

private:

    /// @brief Resources needed to construct the Building
    int power=5;
    int water=4;
    int wood=1;
    int steel=1;
    int concrete=1;

};

#endif