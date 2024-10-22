#ifndef DECORATOR_H
#define DECORATOR_H

#include "Building.h"

class Decorator : public Building
{
private:
    Building* building;
public:
    void addCitizen();
};

#endif // DECORATOR_H