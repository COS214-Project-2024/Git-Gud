/**
 * @file test_Strategy.cpp
 * @author Git-Gud
 * @brief Unit tests for strategy (tax)
 * @version 0.1
 * @date 2024-11-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "gtest/gtest.h"
#include "Player.h"
#include "Citizen.h"
#include "TaxManager.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"


class StrategyTest : public ::testing::Test {

    protected:
        Player player;

};

TEST_F(StrategyTest, testBalance){
    EXPECT_EQ(player.getBalance(),0.0f);
}

TEST_F(StrategyTest, taxCitizensTest){
    ResidentialBuilding* r1 = new ResidentialBuilding(10);
    EXPECT_EQ(r1->getTenants().size(),10);
    player.addResidentialBuilding(new ResidentialBuilding(10));
    player.changeTaxRate(10.0f);
    player.taxResidentialBuildings();
    EXPECT_EQ(player.getBalance(),25.0f);
    delete r1;
}

TEST_F(StrategyTest, taxMultipleCitizensTest){
    ResidentialBuilding* r1 = new ResidentialBuilding(6);
    ResidentialBuilding* r2 = new ResidentialBuilding(15);
    EXPECT_EQ(r1->getTenants().size(),6);
    EXPECT_EQ(r2->getTenants().size(),15);
    player.addResidentialBuilding(r1);
    player.addResidentialBuilding(r2);
    player.changeTaxRate(50.0);
    player.taxResidentialBuildings();
    EXPECT_EQ(player.getBalance(),262.5f);
    delete r1;
    delete r2;
}

TEST_F(StrategyTest, taxCommerialTest){
    CommercialBuilding* c1 = new CommercialBuilding(10,10,5,LUXURY);
    player.addCommercialBuilding(c1);
    player.changeTaxRate(10.0);
    player.taxCommercialBuildings();
    EXPECT_EQ(player.getBalance(),30.0f);
    delete c1;
}

TEST_F(StrategyTest, taxMultipleCommercialTest){
    CommercialBuilding* c1 = new CommercialBuilding(10,10,3,LUXURY);
    CommercialBuilding* c2 = new CommercialBuilding(10,10,1,FOOD);
    CommercialBuilding* c3 = new CommercialBuilding(10,10,5,GENERAL);
    player.addCommercialBuilding(c1);
    player.addCommercialBuilding(c2);
    player.addCommercialBuilding(c3);
    player.changeTaxRate(20.0);
    player.taxCommercialBuildings();
    EXPECT_EQ(player.getBalance(),70.0f);
    delete c1;
    delete c2;
    delete c3;
}

TEST_F(StrategyTest, taxIndustrialTest){
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    player.addIndustrialBuilding(i1);
    player.changeTaxRate(10.0);
    player.taxIndustrialBuildings();
    EXPECT_EQ(player.getBalance(),30.0f);
    delete i1;
}

TEST_F(StrategyTest, taxMultipleIndustrialTest){
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    IndustrialBuilding* i2 = new IndustrialBuilding(10,50,5,TECHNOLOGY,2);
    IndustrialBuilding* i3 = new IndustrialBuilding(10,50,5,ENERGY,4);
    player.addIndustrialBuilding(i1);
    player.addIndustrialBuilding(i2);
    player.addIndustrialBuilding(i3);
    player.changeTaxRate(10.0);
    player.taxIndustrialBuildings();
    EXPECT_EQ(player.getBalance(),90.0f);
    delete i1;
    delete i2;
    delete i3;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}