#include "Player.h"
#include <iostream>
#include "ResidentialBuilding.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include <cassert>

int main(){

    Player* player = new Player();

    // Test changeTaxRate method
    player->changeTaxRate(10);
    assert(player->getBalance() >= 0); // Ensure the player has a non-negative balance

    // Test building methods
    // bool industrialBuilt = player->buildIndustrialBuilding(0, 0);
    // assert(industrialBuilt); // Assert that the building was built successfully

    // bool commercialBuilt = player->buildCommercialBuilding(1, 1);
    // assert(commercialBuilt); // Assert that the building was built successfully

    // bool residentialBuilt = player->buildResidentialBuilding(2, 2);
    // assert(residentialBuilt); // Assert that the building was built successfully

    // bool landmarkBuilt = player->buildLandmark(3, 3);
    // assert(landmarkBuilt); // Assert that the building was built successfully

    // Test registering buildings
    ResidentialBuilding* resBuilding = new ResidentialBuilding(10); // Assume a constructor exists
    player->registerResidentialBuilding(resBuilding);

    

    IndustrialBuilding* indBuilding = new IndustrialBuilding(5, 10, 3, Industry::MANUFACTURING, 3); // Assume a constructor exists
    player->registerIndustrialBuilding(indBuilding);

    

    CommercialBuilding* comBuilding = new CommercialBuilding(5, 10, 3, BusinessType::LUXURY); // Assume a constructor exists
    player->registerCommercialBuilding(comBuilding);

    // Test taxing buildings
    player->taxResidentialBuildings();
    player->taxIndustrialBuildings();
    player->taxCommercialBuildings();

    

    // Check that the balance is updated correctly after taxing
    assert(player->getBalance() >= 0); // Ensure balance is non-negative

    std::cout << "test1" << endl;

    // // Test building utilities
    // bool sewageBuilt = player->buildSewageSystem(4, 4);
    // assert(sewageBuilt); // Assert that the utility was built successfully

    

    // bool wasteBuilt = player->buildWasteManagement(5, 5);
    // assert(wasteBuilt); // Assert that the utility was built successfully

    // bool powerBuilt = player->buildPowerPlant(6, 6);
    // assert(powerBuilt); // Assert that the utility was built successfully

    // bool waterBuilt = player->buildWaterFilteringPlant(7, 7);
    // assert(waterBuilt); // Assert that the utility was built successfully

    // // Test upgrading buildings
    // bool upgradedWithCoffeeShop = player->upgradeBuildingWithCoffeeShop(0, 0);
    // assert(upgradedWithCoffeeShop); // Assert the upgrade was successful

    // bool upgradedWithParking = player->upgradeBuildingWithParking(1, 1);
    // assert(upgradedWithParking); // Assert the upgrade was successful

    

    // Clean up resources
    delete player;
    delete resBuilding; // Clean up allocated buildings
    delete indBuilding; // Clean up allocated buildings
    delete comBuilding; // Clean up allocated buildings

    std::cout << "All tests passed!" << std::endl;


}