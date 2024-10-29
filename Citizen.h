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
        bool getHasJob();
        void setJobStatus(bool jobStatus);
        void setState(SatisfactionLevel* satislevel);

        //void update(ChangeData changeData);
        void handleTaxChange(float newTaxRate);
        void handleBuildingConstructed(float BuildingNum);
        
        /// @brief Returns the satifaction level of the citizen
        /// @return SatisfactionLevel*
        SatisfactionLevel* getSatisfactionLevel();

        /// @brief sets the satifaction level of the citizen
        void setSatisfactionLevel(SatisfactionLevel* satisfactionLevel);

};


#endif // CITIZEN_H