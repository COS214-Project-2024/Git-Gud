#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <list>

//tax manager and tax strategies
#include "TaxManager.h"
#include "TaxCommercial.h"
#include "TaxFactories.h"
#include "TaxResidents.h"
// game environment and architecture
#include "GameEnvironment.h"
//building factories
#include "IndustrialBuildingFactory.h"
#include "CommercialBuildingFactory.h"
#include "ResidentialBuildingFactory.h"
#include "LandmarkFactory.h"
//building decorator factories
#include "BuildingWithCoffeeShopFactory.h"
#include "BuildingWithParkingFactory.h"
// utility factories
#include "SewageSystemFactory.h"
#include "WasteManagementFactory.h"
#include "PowerPlantFactory.h"
#include "WaterFilteringPlantFactory.h"
#include "HealthCareFactory.h"
#include "EducationFactory.h"
#include "LawEnforcementFactory.h"
//Resource Manager
#include "ResourceManager.h"



//#include "Utility.h"
//GameEnvironment and other classes already #include all the concrete utility and factory implementations

class Player
{
private:
    //tax manager and tax strategies
    float Balance = 0.0;// should we be getting dis fom resourceManager?
    TaxManager* taxMan;
    GameEnvironment* gameEnv;
    //factories
    BuildingFactory* industrialFactory;
    BuildingFactory* commercialFactory;
    BuildingFactory* residentialFactory;
    BuildingFactory* landmarkFactory;
    //decorator factories
    BuildingFactory* coffeeShopFactory;
    BuildingFactory* parkingFactory;
    //utility factories
    UtilityFactory* sewageFactory;
    UtilityFactory* wasteFactory;
    UtilityFactory* powerFactory;
    UtilityFactory* waterFactory;
    UtilityFactory* healthFactory;
    UtilityFactory* educationFactory;
    UtilityFactory* lawFactory;
    //resource manager
    ResourceManager* resourceManager;

    //JunkYard. Things that failed to get added to the game go here

    list<Building*> leftOverBuildings;
    list<Utility*> leftOverUtilities;

    bool addBuilding(Building* newBuilding, int x, int y)
    {
        if (newBuilding){
            if (gameEnv->add(newBuilding, x, y)){
                resourceManager->spendBudget(newBuilding->getCost());
                return true;
            }
            else{
                delete newBuilding;
                return false;
            }       
        }
        return false;
    };

    

public:
    Player();
    ~Player();
    void changeTaxRate(float tax);

    //Love, Death and Taxes
    //use these in the addition logic
    void taxResidentialBuildings();
    void taxIndustrialBuildings();
    void taxCommercialBuildings();
    void registerResidentialBuilding(ResidentialBuilding* residentialBuilding);
    void registerIndustrialBuilding(IndustrialBuilding* industrialBuilding);
    void registerCommercialBuilding(CommercialBuilding* commercialBuilding);

    float getBalance();

    //TaxManager* getTaxMan(){return taxMan;};

    // Bob the builder can't fix this

    bool buildIndustrialBuilding(int x, int y);
    bool buildCommercialBuilding(int x, int y);
    bool buildResidentialBuilding(int x, int y);
    bool buildLandmark(int x, int y);

    //decorator buildings
    bool upgradeBuildingWithCoffeeShop(int x, int y);
    bool upgradeBuildingWithParking(int x, int y);

    //We can do what Sasol can't
    bool buildSewageSystem(int x, int y);
    bool buildWasteManagement(int x, int y);
    bool buildPowerPlant(int x, int y);
    bool buildWaterFilteringPlant(int x, int y);
    bool buildHealthCare(int x, int y);
    bool buildEducation(int x, int y);
    bool buildLawEnforcement(int x, int y);

    
    
};


#endif // PLAYER_H