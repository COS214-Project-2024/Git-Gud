#ifndef SMALLER_H
#define SMALLER_H

#include "Decorator.h"

class Smaller : public Decorator
{
private:
    int capacity;
public:
    void addCitizen();
};

#endif // SMALLER_H