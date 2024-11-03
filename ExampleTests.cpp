#include "gtest/gtest.h"
#include "GameEnvironment.h"

class MockBuilding : public Building {
    
       
};

class GameEnvironmentTest : public ::testing::Test {
    protected:
    GameEnvironment* environment;

    void SetUp() override {
        environment = new GameEnvironment();
    }

    void TearDown() override {
        delete environment;
    }
};

TEST_F(GameEnvironmentTest, ResizeGrideNorth)
{
    int initialRows = environment->getRows();
    int initialCols = environment->getCols();

    environment->createRoad(24,-1);

    EXPECT_EQ((int)(initialRows*1.1), environment->getRows());
    EXPECT_EQ(initialCols, environment->getCols());
    
}

TEST_F(GameEnvironmentTest, ResizeGrideSouth)
{
    int initialRows = environment->getRows();
    int initialCols = environment->getCols();

    environment->createRoad(24,51);

    EXPECT_EQ((int)(initialRows*1.1), environment->getRows());
    EXPECT_EQ(initialCols, environment->getCols());
    
}

TEST_F(GameEnvironmentTest, ResizeGrideEast)
{
    int initialRows = environment->getRows();
    int initialCols = environment->getCols();

    environment->createRoad(51,24);

    EXPECT_EQ(initialRows, environment->getRows());
    EXPECT_EQ((int)(initialCols*1.1), environment->getCols());
    
}

TEST_F(GameEnvironmentTest, ResizeGrideWest)
{
    int initialRows = environment->getRows();
    int initialCols = environment->getCols();

    environment->createRoad(-1,24);

    EXPECT_EQ(initialRows, environment->getRows());
    EXPECT_EQ((int)(initialCols*1.1), environment->getCols());
    
}

TEST_F(GameEnvironmentTest, RadialBuildingIteratorEmptyArea)
{
    auto* radialIterator = environment->createRadBuildItr(24, 24, 3);

    ASSERT_NE(radialIterator, nullptr);
    EXPECT_EQ(radialIterator->current(), nullptr);
}

TEST_F(GameEnvironmentTest, RadialBuildingIteratorSingleBuilding)
{
    auto* building = new MockBuilding();
    environment->add(building, 24, 25);

    auto* radialIterator = environment->createRadBuildItr(24, 24, 3);

    ASSERT_NE(radialIterator, nullptr);
    EXPECT_EQ(radialIterator->current(), building);
}

TEST_F(GameEnvironmentTest, RadialBuildingIteratorMultipleBuildings)
{
    auto* building1 = new MockBuilding();
    auto* building2 = new MockBuilding();
    auto* building3 = new MockBuilding();
    environment->add(building1, 24, 25);
    environment->add(building2, 25, 24);
    environment->add(building3, 23, 24);

    auto* radialIterator = environment->createRadBuildItr(24, 24, 3);

    ASSERT_NE(radialIterator, nullptr);
    EXPECT_EQ(radialIterator->current(), building1);
    EXPECT_TRUE(radialIterator->hasNext());
    radialIterator->next();
    EXPECT_EQ(radialIterator->current(), building3);
    EXPECT_TRUE(radialIterator->hasNext());
    radialIterator->next();
    EXPECT_EQ(radialIterator->current(), building2);
    EXPECT_FALSE(radialIterator->hasNext());
    radialIterator->next();
    EXPECT_EQ(radialIterator->current(), nullptr);
}

TEST_F(GameEnvironmentTest, LinearBuildingIteratorEmptyArea)
{
    auto* linearIterator = environment->createLinBuildItr();

    ASSERT_NE(linearIterator, nullptr);
    EXPECT_EQ(linearIterator->current(), nullptr);
    EXPECT_EQ(linearIterator->hasNext(), false);
    linearIterator->next();
    EXPECT_EQ(linearIterator->current(), nullptr);
    EXPECT_EQ(linearIterator->hasNext(), false);
}

TEST_F(GameEnvironmentTest, LinearBuildingIteratorSingleBuilding)
{
    auto* building = new MockBuilding();
    environment->add(building, 24, 25);

    auto* linearIterator = environment->createLinBuildItr();

    ASSERT_NE(linearIterator, nullptr);
    EXPECT_EQ(linearIterator->current(), building);
    EXPECT_EQ(linearIterator->hasNext(), false);
    linearIterator->next();
    EXPECT_EQ(linearIterator->current(), nullptr);
}

TEST_F(GameEnvironmentTest, LinearBuildingIteratorMultipleBuildings)
{
    for (int i = 0; i < 20; i+=2) {
        for (int j = 0; j < 10; j++) {
            auto* building = new MockBuilding();
            environment->createRoad(i, j);
            environment->add(building, i+1, j);
        }
    }

    int count = 1;
    auto* linearIterator = environment->createLinBuildItr();

    ASSERT_NE(linearIterator, nullptr);
    while (linearIterator->hasNext()) {
        linearIterator->next();
        count++;
    }

    EXPECT_EQ(count, 100);
}

TEST_F(GameEnvironmentTest, LinearUtilityIteratorEmptyArea)
{
    auto* utilityIterator = environment->createLinUtilItr();

    ASSERT_NE(utilityIterator, nullptr);
    EXPECT_NE(utilityIterator->current(), nullptr);
    EXPECT_EQ(utilityIterator->hasNext(), false);
    EXPECT_EQ(utilityIterator->current()->getHasRoad(), true);
    utilityIterator->next();
    EXPECT_EQ(utilityIterator->current(), nullptr);
    EXPECT_EQ(utilityIterator->hasNext(), false);
}

TEST_F(GameEnvironmentTest, LinearUtilityIteratorSingleUtility)
{
    environment->createRoad(24, 25);

    auto* utilityIterator = environment->createLinUtilItr();

    ASSERT_NE(utilityIterator, nullptr);

    EXPECT_NE(utilityIterator->current(), nullptr);
    EXPECT_EQ(utilityIterator->hasNext(), true);
    EXPECT_EQ(utilityIterator->current()->getHasRoad(), true);
    utilityIterator->next();
    EXPECT_NE(utilityIterator->current(), nullptr);
    EXPECT_EQ(utilityIterator->hasNext(), false);
    EXPECT_EQ(utilityIterator->current()->getHasRoad(), true);
    utilityIterator->next();
    EXPECT_EQ(utilityIterator->current(), nullptr);
    EXPECT_EQ(utilityIterator->hasNext(), false);
}

TEST_F(GameEnvironmentTest, LinearUtilityIteratorMultipleUtilities)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            environment->createRoad(i, j);
        }
    }

    int count = 1;
    auto* utilityIterator = environment->createLinUtilItr();

    ASSERT_NE(utilityIterator, nullptr);
    while (utilityIterator->hasNext()) {
        utilityIterator->next();
        count++;
    }

    EXPECT_EQ(count, 101);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



