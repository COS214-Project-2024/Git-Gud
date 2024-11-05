#include "gtest/gtest.h"
#include <gmock/gmock.h>
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
    Player p;
    EXPECT_EQ(p.getBalance(),0.0f);
}

TEST_F(StrategyTest, taxCitizensTest){
    Player p;
    ResidentialBuilding* r1 = new ResidentialBuilding(10);
    r1->addCitizens();
    p.addResidentialBuilding(r1);
    p.changeTaxRate(10.0);
    p.taxResidentialBuildings();
    EXPECT_EQ(p.getBalance(),25.0f);
}

TEST_F(StrategyTest, taxMultipleCitizensTest){
    Player p;
    ResidentialBuilding* r1 = new ResidentialBuilding(5);//62.5
    ResidentialBuilding* r2 = new ResidentialBuilding(15);
    r1->addCitizens();
    r2->addCitizens();
    p.addResidentialBuilding(r1);
    p.addResidentialBuilding(r2);
    p.changeTaxRate(50.0);
    p.taxResidentialBuildings();
    EXPECT_EQ(p.getBalance(),93.75f);
}

TEST_F(StrategyTest, taxCommerialTest){
    Player p;
    CommercialBuilding* c1 = new CommercialBuilding(10,10,5,LUXURY);
    p.addCommercialBuilding(c1);
    p.changeTaxRate(10.0);
    p.taxCommercialBuildings();
    EXPECT_EQ(p.getBalance(),20.0f);
}

TEST_F(StrategyTest, taxMultipleCommercialTest){
    Player p;
    CommercialBuilding* c1 = new CommercialBuilding(10,10,5,LUXURY);
    CommercialBuilding* c2 = new CommercialBuilding(10,10,5,FOOD);
    CommercialBuilding* c3 = new CommercialBuilding(10,10,5,GENERAL);
    p.addCommercialBuilding(c1);
    p.addCommercialBuilding(c2);
    p.addCommercialBuilding(c3);
    p.changeTaxRate(10.0);
    p.taxCommercialBuildings();
    EXPECT_EQ(p.getBalance(),45.0f);
}

TEST_F(StrategyTest, taxIndustrialTest){
    Player p;
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    p.addIndustrialBuilding(i1);
    p.changeTaxRate(10.0);
    p.taxIndustrialBuildings();
    EXPECT_EQ(p.getBalance(),30.0f);
}

TEST_F(StrategyTest, taxMultipleIndustrialTest){
    Player p;
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    IndustrialBuilding* i2 = new IndustrialBuilding(10,50,5,TECHNOLOGY,2);
    IndustrialBuilding* i3 = new IndustrialBuilding(10,50,5,ENERGY,4);
    p.addIndustrialBuilding(i1);
    p.addIndustrialBuilding(i2);
    p.addIndustrialBuilding(i3);
    p.changeTaxRate(10.0);
    p.taxIndustrialBuildings();
    EXPECT_EQ(p.getBalance(),190.0f);
}