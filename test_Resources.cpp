#include <gtest/gtest.h>
#include "Resources.h"

class ResourcesTest : public ::testing::Test {
protected:
    Resources resources;
};

TEST_F(ResourcesTest, Initialization) {
    EXPECT_EQ(resources.getWood(), 0);
    EXPECT_EQ(resources.getSteel(), 0);
    EXPECT_EQ(resources.getConcrete(), 0);
    EXPECT_EQ(resources.getBudget(), 0);
    EXPECT_EQ(resources.getWaterSupply(), 0);
    EXPECT_EQ(resources.getEnergySupply(), 0);
}

TEST_F(ResourcesTest, AddResources) {
    resources.addResource("wood", 10);
    resources.addResource("steel", 20);
    resources.addResource("concrete", 30);
    resources.addResource("waterSupply", 40);
    resources.addResource("energySupply", 50);

    EXPECT_EQ(resources.getWood(), 10);
    EXPECT_EQ(resources.getSteel(), 20);
    EXPECT_EQ(resources.getConcrete(), 30);
    EXPECT_EQ(resources.getWaterSupply(), 40);
    EXPECT_EQ(resources.getEnergySupply(), 50);
}

TEST_F(ResourcesTest, UseResources) {
    resources.addResource("wood", 10);
    resources.addResource("steel", 20);
    resources.useResource("wood", 5);
    resources.useResource("steel", 10);

    EXPECT_EQ(resources.getWood(), 5);
    EXPECT_EQ(resources.getSteel(), 10);
}

TEST_F(ResourcesTest, UseResourcesNegativeCheck) {
    resources.addResource("wood", 5);
    resources.useResource("wood", 10); // Attempt to use more than available

    EXPECT_EQ(resources.getWood(), 0); // Should not go below 0
}

TEST_F(ResourcesTest, AddAndSpendBudget) {
    resources.addBudget(1000);
    EXPECT_EQ(resources.getBudget(), 1000);

    resources.spendBudget(200);
    EXPECT_EQ(resources.getBudget(), 800);

    resources.spendBudget(1000); // Attempt to overspend
    EXPECT_EQ(resources.getBudget(), 0); // Budget should not go negative
}