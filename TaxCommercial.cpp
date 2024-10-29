#include "TaxCommercial.h"

float TaxCommercial::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    std::list<CommercialBuilding*>::iterator buildingIt;
    for (buildingIt = comBuildings.begin(); buildingIt != comBuildings.end(); buildingIt++){
        int buildingTax;
        switch ((*buildingIt)->getBusinessType())
        {
        case LUXURY:
            buildingTax = tax*2;
            break;
        case FOOD:
            buildingTax = tax*1.5;
            break;
        case GENERAL:
            buildingTax = tax;
            break;
        default:
            break;
        }
        totalTax+=buildingTax*(*buildingIt)->getNumStories(); 
    }
    return totalTax;
}