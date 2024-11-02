#include <gtest/gtest.h>
#include "PrototypeManager.h"
#include "Building.h"

// Mock Concrete Building classes for testing
class MockBuilding : public Building {
public:
    virtual ~MockBuilding() {}
    MockBuilding* clone() const override {
        return new MockBuilding(*this);
    }
    void provideService() override{
        std::cout << "This is for testing" << std::endl;
    }
    float getCost(){
        return 0;
    }

};

// Test Suite for PrototypeManager
class PrototypeManagerTest : public ::testing::Test {
protected:
    PrototypeManager* manager = new PrototypeManager();
    Building* building1;
    Building* building2;
    Building* building3;

    void SetUp() override {
        building1 = new MockBuilding();
        building2 = new MockBuilding();
        building3 = new MockBuilding();
    }

    void TearDown() override {
        delete building1;
        delete building2;
        delete building3;
    }
};

// Test for adding prototypes
TEST_F(PrototypeManagerTest, AddPrototypeTest) {
    manager->addPrototype(building1);
    manager->addPrototype(building2);
    ASSERT_EQ(manager->getPrototype(building1), building1);
    ASSERT_EQ(manager->getPrototype(building2), building2);
    EXPECT_EQ(manager->getSize(), 2);  // returns current number of prototypes
}

// Test for retrieving prototypes
TEST_F(PrototypeManagerTest, GetPrototypeTest) {
    manager->addPrototype(building1);
    EXPECT_EQ(manager->getPrototype(building1), building1);
    EXPECT_EQ(manager->getPrototype(building2), nullptr);  // building2 hasn't been added
    EXPECT_EQ(manager->getSize(), 1);
}

// Test for removing prototypes
TEST_F(PrototypeManagerTest, RemovePrototypeTest) {
    manager->addPrototype(building1);
    manager->addPrototype(building2);
    bool removed = manager->removePrototype(building1);
    EXPECT_TRUE(removed);
    EXPECT_EQ(manager->getPrototype(building1), nullptr);
    EXPECT_EQ(manager->getSize(), 1);  
}

// Test for resizing the array
TEST_F(PrototypeManagerTest, ResizeArrayTest) {
    // Add enough buildings to trigger a resize
    for (int i = 0; i < 11; ++i) {
        manager->addPrototype(new MockBuilding());
    }
    EXPECT_GE(manager->getCapacity(), 10);  // Assuming initial capacity is 10
    EXPECT_GE(manager->getSize(), 11);      // After resizing, it should be able to hold all buildings
}

// Test for adding prototypes after resizing
TEST_F(PrototypeManagerTest, AddAfterResizeTest) {
    // Add buildings to trigger resize
    for (int i = 0; i < 15; ++i) {
        manager->addPrototype(new MockBuilding());
    }
    EXPECT_EQ(manager->getSize(), 15);
    EXPECT_GE(manager->getCapacity(), 15); // Ensure capacity grew appropriately
}


// To run:
// g++ -std=c++11 test_PrototypeManager->cpp PrototypeManager->cpp Building.cpp UnderConstruction.cpp Operational.cpp Dilapidated.cpp -lgtest -lgtest_main -pthread -o test_PrototypeManager
// ./test_PrototypeManager