#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"

class IndustrialBuilding : public Building
{
private:
    
public:

    IndustrialBuilding(BuildingState* s);

    virtual void provideService();

    virtual int getCost();

};


#endif // INDUSTRIALBUILDING_H