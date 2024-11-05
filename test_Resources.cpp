#include <gtest/gtest.h>
#include "Resources.h"

// Test Suite for Resources
class ResourcesTest : public ::testing::Test {
protected:
    Resources resources; // Default initialization

    void SetUp() override {
        resources = Resources(10, 20, 30, 40, 50, 1000, 60); // Initialize with specific values
    }
};

TEST_F(ResourcesTest, Initialization) {
    EXPECT_EQ(resources.getWoodResource().getAmount(), 10);
    EXPECT_EQ(resources.getSteelResource().getAmount(), 20);
    EXPECT_EQ(resources.getConcreteResource().getAmount(), 30);
    EXPECT_EQ(resources.getWaterSupplyResource().getAmount(), 40);
    EXPECT_EQ(resources.getEnergySupplyResource().getAmount(), 50);
    EXPECT_EQ(resources.getBudgetResource().getAmount(), 1000);
    EXPECT_EQ(resources.getWasteCapacityResource().getAmount(), 60);
}

TEST_F(ResourcesTest, AddResourceAmounts) {
    resources.getWoodResource().addAmount(5);
    resources.getSteelResource().addAmount(10);
    resources.getConcreteResource().addAmount(15);
    EXPECT_EQ(resources.getWoodResource().getAmount(), 15);
    EXPECT_EQ(resources.getSteelResource().getAmount(), 30);
    EXPECT_EQ(resources.getConcreteResource().getAmount(), 45);
}

TEST_F(ResourcesTest, SubtractResourceAmounts) {
    resources.getWoodResource().subtractAmount(5);
    resources.getSteelResource().subtractAmount(10);
    resources.getConcreteResource().subtractAmount(15);
    EXPECT_EQ(resources.getWoodResource().getAmount(), 5);
    EXPECT_EQ(resources.getSteelResource().getAmount(), 10);
    EXPECT_EQ(resources.getConcreteResource().getAmount(), 15);
}

TEST_F(ResourcesTest, ResourceAmountsCannotGoNegative) {
    resources.getWoodResource().subtractAmount(15);
    resources.getSteelResource().subtractAmount(30);
    EXPECT_EQ(resources.getWoodResource().getAmount(), 0);
    EXPECT_EQ(resources.getSteelResource().getAmount(), 0);
}