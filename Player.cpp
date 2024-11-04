#include "Player.h"

//Instantiation of the player class
Player::Player(){
    taxMan = new TaxManager;

    industrialFactory = new IndustrialBuildingFactory();
    commercialFactory = new CommercialBuildingFactory();
    residentialFactory = new ResidentialBuildingFactory();
    landmarkFactory = new LandmarkFactory();
    coffeeShopFactory = new BuildingWithCoffeeShopFactory();
    parkingFactory = new BuildingWithParkingFactory();

    sewageFactory = new SewageSystemFactory();
    wasteFactory = new WasteManagementFactory();
    powerFactory = new PowerPlantFactory();
    waterFactory = new WaterFilteringPlantFactory();
    healthFactory = new HealthCareFactory();
    educationFactory = new EducationFactory();
    lawFactory = new LawEnforcementFactory();

    resourceManager = ResourceManager::getInstance();

    leftOverBuildings = std::list<Building*>();
    leftOverUtilities = std::list<Utility*>();

}

Player::~Player(){
    if (taxMan) {
        delete taxMan;
        taxMan = nullptr;
    }
}

//HMUNI

void Player::changeTaxRate(float tax){
    taxMan->updateTotalTaxRate(tax);
}

void Player::taxResidentialBuildings(){
    taxMan->chooseTaxMethod(new TaxResidents);
    resourceManager->addBudget(taxMan->calculateTax());
}

void Player::taxIndustrialBuildings(){
    taxMan->chooseTaxMethod(new TaxFactories);
    resourceManager->addBudget(taxMan->calculateTax());
}

void Player::taxCommercialBuildings(){
    taxMan->chooseTaxMethod(new TaxCommercial);
    resourceManager->addBudget(taxMan->calculateTax());
}

void Player::registerResidentialBuilding(ResidentialBuilding* residentialBuilding){
    taxMan->addResidential(residentialBuilding);
}   

void Player::registerIndustrialBuilding(IndustrialBuilding* industrialBuilding){
    taxMan->addIndustrial(industrialBuilding);
}

void Player::registerCommercialBuilding(CommercialBuilding* commercialBuilding){
    taxMan->addCommercial(commercialBuilding);
}

float Player::getBalance(){
    return resourceManager->getBudget();
}

//Building Addition Logic

bool Player::buildIndustrialBuilding(int x, int y){
    Building* newBuilding = industrialFactory->constructBuilding();

    return addBuilding(newBuilding, x, y);
    
}

bool Player::buildCommercialBuilding(int x, int y){
    Building* newBuilding = commercialFactory->constructBuilding();

    return addBuilding(newBuilding, x, y);
}

bool Player::buildResidentialBuilding(int x, int y){
    Building* newBuilding = residentialFactory->constructBuilding();

    return addBuilding(newBuilding, x, y);
}

bool Player::buildLandmark(int x, int y){
    Building* newBuilding = landmarkFactory->constructBuilding();

    return addBuilding(newBuilding, x, y);
}

//Upgrades people, upgrades. That's how we make the dough
//https://www.youtube.com/watch?v=99DeRHisQtI

bool Player::upgradeBuildingWithCoffeeShop(int x, int y){
    //At this point upgrading builings only costs resources, not money
    BuildingIterator* itr = gameEnv->createRadBuildItr(x, y, 0);
    Building* building = itr->current();

    delete itr;

    if (building){
        Building* newBuilding = coffeeShopFactory->upgradeBuilding(building);
        if (newBuilding){
            gameEnv->remove(x,y);
            return gameEnv->add(newBuilding, x, y);
        }else{
            return false;
        }
    }
    return false;          
}

bool Player::upgradeBuildingWithParking(int x, int y){
    //At this point upgrading builings only costs resources, not money
    BuildingIterator* itr = gameEnv->createRadBuildItr(x, y, 0);
    Building* building = itr->current();

    delete itr;

    if (building){
        Building* newBuilding = parkingFactory->upgradeBuilding(building);
        if (newBuilding){
            gameEnv->remove(x,y);
            return gameEnv->add(newBuilding, x, y);
        }else{
            return false;
        }
    }
    return false;
}

//Utility addition logic

bool Player::buildSewageSystem(int x, int y){
    Utility* newUtility = sewageFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildWasteManagement(int x, int y){
    Utility* newUtility = wasteFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildPowerPlant(int x, int y){
    Utility* newUtility = powerFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildWaterFilteringPlant(int x, int y){
    Utility* newUtility = waterFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildHealthCare(int x, int y){
    Utility* newUtility = healthFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildEducation(int x, int y){
    Utility* newUtility = educationFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}

bool Player::buildLawEnforcement(int x, int y){
    Utility* newUtility = lawFactory->createUtility(100, 1000);
    return addUtility(newUtility, x, y);
}





