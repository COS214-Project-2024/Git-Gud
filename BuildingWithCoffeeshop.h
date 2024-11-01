/**
 * @file BuildingWithCoffeeshop.h
 * @author GitGud
 * @brief Concrete decorator class used to add a coffees hop to the Building
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGWITHCOFFEESHOP_H
#define BUILDINGWITHCOFFEESHOP_H

#include "Decorator.h"
#include <vector>

class BuildingWithCoffeeShop : public Decorator{

public:

    /**
     * @brief Construct a new Building With Coffee Shop object
     * 
     * @param b 
     */
    BuildingWithCoffeeShop(Building* b);

    /**
     * @brief Construct a new Building With Coffee Shop object
     * 
     */
    BuildingWithCoffeeShop(){};

    /**
     * @brief Method used to provide a service to the Citizens in the decorated Building
     * 
     */
    virtual void provideService();

    /**
     * @brief Get the Cost of the decorated Building
     * 
     * @return float 
     */
    virtual float getCost();

    /**
     * @brief Set the State object
     * 
     * @param s 
     */
    virtual void setState(BuildingState* s);

    /**
     * @brief Method used to repair the Building
     * 
     */
    virtual void repairBuilding();

    /**
     * @brief Method used to get the current state of the Building as a string
     * 
     * @return std::string 
     */
    virtual std::string currentState();

    /**
     * @brief Method sued to simulate the construction of the Building
     * 
     */
    virtual void simulateConstruction();

    /**
     * @brief Destroy the Building With Coffee Shop object
     * 
     */
    virtual ~BuildingWithCoffeeShop(){};

    /**
     * @brief Get the number of stories of the Building
     * 
     * @return int 
     */
    virtual int getNumStories();

    /**
     * @brief Get the Business Type object
     * 
     * @return BusinessType 
     */
    virtual BusinessType getBusinessType();

    /**
     * @brief Add a Citizen as an employee to the Building
     * 
     */
    virtual void addEmployees();

    /**
     * @brief Get the Size of the Building
     * 
     * @return int 
     */
    virtual int getSize();

    /**
     * @brief Get the Pollution Level of the Building
     * 
     * @return float 
     */
    virtual float getPollutionLevel();

    /**
     * @brief Method use to add a Citizen to the Building
     * 
     */
    virtual void addCitizens();

    /**
     * @brief Get a list of the Citizens that lives or works in the Building
     * 
     * @return std::list<Citizen*> 
     */
    virtual std::list<Citizen*> getTenants();

    /**
     * @brief Method used to return a pointer to a copy of the object
     * 
     * @return BuildingWithCoffeeShop* 
     */
    virtual BuildingWithCoffeeShop* clone();

    /**
     * @brief Method sued to add a worker to the Coffeeshop
     * 
     */
    virtual void addWorker();

};

#endif