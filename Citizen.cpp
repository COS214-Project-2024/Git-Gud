#include "Citizen.h"

void Citizen::update(ChangeData changeData){

    if(changeData.changeType == "TaxChange"){

        handleTaxChange(changeData.value);

    } else if(changeData.changeType == "BuildingConstructed"){

        handleBuildingConstructed(changeData.value);

    }

}

void Citizen::handleTaxChange(float changeInTaxRate){

    if(changeInTaxRate > 0){ //increase in tax

        //subtract SatisfactionLevel float by 'changeInTaxRate'

    } else if(changeInTaxRate < 0){ //decrease in tax

        //add SatisfactionLevel float by 'changeInTaxRate'

    }

}

void Citizen::handleBuildingConstructed(float BuildingFloat){

    if(BuildingFloat == 1.0f){

        //set satisfaction level (decrease float by 1)

    } else if(BuildingFloat == 2.0f || BuildingFloat == 3.0f){

        //+0.5

    } else if(BuildingFloat == 4.0f){

        //+2

    }


}