#ifndef BIGGER_H
#define BIGGER_H

#include "Decorator.h"

class Bigger : public Decorator
{
private:
    int capacity;
public:
    void addCitizen();
};

#endif // BIGGER_H