#include "gtest/gtest.h"
#include "Dilapidated.h"
#include "Operational.h"
#include "UnderConstruction.h"
#include "CommercialBuilding.h"
#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

class BuildingTest : public ::testing::Test {
protected:
    CommercialBuilding* building; //use concrete building because you cannot create an instance of an abstract class (BUILDING)

    void SetUp() override{

        BuildingState* initialState = new UnderConstruction();
        int capacity = 100;
        int size = 200;
        int numStores = 5;
        BusinessType businessType = LUXURY;

        building = new CommercialBuilding(initialState, capacity, size, numStores, businessType);
    }
};

TEST_F(BuildingTest, ConstructorTest) {
    EXPECT_EQ(building->currentState(), "UnderConstruction");
}

TEST_F(BuildingTest, RepairBuildingTest){

    building->repairBuilding();
    building->setState(new Dilapidated);
    building->repairBuilding();
    EXPECT_EQ(building->currentState(), "Operational");

}

TEST_F(BuildingTest, SimulateConstructionTest){

    std::this_thread::sleep_for(std::chrono::seconds(10));
    EXPECT_EQ(building->currentState(), "Operational");

}

//run all tests
int main(int argc, char **argv){

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    
}
