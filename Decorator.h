/**
 * @file Decorator.h
 * @author GitGud
 * @brief Base class of the Decorator hierarchy used to decorate Building-objects
 * @version 0.1
 * @date 2024-11-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"
#include "ResourceManager.h"
#include <memory>

class Decorator : public Building{
protected:

    /// @brief Building-object that is being decorated
    Building* building;

public:

    /**
     * @brief Method used to provide a service to Citizens
     * 
     */
    virtual void provideService(){};

    /**
     * @brief Get the cost of the decorated Building
     * 
     * @return float 
     */
    virtual float getCost()=0;

    /**
     * @brief Method sued to return a pointer to a copy of the object
     * 
     * @return Decorator* 
     */
    virtual Decorator* clone()=0;

    /**
     * @brief Destroy the Decorator object
     * 
     */
    virtual ~Decorator();

};

#endif // DECORATOR_H