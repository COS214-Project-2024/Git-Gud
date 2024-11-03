#ifndef PLAYER_H
#define PLAYER_H

#include "TaxManager.h"
#include "TaxCommercial.h"
#include "TaxFactories.h"
#include "TaxResidents.h"

class Player
{
private:
    float Balance = 0.0;
    TaxManager* taxMan;
public:
<<<<<<< Updated upstream
=======
    Player();
    ~Player();
    void changeTaxRate(float tax);

>>>>>>> Stashed changes
    void taxResidentialBuildings();
    void taxIndustrialBuildings();
    void taxCommercialBuildings();

    void addResidentialBuilding(ResidentialBuilding* residentialBuilding);
    void addIndustrialBuilding(IndustrialBuilding* industrialBuilding);
    void addCommercialBuilding(CommercialBuilding* commercialBuilding);
<<<<<<< Updated upstream
=======

    float getBalance();

    TaxManager* getTaxMan(){return taxMan;};
    
>>>>>>> Stashed changes
};


#endif // PLAYER_H