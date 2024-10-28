#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"
#include "ResourceManager.h"

class Decorator : public Building{
protected:

    Building* building;

public:

    virtual void provideService(){};

    virtual int getCost()=0;

    virtual ~Decorator();

};

#endif // DECORATOR_H