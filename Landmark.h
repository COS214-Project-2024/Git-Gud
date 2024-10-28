#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"

class LandmarkBuilding : public Building{

    private:
        int landmarkName;
    public:

    protected: 
        LandmarkBuilding();

        LandmarkBuilding(BuildingState* s);

        virtual void provideService() override;

        virtual float getCost() override;

};


#endif // LANDMARKBUILDING_H