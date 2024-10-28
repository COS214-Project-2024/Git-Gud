#ifndef CITIZEN_H
#define CITIZEN_H

#include "SatisfactionLevel.h"

class Citizen{

    private:
        SatisfactionLevel* satisfactionLevel;
    public:
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