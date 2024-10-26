#ifndef STEEL_H
#define STEEL_H

#include "Resource.h"

class Steel : public Resource {
public:
    Steel(int cost, int initialAmount) : Resource(cost, initialAmount) {}
};

#endif // STEEL_H