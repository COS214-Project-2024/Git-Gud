#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"
#include "Subject.h"

class IndustrialBuilding : public Building{
    
    private:
        
    public:

    protected:
        IndustrialBuilding();

    IndustrialBuilding(BuildingState* s);

    virtual void provideService();

    virtual int getCost();

};


#endif // INDUSTRIALBUILDING_H