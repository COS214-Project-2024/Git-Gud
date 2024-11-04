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
   // std::cout << "test" << std::endl;
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
bool Player::createRoad(int x, int y){
    gameEnv->createRoad(x, y);
    return true;

}

bool Player::buildIndustrialBuilding(int x, int y){
    Building* newBuilding = fetchBuildingFromJunkYard("IndustrialBuilding");

    if (newBuilding==nullptr){
        newBuilding = industrialFactory->constructBuilding();
    }

    return addBuilding(newBuilding, x, y);
    
}

bool Player::buildCommercialBuilding(int x, int y){
    Building* newBuilding = fetchBuildingFromJunkYard("CommercialBuilding");

    if (newBuilding==nullptr){
        newBuilding = commercialFactory->constructBuilding();
    }

    return addBuilding(newBuilding, x, y);
}

bool Player::buildResidentialBuilding(int x, int y){
    Building* newBuilding = fetchBuildingFromJunkYard("ResidentialBuilding");

    if (newBuilding==nullptr){
        newBuilding = residentialFactory->constructBuilding();
    }

    return addBuilding(newBuilding, x, y);
}

bool Player::buildLandmark(int x, int y){
    Building* newBuilding = fetchBuildingFromJunkYard("LandmarkBuilding");

    if (newBuilding==nullptr){
        newBuilding = landmarkFactory->constructBuilding();
    }

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
            gameEnv->decouple(x,y);
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
            gameEnv->decouple(x,y);
            return gameEnv->add(newBuilding, x, y);
        }else{
            return false;
        }
    }
    return false;
}

//Utility addition logic

bool Player::buildSewageSystem(int x, int y){

    Utility* newUtility = fetchUtilityFromJunkYard("SewageSystem");

    if (newUtility==nullptr){
        newUtility = sewageFactory->createUtility(100, 1000);
    }

    return addUtility(newUtility, x, y);
}

bool Player::buildWasteManagement(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("WasteManagement");

    if (newUtility==nullptr){
        newUtility = wasteFactory->createUtility(100, 1000);
    }

    return addUtility(newUtility, x, y);
}

bool Player::buildPowerPlant(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("PowerPlant");

    if (newUtility==nullptr){
        newUtility = powerFactory->createUtility(100, 1000);
    }

    return addUtility(newUtility, x, y);
}

bool Player::buildWaterFilteringPlant(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("WaterFilteringPlant");

    if (newUtility==nullptr){
        newUtility = waterFactory->createUtility(100, 1000);
    }
    return addUtility(newUtility, x, y);
}

bool Player::buildHealthCare(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("HealthCare");

    if (newUtility==nullptr){
        newUtility = healthFactory->createUtility(100, 1000);
    }
    return addUtility(newUtility, x, y);
}

bool Player::buildEducation(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("Education");

    if (newUtility==nullptr){
        newUtility = educationFactory->createUtility(100, 1000);
    }
    return addUtility(newUtility, x, y);
}

bool Player::buildLawEnforcement(int x, int y){
    Utility* newUtility = fetchUtilityFromJunkYard("LawEnforcement");

    if (newUtility==nullptr){
        newUtility = lawFactory->createUtility(100, 1000);
    }
    return addUtility(newUtility, x, y);
}

std::string Player::printRow(int currRow){
    return gameEnv->printTerminal(currRow);
}

int Player::getWood(){
    return resourceManager->getWood();
}

int Player::getSteel(){
    return resourceManager->getSteel();
}

int Player::getConcrete(){
    return resourceManager->getConcrete();
}

int Player::getPower(){
    return resourceManager->getEnergySupply();
}

int Player::getWater(){
    return resourceManager->getWaterSupply();
}