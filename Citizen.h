#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"
#include "Subject.h"

class Citizen{

    private:
        SatisfactionLevel* satisfactionLevel;
    public:
        void update(ChangeData changeData);
        void handleTaxChange(float newTaxRate);
        void handleBuildingConstructed(float BuildingNum);

};


#endif // CITIZEN_H