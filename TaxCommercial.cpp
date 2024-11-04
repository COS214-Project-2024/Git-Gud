#include "TaxCommercial.h"
float TaxCommercial::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    for (CommercialBuilding* building : comBuildings){
        int buildingTax;
        switch (building->getBusinessType())
        {
        case LUXURY:
            buildingTax = tax*1.5;
            break;
        case FOOD:
            buildingTax = tax;
            break;
        case GENERAL:
            buildingTax = tax*0.5;
            break;
        default:
            break;
        }
        int factor = building->getNumStories()-3; //Additional Tax if building is large
        if (factor < 1)
        {
           factor = 1;
        }
        
        totalTax+=buildingTax*factor; 
    }
    return totalTax;
}