#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"

class Decorator : public Building{
private:
    Building* building;
public:
    virtual void provideService();
};

#endif // DECORATOR_H