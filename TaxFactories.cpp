#include "TaxFactories.h"

float TaxFactories::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    std::list<IndustrialBuilding*>::iterator buildingIt;
    for (buildingIt = indBuildings.begin(); buildingIt != indBuildings.end(); buildingIt++){
        int buildingTax;
        switch ((*buildingIt)->getIndustryType())
        {
        case MANUFACTURING:
            int factor = (*buildingIt)->getNumStories()-(*buildingIt)->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            buildingTax = tax*factor;
            break;
        case ENERGY:
            int factor = 5-(*buildingIt)->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            buildingTax = tax*factor;
            break;
        case TECHNOLOGY:
                buildingTax = tax*((*buildingIt)->getNumStories()+(*buildingIt)->getSize());
            break;
        default:
            break;
        }
        totalTax+=buildingTax; 
    }
    return totalTax;
}