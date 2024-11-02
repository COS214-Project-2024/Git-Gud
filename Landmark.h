#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"
#include "GameEnvironment.h"

class LandmarkBuilding : public Building{

    private:
        int landmarkName;
    public:
        

   // protected: changed to accomodate factory
        LandmarkBuilding(int capacity);
        LandmarkBuilding(std::unique_ptr<BuildingState> s, int capacity);

        virtual void provideService() override;
        virtual float getCost() override;

        virtual LandmarkBuilding* clone();

};


#endif // LANDMARKBUILDING_H