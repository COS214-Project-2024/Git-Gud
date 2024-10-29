#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"
#include "Subject.h"

class Citizen{

    private:
        SatisfactionLevel* satisfactionLevel;
        bool hasJob;

    public:
        Citizen();
        Citizen(bool hasJob);
        void update(ChangeData changeData);
        void handleTaxChange(float newTaxRate);
        void handleBuildingConstructed(float BuildingNum);
        bool getHasJob();
        void setJobStatus(bool jobStatus);

};


#endif // CITIZEN_H