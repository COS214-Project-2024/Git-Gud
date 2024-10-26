#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"

class CommercialBuilding : public Building
{
private:
    
public:

    CommercialBuilding(BuildingState* s);

    virtual void provideService();

    virtual int getCost();

};


#endif // COMMERCIALBUILDING_H