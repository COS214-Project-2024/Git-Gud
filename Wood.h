#ifndef WOOD_H
#define WOOD_H

#include "Resource.h"

class Wood : public Resource {
public:
    Wood(int cost, int initialAmount) : Resource(cost, initialAmount) {}
};

#endif // WOOD_H