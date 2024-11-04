#include <gtest/gtest.h>
#include "Player.h"
#include "ResidentialBuilding.h"
#include "IndustrialBuilding.h"
#include "CommercialBuilding.h"
#include "Utility.h"

// Fixture for Player
class PlayerTest : public ::testing::Test {
protected:
    Player* player;

    void SetUp() override {
        player = new Player();
    }

    void TearDown() override {
        delete player;
    }
};

// Test for getBalance()
TEST_F(PlayerTest, GetBalance_InitialBalanceIsZero) {
    EXPECT_FLOAT_EQ(player->getBalance(), 0.0);
}

// Test for addBuilding() - using Residential Building as an example
TEST_F(PlayerTest, AddBuilding_AddResidentialBuildingSuccess) {
    ResidentialBuilding* residentialBuilding = new ResidentialBuilding();
    bool success = player->addBuilding(residentialBuilding, 1, 1);
    EXPECT_TRUE(success);
    delete residentialBuilding;
}

TEST_F(PlayerTest, AddBuilding_AddBuildingFailsWhenPositionOccupied) {
    ResidentialBuilding* residentialBuilding = new ResidentialBuilding();
    player->addBuilding(residentialBuilding, 1, 1); // First add
    bool success = player->addBuilding(residentialBuilding, 1, 1); // Attempt add again at same position
    EXPECT_FALSE(success);
    delete residentialBuilding;
}

// Test for addUtility() - using Sewage System as an example
TEST_F(PlayerTest, AddUtility_AddSewageSystemSuccess) {
    SewageSystem* sewageSystem = new SewageSystem();
    bool success = player->addUtility(sewageSystem, 2, 2);
    EXPECT_TRUE(success);
    delete sewageSystem;
}

// Test for changeTaxRate()
TEST_F(PlayerTest, ChangeTaxRate_TaxRateUpdated) {
    float initialBalance = player->getBalance();
    player->changeTaxRate(0.1f); // Adjust tax rate
    EXPECT_NE(player->getBalance(), initialBalance); // Assume balance changes after taxing buildings
}

// Test for fetchBuildingFromJunkYard()
TEST_F(PlayerTest, FetchBuildingFromJunkYard_ReturnsNullIfJunkyardEmpty) {
    Building* building = player->fetchBuildingFromJunkYard("ResidentialBuilding");
    EXPECT_EQ(building, nullptr);
}

TEST_F(PlayerTest, FetchBuildingFromJunkYard_ReturnsBuildingIfTypeMatches) {
    ResidentialBuilding* residentialBuilding = new ResidentialBuilding();
    player->addBuilding(residentialBuilding, 10, 10); // add to junkyard if fails
    Building* fetched = player->fetchBuildingFromJunkYard("ResidentialBuilding");
    EXPECT_NE(fetched, nullptr);
    EXPECT_EQ(fetched->getType(), "ResidentialBuilding");
    delete fetched;
}

// Additional tests for build functions
TEST_F(PlayerTest, BuildIndustrialBuilding_SuccessfulConstruction) {
    bool success = player->buildIndustrialBuilding(3, 3);
    EXPECT_TRUE(success);
}

TEST_F(PlayerTest, UpgradeBuildingWithCoffeeShop_BuildingExistsUpgradeSuccessful) {
    ResidentialBuilding* building = new ResidentialBuilding();
    player->addBuilding(building, 5, 5);
    bool upgraded = player->upgradeBuildingWithCoffeeShop(5, 5);
    EXPECT_TRUE(upgraded);
    delete building;
}
