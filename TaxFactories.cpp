#include "TaxFactories.h"

float TaxFactories::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    int factor = 1;
    std::list<IndustrialBuilding*>::iterator buildingIt;
    for (buildingIt = indBuildings.begin(); buildingIt != indBuildings.end(); buildingIt++){
        factor = 1;
        switch ((*buildingIt)->getIndustryType())
        {
        case MANUFACTURING:
            factor = (*buildingIt)->getNumStories()-(*buildingIt)->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            break;
        case ENERGY:
            factor = 5-(*buildingIt)->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            break;
        case TECHNOLOGY:
                factor = (*buildingIt)->getNumStories()+(*buildingIt)->getSize();
            break;
        default:
            break;
        }
        totalTax+=tax*factor; 
    }
    return totalTax;
}