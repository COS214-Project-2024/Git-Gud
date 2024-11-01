#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"
#include "ResourceManager.h"

class Decorator : public Building{
protected:

    Building* building;

public:

    virtual void provideService(){};

    virtual float getCost()=0;

    virtual Decorator* clone()=0;

    virtual ~Decorator();

};

#endif // DECORATOR_H