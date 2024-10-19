#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include "Building.h"
#include <list>

class ResidentialBuilding : public Building
{
private:
    std::list<Citizen*> tenants;
public:

};


#endif // RESIDENTIALBUILDING_H