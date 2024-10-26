#ifndef POWER_H
#define POWER_H

#include "Resource.h"

class Power : public Resource {
public:
    Power(int cost, int initialAmount) : Resource(cost, initialAmount) {}
};

#endif // POWER_H