#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"
#include "Subject.h"
#include "ChangeData.h"

class Citizen{

    private:
        SatisfactionLevel* satisfactionLevel;
        bool hasJob;

    public:
        Citizen();
        virtual ~Citizen();
        Citizen(bool hasJob);
        virtual void update(ChangeData changeData);
        void handleTaxChange(float newTaxRate);
        void handleBuildingConstructed(float BuildingNum);
        bool getHasJob();
        void setJobStatus(bool jobStatus);
        void setState(SatisfactionLevel* satislevel);

};


#endif // CITIZEN_H