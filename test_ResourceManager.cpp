// test_ResourceManager.cpp
#include <gtest/gtest.h>
#include "ResourceManager.h"

class ResourceManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        ResourceManager::resetInstance(); // Reset to ensure a fresh instance
    }
};

TEST_F(ResourceManagerTest, SingletonInstance) {
    ResourceManager* instance1 = ResourceManager::getInstance();
    ResourceManager* instance2 = ResourceManager::getInstance();
    EXPECT_EQ(instance1, instance2);
}

TEST_F(ResourceManagerTest, ResourceUsageAndAddition) {
    ResourceManager* manager = ResourceManager::getInstance();

    // Initialize resources directly for testing instead of adding
    manager->initializeResources(40, 20, 30, 10);   // Set Wood:10, Steel:20, Concrete:30, Water:40
    EXPECT_EQ(manager->getWood(), 10);       // Expecting wood to be 10
    EXPECT_EQ(manager->getSteel(), 20);      // Expecting steel to be 20
    EXPECT_EQ(manager->getConcrete(), 30);   // Expecting concrete to be 30
    EXPECT_EQ(manager->getWaterSupply(), 40);// Expecting water supply to be 40

    // Use resources to test decrementing values
    manager->useResources(5, 10, 15, 20, 5); // Subtract Wood:5, Steel:10, Concrete:15, Water:20, Energy:5
    EXPECT_EQ(manager->getWood(), 5);        // Wood should now be 5
    EXPECT_EQ(manager->getSteel(), 10);      // Steel should now be 10
    EXPECT_EQ(manager->getConcrete(), 15);   // Concrete should now be 15
    EXPECT_EQ(manager->getWaterSupply(), 20);// Water supply should now be 20
    EXPECT_EQ(manager->getEnergySupply(), 0);// No energy added initially, so it should be 0
}

TEST_F(ResourceManagerTest, SufficientMaterialsCheck) {
    ResourceManager* manager = ResourceManager::getInstance();
    manager->initializeResources(10, 10, 10, 10);   // Initialize with specific values
    manager->addEnergySupply(20);                   // Add initial energy

    EXPECT_TRUE(manager->sufficientMaterials(5, 5, 5, 5, 10));   // Should pass
    EXPECT_FALSE(manager->sufficientMaterials(15, 15, 15, 15, 25));  // Should fail
}