#include "TaxFactories.h"

float TaxFactories::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    int factor = 1;
    for (IndustrialBuilding* buildings : indBuildings){
        factor = 1;
        switch (buildings->getIndustryType())
        {
        case MANUFACTURING:
            factor = buildings->getNumStories()-buildings->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            break;
        case ENERGY:
            factor = 5-buildings->getPollutionLevel();
            if(factor < 1){
                factor = 1;
            }
            break;
        case TECHNOLOGY:
                factor = (buildings->getNumStories());
            break;
        default:
            break;
        }
        totalTax+=tax*factor; 
    }
    return totalTax;
}