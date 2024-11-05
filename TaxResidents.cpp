#include "TaxResidents.h"

float TaxResidents::CollectTax(std::list<ResidentialBuilding*> resBuildings, std::list<CommercialBuilding*> comBuildings, std::list<IndustrialBuilding*> indBuildings, float tax){
    float totalTax = 0;
    std::list<ResidentialBuilding*>::iterator buildingIt;
    for (ResidentialBuilding* building : resBuildings){
        std::list<Citizen*> tenants = building->getTenants();
        for (Citizen* tenant : tenants){
            totalTax+= tenant->getSatisfactionLevel()->getTaxReturn()*(tax*0.25);
        }
    }
    return totalTax;
}