/**
 * @file BuildingWithParking.h
 * @author GitGud
 * @brief Concrete decorator used to add a parking lot to a Building object
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef BUILDINGWITHPARKING_H
#define BUILDINGWITHPARKING_H

#include "Decorator.h"
#include <vector>

class BuildingWithParking : public Decorator{

public:

    /**
     * @brief Construct a new Building With Parking object
     * 
     * @param b 
     */
    BuildingWithParking(Building* b);

    /**
     * @brief Construct a new Building With Parking object
     * 
     */
    BuildingWithParking(){this->buildingState=nullptr;};

    /**
     * @brief Method used to provide additional service on top of the service from the Building-object being decorated
     * 
     */
    virtual void provideService();

    /**
     * @brief Get the cost of the decorated Building
     * 
     * @return float 
     */
    virtual float getCost();

    /**
     * @brief Set the State object
     * 
     * @param s 
     */
    virtual void setState(std::unique_ptr<BuildingState> s);

    /**
     * @brief Repair the Decorated building
     * 
     */
    virtual void repairBuilding();

    /**
     * @brief Get the current state of the Building as a string
     * 
     * @return std::string 
     */
    virtual std::string currentState();

    /**
     * @brief Simulate the construction of the Building
     * 
     */
    virtual void simulateConstruction();

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
     * @brief Method sued to add employees to the decorated building
     * 
     */
    virtual void addEmployees();

    /**
     * @brief Get the size of the Building
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
     * @brief Add Citizens to the decorated Building
     * 
     */
    virtual void addCitizens();

    /**
     * @brief Get a list of the Citizens that live in the decorated building
     * 
     * @return std::list<Citizen*> 
     */
    virtual std::list<Citizen*> getTenants();

    /**
     * @brief Add a workers that will work at the parking lot
     * 
     */
    virtual void addWorker();

    /**
     * @brief Method sued to clone the a BuildingWithParking object
     * 
     * @return BuildingWithParking* 
     */
    virtual BuildingWithParking* clone();

    virtual ~BuildingWithParking(){};

};

#endif