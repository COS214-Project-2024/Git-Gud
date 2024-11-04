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
#include "TaxFactories.h"
#include "TaxResidents.h"
#include "TaxCommercial.h"
#include "Citizen.h"
#include "TaxManager.h"
#include "IndustrialBuilding.h"
#include "ResidentialBuilding.h"
#include "CommercialBuilding.h"


class StrategyTest : public ::testing::Test {

    protected:
        TaxManager tax;

};

TEST_F(StrategyTest, EmptyTax){
    tax.chooseTaxMethod(new TaxResidents);
    EXPECT_EQ(tax.calculateTax(),0.0f);
}

TEST_F(StrategyTest, taxCitizensTest){
    ResidentialBuilding* r1 = new ResidentialBuilding(10);
    EXPECT_EQ(r1->getTenants().size(),10);
    tax.addResidential(new ResidentialBuilding(10));
    tax.updateTotalTaxRate(10.0f);
    tax.chooseTaxMethod(new TaxResidents);
    EXPECT_EQ(tax.calculateTax(),25.0f);
    delete r1;
}

TEST_F(StrategyTest, taxMultipleCitizensTest){
    ResidentialBuilding* r1 = new ResidentialBuilding(6);
    ResidentialBuilding* r2 = new ResidentialBuilding(15);
    EXPECT_EQ(r1->getTenants().size(),6);
    EXPECT_EQ(r2->getTenants().size(),15);
    tax.addResidential(r1);
    tax.addResidential(r2);
    tax.updateTotalTaxRate(75.0);
    tax.updateTotalTaxRate(50.0);
    tax.chooseTaxMethod(new TaxResidents);
    EXPECT_EQ(tax.calculateTax(),262.5f);
    delete r1;
    delete r2;
}

TEST_F(StrategyTest, taxCommerialTest){
    CommercialBuilding* c1 = new CommercialBuilding(10,10,5,LUXURY);
    tax.addCommercial(c1);
    tax.updateTotalTaxRate(10.0);
    tax.chooseTaxMethod(new TaxCommercial);
    EXPECT_EQ(tax.calculateTax(),30.0f);
    delete c1;
}

TEST_F(StrategyTest, taxMultipleCommercialTest){
    CommercialBuilding* c1 = new CommercialBuilding(10,10,3,LUXURY);
    CommercialBuilding* c2 = new CommercialBuilding(10,10,1,FOOD);
    CommercialBuilding* c3 = new CommercialBuilding(10,10,5,GENERAL);
    tax.addCommercial(c1);
    tax.addCommercial(c2);
    tax.addCommercial(c3);
    tax.updateTotalTaxRate(20.0);
    tax.chooseTaxMethod(new TaxCommercial);
    EXPECT_EQ(tax.calculateTax(),70.0f);
    delete c1;
    delete c2;
    delete c3;
}

TEST_F(StrategyTest, taxIndustrialTest){
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    tax.addIndustrial(i1);
    tax.updateTotalTaxRate(10.0);
    tax.chooseTaxMethod(new TaxFactories);
    EXPECT_EQ(tax.calculateTax(),30.0f);
    delete i1;
}

TEST_F(StrategyTest, taxMultipleIndustrialTest){
    IndustrialBuilding* i1 = new IndustrialBuilding(10,50,5,MANUFACTURING,2);
    IndustrialBuilding* i2 = new IndustrialBuilding(10,50,5,TECHNOLOGY,2);
    IndustrialBuilding* i3 = new IndustrialBuilding(10,50,5,ENERGY,4);
    tax.addIndustrial(i1);
    tax.addIndustrial(i2);
    tax.addIndustrial(i3);
    tax.updateTotalTaxRate(10.0);
    tax.chooseTaxMethod(new TaxFactories);
    EXPECT_EQ(tax.calculateTax(),90.0f);
    delete i1;
    delete i2;
    delete i3;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}