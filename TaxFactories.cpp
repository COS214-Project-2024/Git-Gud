#include "TaxFactories.h"

float TaxFactories::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    std::list<IndustrialBuilding*>::iterator buildingIt;
    for (buildingIt = indBuildings.begin(); buildingIt != indBuildings.end(); buildingIt++){
        int buildingTax;
        switch ((*buildingIt)->getIndustryType())
        {
        case MANUFACTURING:
            buildingTax = tax*((*buildingIt)->getNumStories()+(*buildingIt)->getPollutionLevel());
            break;
        case ENERGY:
            buildingTax = tax*((*buildingIt)->getPollutionLevel()*2);
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