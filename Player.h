#ifndef PLAYER_H
#define PLAYER_H

#include "TaxManager.h"
#include "TaxCommercial.h"
#include "TaxFactories.h"
#include "TaxResidents.h"

class Player
{
private:
    float Balance;
    TaxManager* taxMan;
public:
    void taxResidentialBuildings();
    void taxIndustrialBuildings();
    void taxCommercialBuildings();

    void addResidentialBuilding(ResidentialBuilding* residentialBuilding);
    void addIndustrialBuilding(IndustrialBuilding* industrialBuilding);
    void addCommercialBuilding(CommercialBuilding* commercialBuilding);
};


#endif // PLAYER_H