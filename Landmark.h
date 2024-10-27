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

    virtual void provideService();

    virtual int getCost();

};


#endif // LANDMARKBUILDING_H