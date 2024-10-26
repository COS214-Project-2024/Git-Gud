#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"
#include "ResourceManager.h"

class Decorator : public Building{
private:

    Building* building;

public:

    virtual void provideService();

    virtual int getCost();

};

#endif // DECORATOR_H