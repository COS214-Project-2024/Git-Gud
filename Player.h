#ifndef PLAYER_H
#define PLAYER_H

#include "TaxManager.h"
#include "TaxCommercial.h"
#include "TaxFactories.h"
#include "TaxResidents.h"
#include "GameEnvironment.h"
#include "Utility.h"


class GameEnvironment;

class Player
{
private:
    float Balance;
    TaxManager* taxMan;
public:
    void changeTaxRate(float tax);

    void taxResidentialBuildings();
    void taxIndustrialBuildings();
    void taxCommercialBuildings();

    void addResidentialBuilding(ResidentialBuilding* residentialBuilding);
    void addIndustrialBuilding(IndustrialBuilding* industrialBuilding);
    void addCommercialBuilding(CommercialBuilding* commercialBuilding);

    float getBalance();
    void provideServiceForUtility(int x, int y, int radius, Utility *utility, GameEnvironment *gameEnv);
};


#endif // PLAYER_H