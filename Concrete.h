#ifndef CONCRETE_H
#define CONCRETE_H

#include "Resource.h"

class Concrete : public Resource {
public:
    Concrete(int cost, int initialAmount) : Resource(cost, initialAmount) {}
};

#endif // CONCRETE_H