#include <gtest/gtest.h>
#include "ResourceManager.h"

class ResourceManagerTest : public ::testing::Test {
protected:
    void SetUp() override {
        ResourceManager::resetInstance(); // Reset Singleton instance for each test
    }
};

TEST_F(ResourceManagerTest, SingletonInstance) {
    ResourceManager* instance1 = ResourceManager::getInstance();
    ResourceManager* instance2 = ResourceManager::getInstance();
    EXPECT_EQ(instance1, instance2); // Should be the same instance
}

TEST_F(ResourceManagerTest, InitializeResources) {
    ResourceManager* manager = ResourceManager::getInstance();
    manager->initializeResources(10, 20, 30, 40); // Initialize specific values

    EXPECT_EQ(manager->getWood(), 40);
    EXPECT_EQ(manager->getSteel(), 20);
    EXPECT_EQ(manager->getConcrete(), 30);
    EXPECT_EQ(manager->getWaterSupply(), 10);
}

TEST_F(ResourceManagerTest, AddResources) {
    ResourceManager* manager = ResourceManager::getInstance();
    manager->addResource("wood", 10);
    manager->addResource("steel", 20);
    manager->addResource("concrete", 30);
    manager->addResource("waterSupply", 40);

    EXPECT_EQ(manager->getWood(), 10);
    EXPECT_EQ(manager->getSteel(), 20);
    EXPECT_EQ(manager->getConcrete(), 30);
    EXPECT_EQ(manager->getWaterSupply(), 40);
}

TEST_F(ResourceManagerTest, UseResources) {
    ResourceManager* manager = ResourceManager::getInstance();
    manager->initializeResources(40, 20, 30, 10); // Initialize with specific values

    manager->useResource("wood", 5);
    manager->useResource("steel", 10);
    manager->useResource("concrete", 15);
    manager->useResource("waterSupply", 5);

    EXPECT_EQ(manager->getWood(), 35);
    EXPECT_EQ(manager->getSteel(), 10);
    EXPECT_EQ(manager->getConcrete(), 15);
    EXPECT_EQ(manager->getWaterSupply(), 5);
}

TEST_F(ResourceManagerTest, SufficientMaterialsCheck) {
    ResourceManager* manager = ResourceManager::getInstance();
    manager->initializeResources(10, 10, 10, 10); // Initialize specific values
    manager->addResource("energySupply", 20);     // Set initial energy

    EXPECT_TRUE(manager->sufficientMaterials(5, 5, 5, 5, 10));   // Should be true
    EXPECT_FALSE(manager->sufficientMaterials(15, 15, 15, 15, 25)); // Should be false
}