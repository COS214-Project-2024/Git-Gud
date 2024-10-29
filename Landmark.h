#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"
#include "GameEnvironment.h"

class LandmarkBuilding : public Building{

    private:
        int landmarkName;
    public:

    protected: 
        LandmarkBuilding(int capacity);
        LandmarkBuilding(BuildingState* s, int capacity);

        virtual void provideService() override;
        virtual float getCost() override;

};


#endif // LANDMARKBUILDING_H