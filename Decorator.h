#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"
#include "ResourceManager.h"

class Decorator : public Building{
protected:

    Building* building;

public:

    Decorator(Building* b, int cap);

    virtual void provideService(){};

    virtual float getCost(){};

    virtual ~Decorator();

};

#endif // DECORATOR_H