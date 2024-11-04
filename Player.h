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
#include "TrafficBuildingFactory.h"
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
using namespace std;

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
    TrafficBuildingFactory* trafficFactory;
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
                UtilityIterator* itr = gameEnv->createRadUtilItr(x, y, 3);
                Utility* temp;
                while (itr->current() != nullptr){
                    temp = itr->current()->getUtility("SewageSystem");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("PowerPlant");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("WaterFilteringPlant");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("WasteManagement");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("HealthCare");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("Education");
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }
                    temp = itr->current()->getUtility("LawEnforcement"); 
                    if (temp != nullptr){ temp->scanBuilding(newBuilding); }

                    itr->next();
                }
                return true;
            }
            else{
                leftOverBuildings.push_back(newBuilding);
                return false;
            }       
        }
        return false;
    };

    bool addUtility(Utility* newUtility, int x, int y)
    {
        if (newUtility){
            if (gameEnv->add(newUtility, x, y)){
                BuildingIterator* itr = gameEnv->createRadBuildItr(x, y, 3);

                while (itr->current() != nullptr){
                   newUtility->scanBuilding(itr->current());
                    itr->next();
                }
                newUtility->callObserver();
                delete itr;
                return true;
            } else {
                leftOverUtilities.push_back(newUtility);
                return false;
            }
        }
        return false;
    };

    Building* fetchBuildingFromJunkYard(string type){
        Building* temp;
        for (list<Building*>::iterator it = leftOverBuildings.begin(); it != leftOverBuildings.end(); ++it){
            temp = *it;
            if (temp->getType() == type){
                leftOverBuildings.erase(it);
                return temp;
            }
        }
        return nullptr;
    };

    Utility* fetchUtilityFromJunkYard(string type){
        Utility* temp;
        for (list<Utility*>::iterator it = leftOverUtilities.begin(); it != leftOverUtilities.end(); ++it){
            temp = *it;
            if (temp->getUtilityType() == type){
                leftOverUtilities.erase(it);
                return temp;
            }
        }
        return nullptr;
    };
        

public:
    Player();
    ~Player();
    void changeTaxRate(float tax);

    int getWood();
    int getSteel();
    int getConcrete();
    int getPower();
    int getWater();
    

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

    bool createRoad(int x, int y);
    bool buildIndustrialBuilding(int x, int y);
    bool buildCommercialBuilding(int x, int y);
    bool buildResidentialBuilding(int x, int y);
    bool buildLandmark(int x, int y);
    bool buildTaxiTrafficBuilding(int x, int y);
    bool buildBusTrafficBuilding(int x, int y);
    bool buildTrainTrafficBuilding(int x, int y);
    bool buildAirportTrafficBuilding(int x, int y);
    

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

    //Junky Yard
    std::string printRow(int currRow);



    
    
};


#endif // PLAYER_H