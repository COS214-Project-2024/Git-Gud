#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"

class CommercialBuilding : public Building{

    private:
        
    public:

    protected:
        CommercialBuilding();

        CommercialBuilding(BuildingState* s);

        virtual void provideService() override;

        virtual float getCost() override;

};


#endif // COMMERCIALBUILDING_H