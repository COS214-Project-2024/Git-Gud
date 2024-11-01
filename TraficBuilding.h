#ifndef TRAFICBUILDING_H
#define TRAFICBUILDING_H

#include "Building.h"

class TraficBuilding: public Building{

    private:

    public:

    protected: 
        TraficBuilding() = default;

        TraficBuilding(BuildingState* s);

        virtual void provideService() override;

        virtual float getCost() override;

        virtual TraficBuilding* clone();

};

#endif // TRAFICBUILDING_H