#ifndef BUILDING_H
#define BUILDING_H

#include "BuildingState.h"
//#include "Citizen.h"
#include "Subject.h"

class Building : public Subject{

    private:
        BuildingState* state;
    public:
        Building();

};


#endif // BUILDING_H