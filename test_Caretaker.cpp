#include <gtest/gtest.h>
#include "GameEnvironment.h"
#include "ResourceManager.h"
#include "Caretaker.h"

class CaretakerTest : public ::testing::Test {
protected:
    GameEnvironment* environment;
    Caretaker* caretaker;

    void SetUp() override {
        ResourceManager::resetInstance();
        environment = new GameEnvironment();
        caretaker = new Caretaker(environment);
        ResourceManager::getInstance()->initializeResources(100, 200, 300, 400);
    }

    void TearDown() override {
        delete environment;
        delete caretaker;
        ResourceManager::resetInstance();
    }
};

TEST_F(CaretakerTest, SaveAndRestoreSingleState) {
    // Modify the initial state
    ResourceManager::getInstance()->addResource("wood", 50);
    environment->add(new ResidentialBuilding(10), 1, 1);

    // Save this state in the caretaker
    caretaker->save();

    // Modify the environment further
    ResourceManager::getInstance()->addResource("steel", 100);
    environment->add(new CommercialBuilding(5, 2, 2, BusinessType::FOOD), 2, 2);

    // Restore the saved state
    caretaker->restore(0);

    // Verify the restored state using accessors
    EXPECT_EQ(ResourceManager::getInstance()->getWood(), 150); // Initially 100 + 50
    EXPECT_EQ(ResourceManager::getInstance()->getSteel(), 200); // Unchanged steel
    EXPECT_TRUE(environment->getBuildingGrid()[1][1] != nullptr);
    EXPECT_EQ(environment->getBuildingGrid()[2][2], nullptr); // Shouldn't exist in the restored state
}

TEST_F(CaretakerTest, MultipleSaveAndRestore) {
    // Save initial state
    caretaker->save();

    // Make changes and save again
    ResourceManager::getInstance()->addResource("concrete", 200);
    environment->add(new IndustrialBuilding(std::make_unique<UnderConstruction>(), 100, 50, 4, Industry::MANUFACTURING, 1), 3, 3);
    caretaker->save();

    // Make further changes and save
    ResourceManager::getInstance()->useResource("waterSupply", 50);
    environment->createRoad(5, 5);
    caretaker->save();

    // Restore to the second saved state (index 1)
    caretaker->restore(1);
    EXPECT_EQ(ResourceManager::getInstance()->getConcrete(), 500); // Initially 300 + 200
    EXPECT_TRUE(environment->getBuildingGrid()[3][3] != nullptr);
    EXPECT_EQ(environment->getUtilityGrid()[5][5], nullptr); // Road should not exist
}

TEST_F(CaretakerTest, InvalidRestoreThrowsException) {
    // Try restoring without any saved states, should throw exception
    ASSERT_THROW(caretaker->restore(0), std::out_of_range);

    // Save one state and restore an out-of-range index
    caretaker->save();
    ASSERT_THROW(caretaker->restore(1), std::out_of_range);
}

TEST_F(CaretakerTest, ClearHistory) {
    // Save multiple states
    caretaker->save();
    ResourceManager::getInstance()->addResource("wood", 100);
    caretaker->save();
    ResourceManager::getInstance()->addResource("steel", 50);
    caretaker->save();

    // Check history size before and after clearing
    EXPECT_EQ(caretaker->getHistorySize(), 3);
    caretaker->clearHistory();
    EXPECT_EQ(caretaker->getHistorySize(), 0);

    // After clearing, any restore should throw an exception
    ASSERT_THROW(caretaker->restore(0), std::out_of_range);
}