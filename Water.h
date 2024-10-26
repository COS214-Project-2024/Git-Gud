#ifndef WATER_H
#define WATER_H

#include "Resource.h"

class Water : public Resource {
public:
    Water(int cost, int initialAmount) : Resource(cost, initialAmount) {}
};

#endif // WATER_H