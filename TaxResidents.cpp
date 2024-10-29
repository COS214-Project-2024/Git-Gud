#include "TaxResidents.h"

float TaxResidents::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    std::list<ResidentialBuilding*>::iterator buildingIt;
    std::list<Citizen*>::iterator tenatIt;
    for (buildingIt = resBuildings.begin(); buildingIt != resBuildings.end(); buildingIt++){
        std::list<Citizen*> tenats = (*buildingIt)->getTenants();
        for (tenatIt = tenats.begin(); tenatIt != tenats.end(); tenatIt++){
            totalTax+= (*tenatIt)->getSatisfactionLevel()->getTaxReturn()*(tax*0.25);
        }
    }
    return totalTax;
}