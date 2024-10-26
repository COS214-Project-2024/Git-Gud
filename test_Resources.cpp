// test_Resources.cpp
#include <gtest/gtest.h>
#include "Resources.h"

TEST(ResourcesTest, Initialization) {
    Resources resources(10, 20, 30, 100, 50, 60);
    EXPECT_EQ(resources.getWood(), 10);
    EXPECT_EQ(resources.getSteel(), 20);
    EXPECT_EQ(resources.getConcrete(), 30);
    EXPECT_EQ(resources.getBudget(), 100);
    EXPECT_EQ(resources.getWaterSupply(), 50);
    EXPECT_EQ(resources.getEnergySupply(), 60);
}

TEST(ResourcesTest, AddResources) {
    Resources resources;
    resources.addWood(15);
    resources.addSteel(25);
    resources.addConcrete(35);
    resources.addBudget(150);
    resources.addWaterSupply(40);
    resources.addEnergySupply(50);

    EXPECT_EQ(resources.getWood(), 15);
    EXPECT_EQ(resources.getSteel(), 25);
    EXPECT_EQ(resources.getConcrete(), 35);
    EXPECT_EQ(resources.getBudget(), 150);
    EXPECT_EQ(resources.getWaterSupply(), 40);
    EXPECT_EQ(resources.getEnergySupply(), 50);
}

TEST(ResourcesTest, UseResources) {
    Resources resources(10, 20, 30, 100, 50, 60);
    resources.useWood(5);
    resources.useSteel(10);
    resources.useConcrete(15);
    resources.spendBudget(50);
    resources.useWaterSupply(20);
    resources.useEnergySupply(30);

    EXPECT_EQ(resources.getWood(), 5);
    EXPECT_EQ(resources.getSteel(), 10);
    EXPECT_EQ(resources.getConcrete(), 15);
    EXPECT_EQ(resources.getBudget(), 50);
    EXPECT_EQ(resources.getWaterSupply(), 30);
    EXPECT_EQ(resources.getEnergySupply(), 30);
}

TEST(ResourcesTest, UseResourcesNegativeCheck) {
    Resources resources(5, 5, 5, 5, 5, 5);
    resources.useWood(10);
    resources.useSteel(10);
    resources.useConcrete(10);
    resources.spendBudget(10);
    resources.useWaterSupply(10);
    resources.useEnergySupply(10);

    EXPECT_EQ(resources.getWood(), 0);
    EXPECT_EQ(resources.getSteel(), 0);
    EXPECT_EQ(resources.getConcrete(), 0);
    EXPECT_EQ(resources.getBudget(), 0);
    EXPECT_EQ(resources.getWaterSupply(), 0);
    EXPECT_EQ(resources.getEnergySupply(), 0);
}
