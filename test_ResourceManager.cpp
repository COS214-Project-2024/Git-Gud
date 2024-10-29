#include <gtest/gtest.h>
#include "ResourceManager.h"

// Test Suite for ResourceManager
class ResourceManagerTest : public ::testing::Test {
protected:
    ResourceManager* manager;

    void SetUp() override {
        ResourceManager::resetInstance();
        manager = ResourceManager::getInstance();
        manager->initializeResources(10, 20, 30, 40);
    }
};

TEST_F(ResourceManagerTest, SingletonInstance) {
    ResourceManager* instance1 = ResourceManager::getInstance();
    ResourceManager* instance2 = ResourceManager::getInstance();
    EXPECT_EQ(instance1, instance2);
}

TEST_F(ResourceManagerTest, InitializeResources) {
    EXPECT_EQ(manager->getWood(), 10);
    EXPECT_EQ(manager->getSteel(), 20);
    EXPECT_EQ(manager->getConcrete(), 30);
    EXPECT_EQ(manager->getWaterSupply(), 40);
}

TEST_F(ResourceManagerTest, AddResource) {
    manager->addResource("wood", 5);
    manager->addResource("steel", 10);
    EXPECT_EQ(manager->getWood(), 15);
    EXPECT_EQ(manager->getSteel(), 30);
}

TEST_F(ResourceManagerTest, UseResource) {
    manager->useResource("wood", 5);
    manager->useResource("steel", 10);
    EXPECT_EQ(manager->getWood(), 5);
    EXPECT_EQ(manager->getSteel(), 10);
}

TEST_F(ResourceManagerTest, ResourceCannotGoNegative) {
    manager->useResource("wood", 15); // More than available
    manager->useResource("steel", 25); // More than available
    EXPECT_EQ(manager->getWood(), 0);
    EXPECT_EQ(manager->getSteel(), 0);
}

TEST_F(ResourceManagerTest, BudgetModification) {
    manager->addBudget(500);
    EXPECT_EQ(manager->getBudget(), 500500); // Starting budget + 500
    manager->spendBudget(300);
    EXPECT_EQ(manager->getBudget(), 500200); // Updated budget after spending
}

TEST_F(ResourceManagerTest, SufficientMaterialsCheck) {
    EXPECT_TRUE(manager->sufficientMaterials(5, 10, 10, 5, 0)); // Should be sufficient
    EXPECT_FALSE(manager->sufficientMaterials(15, 25, 35, 45, 5)); // Should not be sufficient
}